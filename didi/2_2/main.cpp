#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        priority_queue<int> que;
        set<int> st;

        int count = 0;
        int res = -1;
        que.push(-1);
        while(count < n){
            int cur = que.top();
            count ++;
            if(count == n){
                res = cur;
                break;
            }
            que.pop();
            st.erase(cur);
            int next = cur * 2;
            if(st.find(next) == st.end()){ 
                st.insert(next); 
                que.push(next);
            }

            next = cur * 3;
            if(st.find(next) == st.end()){
                st.insert(next);
                que.push(next);
            }

            next = cur * 5;
            if(st.find(next) == st.end()){
                st.insert(next);
                que.push(next);
            }
        }
        printf("%d\n", -res);
    }

}
