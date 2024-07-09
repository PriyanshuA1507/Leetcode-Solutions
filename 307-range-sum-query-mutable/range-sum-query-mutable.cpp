class NumArray {
public:
    class SGT {
    public:
        vector<int> seg;
        SGT(int n) {
            seg.resize(4 * n);
        }
        
        void build(int i, int l, int r, vector<int>& arr) {
            if (l == r) {
                seg[i] = arr[l];
                return;
            }
            int mid = (l + r) / 2;
            build(2 * i + 1, l, mid, arr);
            build(2 * i + 2, mid + 1, r, arr);
            seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
        }
        
        void update(int idx, int val, int i, int l, int r) {
            if (l == r) {
                seg[i] = val;
                return;
            }
            int mid = (l + r) / 2;
            if (idx <= mid) {
                update(idx, val, 2 * i + 1, l, mid);
            } else {
                update(idx, val, 2 * i + 2, mid + 1, r);
            }
            seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
        }
        
        int query(int start, int end, int i, int l, int r) {
            if (l > end || r < start) return 0;
            if (l >= start && r <= end) return seg[i];
            int mid = (l + r) / 2;
            return query(start, end, 2 * i + 1, l, mid) + query(start, end, 2 * i + 2, mid + 1, r);
        }
    };
    
    int n;
    SGT* stree;
    NumArray(vector<int>& nums) {
        n = nums.size();
        stree = new SGT(n);
        stree->build(0, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        stree->update(index, val, 0, 0, n - 1);
    }
    
    int sumRange(int left, int right) {
        return stree->query(left, right, 0, 0, n - 1);
    }
};