class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        
        res = []

        for i in range(len(emails)):
            em = ""
            j = 0
            while emails[i][j] != '@':
                if emails[i][j] == '+':
                    while emails[i][j+1] != '@':
                        j += 1
                elif emails[i][j] != '.':
                    em = em + emails[i][j]
                j += 1
            
            em = em + emails[i][j:]

            k = 0
            while k < len(res): 
                if em == res[k]:
                    break
                k += 1

            if k == len(res):
                res.append(em)

        print(res)
        return len(res)


# case
# .: skip
# +: skip until @
# @: copy until tail