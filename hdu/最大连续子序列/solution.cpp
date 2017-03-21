#include <cstdio>
using namespace std;
#define MAX 10001

int main()
{
	int k;
	int num[MAX];
	scanf("%d", &k);

	while(k != 0)
	{
		for(int i = 0; i < k; i++)
		{
			scanf("%d", &num[i]);
		}

		int s = 0;
		int sum = 0;
		int max_sum = -1;
		int max_s = 0, max_e = k - 1;

		for(int i = 0; i < k; i++)
		{
			sum += num[i];
			if(sum > max_sum)
			{
				max_sum = sum;
				max_s = s;
				max_e = i;
			}

			if(sum < 0)
			{
				s = i + 1;
				sum = 0;
			}
		}

		if(max_sum < 0) max_sum = 0;

		printf("%d %d %d\n", max_sum, num[max_s], num[max_e]);
		scanf("%d", &k);
	}
}
