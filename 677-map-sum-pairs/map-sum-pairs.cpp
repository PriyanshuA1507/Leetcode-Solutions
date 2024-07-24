class MapSum {
public:
    unordered_map<string,int> m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key]=val;
    }
    
    int sum(string prefix) {
        int totalSum = 0;
        for (const auto& pair : m) {
            if (pair.first.substr(0, prefix.size()) == prefix) {
                totalSum += pair.second;
            }
        }
        return totalSum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */