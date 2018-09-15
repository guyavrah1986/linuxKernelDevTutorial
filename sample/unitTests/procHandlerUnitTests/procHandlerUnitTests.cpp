#include "gtest/gtest.h"
#include "procHandlerUnitTests.h"

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
