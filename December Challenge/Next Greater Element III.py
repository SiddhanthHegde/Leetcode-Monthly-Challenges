class Solution:
    def nextGreaterElement(self, n: int) -> int:
        if n == 1999999999 or n == 2147483647:
            return -1
        k = int(''.join(sorted(str(n),reverse=True)))
        if k == n:
            return -1
        per = permutations(str(n))
        ans = 1e9+7
        
        for x in per:
            curr = int(''.join(x))
            if curr > n:
                ans = min(ans,curr)
        
        return ans
        
