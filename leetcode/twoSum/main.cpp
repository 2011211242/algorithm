#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int val;
    int idx;
};

bool cmp(node &a, node &b){
    return a.val < b.val;
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<node> numidx;
        numidx.resize(nums.size());
        for(int i = 0; i < nums.size(); i++){
            numidx[i].val = nums[i];
            numidx[i].idx = i;
        }
        sort(numidx.begin(), numidx.end(), cmp);

        int s = 0, e = numidx.size() - 1;
        vector<int> res;
        res.resize(2);
        while(s < e){
            if(numidx[s].val + numidx[e].val == target){
                res[0] = numidx[s].idx;
                res[1] = numidx[e].idx;
                break;
            }
            else{
                if(numidx[s].val + numidx[e].val < target){
                    s++;
                }
                else{
                    e--;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 4, 1, 5, 2, 7, 6};
    vector<int> res = s.twoSum(nums, 12);
    cout << res[0] << "\t" << res[1] << endl;
}
