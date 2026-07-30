/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        deque<ListNode *> dq;
        ListNode * p = head;
        for(p=head;p;p=p->next){
            dq.push_back(p);
        }
        ListNode * curr = head;
        dq.pop_front();
        bool flag = false;
        while(!dq.empty()){
        ListNode * node;
        if(flag){
            node = dq.front();
            dq.pop_front();
            flag = false;
        }
        else{
            node = dq.back();
            dq.pop_back();
            flag = true;
        }

        curr->next = node;
        curr = curr->next;
        }
        curr->next = nullptr;
    }
};
