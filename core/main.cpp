#include <stdio.h>

void test1(){
    char str[2];
    str[100000] = 't';

}

void test(){
    test1();
}

int main(){
    test();
    return 0;
}

