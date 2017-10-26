#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int len(int n){
    if(n == 0) return 1;
    int c = 0;
    while(n) {
        c++;
        n /= 10;
    }
    return c;
}

int a = 0;
int max_res =  1;
int max_abs = 0;
int ret = 0;

void get_res(vector<int> &input_list, int i, int n, int val){
    if(i == n){
        if(min(abs(a - val), max_res - abs(a - val)) > max_abs){
            max_abs = min(abs(a - val), max_res - abs(a - val)); 
            ret = val;
        }
        else{
            if(min(abs(a - val), abs(max_res - (a - val))) == max_abs && val < ret){
                ret = val;
            }
        }
    }
    else{
        for(int j = i; j < 10; j++)
        {
            swap(input_list[i], input_list[j]);
            int next = val * 10 + input_list[i];
            get_res(input_list, i + 1, n, next);
            swap(input_list[i], input_list[j]);
        }
    }
}

int main(){
    scanf("%d", &a);

    int n = len(a);
    vector<int> input_list(10);

    for(int i = 0; i <= 9; i++){
        input_list[i] = i;
    }

    for(int i = 0; i < n; i++){
        max_res = max_res * 10;
    }

    int val = 0;
    get_res(input_list, 0, n, val);

    cout<<ret<<endl;
}

