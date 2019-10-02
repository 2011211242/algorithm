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
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;

        if (((num & (num - 1)) == 0) && (0x55555555 & num))
        {
            return true;
        }

        return false;
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfFour(16) << endl; 

}
