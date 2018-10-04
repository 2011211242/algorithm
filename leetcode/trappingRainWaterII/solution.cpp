#include <queue>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:

enum color{
    white, black,
};

struct point {
    int x, y;
    int h;
    
    point(int _x, int _y, int _h) : x(_x), y(_y), h(_h){}

    bool operator < (const point &b) const {
        return h > b.h;
    }
};


bool isWithin(int x, int y, int row, int col) {
    return x >= 0 && x < row && y >= 0 && y < col;
}


int trapRainWater(vector<vector<int>>& heightMap) {
    if (heightMap.empty()) return 0;

    int row = heightMap.size();
    int col = heightMap[0].size();

    vector<vector<color>> colorMap(row, vector<color>(col, white));
    priority_queue<point> que;

    for(int i = 0; i < row; i++ ) {
        colorMap[i][0] = black;
        que.push({ x : i, y : 0, h : heightMap[i][0]});

        colorMap[i][col - 1] = black;
        que.push({ x : i, y : col - 1, h : heightMap[i][col - 1]});
    }

    for(int j = 1; j < col - 1; j++ ) {
        colorMap[0][j] = black;
        que.push({ x : 0, y : j, h : heightMap[0][j]});

        colorMap[row - 1][j] = black;
        que.push({ x : row - 1, y : j, h : heightMap[row - 1][j]});
    }

    int water = 0;
    while( !que.empty() ) {
        const vector<int> delta_x = {-1, 1, 0, 0};
        const vector<int> delta_y = {0, 0, -1, 1};

        const point p = que.top();
        que.pop();

        const int h = p.h;
        for(int i = 0; i < 4; i ++) {
            int nx = p.x + delta_x[i]; 
            int ny = p.y + delta_y[i];

            if(!isWithin(nx, ny, row, col) || colorMap[nx][ny] == black) {
                continue;
            }

            colorMap[nx][ny] = black;
            if (h > heightMap[nx][ny]) {
                water += h - heightMap[nx][ny];
                que.push({x: nx, y: ny, h : h});
            }
            else {
                que.push({x: nx, y: ny, h : heightMap[nx][ny]});
            }
        }
    }

    return water;
}

};


int main() {
    vector<vector<int>> heightMap = 
        {{13,16,15,18,15,15},{14,1,8,9,7,9},{19,5,4,2,5,10},{13,1,7,9,10,3},{17,7,5,10,6,1},{15,9,8,2,8,3}};

    Solution s;
    cout << s.trapRainWater(heightMap) << endl;
    return 0;
}
