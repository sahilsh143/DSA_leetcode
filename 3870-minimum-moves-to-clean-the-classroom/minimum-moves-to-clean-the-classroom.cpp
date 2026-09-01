class Solution {
public:
    struct State {
        int r;
        int c;
        int energy;
        int mask;
        int dist;
    };

    int minMoves(vector<string>& classroom, int energy) {
        
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int litterCount = 0;

        // Give every litter an ID
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // If there is no litter
        if (litterCount == 0)
            return 0;

        // Example:
        // 3 litter -> 111 -> 7
        int allMask = (1 << litterCount) - 1;

        /*
            best[r][c][mask] = maximum energy
            with which we have reached (r,c)
            after collecting 'mask' litter.
        */
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << litterCount, -1)
            )
        );

        queue<State> q;

        // Initially:
        // position = S
        // energy = maximum energy
        // mask = 0
        // distance = 0
        q.push({sr, sc, energy, 0, 0});

        best[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            State cur = q.front();
            q.pop();

            int r = cur.r;
            int c = cur.c;
            int e = cur.energy;
            int mask = cur.mask;
            int dist = cur.dist;

            // Collected all litter
            if (mask == allMask) {
                return dist;
            }

            // No energy -> cannot move
            if (e == 0)
                continue;

            // Try all 4 directions
            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                // Outside grid
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Obstacle
                if (classroom[nr][nc] == 'X')
                    continue;

                // Moving costs 1 energy
                int newEnergy = e - 1;

                // New mask
                int newMask = mask;

                // If we found litter
                if (classroom[nr][nc] == 'L') {
                    int litterId = id[nr][nc];
                    newMask = mask | (1 << litterId);
                }

                // Reset energy at R
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                /*
                    If we have already reached this
                    position + mask with MORE energy,
                    there is no reason to visit again.
                */
                if (newEnergy > best[nr][nc][newMask]) {

                    best[nr][nc][newMask] = newEnergy;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask,
                        dist + 1
                    });
                }
            }
        }

        // Impossible to collect all litter
        return -1;
    }
};