#include <cstdio>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> numSta;
        stack<char> opSta;
        opSta.push('(');
        s.push_back(')');
        int num = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + s[i] - '0';
                continue;
            }

            if(s[i] == '('){
                opSta.push('(');
                continue;
            }

            if(s[i] == ')'){
                if(opSta.top() == '('){
                    opSta.pop();
                    continue;
                }

                char opTop = opSta.top();
                int numTop = numSta.top();

                opSta.pop();
                opSta.pop();
                numSta.pop();

                if(opTop == '-'){
                    num = numTop - num;
                }
                if(opTop == '+'){
                    num = numTop + num;
                }
                continue;
            }

            if(s[i] == '+' || s[i] == '-'){
                if(opSta.top() == '+' || opSta.top() == '-'){
                    int numTop = numSta.top();
                    char opTop = opSta.top();
                    numSta.pop();
                    opSta.pop();

                    if(opTop == '-'){
                        num = numTop - num;
                    }
                    if(opTop == '+'){
                        num = numTop + num;
                    }
                }
                numSta.push(num);
                num = 0;
                opSta.push(s[i]);
            }
        }
        return num;
    }
};

int main(){
    string s = "1 - (5)";
    Solution sol;
    printf("%d\n", sol.calculate(s));
}
