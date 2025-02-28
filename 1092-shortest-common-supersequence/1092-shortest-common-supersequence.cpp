class Solution {
public:
    //******nvdpsaluja******
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();

        // dp[i][j] denotes the length of the longest common subsequence (LCS) 
        // of substrings str1[0...i-1] and str2[0...j-1]
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Fill the dp table using bottom-up approach (LCS calculation)
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    // If characters match, increment LCS length
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // Otherwise, take the maximum from previous computations
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // 'str' will store the shortest common supersequence
        string str;
        int i = n1, j = n2;

        // Backtracking to construct the shortest common supersequence
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                // If characters match, include them in the result and move diagonally
                str.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                // If the value comes from dp[i-1][j], include str1[i-1]
                str.push_back(str1[i - 1]);
                i--;
            } else {
                // Otherwise, include str2[j-1]
                str.push_back(str2[j - 1]);
                j--;
            }
        }

        // Add remaining characters of str1 (if any)
        while (i > 0) {
            str.push_back(str1[i - 1]);
            i--;
        }
        
        // Add remaining characters of str2 (if any)
        while (j > 0) {
            str.push_back(str2[j - 1]);
            j--;
        }

        // Since we built the result string in reverse order, reverse it
        reverse(str.begin(), str.end());
        return str;
    }
};
