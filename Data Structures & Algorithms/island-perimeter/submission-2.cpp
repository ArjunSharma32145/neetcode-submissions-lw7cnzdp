class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    perimeter += 4;
                    int drow[4] = {-1,0,1,0};
                    int dcol[4] = {0,1,0,-1};
                    for(int k=0;k<4;k++){
                        int nrow = i + drow[k];
                        int ncol = j + dcol[k];
                        if(nrow >=0 && nrow < m && ncol >= 0 && ncol< n && grid[nrow][ncol] == 1) perimeter--;
                    }
                }
            }
        }
        return perimeter;
    }
};