#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m;
long long int res = 0;

typedef struct{
    int to;
    int dist;
}edge;

typedef struct{
    int val;
    bool visited;
    vector<edge> edgeList;
}Map;

void dfs(vector<Map> &cityMap, map<pair<int, int>,long long int> &dup, map<pair<int, int>,int> &dist,int index){
    cityMap[index].val = 1;
    cityMap[index].visited = true;

    for(int i = 0; i < cityMap[index].edgeList.size(); i++){
        int next = cityMap[index].edgeList[i].to;

        if(cityMap[next].visited == false){
            int d = cityMap[index].edgeList[i].dist;
            dfs(cityMap, dup, dist, next);
            cityMap[index].val += cityMap[next].val;

            pair<int, int> p;
            if(index > next) p = pair<int, int>(next, index);
            else p = pair<int, int>(index, next);
            dup[p] = (long long int)(n - cityMap[next].val) * (long long int)cityMap[next].val;
            dist[p] = d;
            res += dup[p] * d;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);

    int from, to, val;
    vector<Map> cityMap = vector<Map>(n + 1);

    map<pair<int,int>, long long int> dup;
    map<pair<int,int>, int> dist;

    edge e1, e2;
    for(int i = 1; i < n; i++){
        scanf("%d %d %d", &from, &to, &val);
        cityMap[from].visited = false;
        cityMap[to].visited = false;

        e1.to = to;
        e1.dist = val;
        cityMap[from].edgeList.push_back(e1);

        e2.to = from;
        e2.dist = val;
        cityMap[to].edgeList.push_back(e2);
    }
    dfs(cityMap, dup, dist, 1);
    char op[12];
    for(int i = 1; i <= m; i++){
        scanf("%s", op);
        if(strcmp(op, "QUERY") == 0){
            printf("%lld\n", res);
        }

        if(strcmp(op, "EDIT") == 0){
            scanf("%d %d %d", &from, &to, &val);
            if(from > to) swap(from, to);
            pair<int, int> p = pair<int, int>(from, to);
            res += dup[p] * (val - dist[p]);
            dist[p] = val;
        }
    }
}
