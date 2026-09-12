class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // as i have to always take out max two heaviest stones best is to use max heap
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a == b) continue;
            if( a < b) pq.push(b-a);
            else pq.push(a-b);
        }
        if(pq.size()) return pq.top();
        return 0;
    }
};
