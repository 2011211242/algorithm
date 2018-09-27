//287. Find the Duplicate Number

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            while(nums[i] != i) {
                int cur = nums[i];
                if(cur != nums[cur]) {
                    swap(nums[i], nums[cur]);
                }
                else return cur;
            }
        }
        return nums[0];
    }
};

int main() {
    Solution s;
    vector<int> num = {1, 2, 3, 2};
    cout << s.findDuplicate(num) << endl;
}
