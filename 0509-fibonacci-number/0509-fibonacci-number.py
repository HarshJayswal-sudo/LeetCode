class Solution(object):
    def fib(self, n):
        if n<1:
            return n
        a = 0
        b = 1
        for i in range(2,n+1):
            c = a+b#1
            a = b#1
            b = c#1
        return b

        