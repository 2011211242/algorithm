#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int v[1001], p[1001];

    scanf("%d", &n);
    while(n != 0)
    {
        int mx = 1;
        for(int i = 1; i <= n; i++){
            scanf("%d", &v[i]);
            if(v[mx] < v[i]) mx = i;
        }
        swap(v[mx], v[n]);
//       sort(v + 1, v + n + 1, cmp);

        fill(p, p + 1001, 0);
        int m;
        scanf("%d", &m);

        if(m < 5)printf("%d\n", m);
        else{
            m -= 5;
            for(int i = 1; i < n; i++){
                for(int j = m; j >= v[i]; j--){
                    p[j] = max(p[j], p[j - v[i]] + v[i]);
                }
            }
            printf("%d\n", m + 5 - p[m] - v[n]);
        }
        scanf("%d", &n);
    }
    return 0;
}

