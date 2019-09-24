#include <iostream>
using namespace std;
class A{
public:
    A(int a)  { b = a; }
    A()  { }
    ~A() { }

    virtual void testA() { cout << "testA" << endl; }
    virtual void testB() { cout << "testB" << endl; }
    virtual int GetB() { return b; }
private:
    int b;
};
