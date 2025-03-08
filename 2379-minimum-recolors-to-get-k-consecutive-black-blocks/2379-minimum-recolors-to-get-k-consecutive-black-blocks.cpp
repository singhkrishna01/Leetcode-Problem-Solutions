class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int White = 0, ans = INT_MAX;
        int n = blocks.size();
        int i = 0, j = 0;

        for (j = 0; j < k; j++) {
            if (blocks[j] == 'W') 
                White++;
        }
        ans = min(ans, White);
        while (j < n) {
            if (blocks[i] == 'W') 
                White--;
            if (blocks[j] == 'W') 
                White++;
            
            ans = min(ans, White);
            i++, j++;
        }

        return ans;
    }
};