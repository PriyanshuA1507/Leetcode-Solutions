class Solution {
public:
    using p = pair<int, int>; // Pair to store duration and button ID

    int buttonWithLongestTime(vector<vector<int>>& events) {
        // Variable to track the button with the longest duration
        int maxDuration = events[0][1]; // Initial duration for the first button
        int buttonID = events[0][0];    // Button ID of the first button

        // Iterate through the rest of the events
        for (int i = 1; i < events.size(); i++) {
            int duration = events[i][1] - events[i - 1][1]; // Calculate duration

            // Update if we find a longer duration or if durations are equal and button ID is smaller
            if (duration > maxDuration || (duration == maxDuration && events[i][0] < buttonID)) {
                maxDuration = duration;
                buttonID = events[i][0];
            }
        }

        return buttonID;
    }
};
