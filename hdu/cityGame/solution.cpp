#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int getMaxArea(const vector<int> &height)
{
    vector<int> arise(1, 0);
    int max_area = 0;
    for(int i = 1; i < height.size(); i++)
    {
        int back = arise.back();
        while(height[back] > height[i])      
        {
            int h = height[back];
            arise.pop_back();
            back = arise.back();
            max_area = max(max_area, h * (i - back - 1));
        }
        arise.push_back(i);
    }
    return max_area;
}

int main()
{
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        int m, n;
        scanf("%d %d", &n, &m);

        vector<int> height(m + 2, 0);
        int max_area = 0;

        for(int j = 0; j < n; j++)
        {
            char ch;
            for(int k = 0; k < m; k++)
            {
                scanf("%s", &ch);
                if(ch == 'R')
                {
                    height[k + 1] = 0;
                }
                else
                {
                    height[k + 1] ++;
                }
            }

            max_area = max(max_area, getMaxArea(height));
        }
        printf("%d\n\n", 3 * max_area);
    }
}
