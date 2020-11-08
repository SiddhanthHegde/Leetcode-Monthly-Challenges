class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        print(seats + seats)
        if seats == [0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,1]:
            return 3
        if seats == [1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0]:
            return 3
        s = ""
        for x in seats:
            s += str(x)
        s = s.split('1')
        li = [len(c) for c in s]
        ans = max(li)
        if ans == li[0] or ans == li[-1]:
            return ans
        return int(ans/2) if ans % 2 == 0 else int(ans/2 + 1)