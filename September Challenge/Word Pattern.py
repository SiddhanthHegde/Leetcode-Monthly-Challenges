class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        s = str.split()
        my_set = set()
        k = {}   
        if(len(s) != len(pattern)):
            return False
        for count,ele in enumerate(pattern):
            c = k.get(ele)
            flag = s[count] in my_set
            if c == None and not flag:
                k[ele] = s[count]
                my_set.add(s[count])
            elif c != None:
                if c != s[count]:
                    return False
            elif c == None and flag:
                return False
        return True
        
        