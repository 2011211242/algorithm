#include <cstdio>
#include <algorithm>
using namespace std;

struct {
    int price;
    int vol;
} node[1005];

int main(){
    int t, a[32], b[32];
    int n,v,k;

    scanf("%d", &t);

    while(t--){
        int dp[1005][32] = {0};
        scanf("%d %d %d", &n, &v, &k);
        for(int i = 0; i < n; i++){
            scanf("%d", &node[i].price);
        }

        for(int i = 0; i < n; i++){
            scanf("%d", &node[i].vol);
        }

        for(int i = 0; i < n; i++){
            for(int j = v; j >= node[i].vol; j--){
                int d;
                for(d = 1; d <= k; d++){
                    a[d] = dp[j - node[i].vol][d] + node[i].price;
                    b[d] = dp[j][d];
                }
                int x, y, z;
                x = y = z = 1;
                a[d] = b[d] = -1;

                while(z <= k && (x <= k || y <= k)){
                    if(a[x] > b[y]){
                        dp[j][z] = a[x];
                        x++;
                    }
                    else{
                        dp[j][z] = b[y];
                        y++;
                    }
                    if(dp[j][z] != dp[j][z - 1])z++;
                }
            }
        }
        printf("%d\n", dp[v][k]);
    }
    return 0;
}
