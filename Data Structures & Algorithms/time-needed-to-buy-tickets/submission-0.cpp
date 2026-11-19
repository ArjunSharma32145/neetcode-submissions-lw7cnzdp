class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            int check = 0;
            if(k == i) check = 1;
          q.push({tickets[i],check});
        }
        int time = 0;
        while(!q.empty()){
          time++;
          auto it  = q.front();
          q.pop();
          it.first -= 1;
          if(it.first == 0 && it.second == 1) return time;
        if(it.first > 0)  q.push(it);
        }
        return -1;
    }
};