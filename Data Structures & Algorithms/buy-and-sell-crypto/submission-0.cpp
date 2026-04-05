class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i =0;
        int j=1;
        int maxprof =0;
        while(j<n){
            if(prices[i]<prices[j]){
           int currprof= prices[j]-prices[i];
           maxprof=max(maxprof,currprof);
            }
            else{
                i=j;
            }
            j++;
        }
        return maxprof;
    }
};
