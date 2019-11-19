/*****************************************************************************/
/*  (C) Copyright  TOSHIBA TEC CORPORATION 2008   All Rights Reserved        */
/*****************************************************************************
============================== Source Header =================================
 Filename: boxdocument.h
 Revision: com_m#4
 File Spec: EBX:MA6057.A-DEV_SRC;com_m#4
 Originator: 07475
 Last Changed: 08-DEC-2008 19:22:11

  Outline : definition of BOX types

*/
/*----------------------------------------------------------------------------
 Related Change Documents:
   Not related to any Change Document
------------------------------------------------------------------------------
 Related Baselines:
   1:
   	Baseline:      "EBX:SCI_PHASE4_V2245_20081209_1928"
   	Creation Date: 09-DEC-2008 19:28:36
   	Description:   Baseline SCI_PHASE4_V2245_20081209_1928.AAAA
   
   2:
   	Baseline:      "EBX:SCI_PHASE4_V2245_20081209_1637"
   	Creation Date: 09-DEC-2008 16:38:54
   	Description:   Baseline SCI_PHASE4_V2245_20081209_1637.AAAA
   
------------------------------------------------------------------------------
 History:
   Revision com_m#4 (APPROVED)
     Updated:  09-DEC-2008 12:59:23      07475
       Updated attribute(s)
     Created:  08-DEC-2008 19:22:50      07475
       boxdocument.h:SessionID implementation change
     Updated:  08-DEC-2008 19:22:11      07475
       Item revision com_m#4 created from revision com_m#3 with status
       $TO_BE_DEFINED
   
   Revision com_m#3 (APPROVED)
     Updated:  17-NOV-2008 14:32:51      13848
       Updated attribute(s)
     Created:  17-NOV-2008 14:32:20      13848
       Add new interfaces for 4th build
     Updated:  17-NOV-2008 14:31:27      13848
       Item revision com_m#3 created from revision com_m#2 with status
       $TO_BE_DEFINED
   
   Revision com_m#2 (APPROVED)
     Updated:  01-SEP-2008 17:15:56      13848
       Updated attribute(s)
     Created:  01-SEP-2008 17:14:57      13848
       Update for Ph3.5 1st build
     Updated:  01-SEP-2008 17:12:55      13848
       Item revision com_m#2 created from revision com_m#1 with status
       $TO_BE_DEFINED
   
   Revision com_m#1 (UNIT TESTED)
     Updated:  01-SEP-2008 16:51:14      13848
       Updated attribute(s)
     Created:  19-AUG-2008 14:41:31      13848
       Initial revision
========================== End of Source Header =============================*/

#ifndef __CI_BOXDOCUMENT_H__
#define __CI_BOXDOCUMENT_H__

#include <status.h>
#include <CI/OperatingEnvironment/interface.h>
#include <CI/OperatingEnvironment/ref.h>
#include <CI/OperatingEnvironment/cstring.h>

#include <CI/BoxDocument/progress.h>
#include <CI/BoxDocument/box.h>
#include <CI/BoxDocument/document.h>

namespace ci {
namespace boxdocument {

using ci::operatingenvironment::CString;

/**
 * BoxDocStatus shows BoxDocument status
 */
typedef enum eBoxDocStatus {
    INITIALIZED = 0,
    INITIALIZING,
    UNINITIALIZED,
    DELETING_ALL,
} BoxDocStatus;

typedef enum eAccessContext {
    LOCAL_READ = 0,
    LOCAL_WRITE,
    REMOTE_READ,
    REMOTE_WRITE,
} AccessContext;

DECL_OBJ_REF(BoxDocument);

/**
 * BoxDocument class provides to get BOX instance
 */
class BoxDocument : public ci::operatingenvironment::Interface
{
public:

    /** Virtual destructor */
    virtual ~BoxDocument() {};
    
    /**
     * @deprecated -- Please use the new Acquire . Retained only for backward compatibility.
     * Returns a reference to a BoxDocument
     * @return reference to BoxDocument interface  
     */
    static BoxDocumentRef Acquire();

    /**
     * Returns a reference to a BoxDocument
     * Updates the session ID if present else creates a new sessionID and returns it to the user. 
     * @return reference to BoxDocument interface  
     */
    static BoxDocumentRef Acquire(CString &sessionId);
       
    /**
     * create new box
     * @param[out] box - instance of Box class
     * @param[in] boxbasepath - box type e.g. "eFilingboxes"
     * @param[in] boxnumber - string of 1-20 digits box number
     * @param[in] boxpassword - the password of box. if empty, the box is 
     *                          NOT protected.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     *         STATUS_RESOURCE_WITH_SAME_NAME_EXISTS if resource with the name already exists.
     *         STATUS_MAX_ALLOWED_RESOURCES_REACHED if the resource limit is reached     
     */
    virtual Status CreateBox(BoxRef &box, 
                             CString boxbasepath, 
                             CString boxnumber,
                             CString boxpassword = "") = 0;
    
    /**
     * get protected Box instance by path
     * @param[out] box - instance of Box class 
     * @param[in] boxbasepath - box type e.g. "eFilingboxes"
     * @param[in] boxnumber - string of 1-20 digits box number
     * @param[in] boxpassword - box password
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_AUTHENTICATIONFAILS on authentication fails,
     *         STATUS_BOXISLOCKED on box is locked.
     *		  STATUS_RESOURCENOTFOUND	if Box is not found
     */
    virtual Status GetBox(BoxRef &box, 
                          CString boxbasepath, 
                          CString boxnumber,
                          CString boxpassword = "") = 0;

    /**
     * get a list of box
     * @param[out] list - list of boxes. This list have snapshot of each box
     *                     instances. 
     * @param[in] boxbasepath - box type e.g. "eFilingboxes"
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetBoxList(BoxList &list, CString boxbasepath) = 0;
    
    /**
     * get a list of box
     * @param[out] list - list of boxes. This list have snapshot of each box
     *                     instances. 
     * @param[in] boxbasepath - box type e.g. "eFilingboxes"
     * @param[in] from - return list from this value.
     * @param[in] size - list size, if "from" + "size" is bigger than the 
     *                    number of all boxes, return list size will be smaller
     *                    than "size".
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetBoxList(BoxList &list, CString boxbasepath, 
                               unsigned int from, unsigned int size) = 0;
    
    /**
     * delete the box
     * if a document in the box is using, it will fail(some documents are 
     *  deleted).
     * @param[in] boxbasepath - box type e.g. "eFilingboxes"
     * @param[in] boxnumber - string of 1-20 digits box number
     * @param[in] boxpassword - box password     
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status DeleteBox(CString boxbasepath, CString boxnumber, CString boxpassword = "") = 0;

    /**
     * get protected MailBox instance by path
     * @param[out] box - instance of Box class 
     * @param[in] boxbasepath - box type e.g. "eFilingboxes"
     * @param[in] boxnumber - string of 1-20 digits box number
     * @param[in] context - access context enum    
     * @param[in] boxpassword - box password
     * @param[in] enableAdminPass - allow admin password for GetMailBox
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_AUTHENTICATIONFAILS on authentication fails,
     *         STATUS_BOXISLOCKED on box is locked.
     *		  STATUS_RESOURCENOTFOUND	if Box is not found     
     *		  STATUS_NOT_ALLOWED if any invalid mail box operation is performed
     */
	virtual Status GetMailBox(BoxRef &box, CString boxbasepath, CString boxnumber,AccessContext context,CString boxpassword = "", CString phone = "", bool enableAdminPass = true) = 0;

    /**
     * delete the box
     * if any documents exist in the box, it will fail.
     * @param[in] boxbasepath - box type e.g. "eFilingboxes"
     * @param[in] boxnumber - string of 1-20 digits box number
     * @param[in] context - access context enum     
     * @param[in] boxpassword - box password     
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     *         STATUS_DOCUMENTS_EXIST if documents exist in the box.     
     */
    virtual Status DeleteMailBox(CString boxbasepath, CString boxnumber,AccessContext context, CString boxpassword = "") = 0;
    
    /**
     * Initialize all Documents.
     * If Document status is CREATING or DELETING, it is changed to WAITING.
     * WAITING Document is deleted when Cleanup() is called. If Document status
     * is EDITING or USING or RESERVING, it is changed to READY. Also the method clean up 
     * box clipboard.
     * Till finishing initialization, BoxDocument::GetStatus returns 
     * INITIALIZING. And BoxDocument returns STATUS_FAILED_INITIALIZATION 
     * on the other methods. 
     * @return STATUS_OK on success.
     *         STATUS_FAILED_INITIALIZATION on INITIALIZING.
     *         STATUS_DELETINGALL on DELETING ALL.     
     */
    virtual Status Initialize() = 0;
    
    /**
     * Cleanup all WAITING Documents.
     * The method search each box and delete WAITING Document.
     * @return STATUS_OK on success.
     *         STATUS_FAILED_INITIALIZATION when uninitialized
     */
    virtual Status Cleanup() = 0;
    
    /**
     * return the status of the boxbasepath
     * @param[in] boxbasepath - box type e.g. "EFilingboxes"
     * @return INITIALIZED - the boxbasepath is available.
     *         INITIALIZING - the boxbasepath is initializing, not available.
     *         UNINITIALIZED - the boxbasepath is uninitialized, not available.
     *         DELETING_ALL - the boxbasepath is deleting all, not available.  
     */
    virtual BoxDocStatus GetStatus(CString boxbasepath = "EFilingBoxes") = 0;

    /**
     * confirm Box exists or not
     * @param[in] boxbasepath - box type e.g. "eFilingboxes"
     * @param[in] boxnumber - string of 1-20 digits box number
     * @return true if box exists
     *         false if box doesn't exist.
     */
    virtual bool BoxExist(CString boxbasepath, CString boxnumber) = 0;

	/**
	* Delete all folders/documents and delete all boxes except public box
	* @param[in] boxbasepath - box type e.g. "eFilingboxes"
	* @return STATUS_OK on success. 
	*         STATUS_NOTREADY on not ready state.
	*         STATUS_FAILED on Failure	
	*/
	virtual Status DeleteAll(CString boxbasepath) = 0;

	/**
	* Clears the clip board data for current session id
	* @return STATUS_OK on success. 
	*         STATUS_FAILED on Failure
	*/
	virtual Status ClearClipBoard() = 0;	

	/**
	* This method search for each box present in the EFilingBoxes and unlock the box if it is locked. 
	* @return STATUS_OK
	*		STATUS_FAILED
	*/
	virtual Status UnlockAllBoxes() = 0;
	
	/**
	* Delete all folders/documents and delete all boxes
	* @param[in] boxbasepath - box type e.g. "eFilingboxes"
	* @param[in] publicbox - create public box
	* @return STATUS_OK on success. 
	*         STATUS_FAILED on Failure	
	*/
	virtual Status DeleteAll(CString boxbasepath, bool publicbox) = 0;
	
	/**
	 * confirm the BoxBasePath is used.
	 * @param[in] boxbasepath - box type e.g. "EFilingboxes"
	 * @return true if the boxbasepath is used.
	 *         false if the boxbasepath is NOT used.
	 */
	virtual bool isUsed(CString boxbasepath = "EFilingBoxes") = 0;

    /**
     * Get a list of box. Using this box instance user can able to get only box name and the box number
     * @param[out] list - list of boxes. This list have snapshot of each box
     *                     instances. 
     * @param[out] list - total number of boxes     
     * @param[in] boxbasepath - box type e.g. "eFilingboxes"
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetBoxList(BoxList &list, int &totalBoxes,  CString boxbasepath) = 0;
    
    /**
     * Get a list of mailbox. Using this box instance user can get box name, the box number, 
     * documentType, userName, comment and WEPDocument.
     * @param[out] list - list of mailboxes. This list have snapshot of each mailbox
     *                     instances. 
     * @param[out] list - total number of mailboxes     
     * @param[in] boxbasepath - box type e.g. "ITUTBoxes"
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetMailBoxList(BoxList &list, int &totalBoxes,  CString boxbasepath) = 0;
	
}; // class BoxDocument

}; // end of namespace boxdocument
}; // end of namespace ci

#endif // #ifndef __CI_BOXDOCUMENT_H__
