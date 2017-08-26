#include <cstdio>
#include <cstdlib>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 0; i < nums.size(); i++)
            x ^= nums[i];
        
        x &= -x;
        vector<int> res(2, 0);

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] & x) res[0] ^= nums[i];
            else    res[1] ^= nums[i];
        } 
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> res = s.singleNumber(nums);
    for(int i = 0; i < res.size(); i++)
    {
        printf("%d\t", res[i]);
    }
    printf("\n");
    return 0;
}
