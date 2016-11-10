#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMaxLength(string str){
        int * next = new int[str.length() + 1];
        next[0] = next[1] = 0;
        int j = 0;

        for(int i = 1; i < str.length(); i++){
            while(j > 0 && str[i] != str[j]) j = next[j];
            if(str[i] == str[j]) j++;
            next[i + 1] = j;
        }

        int res = next[str.length()];
        delete [] next;
        return res;
    }

    string shortestPalindrome(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int len = getMaxLength(s + "#" + s1);
        string s2 = s.substr(len);
        reverse(s2.begin(), s2.end());
        return s2 + s;
    }
};


int main(){
    Solution s;
    printf("%s\n", s.shortestPalindrome(string("aacecaaa")).c_str());
    printf("%s\n", s.shortestPalindrome(string("abcd")).c_str());
}
