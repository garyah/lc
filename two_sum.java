import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> candidateValues = new HashMap<>();
        for (int index = 0; index < nums.length; index++) {
            int candidateValue = nums[index];
            int otherValue = target - candidateValue;
            if (candidateValues.containsKey(otherValue)) {
                return new int[] {candidateValues.get(otherValue), index};
            }
            candidateValues.put(candidateValue, index);
        }
        return null;
    }
};
