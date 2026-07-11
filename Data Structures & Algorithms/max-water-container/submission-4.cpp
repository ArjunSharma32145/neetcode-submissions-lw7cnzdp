class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i=0;
        int j=n-1;
        int maxi = 0;
        while(i<j){
            int ht = min(heights[i],heights[j]);
            int base = j-i;
            maxi = max(maxi, ht*base);
            if(heights[i] >= heights[j]) j--;
            else i++;
        }
        return maxi;
    }
};
