#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int get_res(string str, int k){
    int n = str.length();
    vector<int> dp(n);
    dp[0] = str[i] == '0';
    printf("");
    for(int i = 1; i < n; i++)
    {
        if(dp[i])
    }
    return max_l;
}

int main()
{
    string str= "1110010011001101";
    int k = 4;
    int res = get_res(str, k);
    printf("%d\n", res);
}
