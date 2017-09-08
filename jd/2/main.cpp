#include <cstdio>
#include <vector>
using namespace std;

bool judge(const vector<int> &num, int k){
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < num.size(); i++){
        for(int j = k; j >= num[i]; j--){
            dp[j] += dp[j - num[i]];
        }
    }
    return dp[k] > 0;
}

int main(){
    int l, r;
    while(scanf("%d %d", &l, &r) != EOF){
        int res = 0;
        for(int i = l; i <= r; i++){
            int tmp = i;
            vector<int> num;
            int sum = 0;
            while(tmp){
                int tp = tmp % 10;
                if(tp > 0){
                    num.push_back(tp);
                    sum += tp;
                }
                tmp /= 10;
            }
            if(sum % 2 == 0){
                res += judge(num, sum / 2);
            }
        }
        printf("%d\n", res);
    }
}
