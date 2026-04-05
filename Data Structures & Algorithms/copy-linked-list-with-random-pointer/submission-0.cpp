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
       unordered_map<Node*,Node*> copa;
       copa[NULL] = NULL;
       Node * cur = head;
       while(cur){
        Node *copy = new Node(cur->val);
        copa[cur] = copy;
       cur = cur->next;
       }
       cur = head;
       while(cur){
          Node *copy = copa[cur];
          copy->next = copa[cur->next];
          copy->random = copa[cur->random];
          cur = cur->next;
       }
       return copa[head];
    }
};
