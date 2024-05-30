#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string swap1(string num) {
        int start  = num.size() - 1;
        int end = num.size() - 2;
        if (end >= 0) {
            swap(num[start], num[end]);
        }
        return num;
    }

    int getMinSwaps(string num, int k) {
        string a = num;
        int ans = 0;
        while (k-- > 0) {
            next_permutation(num.begin(), num.end());
        }

      
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != num[i]) {
                int j = i;
                while (a[j] != num[i]) {
                    ++j;
                }
                while (j > i) {
                    swap(a[j], a[j-1]);
                    --j;
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};
