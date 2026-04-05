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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr;
        ptr=head;
        if(!head) return NULL;
        int count=0;
        while(ptr){
            count++;
            ptr = ptr->next;
        }
        if(count==1 ) return NULL;
        int nol = count - n;
           if(nol==0){
            head=head->next;
            return head;
           }
           if(nol-1==0){
            if(head->next->next != NULL){
                head->next = head->next->next;
                return head;
            }
            else head->next = NULL;
            return head;
           }
        ptr=head;
        nol--;
        while(nol!=0){
           nol--;
           ptr = ptr->next;
        }
        if(ptr->next->next != NULL)
        ptr->next = ptr->next->next;
        else ptr->next =NULL;
        return head;
    }
};
