class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        heapMin = []
        heapMax = []
        for ind, lis in enumerate(nums):
            element = nums[ind].pop(0)
            heapq.heappush(heapMin, (element,ind))
            heapq.heappush(heapMax, -1*element)
        ans = []
        while 1:
            minE,ind1 = heapq.heappop(heapMin)
            maxE = -1 * heapMax[0]
            if ans == [] :
                ans = [minE,maxE]
            elif maxE-minE < ans[1]-ans[0]:
                ans = [minE,maxE]
            if len(nums[ind1]) > 0:
                element = nums[ind1].pop(0)
                heapq.heappush(heapMin, (element,ind1))
                heapq.heappush(heapMax, -1*element)
            else:
                return ans

