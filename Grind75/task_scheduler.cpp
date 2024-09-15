struct Task {
    char symbol;
    int frequency;
    int cooldown;

    Task(char symbol, int frequency, int cooldown): symbol(symbol), frequency(frequency), cooldown(cooldown){}
};

struct TaskComparator{
    bool operator()(const Task& first, const Task& second){
        return first.frequency < second.frequency;
    }
};


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Time: O(n), Space: O(1)
        int time = 0;
        priority_queue<Task, std::vector<Task>, TaskComparator> pq;

        unordered_map<char, int> ft;
        for(auto task: tasks)
            ft[task]++;

        for(auto&[symbol, frequency]: ft)
            pq.push(Task(symbol, frequency, 0));

        queue<Task> in_cooldown;
        while(!in_cooldown.empty() || !pq.empty()){
            while(!in_cooldown.empty() && in_cooldown.front().cooldown <= time){
                pq.push(in_cooldown.front());
                in_cooldown.pop();
            }

            if(!pq.empty()){
                if(pq.top().cooldown <= time){
                    auto top = pq.top();
                    pq.pop();
                    top.frequency--;
                    top.cooldown = time + n + 1;

                    if(top.frequency > 0)
                        in_cooldown.push(top);
                }
                time++;
            } else time++;
        }


        return time;
    }

};