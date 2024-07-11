class RangeFreqQuery {
public:
    class SGT {
    public:
        vector<map<int, int>> seg;
        SGT(int n) {
            seg.resize(4 * n);
        }
        
        void build(int i, int l, int r, vector<int>& arr) {
            if (l == r) {
                seg[i][arr[l]]++;
                return;
            }
            int mid = l + (r - l) / 2;
            build(2 * i + 1, l, mid, arr);
            build(2 * i + 2, mid + 1, r, arr);
            seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
        }
        
        map<int, int> merge(map<int, int>& left, map<int, int>& right) {
            map<int, int> result = left;
            for (auto& [key, value] : right) {
                result[key] += value;
            }
            return result;
        }

        int query(int start, int end, int i, int l, int r, int value) {
            if (l > end || r < start) return 0;
            if (l >= start && r <= end) return seg[i][value];
            int mid = l + (r - l) / 2;
            return query(start, end, 2 * i + 1, l, mid, value) + query(start, end, 2 * i + 2, mid + 1, r, value);
        }
    };

    int n;
    SGT* stree;

    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        stree = new SGT(n);
        stree->build(0, 0, n - 1, arr);
    }

    int query(int left, int right, int value) {
        return stree->query(left, right, 0, 0, n - 1, value);
    }
};


/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */