import java.util.ArrayList;
import java.util.List;

class Solution {
    static ArrayList<String> padRet(String p, String up) {
        if (up.isEmpty()) {
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }
        
        int digit = up.charAt(0) - '0';  // Convert char to digit (e.g., '2' -> 2)

        ArrayList<String> list = new ArrayList<>();

        // Mapping of digits to their corresponding characters
        String[] mappings = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        // Get the characters corresponding to the current digit
        String chars = mappings[digit];
        for (char ch : chars.toCharArray()) {
            list.addAll(padRet(p + ch, up.substring(1)));
        }
        return list;
    }

    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) {
            return new ArrayList<>();
        }
        return padRet("", digits);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String digits = "8";
        List<String> result = solution.letterCombinations(digits);
        System.out.println(result);
    }
}
