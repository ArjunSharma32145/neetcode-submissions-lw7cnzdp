class Solution {
    int sumofsquares(int p){
        int sum = 0;
        while(p != 0){
            int c = p%10;
            p = p/10;
            sum += c*c;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(!st.count(n)){
            st.insert(n);
            n = sumofsquares(n);
            if(n == 1) return true;
        }
        return false;
    }
};
