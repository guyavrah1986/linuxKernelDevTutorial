#include "procDetailes.h"
#include "procDetailesUnitTests.h"
#include "utils.h"

using namespace std;

procDetailesUnitTests::procDetailesUnitTests()
{
	cout << "procDetailesUnitTests::procDetailesUnitTests" << endl;
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
	//ProcessDetailes procDestailes;
	//LOG(INFO) << "ProcHandlerUnitTests::addNonExistingProcDetailesToMap";
	//Result res = procHandler.addProcessDetaliesToMap("jk",move(procDetailes));
}

