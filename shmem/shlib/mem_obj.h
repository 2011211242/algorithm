#include <iostream>
using namespace std;
class A{
public:
    A(int b)  { a = b; }
    A()  { }
    ~A() { }

    virtual void test() { cout << "test" << endl; }
    virtual int Get() { return a; }
private:
    int a;
};
