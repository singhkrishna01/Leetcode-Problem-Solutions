class Solution {
public:
    // Function to check if the characters in the words can be rearranged
    // to make each word have the same characters in the same frequency.
    bool makeEqual(vector<string>& words) {

        // Array to store the count of each character (initialized to 0).
        vector<int> characterCount(26, 0);

        // Loop through each word in the input vector 'words'.
        for (const string& inputWord : words) {
            // Loop through each character in the current word.
            for (char inputChar : inputWord) {
                // Increment the count of the current character in 'characterCount'.
                characterCount[inputChar - 'a']++;
            }
        }

        // Check if the count of each character is divisible by the total number of words.
        for (int count : characterCount) {
            if (count % words.size() != 0) {
                // If not divisible, characters cannot be rearranged to make all words equal.
                return false;
            }
        }

        // If all characters can be rearranged to make words equal, return true.
        return true;
    }
};