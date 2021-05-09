// TC: O(n^2)
    int dpSol(vector<int> &nums) {
        vector<int> lis(nums.size(), 1);
        int max_len = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            // check the LIS of numbers before current
            // with which current number can be added
            for(int j = 0; j < i; j++) {
                // if LIS ending with jth number can create a longer LIS
                if(nums[j] < nums[i] && lis[j] + 1 > lis[i])
                    lis[i] = lis[j] + 1;
                max_len = max(max_len, lis[i]);
            }
        }
        return max_len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // return dpSol(nums);
        return bSearchSol(nums);
    }
};

BINARY SEARCH:
 int n=nums.size();
        
        vector<int>lis;
        lis.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            // need to find right position for nums[i]in lis
            int ind=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin(); 
            if(ind==lis.size())
            {
                lis.push_back(nums[i]);
            }
            else
            {
                lis[ind]=nums[i];
            }
            
        }
        return lis.size();
        
