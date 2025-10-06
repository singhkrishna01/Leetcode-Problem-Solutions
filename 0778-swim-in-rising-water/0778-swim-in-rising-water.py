class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        DIRS = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        visited = set([(0, 0)])
        heap = [(grid[0][0], 0, 0)]
        t = 0

        while heap:
            if heap[0][0] > t:
                t = heap[0][0]
            _, i, j = heappop(heap)
            if i == len(grid) - 1 and j == len(grid[0]) - 1:
                return t
            
            for di, dj in DIRS:
                if (i + di, j + dj) not in visited and 0 <= i + di < len(grid) and 0 <= j + dj < len(grid[0]):
                    visited.add((i + di, j + dj))
                    heappush(heap, (grid[i + di][j + dj], i + di, j + dj))
        