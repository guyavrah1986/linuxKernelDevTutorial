#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
 
#define GET_PID_NR 39
#define MY_SYS_CALL_NR 335

using namespace std;

int main(int argc, char** argv)
{
	cout << "main - start" << endl;
	//Call an existing syscall as test
	long pid;
	pid = syscall(GET_PID_NR);
	cout << "PID is:" << pid << endl;;
	 
	//Call our syscall
	long res = 1;	
	const char data [] = "some_data";
	char* dst;
	long len = sizeof(data);
	cout << "main - data is " << len << " bytes long, &dst is at address:" << &dst << endl;
	res = syscall(MY_SYS_CALL_NR, data, &dst, len);
	cout << "res is:" << res << endl;
	cout << "main - end" << endl;
	return 0;
}
