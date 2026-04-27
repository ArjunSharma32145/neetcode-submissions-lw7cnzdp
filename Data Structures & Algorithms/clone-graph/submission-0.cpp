/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> oldwithnew;
        return dfs(node,oldwithnew);
    }
    Node* dfs(Node* node,unordered_map<Node*,Node*> & oldwithnew){
        if(node == NULL) return NULL;
        if(oldwithnew.count(node)) return oldwithnew[node];
        Node* copy = new Node(node->val);
        oldwithnew[node] = copy;
        for(auto nei : node->neighbors){
            copy->neighbors.push_back(dfs(nei,oldwithnew));
        }
        return copy;
    }
};
