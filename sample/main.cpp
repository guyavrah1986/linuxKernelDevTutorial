#include <iostream>
#include <memory>
#include <glog/logging.h>

#include "globalInclude.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "main - start" << endl;
	google::InitGoogleLogging(argv[0]);

	LOG(INFO) << "This is an info  message";
	if (argc != NumOfCommandLineArgs)
	{
		cerr << "main - not enough arguments provided, excpecting:" << NumOfCommandLineArgs << endl;
		return 1;
	}

	unique_ptr<int> p;
	cout << "main - end" << endl;
	return 0;
}
