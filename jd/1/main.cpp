#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

int main(){
    unsigned long long int n;
    while(scanf("%llu", &n) != EOF)
    {
        unsigned long long int r = 1;
        unsigned long long int l;

        while(r * r < 2 * n){
            r <<= 1;
        }
        l = r >> 1;

        unsigned long long int mid;
        while(l < r - 1){
            mid = (l + r) / 2;
            if(mid * mid >= 2 * n - mid){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        printf("%llu\n", l);
    }
}
