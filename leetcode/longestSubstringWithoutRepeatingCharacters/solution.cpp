#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_idx(256, -1);
        int dp = -1, ret = 0;
        for(int i = 0; i < s.length(); i++){
            dp = max(dp, last_idx[s[i]]);
            last_idx[s[i]] = i;
            ret = max(ret, i - dp);
        }
        return ret;
    }
};

int main(){
}
