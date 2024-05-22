class Solution {
public:
    bool canShipWithinDays(vector<int>& w, int days, int maxLoad) {
        int dayCount = 1;
        int currentLoad = 0;
        for (int i = 0; i < w.size(); i++) {
            if (currentLoad + w[i] <= maxLoad) {
                currentLoad += w[i];
            } else {
                dayCount++;
                if (dayCount > days || w[i] > maxLoad) {
                    return false;
                }
                currentLoad = w[i];
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& w, int days) {
        int sum = 0;
        int maxWeight = 0;
        for (int i = 0; i < w.size(); i++) {
            sum += w[i];
            if (w[i] > maxWeight) {
                maxWeight = w[i];
            }
        }

        int start = maxWeight;
        int end = sum;
        int answer = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (canShipWithinDays(w, days, mid)) {
                answer = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return answer;
    }
};
