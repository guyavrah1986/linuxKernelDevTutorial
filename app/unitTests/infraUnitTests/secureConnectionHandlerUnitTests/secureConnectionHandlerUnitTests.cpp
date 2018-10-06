#include <glog/logging.h>
#include <fstream>

#include "secureConnectionHandlerUnitTests.h"
#include "secureConnectionHandler.h"
#include "utils.h"

using namespace std;

size_t numOfInitForGlog = 0;

SecureConnectionHandlerUnitTests::SecureConnectionHandlerUnitTests()
{
	cout << "SecureConnectionHandlerUnitTests::SecureConnectionHandlerUnitTests" << endl;
	if (0 == numOfInitForGlog)
	{
		const string logFileNameFullPath = LOGS_PATH_PREFIX + string(typeid(SecureConnectionHandlerUnitTests).name());
		if (setGlog(typeid(SecureConnectionHandlerUnitTests).name(), google::GLOG_INFO, logFileNameFullPath.c_str()).IsSuccess() == false)
		{
			cerr << "SecureConnectionHandlerUnitTests::SecureConnectionHandlerUnitTests - unable to initialize log" << endl;
		}
		else
		{
			LOG(INFO) << "SecureConnectionHandlerUnitTests::SecureConnectionHandlerUnitTests - glog was initialized successfully";
			++numOfInitForGlog;
		}
	}
	else
	{
		LOG(INFO) << "SecureConnectionHandlerUnitTests::SecureConnectionHandlerUnitTests - glog is already initialized successfully";
	}
}

SecureConnectionHandlerUnitTests::~SecureConnectionHandlerUnitTests()
{
	cout << "SecureConnectionHandlerUnitTests::~SecureConnectionHandlerUnitTests" << endl;
}

void SecureConnectionHandlerUnitTests::SetUp()
{
	cout << "SecureConnectionHandlerUnitTests::SetUp" << endl;
}

void SecureConnectionHandlerUnitTests::TearDown()
{
	cout << "SecureConnectionHandlerUnitTests::TearDown" << endl;
}


// =====================================================================================================================
// GTests for this class
// =====================================================================================================================

TEST_F(SecureConnectionHandlerUnitTests, verifyAddConnectionFailsUponInvalidArguments)
{
	LOG(INFO) << "SecureConnectionHandlerUnitTests::verifyAddConnectionFailsUponInvalidArguments";
	SecureConnectionsHandler secHandler;

	const string emptyStringArg = "";
	const string pemFileName = "fakePEMFile.pem";
	const string nonExistingPemFileName = "notExists.pem";
	const string validPemFileName = "/home/guya/guya/dev/linuxKernelDevTutorial/httpServerForTesting/localhost.pem";
	const string ip = "127.0.0.1";
	const unsigned short port = 8080;
	bool res = false;

	// create a "fake" PEM file
	ofstream pemFile(pemFileName);
	pemFile << "ASEDCXSWEF" << endl;
	pemFile.close();

	// empty IP address string
	res = secHandler.CreateConnection(emptyStringArg, port, pemFileName);
	EXPECT_EQ(res, false);

	// empty PEM file name
	res = secHandler.CreateConnection(ip, port, emptyStringArg);
	EXPECT_EQ(res, false);

	// non-existing PEM file name
	res = secHandler.CreateConnection(ip, port, nonExistingPemFileName);
	EXPECT_EQ(res, false);

	// TODO: Uncommenct this sub-test in case there is a valid
	// server that this "clinet" can connect to
	// valid PEM file name
	/*
	res = secHandler.CreateConnection(ip, port, validPemFileName);
	EXPECT_EQ(res, true);
	*/

	// finally delete the file
	int removeRes = remove(pemFileName.c_str());
	EXPECT_EQ(removeRes, 0);
}


