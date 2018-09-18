#include <glog/logging.h>

#include "stdThreadRaiiWrapper.h"
#include "threadWrapperUnitTests.h"
#include "utils.h"

using namespace std;

bool isCalled = false;

ThreadWrapperUnitTests::ThreadWrapperUnitTests()
{
	cout << "ThreadWrapperUnitTests::ThreadWrapperUnitTests" << endl;
	const string logFileNameFullPath = LOGS_PATH_PREFIX + string(typeid(ThreadWrapperUnitTests).name());
	if (setGlog(typeid(ThreadWrapperUnitTests).name(), google::GLOG_INFO, logFileNameFullPath.c_str()).IsSuccess() == false)
	{
		cerr << "ThreadWrapperUnitTests::ThreadWrapperUnitTests - unable to initialize log" << endl;
	}
	else
	{
		LOG(INFO) << "ThreadWrapperUnitTests::ThreadWrapperUnitTests - glog was initialized successfully";
	}
}

ThreadWrapperUnitTests::~ThreadWrapperUnitTests()
{
	cout << "ThreadWrapperUnitTests::~ThreadWrapperUnitTests" << endl;
}

void ThreadWrapperUnitTests::SetUp()
{
	cout << "ThreadWrapperUnitTests::SetUp" << endl;
}

void ThreadWrapperUnitTests::TearDown()
{
	cout << "ThreadWrapperUnitTests::TearDown" << endl;
}


// =====================================================================================================================
// GTests for this class
// =====================================================================================================================

void func1()
{
	isCalled = true;
}

TEST_F(ThreadWrapperUnitTests, verifyJoin)
{
	isCalled = false;
	LOG(INFO) << "ThreadWrapperUnitTests::verifyJoin";

	{
		LOG(INFO) << "ThreadWrapperUnitTests::verifyJoin - entering dummy scope, creating StdThreadRaiiWrapper";
		StdThreadRaiiWrapper joinedThread(thread(func1), &thread::join);
	}

	EXPECT_EQ(isCalled, true);
}

