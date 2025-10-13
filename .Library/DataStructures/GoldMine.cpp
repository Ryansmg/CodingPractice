// Update : 2025-10-11

struct GoldMine {
    long long mx = -3333333333333333333, lmx = -3333333333333333333, rmx = -3333333333333333333, sum = 0; GoldMine() = default;
    GoldMine(long long a, long long la, long long ra, long long s) : mx(a), lmx(la), rmx(ra), sum(s) {}
    explicit GoldMine(long long v) : mx(v), lmx(v), rmx(v), sum(v) {}
    GoldMine operator+(const GoldMine&b) const { return {std::max({mx,b.mx,rmx+b.lmx}),std::max(lmx,sum+b.lmx),std::max(rmx+b.sum,b.rmx),sum+b.sum};}
};
