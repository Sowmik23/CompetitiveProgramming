class Solution {
public:
    string intToRoman(int num) {
        string ones[]  = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
        string thousands[]  = {"", "M", "MM", "MMM"}; //as limit 3999

        return thousands[num/1000]+hundreds[(num%1000)/100]+tens[(num%100)/10]+ones[(num%10)];
    }
};
