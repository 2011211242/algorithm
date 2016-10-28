#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    int robI(vector<int>&nums){
        if(nums.empty()) return 0;
        int sz = nums.size();
        int l[sz + 1];
        int g[sz + 1];

        l[0] = g[0] = 0;
        l[1] = g[1] = nums[0];

        for(int i = 1; i < sz; i++){
            l[i + 1] = g[i - 1] + nums[i];
            g[i + 1] = max(g[i], l[i + 1]);
        }
        return g[sz];
    }
    int rob(vector<int>&nums){
        if(nums.empty()) return 0;
        if(nums.size() == 1) return max(0, nums[0]);
        if(nums.size() == 2) return max(0, max(nums[0], nums[1]));

        vector<int> s1;
        vector<int> s2;
        s1.resize(nums.size() - 2);
        s2.resize(nums.size() - 1);
        std::copy(nums.begin() + 1, nums.begin() + nums.size() - 2, s1.begin());
        std::copy(nums.begin(), nums.begin() + nums.size() - 1, s2.begin());

        return max(robI(s1) + nums[nums.size() - 1], robI(s2));
    }
};

int main(){
    Solution s;
    vector<int> num = {4, 1, 2, 5};
    printf("res = %d\n", s.rob(num));
}
