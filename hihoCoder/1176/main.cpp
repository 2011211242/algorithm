#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

enum {
    WHITE,
    GRAY,
    BLACK   
};

static int time = 0;

struct node{
    int d, f, pre;
    vector<int> adj;
    int color;
    node(){
        d = 0;
        f = 0;
        color = WHITE;
        pre = 0;
    }
};

vector<node> map;

void dfs_visit(int u)
{
    time = time + 1;
    map[u].d = time;
    map[u].color = GRAY;

    for(auto v : map[u].adj)
    {
        if(map[v].color == WHITE)
        {
            map[v].pre = u;
            dfs_visit(v);
        }
    }
    map[u].color = BLACK;
    time = time + 1;
    map[u].f = time;
}

void dfs()
{
    for(int i = 1; i <= map.size(); i++)
    {
        if(map[i].color == WHITE)
        {
            dfs_visit(i);
        }
    }
}

bool is_connected_graph()
{
   dfs();
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
        map[u].adj.push_back(v);
        map[v].adj.push_back(u);
    }
}
