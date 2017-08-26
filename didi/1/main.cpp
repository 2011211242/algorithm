#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> nums;
    int n;
    while(scanf("%d", &n)!=EOF){
        nums.push_back(n);
    }
    int s = 0;
    int res = 0;
    for(int i = 0; i < nums.size(); i++){
        if(i == 0) res = nums[i];
        s+= nums[i];
        if(s < 0) s = 0;
        else res=max(res, s);
    }
    printf("%d\n", res);
}
