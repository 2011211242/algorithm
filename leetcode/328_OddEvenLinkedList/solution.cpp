/**
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Version: 1.0: solution.cpp 2019年09月30日 
 *
 * Authors:
 *   andrewyan <andrewyan@tencent.com>
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* ptr = head;
        ListNode* even_head = NULL, * even_ptr = NULL;

        if (ptr && ptr -> next)
        {
            even_head = even_ptr  = ptr -> next;
            ptr -> next = even_ptr -> next;

            even_ptr -> next = NULL;
            if (ptr && ptr -> next) ptr = ptr -> next;
        }

        while(ptr && ptr -> next)
        {
            even_ptr -> next = ptr -> next;
            ptr -> next = ptr -> next -> next;

            even_ptr -> next -> next = NULL;
            even_ptr = even_ptr -> next;

            if (ptr && ptr -> next) ptr = ptr -> next;
            else break;
        }

        ptr -> next = even_head;
        return head;
    }
};

int main() {
    vector<int> nums = {
        1,2,3,4
    };

    ListNode * root = NULL, * ptr = NULL;
    for(int i = 0; i < nums.size(); i++)
    {
        if (root == NULL)
        {
            root = ptr = new ListNode(nums[i]);
        }
        else {
            ptr -> next = new ListNode(nums[i]);
            ptr = ptr -> next;
        }
    }

    Solution s;
    ptr = s.oddEvenList(root);

    while(ptr)
    {
        cout << ptr -> val << "  ";
        ptr = ptr -> next;
    }
    cout << endl;
}
