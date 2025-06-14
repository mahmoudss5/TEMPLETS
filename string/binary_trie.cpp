struct Node {
    Node* child[2] = {nullptr, nullptr};
    int freq = 0;
};

struct BinaryTrie {
    Node* root = new Node();

    void insert(int x) {
        Node* cur = root;
        cur->freq++;  
        for (int i = 31; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (!cur->child[bit])
                cur->child[bit] = new Node();
            cur = cur->child[bit];
            cur->freq++;
        }
    }

    void erase(int n, int i, Node*& cur) {
        if (cur == nullptr) return;

        if (i >= 0) {
            int idx = (n >> i) & 1;
            erase(n, i - 1, cur->child[idx]);
        }

        cur->freq--;
        if (cur->freq == 0) {
            delete cur;
            cur = nullptr;
        }
    }
    bool exists(int x) {
        Node* cur = root;
        if (!cur || cur->freq == 0) return false;

        for (int i = 31; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (!cur->child[bit] || cur->child[bit]->freq == 0)
                return false;
            cur = cur->child[bit];
        }
        return true;
    }

    int frequency(int x) {
        if (!exists(x)) return 0;
        Node* cur = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (!cur->child[bit]) return 0;
            cur = cur->child[bit];
        }
        return cur ? cur->freq : 0;
    }
};
