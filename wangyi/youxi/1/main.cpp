#include <cstdio>
#include <vector>
using namespace std;

bool find(vector<vector<int>> &dp, int x1, int y1, int x2, int y2, int k){
    if(x1 > x2 || y1 > y2) return false;

    if(dp[x1][y1] > k || dp[x2][y2] < k)
        return false;

    if(dp[x2][y2] == k || dp[x1][y1] == k) 
        return true;

    int x_m = (x1 + x2) / 2, y_m = (y1 + y2) / 2;

    return find(dp, x1, y1, x_m, y_m, k) || find(dp, x_m + 1, y1, x2, y_m, k) || 
        find(dp, x1, y_m + 1, x_m, y2, k) || find(dp, x_m + 1, y_m + 1, x2, y2, k);
}

int main(){
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF){
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int tmp;
                scanf("%d", &tmp);
                dp[i][j] = tmp;
            }
        }
        int k;
        scanf("%d", &k);
        bool ret = find(dp, 0, 0, m - 1, n - 1, k);
        printf("%d\n", ret);
    }
}
