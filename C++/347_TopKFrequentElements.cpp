using namespace std;
#include <vector>
#include <unordered_map>
#include <priority_queue>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> ht;

        for (auto num:nums) {
            ht[num] += 1;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for (auto& [element, frequency]: ht) {
            minHeap.push({frequency, element});
            if (minHeap.size() > k) minHeap.pop();
        }

        vector<int> ans;

        for (int i=0;i<k;i++) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;        
    }
};