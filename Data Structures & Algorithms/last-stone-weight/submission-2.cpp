class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // max heap
        priority_queue<int> pq;
        for(auto it : stones) pq.push(it);
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y= pq.top();
            pq.pop();
            if(x == y) continue;
            else pq.push(abs(x-y));
        }
        if(pq.size() == 1) return pq.top();
        return 0;
    }
};
