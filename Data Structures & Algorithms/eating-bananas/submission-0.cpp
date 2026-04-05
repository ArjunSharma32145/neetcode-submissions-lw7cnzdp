class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start =1;
        int end = *max_element(piles.begin(),piles.end());
        int ans = end;
        while(start<=end){
            int mid = start + (end-start)/2;
            int totaltime =0;
            for(auto it : piles){
                totaltime += (it+mid-1)/mid;
            }
            if(totaltime <=h){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};
