class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buy = prices[0];
       int maxiprof = 0;
       for(int i=0;i<prices.size();i++){
        int sell = prices[i];
        int prof = sell - buy;
        if(prof > 0) maxiprof += prof;
        buy = sell;
       } 
       return maxiprof;
    }
};