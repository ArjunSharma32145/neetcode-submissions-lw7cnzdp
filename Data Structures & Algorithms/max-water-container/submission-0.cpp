class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int currarea=0;
        int maxarea=0;
      for(int i=0;i<n-1;i++){
         for(int j=i+1;j<n;j++){
            currarea= (j-i)*(min(heights[i],heights[j]));
            maxarea=max(maxarea,currarea);
         }
      }
      return maxarea;
    }
};
