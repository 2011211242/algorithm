#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int get_res(string str, int k){
    int n = str.length(), max_l = 0;
    int s = 0, e = 0, z = 0;

    while(e < n && z < k){
        z += str[e] == '0';
        e ++;
    }

    max_l = e;
    while(e < n){
        while(e < n && str[e] == '1'){e++;}
        max_l = max(max_l, e - s);
        while(s < n && str[s] == '1'){s++;}
        s++, e++;
    }

    return max_l;
}

int main()
{
    string str= "11101110010011001101";
    int k = 4;
    int res = get_res(str, k);
    printf("%d\n", res);
}
