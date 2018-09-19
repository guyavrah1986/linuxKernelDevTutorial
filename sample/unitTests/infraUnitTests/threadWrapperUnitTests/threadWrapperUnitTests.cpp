#include <glog/logging.h>
#include <chrono>
#include <exception>

#include "stdThreadRaiiWrapper.h"
#include "threadWrapperUnitTests.h"
#include "utils.h"

using namespace std;

bool isCalled = false;
bool isThrown = false;

size_t numOfInitForGlog = 0;

ThreadWrapperUnitTests::ThreadWrapperUnitTests()
{
	cout << "ThreadWrapperUnitTests::ThreadWrapperUnitTests" << endl;
	if (0 == numOfInitForGlog)
	{
		const string logFileNameFullPath = LOGS_PATH_PREFIX + string(typeid(ThreadWrapperUnitTests).name());
		if (setGlog(typeid(ThreadWrapperUnitTests).name(), google::GLOG_INFO, logFileNameFullPath.c_str()).IsSuccess() == false)
		{
			cerr << "ThreadWrapperUnitTests::ThreadWrapperUnitTests - unable to initialize log" << endl;
		}
		else
		{
			LOG(INFO) << "ThreadWrapperUnitTests::ThreadWrapperUnitTests - glog was initialized successfully";
			++numOfInitForGlog;
		}
	}
	else
	{
		LOG(INFO) << "ThreadWrapperUnitTests::ThreadWrapperUnitTests - glog is already initialized successfully";
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
	LOG(INFO) << "ThreadWrapperUnitTests::func1 - thread ID is:" << this_thread::get_id();
	isCalled = true;
}

TEST_F(ThreadWrapperUnitTests, verifyJoin)
{
	isCalled = false;
	LOG(INFO) << "ThreadWrapperUnitTests::verifyJoin - start";

	{
		LOG(INFO) << "ThreadWrapperUnitTests::verifyJoin - entering dummy scope, creating StdThreadRaiiWrapper";
		StdThreadRaiiWrapper joinedThread(thread(func1), &thread::join);
	}

	EXPECT_EQ(isCalled, true);
	LOG(INFO) << "ThreadWrapperUnitTests::verifyJoin - end";
}

TEST_F(ThreadWrapperUnitTests, verifyDetach)
{
	isCalled = false;
	LOG(INFO) << "ThreadWrapperUnitTests::verifyDetach - start";

	{
		LOG(INFO) << "ThreadWrapperUnitTests::verifyDetach - entering dummy scope, creating StdThreadRaiiWrapper";
		StdThreadRaiiWrapper detachedThread(thread(func1), &thread::detach);
		this_thread::sleep_for((chrono::seconds(1)));
	}

	EXPECT_EQ(isCalled, true);
	LOG(INFO) << "ThreadWrapperUnitTests::verifyDetach - end";
}

void workerThread()
{
	LOG(INFO) << "ThreadWrapperUnitTests::workerThread";
	size_t numOfSecToWorkUntillExceptionIsThrown = 3;
	size_t numSecPassed = 0;
	isCalled = true;

	while (true)
	{
		LOG(INFO) << "ThreadWrapperUnitTests::workerThread - in iteration number:" << ++numSecPassed;
		this_thread::sleep_for((chrono::seconds(1)));
		if (numSecPassed == numOfSecToWorkUntillExceptionIsThrown)
		{
			return;
		}
	}

	// should never reach here
	LOG(INFO) << "ThreadWrapperUnitTests::workerThread - end";
}

TEST_F(ThreadWrapperUnitTests, verifyThatJoindThreadThatThrowsExcpetionTerminateGracefully)
{
	LOG(INFO) << "ThreadWrapperUnitTests::verifyThatJoindThreadThatThrowsExcpetionTerminateGracefully - start";
	isCalled = false;
	isThrown = false;

	try
	{
		LOG(INFO) << "ThreadWrapperUnitTests::verifyThatJoindThreadThatThrowsExcpetionTerminateGracefully - entering dummy scope, creating StdThreadRaiiWrapper";
		StdThreadRaiiWrapper joinedThread(thread(workerThread), &thread::join);
		throw runtime_error("main thread threw exception");
		LOG(INFO) << "ThreadWrapperUnitTests::verifyThatJoindThreadThatThrowsExcpetionTerminateGracefully - this line should not be reached";
	}
	catch (const exception& e)
	{
		LOG(INFO) << "ThreadWrapperUnitTests::verifyThatJoindThreadThatThrowsExcpetionTerminateGracefully - caught std::exception, e.what:" << e.what();
	}

	EXPECT_EQ(isCalled, true);
	LOG(INFO) << "verifyThatJoindThreadThatThrowsExcpetionTerminateGracefully::verifyThatJoindThreadThatThrowsExcpetionTerminateGracefully - end";
}

