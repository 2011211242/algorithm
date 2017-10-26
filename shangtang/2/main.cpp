#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct Point{
    int x, y;
    Point(int i, int j){
        x = i;
        y = j;
    }
};

int delta_x[4] = {0, 0, 1, -1};
int delta_y[4] = {-1, 1, 0, 0};

bool valid(int x, int y, int m, int n){
    return x >= 0 && y >= 0 && x < m && y < n;
}

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    vector<vector<bool>> mp(m, vector<bool>(n));
    vector<vector<bool>> mp1(m, vector<bool>(n, true));
    vector<vector<bool>> mp2(m, vector<bool>(n, false));

    queue<Point> que;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int tmp;
            scanf("%d", &tmp);
            mp[i][j] = (tmp == 1);
            if(mp[i][j] == false && (i == 0 || j == 0 || j == n - 1)){
                que.push(Point(i, j));
            }
        }
    }
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    while(!que.empty()){
        Point cur = que.front();
        que.pop();

        mp1[cur.x][cur.y] = false;
        for(int i = 0; i < 4; i++){
            int nx = cur.x + delta_x[i];
            int ny = cur.y + delta_y[i];
            if(valid(nx, ny, m, n) && visited[nx][ny] == false && mp[nx][ny] == false){
                que.push(Point(nx, ny));
            }
        }
        visited[cur.x][cur.y] = true;
    }

    for(int i = 0; i < n; i++){
        que.push(Point(m - 1, i));
    }

    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    while(!que.empty()){
        Point cur = que.front();
        que.pop();
        mp2[cur.x][cur.y] = true;
        for(int i = 0; i < 4; i++){
            int nx = cur.x +delta_x[i];
            int ny = cur.y + delta_y[i];
            if(valid(nx, ny, m, n) && visited[nx][ny] == false && mp1[nx][ny] == true){
                que.push(Point(nx, ny));
            }
        }
        visited[cur.x][cur.y] = true;
    }

    int cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j= 0; j < n; j++){
            if(mp2[i][j]) cnt ++;
        }
    }
    printf("%d\n", cnt);
}
