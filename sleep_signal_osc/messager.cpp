#include "common.hpp"

const std::string no_camera_message = "No camera connected, please connect 1 or more";
const std::string platform_camera_name = "Platform Camera";

using namespace std;

Server::Server()
{
	initialize();
}
Server::~Server()
{
	// Finalize
	finalize();
}

void Server::initialize() {

}

void Server::finalize() {

}

#pragma region sensor_networking

void Server::setup_osc_out_ip(const char* ip) {
	osc_out_ip_ = ip;
}

void Server::setup_osc_out_port(const char* port) {
	outgoing_port_ = atoi( port);
}

void Server::osc_send(const char * str) {
	// TODO : send to Unity with OSC
	// Transmit data
	UdpTransmitSocket transmitSocket(IpEndpointName(osc_out_ip_, outgoing_port_));
	char buffer[OUTPUT_BUFFER_SIZE];
	osc::OutboundPacketStream ps(buffer, OUTPUT_BUFFER_SIZE);

	ps << osc::BeginBundleImmediate
		<< osc::BeginMessage("/custom_interrupt")
		<< str
		<< osc::EndMessage
		<< osc::EndBundle;

	transmitSocket.Send(ps.Data(), ps.Size());
}

#pragma endregion getting sensor data through tcp socket