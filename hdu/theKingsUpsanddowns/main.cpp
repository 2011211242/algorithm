#include <cstdio>
using namespace std;
#define MAX_N 22

unsigned long long int f_n[MAX_N] = {0};
unsigned long long int p_n[MAX_N] = {0};

unsigned long long int p(int n){
    if(p_n[n]) return p_n[n];
    if(n <= 1) return 1;
    return p(n - 1) * n;
}

unsigned long long int c(int n, int k){
    return p(n) / (p(k) * p(n - k));
}



unsigned long long int f(int n){
    if(f_n[n]) return f_n[n];
    if(n <= 1) f_n[n] = 1;
    else{
        f_n[n] = f(n - 1) + c(n - 1, 1) * f(n - 2);
        for(int i = 2; i < n - 2; i++){
            f_n[n] += c(n - 1, i) * f(i) *  f(n - i - 1) / 4;
        }
    }
    return f_n[n];
}

int main(){
    int t;
    scanf("%d", &t);
    int d,n;
    f(20);
    f_n[1] = 1;
    for(int i = 0; i < t; i++){
        scanf("%d %d", &d, &n);
        printf("%d %llu\n", d, f(n));
    }
}
