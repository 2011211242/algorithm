#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int pow(int n, int k)
    {
        int ret = 0;
        while(n % k == 0)
        {
            n /= k;
            ret++;
        }
        return ret;
    }

    int bulbSwitch(int n) {
        if(n <= 0) return 0;
        vector<bool> state(n + 1, true);
        vector<bool> sp(n + 1, true);
        int res = 1;

        for(int i = 2; i < state.size(); i++)
        {
            if(sp[i])
            {
                int tmp = i;
                while(tmp <=n)
                {
                    if(state[tmp] == true)
                    {
                        if(pow(tmp, i) & 0x01)
                        {
                            state[tmp] = false;
                        }
                    }
                    sp[tmp] = false;
                    tmp += i;
                }
            }

            if(state[i])
            {
                res += 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    printf("%d\n", sol.bulbSwitch(8));
}

