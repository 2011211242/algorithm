#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        vector<int> dp(1005);
        vector<int> pos;
        int num;
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &num);
            pos.push_back(num);
        }
        sort(pos.begin(), pos.end());
        long long int res = 1;
        int cur = 0;
        for(int i = 0; i < pos.size(); i++){
            if(pos[i] <= cur){
                res = 0;
                break;
            }
            res *= (pos[i] - cur);
            if(res >= 1000000007) res -=1000000007;
            cur ++;
        }
        printf("%lld\n", res);
    }
}
