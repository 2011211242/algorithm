#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int longest_sub_seri(string &str1, string &str2){
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));
    for(int i = 0; i < str1.length(); i++){
        for(int j = 0; j < str2.length(); j++){
            if(str1[i] == str2[j]){
                dp[i + 1][j + 1] = max(dp[i][j] + 1, max(dp[i][j + 1], dp[i + 1][j]));
            }
            else{
                dp[i + 1][j + 1] = max(dp[i][j], dp[i][j]);
            }
        }
    }
    return dp[str1.length()][str2.length()];
}

int main(){
    char s[52];
    while(scanf("%s", s) != EOF){
        string str = s;
        int res = 0;
        
        for(int i = 1; i < str.length(); i++){
            string s1 = str.substr(0, i);
            string s2 = str.substr(i);

            if(s2.length() <= res) break;
            res = max(res, longest_sub_seri(s1, s2));
        }
        
        printf("%d\n", 2 * res);
    }
}
