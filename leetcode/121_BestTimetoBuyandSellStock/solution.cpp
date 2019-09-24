#include  <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int bought = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            max_profit = max(max_profit, prices[i] - bought);
            bought = min(bought,  prices[i]);
        }
        return max_profit;
    }
};

int main() {
    
    Solution s;
    vector<int> prices = { 7,1,5,3,6,4 };

    cout << s.maxProfit(prices) << endl;
}
