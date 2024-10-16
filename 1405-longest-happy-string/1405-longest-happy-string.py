class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        result = ''
        max_heap = []
        if a > 0:
            heappush(max_heap, (-a, 'a'))
        if b > 0:
            heappush(max_heap, (-b, 'b'))
        if c > 0:
            heappush(max_heap, (-c, 'c'))
        while max_heap:
            freq, letter = heappop(max_heap)
            result += letter
            freq += 1
            if freq < 0:
                if len(result) >= 2 and result[-2] == result[-1]:
                    if not max_heap:
                        break
                    next_freq, next_letter = heappop(max_heap)
                    result += next_letter
                    next_freq += 1
                    if next_freq < 0:
                        heappush(max_heap, (next_freq, next_letter))
                heappush(max_heap, (freq, letter))
        return result