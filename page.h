/*****************************************************************************/
/*  (C) Copyright  TOSHIBA TEC CORPORATION 2008   All Rights Reserved        */
/*****************************************************************************
============================== Source Header =================================
 Filename: page.h
 Revision: com_m#3
 File Spec: EBX:MA6059.A-DEV_SRC;com_m#3
 Originator: 07475
 Last Changed: 17-NOV-2008 14:31:28

  Outline : definition of page operation

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
     Updated:  17-NOV-2008 14:32:51      13848
       Updated attribute(s)
     Created:  17-NOV-2008 14:32:21      13848
       Add new interfaces for 4th build
     Updated:  17-NOV-2008 14:31:28      13848
       Item revision com_m#3 created from revision com_m#2 with status
       $TO_BE_DEFINED
   
   Revision com_m#2 (APPROVED)
     Updated:  01-SEP-2008 17:15:57      13848
       Updated attribute(s)
     Created:  01-SEP-2008 17:14:58      13848
       Update for Ph3.5 1st build
     Updated:  01-SEP-2008 17:12:56      13848
       Item revision com_m#2 created from revision com_m#1 with status
       $TO_BE_DEFINED
   
   Revision com_m#1 (UNIT TESTED)
     Updated:  01-SEP-2008 16:51:15      13848
       Updated attribute(s)
     Created:  19-AUG-2008 14:41:54      13848
       Initial revision
========================== End of Source Header =============================*/

#ifndef __CI_PAGE_H__
#define __CI_PAGE_H__

#include <list>
#include <status.h>
#include <types.h>
#include <CI/OperatingEnvironment/ref.h>
#include <CI/OperatingEnvironment/cstring.h>

namespace ci {
namespace boxdocument {

using ci::operatingenvironment::CString;

class Page;
typedef std::list<operatingenvironment::Ref<Page> > PageList;

DECL_OBJ_REF(Page);

namespace papersize{
	static const char *const PAPER_SIZE_A1 = "A1"; 
	static const char *const PAPER_SIZE_A2 = "A2"; 
	static const char *const PAPER_SIZE_A3 = "A3"; 
	static const char *const PAPER_SIZE_A4 = "A4"; 
	static const char *const PAPER_SIZE_A5 = "A5";
	static const char *const PAPER_SIZE_A6 = "A6";  
	static const char *const PAPER_SIZE_A7 = "A7"; 
	static const char *const PAPER_SIZE_A3Wide = "A3Wide"; 
	static const char *const PAPER_SIZE_B1 = "B1"; 
	static const char *const PAPER_SIZE_B2 = "B2"; 
	static const char *const PAPER_SIZE_B3 = "B3"; 
	static const char *const PAPER_SIZE_B4 = "B4"; 
	static const char *const PAPER_SIZE_B5 = "B5"; 
	static const char *const PAPER_SIZE_B6 = "B6"; 
	static const char *const PAPER_SIZE_B7 = "B7"; 
	static const char *const PAPER_SIZE_LETTER = "LETTER"; 
	static const char *const PAPER_SIZE_LEDGER = "LEDGER"; 
	static const char *const PAPER_SIZE_LEGAL = "LEGAL"; 
	static const char *const PAPER_SIZE_STATEMENT = "STATEMENT"; 
	static const char *const PAPER_SIZE_COMPUTER = "COMPUTER";
	static const char *const PAPER_SIZE_FOLIO = "FOLIO";
	static const char *const PAPER_SIZE_13inchLEGAL = "13inchLEGAL";
	static const char *const PAPER_SIZE_8_5SQ = "8.5SQ";
	static const char *const PAPER_SIZE_LEDGERWide = "LEDGERWide";
	static const char *const PAPER_SIZE_13x19inch = "13x19inch";
	static const char *const PAPER_SIZE_8K = "8K";
	static const char *const PAPER_SIZE_16K = "16K";
	static const char *const PAPER_SIZE_Postcard = "Postcard";
	static const char *const PAPER_SIZE_SRA3 = "SRA3";
	static const char *const PAPER_SIZE_320x460mm = "320x460mm";
	static const char *const PAPER_SIZE_A1_R = "A1-R";
	static const char *const PAPER_SIZE_A2_R = "A2-R";
	static const char *const PAPER_SIZE_A3_R = "A3-R";
	static const char *const PAPER_SIZE_A4_R = "A4-R";
	static const char *const PAPER_SIZE_A5_R = "A5-R";
	static const char *const PAPER_SIZE_A6_R = "A6-R";
	static const char *const PAPER_SIZE_A7_R = "A7-R";
	static const char *const PAPER_SIZE_A3Wide_R = "A3Wide-R";
	static const char *const PAPER_SIZE_B1_R = "B1-R";
	static const char *const PAPER_SIZE_B2_R = "B2-R";
	static const char *const PAPER_SIZE_B3_R = "B3-R";
	static const char *const PAPER_SIZE_B4_R = "B4-R";
	static const char *const PAPER_SIZE_B5_R = "B5-R";
	static const char *const PAPER_SIZE_B6_R = "B6-R";
	static const char *const PAPER_SIZE_B7_R = "B7-R";
	static const char *const PAPER_SIZE_LETTER_R = "LETTER-R";
	static const char *const PAPER_SIZE_LEDGER_R = "LEDGER-R";
	static const char *const PAPER_SIZE_LEGAL_R = "LEGAL-R";
	static const char *const PAPER_SIZE_STATEMENT_R = "STATEMENT-R";
	static const char *const PAPER_SIZE_COMPUTER_R = "COMPUTER-R";
	static const char *const PAPER_SIZE_FOLIO_R = "FOLIO-R";
	static const char *const PAPER_SIZE_13inchLEGAL_R = "13inchLEGAL-R";
	//static const char *const PAPER_SIZE_8.5SQ = "8.5SQ";//since the name for 8.5SQ and 8.5SQ-R is same, only one variable is defined
	static const char *const PAPER_SIZE_LEDGERWide_R = "LEDGERWide-R";
	static const char *const PAPER_SIZE_13x19inch_R = "13x19inch-R";
	static const char *const PAPER_SIZE_8K_R = "8K-R";
	static const char *const PAPER_SIZE_16K_R = "16K-R";
	static const char *const PAPER_SIZE_13_5Legal_R = "13.5Legal-R";
	static const char *const PAPER_SIZE_13_5Legal = "13.5Legal";
	static const char *const PAPER_SIZE_Executive_R = "Executive-R";
	static const char *const PAPER_SIZE_Executive = "Executive";
	static const char *const PAPER_SIZE_Postcard_R = "Postcard-R";
	static const char *const PAPER_SIZE_DOUBLEPOSTCARD_R = "DoublePostcard-R";
	static const char *const PAPER_SIZE_DOUBLEPOSTCARD = "DoublePostcard";
	static const char *const PAPER_SIZE_SRA3_R = "SRA3-R";
	static const char *const PAPER_SIZE_320x460mm_R = "320x460mm-R";
	static const char *const PAPER_SIZE_Undefined = "Undefined";
	static const char *const PAPER_SIZE_Custom = "Custom";
	static const char *const PAPER_SIZE_CustomLongA = "CustomLongA";
	static const char *const PAPER_SIZE_CustomLongB = "CustomLongB";
	static const char *const PAPER_SIZE_CustomScan = "CustomScan"; //COM_SCAN_CUSTOM  EBX_RCR_236
};//end of namespace papersize

/**
 * Paper size definitions
 */
typedef enum ePaperSize {
    A1 = 11, 
    A2 = 21, 
    A3 = 31, 
    A4 = 41, 
    A5 = 51, 
    A6 = 61, 
    A7 = 71, 
    A3_WIDE = 81,
    B1 = 111, 
    B2 = 121, 
    B3 = 131, 
    B4 = 141, 
    B5 = 151, 
    B6 = 161, 
    B7 = 171, 
    LETTER = 201, 
    LEDGER = 211, 
    LEGAL = 221, 
    STATEMENT = 231, 
    COMPUTER = 241, 
    FOLIO = 251, 
    LEGAL13 = 261,  // 13inch LEGAL
    SQUARE8_5 = 271, // 8.5 x 8.5 inch
    LEDGER_WIDE = 281, // LEDGER WIDE
    RECTANGLE13X19 = 291, // 13 x 19 inch
    SIZE_8K = 401, // 8K
    SIZE_16K = 411, // 16K
    POSTCARD = 501,
    SRA3_450 = 701, // SRA3 (320x450)
    SRA3_460 = 711, // SRA3 (320x460)
    A1_R = 10, 
    A2_R = 20, 
    A3_R = 30, 
    A4_R = 40, 
    A5_R = 50, 
    A6_R = 60, 
    A7_R = 70, 
    A3_WIDE_R = 80,
    B1_R = 110, 
    B2_R = 120, 
    B3_R = 130, 
    B4_R = 140, 
    B5_R = 150, 
    B6_R = 160, 
    B7_R = 170, 
    LETTER_R = 200, 
    LEDGER_R = 210, 
    LEGAL_R = 220, 
    STATEMENT_R = 230, 
    COMPUTER_R = 240, 
    FOLIO_R = 250, 
    LEGAL13_R = 260,  // 13inch LEGAL - R
    SQUARE8_5_R = 270, // 8.5 x 8.5 inch - R
    LEDGER_WIDE_R = 280, // LEDGER WIDE - R
    RECTANGLE13X19_R = 290, // 13 x 19 inch
    SIZE_8K_R = 400, // 8K - R
    SIZE_16K_R = 410, // 16K - R
	LEGAL135 = 441, //13.5 Legal
    LEGAL135_R = 440, //13.5 Legal - R
    EXECTIVE = 461, //Exective
    EXECTIVE_R = 460, //Exective - R
    POSTCARD_R = 500,
	DOUBLEPOSTCARD = 651,//DoublePostcard
	DOUBLEPOSTCARD_R = 650,//DoublePostcard-R
    SRA3_450_R = 700, // SRA3 (320x450) - R
    SRA3_460_R = 710, // SRA3 (320x460) - R
    SPECIAL_CUSTOMSCAN  = 890, //COM_SCAN_CUSTOM EBX_RCR_236      
    UNDEF_SIZE = 900, // Undefined
    SPECIAL_SIZE = 910, // Custom
    SPECIAL_LONG800 = 920, // CustomLongA
    SPECIAL_LONG1200 = 930, // CustomLongB    
} PaperSize;

typedef enum eFileFormat {
    FF_MH = 1,
    FF_RECTOR = 5,
    FF_JPEG411 = 6,
    FF_JPEG444 = 7,
    FF_JPEG8BITGRAY = 8,
    FF_MMR = 9,
    FF_PDF = 10,
    FF_TTECJPEGGRAY = 11,
    FF_TTECJPEGCOLOR = 12,
    FF_COPYJPEGGRAY = 13,
    FF_COPYJPEGCOLOR = 14,
    FF_DIB = 15,
    FF_TIFF = 16,
    FF_XPS = 17,
    FF_PNG = 18,
    FF_RAW = 0,
    FF_DOC = 19,
    FF_PPT = 20,
    FF_XLS = 21,
} FileFormat;

typedef enum eOrientation {
    PORTRAIT = 0,
    LANDSCAPE, 
} Orientation;

typedef enum eAngle {
    NOROTATE = 0,
    ROTATE90,
    ROTATE180,
    ROTATE270,
} Angle;

typedef enum eColorMode {
    COLOR = 4,
    GRAY = 2,
    MONO = 1,
} ColorMode;

/**
 * Page class provides facilities of page operation.
 */
class Page 
{
public:
    /** Virtual destructor */
    virtual ~Page() {};
    
    /**
     * put an image to the page
     * actual image is NOT copied to under the document folder if this function
     * has NO owner document.
     * @param[in] path - the image file path to be put
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status PutImage(CString path) = 0;
    
    /**
     * get an image path to the page
     * @param[out] path - local path of the image.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetImage(CString &path) = 0;
    
    /**
     * put a subsampling image to the page
     * actual image is NOT copied to under the document folder if this function
     * has NO owner document.
     * @param[in] path - the subsampling image file path to be put
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status PutSubsamplingImage(CString path) = 0;
    
    /**
     * get a subsampling image path to the page
     * @param[out] path - local path of the image.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetSubsamplingImage(CString &path) = 0;
    
    /**
     * put a thumbnail image to the page
     * actual image is NOT copied to under the document folder if this function
     * has NO owner document.
     * @param[in] path - the subsampling image file path to be put
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status PutThumbnailImage(CString path) = 0;
    
    /**
     * get a thumbnail image path to the page
     * @param[out] path - local path of the image.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetThumbnailImage(CString &path) = 0;
    
    /**
     * set the page property
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
     * get the page property
     * @param[in] key - the property name to be set
     * @param[out] value - the property value
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetWebDAVProperty(CString key, CString &value) = 0;
    
    //-------------------- System File Properties --------------------
    /**
     * set system file properties
     *  the properties are reflected to Document on addition
     * @param[in] systemfile - a pointer to System File
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status SetSystemFile(void* systemfile) = 0;
    
    /**
     * set subsampling system file properties
     *  the properties are reflected to Document on addition
     * @param[in] systemfile - a pointer to System File
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status SetSubSamplingSystemFile(void* systemfile) = 0;
    
    /**
     * set thumbnail system file properties
     *  the properties are reflected to Document on addition
     * @param[in] systemfile - a pointer to System File
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status SetThumbnailSystemFile(void* systemfile) = 0;
    
    /**
     * get resolution of the image
     * @param[out] horizontal - horizontal resolution of the page
     * @param[out] vertical - vertical resolution of the page
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetResolution(int &horizontal, int &vertical) = 0;
    
    /**
     * get size of the image
     * @param[out] width - width (pixels) of the page
     * @param[out] height - height (pixels) of the page
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetImageSize(int &width, int &height) = 0;
    
    /**
     * get adjusted size (internal data size) of the image
     * @param[out] width - width (pixels) of the page
     * @param[out] height - height (pixels) of the page
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetAdjustedImageSize(int &width, int &height) = 0;
    
    /**
     * get size of the paper
     * @param[out] size - the string of paper size
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetPaperSize(CString &size) = 0;
    
    /**
     * get size of the paper
     * @param[out] size - the constant of paper size
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetPaperSize(PaperSize &size) = 0;
    
    /**
     * get file size of the page
     * @param[out] size - size of the page
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetFileSize(uint64 &size) = 0;
    //-------------------- end of System File Properties --------------------
        
    /**
     * set Copy-JPEG parameter
     * this parameter is also stored as file when the page is associated with 
     * Document.
     * @param[in] param - Copy-JPEG parameter to be stored.
     * @param[in] param - size of the Copy-JPEG parameter to be stored. Default size is 66
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status SetCopyJpegParameter(void *param, uint32 size=66) = 0;
    
    /**
     * get file path of Copy-JPEG parameter
     * @param[out] path - file path of Copy-JPEG parameter. if fails, empty 
     *                     string "" will return.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure. e.g. file not found.
     */
    virtual Status GetCopyJpegParameterFilePath(CString &path) = 0;
    
    /**
     * get format of image file
     * @param[out] format - format of image file.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetFileFormat(FileFormat &format) = 0;
    
    /**
     * get format of subsampling image file
     * @param[out] format - format of image file.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetSubsamplingFileFormat(FileFormat &format) = 0;
    
    /**
     * get format of thumbnail file
     * @param[out] format - format of image file.
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetThumbnailFileFormat(FileFormat &format) = 0;
    
    /**
     * get orientation of image file
     * @param[out] orientation - PORTRAIT / LANDSCAPE
     * @return STATUS_OK on success
     *         STATUS_FAILED on failure.
     */
    virtual Status GetOrientation(Orientation &orientation) = 0;
    
    /**
     * get angle of image file
     * @param[out] angle - NOROTATE / ROTATE90 / ROTATE180 / ROTATE270
     * @return STATUS_OK on success
     *         STATUS_FAILED on failure.
     */
    virtual Status GetAngle(Angle &angle) = 0;
    
    /**
     * get color mode of image file
     * @param[out] color - COLOR / GRAY / MONO
     * @return STATUS_OK on success
     *         STATUS_FAILED on failure.
     */
    virtual Status GetColorMode(ColorMode &color) = 0;
}; // class Page

}; // end of namespace boxdocument
}; // end of namespace ci

#endif // #ifndef __CI_PAGE_H__
