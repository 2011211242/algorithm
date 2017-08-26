#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        vector<int32_t> wordsBitMap(words.size(), 0);
        for(int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            for(auto ch : word)
            {
                wordsBitMap[i] |= (1 << (ch - 'a'));
            }
        }

        int32_t res = 0;
        for(int i = 0; i < wordsBitMap.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if((wordsBitMap[i] & wordsBitMap[j]) == 0)
                {
                    res = max(res, (int32_t)words[i].length() * (int32_t)words[j].length());
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> words = {"a", "b"};
    printf("%d\n", s.maxProduct(words));
}
