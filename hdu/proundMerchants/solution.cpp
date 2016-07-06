#include <cstdio>
#include <algorithm>

using namespace std;

sturct {
    int p,q,v;
}node[500];

int main()
{
    int n, m;

    while(~scanf("%d %d", &n, &m)){
        int dp[5001] = {0};
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &node[i].p, &node[i].q, &node[i].v);
        }

        for(int i = 0; i < n; i++){
            for(int j = m; j >= dp)
        }
    }

    return 0;
}
