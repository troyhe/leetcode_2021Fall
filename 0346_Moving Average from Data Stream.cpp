class MovingAverage {
    deque<int> q;
    double sum;
    int queueSize;
        
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        queueSize = size;
        sum = 0;
    }
    
    double next(int val) {
        sum += val;
        if (q.size() < queueSize){
            q.push_back(val);
        } else {
            q.push_back(val);
            sum -= q.front();
            q.pop_front();
        }
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
