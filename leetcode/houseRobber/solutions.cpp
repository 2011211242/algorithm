#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        int l[sz + 1];
        int g[sz + 1];

        l[0] = g[0] = 0;
        l[1] = g[1] = nums[0];

        for(int i = 1; i < nums.size(); i++){
            l[i + 1] = g[i - 1] + nums[i];
            g[i + 1] = max(g[i], l[i + 1]);
        }
        return g[sz];
    }
};

int main(){
    vector<int> nums = {7, 10, 8, 2};
    Solution s;
    int mny = s.rob(nums);
    printf("%d\n", mny);
}
