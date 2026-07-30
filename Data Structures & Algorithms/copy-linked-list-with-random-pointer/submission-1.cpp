/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *,Node *> oldToNew;
        Node * curr=  head;
        // first pass only generating nodes 
        while(curr){
            Node * copy = new Node(curr->val);
            oldToNew[curr] = copy;
            curr= curr->next;
        }
        // second pass connecting those generated nodes
        curr = head;
        while(curr){
            Node * copy = oldToNew[curr];
            copy->next = oldToNew[curr->next];
            copy->random = oldToNew[curr->random];
            curr= curr->next;
        }
        return oldToNew[head];
    }
};
