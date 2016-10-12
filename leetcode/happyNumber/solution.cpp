#include <cstdio>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> si;
        while(n != 1){
            if(si.find(n) != si.end()) return false;
            si.insert(n);
            int tmp = 0;
            while(n != 0){
                tmp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = tmp;
        }
        return true;
    }
};

int main(){
    Solution s;
    printf("%d\n", s.isHappy(19));
}
