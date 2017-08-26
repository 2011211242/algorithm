#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct cmp{
    bool operator() (const int i, const int j){
        return i > j;
    }
};

int main(){
    priority_queue<int, vector<int>, cmp> que;
    vector<int> nums;
    int n;
    while(scanf("%d", &n)!=EOF){
        nums.push_back(n);
    }
    int k = nums.back();
    for(int i = 0; i < nums.size() - 1; i++){
        if(i < k) que.push(nums[i]);
        else{
            if(nums[i] > que.top()){
                que.push(nums[i]);
                que.pop();
            }
        }
    }
    int t = que.top();
    printf("%d\n", t);
}
