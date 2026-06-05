#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        queue<string> q;
        vector<vector<string>> graph(26);
        unordered_set<string> vis;

        for (auto str : stickers) {
            sort(str.begin(), str.end());
            for (int i = 0; i < (int)str.size(); i++) {
                if (i == 0 || str[i] != str[i - 1]) {
                    graph[str[i] - 'a'].emplace_back(str);
                }
            }
        }

        sort(target.begin(), target.end());
        q.emplace(target);
        vis.insert(target);
        int level = 1;

        auto nexts = [&](string t, string s) -> string {
            string builder;
            for (int i = 0, j = 0; i < (int)t.size(); ) {
                if (j == (int)s.size()) {
                    builder += t[i++];
                } else {
                    if (t[i] > s[j]) {
                        j++;
                    } else if (t[i] < s[j]) {
                        builder += t[i++];
                    } else {
                        i++; j++;
                    }
                }
            }
            return builder;
        };

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                for (const auto &s : graph[cur[0] - 'a']) {
                    string next = nexts(cur, s);
                    if (next.empty()) return level;
                    sort(next.begin(), next.end());
                    if (vis.insert(next).second) {
                        q.emplace(next);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
