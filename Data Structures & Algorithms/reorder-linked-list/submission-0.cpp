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
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second = slow->next;
        ListNode *prev = slow->next = NULL;
        while(second){
            ListNode *nex = second->next;
            second->next = prev;
            prev = second;
            second = nex;
        }
        ListNode *first = head;
        ListNode *scond = prev;
        while(scond){
            ListNode *tmp1 = first->next;
            ListNode *tmp2 = scond->next;
            first->next = scond;
            scond->next = tmp1;
            first = tmp1;
            scond = tmp2;
        }
    }
};
