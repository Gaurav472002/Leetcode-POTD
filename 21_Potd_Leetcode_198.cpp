class Solution {
public:
    int rob(vector<int>& nums) {
        // bottom up dp
        int n=nums.size();
        vector<int>dp(n+1,0);
        if(n==1)return nums[0];
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            int take =nums[i-1]+dp[i-2];
            int notTake = dp[i-1];
            dp[i]=max(take,notTake);

        }
        return dp[n];
    }
};
