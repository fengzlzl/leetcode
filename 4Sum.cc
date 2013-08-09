class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector< vector<int> > ans;
        if (num.size() < 4) return ans;
         
        unordered_map<int, int> tot;
        for (int i = 0; i < num.size(); i++)
            tot[num[i]]++;
        vector<int> val;
        for (auto it = tot.begin(); it != tot.end(); it++)
            val.push_back(it->first);
        sort(val.begin(), val.end());
             
        unordered_map<int, vector< pair<int, int> > > pairs;
        for (int i = 0; i < val.size(); i++)
         for (int j = i; j < val.size(); j++)
         {
             if (i == j && tot[val[i]] == 1) continue;
             pairs[val[i] + val[j]].push_back(make_pair(val[i], val[j]));
         }
        for (auto head = pairs.begin(); head != pairs.end(); head++)
        {
            auto tail = pairs.find(target - head->first);
            if (tail == pairs.end()) continue;
            for (auto pi = head->second.begin(); pi != head->second.end(); pi++)
                for (auto pj = tail->second.rbegin(); pj != tail->second.rend(); pj++)
                {
                    if (pi->second > pj->first) break;
                    vector<int> cur = {pi->first, pi->second, pj->first, pj->second};
                    unordered_map<int, int> cnt;
                    bool flag = true;
                    for (int i = 0; i < cur.size(); i++)
                    {
                        cnt[cur[i]]++;
                        if (cnt[cur[i]] > tot[cur[i]]) flag = false;
                    }
                    if (flag) ans.push_back(cur);
                }
        }
        return ans;
    }
};