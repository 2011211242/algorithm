#include <queue>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:

enum color{
    white, gray, black,
};

struct height{
    int h;
    color c;
    height(): c(white) {}
    height(const int _h, const color _c): h(_h), c(_c) {}

    bool operator < (const height &b) const {
        return h > b.h;
    }
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
    int row = heightMap.size();
    int col;
    if( row ) col = heightMap[0].size();
    else return 0;

    vector<vector<height>> hp(row, vector<height>(col, {h:INT_MAX, c:white}));
    priority_queue<point> que;

    for(int i = 0; i < row; i++ ) {
        hp[i][0].h = heightMap[i][0];
        hp[i][0].c = gray;
        que.push({ x : i, y : 0, h : hp[i][0].h});

        hp[i][col - 1].h = heightMap[i][col - 1];
        hp[i][col - 1].c = gray;
        que.push({ x : i, y : col - 1, h : hp[i][col - 1].h});
    }

    for(int j = 1; j < col - 1; j++ ) {
        hp[0][j].h = heightMap[0][j];
        hp[0][j].c = gray;
        que.push({ x : 0, y : j, h : hp[0][j].h});

        hp[row - 1][j].h = heightMap[row - 1][j];
        hp[row - 1][j].c = gray;
        que.push({ x : row - 1, y : j, h : hp[row - 1][j].h});
    }


    while( !que.empty() ) {
        const vector<int> delta_x = {-1, 1, 0, 0};
        const vector<int> delta_y = {0, 0, -1, 1};

        point p = que.top();
        que.pop();

        const int x = p.x; 
        const int y = p.y;

        hp[x][y].c = black;
        if (hp[x][y].h < heightMap[x][y]){
            hp[x][y].h = heightMap[x][y];
        } 

        const int h = hp[x][y].h;

        for(int i = 0; i < 4; i ++) {
            int nx = x + delta_x[i]; 
            int ny = y + delta_y[i];

            if(!isWithin(nx, ny, row, col) || hp[nx][ny].c == black) {
                continue;
            }

            if (h < hp[nx][ny].h) {
                hp[nx][ny].h = h;
                que.push({x: nx, y: ny, h : hp[nx][ny].h});
            }
        }
    }

    int water = 0;
    for (int i = 1; i < row - 1; i++) {
        for (int j = 1; j < col - 1; j++) {
            water += (hp[i][j].h - heightMap[i][j]);
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
    //s.test();
    return 0;
}
