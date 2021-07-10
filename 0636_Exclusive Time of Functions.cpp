class Solution {
    vector<int> extractInfo(string& log){
        vector<int> ans(3, 0);
        int idx = log.find(":");
        ans[0] = stoi(log.substr(0, idx));
        log = log.substr(idx+1);
        idx = log.find(":");
        if (log.substr(0, idx) == "end") ans[1] = 1;
        ans[2] = stoi(log.substr(idx+1));
        return ans;
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> time(n, 0);
        stack<int> functions;
        int currentFun = -1;
        int start = 0;
        for (int i = 0; i < logs.size(); i++){
            vector<int> info = extractInfo(logs[i]);
            if (info[1] == 1){
                time[currentFun] += info[2] - start + 1;
                currentFun = -1;
                if (!functions.empty()){
                    currentFun = functions.top();
                    functions.pop();
                    start = info[2] + 1;
                }
            } else {
                if (currentFun != -1){
                    time[currentFun] += info[2] - start;
                    functions.push(currentFun);
                }
                currentFun = info[0];
                start = info[2];
            }
        }
        return time;
    }
};
