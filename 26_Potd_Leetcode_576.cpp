class Solution {
public:

    int mod =1e9+7;
    int dp[51][51][51];
    int solve(int m,int n, int maxMove,int i,int j){    

        

        if(i>=m || i<0 || j>=n || j<0) return 1;
        if(maxMove<=0)return  0; // was not able to go out of boundary

        if(dp[i][j][maxMove]!=-1)return dp[i][j][maxMove];
        int res = 0 ;

        res = (res + solve(m, n, maxMove - 1, i + 1, j)) % mod; // move in 4 possible directions
        res = (res + solve(m, n, maxMove - 1, i - 1, j)) % mod; 
        res = (res + solve(m, n, maxMove - 1, i, j + 1)) % mod;
        res = (res + solve(m, n, maxMove - 1, i, j - 1)) % mod;
    
        return dp[i][j][maxMove]=res%mod;

    }



    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow,startColumn) % mod;
    }
};
