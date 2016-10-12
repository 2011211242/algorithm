#include <cstdio>
using namespace std;


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(n > m){
            n = n & (n - 1);
        }
        return n;
    }
};
int main(){
    Solution s;
    int res = s.rangeBitwiseAnd(5, 7);
    printf("%d\n", res);
}
