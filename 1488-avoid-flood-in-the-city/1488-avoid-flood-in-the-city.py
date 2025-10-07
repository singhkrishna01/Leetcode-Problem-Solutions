class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        n = len(rains)
        q = SortedList()
        cur = defaultdict(int)
        ans = [-1]*n
        for i in range(n):
            if rains[i] > 0:
                if rains[i] not in cur:
                    cur[rains[i]] = i
                    continue

                lastInstance = cur[rains[i]]
                idx = q.bisect_right(lastInstance)
                if idx == len(q):
                    return []
                
                ans[q[idx]] = rains[i]
                del q[idx]

                cur[rains[i]] = i
            else:
                q.add(i)
        
        while q:
            ans[q[0]] = 100000
            del q[0]
        
        return ans