#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isJudge(string &s)
{
    if(s.empty()) return false;
    for(int i = 0; i < s.length() / 2; i++){
        if(s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}

int main(){
    int n;
    char str[500][301];

    while(scanf("%d", &n) != EOF){
        //cin.getline(str[0], 301);
        int count = 0;
        for(int i = 0; i < n; i++){
            scanf("%s", str[i]);
            //cin.getline(str[i], 301);
            //printf("%s\n", str[i]);
            for(int j = 0; j < i; j++){
                string s;
                s = string(str[i]) + string(str[j]);
                if(isJudge(s)) count++;
                s = string(str[j]) + string(str[i]);
                if(isJudge(s)) count++;
            }
        }
        printf("%d\n", count);
    }
}
