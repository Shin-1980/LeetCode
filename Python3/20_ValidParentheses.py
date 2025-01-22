class Solution:
    def isValid(self, s: str) -> bool:
        
        st = []
        mapping = {')':'(', '}':'{', ']':'['}

        for c in s:
            if c in mapping.values():
                st.append(c)
            elif c in mapping:
                if not st or st[-1] != mapping[c]:
                    return False
                st.pop()
            else:
                return False

        return not st
        