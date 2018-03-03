#include <cstdio>
#include <map>
#include <climits>
using namespace std;

int main(){
    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    int tmp;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        printf("%d ", tmp);
        mp[tmp] = mp[tmp] + 1;
    }
    printf("\n\n");

    map<int,int>::iterator lower_bound = mp.begin(); 
    map<int,int>::iterator upper_bound = mp.end(); 
    upper_bound--; 


    int ret = 0;
    while(lower_bound->first != upper_bound->first){
        int ni = upper_bound -> first - lower_bound -> first;
        ret += ni;
        lower_bound -> second --;
        upper_bound -> second --;
        if(lower_bound->second == 0){
            mp.erase(lower_bound);
        }

        if(upper_bound->second == 0){
            mp.erase(upper_bound);
        }
        mp[ni] = mp[ni] + 1;
        lower_bound = mp.begin(); 
        upper_bound = mp.end(); 
        upper_bound--; 
    }
    printf("ret = %d\n", ret);
    /*
    map<int,int>::iterator iter = mp.begin();
    for(; iter != mp.end(); iter++){
        printf("%d %d\n", iter->first, iter->second);
    }

    printf("-------------------\n");
    if(lower_bound != mp.end()){
        printf("lower_bound %d %d\n", lower_bound->first, lower_bound->second);
        //mp.erase(lower_bound);
    }

    if(upper_bound != mp.end()){
        printf("upper_bound %d %d\n", upper_bound->first, upper_bound->second);
        //mp.erase(upper_bound);
    }


    while(lower_bound->first != upper_bound->first){
        if(lower_bound != mp.end()){
            printf("lower_bound %d %d\n", lower_bound->first, lower_bound->second);
            //mp.erase(lower_bound);
        }

        if(upper_bound != mp.end()){
            printf("upper_bound %d %d\n", upper_bound->first, upper_bound->second);
            //mp.erase(upper_bound);
        }

        lower_bound = mp.lower_bound(INT_MAX); 
        upper_bound = mp.upper_bound(INT_MIN); 
        break;
    }
    */
}
