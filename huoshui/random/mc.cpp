#include <iostream>
#include <vector>

using namespace std;

#define LEN 3

void init(const vector<double>& w, vector<double>& p) {
    double sum = 0.0f;
    for(int i = 0; i < w.size(); i++)
    {
        sum += w[i];
    }

    p.resize(w.size());
    for(int i = 0; i < w.size(); i++)
    {
        p[i] = w[i] / sum;
    }
}

double uniform()
{
    return ((double)rand()) / ((double)RAND_MAX);
}

unsigned int random(const vector<double>& p_vec) {
    unsigned int idx = rand() % p_vec.size();
    double p = uniform();

    unsigned int ret = idx;
    unsigned count = 1;
    while( p > p_vec[idx] || count < 5) {
        idx = rand() % p_vec.size();
        p = uniform();

        if (p >= p_vec[idx]) {
            ret = idx;
            count ++;
        }
        //cout << idx << ", " << p << ", " << p_vec[idx] << endl;
        

    }

    return idx;
}



int main() {
    srand(time(nullptr));
    vector<double> weights(LEN);
    for(int i = 0; i < LEN; i++) {
        weights[i] = uniform() * (rand() % 1000);
    }

    vector<double> r_vec;
    init(weights, r_vec);
    for(int i = 0; i < r_vec.size(); i++)
    {
        cout << r_vec[i] << " ";
    }
    cout << endl;

    const int FREQ = 100000000;
    vector<double> freq(weights.size(), 0);
    for(int i = 0; i < FREQ; i++)
    {
        freq[random(r_vec)] += 1;
    }

    for(int i = 0; i < weights.size(); i++)
    {
        freq[i] /= FREQ;
    }

    for(int i = 0; i < freq.size(); i++)
    {
        cout << freq[i] << " ";
    }
    cout << endl;

}
