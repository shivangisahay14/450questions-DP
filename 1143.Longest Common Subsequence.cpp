Method 1 - (recursive)
 int lcs(string text1, string text2, int n, int m) {
        if(n == 0 || m == 0) return 0;
        else {
            if(text1[n - 1] == text2[m - 1]) return  1 + lcs(text1, text2, n - 1, m - 1);
            else return max(lcs(text1, text2, n, m - 1), lcs(text1, text2, n - 1, m));
        }
        return 0;
    }



Method 2 - (memoization/top-down)
class Solution {
public:
    int** memo;
    int lcs(string text1, string text2, int n, int m) {
        if(memo[n][m] != -1) return memo[n][m];
        if(n == 0 || m == 0) memo[n][m] = 0;
        else {
            if(text1[n - 1] == text2[m - 1]) memo[n][m] = 1 + lcs(text1, text2, n - 1, m - 1);
            else {
                memo[n][m] = max(lcs(text1, text2, n, m - 1), lcs(text1, text2, n - 1, m));
            }
        }
        return memo[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        
        memo = new int*[n+1];
        for(int i = 0; i <= n; i++)
            memo[i] = new int[m+1];
        
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                memo[i][j] = -1;
        
        return lcs(text1, text2, n, m);
    }
};


Method 3 - Bottom-up Approach
int longestCommonSubsequence(string text1, string text2) {
        
        int m=text1.size();
        int n=text2.size();
        if(m==0 || n==0)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
    return dp[m][n];
        
