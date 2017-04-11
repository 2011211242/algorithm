#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long int solve(vector<int> &l1, vector<int> &l2)
{
    long long int seconds = 0;
    long long int sum = 0;
    for(int i = 0; i < l1.size(); i++)
    {
        sum += (l1[i] + l2[i]);
    }

    long long int average = sum / (l1.size() * 2);

    int i = 0;
    for(; i < l1.size() - 1; i++)
    {
        if(l1[i] < average)         
        {
            if(l2[i] < average)
            {
                seconds += (average << 1) - (l1[i] + l2[i]);
                l1[i + 1] += (l1[i] - average);
                l2[i + 1] += (l2[i] - average);
            }
            else
            {
                if(l2[i] - average >= average - l1[i])
                {
                    seconds += (l2[i] - average);
                    l2[i + 1] += (l1[i] + l2[i]) - (average << 1);
                }
                else
                {
                    seconds += (average - l1[i]);
                    l1[i + 1] += (l1[i] + l2[i]) - (average << 1);
                }
            }
        }
        else
        {
            if(l2[i] < average) /*l1 >= average && l2 < average*/
            {
                if(l1[i] - average >= average - l2[i])
                {
                    seconds += (l1[i] - average);
                    l1[i + 1] += (l1[i] + l2[i]) - (average << 1);
                }
                else
                {
                    seconds += (average - l2[i]);
                    l2[i + 1] += (l1[i] + l2[i]) - (average << 1);
                }
            }
            else
            {
                seconds += (l1[i] + l2[i]) - (average << 1);
                l1[i + 1] += (l1[i] - average);
                l2[i + 1] += (l2[i] - average);
            }
        }
    }
    seconds += (max(l1[i], l2[i]) - average);
    return seconds;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        vector<int> l1(n);
        vector<int> l2(n);

        for(int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            l1[i] = num;
        }

        for(int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            l2[i] = num;
        }

        printf("%lld\n", solve(l1, l2));
    }
}
