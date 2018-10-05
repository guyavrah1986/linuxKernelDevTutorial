#include <glog/logging.h>

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

TEST_F(SecureConnectionHandlerUnitTests, verifyAddConnectionFailsUponInvalidArguments)
{
	MEM_CHECK_BEFORE_TEST(g_numBytesAllocated);
	SecureConnectionsHandler sec;

	MEM_CHECK_AFTER_TEST(g_numBytesAllocated);
}


