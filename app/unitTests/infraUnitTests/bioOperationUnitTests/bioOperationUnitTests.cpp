#include <glog/logging.h>

#include "../mallocAndFreeWrappersForUnitTests/mallocAndFreeWrappers.c"
#include "bioOperationUnitTests.h"
#include "utils.h"

using namespace std;

size_t numOfInitForGlog = 0;

BioOperationUnitTests::BioOperationUnitTests()
{
	cout << "BioOperationUnitTests::BioOperationUnitTests" << endl;
	if (0 == numOfInitForGlog)
	{
		my_init_hook();
		const string logFileNameFullPath = LOGS_PATH_PREFIX + string(typeid(BioOperationUnitTests).name());
		if (setGlog(typeid(BioOperationUnitTests).name(), google::GLOG_INFO, logFileNameFullPath.c_str()).IsSuccess() == false)
		{
			cerr << "BioOperationUnitTests::BioOperationUnitTests - unable to initialize log" << endl;
		}
		else
		{
			LOG(INFO) << "BioOperationUnitTests::BioOperationUnitTests - glog was initialized successfully";
			++numOfInitForGlog;
		}
	}
	else
	{
		LOG(INFO) << "BioOperationUnitTests::BioOperationUnitTests - glog is already initialized successfully";
	}
}

BioOperationUnitTests::~BioOperationUnitTests()
{
	cout << "BioOperationUnitTests::~BioOperationUnitTests" << endl;
}

void BioOperationUnitTests::SetUp()
{
	cout << "BioOperationUnitTests::SetUp" << endl;
}

void BioOperationUnitTests::TearDown()
{
	cout << "BioOperationUnitTests::TearDown" << endl;
}


// =====================================================================================================================
// GTests for this class
// =====================================================================================================================

TEST_F(BioOperationUnitTests, test1)
{
	MEM_CHECK_BEFORE_TEST(g_numBytesAllocated);

	MEM_CHECK_AFTER_TEST(g_numBytesAllocated);
}


