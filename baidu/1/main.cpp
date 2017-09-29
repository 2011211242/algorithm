#include <cstdio>
#include <vector>
using namespace std;
#define MAX_L 1000000 

int get_pair(int n){
    int ret = 0;
    while(n){
        ret = ret * 10 + (n % 10);
        n /= 10;
    }
    return ret;
}

int main(){
    vector<bool> dp(MAX_L, true);

    for(int i = 2; i < dp.size(); i++){
        if(dp[i]){
            int next = i + i;
            while(next <  dp.size()){
                dp[next] = false;
                next += i;
            }
        }
    }

    int n;
    scanf("%d", &n);
    int cnt = 0;
    int ret;
    for(int i = 10; i <= 1000000; i++){
        if(dp[i])
        {
            int pr = get_pair(i);
            if(pr != i && dp[pr]){
                cnt ++;
                ret = i; 
            }
        }
        if(cnt >= n) break;
    }
    if(cnt == n && ret <= 1000000) printf("%d\n", ret);
    else printf("-1\n");
}
