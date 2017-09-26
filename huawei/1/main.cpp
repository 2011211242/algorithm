#include <cstdio>
#include <vector>
using namespace std;

int main(){
    char s1[102];
    char s2[102];
    vector<int> a(52, 0);
    vector<bool> b(52, false);
    scanf("%s%s", s1, s2);
    //printf("%s\n%s\n", s1, s2);
    for(int i = 0; s1[i]; i++){
        if(s1[i] >= 'a' && s1[i] <= 'z'){
            a[s1[i] - 'a'] ++;
        }

        if(s1[i] >= 'A' && s1[i] <= 'Z'){
            a[s1[i] - 'A' + 26] ++;
        }

    }
    //printf("1111\n");

    for(int i = 0; s2[i]; i++){
        if(s2[i] >= 'a' && s2[i] <= 'z' && a[s2[i] - 'a'] > 0){
            b[s2[i] - 'a'] = true;
            s2[i] = '_';
        }
        else{
            if(s2[i] >= 'A' && s2[i] <= 'Z' && a[s2[i] - 'A' + 26] > 0){
                b[s2[i] - 'A' + 26] = true;
                s2[i] = '_';
            }
        }
    }

    //printf("2222\n");
    for(int i = 0; s1[i]; i++){
        if(s1[i] >= 'a' && s1[i] <= 'z' && b[s1[i] - 'a']){
            s1[i] = '_';
        }
        else {
            if(s1[i] >= 'A' && s1[i] <= 'Z' && b[s1[i] - 'A' + 26]){
                s1[i] = '_';
            }
        }
    }
    printf("%s\n%s\n", s1, s2);

}
