#include <cstdio>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) == mp.end()){
                mp.add(nums[i]);
            }
            else return true;
        }
        return false;
    }
};

int main(){}
