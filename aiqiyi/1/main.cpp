#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    char str[60];
    while(scanf("%s", str) != EOF){
        stack<char> stk;
        int depth = 0;
        int d = 0;
        for(int i = 0; str[i]; i++){
            if(str[i] == '('){
                stk.push('(');
                d ++;
                depth = max(depth, d);
            }
            else{
                stk.pop();
                d --;
            }
        }
        printf("%d\n", depth);
    }
}
