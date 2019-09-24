#include <iostream>
using namespace std;

class A {
public:
    virtual void fa(){
        cout << "&a=" << ((int64_t)&a) << endl;
    }
    uint64_t a;
};

class B {
public:
    virtual void fb(){
        cout << "&b=" << ((int64_t)&b) << endl;
    }
    uint64_t b;
};

class C: public A, public B {
public:
    virtual void fc(){
        cout << "&c=" << ((int64_t)&c) << endl;
        cout << "&c - &b=" << ((int64_t)&c - (int64_t)&b) << endl;
        cout << "&c - &a=" << ((int64_t)&c - (int64_t)&a) << endl;
    }
    uint64_t c;
};

int main() {
    C c;

    cout << "sizeof(A)=" << sizeof(A) << endl;
    cout << "sizeof(B)=" << sizeof(B) << endl;
    cout << "sizeof(C)=" << sizeof(C) << endl;
    c.fa();
    c.fb();
    c.fc();
    return 0;
}
