#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &grid,int x,\
            int y, vector<vector<bool>> &visited){
        if(x < 0 || y < 0 || x >= grid.size() || visited[x][y] == true||\
                y >= grid[0].size() || grid[x][y] == '0')
            return;

        visited[x][y] = true;
        dfs(grid, x + 1, y, visited);
        dfs(grid, x, y + 1, visited);
        dfs(grid, x - 1, y, visited);
        dfs(grid, x, y - 1, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        vector<vector<bool>> visited = vector<vector<bool>>(grid.size(), \
                vector<bool>(grid[0].size(), false));

        int ret = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    dfs(grid, i, j, visited);
                    ret ++;
                }
            }
        }
        return ret;
    }
};

int main(){
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution s;
    int ret = s.numIslands(grid);
    printf("%d\n", ret);
}
