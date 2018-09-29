class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<pair<bool, size_t>> candidateNonNegativeValues;
        vector<pair<bool, size_t>> candidateNegativeValues;
        for (auto index = 0; index < nums.size(); ++index) {
            auto candidateValue = nums[index];
            if (candidateValue >= 0 && candidateNonNegativeValues.size() > candidateValue && candidateNonNegativeValues[candidateValue].first
                || candidateValue < 0 && candidateNegativeValues.size() > -candidateValue-1 && candidateNegativeValues[-candidateValue-1].first) {
                if (candidateValue << 1 == target) {
                    result.push_back((candidateValue >= 0 ? candidateNonNegativeValues[candidateValue] : candidateNegativeValues[-candidateValue-1]).second);
                    result.push_back(index);
                    return result;
                }
            } else {
                auto otherValue = target - candidateValue;
                if (otherValue >= 0 && candidateNonNegativeValues.size() > otherValue && candidateNonNegativeValues[otherValue].first
                    || otherValue < 0 && candidateNegativeValues.size() > -otherValue-1 && candidateNegativeValues[-otherValue-1].first) {
                    result.push_back((otherValue >= 0 ? candidateNonNegativeValues[otherValue] : candidateNegativeValues[-otherValue-1]).second);
                    result.push_back(index);
                    return result;
                }
            }
            pair<bool, size_t> pairToStore;
            if (candidateValue >= 0 && candidateNonNegativeValues.size() <= candidateValue
                || candidateValue < 0 && candidateNegativeValues.size() <= -candidateValue-1) {
                pairToStore.first = false;
                (candidateValue >= 0 ? candidateNonNegativeValues : candidateNegativeValues).resize(candidateValue >= 0 ? candidateValue+1 : -candidateValue, pairToStore);
            }
            pairToStore.first = true;
            pairToStore.second = index;
            (candidateValue >= 0 ? candidateNonNegativeValues[candidateValue] : candidateNegativeValues[-candidateValue-1]) = pairToStore;
        }
        // not yet sure how to make value null appear in output
        return result;
    }
};
