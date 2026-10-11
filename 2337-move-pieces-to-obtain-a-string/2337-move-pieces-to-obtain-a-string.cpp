class Solution {
public:
    bool canChange(string start, string target) {

        int n = start.size();

        int i = 0;
        int j = 0;

        while (i < n || j < n) {

            // Skip empty spaces in start
            while (i < n && start[i] == '_') {
                i++;
            }

            // Skip empty spaces in target
            while (j < n && target[j] == '_') {
                j++;
            }

            // If one string ends before the other
            if (i == n || j == n) {
                return i == n && j == n;
            }

            // Pieces must be the same
            if (start[i] != target[j]) {
                return false;
            }

            // L can only move left
            if (start[i] == 'L' && i < j) {
                return false;
            }

            // R can only move right
            if (start[i] == 'R' && i > j) {
                return false;
            }

            // Move to next piece
            i++;
            j++;
        }

        return true;
    }
};