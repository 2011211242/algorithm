#include <cstdio>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0) return a;
        int local = a ^ b;
        int carry = a & b;
        return getSum(local, carry << 1);
    }
};

int main(){
    Solution s;
    int a = 2;
    int b = 3;
    printf("%d\n", s.getSum(a, b));
}

