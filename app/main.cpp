#include <iostream>
#include <memory>
#include <glog/logging.h>
#include <unistd.h>

#include "utils.h"
#include "procHandler.h"
#include "handlersDispatcher.h"
#include "stdThreadRaiiWrapper.h"
#include "secureConnectionHandler.h"

using namespace std;

// TODO: remove after testing is done
void testSslConnection()
{
	cout << "testSslConnection - start" << endl;
	SecureConnectionsHandler secureConnectionHandler;
	const string serverIp = "127.0.0.1";
	const unsigned short serverPort = 8080;
	const string certPemFile = "/home/guya/guya/dev/linuxKernelDevTutorial/localhost.pem";
	if (false == secureConnectionHandler.CreateConnection(serverIp, serverPort, certPemFile))
	{
		cout << "testSslConnection - did NOT create a SecureConnectionsHandler object on the stack, aborting" << endl;
		return;
	}

	cout << "testSslConnection - SUCCESSFULLY created a SecureConnectionsHandler object on the stack" << endl;

	const string getRequest = "GET / HTTP/1.1";
	cout << "testSslConnection - about to send:" << getRequest << " to the server" << endl;
	int res = secureConnectionHandler.SendData(getRequest);
	cout << "testSslConnection - sent:" << res << " bytes to the server" << endl;
    sleep(1);

	vector<unsigned char> buffToReadInto;
	buffToReadInto.reserve(1500);
	res = secureConnectionHandler.ReceiveData(buffToReadInto);
	string retStr(buffToReadInto.begin(), buffToReadInto.end());
	cout << "testSslConnection - received:" << retStr << " from the server" << endl;


}
// TODO: remove after testing is done

int main(int argc, char** argv)
{
	cout << "main - start" << endl;
	testSslConnection();
	cout << "main - end" << endl;
}


/* ORIGINAL MAIN
int main(int argc, char** argv)
{
	cout << "main - start" << endl;
	if (handleCommandLineArgs(argc, argv).IsSuccess() == false)
	{
		cerr << "main - not enough arguments provided, excpecting:" << NumOfCommandLineArgs << endl;
		return 1;
	}

	const char* GLOG_INFO_LEVEL_LOG_PATH = "/tmp/guyProj/exe_INFO_log";
	if (setGlog(argv[0], google::GLOG_INFO, GLOG_INFO_LEVEL_LOG_PATH).IsSuccess() == false)
	{
		cerr << "main - invalid arguments provided" << endl;
		return 1;
	}

	cout << "main - end" << endl;
	return 0;
}
*/
