#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, long long int target) {
        int n = num.length();
        vector<vector<long long int>> dp(n, vector<long long int>(n));
        vector<vector<string>> exprs(n, vector<string>(n));

        for(int i = 0; i < )
    }
};

int main(){
    Solution s;
    string num = "2147483648";
    vector<string> ops = s.addOperators(num, -2147483648);
    cout << "-------------------------------------" << endl;
    for(auto op : ops)
        cout << op <<endl;

}

