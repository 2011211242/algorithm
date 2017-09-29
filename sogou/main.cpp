#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n;
    freopen("test.txt", "r", stdin);
    scanf("%d", &n);

    vector<double> num(2 * n);
    for(int i = 0; i < n; i++){
        double tmp;
        scanf("%lf", &tmp);
        num[i] = tmp;
        num[i + n] = tmp + 360.0;
    }
    
    int s = 1, e = 1;
    int ret = 0;
    for(int i = 0; i < n; i++){
        while(s < i + n && num[s] - num[i] < 180){
            s++;
        }

        if(s - i > 1){
            ret += (s - i - 2) * (s - i - 1) / 2;
        }
    }
    
    //printf("\n");
    printf("%d\n", ret);
}
