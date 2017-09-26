#include <cstdio>
using namespace std;

int num[32];

int get_res(int n, int m, int power){
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(n > m) return 0;

    int ret = 0;
    for(int i = 0; i <= 2; i++){
        ret += get_res(n - power * i, m - power * 2, power >> 1);
    }
    return ret;
}

int main(){
    int n;
    for(int i = 0; i < 32; i++){
        num[i] = 2;
    }

    while(scanf("%d", &n) != EOF){
        int cnt = 0;
        int tmp = n;

        while(tmp){
            cnt ++;
            tmp >>= 1;
        } 

        int m = (1 << cnt + 1) - 2;
        int ret = get_res(n, m, 1 << (cnt - 1));
        printf("%d\n", ret);
    }
}

