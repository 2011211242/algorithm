#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 20001
using namespace std;

int main(){
    int c, n;
    scanf("%d", &c);
    int dp[MAX];
    fill(dp, dp + MAX, 0);
    dp[0] = 1;
    for(int i = 1; i < MAX; i++){
        dp[i] = dp[i - 1] + i;
    }

    for(int i = 0; i < c; i++){
        scanf("%d", &n);
        printf("%d\n", dp[n * 2] - n * 2);
    }
    return 0;
}

