class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int brought = prices[0];
        for(int i=1;i<prices.size();i++){
            int diffi = prices[i] - brought;
            if(diffi > 0) maxprofit += diffi;
            brought = prices[i];
        }
        return maxprofit;
    }
};