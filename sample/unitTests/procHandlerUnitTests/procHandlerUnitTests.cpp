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

TEST_F(ProcHandlerUnitTests, addProcDetailesToMap)
{
	LOG(INFO) << "ProcHandlerUnitTests::addProcDetailesToMap";
	ProcHandler procHandler;

	// first, add a new ProcessDetailes to an empty map
	const string exe1Name = "ExeName1";
	Result res = procHandler.addProcessDetaliesToMap(exe1Name, move(ProcessDetailes()));
	EXPECT_EQ(res.IsSuccess(), true);
	EXPECT_EQ(procHandler.GetProcessExeNameToProcessDetailesMap().count(exe1Name), 1);

	// now insert second ProcessDetailes
	const string exe2Name = "ExeName2";
	res = procHandler.addProcessDetaliesToMap(exe2Name, move(ProcessDetailes()));
	EXPECT_EQ(res.IsSuccess(), true);
	EXPECT_EQ(procHandler.GetProcessExeNameToProcessDetailesMap().count(exe2Name), 1);
	EXPECT_EQ(procHandler.GetProcessExeNameToProcessDetailesMap().size(), 2);

	// now overwrite the previous exe1Name ProcessDetailes with new detailes
	const long int newExe1Pid = 12;
	const long int newExe1ParentPid = 15;

	res = procHandler.addProcessDetaliesToMap(exe1Name, move(ProcessDetailes(newExe1Pid, newExe1ParentPid)));
	EXPECT_EQ(res.IsSuccess(), true);
	EXPECT_EQ(procHandler.GetProcessExeNameToProcessDetailesMap().size(), 2);
	auto it = procHandler.GetProcessExeNameToProcessDetailesMap().find(exe1Name);
	EXPECT_EQ((it->first) == exe1Name, true);
	EXPECT_EQ(it->second.GetPid(), newExe1Pid);
	EXPECT_EQ(it->second.GetParentPid(), newExe1ParentPid);
}

