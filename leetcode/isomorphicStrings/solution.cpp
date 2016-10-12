#include <cstdio>
#include <string>
using namespace std;

class Solution {
private:
    string change(string s){
        string ret = string("");
        char ch = 'a';
        for(int i = 0; i < s.length(); i++){
            int pos = s.substr(0, i).find(s[i]);
            if(pos != string::npos)
            {
                ret.push_back(ret[pos]);
            }
            else{
                ret.push_back(ch);
            }
            ch += 1;
        }
        return ret;
    }
public:
    bool isIsomorphic(string s, string t) {
        return change(s) == change(t);
    }
};

int main(){
    Solution s;
    printf("%d\n", s.isIsomorphic(string("egg"), string("add")));
}
