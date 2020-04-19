# cmake needs this line
cmake_minimum_required(VERSION 2.8)

# Define project name
project(sleep_signal_osc)

# Set installation folder
set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "default install path" FORCE )

# Set additional include folders
set (ADDITIONAL_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# OSCPACK
set(OSCPACK_INCLUDE_DIR      "D:/Libraries/oscpack_1_1_0")


# GFLAGS
set(gflags_DIR "D:/Libraries/gflags/install/lib/cmake/gflags")
find_package(gflags REQUIRED)
set(GFLAGS_INCLUDE "D:/Libraries/gflags/install/include")
set(GFLAGS_LIB "D:/Libraries/gflags/install/lib/gflags_nothreads_static.lib")

include_directories(${ADDITIONAL_INCLUDE} ${OSCPACK_INCLUDE_DIR} ${GFLAGS_INCLUDE})

# Declare the executable target built from your sources
set(SOURCES 
	main.cpp 
	messager.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/include/common.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/flags.hpp 
	${OSCPACK_INCLUDE_DIR}/osc/OscTypes.cpp 
	${OSCPACK_INCLUDE_DIR}/osc/OscReceivedElements.cpp 
	${OSCPACK_INCLUDE_DIR}/osc/OscPrintReceivedElements.cpp 
	${OSCPACK_INCLUDE_DIR}/osc/OscOutboundPacketStream.cpp 
	${OSCPACK_INCLUDE_DIR}/ip/IpEndpointName.cpp 
	${OSCPACK_INCLUDE_DIR}/ip/win32/NetworkingUtils.cpp 
	${OSCPACK_INCLUDE_DIR}/ip/win32/UdpSocket.cpp)
add_executable(sleep_signal_osc ${SOURCES} )

# Link your application with OpenCV libraries
target_link_libraries(sleep_signal_osc ws2_32 winmm ${GFLAGS_LIB} shlwapi.lib)