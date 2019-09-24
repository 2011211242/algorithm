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

int main() {
    cout << "sizeof a: " << sizeof(A) << endl;
    int shm_id = shmget(888888, sizeof(A), IPC_CREAT|0666);
    if (shm_id == SHM_FAILED) {
        cout << "create shared mem fail" << endl;
        return 0;
    }
    
    char * buf; 
    buf = (char*) shmat(shm_id, NULL, 0);

    A a;
    //*(int64_t*)buf = *(int64_t*)(&a);

    A * pc = new(buf)A();//(A*)buf;

    cout << "pc GetB: " << pc -> GetB() << endl;
    pc -> testA();
}
