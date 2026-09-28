class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
      int targetrow = -1;
      int start = 0;
      int end = matrix.size()-1;
      while(start<=end){
        int row = start + (end-start)/2;
        if(target > matrix[row][n-1]) start = row+1;
        else if(target < matrix[row][0]) end = row-1;
        else{
            targetrow = row;
            break;
        }
      }
      if(targetrow == -1) return false;
      start = 0;
      end = n-1;
      while(start<=end){
        int mid = start + (end-start)/2;
        if(matrix[targetrow][mid] == target) return true;
        else if(matrix[targetrow][mid] > target) end = mid-1;
        else start = mid+1;
      }  
      return false;
    }
};
