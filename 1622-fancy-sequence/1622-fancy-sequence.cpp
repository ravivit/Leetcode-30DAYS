class Fancy {
public:
    const long MOD = 1e9 + 7;
    vector<long> seq;
    long mul = 1;
    long add = 0;

    long modInverse(long x) {
        long res = 1, p = MOD - 2;
        while(p){
            if(p & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            p >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long inv = modInverse(mul);
        long stored = ((val - add + MOD) % MOD * inv) % MOD;
        seq.push_back(stored);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if(idx >= seq.size()) return -1;
        return (seq[idx] * mul + add) % MOD;
    }
};