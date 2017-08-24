#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

struct edge
{
    int v;
    bool valid;
    edge(int v1){
        v = v1;
        valid = true;
    }
};

vector<vector<edge>> map;
vector<int> path;

void dfs(int u)
{
    for(int i = 0; i < map[u].size(); i++)
    {
        if(map[u][i].valid)
        {
            map[u][i].valid = false;
            dfs(map[u][i].v);
            path.push_back(map[u][i].v & 0x01);
        }
    }
}


int main()
{
    int N;
    scanf("%d", &N);
    int opt = 0;

    for(int i = 1; i < N; i++)
    {
        opt = (opt << 1) + 1;
    }

    map.resize(opt + 1);
    for(int i = 0; i <= opt; i++)
    {
        map[i].push_back(edge(((i << 1) + 0) & opt));
        map[i].push_back(edge(((i << 1) + 1) & opt));
    }

    dfs(0);

    for(int i = 0; i < path.size(); i++)
    {
        printf("%d", path[i]);
    }
    printf("\n");
    return 0;
}
