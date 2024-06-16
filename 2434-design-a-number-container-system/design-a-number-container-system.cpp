class NumberContainers {
   unordered_map<int,set<int>>m1;
   unordered_map<int,int>m;
   
public:
    NumberContainers() {
    }

   void change(int index, int number) {
        if (m.find(index) != m.end()) {
            int oldNumber = m[index];
            m1[oldNumber].erase(index);
            if (m1[oldNumber].empty()) {
                m1.erase(oldNumber);
            }
        }
        m[index] = number;
        m1[number].insert(index);
    }

    int find(int number) {
        if (m1.find(number) != m1.end() && !m1[number].empty()) {
            return *m1[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */