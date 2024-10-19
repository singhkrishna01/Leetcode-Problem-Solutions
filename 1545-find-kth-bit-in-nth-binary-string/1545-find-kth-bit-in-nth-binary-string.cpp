class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int length = (1 << (n - 1)) - 1;
        if (k == length + 1) return '1';
        
        if (k <= length) {
        } else {
            int mirroredIndex = 2 * length + 2 - k;
            char bit = findKthBit(n - 1, mirroredIndex);
        }
    }
    
    char invert(char bit) {
        return bit == '0' ? '1' : '0';
    }
};