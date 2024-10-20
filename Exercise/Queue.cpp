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
        temp = n;//保留n值
        queue<int> timeQueue; // 使用队列来存储时间
        unordered_map<int, int> nationCount; // 使用哈希表来存储国家出现次数
        int count = 0;

        while (n--) {
            cin >> t >> k;
            while (k--) {
                int nation;
                cin >> nation; // 读取国家
                timeQueue.push(t); // 存储时间
                if (nationCount[nation] == 0) {
                    count++; // 如果是新国家，增加计数
                }
                nationCount[nation]++; // 增加国家计数
            }

            while (!timeQueue.empty() && t - timeQueue.front() >= 86400) {
                int expiredNation = timeQueue.front();
                timeQueue.pop();
                if (--nationCount[expiredNation] == 0) {
                    count--; // 如果国家计数为0，减少计数
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