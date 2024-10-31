class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int n = robot.size(), m = factory.size();
        const long long INF = 1LL<<40;
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(m+1, vector<long long>(101, INF)));

        for (int i=0; i <n; i++) { 
            for (int j=0; j <m; j++) {
                int xR=robot[i], xF=factory[j][0], Capacity=factory[j][1];

                long long otherFactory=(j==0)?INF:dp[i][j-1][0];

                    long long factoryJ=(i==0)?abs(xR-xF):abs(xR-xF)+dp[i-1][j][k+1];
                    dp[i][j][k] = min(otherFactory, factoryJ);
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};
