class Solution {
public:
    string simplifyPath(string path) {
        // Time: O(n), Space: O(n)
        vector<string> dirs;
        for(int i = 0; i < path.size(); i++){
            auto ch = path[i];
            if(ch == '/'){
                auto arg = read_arg(i, path);
                if(arg.empty())
                    continue;
                else if(arg == ".."){
                    if(dirs.size()){
                        dirs.pop_back();
                    }
                } else if(arg != "."){
                    dirs.push_back(arg);
                }
            }
        }

        if(dirs.empty())
            return "/";

        string result;
        for(auto each: dirs)
            result += "/" + each;

        return result;
    }

    string read_arg(int& idx, const string& path){
        idx++;
        if(idx >= path.size())
            return "";

        string result;
        while(idx < path.size() && path[idx] != '/')
            result += path[idx++];
        idx--;
        return result;
    }
};