#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

enum{
    white,
    gray,
    black
};

bool dfs(int s, vector<vector<int>> &map, vector<short> &color)
{
    color[s] = gray;
    bool flag = false;

    for(auto next:map[s])
    {
        if(color[next]==gray ) return false;
        if(color[next]==white && dfs(next, map, color) == false) return false;
            
    }
    color[s] = black;
    return true;
}

int main()
{
    int T, M, N;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &M);
        vector<vector<int>> map;
        vector<short> color;
        map.resize(N + 1);
        color.resize(N + 1, white);

        for(int j = 0; j < M; j++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            map[a].push_back(b);
        }

        bool flag = true;
        for(int i = 1; i <= N; i++)
        {
            if(color[i] == white)
            {
                if(dfs(i, map, color) == false)
                {
                    flag = false;    
                    break;
                }
            }
        }
        if(flag) printf("Correct\n");
        else  printf("Wrong\n");
    }
}

