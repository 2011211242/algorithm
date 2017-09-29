#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
struct node{
    unsigned long long int val;
    int idx;
    int n;
};

struct cmp{
    bool operator()(node a, node b){
        return a.val > b.val;
    }
};

unsigned long long int get_res(vector<unsigned long long int> &pp, unsigned long long  int n)
{
    unsigned long long int ret = 0;
    unsigned long long int pow = 1;

    for(int i = 0; i <= 7; i++){
        ret += pow * pp[i];
        pow *= n;
    }
    return ret;
}

int main(){
    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<vector<unsigned long long int>> p(n, vector<unsigned long long int>(8));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 7; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            p[i][7 - j] = tmp;
        }
    }

    int k;
    scanf("%d", &k);

    priority_queue<node, vector<node>, cmp> que; 
    for(int i = 0; i < n; i++){
        node tmp;
        tmp.val = get_res(p[i], 1);
        //printf("tmp.val = %d\n", tmp.val);
        tmp.idx = i;
        tmp.n = 1;
        que.push(tmp);
    }
    
    for(int i = 0; i < k - 1; i++){
        node top_node = que.top();
        que.pop();
        top_node.n ++;
        top_node.val = get_res(p[top_node.idx], top_node.n);
        que.push(top_node);
    }

    node top_node = que.top();
    unsigned long long int ret = top_node.val;
    printf("%llu\n", ret);
    //vector<int>
}
