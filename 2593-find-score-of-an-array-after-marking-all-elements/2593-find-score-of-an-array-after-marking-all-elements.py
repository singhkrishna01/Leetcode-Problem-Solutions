class Solution:
    def findScore(self, nums: List[int]) -> int:

        score = 0
        n = len(nums)
        stack = [] # monotonic strictly decreasing stack 

        for num in nums:
            if stack and num >= stack[-1]:
                skip = False 
                while stack:
                    add = stack.pop()
                    if not skip:
                        score += add  # Add every other number to our score
                    skip = not skip   # Toggle between adding and skipping
                continue
            stack.append(num)
        skip = False
        while stack:
            add = stack.pop()
            if not skip:
                score += add
            skip = not skip
        
        return score