class Solution {
public:
    std::string toBinary(int number) {
        if (number == 0) return "0";
        std::string binary = "";
        while (number > 0) {
            binary = (number % 2 == 0 ? "0" : "1") + binary;
            number /= 2;
        }
        return binary;
    }

    int minChanges(int n, int k) {
        std::string binN = toBinary(n);
        std::string binK = toBinary(k);

      
        while (binN.length() < binK.length()) {
            binN = "0" + binN;
        }
        while (binK.length() < binN.length()) {
            binK = "0" + binK;
        }

        int changes = 0;
        for (size_t i = 0; i < binN.length(); ++i) {
            if (binK[i] == '1' && binN[i] == '0') {
            
                return -1;
            }
            if (binN[i] == '1' && binK[i] == '0') {
                
                changes++;
            }
        }

        return changes;
    }
};
