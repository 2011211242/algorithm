#include <cstdio>
#include <cmath>
using namespace std;

#define SQRT2 1.4142135623

int main(){
    double x0, y0, r;
    scanf("%lf %lf %lf", &x0, &y0, &r);
    const double r2 = r * r;
    int x_s = (int)ceil(x0 - r);
    int x_e = (int)floor(x0 + r);

    int y_u = (int)floor(y0 + r);
    int y_d = (int)ceil(y0 - r);

    int res_x = 0;
    int res_y = 0;

    double dist = 0.00000000f;
    for(int x = (int)floor(x0); x >= x_s; x--){
        double tmp_x = (x - x0) * (x - x0);
        while(tmp_x + (y_u - y0) * (y_u - y0) > r2 && y_u >= y0) y_u--;
        while(tmp_x + (y0 - y_d) * (y0 - y_d) > r2 && y_d <= y0) y_d++;

        if(y_u >= y0){
            if((y_u - y0) * (y_u - y0) + tmp_x > dist){
                dist = tmp_x + (y_u - y0) * (y_u - y0);
                res_x = x;
                res_y = y_u;
            }else{
                if((y_u - y0) * (y_u - y0) + tmp_x == dist){
                    if(x > res_x || (x == res_x && y_u > res_y)){
                        res_x = x;
                        res_y = y_u;
                    }
                }
            }
        }
        if(y_d <= y0){
            if((y0 - y_d) * (y0 - y_d) + tmp_x > dist){
                dist = tmp_x + (y0 - y_d) * (y0 - y_d);
                res_x = x;
                res_y = y_d;
            }else{
                if((y_d - y0) * (y_d - y0) + tmp_x == dist){
                    if(x > res_x || (x == res_x && y_d > res_y)){
                        res_x = x;
                        res_y = y_d;
                    }
                }
            }
        }
    }

    y_u = (int)floor(y0 + r);
    y_d = (int)ceil(y0 - r);

    for(int x = (int)ceil(x0); x <= x_e; x++){
        double tmp_x = (x - x0) * (x - x0);
        while(tmp_x + (y_u - y0) * (y_u - y0) > r2 && y_u >= y0) y_u--;
        while(tmp_x + (y0 - y_d) * (y0 - y_d) > r2 && y_d <= y0) y_d++;

        if(y_u >= y0){
            if((y_u - y0) * (y_u - y0) + tmp_x > dist){
                dist = tmp_x + (y_u - y0) * (y_u - y0);
                res_x = x;
                res_y = y_u;
            }
            else{
                if((y_u - y0) * (y_u - y0) + tmp_x == dist){
                    if(x > res_x || (x == res_x && y_u > res_y)){
                        res_x = x;
                        res_y = y_u;
                    }
                }
            }
        }
        if(y_d <= y0){
            if((y0 - y_d) * (y0 - y_d) + tmp_x > dist){
                dist = tmp_x + (y0 - y_d) * (y0 - y_d);
                res_x = x;
                res_y = y_d;
            }
            else{
                if((y_d - y0) * (y_d - y0) + tmp_x == dist){
                    if(x > res_x || (x == res_x && y_d > res_y)){
                        res_x = x;
                        res_y = y_d;
                    }
                }
            }
        }
    }
    printf("%d %d\n", res_x, res_y);
}
