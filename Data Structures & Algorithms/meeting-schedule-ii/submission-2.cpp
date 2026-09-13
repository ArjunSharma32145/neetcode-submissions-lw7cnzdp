/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        for(auto it : intervals){
            start.push_back(it.start);
            end.push_back(it.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int rooms= 0;
        int ans = 0;
        int j=0;
        int k =0;
        while(j < start.size() && k<end.size()){
              if(start[j] < end[k]){
                rooms++;
                ans = max(ans,rooms);
                j++;
              }
              else if(start[j] == end[k]){
                rooms--;
                k++;
                rooms++;
                j++;
                ans = max(ans,rooms);
              }
              else{
                rooms--;
                k++;
              }
        }
        return ans;
    }
};
