class MyCalendar {
public:
   set<pair<int,int>> booking;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) { 
       for(auto it: booking){
        if(max(it.first,start)<min(it.second,end)){
            return false;
        }
       }
       booking.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */