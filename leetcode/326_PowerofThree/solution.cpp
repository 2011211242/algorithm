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
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        int digit = n & 0xf;
        return ( digit == 9 || digit == 3 || digit == 1 || digit == 7)
    }
};

