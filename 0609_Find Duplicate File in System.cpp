class Solution {
    void storeContent(unordered_map<string, vector<string>>& content2path, string& path){
        string dir;
        stringstream s(path);
        s >> dir;
        string file;
        while (s >> file){
            int beginIdx = file.find('(');
            int endIdx = file.find(')');
            content2path[file.substr(beginIdx + 1, endIdx - beginIdx - 1)].push_back(dir + "/" + file.substr(0, beginIdx));
        }
    }
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> content2path;
        for (int i = 0; i < paths.size(); i++){
            storeContent(content2path, paths[i]);
        }
        vector<vector<string>> ans;
        for (auto it: content2path){
            if (it.second.size() >= 2) ans.push_back(it.second);
        }
        return ans;
    }
};
