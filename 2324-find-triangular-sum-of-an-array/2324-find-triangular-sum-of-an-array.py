class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        return sum([nums[i] * math.comb(len(nums) - 1, i) for i in range(len(nums))]) % 10