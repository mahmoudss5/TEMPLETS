const int N = 5e6 + 5;
const int mod = 1e9 + 7;
const int mod2 = 2e9 + 11;
const int LOG = 20;
const int inf = LONG_LONG_MAX;
const int base = 31;
const int base2 = 37;
int inv, inv2;
vector <int> pw(N), pw2(N);
int power(int b, int p, int m)
{
    b %= m;
    if(p == 0) return 1;
    int res = 1;
    while(p > 0)
    {
        if(p&1) res = (res * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }
    return res;
}

void pre()
{
    inv = power(base, mod-2, mod);
    inv2 = power(base2, mod2-2, mod2);
    pw[0] = pw2[0] = 1;
    for(int i = 1; i < N; i++)
    {
        pw[i] = (pw[i-1] * base) % mod;
        pw2[i] = (pw2[i-1] * base2) % mod2;
    }
}

struct Hashing
{
private:
    int h, h2, len;
    deque <char> dq;
public:
    Hashing()
    {
        h = h2 = len = 0;
        dq.clear();
    }
    int get1()
    {
        return h;
    }
    int get2()
    {
        return h2;
    }
    void push_back(char c)
    {
        //! first hash based
        h = (h * base + (c - 'a')) % mod;
        //! second hash based
        h2 = (h2 * base2 + (c - 'a')) % mod2;
        dq.push_back(c);
        len++;
    }
    void pop_back()
    {
        if(len == 0) return;
        char c = dq.back();
        //! first hash
        h = ((h - (c - 'a') + mod) * inv) % mod;
        //! second hash
        h2 = ((h2 - (c - 'a') + mod2) * inv2) % mod2;
        dq.pop_back();
        len--;
    }
    void push_front(char c)
    {
        //! first hash
        h = (h + (c - 'a') * pw[len]) % mod;
        //! second hash
        h2 = (h2 + (c - 'a') * pw2[len]) % mod2;
        dq.push_front(c);
        len++;
    }
    void pop_front()
    {
        if(len == 0) return;
        char c = dq.front();
        //! first hash
        h = (h - ((c - 'a') * pw[len-1]) % mod + mod) % mod;
        //! second hash
        h2 = (h2 - ((c - 'a') * pw2[len-1]) % mod2 + mod2) % mod2;
        dq.pop_front();
        len--;
    }
}
