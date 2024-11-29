class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1

        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        m, n = len(grid), len(grid[0])

        minhpq = [(0, 0, 0)]       
        visited = {(0, 0)}         

        while minhpq:
            time, i, j = heappop(minhpq)

            if i == m - 1 and j == n - 1:
                return time

            for di, dj in dirs:
                di, dj = i + di, j + dj
                
                if di < 0 or di >= m or dj < 0 or dj >= n or (di, dj) in visited:
                    continue

                wait = 1 if (grid[di][dj] - time) % 2 == 0 else 0

                next_time = max(time + 1, grid[di][dj] + wait)

                heappush(minhpq, (next_time, di, dj))
                visited.add((di, dj))

        return -1