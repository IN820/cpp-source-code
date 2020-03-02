//leetcode c++ approach
//https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Cell = tuple<int, int>;
    struct hash {
        size_t operator()(Cell cell) const { auto [i, j] = cell; return i * 123 + j; }
    };
    using Set = unordered_set<Cell, hash>;
    VI spiralOrder(VVI& A, int i = 0, int j = 0, Set seen = {}, VI ans = {}) {
        int M = A.size(),
            N = M == 0 ? 0 : A[0].size();
        int dir = 0; VVI dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // clockwise: (👉, 👇, 👈, 👆)
        while (seen.size() < M * N) {
            if (seen.insert({i, j}).second)
                ans.push_back(A[i][j]);
            auto u = i + dirs[dir][0],
                 v = j + dirs[dir][1];
            if (0 <= u && u < M && 0 <= v && v < N && seen.find({u, v}) == seen.end())
                i = u,
                j = v;
            else if (++dir == dirs.size())
                dir = 0;
        }
        return ans;
    }
};
