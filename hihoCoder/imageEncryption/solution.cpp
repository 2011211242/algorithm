#include <cstdio>
#include <vector>
using namespace std;

int a[100][100], b[100][100], rotate[100][100], Min[100][100];

void input(int a[][100], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void matrixCp(int a[][100], int b[][100], int x, int y, int n){
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            a[i][j] = b[i][j];
        }
    }
}

void matrixRotate(int a[][100], int x, int y, int n){
    for(int i1 = x, j2 = y + n - 1; i1 < x + n, j2 >= y; i1++, j2--){
        for(int j1 = y, i2 = x; j1 < y + n, i2 < x + n; j1++, i2++){
            rotate[i2][j2] = a[i1][j1];
        }
    }
    matrixCp(a, rotate, x, y, n);
}

bool matrixCmp(int a[][100], int b[][100], int x, int y, int n){
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(a[i][j] < b[i][j]) return true;
            if(a[i][j] > b[i][j]) return false;
        }
    }
    return false;
}

void dfs(int a[][100], int x, int y, int n){
    if(n % 2){
        matrixCp(Min, a, x, y, n);
        for(int i = 0; i < 3; i++){
            matrixRotate(a, x, y, n);
            if(matrixCmp(a, Min, x, y, n)){
                matrixCp(Min, a, x, y, n);
            }
        }
        matrixCp(a, Min, x, y, n);
    }
    else{
        int n2 = n / 2;
        dfs(a, x, y, n2);
        dfs(a, x + n2, y, n2);
        dfs(a, x, y + n2, n2);
        dfs(a, x + n2, y + n2, n2);

        matrixCp(Min, a, x, y, n);
        for(int i = 0; i < 3; i++){
            matrixRotate(a, x, y, n);
            if(matrixCmp(a, Min, x, y, n)){
                matrixCp(Min, a, x, y, n);
            }
        }
        matrixCp(a, Min, x, y, n);

    }
}

bool isSame(int a[][100], int b[][100], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

int main(){
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        input(a, n);
        input(b, n);
        dfs(a, 0, 0, n);
        dfs(b, 0, 0, n);
        if(isSame(a, b, n)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}
