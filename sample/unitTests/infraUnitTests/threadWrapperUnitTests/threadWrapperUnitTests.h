#pragma once

#include "gtest/gtest.h"

class ThreadWrapperUnitTests : public ::testing::Test
{
protected:

	ThreadWrapperUnitTests();
	virtual ~ThreadWrapperUnitTests();
	virtual void SetUp();
	virtual void TearDown();
};

