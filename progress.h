/*****************************************************************************/
/*  (C) Copyright  TOSHIBA TEC CORPORATION 2008   All Rights Reserved        */
/*****************************************************************************
============================== Source Header =================================
 Filename: %PM%
 Revision: %PR%
 File Spec: %PID%
 Originator: %PO%
 Last Changed: %PRT%

  Outline : definition of box operation

*/
/*----------------------------------------------------------------------------
 Related Change Documents:
   %PIRC%
------------------------------------------------------------------------------
 Related Baselines:
   %PIRB%
------------------------------------------------------------------------------
 History:
   %PL%
========================== End of Source Header =============================*/

#ifndef __CI_PROGRESS_H__
#define __CI_PROGRESS_H__

#include <CI/OperatingEnvironment/ref.h>

namespace ci {
namespace boxdocument {

DECL_OBJ_REF(Progress);

/**
 * Progress class provides facilities to get progress.
 */
class Progress
{
public:
    /** Virtual destructor */
    virtual ~Progress() {};
    
    /**
     * get progress
     * when error happen, progress is always 100. And return value is NOT 
     * STATUS_OK. It depends on each operation.
     * @param[out] progress - progress [0-100] %
     * @return STATUS_OK on success,
     *         STATUS_FAILED on failure.
     */
    virtual Status GetProgress(int &progress) = 0;
};

}; // end of namespace boxdocument
}; // end of namespace ci

#endif // #ifndef __CI_PROGRESS_H__
