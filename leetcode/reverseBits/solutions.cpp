#include <cstdio>
#include <stdint.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t sm = 0x01, em = 0x80000000;
        int res = 0;
        for(int i = 0; i < 32; i++){
            res = (res << 1) ^ (n & 0x01);
            n >>= 1;
        }
        return res;
    }
};

int main(){
    Solution s;
    uint32_t u = s.reverseBits(43261596);
    printf("%u\n", u);
}
