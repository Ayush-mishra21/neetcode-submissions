class Solution {
    List<String> ans = new ArrayList<>();
    Map<Character, String> mp = new HashMap<>();
    void solve(String digits, int ind, String res) {
        if (ind >= digits.length()) {
            if(res.length() == 0)return;
            ans.add(res);
            return;
        }
        String s = mp.get(digits.charAt(ind));
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            String newres = res + ch;
            solve(digits, ind + 1, newres);
        }
    }
    public List<String> letterCombinations(String digits) {
        mp.put('2', "abc");
        mp.put('3', "def");
        mp.put('4', "ghi");
        mp.put('5', "jkl");
        mp.put('6', "mno");
        mp.put('7', "pqrs");
        mp.put('8', "tuv");
        mp.put('9', "wxyz");
        solve(digits, 0, "");
        return ans;
    }
}
