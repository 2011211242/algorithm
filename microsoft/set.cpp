#include <cstdio>
#include <climits>
#include <set>
using namespace std;

struct node{
    int val;
    int count;
    node(int v, int c):val(v), count(c){}
};

bool operator < (const node &a, const node & b){
    if(a.val == b.val) return a.count < b.count;
    return a.val < b.val;
}

int main(){
    set<node> st;
    st.insert(node(0, 1));
    //st.insert(node(4, 0));
    st.insert({7, 0});


    for(set<node>::iterator it = st.begin(); it != st.end(); it++){
        printf("%d %d\n", it->val, it->count);
    }
    printf("\n");

    /*
    printf("%d\n", *st.lower_bound(INT_MIN));

    if(st.upper_bound(7) != st.end())
        printf("%d\n", *st.upper_bound(7));
    set<int>::iterator s = st.find(0);
    set<int>::iterator e = st.find(9);
    st.erase(*s);
    st.erase(*e);
    */
}
