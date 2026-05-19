class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> freq;
        for(auto it : tasks) freq[it]++;
        // max heap
        priority_queue<int> pq;
        for(auto it : freq) pq.push(it.second);
        queue<pair<int,int>> q;
        int time = 0;
        while( !pq.empty() || !q.empty()){
          time += 1;
          int lol = 0;
          if(!pq.empty()){
            lol = pq.top();
            pq.pop();
            lol = lol-1;
          }
          if(lol){
            q.push({lol,time+n});
          }
          if(!q.empty()){
            auto check = q.front();
            if(time >= check.second){
                q.pop();
                pq.push(check.first);
            }
          }
        }
        return time;
    }
};
