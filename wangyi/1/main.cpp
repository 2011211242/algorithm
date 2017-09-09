#include <cstdio>
#include <vector>
using namespace std;

void dfs(int s, const vector<vector<int>> &mp, vector<bool> &visited, int l, int & max_res){
    bool flag = visited[s];
    if(flag == false) visited[s] = true;
    if(l == 0){
        int count = 0;
        for(int i = 0; i < visited.size(); i++){
            if(visited[i] == true){
                count ++;
            }
        }
        max_res = max(count, max_res);
    }
    else{
        for(int i = 0; i < mp[s].size(); i++){
            dfs(mp[s][i], mp, visited, l - 1, max_res);
        }
    }

    if(flag == false) visited[s] = false;
}

int main(){
    int n, l;
    while(scanf("%d %d", &n, &l) != EOF){
        vector<vector<int>> mp(n);
        for(int i = 1; i < n; i++){
            int num;
            scanf("%d", &num);
            mp[i].push_back(num);
            mp[num].push_back(i);
        }

        int max_l = 0;
        vector<bool> visited(n, false);
        visited[0] = true;
        int max_res = 0;
        dfs(0, mp, visited, l, max_res);
        printf("%d\n", max_res);
    }
}
