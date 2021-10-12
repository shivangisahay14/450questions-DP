//The concept is based on the fact that minimum no of deletions will lead to longest palindromic subsequence,
//as no of insertions =no of deletions, therefore no of insertions= s.size()-length of LPS.


 int minInsertions(string s) {
        
        string t =s;
        reverse(t.begin(),t.end());
        
        int m=s.size();
        int n=t.size();
        if(m==0 || n==0)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
    return m-dp[m][n];
        
    }
