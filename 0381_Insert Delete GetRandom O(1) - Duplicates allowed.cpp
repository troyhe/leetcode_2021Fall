class RandomizedCollection {
    unordered_map<int, vector<int>> dic;
    vector<vector<int>> nums;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool present = true;
        if (dic[val].size() != 0) present = false;
        nums.push_back({val, (int)dic[val].size()});
        dic[val].push_back(nums.size() - 1);
        return present;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (dic[val].size() == 0) return false;
        // the idx of the deleted number
        int idx = dic[val].back();
        dic[val].pop_back();
        
        nums[idx] = nums.back();
        dic[nums[idx][0]][nums[idx][1]] = idx;
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int r = rand() % (int) nums.size();
        return nums[r][0];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
