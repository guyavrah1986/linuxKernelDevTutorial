#include <glog/logging.h>
#include <fstream>

#include "mallocAndFreeWrappers.c"
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
		my_init_hook();
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

void actualFunc1()
{
	SecureConnectionsHandler secHandler;
}

TEST_F(SecureConnectionHandlerUnitTests, verifyAddConnectionFailsUponInvalidArguments)
{
	MEM_CHECK_BEFORE_TEST(g_numBytesAllocated);
	actualFunc1();
	/*
	{


		const string emptyStringArg = "";
		const string pemFileName = "fakePEMFile.pem";
		const string nonExistingPemFileName = "notExists.pem";
		const string ip = "127.0.0.1";
		const unsigned short port = 8080;

		/*
		// create a "fake" PEM file
		ofstream pemFile(pemFileName);
		pemFile << "ASEDCXSWEF" << endl;
		pemFile.close();


		// empty IP address string
		bool res = secHandler.AddConnection(emptyStringArg, port, pemFileName);
		EXPECT_EQ(res, false);

		// empty PEM file name
		res = secHandler.AddConnection(ip, port, emptyStringArg);
		EXPECT_EQ(res, false);

		// non-existing PEM file name
		res = secHandler.AddConnection(ip, port, nonExistingPemFileName);
		EXPECT_EQ(res, false);


		// finally delete the file
		int removeRes = remove(pemFileName.c_str());
		EXPECT_EQ(removeRes, 0);

	}
	*/

	MEM_CHECK_AFTER_TEST(g_numBytesAllocated);
}


