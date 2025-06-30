struct item {
    int cnt[3] = {};
};

struct lazyprp {
    int n;
    vector<item> seg;
    vector<int> v, lazy;

    lazyprp(int n) {
        this->n = n;
        seg.resize(4 * n);
        lazy.resize(4 * n, 0);
        v.resize(n, 0);
    }

    item merge(item a, item b) {
        item res;
        for (int i = 0; i < 3; ++i)
            res.cnt[i] = a.cnt[i] + b.cnt[i];
        return res;
    }

    void build(int at, int l, int r) {
        if (l == r) {
            seg[at].cnt[0] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(at * 2 + 1, l, mid);
        build(at * 2 + 2, mid + 1, r);
        seg[at] = merge(seg[at * 2 + 1], seg[at * 2 + 2]);
    }

    void rotate(int at) {
        int temp = seg[at].cnt[2];
        seg[at].cnt[2] = seg[at].cnt[1];
        seg[at].cnt[1] = seg[at].cnt[0];
        seg[at].cnt[0] = temp;
    }

    void prop(int at, int l, int r) {
        int times = lazy[at] % 3;
        for (int i = 0; i < times; ++i) rotate(at);

        if (l != r) {
            lazy[at * 2 + 1] += lazy[at];
            lazy[at * 2 + 2] += lazy[at];
        }
        lazy[at] = 0;
    }

    item get(int st, int en) {
        return get(0, 0, n - 1, st, en);
    }

    item get(int at, int l, int r, int st, int en) {
        prop(at, l, r);
        if (r < st || l > en) return item();

        if (l >= st && r <= en)
            return seg[at];

        int mid = (l + r) / 2;
        item left = get(at * 2 + 1, l, mid, st, en);
        item right = get(at * 2 + 2, mid + 1, r, st, en);
        return merge(left, right);
    }

    void update(int st, int en, int val) {
        update(0, 0, n - 1, st, en, val);
    }

    void update(int at, int l, int r, int st, int en, int val) {
        prop(at, l, r);
        if (r < st || l > en) return;

        if (l >= st && r <= en) {
            lazy[at] += val;
            prop(at, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(at * 2 + 1, l, mid, st, en, val);
        update(at * 2 + 2, mid + 1, r, st, en, val);
        seg[at] = merge(seg[at * 2 + 1], seg[at * 2 + 2]);
    }
};
