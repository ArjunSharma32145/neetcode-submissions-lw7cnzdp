class Solution {
    int solve(int i,int total,vector<int> & stones,vector<vector<int>> & dp,int totalsum,int target){
        int n = stones.size();
        if(total >= target || i == n){
            return abs(total - (totalsum - total));
        }
        if(dp[i][total] != -1) return dp[i][total];

        int take = solve(i+1,total + stones[i],stones,dp,totalsum,target);
        int nottake = solve(i+1,total,stones,dp,totalsum,target);
        return dp[i][total] = min(take,nottake);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalsum = 0;
        for(auto it : stones) totalsum += it;
        int target = ceil(totalsum/2);
        vector<vector<int>> dp(n,vector<int>(target+1,-1)); 
        return solve(0,0,stones,dp,totalsum,target);

    }
};