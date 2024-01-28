class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int rows= matrix.size();
        int cols = matrix[0].size();

        for(int row=0;row<rows;row++){
            for(int col=1;col<cols;col++){
                matrix[row][col]+=matrix[row][col-1]; // adding the row wise sum
            }
        }

        int ans=0;

        for(int startcol=0;startcol<cols;startcol++){
            for(int j=startcol;j<cols;j++){
                unordered_map<int,int>mp;
                int cumsum=0;
                mp.insert({0,1});

                for(int row=0;row<rows;row++){
                    cumsum+= matrix[row][j]- (startcol>0? matrix[row][startcol-1]:0);

                    if(mp.find(cumsum-target)!=mp.end()){
                        ans+=mp[cumsum-target];
                    }
                    mp[cumsum]++;
                }
            }
        }
        return ans;
    }
};
