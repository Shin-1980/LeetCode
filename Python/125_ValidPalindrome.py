class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        def getChr(c):
            
            unica = ord(c) - ord('a')
            unicA = ord(c) - ord('A')
            unicn = ord(c) - ord('0')

            if -1 < unica < 26:
                return c

            if -1 < unicA < 26:
                return chr(unicA + ord('a'))

            if -1 < unicn < 10:
                return c
            return ''

        idxh = 0        # head
        idxt = len(s) - 1   # tail

        while idxh < idxt:
            c1 = getChr(s[idxh])
            c2 = getChr(s[idxt])

            if c1 != '' and c2 != '':
                if c1 != c2:
                    return False
                else:
                    idxh += 1
                    idxt -= 1
            else:
                if c1 == '':
                    idxh += 1
                else:
                    idxt -= 1

        return True

# Algorithm: two pointers
# check the unicode and get alphanumeric charracters converted to lowercase letters and num (skip other)

