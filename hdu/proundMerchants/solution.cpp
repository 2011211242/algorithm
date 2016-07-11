#include <cstdio>
#include <algorithm>

using namespace std;

struct item{
    int p,q,v;
}node[500];

bool cmp(item a, item b){
    return a.p - a.q > b.p - b.q;
}

int main()
{
    int n, m;

    while(~scanf("%d %d", &n, &m)){
        int dp[5001] = {0};
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &node[i].p, &node[i].q, &node[i].v);
        }

        sort(node, node + n, cmp);


        for(int i = 0; i < n; i++){
            for(int j = m; j >= node[i].q; j--)
            {
                dp[j] = max(dp[j], dp[j - node[i].p] + node[i].v);
            }
        }
        printf("%d\n", dp[m]);
    }

    return 0;
}
