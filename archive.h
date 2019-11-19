/*****************************************************************************/
/*  (C) Copyright  TOSHIBA TEC CORPORATION 2008   All Rights Reserved        */
/*****************************************************************************
============================== Source Header =================================
 Filename: archive.h
 Revision: com#2.0.1.1
 File Spec: EBX:A11005.A-DEV_SRC;com#2.0.1.1
 Originator: Z13152EC
 Last Changed: 17-DEC-2009 10:04:50

  Outline : definition of box operation

*/
/*----------------------------------------------------------------------------
 Related Change Documents:
   Not related to any Request
------------------------------------------------------------------------------
 Related Baselines:
   1:
   	Baseline:      "EBX:SCI_PHASE5_V42517_PRE_20100107_1820"
   	Creation Date: 07-JAN-2010 18:28:58
   	Description:   Baseline SCI_PHASE5_V42517_PRE_20100107_1820.AAAA
   
   2:
   	Baseline:      "EBX:SCI_PHASE5_V42517_PRE_20100107_1749"
   	Creation Date: 07-JAN-2010 17:58:20
   	Description:   Baseline SCI_PHASE5_V42517_PRE_20100107_1749.AAAA
   
   3:
   	Baseline:      "EBX:SCI_PHASE5_V42517_PRE_20100107_1038"
   	Creation Date: 07-JAN-2010 10:47:18
   	Description:   Baseline SCI_PHASE5_V42517_PRE_20100107_1038.AAAA
   
   4:
   	Baseline:      "EBX:DAILY_V5999_20100107_0500"
   	Creation Date: 07-JAN-2010 05:09:16
   	Description:   Baseline DAILY_V5999_20100107_0500.AAAA
   
   5:
   	Baseline:      "EBX:DAILY_V4999_20100107_0400"
   	Creation Date: 07-JAN-2010 04:09:44
   	Description:   Baseline DAILY_V4999_20100107_0400.AAAA
   
   6:
   	Baseline:      "EBX:DAILY_V5999_20100106_1400"
   	Creation Date: 06-JAN-2010 14:09:04
   	Description:   Baseline DAILY_V5999_20100106_1400.AAAA
   
   7:
   	Baseline:      "EBX:TUESDAY"
   	Creation Date: 06-JAN-2010 13:37:03
   	Description:   Baseline TUESDAY.AAAA
   
   8:
   	Baseline:      "EBX:DAILY_V4999_20100106_1300"
   	Creation Date: 06-JAN-2010 13:09:05
   	Description:   Baseline DAILY_V4999_20100106_1300.AAAA
   
   9:
   	Baseline:      "EBX:DAILY_V5999_20100106_0500"
   	Creation Date: 06-JAN-2010 05:09:14
   	Description:   Baseline DAILY_V5999_20100106_0500.AAAA
   
   10:
   	Baseline:      "EBX:DAILY_V4999_20100106_0400"
   	Creation Date: 06-JAN-2010 04:09:33
   	Description:   Baseline DAILY_V4999_20100106_0400.AAAA
   
   11:
   	Baseline:      "EBX:DAILY_V5999_20100105_1400"
   	Creation Date: 05-JAN-2010 14:09:11
   	Description:   Baseline DAILY_V5999_20100105_1400.AAAA
   
   12:
   	Baseline:      "EBX:DAILY_V4999_20100105_1300"
   	Creation Date: 05-JAN-2010 13:09:05
   	Description:   Baseline DAILY_V4999_20100105_1300.AAAA
   
   13:
   	Baseline:      "EBX:MONDAY"
   	Creation Date: 05-JAN-2010 11:02:37
   	Description:   Baseline MONDAY.AAAA
   
   14:
   	Baseline:      "EBX:DAILY_V5999_20100105_0500"
   	Creation Date: 05-JAN-2010 05:08:59
   	Description:   Baseline DAILY_V5999_20100105_0500.AAAA
   
   15:
   	Baseline:      "EBX:DAILY_V4999_20100105_0400"
   	Creation Date: 05-JAN-2010 04:09:30
   	Description:   Baseline DAILY_V4999_20100105_0400.AAAA
   
   16:
   	Baseline:      "EBX:DAILY_V5999_20100104_1400"
   	Creation Date: 04-JAN-2010 14:09:12
   	Description:   Baseline DAILY_V5999_20100104_1400.AAAA
   
   17:
   	Baseline:      "EBX:DAILY_V4999_20100104_1300"
   	Creation Date: 04-JAN-2010 13:08:42
   	Description:   Baseline DAILY_V4999_20100104_1300.AAAA
   
   18:
   	Baseline:      "EBX:DAILY_V5999_20100104_0500"
   	Creation Date: 04-JAN-2010 05:08:59
   	Description:   Baseline DAILY_V5999_20100104_0500.AAAA
   
   19:
   	Baseline:      "EBX:DAILY_V4999_20100104_0400"
   	Creation Date: 04-JAN-2010 04:08:56
   	Description:   Baseline DAILY_V4999_20100104_0400.AAAA
   
   20:
   	Baseline:      "EBX:0.0.9.177"
   	Creation Date: 03-JAN-2010 12:01:41
   	Description:   Baseline 0.0.9.177.AAAA
   
   21:
   	Baseline:      "EBX:0.0.9.176"
   	Creation Date: 02-JAN-2010 12:01:58
   	Description:   Baseline 0.0.9.176.AAAA
   
   22:
   	Baseline:      "EBX:DAILY_V5999_20100101_1400"
   	Creation Date: 01-JAN-2010 14:08:32
   	Description:   Baseline DAILY_V5999_20100101_1400.AAAA
   
   23:
   	Baseline:      "EBX:DAILY_V4999_20100101_1300"
   	Creation Date: 01-JAN-2010 13:08:35
   	Description:   Baseline DAILY_V4999_20100101_1300.AAAA
   
   24:
   	Baseline:      "EBX:0.0.9.175"
   	Creation Date: 01-JAN-2010 12:02:10
   	Description:   Baseline 0.0.9.175.AAAA
   
   25:
   	Baseline:      "EBX:DAILY_V5999_20100101_0500"
   	Creation Date: 01-JAN-2010 05:09:08
   	Description:   Baseline DAILY_V5999_20100101_0500.AAAA
   
   26:
   	Baseline:      "EBX:DAILY_V4999_20100101_0400"
   	Creation Date: 01-JAN-2010 04:10:02
   	Description:   Baseline DAILY_V4999_20100101_0400.AAAA
   
   27:
   	Baseline:      "EBX:0.0.9.174"
   	Creation Date: 30-DEC-2009 12:02:12
   	Description:   Baseline 0.0.9.174.AAAA
   
   28:
   	Baseline:      "EBX:DAILY_V5999_20091230_0500"
   	Creation Date: 30-DEC-2009 05:08:31
   	Description:   Baseline DAILY_V5999_20091230_0500.AAAA
   
   29:
   	Baseline:      "EBX:DAILY_V4999_20091230_0400"
   	Creation Date: 30-DEC-2009 04:08:30
   	Description:   Baseline DAILY_V4999_20091230_0400.AAAA
   
   30:
   	Baseline:      "EBX:DAILY_V5999_20091229_1400"
   	Creation Date: 29-DEC-2009 14:08:31
   	Description:   Baseline DAILY_V5999_20091229_1400.AAAA
   
   31:
   	Baseline:      "EBX:DAILY_V4999_20091229_1300"
   	Creation Date: 29-DEC-2009 13:08:25
   	Description:   Baseline DAILY_V4999_20091229_1300.AAAA
   
   32:
   	Baseline:      "EBX:DAILY_V5999_20091229_0500"
   	Creation Date: 29-DEC-2009 05:08:36
   	Description:   Baseline DAILY_V5999_20091229_0500.AAAA
   
   33:
   	Baseline:      "EBX:DAILY_V4999_20091229_0400"
   	Creation Date: 29-DEC-2009 04:08:34
   	Description:   Baseline DAILY_V4999_20091229_0400.AAAA
   
   34:
   	Baseline:      "EBX:DAILY_V5999_20091228_1400"
   	Creation Date: 28-DEC-2009 14:08:18
   	Description:   Baseline DAILY_V5999_20091228_1400.AAAA
   
   35:
   	Baseline:      "EBX:DAILY_V4999_20091228_1300"
   	Creation Date: 28-DEC-2009 13:08:22
   	Description:   Baseline DAILY_V4999_20091228_1300.AAAA
   
   36:
   	Baseline:      "EBX:DAILY_V5999_20091228_0500"
   	Creation Date: 28-DEC-2009 05:08:21
   	Description:   Baseline DAILY_V5999_20091228_0500.AAAA
   
   37:
   	Baseline:      "EBX:DAILY_V4999_20091228_0400"
   	Creation Date: 28-DEC-2009 04:08:08
   	Description:   Baseline DAILY_V4999_20091228_0400.AAAA
   
   38:
   	Baseline:      "EBX:0.0.9.173"
   	Creation Date: 27-DEC-2009 13:01:29
   	Description:   Baseline 0.0.9.173.AAAA
   
   39:
   	Baseline:      "EBX:0.0.9.172"
   	Creation Date: 26-DEC-2009 13:01:57
   	Description:   Baseline 0.0.9.172.AAAA
   
   40:
   	Baseline:      "EBX:DAILY_V5999_20091226_0500"
   	Creation Date: 26-DEC-2009 05:07:49
   	Description:   Baseline DAILY_V5999_20091226_0500.AAAA
   
   41:
   	Baseline:      "EBX:DAILY_V4999_20091226_0400"
   	Creation Date: 26-DEC-2009 04:08:02
   	Description:   Baseline DAILY_V4999_20091226_0400.AAAA
   
   42:
   	Baseline:      "EBX:DAILY_V5999_20091225_1400"
   	Creation Date: 25-DEC-2009 14:07:52
   	Description:   Baseline DAILY_V5999_20091225_1400.AAAA
   
   43:
   	Baseline:      "EBX:DAILY_V4999_20091225_1300"
   	Creation Date: 25-DEC-2009 13:07:56
   	Description:   Baseline DAILY_V4999_20091225_1300.AAAA
   
   44:
   	Baseline:      "EBX:0.0.9.171"
   	Creation Date: 25-DEC-2009 13:01:45
   	Description:   Baseline 0.0.9.171.AAAA
   
   45:
   	Baseline:      "EBX:DAILY_V5999_20091225_0500"
   	Creation Date: 25-DEC-2009 05:07:57
   	Description:   Baseline DAILY_V5999_20091225_0500.AAAA
   
   46:
   	Baseline:      "EBX:DAILY_V4999_20091225_0400"
   	Creation Date: 25-DEC-2009 04:08:10
   	Description:   Baseline DAILY_V4999_20091225_0400.AAAA
   
   47:
   	Baseline:      "EBX:DAILY_V5999_20091224_2030"
   	Creation Date: 24-DEC-2009 20:37:42
   	Description:   Baseline DAILY_V5999_20091224_2030.AAAA
   
   48:
   	Baseline:      "EBX:DAILY_V4999_20091224_2000"
   	Creation Date: 24-DEC-2009 20:07:46
   	Description:   Baseline DAILY_V4999_20091224_2000.AAAA
   
   49:
   	Baseline:      "EBX:DAILY_V5999_20091224_1310"
   	Creation Date: 24-DEC-2009 13:17:48
   	Description:   Baseline DAILY_V5999_20091224_1310.AAAA
   
   50:
   	Baseline:      "EBX:0.0.9.170"
   	Creation Date: 24-DEC-2009 13:01:54
   	Description:   Baseline 0.0.9.170.AAAA
   
   51:
   	Baseline:      "EBX:DAILY_V4999_20091224_1240"
   	Creation Date: 24-DEC-2009 12:47:42
   	Description:   Baseline DAILY_V4999_20091224_1240.AAAA
   
   52:
   	Baseline:      "EBX:DAILY_V5999_20091224_0500"
   	Creation Date: 24-DEC-2009 05:07:47
   	Description:   Baseline DAILY_V5999_20091224_0500.AAAA
   
   53:
   	Baseline:      "EBX:DAILY_V4999_20091224_0400"
   	Creation Date: 24-DEC-2009 04:07:36
   	Description:   Baseline DAILY_V4999_20091224_0400.AAAA
   
   54:
   	Baseline:      "EBX:DAILY_V5999_20091223_1400"
   	Creation Date: 23-DEC-2009 14:07:40
   	Description:   Baseline DAILY_V5999_20091223_1400.AAAA
   
   55:
   	Baseline:      "EBX:DAILY_V4999_20091223_1300"
   	Creation Date: 23-DEC-2009 13:07:26
   	Description:   Baseline DAILY_V4999_20091223_1300.AAAA
   
   56:
   	Baseline:      "EBX:0.0.9.169"
   	Creation Date: 23-DEC-2009 13:02:05
   	Description:   Baseline 0.0.9.169.AAAA
   
   57:
   	Baseline:      "EBX:DAILY_V5999_20091223_0500"
   	Creation Date: 23-DEC-2009 05:07:32
   	Description:   Baseline DAILY_V5999_20091223_0500.AAAA
   
   58:
   	Baseline:      "EBX:DAILY_V4999_20091223_0400"
   	Creation Date: 23-DEC-2009 04:08:07
   	Description:   Baseline DAILY_V4999_20091223_0400.AAAA
   
   59:
   	Baseline:      "EBX:DAILY_V5999_20091222_1400"
   	Creation Date: 22-DEC-2009 14:07:34
   	Description:   Baseline DAILY_V5999_20091222_1400.AAAA
   
   60:
   	Baseline:      "EBX:DAILY_V4999_20091222_1300"
   	Creation Date: 22-DEC-2009 13:07:29
   	Description:   Baseline DAILY_V4999_20091222_1300.AAAA
   
   61:
   	Baseline:      "EBX:0.0.9.168"
   	Creation Date: 22-DEC-2009 13:02:11
   	Description:   Baseline 0.0.9.168.AAAA
   
   62:
   	Baseline:      "EBX:DAILY_V5999_20091222_0900"
   	Creation Date: 22-DEC-2009 09:06:58
   	Description:   Baseline DAILY_V5999_20091222_0900.AAAA
   
   63:
   	Baseline:      "EBX:DAILY_V4999_20091222_0400"
   	Creation Date: 22-DEC-2009 04:07:53
   	Description:   Baseline DAILY_V4999_20091222_0400.AAAA
   
   64:
   	Baseline:      "EBX:DAILY_V5999_20091221_1400"
   	Creation Date: 21-DEC-2009 14:07:11
   	Description:   Baseline DAILY_V5999_20091221_1400.AAAA
   
   65:
   	Baseline:      "EBX:DAILY_V4999_20091221_1300"
   	Creation Date: 21-DEC-2009 13:07:08
   	Description:   Baseline DAILY_V4999_20091221_1300.AAAA
   
   66:
   	Baseline:      "EBX:DAILY_V5999_20091221_0500"
   	Creation Date: 21-DEC-2009 05:07:08
   	Description:   Baseline DAILY_V5999_20091221_0500.AAAA
   
   67:
   	Baseline:      "EBX:DAILY_V4999_20091221_0400"
   	Creation Date: 21-DEC-2009 04:07:17
   	Description:   Baseline DAILY_V4999_20091221_0400.AAAA
   
   68:
   	Baseline:      "EBX:0.0.9.167"
   	Creation Date: 20-DEC-2009 13:01:22
   	Description:   Baseline 0.0.9.167.AAAA
   
   69:
   	Baseline:      "EBX:0.0.9.166"
   	Creation Date: 19-DEC-2009 13:02:00
   	Description:   Baseline 0.0.9.166.AAAA
   
   70:
   	Baseline:      "EBX:TEST"
   	Creation Date: 19-DEC-2009 10:16:22
   	Description:   Baseline TEST.AAAA
   
   71:
   	Baseline:      "EBX:DAILY_V5999_20091219_0500"
   	Creation Date: 19-DEC-2009 05:06:58
   	Description:   Baseline DAILY_V5999_20091219_0500.AAAA
   
   72:
   	Baseline:      "EBX:DAILY_V4999_20091219_0400"
   	Creation Date: 19-DEC-2009 04:07:10
   	Description:   Baseline DAILY_V4999_20091219_0400.AAAA
   
   73:
   	Baseline:      "EBX:DAILY_V5999_20091218_1400"
   	Creation Date: 18-DEC-2009 14:07:02
   	Description:   Baseline DAILY_V5999_20091218_1400.AAAA
   
   74:
   	Baseline:      "EBX:DAILY_V4999_20091218_1300"
   	Creation Date: 18-DEC-2009 13:06:51
   	Description:   Baseline DAILY_V4999_20091218_1300.AAAA
   
   75:
   	Baseline:      "EBX:0.0.9.165"
   	Creation Date: 18-DEC-2009 13:02:27
   	Description:   Baseline 0.0.9.165.AAAA
   
   76:
   	Baseline:      "EBX:DAILY_V5999_20091218_0500"
   	Creation Date: 18-DEC-2009 05:06:53
   	Description:   Baseline DAILY_V5999_20091218_0500.AAAA
   
   77:
   	Baseline:      "EBX:DAILY_V4999_20091218_0400"
   	Creation Date: 18-DEC-2009 04:07:05
   	Description:   Baseline DAILY_V4999_20091218_0400.AAAA
   
   78:
   	Baseline:      "EBX:DAILY_V5999_20091217_1700"
   	Creation Date: 17-DEC-2009 17:06:46
   	Description:   Baseline DAILY_V5999_20091217_1700.AAAA
   
   79:
   	Baseline:      "EBX:DAILY_V4999_20091217_1630"
   	Creation Date: 17-DEC-2009 16:36:36
   	Description:   Baseline DAILY_V4999_20091217_1630.AAAA
   
------------------------------------------------------------------------------
 History:
   Revision com#2.0.1.1 (APPROVED)
     Updated:  17-DEC-2009 10:06:15      Z13848EC
       Updated attribute(s)
     Created:  17-DEC-2009 10:06:01      Z13848EC
       * Updated code to support PollingBoxes in GetMailBox()
       * Incorporated namespace changes
     Updated:  17-DEC-2009 10:04:50      Z13848EC
       Updated attribute(s)
   
   Revision com#2.0.1 (APPROVED)
     Updated:  30-NOV-2009 18:13:44      Z13152EC
       Updated attribute(s)
     Created:  30-NOV-2009 18:12:45      Z13152EC
       for new compiler
     Updated:  30-NOV-2009 18:08:37      Z13152EC
       Updated attribute(s)
   
   Revision com#2.0 (APPROVED)
     Updated:  28-SEP-2009 21:32:38      Z13152EC
       Updated attribute(s)
     Updated:  27-MAY-2009 13:23:18      Z07475EC
       Migration Initial Revision
     Created:  27-MAY-2009 13:23:18      Z07475EC
       Migration Initial Revision
========================== End of Source Header =============================*/

#ifndef __CI_ARCHIVE_H__
#define __CI_ARCHIVE_H__

#include <list>
#include <status.h>
#include <types.h>
#include <CI/OperatingEnvironment/ref.h>
#include <CI/OperatingEnvironment/cstring.h>

using ci::operatingenvironment::CString;
namespace ci {
namespace boxdocument {


/**
 * Archiver class provides facilities to create archive.
 */
class Archiver
{
public:
typedef enum eArchiveStatus {
	    READY = 0,
	    ARCHIVING,
	    CREATED,
	    CANCELED,
	    DELETED,
	    ERROR,
	    DISK_FULL,
	    ARCHIVE_SIZE_ERROR,
	    CANCEL_INITIATED
}ArchiveStatus;

/**
 * ArchiveStatus shows archiving status
 */
 
    /** Virtual destructor */
    virtual ~Archiver() {};
    
    /**
     * get archiving status
     * @param[out] status - archiving status
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     *         STATUS_ARCHIVE_SIZE_ERROR if the size of file goes beyond 2GB.	
     */
    virtual Status GetStatus(ArchiveStatus &status) = 0;
    
    /**
     * get archiving progress
     * @param[out] progress - archiving progress [0-100] %
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetProgress(int &progress) = 0;
    
    /**
     * get a path of created archive
     * @param[out] path - archive path
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetPath(CString &path) = 0;
    
    /**
     * cancel to archive
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status Cancel() = 0;
}; // class Archiver

/**
 * Extractor class provides facilities to extract archive.
 */
class Extractor
{
public:
typedef enum eExtractStatus {
    READY = 0,
    EXTRACTING,
    FINISHED,
    CANCELED,
    ERROR,
    DISK_FULL,
    UNIDENTIFIED_FILE_FORMAT, //If inner zip file invalid
    INVALID_ARCHIVE_FILE, //If outer zip file invalid
    MAX_ALLOWED_RESOURCES_REACHED,
    STATUS_INVALID_PRODUCTTYPE, //if the product type mismatches
    CANCEL_INITIATED
}ExtractStatus;

/**
 * ExtractStatus shows extracting status
 */

    /** Virtual destructor */
    virtual ~Extractor() {};
    
    /**
     * get extracting status
     * @param[out] status - extracting status
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     *         STATUS_UNIDENTIFIED_FILE_FORMAT if it could not identify the file format.     
     */
    virtual Status GetStatus(ExtractStatus &status) = 0;
    
    /**
     * get extracting progress
     * @param[out] progress - extracting progress [0-100] %
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetProgress(int &progress) = 0;
    
    /**
     * cancel to extract
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status Cancel() = 0;

}; // class Extractor

DECL_OBJ_REF(Archiver);
DECL_OBJ_REF(Extractor);
}; // end of namespace boxdocument
}; // end of namespace ci

#endif // #ifndef __CI_ARCHIVE_H__
