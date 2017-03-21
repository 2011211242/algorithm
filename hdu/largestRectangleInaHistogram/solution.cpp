#include <cstdio>
#include <stack>
#define MAX 100001
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	while(n)
	{
		int num[MAX] = { 0 };
		stack<int> stk;
		stk.push(0);

		unsigned long long int max_area = 0;
		for(int i = 1; i <= n; i ++)
		{
			scanf("%d", &num[i]);

			int top = stk.top();
			while(num[i] < num[top])
			{
				int height = num[top];

				stk.pop();
				top = stk.top();

				unsigned long long int area = (unsigned long long int)height * (i - top - 1);
				if(area > max_area) max_area = area;
			}
			stk.push(i);
		}

		int top = stk.top();
		while(0 < num[top])
		{
			int height = num[top];

			stk.pop();
			top = stk.top();

			unsigned long long int area = (unsigned long long int)height * (n - top);
			if(area > max_area) max_area = area;
		}

		printf("%llu\n", max_area);
		scanf("%d", &n);
	}
}


