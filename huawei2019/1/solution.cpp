#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int max_gift(const vector<vector<int>>& mp)
{
	if (mp.size() <= 0 || mp[0].size() <= 0) return 0;

	vector<int> dp(mp[0].size());
	dp[0] = mp[0][0];
	for (int i = 1; i < mp[0].size(); i++)
	{
		dp[i] = mp[0][i] + dp[i - 1];
	}

	for (int i = 1; i < mp.size(); i++)
	{
		dp[0] = dp[0] + mp[i][0];
		for (int j = 1; j < mp[i].size(); j++)
		{
			dp[j] = mp[i][j] + max(dp[j], dp[j - 1]);
		}
	}

	return dp[dp.size() - 1];
}

int main()
{
	vector<vector<int>> num = {
		{1, 2, 3},
		{2, 8, 4}
	};
	cout << max_gift(num) << endl;
}


