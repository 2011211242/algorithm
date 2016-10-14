#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int C;
    scanf("%d", &C);
    for(int i = 0; i < C; i++){
        int n;
        int num;
        int dp[100];
        //fill(dp, dp + sizeof(dp) / sizeof(int), 0);
        //printf("%d\n", sizeof(dp) / sizeof(int));
        int res = 0;

        scanf("%d", &n);

        scanf("%d", &num);
        dp[0] = num;

        for(int j = 1; j < n; j++){
            scanf("%d", &num);
            dp[j] = dp[j - 1] + num;

            for(int k = j - 1; k > 0; k--){
                scanf("%d", &num);
                dp[k] = max(dp[k - 1], dp[k]) + num;
            }
            scanf("%d", &num);
            dp[0] += num;
        }

        for(int i = 0; i < n; i++){
            res = max(res, dp[i]);
        }
        printf("%d\n", res);
    }
}
