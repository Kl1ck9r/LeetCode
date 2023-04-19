    /*
        Given a valid (IPv4) IP address, return a defanged version of that IP address.
        A defanged IP address replaces every period "." with "[.]".
    */


// #1
class Solution {
public:
    string defangIPaddr(string address) {
        return regex_replace(address, regex("[.]"), "[.]");
    }
};


// #2
class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for (const auto it : address) {
            if (it == '.') {
                result += "[.]";
            }
            else {
                result += it;
            }
        }
        return result;
    }
};

