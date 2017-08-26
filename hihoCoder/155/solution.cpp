#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        map<int,int> m;
        for(int i = 0; i < n; i++)
        {
            int s, e;
            scanf("%d %d", &s, &e);
            m[s] ++;
            m[e]--;
        }
        int res = 0;
        map<int, int>::iterator iter = m.begin();
        int count = 0;
        for(;iter != m.end(); iter++)
        {
            count += iter -> second;
            res = max(res, count);
        }
        printf("%d\n", res);
    }
}
