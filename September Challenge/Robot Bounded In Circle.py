class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        direction = 'N'
        left = {'N':'W','S':'E','E':'N','W':'S'}
        right = {'N':'E','S':'W','E':'S','W':'N'}
        
        move = {'N':(0,1),'S':(0,-1),'E':(1,0),'W':(-1,0)}
        x,y = 0,0
        for i in instructions:
            
            if i == 'L':
                direction = left[direction]
            elif i == 'R':
                direction = right[direction]
            else:
                x += move[direction][0]
                y += move[direction][1]
                
        return (x,y) == (0,0) or direction != 'N'
                
        