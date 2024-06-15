class LUPrefix {
public:
   set<int> a;
   int m= 0;
    LUPrefix(int n) {
    
    }
    
    void upload(int video) {
      a.insert(video);
    }
    
    int longest() {
     while(a.find(m+1)!=a.end())
     m++;
     return m;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */