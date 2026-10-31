class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>>mp;
    int just=-1;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
        just=timestamp;
    }
    
    string get(string key, int timestamp) {
        if(mp[key].find(timestamp)!=mp[key].end())return mp[key][timestamp];
        else if(just!=-1) return mp[key][just];
        else return "";
    }
};
