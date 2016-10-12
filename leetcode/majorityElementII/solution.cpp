#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;

        int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate1) count1 ++;
            else if(nums[i] == candidate2) count2 ++;
            else if(count1 == 0) candidate1 = nums[i], count1 = 1;
            else if(count2 == 0) candidate2 = nums[i], count2 = 1;
            else count1 = count1 - 1, count2 = count2 - 1;
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate1) count1 ++;
            if(nums[i] == candidate2) count2 ++;
        }
        if(count1 > nums.size() / 3) res.push_back(candidate1);
        if(count2 > nums.size() / 3) res.push_back(candidate2);

        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 1, 2, 3, 4, 2, 1};
    vector<int> res = s.majorityElement(nums);

    printf("----------------------------------\n");
    for(int i = 0; i < res.size(); i++){
        printf("%d\t", res[i]);
    }
    printf("\n--------------------------------\n");
}
