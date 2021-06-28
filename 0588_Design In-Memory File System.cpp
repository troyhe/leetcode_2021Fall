class FileSystem {
    struct FileNode {
        bool isDirectory;
        unordered_map<string, FileNode*> files; // For directory
        string name;
        string content; // For file
        FileNode(string name, bool isDir):name(name), isDirectory(isDir), content(""){}
    };
    FileNode* root;
    vector<string> splitPath(string path){
        vector<string> files;
        int idx;
        while ((idx = path.find('/')) >= 0){
            if (idx > 0) files.push_back(path.substr(0, idx));
            path = path.substr(idx+1);
        }
        if (path.size() > 0) files.push_back(path);
        return files;
    }
    FileNode* findFile(const vector<string>& path, bool isDir = true){
        FileNode* cur = root;
        for (int i = 0; i < path.size(); i++){
            if (cur->files.find(path[i]) == cur->files.end()){
                if (i + 1 == path.size() && !isDir){
                    FileNode* file = new FileNode(path[i], false);
                    cur->files[path[i]] = file;
                } else {
                    FileNode* file = new FileNode(path[i], true);
                    cur->files[path[i]] = file;
                }
            }
            cur = cur->files[path[i]];
        }
        return cur;
    }
public:
    FileSystem() {
        root = new FileNode("root", true);
    }
    
    vector<string> ls(string path) {
        vector<string> pathFile = splitPath(path);
        FileNode* file = findFile(pathFile);
        vector<string> ans;
        if (!file->isDirectory){
            ans.push_back(file->name);
        } else {
            for (auto it: file->files){
                ans.push_back(it.first);
            }
            sort(ans.begin(), ans.end());
        }
        return ans;
    }
    
    void mkdir(string path) {
        vector<string> pathFile = splitPath(path);
        findFile(pathFile);
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> pathFile = splitPath(filePath);
        FileNode* file = findFile(pathFile, false);
        file->content += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> pathFile = splitPath(filePath);
        FileNode* file = findFile(pathFile, true);
        return file->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
