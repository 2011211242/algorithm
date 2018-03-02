#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(); 
        int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int l = 0, h = n1 * 2;
        while(l <= h){
            int mid1 = (l + h) / 2;
            int mid2 = n1 + n2 - mid1;
            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];

            double R1 = (mid1 == n1 * 2) ? INT_MAX : nums1[(mid1) / 2];
            double R2 = (mid2 == n2 * 2) ? INT_MAX : nums2[(mid2) / 2];

            if(R1 < L2) l = mid1 + 1;
            else if(L1 > R2) h = mid1 - 1;
            else return (max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};


int main(){
    vector<int> nums1 = {1, 2, 4, 7, 9};
    vector<int> nums2 = {3, 5, 8, 13, 15, 16};
    Solution s;
    int median = s.findMedianSortedArrays(nums1, nums2);
    cout << median << endl;
}
