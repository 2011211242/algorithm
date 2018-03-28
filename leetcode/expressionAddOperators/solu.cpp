#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    long long int get_val(stack<long long int> &nums, stack<char> &ops){
        while(!ops.empty()){
            long long int n1 = nums.top();
            nums.pop();
            long long int n2 = nums.top();
            nums.pop();

            if(ops.top() == '+'){
                nums.push(n1 + n2);
            }

            if(ops.top() == '-'){
                nums.push(n2 - n1);
            }

            if(ops.top() == '*'){
                nums.push(n2 * n1);
            }

            ops.pop();
        }
        return nums.top();
    }

    void onestep(string num, long long int target, 
            stack<long long int> nums, stack<char> ops, 
            string expr, vector<string> &ret){

        if("" == num){
            auto n1 = nums;
            auto op = ops;

            if(get_val(nums, ops) == target){
                ret.push_back(expr);
                cout << expr << " : " << get_val(n1, op) << endl;
            }

            return;
        }

        stack<long long int> nums2 = nums;
        long long int n1 = nums2.top();
        if(n1 != 0)
        {
            nums2.pop();
            n1 = n1 * 10 + num[0] - '0';
            nums2.push(n1);
            onestep(num.substr(1), target, nums2, ops, expr + num.substr(0, 1), ret);
        }



        nums.push(num[0] - '0');
        ops.push('*');
        onestep(num.substr(1), target, nums, ops, expr + "*" + num.substr(0, 1), ret);
        ops.pop();
        nums.pop();

        get_val(nums, ops);
        nums.push(num[0] - '0');

        ops.push('+');
        onestep(num.substr(1), target, nums, ops, expr + "+" + num.substr(0, 1), ret);
        ops.pop();

        ops.push('-');
        onestep(num.substr(1), target, nums, ops, expr + "-" + num.substr(0, 1), ret);
        ops.pop();

        nums.push(num[0] - '0');
    }


public:
    vector<string> addOperators(string num, long long int target) {
        vector<string> ret;
        if(num == "") return ret;
        stack<long long int> nums;
        stack<char> ops;
        nums.push(num[0] - '0');
        onestep(num.substr(1), target, nums, ops, num.substr(0, 1), ret);
        return ret;
    }
};

int main(){
    Solution s;
    string num = "2147483648";
    vector<string> ops = s.addOperators(num, -2147483648);
    cout << "-------------------------------------" << endl;
    for(auto op : ops)
        cout << op <<endl;

}

