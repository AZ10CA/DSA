class Logger {
    unordered_map<string, int> last_printed;
public:
    Logger() {

    }

    bool shouldPrintMessage(int timestamp, string message) {
        if(last_printed.find(message) == last_printed.end()){
            last_printed[message] = timestamp;
            return true;
        }

        if(timestamp - last_printed[message] < 10)
            return false;

        last_printed[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */