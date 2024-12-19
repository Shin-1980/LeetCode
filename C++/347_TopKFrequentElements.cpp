class Solution {
public:
    static bool comp(pair<int, int> p1, pair<int, int> p2){

        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }

        return p1.second > p2.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        for(auto num:nums) {
            mp[num]++;
        }

        vector<pair<int, int> > freq_arr(mp.begin(), mp.end());

        sort(freq_arr.begin(), freq_arr.end(), comp);

        vector<int> res;
        for (int i=0;i<k;i++){
            res.push_back(freq_arr[i].first);
        }

        return res;
    }
};
