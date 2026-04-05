class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        sort(s1.begin(),s1.end());
        int i=0;
        int j=n-1;
        while(j<m){
            string check = s2.substr(i,j-i+1);
            sort(check.begin(),check.end());
            if(check == s1) return true;
            i++;
            j++;
        }
        return false;
    }
};
