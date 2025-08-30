class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        for row in range(9):
            for col in range(9):
                if board[row][col] != '.':
                    if not self.isSafe(board, row, col, board[row][col]):
                        return False
        return True

    def isSafe(self, sudoku: list[list[str]], row: int, col: int, digit: str) -> bool:
        for i in range(9):
            if i != col and sudoku[row][i] == digit:
                return False

        for i in range(9):
            if i != row and sudoku[i][col] == digit:
                return False

        subgridStartRow = (row // 3) * 3
        subgridStartCol = (col // 3) * 3
        for i in range(subgridStartRow, subgridStartRow + 3):
            for j in range(subgridStartCol, subgridStartCol + 3):
                if (i != row or j != col) and sudoku[i][j] == digit:
                    return False

        return True