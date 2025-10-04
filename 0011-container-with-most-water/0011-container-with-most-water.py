class Solution:
    def maxArea(self, height: List[int]) -> int:
        intermediateList = []

        i = 0
        j = len(height) - 1

        decisionList = [0, 0]
        while (i <= j):

            intermediateList.append(min(height[i], height[j]) * (j - i))
            
            if (height[i] < height[j]):
                i += 1
            else:
                j -= 1

        intermediateList.sort()
        return intermediateList[-1]