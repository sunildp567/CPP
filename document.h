/*****************************************************************************/
/*  (C) Copyright  TOSHIBA TEC CORPORATION 2008   All Rights Reserved        */
/*****************************************************************************
============================== Source Header =================================
 Filename: document.h
 Revision: com_m#4
 File Spec: EBX:MA6058.A-DEV_SRC;com_m#4
 Originator: 07475
 Last Changed: 08-DEC-2008 19:22:56

  Outline : definition of document operation

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
     Updated:  09-DEC-2008 12:59:24      07475
       Updated attribute(s)
     Created:  08-DEC-2008 19:23:26      07475
       document.h:Incorporated defines required for Invalid combination
       check
     Updated:  08-DEC-2008 19:22:56      07475
       Item revision com_m#4 created from revision com_m#3 with status
       $TO_BE_DEFINED
   
   Revision com_m#3 (APPROVED)
     Updated:  17-NOV-2008 14:32:51      13848
       Updated attribute(s)
     Created:  17-NOV-2008 14:32:20      13848
       Add new interfaces for 4th build
     Updated:  17-NOV-2008 14:31:28      13848
       Item revision com_m#3 created from revision com_m#2 with status
       $TO_BE_DEFINED
   
   Revision com_m#2 (APPROVED)
     Updated:  01-SEP-2008 17:15:56      13848
       Updated attribute(s)
     Created:  01-SEP-2008 17:14:58      13848
       Update for Ph3.5 1st build
     Updated:  01-SEP-2008 17:12:55      13848
       Item revision com_m#2 created from revision com_m#1 with status
       $TO_BE_DEFINED
   
   Revision com_m#1 (UNIT TESTED)
     Updated:  01-SEP-2008 16:51:14      13848
       Updated attribute(s)
     Created:  19-AUG-2008 14:41:43      13848
       Initial revision
========================== End of Source Header =============================*/

#ifndef __CI_DOCUMENT_H__
#define __CI_DOCUMENT_H__
#include <set>
#include <list>
#include <map>
#include <types.h>
#include <CI/status.h>
#include <CI/OperatingEnvironment/ref.h>
#include <CI/OperatingEnvironment/cstring.h>
#include <CI/HierarchicalDB/hierarchicaldb.h>

#include <CI/BoxDocument/progress.h>
#include <CI/BoxDocument/page.h>

namespace ci {
namespace boxdocument {

using ci::operatingenvironment::CString;

/**
 * DocStatus shows document status
 */
typedef enum eDocStatus {
    CREATING = 0,
    READY,
    EDITING,
    USING,
    DELETING,
    WAITING,
    RESERVING,
} DocStatus;

DECL_OBJ_REF(Document);
DECL_OBJ_REF(DocumentProperties);

typedef std::list<operatingenvironment::Ref<Document> > DocumentList;
typedef std::list<operatingenvironment::Ref<DocumentProperties> > DocumentPropertiesList;

typedef std::set<PaperSize> PaperSizeSet;

/**
 * Combination of jobType and colorMode
 */
typedef enum eJobTypeColor {
    CopyColor = 0,
    CopyGray,
    CopyMono,
    PrintColor,
    PrintMono,
    ScanColor,
    ScanGray,
    ScanMono,
    FaxMono,
} JobTypeColor;

/* Support for ScanPreview Enhancement - EBX_RCR_233 */
typedef enum eRotateAngle {
	ROTATEBY0 = 0,
	ROTATEBY90,
	ROTATEBY180,
	ROTATEBY270,
} RotateAngle;
typedef std::set<JobTypeColor> JobTypeColorSet;

typedef std::map<PaperSize, int> PaperSizeMap; // count each paper size
typedef std::map<ColorMode, int> ColorModeMap; // count each colorMode
typedef std::map<CString, int> JobTypeMap; // count each job type
typedef std::map<int, int> ResolutionMap; // count each resolution

/**
 * Document class provides facilities of document operation.
 */
class Document 
{
public:
    /** Virtual destructor */
    virtual ~Document() {};
    
    //-------------------- document status methods --------------------
    /**
     * get status of the document
     * @param[out] st - current status of the document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     */
    virtual Status GetStatus(DocStatus &st) = 0;
    
    /**
     * revert the document status back to CREATING
     * change status from READY to CREATING. if document status is not READY, 
     * it will fal.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     */
    virtual Status ReCreate() = 0;
    
    /**
     * change status after creating the document
     * change document status from CREATING to READY. if document status is 
     * NOT CREATING, it will fail.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     */
    virtual Status EndCreating() = 0;
    
    /**
     * change status for using the document
     * change document status from READY or RESERVING to USING. if document status is 
     * NOT COMPLETED, it will fail.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     */
    virtual Status Use() = 0;
    
    /**
     * change status after using the document
     * change document status from USING to READY when any document is NOT 
     * using the document. some documents are still using, the document status 
     * is unchanged. if document status is NOT USING, it will fail.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     */
    virtual Status EndUsing() = 0;
    
    /**
     * start to edit the document
     * change document status from READY to EDITING. if document status is 
     * NOT READY, it will fail.
     * when this method is called, delta document is created. On saving, 
     * delta documents will be overwritten to original documents. 
     * @param[out] editor - instance of DocumentEditor, or NULL
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_USER_EDITING if another user is already editing.
     */
    virtual Status Edit() = 0;
    
    /**
     * save the delta document. 
     * change document status from EDITING to READY. if document status is 
     * NOT EDITING, it will fail.
     * when this method is called, unlock delta document. delta documents 
     * will be overwritten to original documents. after that all delta 
     * documents will be deleted. 
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status Save() = 0;
    
    /**
     * save the delta document. 
     * change document status from EDITING to READY. if document status is 
     * NOT EDITING, it will fail.
     * when this method is called, unlock delta document. delta documents 
     * will be overwritten to original documents. after that all delta 
     * documents will be deleted. 
     * @param[out] progress - user can get operation progress from this.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status Save(ProgressRef &progress) = 0;
    
    /**
     * save the edited document with other name
     * change document status from EDITING to READY. if document status is 
     * NOT EDITING, it will fail.
     * when this method is called, unlock delta document. delta documents 
     * will be overwritten to original documents. after that all delta 
     * documents will be deleted. 
     * @param[in] new_name - merged document save as the name
     * @param[in] resourcebasepath - save to the this folder, if it is set.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status SaveAs(CString new_name, CString resourcebasepath = "") = 0;
    /**
     * save the edited document with other name
     * change document status from EDITING to READY. if document status is 
     * NOT EDITING, it will fail.
     * when this method is called, unlock delta document. delta documents 
     * will be overwritten to original documents. after that all delta 
     * documents will be deleted. 
     * @param[out] progress - user can get operation progress from this.
     * @param[in] new_name - merged document save as the name
     * @param[in] resourcebasepath - save to the this folder, if it is set.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status SaveAs(ProgressRef &progress, 
                          CString new_name, 
                          CString resourcebasepath = "") = 0;
    
    /**
     * cancel editing delta document
     * change document status from EDITING to READY. if document status is 
     * NOT EDITING, it will fail.
     * when this method is called, unlock delta document. all delta 
     * documents will be deleted. 
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     */
    virtual Status CancelEdit() = 0;
    
    //-------------------- end of document status methods --------------------

    /**
     * get new page instance. 
     * this page is not related with any Document. use Document::AppendPage()
     * after setting page properties.
     * @param[out] page - new instance of Page class
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status CreatePage(PageRef &page) = 0;

    /**
     * get page instance in the document
     * @param[in] pageno - page number
     * @param[out] page - instance of Page class
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetPage(int pageno, PageRef &page) = 0;
    
    /**
     * get new page instance. the new page is added as last page.
     * images of the page is copied when this method is called.
     * @param[in] page - instance of Page class
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status AppendPage(PageRef page) = 0;
  	
	/**
     * insert page to the document
     * @param[in] pageno - new page number of the inserted page 
     *                      document[a1, a2, a3] -- InsertPage(2, b1) ->
     *                      docuemnt[a1, b1, a2, a3])
     * @param[in] page  - a page to be added. If image path as page property 
     *                     is set, the image  will be copied to under the 
     *                     document folder.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status InsertPage(int pageno, PageRef page) = 0;
    
    /**
     * insert pages to the document
     * @param[in] pageno - page number to be inserted
                           (first page number of the inserted page)
     * @param[in] pages  - pages to be added. If an image path is set, 
     *                      the image  will be copied to under the document 
     *                      folder.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status InsertPage(int pageno, PageList pages) = 0;
    
    /**
     * insert blank page to the document
     * the page properties are copied from previous page (if inserting to 
     * first page, the page properties are copied from next one)
     * @param[in] pageno - new page number of the inserted page(see InsertPage)
     * @param[in] size - paper size to be inserted
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status InsertBlankPage(int pageno, PaperSize size) = 0;
    
    /**
     * replace page in the document
     * @param[in] pageno - new page number of the replaced page 
     *                      document[a1, a2, a3] -- InsertPage(2, b1) ->
     *                      docuemnt[a1, b1, a3])
     * @param[in] page  - a page to be added. If image path as page property 
     *                     is set, the image  will be copied to under the 
     *                     document folder.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status ReplacePage(int pageno, PageRef page) = 0;
    
    /**
     * replace pages in the document
     * @param[in] pageno - page number to be replaced
                           (first page number of the replaced page)
     * @param[in] pages  - pages to be added. If an image path is set, 
     *                      the image  will be copied to under the document 
     *                      folder.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status ReplacePage(int pageno, PageList pages) = 0;
	
    /**
     * get new page instance. the new page is added as last page.
     * images of the page is linked when this method is called.
     * @param[in] page - instance of Page class
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status AppendPageByLink(PageRef page) = 0;
    
    /**
     * insert page to the document
     * @param[in] pageno - new page number of the inserted page 
     *                      document[a1, a2, a3] -- InsertPage(2, b1) ->
     *                      docuemnt[a1, b1, a2, a3])
     * @param[in] page  - a page to be added. If image path as page property 
     *                     is set, the image  will be linked under the 
     *                     document folder.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status InsertPageByLink(int pageno, PageRef page) = 0;
    
    /**
     * replace page in the document
     * @param[in] pageno - new page number of the replaced page 
     *                      document[a1, a2, a3] -- InsertPage(2, b1) ->
     *                      docuemnt[a1, b1, a3])
     * @param[in] page  - a page to be added. If image path as page property 
     *                     is set, the image  will be linked under the 
     *                     document folder.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status ReplacePageByLink(int pageno, PageRef page) = 0;
    
    /**
     * get an instance of PageList
     * @param[out] list - list of pages. 
     *                     this list have snapshot of each page instances.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetPageList(PageList &list) = 0;
    
    /**
     * get an instance of PageList
     * @param[out] list - list of pages. 
     *                     this list have snapshot of each page instances.
     * @param[in] from - return list from this value. !! 1-origin !!
     * @param[in] size - list size, if "from" + "size" is bigger than the 
     *                    number of all pages, return list size will be smaller
     *                    than "size".
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetPageList(PageList &list, 
                                unsigned int from, unsigned int size) = 0;
    /**
     * get an instance of PageList. Using these objects user can access the
     * following page properties.
     * jobType
     * paperSize
     * resolution
     * image size
     * size
     * thumbnail
     * colorMode
     * creationDate
     * lastModifiedDate
     * cutPage
     *
     * @param[out] list - list of pages. 
     *                     this list have snapshot of each page instances.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetViewPageList(PageList &list) = 0;
    
    /**
     * get an instance of PageList. Using these objects user can access the
     * following page properties.
     * jobType
     * paperSize
     * resolution
     * image size
     * size
     * thumbnail
     * colorMode
     * creationDate
     * lastModifiedDate
     * cutPage
     *
     * @param[out] list - list of pages. 
     *                     this list have snapshot of each page instances.
     * @param[in] from - return list from this value. !! 1-origin !!
     * @param[in] size - list size, if "from" + "size" is bigger than the 
     *                    number of all pages, return list size will be smaller
     *                    than "size".
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetViewPageList(PageList &list, 
                                unsigned int from, unsigned int size) = 0;
    
    //-------------------- System File Operation --------------------
    /**
     * put system file to the document folder
     * @param[in] path - the path of system file
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status PutSystemFile(CString path) = 0;
    
    /**
     * set properties from system file on memory
     * some document properties are set as WebDAV properties. Also, some page 
     * properties are set if the main image is copied to the document folder.
     * @param[in] systemfile - a pointer to System File
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status SetWebDAVPropertyFromSystemFile(void* systemfile) = 0;
    
    /**
     * get a path of the system file
     * @param[out] path - local path of the system file.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetSystemFile(CString &path) = 0;
    
    /**
     * put subsampling system file to the document folder
     * @param[in] path - the path of system file
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status PutSubSamplingSystemFile(CString path) = 0;
    
    /**
     * get a path of the subsampling system file
     * @param[out] path - local path of the system file.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetSubsamplingSystemFile(CString &path) = 0;
    
    /**
     * put thumbnail system file to the document folder
     * @param[in] path - the path of system file
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status PutThumbnailSystemFile(CString path) = 0;
    
    /**
     * get a path of the thumbnail system file
     * @param[out] path - local path of the system file.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetThumbnailSystemFile(CString &path) = 0;

    /**
     * get a path of the first thumbnail image
     * @param[out] path - local path of the first thumbnail image.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status  GetThumbnailImage(CString &path) = 0;
    
    //-------------------- end of System File Operation --------------------
    
    /**
     * set HDB Document of Workflow Execution Parameter. 
     * @param[in] node - WEP node to save
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status SetWEPDocument(dom::NodeRef node) = 0;
    
    /**
     * get WEP Document node from XPath. 
     * @param[out] node - node to be found
     * @param[in] xpath - the XPath to search for
                          if empty string, return root node.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     * @deprecated
     */
    virtual Status GetWEPDocument(dom::NodeRef &node, CString xpath = "") = 0;
    
    /**
     * get WEP document ID
     *  BoxDocument create HDB document and return document ID.
     * @param[out] documentID - HDB document ID
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     * @note user need to delete this document using document ID.
     */
    virtual Status GetWEPDocument(CString& documentID) = 0;
    
    /**
     * set document property
     * @param[in] key - the property name to be set
     * @param[in] value - the property value to be set
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status SetWebDAVProperty(CString key, CString value) = 0;
    
    /**
     * set document property
     * @param[in] key - the property name to be set
     * @param[in] value - the property value to be set
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status SetWebDAVProperty(CString key, int value) = 0;
    
    /**
     * get document property
     * @param[in] key - the property name to be set
     * @param[out] value - the property value
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetWebDAVProperty(CString key, CString &value) = 0;

    /**
     * set a name of the document
     * When a folder has the name already exists, it will fail.
     * @param[in] name - a name to be set
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     *         STATUS_RESOURCE_WITH_SAME_NAME_EXISTS if the resource with that given name already exists in the box.
     */
    virtual Status SetName(CString name) = 0;
    
    /**
     * get a name of the documentr
     * @param[out] name - a name of the container
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetName(CString &name) = 0;
    
    /**
     * get a set of paper size in Document 
     * @param[out] paperset - a set of paper size in Document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetPaperSizeSet(PaperSizeSet &paperset) = 0;
    
    /**
     * get a set of jobType and colorMode combination in Document 
     * @param[out] jcset - a set of jobType and colorMode combination
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetJobTypeColorSet(JobTypeColorSet &jcset) = 0;
    
    //-------------------- System File Properties --------------------
    /**
     * get total page of the document
     * @param[out] total - total page of the document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetTotalPage(int &total) = 0;
    
    /**
     * get total size of the document
     * @param[out] total - total size of the document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetTotalSize(uint64 &total) = 0;
    //-------------------- end of System File Properties --------------------
    
    /**
     * cut the page to clipboard
     * if document status is NOT EDITING, it will fail.
     * @param[in] pageno - source page number
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CutPage(int pageno) = 0;
    
    /**
     * cut the pages to clipboard
     * if document status is NOT EDITING, it will fail.
     * @param[in] pages - vector of source page numbers
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CutPage(std::vector<int> pages) = 0;
    
    /**
     * cut the page to clipboard
     * if document status is NOT EDITING, it will fail.
     * @param[out] progress - user can get operation progress from this.
     * @param[in] pageno - source page number
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CutPage(ProgressRef& progress, int pageno) = 0;
    
    /**
     * cut the pages to clipboard
     * if document status is NOT EDITING, it will fail.
     * @param[out] progress - user can get operation progress from this.
     * @param[in] pages - vector of source page numbers
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CutPage(ProgressRef& progress, std::vector<int> pages) = 0;
    
    /**
     * copy the page to clipboard
     * @param[in] pageno - source page number
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CopyPage(int pageno) = 0;
    
    /**
     * copy the pages to clipboard
     * @param[in] pages - vector of source page numbers
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CopyPage(std::vector<int> pages) = 0;
    
    /**
     * copy the page to clipboard
     * @param[out] progress - user can get operation progress from this.
     * @param[in] pageno - source page number
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CopyPage(ProgressRef& progress, int pageno) = 0;
    
    /**
     * copy the pages to clipboard
     * @param[out] progress - user can get operation progress from this.
     * @param[in] pages - vector of source page numbers
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status CopyPage(ProgressRef& progress, std::vector<int> pages) = 0;
    
    /**
     * paste the page(s) from clipboard
     * if document status is NOT EDITING, it will fail.
     * @param[in] pageno - page number to insert
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status PastePage(int pageno) = 0;
    
    /**
     * paste the page(s) from clipboard
     * if document status is NOT EDITING, it will fail.
     * @param[out] progress - user can get operation progress from this.
     * @param[in] pageno - page number to insert
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
    virtual Status PastePage(ProgressRef& progress, int pageno) = 0;
    
    /**
     * delete page
     * @param[in] pageno - delete page number. after deletion, the pages that 
     *                     have greater page number are off to the front.
     * @param[in] size - delete page size (default = 1)
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     *         STATUS_OUT_OF_RANGE if the user specified page doesn't exist
     */
    virtual Status DeletePage(int pageno, int delete_size = 1) = 0;
    
    /**
     * delete page
     * @param[in] pages - vector of delete page numbers. after deletion, 
     *                     the pages that have greater page numbers are off to
     *                     the front.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
	 *         STATUS_OUT_OF_RANGE if any of the user specified page doesn't exist
     */
    virtual Status DeletePage(std::vector<int> pages) = 0;
    
    /**
     * delete page
     * @param[out] progress - user can get operation progress from this.
     * @param[in] pageno - delete page number. after deletion, the pages that 
     *                     have greater page number are off to the front.
     * @param[in] size - delete page size (default = 1)
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
	 *         STATUS_OUT_OF_RANGE if the user specified page doesn't exist
     */
    virtual Status DeletePage(ProgressRef& progress, 
                              int pageno, 
                              int delete_size = 1) = 0;
    
    /**
     * delete page
     * @param[out] progress - user can get operation progress from this.
     * @param[in] pages - vector of delete page numbers. after deletion, 
     *                     the pages that have greater page numbers are off to
     *                     the front.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
	 *         STATUS_OUT_OF_RANGE if any of the user specified page doesn't exist
     */
    virtual Status DeletePage(ProgressRef& progress, 
                              std::vector<int> pages) = 0;

    /**
     * get a map of paper size in Document 
     * @param[out] papermap - a map of paper size in Document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetPaperSizeMap(PaperSizeMap &papermap) = 0;

    /**
     * get a map of color mode in Document 
     * @param[out] colormap - a map of color mode in Document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetColorModeMap(ColorModeMap &colormap) = 0;

    /**
     * get a map of job type in Document 
     * @param[out] jobmap - a map of job type in Document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetJobTypeMap(JobTypeMap &jobmap) = 0;

    /**
     * get a map of horizontal resolution in Document 
     * @param[out] hrmap - a map of horizontal resolution in Document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetHorizontalResolutionMap(ResolutionMap &hrmap) = 0;


    /**
     * get a map of vertical resolution in Document 
     * @param[out] vrmap - a map of vertical resolution in Document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetVerticalResolutionMap(ResolutionMap &vrmap) = 0;

    /**
     * set input page count of the document
     * @param[in] count - input page count of the document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status SetInputPageCount(int count) = 0;

    /**
     * get input page count of the document. 
     * @param[out] count - input page count of the document. default value will be 0 if no value is set
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetInputPageCount(int &count) = 0;
	
    /**
     * change status for using the document
     * change document status from READY to RESERVING. if document status is 
     *   NOT READY, it will fail.
     * - when Reserve() is called on RESERVING, it will fail as well.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     * @note: Reserve as per the requirement should not be used for EFilingBoxes.
     *   Behavior is undefined, as no specific checks are performed for BoxType.
     */
    virtual Status Reserve() = 0;
    
    /**
     * change status after using the document
     * change document status from RESERVING to READY
     *  & if document status is NOT RESERVING, it will fail.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     */
    virtual Status EndReserving() = 0;
   
	/**
     * paste the page(s) faster from clipboard
     * if document status is NOT EDITING, it will fail.
     * @param[in] pageno - page number to insert
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
	virtual Status FasterPastePage(int pageno) = 0;

	/**
     * paste the page(s) faster from clipboard
     * if document status is NOT EDITING, it will fail.
     * @param[out] progress - user can get operation progress from this.
     * @param[in] pageno - page number to insert
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure,
     *         STATUS_DISK_FULL if there is not enough space on the disk.
     */
	virtual Status FasterPastePage(ProgressRef& progress, int pageno) = 0;

	/* Support for ScanPreview Enhancement Start - EBX_RCR_233 */

	/**
	 * moves the page from source to destination during Scan Preview	 
	 * @param[in] srcpageno    - The source page number to be moved from  
	 * @param[in] dstpageno    - The destination page number to which the source page has to be moved to
	 * @return STATUS_OK on success,
	 *         STATUS_FAILED on failure.
	 *         STATUS_OUT_OF_RANGE if the user specified srcpage doesn't exist/
	 *                             if the user specified dstpageno is out of range
	 * Note : MovePage is not supported for XPS & DIB file formats
	 */

	virtual Status MovePage(int srcpageNo, int dstpageNo ) = 0;

	/**
	 * get rotation angle of the image file during scan preview
	 * @param[in]  pageno - page number of the page that has to be rotated
	 * @param[out] rangle  - NOROTATE / ROTATE90 / ROTATE180 / ROTATE270
	 * @return STATUS_OK on success
	 *         STATUS_FAILED on failure.
	 *         STATUS_OUT_OF_RANGE if the user specified page doesn't exist	 
	 * Note : GetRotation return zero degrees if rotationAngle property doesn't exist 
	 */

	virtual Status GetRotation(int pageNo,RotateAngle &rangle) = 0;

	/**
	 * Rotates the page by 90 degrees clockwise during Scan preview
	 * @param[in]  pageno    - page number of the page that has to be rotated 
	 * @return STATUS_OK on success,
	 *         STATUS_FAILED on failure.
	 *         STATUS_OUT_OF_RANGE if the user specified page doesn't exist
	 * Note : Only PDF file formats (PDF or Slim PDF or PDF/A or PDF/A-2) are supported for Rotate page
	 */
	virtual Status Rotate(int pageNo) = 0;
	/* Support for ScanPreview Enhancement End - EBX_RCR_233 */

	/**
	 *Added to support EBX_RCR_235 FAX Preview
	 * set fax preview property for document
	 * default fax preview property is "false" 
	 * @param[in] value - the property value
	 * @return STATUS_OK on success,
	 *         STATUS_FAILED on failure.
	 */
	virtual Status SetFaxPreviewProperty(bool value) = 0;

	/**
	 *Added to support EBX_RCR_235 FAX Preview
	 * get fax preview property for document
	 * default fax preview property is "false" 
	 * @param[out] value - the property value
	 * @return STATUS_OK on success,
	 *         STATUS_FAILED on failure.
	 */
	virtual Status GetFaxPreviewProperty(bool &value) = 0;

    

}; // class Document

class DocumentProperties
{
public:
    /** Virtual destructor */
    virtual ~DocumentProperties() {};
    
    /**
     * get a name of the document
     * @param[out] name - a name of the container
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetName(CString &name) = 0;
    
    /**
     * get total page of the document
     * @param[out] total - total page of the document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetTotalPage(int &total) = 0;
    
    /**
     * get "from" property of the document
     * @param[out] from - "from" property of the document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetFromProperty(CString &from) = 0;
    
    /**
     * get reception time of the document
     * @param[out] receptiontime - reception time of the document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetReceptionTime(CString &receptiontime) = 0;
    
    /**
     * get reception number of the document
     * @param[out] receptionnum - reception number of the document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetReceptionNumber(CString &receptionnum) = 0;
	
    /**
     * get fromString of the document
     * @param[out] fromString - fromString of the document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetFromString(CString &fromString) = 0;
    /**
     * get fromStringFirstName of the document
     * @param[out] firstName - firstName of the document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetFromStringFirstName(CString &firstName) = 0;

    /**
     * get fromStringLastName of the document
     * @param[out] lastName - lastName of the document
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetFromStringLastName(CString &lastName) = 0;

    /**
     * get the status for FAX received data.
     * @param[out] receivedData - the status for FAX received data.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @Note - It is available via GetDocumentList
     */
    virtual Status GetStatusOfReceivedData(CString &receivedData) = 0;
    
    /**
     * get the status for hard copy
     * @param[out] hardCopy - the status for hard copy.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @Note - It is available via GetDocumentList
     */
    virtual Status GetStatusOfHardCopy(CString &hardCopy) = 0;

    /**
     * get the status for relay report
     * @param[out] relayReport - the status for relay report.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @Note - It is available via GetDocumentList
     */
    virtual Status GetStatusOfRelayReport(CString &relayReport) = 0;

    /**
     * set the status for FAX received data.
     * @param[in] receivedData - the status for FAX received data.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @Note - It is available via GetDocumentList
     */
    virtual Status SetStatusOfReceivedData(CString receivedData) = 0;

    /**
     * set the status for hard copy.
     * @param[in] hardCopy - the status for hard copy.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @Note - It is available via GetDocumentList
     */
    virtual Status SetStatusOfHardCopy(CString hardCopy) = 0;

    /**
     * set the status for relay report.
     * @param[in] relayReport - the status for relay report
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     * @Note - It is available via GetDocumentList
     */
    virtual Status SetStatusOfRelayReport(CString relayReport) = 0;
    
    /**
     * get the status for polling transmission
     * @param[out] pollingTransmission - the status for polling transmission
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetStatusOfPollingTransmission(CString &pollingTransmission) = 0;

    /**
     * set the status for polling transmission
     * @param[in] pollingTransmission - the status for polling transmission
     * return STATUS_OK on success.
     *        STATUS_FAILED on failure.
     */
    virtual Status SetStatusOfPollingTransmission(CString pollingTransmission) = 0; 

}; // class DocumentProperties

class DocFinder {
    CString docname;
public:
    DocFinder(CString name) : docname(name) {}
    bool operator() (DocumentRef doc) const { 
        CString name;
        doc->GetName(name);
        return name == docname; 
    }
    bool operator() (DocumentPropertiesRef docprop) const { 
        CString name;
        docprop->GetName(name);
        return name == docname; 
    }
}; // class DocFinder

}; // end of namespace boxdocument
}; // end of namespace ci

#endif // #ifndef __CI_DOCUMENT_H__
