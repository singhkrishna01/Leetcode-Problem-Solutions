class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        prev = 0
        cur = 1
        record = 0

        nums.append(-10**10)

        for i in range(n):
            if nums[i] < nums[i+1]:
                cur += 1
            else:
                record = max(record, cur // 2, min(prev, cur))
                prev = cur
                cur = 1

        return record
        