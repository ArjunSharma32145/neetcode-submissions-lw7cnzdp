class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        if(stones.size() == 1) return stones[0];
        for(auto it : stones) pq.push(it);
        while(pq.size()>1){
            int diff = 0;
           int a = pq.top();
           pq.pop();
           int b = pq.top();
           pq.pop();
            if(a>b){
            diff = a-b;
             pq.push(diff); }
           else if(b>a) {
            diff = b-a;
            pq.push(diff); }
           if(pq.size()==1) return pq.top();
        }
        return 0;
    }
};
