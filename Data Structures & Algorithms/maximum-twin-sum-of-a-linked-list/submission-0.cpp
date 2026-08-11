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
    int pairSum(ListNode* head) {
        vector<int> arr;
        ListNode * lol = head;
        while(lol){
             arr.push_back(lol->val);
             lol = lol->next;
        }
        int i=0;
        int j = arr.size()-1;
        int ans= 0;
        while(i<j){
          ans= max(ans,arr[i] + arr[j]);
          i++;
          j--;
        }
        return ans;
    }
};