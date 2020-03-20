class Solution {   
    int min(int a, int b, int c) {
        if (a <= b && a <= c) return a;
        if (b <= a && b <= c) return b;
        return c;
    }
public:
    //Time: O(nlgn)
    //Space: O(n)
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        //week[i] corresponds to the maximum index j such that the range [i, j-1] can be covered by a 7-day pass bought on the ith day.
        vector<int> week(days.size());
        //month[i] corresponds to the maximum index j such that the range [i, j-1] can be covered by a 30-day pass bought on the ith day.
        vector<int> month(days.size());
        
        //Fills up the tables
        //O(nlgn)
        for (int i = 0; i < days.size(); ++i) {
            week[i] = lower_bound(days.begin() + i, ::min(days.begin() + i + 7, days.end()), 7 + days[i]) - days.begin();
            month[i] = lower_bound(days.begin() + i, ::min(days.begin() + i + 30, days.end()), 30 + days[i]) - days.begin();
        }
        
        //dp(i) corresponds to the minimum amount of money you need to spend to travel all days in range [i, n]
        vector<int> dp(days.size() + 1);
        dp[days.size()] = 0;
        //dp(i) = min(dp(i+1) + costs[0], dp(week[i]) + costs[1], dp(month[i]) + costs[2])
        for (int i = days.size() - 1; i>=0; --i) dp[i] = min(dp[i+1] + costs[0], dp[week[i]] + costs[1], dp[month[i]] + costs[2]);
        
        return dp[0];
    }
};
