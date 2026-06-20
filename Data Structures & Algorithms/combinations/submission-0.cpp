class Solution {
    void solve(int index,int & n,int & k,vector<int> & temp,vector<vector<int>> & ans){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(index == n+1){
            return;
        }

        //lena hai
        k--;
        temp.push_back(index);
        solve(index+1,n,k,temp,ans);
        k++;
        temp.pop_back();

        //nhi lena
        solve(index+1,n,k,temp,ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,n,k,temp,ans);
        return ans;
    }
};