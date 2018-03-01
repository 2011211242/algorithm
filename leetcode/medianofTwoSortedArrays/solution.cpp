#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        int l1 = 0, l2 = 0, h1 = m - 1, h2 = n - 1;
        double k = (m + n) / 2.0;

        while(l1 < h1){
            int pad = (int)min(h1 - l1, k - 1);
            if(nums1[l1 + pad] > nums2[h2 - pad]){
                h1 = l1 + pad;
                l2 = h2 - pad;
                k =
            }
            else if(nums1[l1 + pad] > nums2[h2 - pad]){

            }
            else
                return nums1[l1 + pad];

        }
    }
};


int main(){
    vector<int> nums = {1, 2, 4, 7, 9};
    vector<int> nums = {3, 5, 8, 13, 15, 16};
}
