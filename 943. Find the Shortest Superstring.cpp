class Solution {
        vector<vector<int>> kmp;   // store prev for each string
        vector<vector<int>> edges; // store length of string j - string i

        /*
        res[i]: use binary integer i to represent a index set, every bit indicates the existence of each number, 
        map key is the leading number index, value is the minimum possible value
        */
        vector<std::unordered_map<int, int>> res; 
        vector<int> aux = { 0b1, 0b10, 0b100, 0b1000, 0b10000, 0b100000, 0b1000000, 0b10000000, 0b100000000, 0b1000000000, 0b10000000000, 0b100000000000, 0b1000000000000 };
        vector<std::unordered_map<int, int>> last; // last index correspond to current index to make the value smallest
    public:
        void findKMP(string& s, vector<int>& pre) {
            pre.push_back(-1);
            for (int i = 1; i < s.size(); i++) {
                int j = pre[i - 1];
                while (j != -1 && s[j + 1] != s[i]) {
                    j = pre[j];
                }
                if (s[j + 1] == s[i]) j++;
                pre.push_back(j);
            }
        }

        int get_overlap(int is, string& s, string& d) {
            vector<int>& pre = kmp[is];
            int j = 0;
            for (int i = 0; i < d.size(); i++) {
                if (s[j] != d[i]) {
                    j--;
                    while (j != -1 && s[j + 1] != d[i]) {
                        j = pre[j];
                    }
                    if (s[j + 1] == d[i]) j++;
                }
                j++;
            }
            return j;
        }

        void get_overlap(int i, string& s, int j, string& t) {
            int s2t = get_overlap(j, t, s);
            int t2s = get_overlap(i, s, t);
            edges[i][j] = t.size() - s2t;
            edges[j][i] = s.size() - t2s;
        }

        // for string s, find all min values for all leading position
        void calculate(string& s, int t) {
            int temp;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '1') {
                    int key = t - aux[s.size() - 1 - i];
                    int temp = key;
                    res[t][i] = INT_MAX;
                    for (auto& j : res[key]) {
                        temp = j.second + edges[j.first][i];
                        if (temp < res[t][i]) {
                            res[t][i] = temp;
                            last[t][i] = j.first;
                        }
                    }
                }
            }
        }

        // n is current res ind, s is the tail char
        void get_final_result(string& realres, vector<string>& A, int n, int s) {
            if (n == aux[A.size() - 1 - s]) {
                realres.append(A[s]);
            }
            else {
                get_final_result(realres, A, n - aux[A.size() - 1 - s], last[n][s]);
                realres.append(A[s].substr(A[s].size() - edges[last[n][s]][s]));
            }
        }

        string shortestSuperstring(vector<string>& A) {
            kmp.clear();
            edges.clear();
            res.assign(1 << A.size(), std::unordered_map<int, int>());
            last.assign(1 << A.size(), std::unordered_map<int, int>());
            for (string& s : A) {
                res[aux[A.size() - 1 - kmp.size()]][kmp.size()] = s.size();
                kmp.push_back(vector<int>());
                findKMP(s, kmp.back());
                edges.push_back(vector<int>(A.size(), 0));
            }


            for (int i = 0; i < A.size(); i++) {
                for (int j = i + 1; j < A.size(); j++) {
                    get_overlap(i, A[i], j, A[j]);
                }
            }

            for (int len = 2; len <= A.size(); len++) {
                string s(A.size() - len, '0');
                s.append(len, '1');
                do {
                    int t = std::stoi(s, NULL, 2);
                    calculate(s, t);
                } while (std::next_permutation(s.begin(), s.end()));
            }

            string realres;

            int minvalue = INT_MAX, ind = (1 << A.size()) - 1, minind;

            for (auto& x : res[ind]) {
                if (x.second < minvalue) {
                    minvalue = x.second;
                    minind = x.first;
                }
            }

            get_final_result(realres, A, ind, minind);

            return realres;
        }
    };