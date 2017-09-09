#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        vector<int> dp(n);
        vector<int> num(n);

        int tmp;
        scanf("%d", &tmp);
        num[0] = tmp;
        dp[0] = 0;
        int min_res = 0;
        int max_gap = 0;

        for(int i = 1; i < n; i++){
            scanf("%d", &tmp);
            num[i] = tmp;
            dp[i] = num[i] > num[i - 1] ? num[i] - num[i - 1] : num[i - 1] - num[i];

            min_res += dp[i];
            max_gap = max(max_gap, dp[i]);
        }
        
        int res = min_res - max_gap;
        for(int s = 1; s < n - 1; s++){
            for(int e = s + 1; e < n; e ++){
                int tmp = num[s - 1] > num[e] ? num[s - 1] - num[e] : num[e] - num[s - 1];
                res = min(res, min_res - dp[s] - dp[e] + tmp); 
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

