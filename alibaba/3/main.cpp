#include <cstdio>
#include <vector>
using namespace std;

int get(int n){
    const int len = 3500;

    vector<int> dp(len, 0);
    vector<int> sum(len, 0);
    int k = 0;
    int i = 1;
    for(; i < len && k < n; i++){
        dp[i] = 1 + dp[i / 10];
        sum[i] = dp[i] + sum[i - 1];
        k += sum[i];
    }
    i--;

    k = sum[i] - (k - n);
    int s = 0;

    while(k > sum[s]){
        s++;
    }

    int t = sum[s] - k;
    while(t){
        t--;
        s /= 10;
    }
    return s % 10;
}

int main(){
    int n;
    scanf("%d", &n);
    int r = get(n);
    printf("%d\n", r);
}

