//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    long long int InternalCount(long long int p[], long long int q[], long long int r[]) {
        Point P(p[0], p[1]);
        Point Q(q[0], q[1]);
        Point R(r[0], r[1]);

        long long int boundary = boundaryPoint(P, Q) + boundaryPoint(Q, R) + boundaryPoint(R, P) + 3;

        long long int area = std::abs(P.x * (Q.y - R.y) + Q.x * (R.y - P.y) + R.x * (P.y - Q.y)) / 2;

        long long int internalPoints = area + 1 - boundary / 2;
        return internalPoints;
    }

private:
    class Point {
    public:
        long long int x, y;
        Point(long long int x, long long int y) : x(x), y(y) {}
    };

    long long int boundaryPoint(Point p, Point q) {
        if (p.x == q.x) return std::abs(p.y - q.y) - 1;
        if (p.y == q.y) return std::abs(p.x - q.x) - 1;
        return gcd(std::abs(p.x - q.x), std::abs(p.y - q.y)) - 1;
    }

    long long int gcd(long long int a, long long int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends