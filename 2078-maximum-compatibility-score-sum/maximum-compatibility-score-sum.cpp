class Solution {
public:
    int check(int i, int j, vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int compatibility = 0;
        for (int k = 0; k < students[0].size(); k++) {
            if (students[i][k] == mentors[j][k]) {
                compatibility++;
            }
        }
        return compatibility;
    }
   int findMaxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int>& usedMentors, int studentIndex) {
        if (studentIndex == students.size()) {
            return 0;
        }

        int maxSum = 0;
        for (int mentorIndex = 0; mentorIndex < mentors.size(); mentorIndex++) {
            if (usedMentors[mentorIndex] == 0) {
                usedMentors[mentorIndex] = 1;
                int currentCompatibility = check(studentIndex, mentorIndex, students, mentors);
                int currentSum = currentCompatibility + findMaxCompatibilitySum(students, mentors, usedMentors, studentIndex + 1);
                maxSum = max(maxSum, currentSum);
                usedMentors[mentorIndex] = 0;
            }
        }

        return maxSum;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size();
        vector<int> usedMentors(n, 0);
        return findMaxCompatibilitySum(students, mentors, usedMentors, 0);
    }

};
