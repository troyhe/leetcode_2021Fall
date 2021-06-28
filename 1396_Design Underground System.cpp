class UndergroundSystem {
    unordered_map<int, pair<string, int>> status;
    unordered_map<string, pair<int, int>> time;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        status[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string s = status[id].first + "#" + stationName;
        time[s].first += t - status[id].second;
        time[s].second ++;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s = startStation + "#" + endStation; 
        return  time[s].first / (double) time[s].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
