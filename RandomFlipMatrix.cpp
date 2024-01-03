class Solution {
public:
    Solution(int n, int m) {
        rows = n;
        cols = m;
        flipped.clear();
    }

    vector<int> flip() {
        int totalCells = rows * cols;
        int randIndex = rand() % totalCells;

        while (flipped.find(randIndex)!=flipped.end()) {
            randIndex = rand() % totalCells;
        }
        flipped.insert(randIndex);
        int i = randIndex / cols;
        int j = randIndex % cols;
        return {i, j};
    }

    void reset() {
        flipped.clear();
    }

private:
    int rows;
    int cols;
    set<int> flipped;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
