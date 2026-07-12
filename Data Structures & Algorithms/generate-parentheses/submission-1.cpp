class Solution {
    void solve(int & open,int & close,int & n,vector<string> & ans,string & temp){
      if(open == n && close == n){
        ans.push_back(temp);
        return;
      }
      //open
      if(open <n){
        open++;
        temp += '(';
        solve(open,close,n,ans,temp);
        open--;
        temp.pop_back();
      }
      //close
      if(open > close && close<n){
        close++;
        temp += ')';
        solve(open,close,n,ans,temp);
        close--;
        temp.pop_back();
      }
    }
public:
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        int open  = 0;
        int close = 0;
        solve(open,close,n,ans,temp);
        return ans;
    }
};
