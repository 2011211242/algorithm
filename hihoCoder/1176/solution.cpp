#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<vector<int>> map;
vector<bool> visited;

void dfs(int u){
    visited[u] = true;
    for(auto v : map[u])
    {
        if(visited[v] == false)
        {
            dfs(v);
        }
    }
}

bool is_connected()
{
    dfs(1);
    visited[0] = true;
    for(auto vst : visited)
    {
        if(!vst) return false;
    }
    return true;
}

int count_prime()
{
    int count = 0;
    for(auto node : map)
    {
        if(node.size() % 2) count++; 
    }
    return count;
}



int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    map.resize(N + 1);
    visited.resize(N + 1, false);

    for(int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        map[u].push_back(v);
        map[v].push_back(u);
    }
    if(is_connected() && count_prime() <= 2)
    {
        printf("Full\n");
    }
    else
    {
        printf("Part\n");
    }
}
