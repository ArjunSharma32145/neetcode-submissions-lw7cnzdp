class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int paisahipaisa = 0;
       int mini = prices[0];
       for(int i=1;i<prices.size();i++){
         paisahipaisa = max(paisahipaisa,prices[i]-mini);
         mini = min(mini,prices[i]);
       } 
       return paisahipaisa;
    }
};
