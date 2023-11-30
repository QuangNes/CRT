#include <iostream>
#include <vector>
using namespace std;


long long extended_gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return gcd;
}

long long mod_inverse(long long a, long long mod) {
    long long x, y;
    extended_gcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

long long chinese_remainder_theorem(long long& N, vector<long long> a, vector<long long> m) {
    for (int i = 0; i < m.size(); i++){
        N *= m[i];
    }

    long long result = 0;

    for (int i = 0; i < a.size(); i++) {
        long long M = N / m[i];
        result += a[i] * mod_inverse(M, m[i]) * M;
    }
    return result%N;
}

void input_data(int &k, vector<long long>& a, vector<long long>& m) {
    cout << "Nhap k la so he phuong trinh : ";
    cin >> k;
    int x = 0, y = 0;
    for (int i = 0; i < k; i++) {
        cout << "Nhap a[" << i << "]: ";
        cin >> x;
        cout << "Nhap m[" << i << "]: ";
        cin >> y;
        a.push_back(x);
        m.push_back(y);
        cout << endl;
    }
}
void show_equation(int k, vector<long long> a, vector<long long> m) {
    cout << endl;
    cout << "He phuong trinh dong du" << endl;
    cout << "Trong C++ khong co dau dong du nen em thay bang dau = cho dep" << endl;
    for (int i = 0; i < k; i++) {
        cout << "x = " << a[i] << " (mod " << m[i] << ")" <<endl;
    }
}

int main() {
    int k;
    long long N = 1;
    vector<long long> a ;
    vector<long long> m ;
    input_data(k, a, m);
    show_equation(k, a, m);
    cout << "Solution: x = " << chinese_remainder_theorem(N,a, m) << " (mod " << N << ") " << endl;
    return 0;
}