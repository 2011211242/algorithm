#include <cstdio>
#include <climits>

using namespace std;
long long int edge[60][100][100];

void getEdge(int power, int n, long long int edge_z[][100], long long int edge_x[][100], long long int edge_y[][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            edge_z[i][j] = LLONG_MAX;
        }
    }

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            for(int j = 0; j < n; j++){
                if(power != 1 || (i != k && k != j)){
                    edge_z[i][j] = edge_z[i][j] < edge_x[i][k] +\
                                   edge_x[k][j] ? edge_z[i][j] :\
                                   edge_x[i][k] + edge_y[k][j];
                }
            }
        }
    }
}

bool check(long long int *dist, int n, int m){
    for(int i = 0 ; i < n; i++){
        if(dist[i] <= m) return true;
    }
    return false;
}

int getRes(long long int n, long long int m){
    int power = 1;
    int num = 2;
    while(num <= m){
        getEdge(power, n, edge[power], edge[power - 1], edge[power - 1]);
        power++;
        num <<= 1;
    }
    long long int dist[100] = {0}, newDist[100];
    long long int ans = 0;

    for(int i = power - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            newDist[j] = LLONG_MAX;
        }

        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if((j != k || i > 0) && newDist[j] > dist[k] + edge[i][k][j]){
                    newDist[j] = dist[k] + edge[i][k][j];
                }
            }
        }

        if(check(newDist, n, m)){
            for(int j = 0; j < n; j++){
                dist[j] = newDist[j];
            }
            ans = ans + (1 << i);
        }
    }
    return ans;
}

int main(){
    long long int n, m;
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lld", &edge[0][i][j]);
        }
    }

    long long int res = getRes(n, m);
    printf("%lld\n", res);
}
