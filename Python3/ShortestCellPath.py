from typing import List

def isPath(grid: List[List[int]], r: int, c: int) -> bool:
    if -1 < r < len(grid) and -1 < c < len(grid[0]) and grid[r][c] == 1:
        grid[r][c] = 2
        return True
    return False

def shortestCellPath(grid: List[List[int]], sr: int, sc: int, tr: int, tc: int) -> int:
    que = []
    l = 0
    pos = [sr,sc,l]
    que.append(pos)
    grid[sr][sc] = 2

    while len(que) > 0:
        cur = que.pop(0)

        if isPath(grid,cur[0]-1,cur[1]):
            npos = [cur[0]-1,cur[1],cur[2]+1]
            if npos[0] == tr and npos[1] == tc: return npos[2]
            que.append(npos)
        if isPath(grid,cur[0]+1,cur[1]):
            npos = [cur[0]+1,cur[1],cur[2]+1]
            if npos[0] == tr and npos[1] == tc: return npos[2]
            que.append(npos)
        if isPath(grid,cur[0],cur[1]-1):
            npos = [cur[0],cur[1]-1,cur[2]+1]
            if npos[0] == tr and npos[1] == tc: return npos[2]
            que.append(npos)
        if isPath(grid,cur[0],cur[1]+1):
            npos = [cur[0],cur[1]+1,cur[2]+1]
            if npos[0] == tr and npos[1] == tc: return npos[2]
            que.append(npos)

        print(grid)

    return -1 
        
	
# debug your code below
grid = [[1, 1, 1, 1], [0, 0, 0, 1], [1, 0, 1, 1]]
sr, sc, tr, tc = 0, 0, 2, 0
print(shortestCellPath(grid, sr, sc, tr, tc))