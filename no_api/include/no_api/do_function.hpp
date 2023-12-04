
#ifndef NO_API_DO_FUNCTION_HPP
#define NO_API_DO_FUNCTION_HPP

#include <memory>
#include "std_srvs/srv/set_bool.hpp"
#include "no_api/input_state.hpp"

void do_function(
  const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
  std::shared_ptr<std_srvs::srv::SetBool::Response> response,
  const InputState & st);

#endif  // NO_API_DO_FUNCTION_HPP