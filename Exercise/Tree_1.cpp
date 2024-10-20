#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getMax(std::vector<int> a, int i, int j) {
    int x, max = 0;
    for (x = i; x <= j; x++) {
        max = a[x] > a[max] ? x : max;
    }
    return max;
}

int main() {
    int i;
    int n;
    int mid;
    int x, y, num;
    cin >> n;
    num = pow(2, n);
    std::vector<int> a(num + 1);
    for (int i = 1; i <= num; i++) {
        cin >> a[i];
    }
    mid = num / 2;
    x = getMax(a, 1, mid);
    y = getMax(a, mid + 1, num);
    x = a[x] < a[y] ? x : y;
    cout << x << endl;
    return 0;
}