#include <cstdio>
using namespace std;

long long int solve(long long int n, long long int q)
{
    long long int depth = 0;
    long long int robots = 1;
    while(robots * q * 2 < n)
    {
        depth ++;
        robots <<= 1;
    }

    return q * depth + (n +  robots - 1) / robots;
}

int main()
{
    long long int n, q;

    while(scanf("%lld %lld", &n, &q) != EOF)
    {
        printf("%lld\n", solve(n, q));    
    }
}

