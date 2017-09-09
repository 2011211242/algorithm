#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int binarySearch(vector<vector<int>> &mp, int s, int m)
    {
        int len = mp[s].size();
        if(m == 1) return mp[s][len - 1];

        int res = INT_MAX;
        for(int i = 0; i <= len - m; i++) 
        {
            res = min(res, max(mp[s][i], binarySearch(mp, s + i + 1, m - 1))); 
        }

        return res;
    }

    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        vector<vector<int>> Map(len);
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                Map[i].push_back(sum);
            }
        }
        return binarySearch(Map, 0, m);
    }
};

int main(){
    Solution s;
    vector<int> nums = {7, 2, 5, 10, 8};
    //vector<int> nums = {1, 2};
    int m = 2;
    int maxSum = s.splitArray(nums, m);
    printf("%d\n", maxSum);
}

