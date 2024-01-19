class Solution {
public:

    int n;

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        n=matrix.size();
        vector<vector<int>>temp(n,vector<int>(n,0));

        for(int col=0;col<n;col++){
            temp[0][col]=matrix[0][col]; // initialize the first row
        }

        for(int row=1;row<n;row++){
            for(int col=0;col<n;col++){

                // fetch the result from 3 possible directions

                //temp[row-1][col-1] left diagonal
                //temp[row-1][col+1] right diagnoal
                // temp[row-1][col] // just upper value
                // here col -1 and col +1 can go out of bound because
                // if col is 0 then -1 index
                // if col is n-1 then col+1 will be nth index

                int a=INT_MAX;
                int b =INT_MAX;
                int c=temp[row-1][col]; // no danger in this one
                if(col-1>=0){
                    a=temp[row-1][col-1];
                }
                if(col+1<n){
                    b=temp[row-1][col+1];
                }
                

                temp[row][col]= matrix[row][col]+min({a,b,c});
            }
        }

        // fetch the minimum result from the last row
        int ans =INT_MAX;
        int lastrow=n-1;
        for(int col=0;col<n;col++){
            ans = min(ans,temp[lastrow][col]);
        }
        return ans;
    }
};
