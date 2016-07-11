#include <cstdio>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverse(string str, int s, int e){
        while(s < e){
            swap(str[s++], str[e--]);
        }
        return str;
    }
    string convertToTitle(int n) {
        string res("");
        while(n){
            n -= 1;
            res.push_back('A' + n % 26);
            n /= 26;
        }
        return reverse(res, 0, res.length() - 1);
    }
};

int main(){
    Solution s;
    cout << s.convertToTitle(1) << endl;
    cout << s.convertToTitle(26) << endl;
    cout << s.convertToTitle(27) << endl;
}
