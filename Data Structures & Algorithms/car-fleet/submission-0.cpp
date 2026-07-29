class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> st;
        vector<pair<float,float>> fleet;
        int n = position.size();
        for(int i=0;i<n;i++){
            fleet.push_back({position[i],speed[i]});
        }
        sort(fleet.begin(),fleet.end());
        for(int i=n-1;i>=0;i--){
            float time = (target - fleet[i].first)/fleet[i].second;
            if(st.empty()) st.push(time);
            else if(st.top() >= time) continue;
            else st.push(time);
        }

        return st.size();
    }
};
