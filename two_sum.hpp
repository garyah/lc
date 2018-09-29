class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<pair<bool, size_t>> candidateValues;
        for (auto index = 0; index < nums.size(); ++index) {
            auto candidateValue = nums[index];
            if (candidateValues.size() > candidateValue && candidateValues[candidateValue].first) {
                if (candidateValue << 1 == target) {
                    result.push_back(candidateValues[candidateValue].second);
                    result.push_back(index);
                    return result;
                }
            } else {
                auto otherValue = target - candidateValue;
                if (candidateValues.size() > otherValue && candidateValues[otherValue].first) {
                    result.push_back(candidateValues[otherValue].second);
                    result.push_back(index);
                    return result;
                }
            }
            pair<bool, size_t> pairToStore;
            if (candidateValues.size() <= candidateValue) {
                pairToStore.first = false;
                candidateValues.resize(candidateValue+1, pairToStore);
            }
            pairToStore.first = true;
            pairToStore.second = index;
            candidateValues[candidateValue] = pairToStore;
        }
        // not yet sure how to make value null appear in output
        return result;
    }
};
