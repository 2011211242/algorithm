#include <cstdio>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        int digit = 0;
        while(num > 0){
            digit += num % 10;
            num /= 10;
        }
        return addDigits(digit);
    }
};
