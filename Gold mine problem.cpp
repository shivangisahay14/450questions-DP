1. Recursive Solution
int maxgoldRec(int r,int c,vector<vector<int>> &M,int n ,int m){
        
        if(c>=m) return 0;
        if(r>=n or r<0) return 0;
        
        int x=maxgoldRec(r,c+1,M,n,m);
        int y=maxgoldRec(r+1,c+1,M,n,m);
        int z=maxgoldRec(r-1,c+1,M,n,m);
        
        return M[r][c]+max({x,y,z});
        
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int maxans=INT_MIN;
        // The max amount of gold collected will be the max
        // value in first column of all rows
          for(int i=0;i<n;i++){
              maxans=max(maxans,maxgoldRec(i,0,M,n,m));
          }
          
          return maxans;
        
    }

2. DP:
int maxGold(int n, int m, vector<vector<int>> M)
    {
        
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        
        for(int j=m-1;j>=0;j--){
            for(int i=0;i<n;i++){
                if(j==m-1){
                    dp[i][j]=M[i][j];
                }
                else if(i==0){
                    dp[i][j]=M[i][j]+max(dp[i][j+1],(i+1<n)?dp[i+1][j+1]:0);
                }
                else if(i==n-1){
                    dp[i][j]=M[i][j]+max(dp[i][j+1],(i-1>=0)?dp[i-1][j+1]:0);
                }
                else{
                dp[i][j]=M[i][j]+max({dp[i][j+1],dp[i-1][j+1],dp[i+1][j+1]});
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i][0]);
        }
        return ans;
