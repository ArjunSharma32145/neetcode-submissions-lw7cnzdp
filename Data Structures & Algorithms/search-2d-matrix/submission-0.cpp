class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int targetrow = 0;
        for(int i=0;i<m;i++){
            if(target <= matrix[i][n-1]){
                targetrow = i;
                break;
            }
        }
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(matrix[targetrow][mid]< target) start = mid+1;
            else if(matrix[targetrow][mid] > target) end = mid-1;
            else return true;
        }
        return false;
    }
};
