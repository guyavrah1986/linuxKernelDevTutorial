#include <iostream>
#include <memory>

#include "globalInclude.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "main - start" << endl;
	if (argc != NumOfCommandLineArgs)
	{
		cerr << "main - not enough arguments provided, excpecting:" << NumOfCommandLineArgs << endl;
		return 1;
	}

	unique_ptr<int> p;
	cout << "main - end" << endl;
	return 0;
}
