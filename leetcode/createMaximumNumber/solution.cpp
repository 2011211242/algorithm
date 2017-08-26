#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool cmp(vector<int>& a, vector<int>& b){
        for(int i = 0; i < a.size() && i < b.size(); i++){
            if(a[i] > b[i]) return true;
            if(a[i] < b[i]) return false;
        }
        if(a.size() > b.size()) return true;
        else return false;
        return true;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> cand1 = candidates(nums1, k);
        vector<vector<int>> cand2 = candidates(nums2, k);
        vector<int> res;

        if(!cand1.empty() && cand1[0].size() == k){
            res = cand1[0];
        }

        if(!cand2.empty() && cand2[0].size() == k){
            res = cand2[0];
        }

        int s1, s2;

        if(cand1.size() < k) s1 = 0;
        else s1 = 1;

        if(s1 < cand1.size())
        {
            s2 = cand2.size() - k + cand1[s1].size();

            while(s1 < cand1.size() && s2 >= 0){
                vector<int> tmp = combine(cand1[s1], cand2[s2]);
                if(res.empty()) res = tmp;
                else if(cmp(res, tmp) == false) res = tmp;

                s2--;
                s1++;
            }
        }
        return res;

    }
//private:
    vector<int> combine(vector<int>& nums1, vector<int>& nums2){
        int s1 = 0, s2 = 0;
        vector<int> res;
        while(s1 < nums1.size() && s2 < nums2.size()){
            vector<int> a = vector<int>(nums1.begin() + s1, nums1.end());
            vector<int> b = vector<int>(nums2.begin() + s2, nums2.end());

            if(cmp(a, b)){
                res.push_back(nums1[s1]);
                s1++;
            }
            else{
                res.push_back(nums2[s2]);
                s2++;
            }
        }

        while(s1 < nums1.size()){
            res.push_back(nums1[s1]);
            s1++;
        }

        while(s2 < nums2.size()){
            res.push_back(nums2[s2]);
            s2++;
        }

        return res;
    }

    vector<int> removeOne(vector<int>& nums){
        vector<int> res;
        int i = 0;
        while(res.size() < nums.size() - 1){
            if(i < nums.size() - 1 && nums[i] < nums[i + 1]){
                break;
            }
            res.push_back(nums[i]);
            i++;
        }

        i++;
        while(res.size() < nums.size() - 1){
            res.push_back(nums[i]);
            i++;
        }
        return res;
    }

    vector<vector<int>> candidates(vector<int>& nums, int k){
        vector<vector<int>> res;
        vector<int> tmp = nums;
        while(tmp.size() > k) tmp = removeOne(tmp);

        while(!tmp.empty()){
            res.push_back(tmp);
            tmp = removeOne(tmp);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 4, 2, 9, 8, 3, 7};

    for(int i = 0; i < nums.size(); i++){
        printf("%d", nums[i]);
    }
    printf("\n");

    vector<int> res = s.removeOne(nums);
    
    for(int i = 0; i < res.size(); i++){
        printf("%d", res[i]);
    }
    printf("\n");

    vector<vector<int>> cand = s.candidates(nums, 5);
    for(int i = 0; i < cand.size(); i++){
        printf("line %d:", i);
        for(int j = 0; j < cand[i].size(); j++){
            printf(" %d", cand[i][j]);
        }
        printf("\n");
    }

    vector<int> nums1 = {3, 4, 6, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    res = s.maxNumber(nums1, nums2, 5);

    printf("res:-------\n");
     
    for(int i = 0; i < nums1.size(); i++){
        printf("%d", nums1[i]);
    }
    printf("\n");
 
    for(int i = 0; i < nums2.size(); i++){
        printf("%d", nums2[i]);
    }
    printf("\n");

    for(int i = 0; i < res.size(); i++){
        printf("%d", res[i]);
    }
    printf("\n");
}

