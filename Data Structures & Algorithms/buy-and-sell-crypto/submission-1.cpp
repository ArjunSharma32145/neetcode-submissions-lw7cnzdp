class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minx = prices[0];
        int ans = 0;
        for(int i=1;i<prices.size();i++){
            int kamai = prices[i]-minx;
            ans = max(ans,kamai);
            minx = min(minx,prices[i]);
        }
        return ans;
    }
};
