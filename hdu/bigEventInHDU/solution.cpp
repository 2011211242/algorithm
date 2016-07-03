#include <cstdio>
#include <algorithm>
using namespace std;

int dp[250001];
int value[5001];

int main(){
    int n;
    while(~scanf("%d", &n), n > 0)
    {
        int l = 0;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            int a, b;
            scanf("%d %d", &a, &b);

            sum += a * b;
            while(b--){
                value[l++] = a;
            }
        }

        int t = sum / 2;
        fill(dp, dp + t + 1, 0);

        for(int i = 0; i < l; i++){
            for(int j = t; j >= value[i]; j--){
                dp[j] = max(dp[j], dp[j - value[i]] + value[i]);
            }
        }
        printf("%d %d\n", sum - dp[t], dp[t]);
    }
    return 0;
}
