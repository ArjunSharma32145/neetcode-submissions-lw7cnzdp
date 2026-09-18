class Solution {
    vector<int> dp;
    int solve(int index,vector<int> & cost){
        int n = cost.size();
        if(index >= n) return 0;
          
          if(dp[index] != -1) return dp[index];
        int onejump = solve(index+1,cost) + cost[index];
        int twojump = solve(index+2,cost) + cost[index];
        return dp[index] =  min(onejump,twojump);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n,-1);
        return min(solve(0,cost),solve(1,cost));
    }
};
