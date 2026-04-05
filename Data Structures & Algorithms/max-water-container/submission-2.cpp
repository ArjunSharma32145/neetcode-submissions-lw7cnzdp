class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i =0;
        int j=n-1;
        int ans = 0;
        while(i<j){
            int len = min(heights[i],heights[j]);
            int bre = j-i;
            ans = max(ans,len*bre);
            if(heights[i]>heights[j]) j--;
            else i++;
        }
        return ans;
    }
};
