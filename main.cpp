
#include "libraries.cpp"
using namespace std;

class SegmentTree {
private:
    vi st, A;
    int n;
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L];
        else {
            build(left(p), L, (L + R) / 2);
            build(right(p), ((L + R) / 2) + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }

public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int) A.size();    // copy content for local usage
        st.assign(4 * n, 0);   // create large enough vector of zeroes
        build(1, 0, n - 1);    // recursive build
    }

    int rmq(int p, int L, int R, int i, int j) {   // O(log n)
        if (i > R || j < L)
            return -1;   // current segment outside query range
        if (L >= i && R <= j)
            return st[p];   // inside query range

        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

        if (p1 == -1)
            return p2;   // if we try to access segment outside query
        if (p2 == -1)
            return p1;   // same as above

        return (A[p1] <= A[p2]) ? p1 : p2;   // as in build routine
    }
};

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int n;
    cin >> n;
    vi a(n);
    REP(i, n) cin >> a[i];

    SegmentTree st(a);

    int tc;
    cin >> tc;
    while (tc--) {
        int l, r;
        cin >> l >> r;
        cout << st.rmq(1, 0, n - 1, l - 1, r - 1) << endl;
    }

    return 0;
}
