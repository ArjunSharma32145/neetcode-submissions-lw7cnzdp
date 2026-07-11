class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = prices[0];
        int maxiprof = 0;
        for(int i=1;i<prices.size();i++){
            int sell = prices[i];
            if(sell < cost) cost = sell;
            else{
                maxiprof = max(maxiprof,sell-cost);
            }
        }
        return maxiprof;
    }
};
