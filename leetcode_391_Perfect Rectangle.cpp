class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> m;
        set<pair<int, int>> s;
        int total_area = 0;
        int cur_area = 0;
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
        for(auto & vec: rectangles){
            cur_area += (vec[3] - vec[1]) * (vec[2] - vec[0]);
            min_x = min(min_x, vec[0]);
            min_y = min(min_y, vec[1]);
            max_x = max(max_x, vec[2]);
            max_y = max(max_y, vec[3]);
            for(int i = 0; i < 4; i += 2){
                for(int j = 1; j < 4; j += 2){
                    m[make_pair(vec[i], vec[j])]++;
                }
            }
        }
        s.insert({min_x, min_y});
        s.insert({min_x, max_y});
        s.insert({max_x, min_y});
        s.insert({max_x, max_y});

        total_area = (max_y - min_y) * (max_x - min_x);
        if(total_area != cur_area)  return false;
        for(auto & item: m){
            if(s.count(item.first)){
                if(item.second != 1)    return false;
            }else{
                if(item.second % 2 != 0)    return false;
            }
        }
        return true;
    }
};