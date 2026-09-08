class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i= 0;
        int j = n-1;
        while(i<j){
            while(!isalnum(s[i]) && i<n) i++;
            while(!isalnum(s[j])&& j>=0) j--;
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
