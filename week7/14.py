class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        directions = [[1,0],[0,1],[0,-1],[-1,0]]
        Queue = [[sr,sc]]
        initial = image[sr][sc]
        if initial==newColor:
            return image
        while len(Queue) > 0:
            sr,sc = Queue.pop(0)
            image[sr][sc] = newColor
            for i in directions:
                r = i[0] + sr
                c = i[1] + sc
                if r<0 or r>=len(image) or c<0 or c>=len(image[0]):
                    continue
                if image[r][c] == initial:
                    Queue.append([r,c])
        return image
            