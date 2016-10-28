#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s){
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return s1 == s;
    }
    string shortestPalindrome(string s) {
        if(s.empty()) return s;

        int left = 0, right = s.length(), mid = (left + right) >> 1;
        while(left < right){
            if(isPalindrome(s.substr(0, mid)))left = mid + 1;
            else right = mid - 1;
            mid = (left + right) >> 1;
        }

        printf("%d\n", mid);
        string prefix = s.substr(mid) ;
        return prefix + s;
    }
};


int main(){
    Solution s;
    printf("%s\n", s.shortestPalindrome(string("aacecaaa")).c_str());
    printf("%s\n", s.shortestPalindrome(string("abcd")).c_str());
}
