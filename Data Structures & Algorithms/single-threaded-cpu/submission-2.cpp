class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // two min heaps
        //min heap for pending tasks
        // obv we will keep enqueue time as a way of sorting for this
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pend;
        //min heap for available tasks
        // obv we gonna use processing time as a way of sorting for this
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> avail;
    for(int i=0;i<tasks.size();i++){
        pend.push({tasks[i][0],{tasks[i][1],i}});
    }
    int time =0;
    vector<int> result;

      while(!pend.empty() || !avail.empty()){
           if(!pend.empty()){
            if(time >= pend.top().first){
            while(!pend.empty() && time >= pend.top().first){
                auto task = pend.top();
                pend.pop();
                avail.push({task.second.first,task.second.second});
            }
            }
            else if(avail.empty()) time  = pend.top().first;
           }
           if(!avail.empty()){
                auto task = avail.top();
                avail.pop();
                result.push_back(task.second);
                time += task.first;     
           }

      }
     return result;
    }
};