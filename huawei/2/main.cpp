#include <cstdio>
#include <cstring>
using namespace std;

bool is_digit(char str[], int i){
    //printf("%d, %c\n", i, str[i]);
    return str[i] >= '0' && str[i] <= '9';
}

bool is_char(char str[], int i){
    //printf("%d, %c\n", i, str[i]);
    return str[i] == '-';
}

int main(){
    char str[100];

    scanf("%s", str);
    bool valid = true;
    int len = strlen(str);
    if(len != 11)
    {
        valid = false;
    }
    else{
        if(is_char(str, 1) && 
                is_char(str, 5) &&
                is_digit(str, 0) &&
                is_digit(str, 2) &&
                is_digit(str, 3) &&
                is_digit(str, 4) &&
                is_digit(str, 6) &&
                is_digit(str, 7) &&
                is_digit(str, 8) &&
                is_digit(str, 9) &&
                is_digit(str, 10) 
          ){
            int p = ((str[0] - '0') * 1 +
                    (str[2] - '0') * 2 +
                    (str[3] - '0') * 3 +
                    (str[4] - '0') * 4 +
                    (str[6] - '0') * 5 +
                    (str[7] - '0') * 6 +
                    (str[8] - '0') * 7 +
                    (str[9] - '0') * 8 +
                    (str[10] - '0') * 9) % 11; 

            str[11] = '-';
            str[13] = '\0';

            if(p  >= 10){
                str[12] = 'X';
            }
            else{
                str[12] = p + '0';
            }
        }
        else{
            valid = false;
        }
    }
    if(valid) printf("%s\n", str);
    else printf("ERROR\n");
}
