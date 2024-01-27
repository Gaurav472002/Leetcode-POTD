class Solution {
public:
    int kInversePairs(int n, int k) {
        // bottom up dp
        vector<vector<int>>t(n+1,vector<int>(k+1));
        int mod =1e9+7;
        for(int i=0;i<=n;i++){
            t[i][0]=1; // make all the values of 1st col =1;
        }

        for(int i=1;i<=n;i++){
            long long sum=1;
            for(int j=1;j<=k;j++){
                sum+= t[i-1][j];

                if(j>=i){
                    sum-=t[i-1][j-i];
                }
                t[i][j]= sum %mod;
               
            }
        }
        return t[n][k];
    }
};
