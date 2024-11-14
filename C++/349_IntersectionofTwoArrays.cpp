class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        std::sort(nums1.begin(),nums1.end());
        auto it1 = unique(nums1.begin(), nums1.end());
        nums1.erase(it1, nums1.end());

        std::sort(nums2.begin(),nums2.end());
        auto it2 = unique(nums2.begin(), nums2.end());
        nums2.erase(it2, nums2.end());

        int idx1 = 0;
        int idx2 = 0;

        vector<int> res;

        while (idx1 < nums1.size() and idx2 < nums2.size()){
            if (nums1[idx1] == nums2[idx2]) {
                res.push_back(nums1[idx1]);
                idx1++;
                idx2++;
            }
            else if (nums1[idx1] < nums2[idx2]) {
                idx1++;
            }
            else {
                idx2++;
            }
        }

        return res;
        
    }
};


// brute force time: O(N*M) N is the length of nums1, M is the length of num2
// use two hashtables. The purpose of hash table is to remove duplicated elements in each array.
// sort and two pointers