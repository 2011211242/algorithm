#include <cstdio>
#include <vector>
using namespace std;

long long int get_res(long long int n, vector<int> &vec, int i){
    if(n == 0) return 1;
    long long int m = 1 << i;
    long long int ret = 0;
    if(n & m){
        if(i > 0 && vec[i - 1] == 2){
            vec[i - 1] = 0;
            ret += get_res(n - m, vec, i + 1);
            vec[i - 1] = 2;
        }
        if(vec[i] >= 1){
            vec[i] -= 1;
            ret += get_res(n - m, vec, i + 1);
            vec[i] += 1;
        }
    }
    else{
        ret += get_res(n, vec, i + 1);
    }
    return ret;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        vector<int> vec(64, 2);
        int ret = get_res(n, vec, 0);
        printf("%d\n", ret);
    }
}
