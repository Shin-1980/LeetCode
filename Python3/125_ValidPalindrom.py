class Solution:
    def isPalindrome(self, s: str) -> bool:

        newS = ""

        for c in s:
            if ('a' <= c and c <= 'z') or ('0' <= c and c <= '9'):
                newS += c
            elif 'A' <= c and c <= 'Z':
                newS += chr(ord(c) - ord('A') + ord('a'))

        print(newS)

        s = 0
        e = len(newS) - 1

        while s<e:
            if newS[s] != newS[e]:
                return False

            s += 1
            e -= 1

        return True
             
# convert A into a
# remove non-alphnumeric characters
# check if it is palindrome
# time O(N)
# memory O(N)