class Solution {
public:
    unordered_map<string, string> decoder;
    int counter = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto encoded = "https://tiny.com/" + to_string(counter);
        counter++;
        decoder[encoded] = longUrl;
        return encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decoder[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));