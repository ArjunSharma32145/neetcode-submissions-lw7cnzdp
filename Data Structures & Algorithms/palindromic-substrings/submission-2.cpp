class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
          //even length
          int r = i+1;
          int l = i;
          while(l>=0 && r<n && s[l] == s[r]){
            count++;
            l--;
            r++;
          }
          //oddlength
          r = i;
          l=i;
          while(l>=0 && r<n && s[l] == s[r]){
             count++;
             l--;
             r++;
          }
        }
        return count;
    }
};
