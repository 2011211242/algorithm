//https://blog.csdn.net/wangfengwf/article/details/52928174
#include <sys/ipc.h>
#include <sys/shm.h>
#include "mem_obj.h"
#include <iostream>
#include<cstring>
using namespace std;

#ifndef SHM_FAILED  //定义方法调用出错常量符号
#define SHM_FAILED -1
#endif

static int b = 100;
int main() {
    int c = b;
    cout << "sizeof a: " << sizeof(A) << endl;
    int shm_id = shmget(888888, sizeof(A), IPC_CREAT|0666);
    if (shm_id == SHM_FAILED) {
        cout << "create shared mem fail" << endl;
        return 0;
    }

    A a(5);

    char * buf; 
    buf = (char*) shmat(shm_id, NULL, 0);

    //*(buf + 1) = '0';

    memcpy((void *)buf, (void *)&a, sizeof(A));

    A * pc = (A*)buf;
    cout << "Get B: " << pc -> GetB() << endl;
    pc -> testA();
}
