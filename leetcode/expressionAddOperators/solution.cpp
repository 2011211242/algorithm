#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        int n = num.length();
        if(0 == n) return ret;
        vector<vector<vector<long long int>>> vals(n,vector<vector<long long int>>(n, vector<long long int>()));
        vector<vector<vector<string>>> exprs(n,vector<vector<string>>(n, vector<string>()));

        for(int i = 0; i < n; i++){
            vals[i][i].push_back(num[i] - '0');
            exprs[i][i].push_back(num.substr(i, 1));
        }

        for(int i = 0; i < n; i++){
            for(int s = 1; s < n - i; s++){
                for(int k = 0; k < vals[i][i + s - 1].size(); k++){
                    if(vals[i][i + s - 1][k] != 0){
                        vals[i][i + s].push_back(vals[i][i + s - 1][k] * 10 + vals[i + s][i + s][0]);
                        exprs[i][i + s].push_back(exprs[i][i + s - 1][k] + exprs[i + s][i + s][0]);
                    }
                }
            }

        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = i + 1; k <=j; k++){
                    for(int t1 = 0; t1 < vals[i][k - 1].size(); t1++){
                        for(int t2 = 0; t2 < vals[k][j].size(); t2++){
                            vals[i][j].push_back(vals[i][k - 1][t1] * vals[k][j][t2]);
                            exprs[i][j].push_back(exprs[i][k - 1][t1] + "*" + exprs[k][j][t2]);
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = i + 1; k <=j; k++){
                    for(int t1 = 0; t1 < vals[i][k - 1].size(); t1++){
                        for(int t2 = 0; t2 < vals[k][j].size(); t2++){
                            vals[i][j].push_back(vals[i][k - 1][t1] + vals[k][j][t2]);
                            exprs[i][j].push_back(exprs[i][k - 1][t1] + "+" + exprs[k][j][t2]);

                            vals[i][j].push_back(vals[i][k - 1][t1] - vals[k][j][t2]);
                            exprs[i][j].push_back(exprs[i][k - 1][t1] + "-" + exprs[k][j][t2]);
 
                        }
                    }
                }
            }
        }

        for(int i = 0; i < vals[0][n - 1].size(); i++){
            if(vals[0][n - 1][i] == target){
                ret.push_back(exprs[0][n - 1][i]);
            }
        }
        return ret;

    }
};

int main(){
    Solution s;
    vector<string> exprs = s.addOperators("", 6);
    for(auto s : exprs)
        cout << s << endl;
}
