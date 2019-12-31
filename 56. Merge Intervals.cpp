class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.empty()) {
            return ans;
        }
        sort(intervals.begin(), intervals.end(), compare);
        int start = intervals[0][0], end = intervals[0][1];
        for (vector<int> interval : intervals) {
            if (interval[0] <= end) {
                end = max(end, interval[1]);
            } else {
                ans.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};
