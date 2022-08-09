class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<int, int, int>> pq;
        for (auto &p : points) {
            pq.push({p[0] * p[0] + p[1] * p[1], p[0], p[1]});
            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;
        while (pq.size())
            ans.push_back({get<1>(pq.top()), get<2>(pq.top())}), pq.pop();
        return ans;
    }
};