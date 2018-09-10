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
	long res = 7;
	char* buff = NULL;
	size_t buffSize = 5;	
	res = syscall(MY_SYS_CALL_NR, buff, buffSize);
	cout << "res is:" << res << endl;
	cout << "main - end" << endl;
	return 0;
}
