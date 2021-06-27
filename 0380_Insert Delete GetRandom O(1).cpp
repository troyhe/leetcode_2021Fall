class RandomizedSet {
    // < val, index>
    unordered_map<int, int> dic;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (dic.find(val) != dic.end()) return false;
        nums.push_back(val);
        dic[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (dic.find(val) == dic.end()) return false;
        if (dic[val] == nums.size() - 1){
            nums.pop_back();
            dic.erase(val);
        } else {
            nums[dic[val]] = nums[nums.size() - 1];
            nums.pop_back();
            dic[nums[dic[val]]] = dic[val];
            dic.erase(val);
        }
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % (int) nums.size();
        return nums[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
