class Solution {
public:
    int uniquePaths(int m, int n) {
        return paths(m-1,n-1);
    }
private : 
 int paths(int i, int j){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    int up = paths(i-1,j);
    int left = paths(i,j-1);
    return up + left;
 }
};
