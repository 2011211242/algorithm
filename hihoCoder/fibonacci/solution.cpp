#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n, num;
    int flist[30];
    int fi[100009];

    fill(fi, fi + 100009, -1);
    flist[0] = 0;
    flist[1] = 1;
    fi[1] = 0;

    for(int i = 2; i < 30; i++){
        flist[i] = flist[i - 1] + flist[i - 2];
        if(flist[i] <= 100000){
            fi[flist[i]] = flist[i - 1];
        }
    }

    int dp[100009];

    fill(dp, dp + 100009, 0);
    scanf("%d", &n);

    long long int res = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        if(num == 1){
            dp[1] ++;
            res += dp[1];
            dp[1] %= 1000000007;
            res %= 1000000007;
            continue;
        }
        if(num == 2){
            res += dp[1] * (dp[1] - 1) / 2;
            dp[2] += dp[1] * (dp[1] - 1) / 2;
            dp[2] %= 1000000007;
            res %= 1000000007;
        }
        else{
            if(fi[num] != -1){
                dp[num] += dp[fi[num]];
                res += dp[fi[num]];
                dp[num] %= 1000000007;
                res %= 1000000007;
            }
        }
    }
    printf("%lld\n", res);
}
