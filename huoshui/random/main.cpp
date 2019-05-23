#include <iostream>
#include <vector>
#include <climits>
#include <assert.h>
#include <cmath>

using namespace std;

#define LEN 100

double uniform()
{
    return ((double)rand()) / ((double)RAND_MAX);
}

void init( const vector<double> w, vector<double>& r_vec ) {
    if (w.size() <= 0) return;

    r_vec.resize(w.size() + 1);
    r_vec[0] = 0;
    for (int i = 0; i < w.size(); i++)
    { 
        r_vec[i + 1] = r_vec[i] + w[i];
    }

    double upper = r_vec[r_vec.size() - 1];
    for(int i = 0; i < r_vec.size(); i++)
    {
        r_vec[i] /= upper;
    }
}

unsigned int binary_search(const vector<double> v, const double key)
{
    unsigned int l = 0, r = v.size() - 1;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if (v[mid] < key)
        {
            l = mid + 1;
        }
        else if (v[mid] > key)
        {
            r = mid;
        }
        else return mid;
    }
    return l;
}

unsigned int random(const vector<double> v) {
    double key = uniform();
    assert ( v[binary_search(v, key)] >= key );
    return binary_search(v, key) - 1;
}

int main() {
    srand(time(nullptr));
    vector<double> weights(LEN);
    for(int i = 0; i < LEN; i++) {
        weights[i] = uniform() * (rand() % 1000);
    }

    vector<double> r_vec;
    init(weights, r_vec);
    /*
    for(int i = 1; i < r_vec.size(); i++)
    {
        cout << r_vec[i] - r_vec[i - 1] << " ";
    }
    cout << endl;
    */

    const int FREQ = 10000000;
    vector<double> freq(weights.size(), 0);
    for(int i = 0; i < FREQ; i++)
    {
        freq[random(r_vec)] += 1;
    }

    for(int i = 0; i < weights.size(); i++)
    {
        freq[i] /= FREQ;
    }

    double Q = 0;
    for(int i = 0; i < freq.size(); i++)
    {
        cout << r_vec[i + 1] - r_vec[i] << " " << freq[i] << endl;
        Q += (r_vec[i + 1] - r_vec[i] - freq[i]) * (r_vec[i + 1] - r_vec[i] - freq[i]);
    }
    cout << endl;
    Q /= freq.size();
    cout << sqrt(Q) << endl;
}


