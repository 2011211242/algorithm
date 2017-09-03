#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int sum = 0, m = 0;
        for(int i = 0; i < n; i++){
            int num;
            scanf("%d", &num);
            m = max(m, num);
            sum += num;
        }
        if(sum - m >= m) printf("Yes\n");
        else printf("No\n");
    }
}
