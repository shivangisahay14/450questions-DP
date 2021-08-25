string longestPalindrome(string s) {
        
        int n=s.length();
        string ans;
        bool dp[n][n];
        int start=0;
        int maxLength=1;
        memset(dp,false,  sizeof dp);
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int i=0;i<n-1;i++){
            if (s[i]==s[i+1]){
                dp[i][i+1]=true;
                if(2>maxLength){
                    maxLength=2;
                    start=i;
                }
            }
        }
        for (int k = 3; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (k > maxLength) {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }
        ans=s.substr(start,maxLength);
        return ans;        
    }
