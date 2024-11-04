class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        b1 = 0 # ()
        b2 = 0 # {}
        b3 = 0 # []

        for i in range(len(s)):
            if s[i] == '(':
                b1 += 1
            elif s[i] == ')':
                b1 -= 1
            elif s[i] == '}':
                b2 -= 1
            elif s[i] == '{':
                b2 += 1
            elif s[i] == '[':
                b3 += 1
            elif s[i] == ']':
                b3 -= 1
                
            if b1 < 0 or b2 < 0 or b3 < 0:
                return False
            
        if b1 == 0 and b2 == 0 and b3 == 0:
            return True
        
        return Fase

        

# utilize three stacks
# push (, {, [
# pop (, {, [   # if the stack is empty, false
# finally the all stacks are empty, true
# if not, false  