// 535. Encode and Decode TinyURL


class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortCode = "";
        if(longToShort.find(longUrl)==longToShort.end()){
            do {
                for(int i=0;i<6;i++){ //we are making 6 length shortcode
                    shortCode+=salt[rand()%62];
                }
            }
            while(shortToLong.find(shortCode)!=shortToLong.end());

            longToShort[longUrl] = shortCode;
            shortToLong[shortCode] = longUrl;
        }
        else {
            shortCode = longToShort[longUrl];
        }
        return "http://tinyurl.com/"+shortCode;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortUrl.size()!=25) return "";
        string shortCode = shortUrl.substr(19);
        if(shortToLong.find(shortCode)==shortToLong.end()) return "";
        return shortToLong[shortCode];
    }
private:
    unordered_map<string, string> shortToLong, longToShort;
    //total 62 alphaneumeric (0,26,52 idx)
    char salt[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));




class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        longUrlMp[index] = longUrl;
        string tinyUrl = convertIntToShortUrl(index);
        cout<<tinyUrl<<endl;
        index++;
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        long idx = convertUrlToIdx(shortUrl);
        return longUrlMp[idx];
    }
private:
    long index = 1;
    unordered_map<long, string> longUrlMp;
    //total 62 alphaneumeric (0,26,52 idx)
    char salt[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    string convertIntToShortUrl(long n){
        
        string tinyUrl = "";
        while(n){
            tinyUrl+=salt[n%62];
            n/=62;
        }
        return tinyUrl;
    }
    long convertUrlToIdx(string tinyUrl){

        long idx = 0;
        for(int i=tinyUrl.size()-1;i>=0;i--){
            if(tinyUrl[i]>='a' and tinyUrl[i]<='z'){
                idx = idx*62 + tinyUrl[i]-'a';
            }
            else if(tinyUrl[i]>='A' and tinyUrl[i]<='Z'){
                idx = idx*62 + tinyUrl[i]-'A'+26;
            }
            else {
                idx = idx*62 + tinyUrl[i] - '0' + 52;
            }
        }
        return idx;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

//DrawBack of this implementation:
// If same url is encoded it will mapped into different index. So it's a wastage to CPU and memory.