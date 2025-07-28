struct segment {
    int n;
    vector<int> seg, v;

    segment(int n) {
        this->n = n;
        seg.resize(4 * n, 0);
        v.resize(n, 0);
    }

    int merge(int a, int b) {
        return gcd(a,b);
    }

    void build(int at, int l, int r) {
        if (l == r) {
            seg[at] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(at * 2 + 1, l, mid);
        build(at * 2 + 2, mid + 1, r);
        seg[at] = merge(seg[at * 2 + 1], seg[at * 2 + 2]);
    }
  int get(int st,int en){
      return get(0,0,n-1,st,en);
    }
    int get(int at, int l, int r, int st, int en) {
        if (l > en || r < st) {
            return 0;
        }
        if (l >= st && r <= en) {
            return seg[at];
        }
        int mid = (l + r) / 2;
        return merge(get(at * 2 + 1, l, mid, st, en), get(at * 2 + 2, mid + 1, r, st, en));
    }
  void update(int indx,int val){
      update(0,0,n-1,indx,val);
    }
    void update(int at, int l, int r, int indx, int val) {
        if (indx < l || indx > r) {
            return;
        }
        if (l == r) {
            seg[at] = val;
            v[indx] = val;
            return;
        }
        int mid = (l + r) / 2;
        update(at * 2 + 1, l, mid, indx, val);
        update(at * 2 + 2, mid + 1, r, indx, val);
        seg[at] = merge(seg[at * 2 + 1], seg[at * 2 + 2]);
    }
};
