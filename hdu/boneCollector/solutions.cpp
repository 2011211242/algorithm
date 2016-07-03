#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int t;
    int n, v;
    int dp[1001];
    int val[1001], vlm[1001];
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d", &n, &v);
        for(int j = 0; j < n; j++){
            scanf("%d", &val[j]);
        }
        for(int j = 0; j < n; j++){
            scanf("%d", &vlm[j]);
        }

        fill(dp, dp + v + 1, 0);
        for(int k = 0; k < n; k++){
            for(int l = v; l >= vlm[k]; l--){
                dp[l] = max(dp[l], dp[l - vlm[k]] + val[k]);
            }
        }
        printf("%d\n", dp[v]);
    }
}
