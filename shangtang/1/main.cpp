#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int get_res(string s)
{
    //printf("%s\n", s.c_str());
    int ret = 0;
    if(s.empty()){
        //printf("empty\n");
        return 1;
    }

    if(s.length() == 1){
        if(s[0] == '0') return 0;
        else{
            return 1;
        }
    }
    else{
        if(s[0] >= '1' && s[0] <= '9'){
            ret += get_res(s.substr(1));

        }
        if(s.length() >= 2 && ((s[1] >= '0' && s[1] <= '6' && s[0] == '2') || 
                    (s[0] == '1'))){
            ret += get_res(s.substr(2));
        }
    }
    return ret;
}

int main(){
    char str[100000];
    while(scanf("%s", str) != EOF ){
        string s = str;
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '1') dp[i + 1] += dp[i];
            if(i >= 1 && (s[i - 1] == '1') || (s[i - 1] == '2' && s[i] <= '6')){
                dp[i + 1] += dp[i - 1];
            }
        }
        printf("%d\n", dp[s.length()]);
    }
}
