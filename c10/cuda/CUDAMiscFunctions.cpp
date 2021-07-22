#include <c10/cuda/CUDAMiscFunctions.h>
#include <stdlib.h>

namespace c10 {
namespace cuda {

const char* get_cuda_check_suffix() noexcept {
  static char* device_blocking_flag = getenv("CUDA_LAUNCH_BLOCKING");
  static bool blocking_enabled =
      (device_blocking_flag && atoi(device_blocking_flag));
  if (blocking_enabled) {
    return "";
  } else {
    return "\nCUDA kernel errors might be asynchronously reported at some"
           " other API call,so the stacktrace below might be incorrect."
           "\nFor debugging consider passing CUDA_LAUNCH_BLOCKING=1.";
  }
}
} // namespace cuda
} // namespace c10