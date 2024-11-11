class Solution(object):

    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """

        #print(x,n)
    
        if n == 0:
            return 1
        if n == 1:
            return x
        elif n > 0:
            if n % 2 == 0:
                return self.myPow(x*x, n//2)
            else:
                #print("ok")
                return self.myPow(x*x, n//2) * x
        else:   # -1
            n = n * -1
            if n % 2 == 0:
                return 1.0 / self.myPow(x*x, n//2) 
            else:
                return 1.0 / (self.myPow(x*x, n//2) * x)


# memoization
# 2^10 -> 2^5 * 2^5
# 2^5 -> 2^2 * 2^2 * 2


# 2^-2 1 / 2^2 