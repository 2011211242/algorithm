#include <cstdio>
#include <algorithm>

#define NUMS 101
#define MAX 100001
using namespace std;

int n, m;
int dp[MAX];
int a[NUMS], b[NUMS];

void completePack(int cost, int weight){
    for(int i = cost; i <= m; i++)
        dp[i] = max(dp[i], dp[i - cost] + weight);
}

void zeroOnePack(int cost, int weight){
    for(int i = m; i >= cost; i--)
        dp[i] = max(dp[i], dp[i - cost] + weight);
}

void multiplyPack(int cost, int weight, int amount){
    if(cost * amount >= m) completePack(cost, weight);
    else{
        int k = 1;
        while(k < amount){
            zeroOnePack(k * cost, k * weight);
            amount -= k;
            k<<=1;
        }
        zeroOnePack(amount * cost, amount * weight);
    }
}

int main(){
    while(scanf("%d%d", &n, &m) && (n + m)){
        fill(dp, dp + MAX, 0);

        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &b[i]);
        }

        for(int i = 0; i < n; i++){
            multiplyPack(a[i], a[i], b[i]);
        }

        int count = 0;
        for(int i = 1; i <= m; i ++){
            if(dp[i] == i) count++;
        }
        printf("%d\n", count);
    }
}

