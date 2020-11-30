class Solution {
public:
    // Time: O(mn)
    // Space: O(mn)
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        for (int i = 0; i <= m; ++i)
            dp[i][0] = 1;
        
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        return dp[m][n];
    }
};