#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
    int dp[100];
    int n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;

    for(int i = 5; i < 100; i++){
        dp[i] = dp[i - 1] + dp[i - 3];
    }

    scanf("%d", &n);
    while(n != 0){
        printf("%d\n", dp[n]);
        scanf("%d", &n);
    }
}

