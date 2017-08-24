#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int get_res(int idx, vector<vector<int>>& tree, vector<bool>&visited, vector<int>& apps, int &max_apps){
    visited[idx] = true;
    int all_app = 0;
    int ret = 0;
    for(int i = 0; i < tree[idx].size(); i++){
        int next = tree[idx][i];
        if(!visited[next]){
            int tmp = get_res(next, tree, visited, apps, max_apps);
            all_app += tmp;
            ret = max(ret, tmp);
        }
    }
    max_apps = max(all_app + apps[idx], max_apps);
    return ret + apps[idx];
}

int main(){
    int numOfapples = 4;
    int numOfNodes = 8;
    vector<int> placeOfapple={2, 3, 5, 6};
    vector<vector<int>> edge = {
        {1, 3},
        {2, 4},
        {1, 2},
        {6, 8},
        {2, 5},
        {3, 7},
        {3, 6},
    };
    vector<vector<int>> tree(numOfNodes + 1);
    vector<int> apps(numOfNodes  + 1, 0);
    vector<bool> visited(numOfNodes  + 1, false);

    for(int i = 0; i < numOfNodes - 1; i++)
    {
        int l = edge[i][0];
        int r = edge[i][1];
        tree[l].push_back(r);
        tree[r].push_back(l);
    }

    for(int i = 0; i <numOfapples; i++){
        apps[placeOfapple[i]] = 1; 
    }
    int res = 0;
    get_res(1, tree, visited, apps, res);
    printf("%d\n", res);
}
