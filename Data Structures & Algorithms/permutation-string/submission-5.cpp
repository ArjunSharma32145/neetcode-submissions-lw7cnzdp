class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> freq1;
        unordered_map<char,int> freq2;
        int m = s1.size();
        int n = s2.size();
        if(m > n) return false;
        for(auto it : s1) freq1[it]++;
        int i=0;
        int j;
        for( j=0;j<m;j++){
            freq2[s2[j]]++;
        }
        if(freq1 == freq2) return true;
        while(j<n){
            freq2[s2[j]]++;
            freq2[s2[i]]--;
            if(freq2[s2[i]] == 0) freq2.erase(s2[i]);
            i++;
            j++;
            if(freq1 == freq2) return true;
        }
        return false;
    }
};
