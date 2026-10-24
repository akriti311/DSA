class Solution {
    public:
    int solve(int row, int col,vector<vector<int>> &dp){
        if(row == 0 && col == 0) return 1;
        if(row <0 || col <0) return 0;

        if(dp[row][col] != 0) return dp[row][col];
        int l = solve(row, col-1,dp);
        int up = solve(row-1, col,dp);

        return dp[row][col] = l+up;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i = 0; i<m; i++){
            dp[i][0] = 1;
        }
        for(int i =1; i<n;i++){
            dp[0][i] = 1;
        }

        for(int row = 1; row <m; row++){
            for(int col = 1; col<n;col++){
                int l = dp[row][col-1];
                int up = dp[row-1][col];
                 dp[row][col] = l+up;
            }
        }
        return dp[m-1][n-1];
    }
};
