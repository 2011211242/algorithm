#include <cstdio>
#include <climits>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++){
            dp[i][1] =  dp[i - 1][1] + nums[i - 1];
        }

        for(int i = 1; i <= n; i++){
            for(int j = 2; j <= m && j <= i; j++){
                int right = nums[i - 1];
                dp[i][j] = max(dp[i - 1][j - 1], right);

                for(int k = i - 2; k > 0 && right <= dp[i][j]; k--){
                    right += nums[k];
                    dp[i][j] = min(max(dp[k][j - 1], right), dp[i][j]);
                }
                //printf("%d\t", dp[i][j]);
            }
            //printf("\n");
        }
        return dp[n][m];
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

