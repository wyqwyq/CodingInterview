class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> m;
        for(int i = 0; i < k && i < matrix.size(); ++i)
            for(int j = 0; j < matrix.size() && (i + 1) * (j + 1) <= k; ++j)
                m.push_back(matrix[i][j]);

        nth_element(m.begin(), m.begin() + k - 1, m.end());
        return *(m.begin() + k - 1);
    }
};