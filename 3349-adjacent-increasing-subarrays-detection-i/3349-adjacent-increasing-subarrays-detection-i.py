class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        knew = k - 1
        if knew == 0:
            return True
        for j in range(k + 1, len(nums)):
                knew -= 1
            else:
                knew = k - 1
            if knew == 0:
                return True
        return False