#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

vector<string> split(string& str){
    int s = 0;
    vector<string> ret; 
    while(s < str.length()){
        int next = str.find(' ', s);
        if(next == string::npos) break;
        ret.push_back(str.substr(s, next - s));
        s = next + 1;
    }
    ret.push_back(str.substr(s));
    return ret;
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    char token[50];
    set<string> st;

    for(int i = 0; i < n; i++){
        scanf("%s", token);
        string tk = token;
        st.insert(tk);
    }

    char str[10000];
    cin.getline(str, 10000);

    bool flag = false;
    for(int i = 0; i < m; i++){
        string url;
        string content;
        cin.getline(str, 10000);
        url = str;
        cin.getline(str, 10000);
        content = str;

        vector<string> ret = split(content);
        sort(ret.begin(), ret.end());
        int count = 0;
        int j = 0;

        if(st.find(ret[j]) != st.end()){
            count++;
        }

        j++;
        while(j  < ret.size() && count < k)
        {
            while(j < ret.size() && ret[j] == ret[j - 1]) j++;
            if(j >= ret.size()) break;

            if(st.find(ret[j]) != st.end()){
                count++;
            }

            j++;
        }
        /*
        for(int j = 0; j < ret.size() && count < k; j++){
            if(st.find(ret[j]) != st.end()){
                count ++;
            }
        }
        */

        if(count == k){
            cout << url << endl;
            flag = true;
        }
    }

    if(!flag) cout << endl;

}
