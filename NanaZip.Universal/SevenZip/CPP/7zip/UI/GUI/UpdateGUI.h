// GUI/UpdateGUI.h

#ifndef ZIP7_INC_UPDATE_GUI_H
#define ZIP7_INC_UPDATE_GUI_H

#include "../Common/Update.h"

#include "UpdateCallbackGUI.h"

/*
  callback->FailedFiles contains names of files for that there were problems.
  RESULT can be S_OK, even if there are such warnings!!!
  
  RESULT = E_ABORT - user break.
  RESULT != E_ABORT:
  {
   messageWasDisplayed = true  - message was displayed already.
   messageWasDisplayed = false - there was some internal error, so you must show error message.
  }
*/

HRESULT UpdateGUI(
    CCodecs *codecs,
    const CObjectVector<COpenType> &formatIndices,
    const UString &cmdArcPath2,
    NWildcard::CCensor &censor,
    CUpdateOptions &options,
    bool showDialog,
    bool &messageWasDisplayed,
    CUpdateCallbackGUI *callback,
    HWND hwndParent = NULL);

// **************** NanaZip Modification Start ****************
/*
  UpdateGUIBatch() compresses each job to its own archive, and all jobs are
  running sequentially in the same progress window. The spec is the parameter
  of the "-sbc#" switch, in the following form:
  "MappingName:MappingSize:EventName".

  RESULT can be S_OK, E_ABORT (user break) or an error code.
  messageWasDisplayed = true if the error message was displayed already.
*/
HRESULT UpdateGUIBatch(
    CCodecs *codecs,
    const UString &spec,
    bool &messageWasDisplayed,
    HWND hwndParent = NULL);
// **************** NanaZip Modification End ****************

#endif
