#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        median = 0;
        size = 0;
    }

    void addNum(int num) {
        if(size++ == 0) {
            median = num;
            return;
        }
        if(max_heap.size() == min_heap.size()) {
            if( num < median ) {
                max_heap.push(num);
            }
            else {
                max_heap.push(median);
                min_heap.push(num);
                median = min_heap.top();
                min_heap.pop();
            }
                
        }
        else {
            if ( num > median ) {
                min_heap.push(num);
            }
            else {
                min_heap.push(median);

                max_heap.push(num);
                median = max_heap.top();
                max_heap.pop();
            }
        }
    }

    double findMedian() {
        if(max_heap.size() == min_heap.size()) {
            return median;
        }
        else if(max_heap.size() > min_heap.size()) {
            return (max_heap.top() + median) / 2.0;
        }
        return median;
    }
private:
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int median;
    int size;
};

int main() {
    MedianFinder s;
    s.addNum(-1);
    s.addNum(-2);
    cout << s.findMedian() << endl;
    return 0;
}
