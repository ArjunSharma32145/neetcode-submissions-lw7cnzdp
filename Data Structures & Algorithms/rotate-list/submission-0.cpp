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
private:
  void rotate(ListNode * node, int actual ,int n, ListNode * end){
    if(!node->next) return;
    while(actual--){
        int p = n-1;
        ListNode * first = node;
       int temp1 = first->val;
        while(p--){
            ListNode * second = first->next;
            if(end == second){
                node->val = second->val;
                second->val = temp1;
                break;
            }
            int temp2 = second->val;
            second->val = temp1;
            temp1 = temp2;
            first = first->next;
        }
    }
  }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 1;
        ListNode * end = head;
        if(!head) return head;
        while(end->next){
            n++;
            end = end->next;
        }
        int actual = k%n;
        rotate(head,actual,n,end);
        return head;
    }
};