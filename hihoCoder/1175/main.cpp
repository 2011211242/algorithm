#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#define MAX 142857

enum {
    white,
    gray,
    black
};

struct node{
    int w;
    vector<int> next;
    int color;
    node(){
        w = 0;
        color = white;
    }
};

vector<node> map;
vector<int> startlist;

void dfs(int s)
{
    map[s].color = gray;
    for(auto next : map[s].next)
    {
        if(map[next].color == white)
        {
            dfs(next);
        }
        map[s].w += map[next].w;
        if(map[s].w >= MAX) map[s].w -= MAX;
    }

    map[s].w++;
    if(map[s].w >= MAX) map[s].w -= MAX;
    map[s].color = black;
}

int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    map.resize(N + 1);
    for(int i = 0; i < K; i++)
    {
        int s;
        scanf("%d", &s);
        startlist.push_back(s);
    }

    for(int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        map[u].next.push_back(v);
    }

    for(int i = 1; i <= N; i++)
    {
        if(map[i].color == white)
        {
            dfs(i);
        }
    }

    int res = 0;
    for(auto s:startlist)
    {
        res += map[s].w;
        if(res >= MAX) res -= MAX;
    }
    printf("%d\n", res);
}
