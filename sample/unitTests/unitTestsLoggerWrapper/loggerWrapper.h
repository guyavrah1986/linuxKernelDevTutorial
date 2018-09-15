#include <glog/logging.h>

#include "gtest/gtest.h"


/* Assume there's only going to be a single instance of this class. 
*  This class task is solely to enable us to initialize only once the Glog for 
*  all other unit tests's classes.
*/ 
class LoggerWrapper : public ::testing::Environment 
{

public:

	static std::string getStartTime()
	{
	    
  	}

	virtual void SetUp() 
	{ 
		google::SetLogDestination(google::GLOG_FATAL, UNIT_TESTS_GLOG_FATAL_LEVEL_PATH);
		google::InitGoogleLogging(argv0); 
	}
private:
	const char* UNIT_TESTS_GLOG_FATAL_LEVEL_PATH = "/tmp/guyProj/unitTests/log";
};
