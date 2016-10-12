#include <cstdio>
#include <stdint.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            cnt++;
            n &= (n - 1);
        }
        return cnt;
    }
};

int main(){
    Solution s;
    int cnt = s.hammingWeight(11);
    printf("%d\n", cnt);
}
