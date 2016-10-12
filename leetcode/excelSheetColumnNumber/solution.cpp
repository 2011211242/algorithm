#include <cstdio>
#include <string>
using namespace std;


class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for(int i = 0; i < s.length(); i++)
        {
            ret = ret * 26 + s[i] - 'A' + 1;
        }
        return ret;
    }
};

int main(){
    Solution s;
    printf("%d\n", s.titleToNumber(string("AB")));
}
