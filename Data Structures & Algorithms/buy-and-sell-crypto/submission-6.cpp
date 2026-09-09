class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxiprofit = 0;
        int buy = prices[0];
        for(int i=1;i<prices.size();i++){
            int sell = prices[i];
            if(sell > buy){
                maxiprofit = max(sell - buy,maxiprofit);
            }
            else buy = sell;
        }
        return maxiprofit;
    }
};
