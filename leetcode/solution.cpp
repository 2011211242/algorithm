/**
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Version: 1.0: solution.cpp 2019年10月02日 
 *
 * Authors:
 *   andrewyan <andrewyan@tencent.com>
 */

#include <iostream>
#include <climits>
using namespace std;


class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        return 1162261467 % n == 0;
    }
};

int main() {
    Solution s;
    s.isPowerOfThree(30); 

}

