class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        while (i < words.size()) {
            int cur_width = words[i].size(), j = i + 1;
            while (j < words.size()) {
                if (cur_width + words[j].size() + 1 > maxWidth) {
                    break;
                }
                cur_width += words[j].size() + 1;
                j++;
            }
            string row = words[i];
            int space_cnt = j - i - 1;
            if (space_cnt == 0 || j == words.size()) {
                for (int k = i + 1; k < j; ++k) {
                    row += " " + words[k];
                }
                row += string(maxWidth - row.size(), ' ');
            } else {
                int space_width = (maxWidth - cur_width) / space_cnt;
                int remain_width = (maxWidth - cur_width) % space_cnt;
                for (int k = i + 1; k < j; ++k) {
                    row += string(space_width, ' ');
                    if (remain_width > 0) {
                        row += " ";
                        remain_width--;
                    }
                    row += " " + words[k];
                }
            }
            ans.push_back(row);
            i = j;
        }
        return ans;
    }
};
