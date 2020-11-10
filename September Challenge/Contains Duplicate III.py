class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        n = len(nums)
        
        if t == 0 and n == len(set(nums)):
            return False
        
        for idx,val in enumerate(nums):
            for j in range(idx + 1,min(idx+1+k,n)):
                if abs(val - nums[j]) <= t:
                    return True
        return False
        