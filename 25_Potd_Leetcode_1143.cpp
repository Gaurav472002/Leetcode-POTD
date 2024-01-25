class Solution {
public:

   
 // bottom up dp

    int longestCommonSubsequence(string text1, string text2) {
        
        int x =text1.length();
        int y = text2.length();
        vector<vector<int>>dp(x+1,vector<int>(y+1));

        for(int i=0;i<x+1;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<y+1;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]= 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }
};
