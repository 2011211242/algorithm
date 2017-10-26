#include <cstdio>
#include <bits/stdc++.h>
#include <cstdlib>
#include <queue>

using namespace std;

struct node{
    int x;
    int y;
    node(int a, int b):x(a), y(b){}
};

const int x_dic[4] = {0, 0, 1, -1};
const int y_dic[4] = {1, -1, 0, 0};

bool valid(int x, int y, int m, int n){
    return x >= 0 && y >= 0 && x < m && y < n;
}

vector<vector<int>> \
get_dist(int x, int y, const vector<vector<int>> & mp){ 
    int m = mp.size();
    int n = mp[0].size();

    vector<vector<int>> visited(mp.size(), vector<int>(mp[0].size(), 0));
    vector<vector<int>> dist_map(m, vector<int>(n, INT_MAX));

    node s(x, y);
    visited[x][y] = 1;
    dist_map[x][y] = 0;

    queue<node> que;
    que.push(s);

    while(!que.empty()){
        for(int i = que.size(); i > 0; i--){
            s = que.front();
            que.pop();
            for(int i = 0; i < 4; i++){
                int tmp_x = s.x + x_dic[i];
                int tmp_y = s.y + y_dic[i];

                if(valid(tmp_x, tmp_y, m, n) &&
                        mp[tmp_x][tmp_y] != 1 && 
                        visited[tmp_x][tmp_y] == 0){

                    que.push(node(tmp_x, tmp_y));
                    visited[tmp_x][tmp_y] = 1;
                    dist_map[tmp_x][tmp_y] = dist_map[s.x][s.y] + 1;
                }
            }
            visited[s.x][s.y] = 2;
        }
    }
    return dist_map;
}

void permut(vector<int> &lst, int l, int cost, 
        int & min_cost, const vector<vector<int>> &key_map){

    if(cost >= min_cost) return;
    if(l == lst.size() - 1){
        cost += key_map[lst[l - 1]][lst[l]];
        if(cost < min_cost) min_cost = cost;
    }
    else{
        for(int i = l; i < lst.size() - 1; i++){
            swap(lst[i], lst[l]);
            permut(lst, l + 1, cost + key_map[lst[i - 1]][lst[i]], min_cost, key_map);
            swap(lst[i], lst[l]);
        }
    }
}

int chase_jerry(const vector<vector<int>>& mp, int x, int y){
    int m = mp.size();
    int n = mp[0].size();

    vector<int> X;
    vector<int> Y;

    X.push_back(0);
    Y.push_back(0);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mp[i][j] == 2 
                    && !(i == 0 && j == 0) 
                    && !(i == x && j == y)){
                X.push_back(i);
                Y.push_back(j);
            }
        }
    }

    X.push_back(x);
    Y.push_back(y);

    vector<vector<int>> key_map(X.size(), vector<int>(X.size(), INT_MAX));
    for(int i = 0; i < X.size(); i++){
        int x_s = X[i], y_s = Y[i];
        vector<vector<int>> dist_map = get_dist(x_s, y_s, mp);

        for(int j = 0; j < X.size(); j++){
            key_map[i][j] = dist_map[X[j]][Y[j]];
            if(key_map[i][j] == INT_MAX){
                return -1;
            }
        }
    }

    vector<int> lst;
    for(int i = 0; i < X.size(); i++){
        lst.push_back(i);
    }


    int min_cost = INT_MAX;
    permut(lst, 1, 0, min_cost, key_map);
    return min_cost;
} 

int main(){
    int m, n;
    freopen("test.txt", "r", stdin);
    scanf("%d %d", &m, &n);
    vector<vector<int>> mp(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int tmp;
            scanf("%d", &tmp);
            mp[i][j] = tmp;
        }
    }

    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", chase_jerry(mp, x, y));
}

