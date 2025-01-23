class Solution:
    def isValid(self, s: str) -> bool:
        mp = {')':'(','}':'{',']':'['}
        st = []

        for c in s:
            if c in mp.values():
                st.append(c)
            elif c in mp.keys():
                if len(st) > 0:
                    ctop = st.pop()
                    if mp[c] != ctop:
                        return False
                else:
                    return False
            else:
                return False
        
        return not st
