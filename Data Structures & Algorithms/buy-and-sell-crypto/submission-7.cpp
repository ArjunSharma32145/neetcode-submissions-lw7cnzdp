class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profits = 0;
       int buy = prices[0];
       for(int i=1;i<prices.size();i++){
        int sell = prices[i];
        if(sell < buy){
            buy = sell;
            continue;
        }
        profits = max(profits,sell - buy);
       } 
       return profits;
    }
};
