#include <iostream>
#include <cstring>
using namespace std;
int win[62503];
int w, l;
int main_35()
{
	char s;
	for (int i = 1; cin >> s && s != 'E'; i++)//ѭ�����룬�������ַ�E���� 
	{
		if (s == 'W')win[i] = 1;
		else win[i] = 2;
	}
	for (int i = 1; 1; i++)
	{
		if (win[i] == 1)w++;//ʤ��+1 
		if (win[i] == 2)l++;//����+1 
		if (win[i] == 0)//����0���¼�����������¼����ǰ�ķ����� 
		{
			cout << w << ":" << l << endl << endl;
			break;
		}
		if (w - l >= 2 || l - w >= 2)
			if (w >= 11 || l >= 11)//��˫���ȷ�������2��һ�����������11��� 
			{
				cout << w << ":" << l << endl;
				w = 0;//�ȷ����� 
				l = 0;
			}
	}
	w = 0;
	l = 0;
	for (int i = 1; 1; i++)
	{
		if (win[i] == 1)w++;
		if (win[i] == 2)l++;
		if (win[i] == 0)
		{
			cout << w << ":" << l;
			break;
		}
		if (w - l >= 2 || l - w >= 2)
			if (w >= 21 || l >= 21)//11��Ϊ21 
			{
				cout << w << ":" << l << endl;
				w = 0;
				l = 0;
			}
	}
	return 0;//�����ؽ���  ��(������)��
}