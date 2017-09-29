#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n != 0){
        stack<int> sta;
        sta.push(0);
        int num_in = 1;
        bool flag = true;
        for(int i = 0; i < n; i++){
            int cur;
            scanf("%d", &cur);
            if(flag){
                while(sta.top() < cur){
                    sta.push(num_in);
                    num_in ++;
                }
                if(sta.top() > cur){
                    flag = false;
                }
                else if(sta.top() == cur){
                    sta.pop();
                }
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
        scanf("%d", &n);
    }
}

