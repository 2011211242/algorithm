#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(m == 0) return 0;
        int n = dungeon[0].size();
        if(n == 0) return 0;
        vector<int> res;
        vector<int> num_res;

        int num = dungeon[0][0];
        num_res.push_back(num);
        res.push_back(num);

        for(int i = 1; i < n; i++){
            num += dungeon[0][i];
            res.push_back(num);
            num_res.push_back(min(num, num_res[i - 1]));
        }

        for(int i = 1; i < m; i++){
            res[0] = res[0] + dungeon[i][0];
            num_res[0] = min(res[0], num_res[0]);

            for(int j = 1; j < n; j++){
                if(res[j - 1] + dungeon[i][j] > res[j] + dungeon[i][j]){
                    res[j] = res[j - 1] + dungeon[i][j];
                }
                else{
                    res[j] = res[j] + dungeon[i][j];
                }
                num_res[j] = max(min(res[j], num_res[j - 1]), min(res[j], num_res[j]));
            }
        }
        return 1 - min(num_res[n - 1], 0);
    }
};

int main(){
    vector<vector<int>> input = {
        {3, -20, 30},
        {-3, 4, 0}
    };
    Solution s;
    printf("%d\n", s.calculateMinimumHP(input));
}
