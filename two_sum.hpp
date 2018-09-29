class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.size() == 2) {
            if (nums[0] + nums[1] == target) {
                result.push_back(0);
                result.push_back(1);
            }
            return result;
        }
        
        unordered_map<int, size_t> candidateValues;
        for (auto index = 0; index < nums.size(); ++index) {
            auto candidateValue = nums[index];
            auto candidateValueIterator = candidateValues.find(candidateValue);
            if (candidateValueIterator != candidateValues.end()) {
                if (candidateValue << 1 == target) {
                    result.push_back(candidateValueIterator->second);
                    result.push_back(index);
                    return result;
                }
            } else {
                auto otherValue = target - candidateValue;
                auto otherValueIterator = candidateValues.find(otherValue);
                if (otherValueIterator != candidateValues.end()) {
                    result.push_back(otherValueIterator->second);
                    result.push_back(index);
                    return result;
                }
            }
            candidateValues[candidateValue] = index;
        }
        // not yet sure how to make value null appear in output
        return result;
    }
};
