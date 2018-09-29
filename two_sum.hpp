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
        
        unordered_map<int, vector<size_t>> candidateValues;
        for (auto index = 0; index < nums.size(); ++index) {
            auto valueToStore = nums[index];
            if (candidateValues.find(valueToStore) == candidateValues.end()) {
                vector<size_t> indexesOfValue;
                candidateValues[valueToStore] = indexesOfValue;
            }
            candidateValues[valueToStore].push_back(index);
        }

        for (auto numsIterator = nums.cbegin(); numsIterator != nums.cend(); ++numsIterator) {
            auto candidateValue = *numsIterator;
            auto otherValue = target - candidateValue;
            if (candidateValue != otherValue) {
                auto otherValueIterator = candidateValues.find(otherValue);
                if (otherValueIterator != candidateValues.end()) {
                    result.push_back(candidateValues[candidateValue][0]);
                    result.push_back(otherValueIterator->second[0]);
                    return result;
                }
            } else if (candidateValues[candidateValue].size() > 1) {
                result.push_back(candidateValues[candidateValue][0]);
                result.push_back(candidateValues[candidateValue][1]);
                return result;
            }
        }
        // not yet sure how to make value null appear in output
        return result;
    }
};
