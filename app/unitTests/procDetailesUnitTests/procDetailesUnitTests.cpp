#include <glog/logging.h>

#include "procDetailes.h"
#include "procDetailesUnitTests.h"
#include "utils.h"
#include "../mallocAndFreeWrappersForUnitTests/mallocAndFreeWrappers.c"

using namespace std;

size_t numOfInitForGlog = 0;

procDetailesUnitTests::procDetailesUnitTests()
{
	LOG(INFO) << "procDetailesUnitTests::procDetailesUnitTests";
	if (0 == numOfInitForGlog)
	{
		my_init_hook();
		// initialize the malloc and free hooks
		const string logFileNameFullPath = LOGS_PATH_PREFIX + string(typeid(procDetailesUnitTests).name());
		if (setGlog(typeid(procDetailesUnitTests).name(), google::GLOG_INFO, logFileNameFullPath.c_str()).IsSuccess() == false)
		{
			cerr << "procDetailesUnitTests::procDetailesUnitTests - unable to initialize log" << endl;
		}
		else
		{
			LOG(INFO) << "procDetailesUnitTests::procDetailesUnitTests - glog was initialized successfully";
			++numOfInitForGlog;
		}
	}
	else
	{
		LOG(INFO) << "procDetailesUnitTests::procDetailesUnitTests - glog is already initialized successfully";
	}
}

procDetailesUnitTests::~procDetailesUnitTests()
{
	cout << "procDetailesUnitTests::~procDetailesUnitTests" << endl;
}

void procDetailesUnitTests::SetUp()
{
	cout << "procDetailesUnitTests::SetUp" << endl;
}

void procDetailesUnitTests::TearDown()
{
	cout << "procDetailesUnitTests::TearDown" << endl;
}


// =====================================================================================================================
// GTests for this class
// =====================================================================================================================

TEST_F(procDetailesUnitTests, test1)
{
	cout << "procDetailesUnitTests::test1" << endl;
	int* p1 = new int(8);
	delete p1;
}

