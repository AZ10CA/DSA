class Solution {
public:
    int compress(vector<char>& chars) {
        // Time: O(n), Space: O(1)
        if(chars.size() == 0)
            return 0;

        int writer = 0;
        char prev_ch = chars[0];
        int cnt = 1;

        for(int i = 1; i < chars.size(); i++){
            if(chars[i] == prev_ch)
                cnt++;
            else {
                write(chars, writer, prev_ch, cnt);
                prev_ch = chars[i];
                cnt = 1;
            }
        }

        write(chars, writer, prev_ch, cnt);

        return writer;
    }

    void write(vector<char>& chars, int& writer_idx, char ch, int count){
        string str_count = to_string(count);
        chars[writer_idx++] = ch;
        if(str_count != "1")
            for(auto ch: str_count)
                chars[writer_idx++] = ch;
    }
};