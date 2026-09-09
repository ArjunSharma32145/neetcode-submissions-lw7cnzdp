class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // ok so given two strings 
        // so s2 contain permutation of s1 then true otherwise false ok so even if s2 exist as substring of s2 thenn also true
        // this is a problem of fix sliding window as substring or subarray 
        int m = s1.size();
        int n = s2.size();
        if(m > n) return false;
        unordered_map<char,int> freq1,freq2;
        for(auto it : s1) freq1[it]++;
        for(int i=0;i<m;i++){
            freq2[s2[i]]++;
        }
        if(freq1 == freq2) return true;
        int l = 0;
        int j = m;
        while(j<n){
            freq2[s2[j]]++;
            freq2[s2[l]]--;
            if(freq2[s2[l]] == 0) freq2.erase(s2[l]);
            l++;
            j++;
            if(freq1 == freq2) return true;
        }
        return false;
    }
};
