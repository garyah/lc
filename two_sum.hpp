class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, size_t> candidateValues;
        for (auto index = 0; index < nums.size(); ++index) {
            auto candidateValue = nums[index];
            auto otherValue = target - candidateValue;
            auto otherValueIterator = candidateValues.find(otherValue);
            if (otherValueIterator != candidateValues.end()) {
                return {otherValueIterator->second, index};
            }
            candidateValues[candidateValue] = index;
        }
        return {};
    }
};
