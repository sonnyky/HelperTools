#ifndef __APP__
#define __APP__

#undef UNICODE

#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <string>
#include <cstring>
#include <signal.h>
#include <cstdio>
#include <chrono>
#include <ctime>

#include <ip/UdpSocket.h>
#include <osc/OscOutboundPacketStream.h>

using namespace std;

#define OUTPUT_BUFFER_SIZE 1024

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")

class Server {
private :
	int mode_; // mode = 0 is send data to remote client. mode = 1 is calibration mode

	// Network comms
	const char* osc_out_ip_ = "127.0.0.1";
	PCSTR incoming_port_ = "1101";
	int outgoing_port_ = 7777;
	int iResult_, iDataResult_;
	int messagelength_, chunk_;
	string data_;
	SOCKET ListenSocket_ = INVALID_SOCKET;
	SOCKET ClientSocket_ = INVALID_SOCKET;


public:
	// Constructor
	Server();

	// Destructor
	~Server();

	// Networking functions
	void osc_send(const char * str);
	void setup_osc_out_ip(const char* ip);
	void setup_osc_out_port(const char* port);

private :
	void initialize();
	void finalize();
};

#endif // __APP__