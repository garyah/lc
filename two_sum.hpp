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
        
        // figuring largest and smallest values not worth it
        // auto firstLargest = nums[0];
        // auto secondLargest = firstLargest;
        // auto firstSmallest = firstLargest;
        // auto secondSmallest = firstLargest;
        // unordered_map<int, size_t> candidateValues;
        unordered_map<int, vector<size_t>> candidateValues;
        for (auto index = 0; index < nums.size(); ++index) {
            // auto valueToCheck = nums[index];
            // if (valueToCheck > firstLargest) {
            //     secondLargest = firstLargest;
            //     firstLargest = valueToCheck;
            // } else if (valueToCheck > secondLargest) {
            //     secondLargest = valueToCheck;
            // }
            // if (valueToCheck < firstSmallest) {
            //     secondSmallest = firstSmallest;
            //     firstSmallest = valueToCheck;
            // } else if (valueToCheck < secondSmallest) {
            //     secondSmallest = valueToCheck;
            // }
            // if (firstLargest + secondLargest == target
            //    || firstSmallest + secondSmallest == target) {
            //     result.push_back(0);
            //     result.push_back(1);
            //     return result;
            // }
            // filtering values not good idea, given 0 and negative values
            //if (valueToCheck <= target) candidateValues[valueToCheck] = index;
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
                    // auto candidateValueIndex = candidateValues[candidateValue][0];
                    // auto otherValueIndex = otherValueIterator->second[0];
                    // if (candidateValueIndex < otherValueIndex) {
                    //     result.push_back(candidateValueIndex);
                    //     result.push_back(otherValueIndex);
                    // } else {
                    //     result.push_back(otherValueIndex);
                    //     result.push_back(candidateValueIndex);
                    // }
                    result.push_back(candidateValues[candidateValue][0]);
                    result.push_back(otherValueIterator->second[0]);
                    return result;
                }
            } else if (candidateValues[candidateValue].size() > 1) {
                result.push_back(candidateValues[candidateValue][0]);
                result.push_back(candidateValues[candidateValue][1]);
                return result;
            }
            // erasing values already seen not good idea, given repeated values
            // candidateValues.erase(candidateValues.find(candidateValue));
        }
        // not yet sure how to make value null appear in output
        return result;
        
        // scanning in order in unordered map not order of input, so fails when multiple valid pairs
        // while (candidateValues.size() > 0) {
        //     auto candidateValueIterator = candidateValues.begin();
        //     auto candidateValue = candidateValueIterator->first;
        //     auto otherValue = target - candidateValue;
        //     auto otherValueIterator = candidateValues.find(otherValue);
        //     if (otherValueIterator != candidateValues.end()) {
        //         auto candidateValueIndex = candidateValueIterator->second;
        //         auto otherValueIndex = otherValueIterator->second;
        //         if (candidateValueIndex < otherValueIndex) {
        //             result.push_back(candidateValueIndex);
        //             result.push_back(otherValueIndex);
        //         } else {
        //             result.push_back(otherValueIndex);
        //             result.push_back(candidateValueIndex);
        //         }
        //         return result;
        //     }
        //     candidateValues.erase(candidateValueIterator);
        // }
        // return null;
    }
};