class Solution:
    def minimumSum(self, grid: List[List[int]]) -> int:
        configs = []
        m, n = len(grid), len(grid[0])

        def helper(x1, x2, y1, y2, curr=[]):
            if len(curr) > 2:
                return
            if x1 >= m or y1 >= n:
                return
            if len(curr) == 2:
                curr.append((x1, x2, y1, y2))
                configs.append(curr[:])
                curr.pop()
                return

            for i in range(x1 + 1, x2 + 1):
                curr.append((x1, i, y1, y2))
                helper(i, x2, y1, y2)
                curr.pop()

            for j in range(y1 + 1, y2 + 1):
                curr.append((x1, x2, y1, j))
                helper(x1, x2, j, y2)
                curr.pop()

            for i in range(x1 + 1, x2 + 1):
                for j in range(y1 + 1, y2 + 1):
                    curr.append((x1, i, y1, j))
                    curr.append((i, x2, y1, j))
                    helper(0, x2, j, y2)
                    curr.pop()
                    curr.append((x1, i, j, y2))
                    helper(i, x2, 0, y2)
                    curr.pop()
                    curr.pop()

        helper(0, m, 0, n)

        def find(a, b, c, d):

            x1, x2 = a, b - 1

            for i in range(a, b):
                f = 1
                for j in range(c, d):
                    if grid[i][j] == 1:
                        f = 0
                if f == 0:
                    break
                x1 += 1

            for i in range(b - 1, a - 1, -1):
                f = 1
                for j in range(c, d):
                    if grid[i][j] == 1:
                        f = 0
                if f == 0:
                    break
                x2 -= 1

            y1, y2 = c, d - 1

            for i in range(c, d):
                f = 1
                for j in range(a, b):
                    if grid[j][i] == 1:
                        f = 0
                if f == 0:
                    break
                y1 += 1

            for i in range(d - 1, c - 1, -1):
                f = 1
                for j in range(a, b):
                    if grid[j][i] == 1:
                        f = 0
                if f == 0:
                    break
                y2 -= 1

            return (x2 - x1 + 1) * (y2 - y1 + 1)

        mini = float("inf")
        for a, b, c in configs:
            x = (
                find(a[0], a[1], a[2], a[3])
                + find(b[0], b[1], b[2], b[3])
                + find(c[0], c[1], c[2], c[3])
            )
            mini = min(mini, x)

        return mini