#include <cstdio>
#include <limits>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int digits = num.length() - k;
        char* stk = new char[num.length()];
        int top = 0;

        for(int i = 0; i < num.length(); i++)
        {
            char c = num[i];
            while(top > 0 && stk[top - 1] > c && k > 0)
            {
                top -= 1;
                k -= 1;
            }
            stk[top++] = c;
        }
        int idx = 0;
        while(idx < digits && stk[idx] == '0') idx++;
        return idx == digits? "0": string(stk, idx, digits - idx);
    }
};
 

int main()
{
    Solution s;
    string num = "10";
    printf("%s\n", s.removeKdigits(num, 2).c_str());
}
