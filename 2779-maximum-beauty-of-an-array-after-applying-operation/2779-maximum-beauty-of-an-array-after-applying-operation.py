class Solution:
    def maximumBeauty(self, a: List[int], k: int) -> int:
        return a.sort() or max(bisect_right(a,v+2*k)-i for i,v in enumerate(a))