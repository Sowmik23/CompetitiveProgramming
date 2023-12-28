class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {


        long long volume = (long long)length*width*height;

        bool bulky = length>=1e4 or width>=1e4 or height>=1e4 or volume>=1e9;
        bool heavy = mass>=100;

        if(bulky and heavy) return "Both";
        else if(!bulky and !heavy) return "Neither";
        else if(bulky and !heavy) return "Bulky";
        else if(!bulky and heavy) return "Heavy";
        return "";
    }
};
