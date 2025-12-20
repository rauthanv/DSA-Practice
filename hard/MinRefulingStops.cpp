// Problem: Minimum Number of Refueling Stops

// Approach:
// Greedy + Max Heap (Priority Queue)


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int dist = startFuel;                
        priority_queue<int> maxfuels;        
        int i = 0;
        int n = stations.size();
        int stopsUsed = 0;

        while (dist < target) {
            // Add all reachable stations to heap
            while (i < n && stations[i][0] <= dist) {
                maxfuels.push(stations[i][1]);
                i++;
            }

            if (maxfuels.empty()) return -1;

            dist += maxfuels.top();
            maxfuels.pop();
            stopsUsed++;
        }
        return stopsUsed;
    }
};
