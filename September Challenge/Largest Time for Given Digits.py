class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        
        best = -1
        
        for h1,h2,h3,h4 in permutations(A):
            hours = h1 + 10 * h2
            mins = h3 + 10 * h4
            if 0 <= hours < 24 and 0 <= mins < 59:
                best = max(best,hours * 60 + mins)
                
        h,m = divmod(best,60)
        
        if best == -1:
            return ""
        if h <= 9:
            h = "0" + str(h)
        if m <= 9:
            m = "0" + str(m)
        return str(h) + ":" + str(m)