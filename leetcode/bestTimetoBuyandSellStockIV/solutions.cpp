#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        if(k >= prices.size() - 1) return solveMaxProfit(prices);
        int g[k + 1] = {0};
        int l[k + 1] = {0};

        for(int i = 0; i < prices.size() - 1; i++){
            int diff = prices[i + 1] - prices[i];
            for(int j = k; j >= 1; j--){
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
    int solveMaxProfit(vector<int> &prices){
        int ret = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i + 1] > prices[i])
                ret += prices[i + 1] - prices[i];
        }
        return ret;
    }
};

