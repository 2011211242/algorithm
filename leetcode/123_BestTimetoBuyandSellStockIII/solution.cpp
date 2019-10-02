/**
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Version: 1.0: solution.cpp 2019年09月23日 
 *
 * Authors:
 *   andrewyan <andrewyan@tencent.com>
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int sum = 0;
        int low = prices[0];
        vector<int> dp(prices.size(), 0);

        for(int i = 1; i < prices.size(); i++)
        {
            int profit = prices[i] - low;
            if (profit > sum) sum = profit;
            else if (prices[i] < low) low = prices[i];

            dp[i] = sum;
        }

        int ret = dp[dp.size() - 1];
        sum = 0;
        int high = prices[prices.size() - 1]; 

        for (int i = prices.size() - 2; i >= 2; i--)
        {
            int profit = high - prices[i];
            if (profit > sum) sum = profit;
            else if (prices[i] > high) high = prices[i];
            ret = max(ret, sum + dp[i - 1]);
        }
        return ret;
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, buy2 = INT_MIN, sell1 = 0, sell2 = 0;
        for (int i : prices)
        {
            buy1 = max(buy1, - i);
            sell1 = max(sell1, buy1 + i);
            buy2 = max(buy2, sell1 - i);
            sell2 = max(sell2, buy2 + i);
        }
        return sell2;
    }
};

int main() {
    Solution s;

    vector<int> prices = {
        1,2,3,4,5
    };

    cout << s.maxProfit(prices) << endl;
}
