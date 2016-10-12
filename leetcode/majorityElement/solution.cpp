#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0) {
                candidate = nums[i];
                count = 1;;
            }
            else{
                if(nums[i] == candidate) count ++;
                else count--;
            }
        }
        return candidate;
    }
};

int main(){
    Solution s;
    vector<int> num = {1, 1, 2, 2, 2};
    int ret = s.majorityElement(num);
    printf("%d\n", ret);
    return 0;
}
