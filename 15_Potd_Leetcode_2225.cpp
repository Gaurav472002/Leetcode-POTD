class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lost_map;
        int n =matches.size();
        for(int i=0;i<n;i++){
            int loser = matches[i][1];
            lost_map[loser]++;
        }
        vector<int>winners;
        vector<int>oneTimeLooser;
        for(int i=0;i<n;i++){
            int winner =matches[i][0];
            int looser =matches[i][1];
            if(lost_map.find(winner)==lost_map.end()){
                winners.push_back(winner);
                lost_map[winner]=2;
            }
            if(lost_map[looser]==1){
                oneTimeLooser.push_back(looser);
            }
        }
        sort(winners.begin(),winners.end());
        sort(oneTimeLooser.begin(),oneTimeLooser.end());
        return {winners,oneTimeLooser};
    }
};
