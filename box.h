/*****************************************************************************/
/*  (C) Copyright  TOSHIBA TEC CORPORATION 2008   All Rights Reserved        */
/*****************************************************************************
============================== Source Header =================================
 Filename: box.h
 Revision: com_m#3
 File Spec: EBX:MA6056.A-DEV_SRC;com_m#3
 Originator: 07475
 Last Changed: 17-NOV-2008 14:33:35

  Outline : definition of box operation

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
   
   3:
   	Baseline:      "EBX:SCI_PHASE4_V3245_PRE"
   	Creation Date: 03-DEC-2008 15:36:53
   	Description:   Baseline SCI_PHASE4_V3245_PRE_20081203_1535.AAAA
   
   4:
   	Baseline:      "EBX:SCI_PHASE4_V3245_PRE_20081203_1343"
   	Creation Date: 03-DEC-2008 13:43:55
   	Description:   Baseline SCI_PHASE4_V3245_PRE_20081203_1343.AAAA
   
   5:
   	Baseline:      "EBX:SCI_PHASE4_V3245_PRE_20081203_0940"
   	Creation Date: 03-DEC-2008 09:41:08
   	Description:   Baseline SCI_PHASE4_V3245_PRE_20081203_0940.AAAA
   
   6:
   	Baseline:      "EBX:SCI_PHASE4_V2244"
   	Creation Date: 20-NOV-2008 09:16:05
   	Description:   Baseline SCI_PHASE4_V2244_20081120_0915.AAAA
   
   7:
   	Baseline:      "EBX:SCI_PHASE4_V2244_20081119_1205"
   	Creation Date: 19-NOV-2008 12:05:51
   	Description:   Baseline SCI_PHASE4_V2244_20081119_1205.AAAA
   
   8:
   	Baseline:      "EBX:SCI_PHASE4_V2244_20081119_1143"
   	Creation Date: 19-NOV-2008 11:44:12
   	Description:   Baseline SCI_PHASE4_V2244_20081119_1143.AAAA
   
   9:
   	Baseline:      "EBX:SCI_PHASE4_V2244_20081118_2059"
   	Creation Date: 18-NOV-2008 20:59:24
   	Description:   Baseline SCI_PHASE4_V2244_20081118_2059.AAAA
   
   10:
   	Baseline:      "EBX:SCI_PHASE4_V2244_20081118_2046"
   	Creation Date: 18-NOV-2008 20:46:32
   	Description:   Baseline SCI_PHASE4_V2244_20081118_2046.AAAA
   
   11:
   	Baseline:      "EBX:SCI_PHASE4_V2244_20081118_1802"
   	Creation Date: 18-NOV-2008 18:03:14
   	Description:   Baseline SCI_PHASE4_V2244_20081118_1802.AAAA
   
------------------------------------------------------------------------------
 History:
   Revision com_m#3 (APPROVED)
     Updated:  17-NOV-2008 14:34:31      13848
       delete the invalid characters
     Updated:  17-NOV-2008 14:33:35      13848
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
     Created:  19-AUG-2008 14:41:21      13848
       Initial revision
========================== End of Source Header =============================*/

#ifndef __CI_BOX_H__
#define __CI_BOX_H__

#include <list>
#include <status.h>
#include <types.h>
#include <CI/OperatingEnvironment/ref.h>
#include <CI/OperatingEnvironment/cstring.h>
#include <CI/BoxDocument/archive.h>
#include <CI/BoxDocument/document.h>

namespace ci {
namespace boxdocument {

/*
 * file name format for the received forwarding
 */
typedef enum eRFFileNameFormat {
    FNF_FilenameDatePage = 1,
    FNF_FilenamePageDate = 2,
    FNF_DateFilenamePage = 3,
    FNF_DatePageFilename = 4,
    FNF_PageFilenameDate = 5,
    FNF_PageDateFilename = 6,
    FNF_HostnameDatePage = 7,
} RFFileNameFormat;

/**
 * date format for the received forwarding
 */
typedef enum eRFDateFormat {
    DF_NONE = 0,
    DF_YYYYMMDDHHmmSS = 1,
    DF_YYMMDDHHmmSS = 2,
    DF_YYYYMMDD = 3,
    DF_YYMMDD = 4,
    DF_HHmmSS = 5,
    DF_YYYYMMDDHHmmSSmm = 6,
} RFDateFormat;

/**
 * page number format for the received forwarding
 */
typedef enum eRFPageNumberFormat {
    PNF_3DIGITS = 3,
    PNF_4DIGITS = 4,
    PNF_5DIGITS = 5,
    PNF_6DIGITS = 6,
} RFPageNumberFormat;

/**
 * sub ID for the received forwarding
 */
typedef enum eRFSubID {
    SID_AUTO = 0,
    SID_4DIGITS = 4,
    SID_5DIGITS = 5,
    SID_6DIGITS = 6,
} RFSubID;

using ci::operatingenvironment::CString;

class Container;
class Box;
class Folder;

DECL_OBJ_REF(Box);
DECL_OBJ_REF(Folder);

typedef std::list<operatingenvironment::Ref<Box> > BoxList;
typedef std::list<operatingenvironment::Ref<Folder> > FolderList;

/**
 * Container class provides common facilities about box and folder.
 */
class Container 
{
public:
    /** Virtual destructor */
    virtual ~Container() {};
    
    /**
     * get document instance in the container.
     * @param[out] doc - instance of Document class
     * @param[in] documentname - serial number from "00000".
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetDocument(DocumentRef &doc, CString documentname) = 0;
    
    /**
     * get a list of document
     * @param[out] list - list of documents. 
     *                     This list have snapshot of each documents instances.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetDocumentList(DocumentList &list) = 0;

    /**
     * get a list of document
     * @param[out] list - list of documents. 
     *                     This list have snapshot of each documents instances.
     * @param[in] from - return list from this value. (0-origin)
     * @param[in] size - list size, if "from" + "size" is bigger than the 
     *                    number of all documents, return size will be 
     *                    smaller than "size".
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetDocumentList(DocumentList &list,
                                    unsigned int from, unsigned int size) = 0;
    
    /**
     * get a list of document. Using these document objects user can access the following 
     * document properties.
     * documentName
     * jobType
     * totalPages
     * creationDate
     * lastModifiedDate
     * Size
     * thumbnail
     * cutDocument
     * document status
     * jobTypeColorMap
     * paperSizeMap
     *
     * @param[out] list - list of documents. 
     *                     This list have snapshot of each documents instances.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetViewDocumentList(DocumentList &list) = 0; 

    /**
     * get a list of document. Using these document objects user can access the following 
     * document properties.
     * documentName
     * jobType
     * totalPages
     * creationDate
     * lastModifiedDate
     * Size
     * thumbnail
     * cutDocument
     * document status
     * jobTypeColorMap
     * paperSizeMap
     *
     * @param[out] list - list of documents. 
     *                     This list have snapshot of each documents instances.
     * @param[in] from - return list from this value. (0-origin)
     * @param[in] size - list size, if "from" + "size" is bigger than the 
     *                    number of all documents, return size will be 
     *                    smaller than "size".
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetViewDocumentList(DocumentList &list, 
                                    unsigned int from, unsigned int size) = 0;

    /**
     * Get a list of document. This returns the CViewDocument class object to the user.
     * Using this documentRef, user can access only name of the document.
     * @param[out] list - list of documents. 
     *                     This list have snapshot of each documents instances.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetDocumentListToDelete(DocumentList &list) = 0;
	
    
    /**
     * create new folder
     * if Folder object call this function, it will fail.
     * @param[in] foldername - new folder name
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     *         STATUS_RESOURCE_WITH_SAME_NAME_EXISTS if resource with the name already exists.
     *         STATUS_MAX_ALLOWED_RESOURCES_REACHED if total files reached MAx number.          
     */
    virtual Status CreateFolder(CString foldername) = 0;

    /**
     * create new folder
     * if Folder object call this function, it will fail.
     * @param[out] folder - instance of Folder class     
     * @param[in] foldername - new folder name
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     *         STATUS_RESOURCE_WITH_SAME_NAME_EXISTS if resource with the name already exists.
     *         STATUS_MAX_ALLOWED_RESOURCES_REACHED if total files reached MAx number.          
     */
    virtual Status CreateFolder(FolderRef& folder,CString foldername) = 0;
    
    /**
     * get folder instance by folder name
     * if Folder object call this function, it will fail.
     * @param[out] folder - reference to folder instance
     * @param[in] foldername - target folder name
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     *		  STATUS_RESOURCENOTFOUND	if Folder is not found     
     */
    virtual Status GetFolder(FolderRef& folder, CString foldername) = 0;
    
    /**
     * get a list of folder
     * if Folder object call this function, it will fail.
     * @param[out] list - list of folders. 
     *                     this list have snapshot of each folder instances.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetFolderList(FolderList &list) = 0;
    
    /**
     * get a list of folder
     * @param[out] list - list of folders. 
     *                     this list have snapshot of each folder instances.
     * @param[in] from - return list from this value. (0-origin)
     * @param[in] size - list size, if "from" + "size" is bigger than the 
     *                    number of all lists, return size will be smaller
     *                    than "size".
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetFolderList(FolderList &list,
                                  unsigned int from, unsigned int size) = 0;
    
    /**
     * delete the folder
     * if documents in the box is using, it will fail(some documents are 
     *  deleted).
     * @param[in] foldername - target folder name
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status DeleteFolder(CString foldername) = 0;
    
    /**
     * set box/folder property
     * @param[in] key - the property name to be set
     * @param[in] value - the property value to be set
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status SetWebDAVProperty(CString key, CString value) = 0;
    
    /**
     * get box/folder property
     * @param[in] key - the property name to be set
     * @param[out] value - the property value
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetWebDAVProperty(CString key, CString &value) = 0;
    
    /**
     * set a name of the container
     * if Folder object call this function, when a folder has the name 
     * already exists, it will fail.
     * @param[in] name - a name to be set
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     *         STATUS_RESOURCE_WITH_SAME_NAME_EXISTS if resource with the name already exists.
     */
    virtual Status SetName(CString name) = 0;
    
    /**
     * get a name of the container
     * @param[out] name - a name of the container
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetName(CString &name) = 0;
    
    /**
     * cut the documents to clipboard
     * if document status is NOT READY, it will fail.
     * @param[in] docname - source document name
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CutDocument(CString docname) = 0;
    
    /**
     * cut the documents to clipboard
     * if document status is NOT READY, it will fail.
     * @param[in] documents - source document names
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CutDocument(std::vector<CString> documents) = 0;
    
    /**
     * cut the documents to clipboard
     * if document status is NOT READY, it will fail.
     * @param[out] progress - user can get operation progress from this.
     * @param[in] docname - source document name
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CutDocument(ProgressRef& progress, CString docname) = 0;
    
    /**
     * cut the documents to clipboard
     * if document status is NOT READY, it will fail.
     * @param[out] progress - user can get operation progress from this.
     * @param[in] documents - source document names
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CutDocument(ProgressRef& progress, 
                               std::vector<CString> documents) = 0;
    /**
     * copy the documents to clipboard
     * if document status is NOT READY or USING 
     *   or RESERVING or EDITING, it will fail.
     * @param[in] docname - source document name
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CopyDocument(CString docname) = 0;
    
    /**
     * copy the documents to clipboard
     * if document status is NOT READY or USING 
     *   or RESERVING or EDITING, it will fail.
     * @param[in] documents - source document names
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CopyDocument(std::vector<CString> documents) = 0;
    
    /**
     * copy the documents to clipboard
     * if document status is NOT READY or USING 
     *   or RESERVING or EDITING, it will fail.
     * @param[out] progress - user can get operation progress from this.
     * @param[in] docname - source document name
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CopyDocument(ProgressRef& progress, CString docname) = 0;
    
    /**
     * copy the documents to clipboard
     * if document status is NOT READY or USING 
     *   or RESERVING or EDITING, it will fail.
     * @param[out] progress - user can get operation progress from this.
     * @param[in] documents - source document names
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CopyDocument(ProgressRef& progress,
                                std::vector<CString> documents) = 0;
    
    /**
     * paste the document from clipboard
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     *         STATUS_MAX_ALLOWED_RESOURCES_REACHED if the Resource Limit is reached.
     */
    virtual Status PasteDocument() = 0;
    
    /**
     * paste the document from clipboard
     * @param[out] progress - user can get operation progress from this.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status PasteDocument(ProgressRef& progress) = 0;
        
    /**
     * create archive
     * @param[out] archiver - created Archiver object.
     * @param[in] target - archive file path / file name
     * @param[in] documentname - document name to be archived
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CreateArchive(ci::operatingenvironment::Ref<Archiver> &archiver, CString target, CString documentname) = 0;
    
    /**
     * create archive
     * @param[out] archiver - created Archiver object.
     * @param[in] target - archive file path / file name
     * @param[in] documentlist - list of document name to be archived
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CreateArchive(ci::operatingenvironment::Ref<Archiver> &archiver, CString target, std::vector<CString> documentlist) = 0;
    
    /**
     * extract archive
     * @param[out] extractor - created Extractor object
     * @param[in] archiverpath - path of the archive to be extracted
     * @param[in] extractorpath - path to which the archived files needs to extracted
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_UNIDENTIFIED_FILE_FORMAT if file format cannot be recognized,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     * */
    virtual Status ExtractArchive(ci::operatingenvironment::Ref<Extractor> &extractor, CString archiverpath,CString extractorpath) = 0;

    /**
     * Delete Archive 
     * @param[in] archivepath - path of the archive file that needs to be deleted
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     * */
    virtual Status DeleteArchive(CString archivepath) = 0;
    
    /**
     * get size of the containers
     * It includes the size of all files that compose Document.
     * @param[out] total - total size (byte) of the container
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetSize(uint64 &size) = 0;

    /**
     * Undo the cut/copy document operation
     * @param[in] docname - source document name
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     */
    virtual Status UndoEditDocument(CString docname) = 0;
	 
    /**
     * Undo the cut/copy document operation
     * @param[in] documents - source document names     
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     */
    virtual Status UndoEditDocument(std::vector<CString> documents) = 0;	


    /**
     * create document instance on the container
     * the name of document is least number of non-exist documents. 
     * @param[out] doc - instance of Document class 
     * @param[in/out] documentname - on input, it is document name expected by 
     *                                users. on output, it's created document 
     *                                name. if document has the same name
     *                                exists, suffix will be added.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     *         STATUS_MAX_ALLOWED_RESOURCES_REACHED if the resource limit is reached
     */
    virtual Status CreateDocument(DocumentRef& doc, 
                                  CString &documentname) = 0;


    /**
     * delete document
     * document status will be changed to DELETING. after that, document will
     * be deleted. 
     * if document status is NOT READY or EDITING, it will fail.
     * @param[in] documentname - serial number from "00000".
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status DeleteDocument(CString documentname) = 0;
    
    /**
     * delete document
     * document status will be changed to DELETING. after that, document will
     * be deleted. 
     * if document status is NOT READY or EDITING, it will fail.
     * @param[out] progress - user can get operation progress from this.
     * @param[in] documentname - serial number from "00000".
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status DeleteDocument(ProgressRef& progress,
    									CString documentname) = 0;
    
    /**
     * get a list of document properties
     * @param[out] list - list of document properties. 
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetDocumentPropertiesList(DocumentPropertiesList &list) = 0;
    
    /**
     * get a list of document
     * @param[out] list - list of document properties. 
     * @param[in] from - return list from this value. (0-origin)
     * @param[in] size - list size, if "from" + "size" is bigger than the 
     *                    number of all documents, return size will be 
     *                    smaller than "size".
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetDocumentPropertiesList(DocumentPropertiesList &list, 
                                    unsigned int from, unsigned int size) = 0;
    // Support for EBX_RCR_235 : Start
    /**
     * paste the document from clipboard to the Box or to the folder present under the Box	
     * @param[out] documentnames - names of the documents that's been pasted
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     *         STATUS_MAX_ALLOWED_RESOURCES_REACHED if the Resource Limit is reached.
     **/
    // Support for EBX_RCR_235 : End
    virtual Status PasteDocument(std::vector<CString> &documentnames) = 0;
     
}; // class Container


/**
 * Box class provides facilities of BOX operation.
 */
class Box : public Container
{
public:
    /** Virtual destructor */
    virtual ~Box() {};
    
    
    /**
     * get a number of the box
     * @param[out] number - a number of the box
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetNumber(CString &number) = 0;	
    
    /**
     * confirm the box.is protected or not.
     * @return true if the box is protected.
     *         false if NOT.
     * @NOTE - It is available via GetBoxList
     */
    virtual bool IsPasswordProtected() = 0;
    
    /**
     * get document preserve days
     * @param[out] days - document preserve days
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetDocumentPreserveDays(CString &days) = 0;

    /**
     * get document preserve flag
     * @param[out] flag - document preserve flag
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetPreservationPeriodFlag(CString &flag) = 0;
    
    /**
     * get last modified date
     * @param[out] date - last modified date of the box
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetLastModifiedDate(CString &date) = 0;

    /**
     * set HDB Document of Workflow Execution Parameter to Box. 
     * @param[in] node - WEP node to save
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status SetWEPDocument(dom::NodeRef node) = 0;
    
    /**
     * get WEP document ID
     *  BoxDocument create HDB document and return document ID.
     * @param[out] documentID - HDB document ID
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     * @note user need to delete this document using document ID.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetWEPDocument(CString& documentID) = 0;
    
    /**
     * change box password
     * @param[in] boxpassword - new box password. If empty, remove protection 
     *                          for the box.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status ChangePassword(CString boxpassword) = 0;

    /**
     * confirm Folder exists or not
     * @param[in] foldername - folder name.
     * @return true if folder exists
     *         false if folder doesn't exist.
     */
    virtual bool FolderExist(CString foldername) = 0;

    /**
     * unlock box
     * @return STATUS_OK on success
     * @NOTE - It is available via GetBoxList
     */
    virtual Status Unlock() = 0;	

    /**
     * Get MailBoxType (documentType). 
     * @param[out] boxtype - box type for the box.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetBoxType(CString &boxtype) = 0;
	
    /**
     * set user name. 
     * @param[in] username - username to set
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status SetUserName(CString username) = 0;

    /**
     * get user name. 
     * @param[out] username - return the username
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetUserName(CString &username) = 0;

    /**
     * set comment. 
     * @param[in] comment - comment to be set
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status SetComment(CString comment) = 0;
	
    /**
     * get comment. 
     * @param[out] comment - return the comment
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetComment(CString &comment) = 0;

    /**
     * confirm the box.is locked or not.
     * @return true if the box is locked.
     *         false if NOT.
     * @NOTE - It is available via GetBoxList     
     */
    virtual bool IsLocked() = 0;

    /**
     * get relay report destination. 
     * @param[out] destination - destination address for relay report
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetRelayReportDestination(CString &destination) = 0;

    /**
     * get relay report destination type. 
     * @param[out] dsttype - destination type for relay report
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetRelayReportDestinationType(CString &dsttype) = 0;

    /**
     * get relay report contact id. 
     * @param[out] id - contact id for relay report
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetRelayReportContactId(CString &id) = 0;
    
    /**
     * set last backup date
     * @param[in] date - last backup date of the box
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status SetLastBackupDate(CString date) = 0;
    
    /**
     * get last backup date
     * @param[out] date - last backup date of the box
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetLastBackupDate(CString &date) = 0;

    /**
     * get a password of the mail box
     * @param[out] password - a number of the box
     * @return STATUS_OK on success,
     *         STATUS_FAILED on invalid box base path.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetPassword(CString &password) = 0;
    /**
     * get the boxcreation date
     * @param[out] date - creation date of the box
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetCreationDate(CString &date) = 0;
	
    /**
     * get the notification email id
     * @param[out] emailId - get the nofication email id
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetNotificationEmailId(CString &emailId) = 0;	
    /**
     * get the number of document present inside a box
     * @param[out] numDoc - get the number of documents in a box
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetDocumentCount(uint &numDoc) = 0;	
    /**
     * get the number of folder inside a box
     * @param[out] numFolder - get the number of folder in a box
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetFolderCount(uint &numFolder) = 0;	
    /**
     * set the file name format for the received forwarding
     * @param[in] fnf - set the file name for the received forwarding
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     *         STATUS_DISK_FULL if there is not enough space in the partition.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status SetFileNameFormat(RFFileNameFormat fnf) = 0;
    /**
     * get the file name format for the received forwarding
     * @param[out] fnf - get the file name for the received forwarding
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetFileNameFormat(RFFileNameFormat &fnf) = 0;  
    
    /**
     * set the date format for the received forwarding
     * @param[in] df - get the date for the received forwarding
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     *         STATUS_DISK_FULL if there is not enough space in the partition.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status SetDateFormat(RFDateFormat df) = 0;

    /**
     * get the date format for the received forwarding
     * @param[out] df - get the date for the received forwarding
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetDateFormat(RFDateFormat &df) = 0;  

    /**
     * set the page number format for the received forwarding
     * @param[in] pnf - get the page number format for the received forwarding
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     *         STATUS_DISK_FULL if there is not enough space in the partition.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status SetPageNumberFormat(RFPageNumberFormat pnf) = 0;  
    
    /**
     * get the page number format for the received forwarding
     * @param[out] pnf - get the page number format for the received forwarding
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetPageNumberFormat(RFPageNumberFormat &pnf) = 0; 

    /**
     * set the sub ID for the received forwarding
     * @param[in] sid - get the Sub ID for the received forwarding
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     *         STATUS_DISK_FULL if there is not enough space in the partition.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status SetSubID(RFSubID sid) = 0;   

    /**
     * get the sub ID for the received forwarding
     * @param[out] sid - get the sub ID for the received forwarding
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetSubID(RFSubID &sid) = 0;  

    /**
     * set comment for the received forwarding. 
     * @param[in] comment - comment to be set
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     *         STATUS_DISK_FULL if there is not enough space in the partition.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status SetRFComment(CString comment) = 0;

    /**
     * get comment for the received forwarding.. 
     * @param[out] comment - return the comment
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @NOTE - It is available via GetBoxList
     */
    virtual Status GetRFComment(CString &comment) = 0; 
}; // class Box

/**
 * Folder class provides facilities of folder operation.
 */
class Folder : public Container
{
public:
    /** Virtual destructor */
    virtual ~Folder() {};
    
}; // class Folder

/**
 * find the box from BoxList by box number (CString).
 */
class BoxFinder {
    CString boxnum;
public:
    BoxFinder(CString num) : boxnum(num) {}
    bool operator() (BoxRef box) const { 
        CString num;
        box->GetNumber(num);
        return num == boxnum; 
    }
}; // class BoxFinder

}; // end of namespace boxdocument
}; // end of namespace ci

#endif // #ifndef __CI_BOX_H__
