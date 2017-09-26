#include <cstdio>
#include <iostream>
#include <vector>
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

const int size = 100000;
int main(){
    int m, n;
    char str[size];
    while(scanf("%d %d", &m, &n) != EOF){
        cin.getline(str, size);

        vector<vector<int>> dp(m, vector<int>(n));
        bool flag = true;
        bool flag2 = true;
        for(int i = 0; i < m; i++){
            if(!cin.getline(str, size)){
                flag = false;
                flag2 = false;
                break;
            }
            int j = 0;
            int idx = 0;
            while(flag && str[j]){
                while(str[j] == ' ')j++;
                dp[i][idx] = 0;
                while(str[j] >= '0' && str[j] <= '9'){
                    dp[i][idx] = dp[i][idx] * 10 + str[j] - '0';
                    j++;
                }
                idx++;
                if(idx > n){
                    flag = false;
                    break;
                }
            }

            if(flag && idx != n){
                flag = false;
            }
        }

        int k;
        //printf("flag %d %d\n", flag, flag2);
        if(flag2)
        {
            scanf("%d", &k);
            if(flag){
                bool ret = find(dp, 0, 0, m - 1, n - 1, k);
                printf("%d\n", ret);
            }
            else printf("input error\n");
        }
        else printf("input error\n");
    }
}
