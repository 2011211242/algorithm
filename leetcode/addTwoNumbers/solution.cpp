#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode(0), *ptr = head;
        while(l1 && l2){
            ptr -> next = new ListNode(ptr -> val / 10 + l1 -> val + l2 -> val);
            ptr -> val %= 10;
            ptr = ptr -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while(ptr -> val >= 10 && l1){
            ptr -> next = new ListNode(ptr -> val / 10 + l1 -> val);
            ptr -> val %= 10;
            ptr = ptr -> next;
            l1 = l1 -> next;
        }

        while(ptr -> val >= 10 && l2){
            ptr -> next = new ListNode(ptr -> val / 10 + l2 -> val);
            ptr -> val %= 10;
            ptr = ptr -> next;
            l2 = l2 -> next;
        }

        if(ptr -> val >= 10){
            ptr -> next = new ListNode(1);
            ptr -> val -= 10;
        }
        else{
            if(l1) ptr -> next = l1;
            else if(l2) ptr -> next = l2;
        }

        ptr = head;
        head = ptr -> next;
        delete ptr;
        return head;
    }
};

int main(){
    Solution s;
}
