#include <cstdio>
#include <vector>
using namespace std;

const int NODE_CAPCITY = 1;
const int MAX_BOUND = 30000;

struct node{
    int boundary[4];
    vector<pair<int,int>> points;
    node *childNode[4];
    int pointNumber;
};

void init(node* root, pair<int,int> p, int x1, int y1, int x2, int y2){
    root -> boundary[0] = x1;
    root -> boundary[1] = y1;
    root -> boundary[2] = x2;
    root -> boundary[3] = y2;

    root -> childNode[0] = NULL;
    root -> childNode[1] = NULL;
    root -> childNode[2] = NULL;
    root -> childNode[3] = NULL;
    root -> points.push_back(p);
    root -> pointNumber = 1;
}

void split(node* root){
    vector<pair<int, int>> points = root -> points;
    root->points = {};

    int a = (root -> boundary[0] + root -> boundary[2]) >> 1;
    int b = (root -> boundary[1] + root -> boundary[3]) >> 1;

    int x1 = root->boundary[0];
    int y1 = root->boundary[1];
    int x2 = root->boundary[2];
    int y2 = root->boundary[3];

    for(int i = 0; i < points.size(); i++){
        if(points[i].first <= a){
            if(points[i].second <= b){
                if(root->childNode[0] == NULL){
                    root->childNode[0] = new node;
                    init(root->childNode[0], points[i], x1, y1, a, b);
                }
                else{
                    root->childNode[0]->points.push_back(points[i]);
                }
            }
            else{
                if(root->childNode[1] == NULL){
                    root->childNode[1] = new node;
                    init(root->childNode[1], points[i], x1, b + 1, a, y2);
                }
                else{
                    root->childNode[1]->points.push_back(points[i]);
                }
            }
        }
        else{
            if(points[i].second <= b){
                if(root -> childNode[2] == NULL){
                    root->childNode[2] = new node;
                    init(root->childNode[2], points[i], a + 1, y1, x2, b);
                }
                else{
                    root->childNode[2]->points.push_back(points[i]);
                }
            }
            else{
                if(root -> childNode[3] == NULL){
                    root->childNode[3] = new node;
                    init(root->childNode[3], points[i], a + 1, b + 1, x2, y2);
                }
                else{
                    root->childNode[3]->points.push_back(points[i]);
                }
            }
        }
    }
}

void insert(node* root, pair<int,int> p){
    root->pointNumber++;
    if(root -> points.size() > 0 && root->points.size() < NODE_CAPCITY){
        root->points.push_back(p);
    }
    else{
        if(root->points.size() == NODE_CAPCITY){
            split(root);
        }

        int x1 = root->boundary[0];
        int y1 = root->boundary[1];
        int x2 = root->boundary[2];
        int y2 = root->boundary[3];
        int a = (x1 + x2) >> 1;
        int b = (y1 + y2) >> 1;

        if(p.first <= a){
            if(p.second <= b){
                if(root->childNode[0] == NULL){
                    root->childNode[0] = new node;
                    init(root->childNode[0], p, x1, y1, a, b);
                }
                else{
                    insert(root->childNode[0], p);
                }
            }
            else{
                if(root->childNode[1] == NULL){
                    root->childNode[1] = new node;
                    init(root->childNode[1], p, x1, b + 1, a, y2);
                }
                else{
                    insert(root->childNode[1], p);
                }
            }
        }
        else{
            if(p.second <= b){
                if(root -> childNode[2] == NULL){
                    root->childNode[2] = new node;
                    init(root->childNode[2], p, a + 1, y1, x2, b);
                }
                else{
                    insert(root->childNode[2], p);
                }
            }
            else{
                if(root -> childNode[3] == NULL){
                    root->childNode[3] = new node;
                    init(root->childNode[3], p, a + 1, b + 1, x2, y2);
                }
                else{
                    insert(root->childNode[3], p);
                }
            }
        }
    }
}

bool distWithin(pair<int,int> p1, pair<int,int> p2, int dist){
    int x = p1.first - p2.first;
    int y = p1.second - p2.second;
    return x * x + y * y <= dist * dist;
}

bool isWithin(pair<int,int> p1, pair<int,int> p2, pair<int,int> p, int r){
    return distWithin(p1, p, r) && distWithin(p2, p, r) && distWithin({p1.first, p2.second}, p, r) && distWithin({p2.first, p1.second}, p, r);
}

bool hasCommon(pair<int,int> p1, pair<int,int> p2, pair<int,int> p, int r){
    if(p.first >= p1.first && p.first <= p2.first){
        if(p.second >= p1.second && p.second <= p2.second){
            return true;
        }
        else{
            if(p.second > p2.second){
                return p.second - r <= p2.second;
            }
            else{
                return p.second + r >= p1.second;
            }
        }
    }
    else{
        if(p.second >= p1.second && p.second <= p2.second){
            if(p.first > p2.first){
                return p.first - r <= p2.first;
            }
            else{
                return p.first + r >= p1.first;
            }
        }
        else{
            return distWithin(p1, p, r) || distWithin(p2, p, r) || distWithin({p1.first, p2.second}, p, r) || distWithin({p2.first, p1.second}, p, r);
        }
    }
}

int search(node *root, pair<int,int> p, int r){
    if(root == NULL) return 0;

    int res = 0;
    int x1 = root->boundary[0];
    int y1 = root->boundary[1];
    int x2 = root->boundary[2];
    int y2 = root->boundary[3];

    if(root->points.empty()){
        if(hasCommon({x1, y1}, {x2, y2}, p, r)){
            if(isWithin({x1, y1}, {x2, y2}, p, r)){
                res = root->pointNumber;
            }
            else{
                res = search(root->childNode[0], p, r);
                res += search(root->childNode[1], p, r);
                res += search(root->childNode[2], p, r);
                res += search(root->childNode[3], p, r);
            }
        }
     }
    else{
        for(int i = 0; i < root->points.size(); i++){
            if(distWithin(p, root->points[i], r)) res++;
        }
    }
    return res;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int x, y, r;
    scanf("%d %d", &x, &y);
    node * root = new node;
    init(root, {x, y}, 0, 0, MAX_BOUND, MAX_BOUND);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &x, &y);
        insert(root, {x, y});
    }

    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &x, &y, &r);
        printf("%d\n", search(root, {x, y}, r));
    }
    return 0;
}


