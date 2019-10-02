/**
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Version: 1.0: solution.cpp 2019年09月30日 
 *
 * Authors:
 *   andrewyan <andrewyan@tencent.com>
 */

#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k <= 0 || prices.size() < 2) return 0;

        if (k >= prices.size() - 1)
        {
            int profit = 0;
            for(int i = 1; i < prices.size(); i++)
            {
                profit += max(prices[i] - prices[i - 1], 0);
            }
            return profit;
        }

        vector<int> buy(k, INT_MIN);
        vector<int> sell(k, 0);
        for(int i = 0; i < prices.size(); i++)
        {
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for(int j = 1; j < k; j++)
            {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k - 1];
    }
};

int main() {
    Solution s;

    vector<int> prices = {
        2,4,1
    };

    cout << s.maxProfit(2, prices) << endl;

    prices = {
        3,2,6,5,0,3
    };

    cout << s.maxProfit(2, prices) << endl;
}

