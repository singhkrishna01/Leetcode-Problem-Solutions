class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        res = [words[0]]
        
        for i in range(1, len(words)):
            freq1 = [0] * 26
            freq2 = [0] * 26
            
            for ch in res[-1]:
                freq1[ord(ch) - ord('a')] += 1
            for ch in words[i]:
                freq2[ord(ch) - ord('a')] += 1
            
            if freq1 != freq2:
                res.append(words[i])
        
        return res