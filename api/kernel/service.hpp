// This file is a part of the IncludeOS unikernel - www.includeos.org
//
// Copyright 2015 Oslo and Akershus University College of Applied Sciences
// and Alfred Bratterud
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SERVICE_H
#define SERVICE_H

extern "C" const char* service_name__;

#include <string>
/** This is where you take over

    The service gets started whenever the OS is done initializing
*/
class Service{

 public:
  
  static const std::string name() {
    return service_name__;
  }
  
  /** The service entry point
      
      This is like 'main' - which we don't have, since the signature wouldn't 
      make sense (no command line, no args, no where to return to)
      
      @note Whenever this function returns, the OS will call `hlt`, sleeping
      until an external interrupt fires (there are no regular timer interrupts
      unless you've enabled them). Your service should hook up event handlers
      to some of the events (like `Nic::on(HttpConnection, your_callback`))
   */
  static void start();

  
  /** Graceful shutdown
      
      If the virtual machine running your service gets a poweroff signal
      (i.e. from the hypervisor, like Qemu or VirtualBox) this function should
      ensure a safe shutdown.
      
      @todo This is not implemented
   */
  static void stop();
  
};

#endif
