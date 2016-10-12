#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
    int T, N;
    int num;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d", &N);
        int maxSum = INT_MIN, dp = 0, s, e, stmp = 1;
        for(int j = 1; j <= N; j++){
            scanf("%d", &num);

            dp += num;
            if(dp > maxSum){
                maxSum = dp;
                s = stmp;
                e = j;
            }

            if(dp < 0){
                stmp = j + 1;
                dp = 0;
            }
        }
        printf("Case %d:\n%d %d %d\n", i, maxSum, s, e);
        if(i < T) printf("\n");
    }
}
