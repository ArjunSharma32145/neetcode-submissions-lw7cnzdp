class KthLargest {
public:
  priority_queue<int,vector<int>,greater<int>> pq;
  int l=0;
    KthLargest(int k, vector<int>& nums) {
        l=k;
        for(auto it : nums) pq.push(it);
        int size = pq.size();
        while(size>k) {
            pq.pop();
            size--;
        }
    }
    
    int add(int val) {
        if(!pq.size()){
            pq.push(val);
            
        }
       else if(val >pq.top() && pq.size() == l){
            pq.pop();
            pq.push(val);
        }
        else if(pq.size() < l) {
            pq.push(val);
        }
        return pq.top();
    }
};
