class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> index;        
        for (int i = 0; i < numbers.size(); i++) {
            auto other_it = index.find(target - numbers[i]);
            if (other_it != index.end()) {
                vector<int> ans = {other_it->second, i + 1};
                return ans;
            }
            index[numbers[i]] = i + 1;
        }
        return vector<int>();               
    }
};
