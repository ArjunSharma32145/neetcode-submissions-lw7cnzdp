class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // as every time we choosing two heaviest stones therefore we need max ele when we pop
        // hence max heap
        priority_queue<int> pq;
        for(auto it : stones) pq.push(it);
        while(pq.size() > 1){
           int a = pq.top();
           pq.pop();
           int b = pq.top();
           pq.pop();
        if(a == b) continue;
        else pq.push(abs(a-b));
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
