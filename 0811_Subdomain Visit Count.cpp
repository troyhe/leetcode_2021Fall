class Solution {
    
    vector<string> extractDomains(string address){
        vector<string> domains;
        // domains.push_back(address);
        while (true){
            int i = address.find('.');
            if (i < 0) break;
            domains.push_back(address);
            address = address.substr(i+1);
        }
        domains.push_back(address);
        return domains;
    }
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counter;
        for (int i = 0; i < cpdomains.size(); i++){
            int space = cpdomains[i].find(' ');
            int frequency = stoi(cpdomains[i].substr(0, space));
            string address = cpdomains[i].substr(space+1);
            vector<string> domains = extractDomains(address);
            for (int j = 0; j < domains.size(); j++){
                counter[domains[j]] += frequency;
            }
        }
        vector<string> ans;
        for (auto it: counter){
            string output = to_string(it.second) + " " + it.first;
            ans.push_back(output);
        }
        return ans;
    }
};
