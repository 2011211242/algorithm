#include <cstdio>
#include <vector>
#include <cstdlib>
#include <climits>
#include <algorithm>
using namespace std;

struct node{
    int p;
    int q;
    int pt;
    int qt;
    vector<int> children;
    bool visited;
    node(){visited = false;}
} tree[10001];

bool cmp(int a, int b){
    return tree[a].qt > tree[b].qt;
}

void dfs(int rt){
    if(tree[rt].visited) return;
    tree[rt].visited = true;
    for(int j = 0; j < tree[rt].children.size(); j++){
        dfs(tree[rt].children[j]);
    }
    sort(tree[rt].children.begin(), tree[rt].children.end(), cmp);

    int cost = tree[rt].p - tree[rt].q;
    int maxCost = tree[rt].p;

    for(int i = 0; i < tree[rt].children.size(); i++){
        cost += tree[tree[rt].children[i]].pt;
        if(cost > maxCost) maxCost = cost;
        cost -= tree[tree[rt].children[i]].qt;
    }
    tree[rt].pt = maxCost;
    tree[rt].qt = maxCost - cost;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &tree[i].p, &tree[i].q);
    }
    int index, val;
    for(int i = 1; i < n; i++){
        scanf("%d %d", &index, &val);
        tree[index].children.push_back(val);
        tree[val].children.push_back(index);
    }
    dfs(1);
    printf("%d\n", tree[1].pt);
}
