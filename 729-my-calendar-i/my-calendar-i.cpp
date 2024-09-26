class MyCalendar {
public:
   set<pair<int,int>> booking;
    MyCalendar() {
        
    }
    bool book(int start, int end) { 
      auto it = booking.lower_bound({start,end});
      if(it!=booking.end() && it->first<end){
        return false;
      }
      if(it!=booking.begin()){
        auto prevIt = prev(it);
        if(start < prevIt->second) {
                return false;
            }
      }
       booking.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */