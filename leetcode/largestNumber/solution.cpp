#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string intToString(int a){
    char tmp[30];
    sprintf(tmp, "%d", a);
    return string(tmp);
}

bool cmp(int a, int b){
    string astr, bstr;
    astr = intToString(a);
    bstr = intToString(b);

    return astr + bstr > bstr + astr;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0 && res.empty() && i != nums.size() - 1)
                continue;

            res += intToString(nums[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 30, 34, 5, 9};
    sort(nums.begin(), nums.end());
    string str = s.largestNumber(nums);
    printf("%s\n", str.c_str());
}
