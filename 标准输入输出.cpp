#include <iostream>
using namespace std;

//�ж��û����������

void test01()
{
	cout << "please input number or string" << endl;
	//͵��

	//char peek = cin.peek();
	//if (peek >= '0' && peek <= '9')
	//{
	//	int num;
	//	cin >> num;
	//	cout << "�������������"<<num << endl;
	//}
	//else
	//{
	//	char str[1024];
	//	cin >> str;
	//	cout << "����������ַ���" << str << endl;
	//}

	//putback
	char in = cin.get();
	cin.putback(in);
	if (in >= '0' && in <= '9')
	{
		int num;
		cin >> num;
		cout << "�������������" << num << endl;
	}
	else
	{
		char str[1024];
		cin >> str;
		cout << "����������ַ���" << str << endl;
	}

}

//���û�����0-9������

void test02()
{
	int num;

	while (true)
	{
		cin >> num;    //��Ҫint������char�����num�����ƻ�������cin.fial()=1;��Ҫ��ձ�־λ�ͻ��������ܽ�������
		while (cin.fail())
		{
			cin.clear();  //��ձ�־λ
			cin.sync();	  //��ջ�����
			cin.ignore(); //ɾ��һ�������ַ�
			cout << "please input a number again" << endl;
			cin >> num;
		}

		if (num >= 0 && num < 10)
		{
			cout << "input number is" << num << endl;
			break;
		}
		else
		{
			cout << "please input number between 0-9" << endl;
		}
		//cout << "singal char is " << cin.fail() << endl;
		//cin.clear();  //��ձ�־λ
		//cin.ignore(); //��ողŵ�һ���ַ�
		//cin.sync();	  //��ջ�����
		//cout << "singal char is " << cin.fail() << endl;
		//cout << "please input again" << endl;
	}
}

void cintest()
{
	char c = cin.get();
	cout <<"c="<< c << endl;
	c = cin.get();
	cout << "c=" << c << endl;
	char s[20];
	char seek = cin.peek();
	cout << "seek = "<<seek << endl;
	cin.getline(s,20);
	cout << "s=" << s << endl;
	c = cin.get();
	cout << "c=" << c << endl;
	cin.get(s, 20);
	cout << "s=" << s << endl;
	c = cin.get();
	cout << "c=" << c << endl;
	cin.putback(c);

}

int main()
{
	test02();
	system("pause");
	return 0;
}