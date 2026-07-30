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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      int  index = 1;
     ListNode * curr = head;
     ListNode * prov = NULL;
     while(index != left){
        if(index + 1 == left) prov = curr;
        curr = curr->next;
        index++;
     }
     ListNode * starter = curr;
     ListNode * prev = NULL;
     while(index != right){
        ListNode * nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr =nex;
        index++;
     }
     ListNode * end = curr->next;
     curr->next = prev;
     starter->next= end;
    if(prov) prov->next = curr;
    if(prov) return head;
    return curr;
    }
};