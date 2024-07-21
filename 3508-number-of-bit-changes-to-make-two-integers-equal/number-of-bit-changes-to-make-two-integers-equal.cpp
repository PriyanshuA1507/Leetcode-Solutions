class Solution {
public:
    std::string ctb(int number) {
        if (number == 0) return "0";
        std::string binary = "";
        while (number > 0) {
            binary = (number % 2 == 0 ? "0" : "1") + binary;
            number /= 2;
        }
        return binary;
    }

    int minChanges(int n, int k) {
        string a = ctb(n);
        string b = ctb(k);

       
        if (a.size() < b.size()) {
            return -1;
        }
         while (a.length() < b.length()) {
            a = "0" + a;
        }
        while (b.length() < a.length()) {
            b = "0" + b;
        }
        int changes = 0;
        for (int i = 0; i < a.size(); i++) {
            if(b[i]=='1' && a[i]=='0'){
                return -1;
            }
             if(b[i]=='0' && a[i]=='1'){
                changes++;
            }
            
        }
        return changes;
    }
};