#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MOD 1000000007

// ���� i^N % (10^9 + 7)
// mod_exp(i, N, MOD)
long long mod_exp(int base, int exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main_29() {
    int N;
    scanf("%d", &N);
    long long ans = 0; // ��ʼ������Ϊ0
    for (int i = 1; i <= N; i++) {
        long long term = mod_exp(i, N, MOD); // ���� i^N % (10^9 + 7)
        //printf("%lld %lld\n", i, term);
        ans ^= term; // �Խ���������
    }
    printf("%lld\n", ans); // ������ս��
    printf("%d", ans + MOD);
    return 0;
}
