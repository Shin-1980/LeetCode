class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        st = []

        for i in range(len(s)):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                st.append(s[i])
            else:
                if len(st) < 1:
                    return False
                elif s[i] == ')':
                    c = st.pop()
                    if c != '(':
                        return False
                elif s[i] == '}':
                    c = st.pop()
                    if c != '{':
                        return False
                elif s[i] == ']':
                    c = st.pop()
                    if c != '[':
                        return False

        if len(st) == 0:
            return True

        return False    

# utilize three stacks
# push (, {, [
# pop (, {, [   # if the stack is empty, false
# finally the all stacks are empty, true
# if not, false  