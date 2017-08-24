#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

struct edge
{
    int u,v;   
    bool valid;
    edge(int u1, int v1){
        u = u1;
        v = v1;
        valid = true;
    }
};

int get_next(int u, edge * e)
{
    if(u == e->u) return e -> v;
    else return e -> u;
}

vector<vector<edge*>> map;
vector<int> path;

void dfs(int u)
{
    for(int i = 0; i < map[u].size(); i++)
    {
        if(map[u][i] -> valid)
        {
            map[u][i] -> valid = false;
            dfs(get_next(u, map[u][i]));
        }
    }
    path.push_back(u);
}


int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    map.resize(N + 1);
    for(int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        edge *  e = new edge(u, v);
        map[u].push_back(e);
        map[v].push_back(e);
    }

    int s = 1;
    for(int i = 1; i < map.size(); i++)
    {
        if(map[i].size() % 2 == 1)
        {
            s = i;
            break;
        }
    }

    dfs(s);
    printf("%d", path[0]);
    for(int i = 1; i < path.size(); i++)
    {
        printf(" %d", path[i]);
    }
    printf("\n");

    return 0;
}
