class Solution:
    def minimumSize(self, nums, maxOperations):
        left, right = 1, max(nums)
        ans = right

        while left <= right:
            mid = (left + right) // 2
            ops = 0
            
            if ops <= maxOperations:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return ans