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
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int low = prices[0];
        int high = prices[0];

        int sum = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > high)
            {
                high = prices[i];
            }
            else if (prices[i] < high)
            {
                if (high > low)
                {
                    sum += (high - low);
                }

                high = low = prices[i];
            }
        }

        if (high > low)
        {
            sum += (high - low);
        }

        return sum;
    }
};

int main() {
    Solution s;

    vector<int> prices = {
        7,1,5,3,6,4
    };

    cout << s.maxProfit(prices) << endl;
}


