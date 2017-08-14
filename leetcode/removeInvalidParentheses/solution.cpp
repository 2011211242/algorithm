#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s){
        stack<char> stk;
        for(char ch : s){
            if(!(ch == '(' || ch == ')')) continue;
            if(ch == '('){
                stk.push(ch);
            }
            else{
                if(stk.empty()) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }

    void dfs(string s, vector<string> &parent, 
            set<string> &st, unsigned long int &len){
        if(s.length() < len || st.find(s) != st.end()) return;

        st.insert(s);
        if(isValid(s)){
            parent.push_back(s);
            len = max(len, s.length());
        }
        else{
            for(unsigned long int i = 0; i < s.length(); i++){
                if(!(s[i] == '(' || s[i] == ')')) continue;

                string pre = s.substr(0,i);
                string end = s.substr(i + 1);
                dfs(pre + end, parent, st, len);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        string parent_str = "";
        set<string> st;
        vector<string> parents;
        unsigned long len = 0;
        dfs(s, parents, st, len);
        vector<string> ret;
        for(string str : parents)
            if(str.length() == len) ret.push_back(str);
        return ret;
    }
};

int main()
{
    Solution s;
    string str = "()(((((((()";
    vector<string> ret = s.removeInvalidParentheses(str);

    for(string str : ret){
        printf("%s\n", str.c_str());
    }
}
