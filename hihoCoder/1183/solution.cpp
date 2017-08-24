#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    vector<int> next;
    bool visited;
    int parent;
    int low;
    int dfn;
    node(){visited = false;parent = 0;}
};

vector<node> graph;
vector<int> articulation;
vector<pair<int, int>> bridge;

void dfs(int u)
{
    static int counter = 0;
    int children = 0;
    graph[u].visited = true;
    graph[u].low = graph[u].dfn = ++counter;

    for(int i = 0; i < graph[u].next.size(); i++)
    {
        int v = graph[u].next[i];
        if(!graph[v].visited)
        {
            children++;
            graph[v].parent = u;
            dfs(v);
            graph[u].low = min(graph[u].low, graph[v].low);

            if(graph[u].parent == 0 && children > 1)
            {
                articulation.push_back(u);
            }

            if(graph[u].parent != 0 && graph[v].low >= graph[u].dfn)
            {
                articulation.push_back(u);
            }

            if(graph[v].low > graph[u].dfn)
            {
                if(u < v) bridge.push_back(pair<int,int>(u, v));
                else bridge.push_back(pair<int,int>(v, u));
            }
        }
        else if(v != graph[u].parent)
        {
            graph[u].low = min(graph[u].low, graph[v].dfn);
        }
    }
}

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.first > b.first || (a.first == b.first && a.second > b.second);
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    graph.resize(N + 1);
    for(int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].next.push_back(v);
        graph[v].next.push_back(u);
    }
    dfs(1);

    if(articulation.size() > 0)
    {
        sort(articulation.begin(), articulation.end());
        printf("%d", articulation[0]);
        for(int i = 1; i < articulation.size(); i++)
        {
            printf(" %d", articulation[i]);

        }
    }
    else
    {
        printf("Null");
    }
    printf("\n");

    sort(bridge.begin(), bridge.end(), cmp);
    for(int i = 0; i < bridge.size(); i++)
    {
        printf("%d %d\n", bridge[i].first, bridge[i].second);
    }
    return 0;
}

