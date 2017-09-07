#include <cstdio>
#include <vector>
using namespace std;

int get_num(const vector<int>& num, int k){
    vector<int> dp(k + 1);
    dp[0] = 1;
    for(int i = 0; i < num.size(); i++){
        for(int j = k; j >= num[i]; j--){
            dp[j] += dp[j - num[i]];
        }
    }
    return dp[k];
}

int main(){
    vector<int> num = {1, 2, 3, 4, 3};
    int res = get_num(num, 5);
    printf("%d\n", res);
}
