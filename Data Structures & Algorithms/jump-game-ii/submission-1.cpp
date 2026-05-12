class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int goal = n-1;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{nums[0],0}});
        vector<int> visited(n,0);
        visited[0] = 1;
        while(!q.empty()){
          int node = q.front().second.first;
          int steps = q.front().first;
          int index = q.front().second.second;
          q.pop();
          if(index == goal) return steps;
          for(int i=index;i<=index+node;i++){
            if(i <n && !visited[i]){
                visited[i] = 1;
                q.push({steps+1,{nums[i],i}});
            }
          }
        }
        return -1;
    }
};
