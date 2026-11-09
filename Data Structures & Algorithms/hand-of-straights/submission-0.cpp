class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        unordered_map<int,int> freq;
        for(auto it : hand) freq[it]++;
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++){
            if(freq[hand[i]] == 0) continue;
            int count = 0;
            int check = hand[i];
            while(count != groupSize){
                if(freq[check] <=0) return false;
                count++;
                freq[check]--;
                check++;
            }
        }
        return true;
    }
};
