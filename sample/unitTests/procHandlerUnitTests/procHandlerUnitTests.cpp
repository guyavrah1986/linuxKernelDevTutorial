#include <glog/logging.h>

#include "procHandler.h"
#include "procDetailes.h"
#include "procHandlerUnitTests.h"
#include "utils.h"

using namespace std;

ProcHandlerUnitTests::ProcHandlerUnitTests()
{
	cout << "ProcHandlerUnitTests::ProcHandlerUnitTests" << endl;
	const string logFileNameFullPath = LOGS_PATH_PREFIX + string(typeid(ProcHandlerUnitTests).name());
	if (setGlog(typeid(ProcHandlerUnitTests).name(), google::GLOG_INFO, logFileNameFullPath.c_str()).IsSuccess() == false)
	{
		cerr << "ProcHandlerUnitTests::ProcHandlerUnitTests - unable to initialize log" << endl;
	}
	else
	{
		LOG(INFO) << "ProcHandlerUnitTests::ProcHandlerUnitTests - glog was initialized successfully";
	}
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

TEST_F(ProcHandlerUnitTests, addNonExistingProcDetailesToMap)
{
	LOG(INFO) << "ProcHandlerUnitTests::addNonExistingProcDetailesToMap";
	ProcHandler procHandler;
	Result res = procHandler.addProcessDetaliesToMap("jk",move(ProcessDetailes()));
	EXPECT_EQ(res.IsSuccess(), true);
}

