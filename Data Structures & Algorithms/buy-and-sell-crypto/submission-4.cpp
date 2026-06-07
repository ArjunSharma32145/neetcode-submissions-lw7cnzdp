class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxiprofit = 0;
        int brought = prices[0];
        for(int i=1;i<prices.size();i++){
            int sell = prices[i];
            int trans = sell - brought;
            if(trans > 0) maxiprofit = max(maxiprofit,trans);
            else brought = sell;
        }
        return maxiprofit;
    }
};
