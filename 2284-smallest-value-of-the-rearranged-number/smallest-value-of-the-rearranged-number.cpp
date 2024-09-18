class Solution {
public:
    long long smallestNumber(long long num) {
       
        std::string str = std::to_string(num);
        std::vector<int> digits;
        bool negative = false;

      
        if (str[0] == '-') {
            negative = true;
            str = str.substr(1); 
        }

        for (char ch : str) {
            digits.push_back(ch - '0');
        }

        std::sort(digits.begin(), digits.end());

        std::string ans;
        if (!negative) {
            if (digits[0] == 0) {
                auto first_non_zero = std::find_if(digits.begin(), digits.end(), [](int d) { return d != 0; });
                if (first_non_zero != digits.end()) {
                    ans.push_back('0' + *first_non_zero);
                    digits.erase(first_non_zero);
                }
            }

            for (int digit : digits) {
                ans.push_back('0' + digit);
            }
        } else {
            for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
                ans.push_back('0' + *it);
            }
            ans = '-' + ans;
        }

        std::stringstream ss(ans);
        long long number;
        ss >> number;

        return number;
    }
};