class Solution {
    int solve(int index,vector<int> & days,vector<int> & costs,vector<int> & dp){
        int n = days.size();
        if(index == n) return 0;

        if(dp[index] != -1) return dp[index];

        // 1 day ticket
        int oneday = costs[0] + solve(index+1,days,costs,dp);
        // 7 day ticket
        int day = days[index];
        int last = day + 6;
        int l = n;
        for(int i=index;i<n;i++){
            if(days[i] > last){
                l = i;
                break;
            }
        }
        int sevday = costs[1] + solve(l,days,costs,dp);

        // 30 day ticket
        day = days[index];
        last = day + 29;
        l = n;
        for(int i=index;i<n;i++){
            if(days[i] > last){
                l = i;
                break;
            }
        }
        int thiday = costs[2] + solve(l,days,costs,dp);
        return dp[index] =  min({oneday,sevday,thiday});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n,-1);
        return solve(0,days,costs,dp);
    }
};