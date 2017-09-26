#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string get_string(const string &s){
    vector<string> v;

    int pre = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '.'){
            v.push_back(s.substr(pre, i - pre));
            pre = i + 1;
        }
    }
    v.push_back(s.substr(pre));

    string ret;
    for(int i = v.size() - 1; i >= 0; i--){
        ret = ret + v[i];
    }
    return ret;
}

bool cmp(const string & s1, const string & s2){
    return get_string(s1) < get_string(s2);
}


int main(){
    char s[300];
    scanf("%s", s);;

    string str = s;
    vector<string> nameSpace;
    int pre = 0;
    for(int i = 0; i < str.length(); i++){
        if(s[i] == '|'){
            nameSpace.push_back(str.substr(pre, i - pre));
            pre = i + 1;
        }
    }
    nameSpace.push_back(str.substr(pre));
    sort(nameSpace.begin(), nameSpace.end(), cmp);

    string ret;
    ret = nameSpace[0];
    for(int i = 1; i < nameSpace.size(); i++){
        ret = ret + "|" + nameSpace[i];
    }
    printf("%s\n", ret.c_str());

}
