vector<int> manacher(const string &s) {
    string t = "@";
    for (char c : s)
        t += "#" + string(1, c);
    t += "#$";

    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;

        if (i < right)
            p[i] = min(right - i, p[mirror]);

        while (t[i + p[i] + 1] == t[i - p[i] - 1])
            p[i]++;

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    return p;
}
