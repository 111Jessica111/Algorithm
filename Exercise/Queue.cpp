#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int result[100005];
    int n, t, k;
    int temp;
    int i = 0;
    while (cin >> n) {
        temp = n;//����nֵ
        queue<int> timeQueue; // ʹ�ö������洢ʱ��
        unordered_map<int, int> nationCount; // ʹ�ù�ϣ�����洢���ҳ��ִ���
        int count = 0;

        while (n--) {
            cin >> t >> k;
            while (k--) {
                int nation;
                cin >> nation; // ��ȡ����
                timeQueue.push(t); // �洢ʱ��
                if (nationCount[nation] == 0) {
                    count++; // ������¹��ң����Ӽ���
                }
                nationCount[nation]++; // ���ӹ��Ҽ���
            }

            while (!timeQueue.empty() && t - timeQueue.front() >= 86400) {
                int expiredNation = timeQueue.front();
                timeQueue.pop();
                if (--nationCount[expiredNation] == 0) {
                    count--; // ������Ҽ���Ϊ0�����ټ���
                }
            }
            result[++i] = count;
        }
        break;
    }    
    for (i = 1; i <= temp; i++) {
        cout << result[i] << endl;
    }
    return 0;
}