/* Include files */

#include "EmbeddedOpenLoop_cgxe.h"
#include "m_PTdG8gdw0OKztclHHj347C.h"

unsigned int cgxe_EmbeddedOpenLoop_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 1444085135 &&
      ssGetChecksum1(S) == 3420787981 &&
      ssGetChecksum2(S) == 1909080517 &&
      ssGetChecksum3(S) == 1621527115) {
    method_dispatcher_PTdG8gdw0OKztclHHj347C(S, method, data);
    return 1;
  }

  return 0;
}
