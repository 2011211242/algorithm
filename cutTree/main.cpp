#include <cstdio>
using namespace std;
struct node {
    int val;
    struct node * next;
    node():val(0), next(NULL){}
};

void cut_tree(int m, int n, int k){
    /* @m human number
     * @n trees number
     * @k the last tree that the chairman cut
     * tree numbered began from 0 to n -1
     */
    if(m > n)
    {
        printf("no result\n");
    }
    else{
        int start_cut;
        int last_cur_tree_num;
        if(2 * m <= n){
            last_cur_tree_num = 2 * m - 1;
        }
        else{
            struct node * root = new node;
            root -> next = root;
            root -> val = 0;
            node * pre = NULL;
            for(int i = n - 1; i > 0; i--){
                node * tmp = new node;
                if(i == n - 1) pre = tmp;

                tmp -> val = i;
                tmp -> next = root -> next;
                root-> next = tmp;
            }


            for(int i = 1; i < m; i++){
                node * tmp = root;
                pre -> next = root -> next;
                tmp -> next = NULL;
                delete tmp;


                root = root -> next;

                pre = pre -> next;
                root = root -> next;
            }
            last_cur_tree_num = root -> val;

        }
        if(last_cur_tree_num <= k) start_cut = k - last_cur_tree_num;
        else start_cut = n - last_cur_tree_num + k + 1;
        printf("%d\n", start_cut);
    }
}

int main(){
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    cut_tree(m, n, k);
}
