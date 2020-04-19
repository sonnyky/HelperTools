// Copyright (C) 2018-2019 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <gflags/gflags.h>
#include <iostream>


/// @brief Message for raw output
static const char port_output_message[] = "Optional. Port is 7777 by default.";

/// @brief Message for help argument
static const char help_message[] = "Print a usage message.";

/// @brief Defines parameter for target port to send OSC messages <br>
/// It is an optional parameter
DEFINE_string(port, "7777", port_output_message);

/// @brief Defines flag for showing help message <br>
DEFINE_bool(h, false, help_message);


/**
* @brief This function shows a help message
*/
static void showUsage() {
	std::cout << std::endl;
	std::cout << "OSC signal messager [OPTION]" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << std::endl;
	std::cout << "    -ip                         " << port_output_message << std::endl;
	
}
