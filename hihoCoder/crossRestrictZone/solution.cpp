#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Circle{
    int x, y, r;
    Circle(int xx, int yy, int rr):x(xx), y(yy), r(rr){}
};

bool isIntersect(Circle &a, Circle &b)
{
    return (a.x - b.x) * (a.x - b.x) +
        (a.y - b.y) * (a.y - b.y) <=
        (a.r + b.r) * (a.r + b.r);
}

bool isIntersect(Circle &a, int y)
{
    return a.y - a.r <= y && y <= a.y + a.r;
}

int main(){
    int T;
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            int w, h, n;
            scanf("%d %d %d", &w, &h, &n);
            vector<Circle> circles;
            for(int i = 0; i < n; i++)
            {
                int x, y, r;
                scanf("%d %d %d", &x, &y, &r);
                circles.push_back(Circle(x, y, r));
            }

            vector<vector<int>> cirMap(n);
            for(int i = 0; i < circles.size() - 1; i++)
            {
                for(int j = i + 1; j < circles.size(); j++)
                {
                    if(isIntersect(circles[i], circles[j]))
                    {
                        cirMap[i].push_back(j);
                        cirMap[j].push_back(i);
                    }
                }
            }

            vector<bool> is_gray(n, false);
            queue<int> que;
            for(int i = 0; i < circles.size(); i++){
                if(isIntersect(circles[i], 0)){
                    que.push(i);
                    is_gray[i] = true;
                }
            }

            bool flag = false;
            while(!que.empty()){
                int cur = que.front();
                que.pop();

                for(int i = 0; i < cirMap[cur].size(); i++)
                {
                    int next = cirMap[cur][i];
                    if(is_gray[next] == false)
                    {
                        if(isIntersect(circles[next], h))
                        {
                            flag = true;
                            break;
                        }

                        is_gray[next] = true;
                        que.push(next);
                    }
                }
                if(flag) break;
            }
            if(flag) printf("NO\n");
            else printf("YES\n");
        }
    }
}
