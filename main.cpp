#include <cstdio>
#include <climits>
using namespace std;

#define num 1000000000

int a = INT_MAX - 10;
int b = INT_MAX - 100394;

int main(){
    long long int x = a * b;
    long long int y = ((long long int)a) * b;
    printf("%lld %lld\n", x, y);
    printf("%d %lld", a * b, a * b);
}

