class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0;
        int n = cost.size();
        int prev = 0;
        int curr=  0;
        for(int i=2;i<=n;i++){
            int onejump = prev + cost[i-1];
            int twojump = prev2 + cost[i-2];
            curr  = min(onejump,twojump);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};
