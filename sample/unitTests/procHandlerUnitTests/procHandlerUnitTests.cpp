#include "gtest/gtest.h"

#include "procHandlerUnitTests.h"
#include "utils.h"

using namespace std;

ProcHandlerUnitTests::ProcHandlerUnitTests()
{
	cout << "ProcHandlerUnitTests::ProcHandlerUnitTests" << endl;
}

ProcHandlerUnitTests::~ProcHandlerUnitTests()
{
	cout << "ProcHandlerUnitTests::~ProcHandlerUnitTests" << endl;
}

void ProcHandlerUnitTests::SetUp()
{
	cout << "ProcHandlerUnitTests::SetUp" << endl;
}

void ProcHandlerUnitTests::TearDown()
{
	cout << "ProcHandlerUnitTests::TearDown" << endl;
}


// =====================================================================================================================
// GTests for this class
// =====================================================================================================================

TEST_F(ProcHandlerUnitTests, test1)
{
	cout << "ProcHandlerUnitTests::test1" << endl;
}

TEST_F(ProcHandlerUnitTests, test2)
{
	cout << "ProcHandlerUnitTests::test2" << endl;
}

// =====================================================================================================================
// main for this class
// =====================================================================================================================


int main(int argc, char* argv[])
{
	const char* UNIT_TESTS_GLOG_PATH = "/tmp/guyProj/unitTests_log";
	if (setGlog(argv[0], google::GLOG_INFO, UNIT_TESTS_GLOG_PATH).IsSuccess() == false)
	{
		cerr << "main - invalid arguments provided" << endl;
		return 1;
	}

	LOG(INFO) << "This is a message";

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

