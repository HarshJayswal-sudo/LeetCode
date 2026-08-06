class Solution(object):
    def getSum(self, a, b):
        MASK = 0xffffffff
        while b!=0:
            carray = ((a&b)<<1)& MASK
            a = (a^b)&MASK
            b = carray
        return a if a< 0x80000000 else ~(a^MASK)
        