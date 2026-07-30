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
        ListNode * hed = head;
        if(!head->next) return ;
        while(hed->next){
            ListNode * nex = hed->next;
            if(!nex->next) return;
            ListNode * curr = nex;

            while(curr->next->next) curr = curr->next;
            ListNode * prev = curr;
            curr = curr->next;
            prev->next = NULL;
            hed->next = curr;
            curr->next = nex;
            hed = hed->next->next;
        }
        return;
    }
};
