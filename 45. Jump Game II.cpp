int minJumps(int arr[], int n)
{
 
    // Base case: when source and
    // destination are same
    if (n == 1)
        return 0;
 
    // Traverse through all the points
    // reachable from arr[l]
    // Recursively, get the minimum number
    // of jumps needed to reach arr[h] from
    // these reachable points
    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--) {
        if (i + arr[i] >= n - 1) {
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
 
    return res;
}

int jump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=0;
        if (n == 0 || nums[0] == 0) return 0;
        
        for(int i=1;i<n;i++){
            dp[i]=INT_MAX;
            for(int j=0;j<i;j++){
                 if (i <= j + nums[j] && dp[j] != INT_MAX) {
                dp[i] = min(dp[i], dp[j] + 1);
                break;
            }
            }
        }
        return dp[n-1];
        
    }

int minJumps(int arr[], int n){
        
    // The number of jumps needed to
    // reach the starting index is 0
    if (n <= 1)
        return 0;

    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;
        
    int ladder=arr[0]; //maxR
    int stairs=arr[0]; //steps
    int jumps=1;
    
    for(int i=1;i<n;i++){
        
        if(i==n-1){
            return jumps;
        }
        ladder=max(ladder,i+arr[i]);
        
        stairs--;
        
        if(stairs==0){
            jumps++;
            //Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if(i>=ladder) return -1;
            stairs=ladder-i;
        }
        
    }
    return -1;
        
    }
