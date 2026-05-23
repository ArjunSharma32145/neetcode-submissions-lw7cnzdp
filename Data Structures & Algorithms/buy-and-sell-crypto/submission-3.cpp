class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      if(n == 1) return 0;
        int maxikamai = 0;
        int buy = prices[0];
        for(int i=1;i<n;i++){
             int sell = prices[i];
             int prof = sell - buy;
             maxikamai = max(prof,maxikamai);
             if(sell < buy) buy = sell;
        }
        return maxikamai;
    }
};
