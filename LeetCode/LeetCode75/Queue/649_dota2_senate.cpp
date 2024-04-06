class Solution {
public:
    string predictPartyVictory(string senate) {
        // Time: O(n), Space: O(n)
        queue<char> voting_queue;
        int dire_count = 0, radiant_count = 0;
        for(auto each: senate){
            voting_queue.push(each);
            dire_count += each == 'D';
            radiant_count += each == 'R';
        }

        int r_power = 0, d_power = 0;

        // start the voting
        while(radiant_count != 0 && dire_count != 0){
            auto senator = voting_queue.front();
            voting_queue.pop();
            if(r_power > 0 && senator == 'D'){
                r_power--;
                dire_count--;
            } else if(d_power > 0 && senator == 'R'){
                d_power--;
                radiant_count--;
            } else if(senator == 'D'){
                d_power++;
                voting_queue.push(senator);
            } else {
                r_power++;
                voting_queue.push(senator);
            }
        }

        return dire_count > 0 ? "Dire" : "Radiant";
    }
};