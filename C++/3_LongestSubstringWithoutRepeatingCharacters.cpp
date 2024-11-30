class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> charSet;

        int l = 0;
        int res = 0;

        for (int r=0;r<s.size();r++) {

            while(charSet.count(s[r])) {
                charSet.erase(s[l]);
                l++;
                std::cout << charSet.count(s[r]) << std::endl;
            }

            charSet.insert(s[r]);
            
            std::cout << r << ":" << l << " " << std::endl;

            res = std::max(res, r - l + 1);

        }

        return res;

    }
};

// abc(a)
//  bca(b)

// abc(a)d
//  bcad

// curlength (cur+1,)
// maxlength (max,cur)