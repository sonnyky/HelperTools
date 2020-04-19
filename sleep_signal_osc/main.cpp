#include "flags.hpp"


#include "common.hpp"

#define PORT 7777

using namespace std;

int INTERRUPT = 0;

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
{
	ofstream myfile;
	auto end = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	switch (fdwCtrlType)
	{
		// Handle the CTRL-C signal. 
	case CTRL_C_EVENT:
		printf("Ctrl-C event\n\n");
		myfile.open("CTRL_C_EVENT.txt");
		myfile << "Writing this to a file.\n";
		myfile.close();
		return TRUE;

		// CTRL-CLOSE: confirm that the user wants to exit. 
	case CTRL_CLOSE_EVENT:
		printf("Ctrl-Close event\n\n");
		return TRUE;

		// Pass other signals to the next handler. 
	case CTRL_BREAK_EVENT:
		myfile.open("CTRL_BREAK_EVENT.txt");
		myfile << "Time interrupt received : \n";
		myfile << std::ctime(&end_time);
		myfile.close();

		INTERRUPT = 1;

		printf("Ctrl-Break event\n\n");
		Sleep(10000);
		return FALSE;

	case CTRL_LOGOFF_EVENT:
		printf("Ctrl-Logoff event\n\n");
		return FALSE;

	case CTRL_SHUTDOWN_EVENT:
		printf("Ctrl-Shutdown event\n\n");
		return FALSE;

	default:
		return FALSE;
	}
}

bool ParseAndCheckCommandLine(int argc, char* argv[]) {
	// ---------------------------Parsing and validation of input args--------------------------------------

	gflags::ParseCommandLineNonHelpFlags(&argc, &argv, true);
	if (FLAGS_h) {
		showUsage();
		return false;
	}

	std::cout << "Parsing input parameters" << std::endl;

	if (FLAGS_port.empty()) {
		std::cout << "Default port 7777 set" << std::endl;
	}
	else {

	}

	return true;
}

int main(int argc, char* argv[])
{

	if (!ParseAndCheckCommandLine(argc, argv)) {
		return EXIT_SUCCESS;
	}
	Server server;
	cout << "port : " << FLAGS_port << endl;
	server.setup_osc_out_port(FLAGS_port.c_str());

	const char * message = "finish";

	int counter = 0;
	if (SetConsoleCtrlHandler(CtrlHandler, TRUE))
	{
		
		while(1){

			if (INTERRUPT == 1) {
				if (counter < 10) {
					server.osc_send(message);
					counter++;
				}
				
			}
		}
		
	}

	
	return 0;
}