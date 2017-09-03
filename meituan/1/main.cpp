#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100000;
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        vector<int> dp(n + 1, 0);
        vector<int> num(n + 1);
        for(int i = 1; i <= n; i++){
            int tmp;
            scanf("%d", &tmp);
            num[i] = tmp;

            dp[i] = dp[i - 1] + num[i];
        }

        int k;
        int max_l = 0;
        scanf("%d", &k);

        bool flag = true;
        for(int t = n; t > 0; t--)
        {
            int e = n;
            int s = e - t;
            while(s >= 0){
                if((dp[e] - dp[s]) % k == 0) {
                    max_l = t;
                    flag = false;
                }
                e--;
                s--;
            }
            if(flag == false) break;
        }
        printf("%d\n", max_l);
    }
}
