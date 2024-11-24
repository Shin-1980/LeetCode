class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        op = "({["

        for c in s:
            if c in op:
                st.append(c)
            else:
                if len(st) == 0:
                     return False
                else:
                    ref = st.pop()
                    #print(c,ref)
                    if c == ')' and ref != '(':
                        return False
                    elif c == '}' and ref != '{':
                        return False
                    elif c == ']' and ref != '[':
                        return False
        
        if len(st) == 0:
            return True
        
        return False

        
        

# determine if the input string is valid.
# 1. must be closed by the same 
# 2. must be closed in the correct order.
# 3. corresponding open bracket of the same type.
# 1 <= s.length

# (]
# (