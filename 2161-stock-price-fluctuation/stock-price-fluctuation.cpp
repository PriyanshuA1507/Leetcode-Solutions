class StockPrice {
private:
    unordered_map<int, int> timestamp_price;
    int latest_timestamp;
    int latest_price;
    priority_queue<pair<int, int>> max_heap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;

public:
    StockPrice() : latest_timestamp(-1), latest_price(-1) {}

    void update(int timestamp, int price) {
        
        timestamp_price[timestamp] = price;

       
        if (timestamp >= latest_timestamp) {
            latest_timestamp = timestamp;
            latest_price = price;
        }

       
        max_heap.emplace(price, timestamp);
        min_heap.emplace(price, timestamp);
    }

    int current() {
    
        return latest_price;
    }

    int maximum() {
        
        while (!max_heap.empty() && timestamp_price[max_heap.top().second] != max_heap.top().first) {
            max_heap.pop();
        }
        return max_heap.top().first;
    }

    int minimum() {
        
        while (!min_heap.empty() && timestamp_price[min_heap.top().second] != min_heap.top().first) {
            min_heap.pop();
        }
        return min_heap.top().first;
    }
};
