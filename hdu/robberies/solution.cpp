#include <cstdio>
#include <algorithm>
using namespace std;

struct {
    int money;
    double p;
}node[100];

int main(){
    int t = 2;
    scanf("%d", &t);
    while(t--){
        int n, sum = 0;
        double p, dp[10001] = {1.0};
		printf("%lf %lf %lf", dp[0], dp[1], dp[2]);
        //memset(dp, dp )

        scanf("%lf %d", &p, &n);
        p = 1.0 - p;

        for(int i = 0; i < n; i++){
            scanf("%d %lf", &node[i].money, &node[i].p);
            node[i].p = 1 - node[i].p;
            sum += node[i].money;
        }

        for(int i = 0; i < n; i++){
            for(int j = sum; j >= node[i].money; j--){
                dp[j] = max(dp[j], dp[j - node[i].money] * node[i].p);
            }
        }

        int i;
        for(i = sum; dp[i] < p; i--);
        printf("%d\n", i);
    }
}

