class Solution {
    int[] par;

    public int findpar(int u) {
        return par[u] == u ? u : (par[u] = findpar(par[u]));
    }

    public int union_slashes(int p1, int p2) {
        p1 = findpar(p1);
        p2 = findpar(p2);
        if (p1 != p2) {
            par[p1] = Math.min(p1, p2);
            par[p2] = Math.min(p1, p2);
            return 0; 
        }
        return 1;
    }

    public int regionsBySlashes(String[] grid) {
        int n = grid.length;
        int N = n + 1;
        par = new int[N * N];
        for (int i = 0; i < N * N; i++) {
            if (i / N == 0 || i % N == 0 || i / N == N - 1 || i % N == N - 1)
                par[i] = 0;
            else
                par[i] = i;
        }
        int regions = 1;
        for (int r = 0; r < n; r++) {
            String s = grid[r];
            for (int c = 0; c < s.length(); c++) {
                if (s.charAt(c) == '/') 
                    regions += union_slashes(findpar(r* N + c + 1),findpar((r + 1) * N + c));
                else if (s.charAt(c) == '\\') 
                    regions += union_slashes(findpar(r * N + c), findpar((r + 1) * N + c + 1));
                
            }
        }
        return regions;
    }
}