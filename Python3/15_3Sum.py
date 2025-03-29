class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = set()

        for i in range(0, len(nums)-2, 1):
            j = i+1
            k = len(nums)-1
            while j<k:
                sum3 = nums[i] + nums[j] + nums[k]
                if sum3 == 0:
                    ans.add((nums[i],nums[j],nums[k]))
                    k = k-1
                    j = j+1
                elif sum3 > 0:
                    k = k-1
                else:
                    j = j+1

        return list(map(list, ans)) 
        
# sort element in acending order
# i,j,,,,k 
# if sum(i,j,k) is begger than 0 k=k-1
# if not j=j+1
# repeats it untilj==K