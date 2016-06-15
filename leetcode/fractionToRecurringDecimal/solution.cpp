#include <cstdio>
#include <map>
#include <string>
using namespace std;

class Solution{
public:
    string fractionToDecimal(int numerator, int denominator){
        long long int n = numerator;
        long long int d = denominator;
        int sign = 1;
        if((n < 0) ^ (d < 0)) sign = -1;
        if(n < 0) n = -n;
        if(d < 0) d = -d;

        string ret = to_string(n / d);
        if(n % d == 0) {
            if(sign == -1 && n / d != 0) ret = "-" + ret;
            return ret;
        }
        else ret += decimal(n % d, d);
        if(sign == -1) ret = "-" + ret;
        return ret;
    }
    string decimal(long long int n, long long int d){
        string ret = ".";
        map<long long int, int> m;
        while(n){
            n *= 10;
            if(m[n] == 0){
                ret += to_string(n/d);
                m[n] = ret.size() - 1;
            }
            else{
                int pos = m[n];
                ret = ret.substr(0, pos) + "(" + ret.substr(pos) + ")";
                return ret;
            }
            n %= d;
        }
        return ret;
    }
};

int main(){
    int n = 10, d = -3;
    Solution s;
    string res = s.fractionToDecimal(n, d);
    printf("%s\n", res.c_str());
    return 0;
}
