from bisect import bisect_left, bisect_right

class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        candidates = nums[::] + [ num + k for num in nums ]
        counter = Counter(nums)
        nums.sort()
        result = 1

        for candidate in candidates:
            left = bisect_left(nums, candidate-k)
            right = bisect_right(nums, candidate+k)
            result = max(result, min( right-left, numOperations + counter[candidate] ))
        
        return result