#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        vector<int> dp(n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int tmp;
            scanf("%d", &tmp);
            dp[i] = dp[i - 1] ^ tmp;
        }

        int c = 0;
        set<int> st;
        st.insert(0);
        for(int i = 1; i <=n; i++){
            int num = dp[i];
            if(st.find(dp[i]) != st.end()){
                c++;
                st.clear();
            }
            st.insert(num);
        }
        printf("%d\n", c);
    }
}
