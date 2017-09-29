#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n){
        vector<int> num(n);
        for(int i = 0; i < n; i++){
            int tmp;
            scanf("%d", &tmp);
            num[i] = tmp;
        }
        
        if(n == 1){
            printf("0\n");
            continue;
        }

        int que_size = ((n * (n - 1)) / 2) / 2;
        vector<int> dp;
        sort(num.begin(), num.end());

        int min_abs = INT_MAX;
        int cnt = 0;
        int res = INT_MAX;
        for(int step = 1; step < n; step++){
            int tmp_abs = INT_MAX;
            for(int s = 0; s < n - step; s++){
                int next = num[s + step] - num[s];
                tmp_abs = min(tmp_abs, next);
                dp.push_back(next);
            }
            sort(dp.begin(), dp.end());

            while(cnt < que_size && dp.back() >= min_abs){
                cnt++;
                dp.pop_back();
            }

            if(cnt == que_size){
                res = dp.back();
                break;
            }
            min_abs = tmp_abs;
        }

        printf("%d\n", res);
        scanf("%d", &n);
    }
}
