#include <iostream>
using namespace std;

//判断用户输入的内容

void test01()
{
	cout << "please input number or string" << endl;
	//偷窥

	//char peek = cin.peek();
	//if (peek >= '0' && peek <= '9')
	//{
	//	int num;
	//	cin >> num;
	//	cout << "您输入的是数字"<<num << endl;
	//}
	//else
	//{
	//	char str[1024];
	//	cin >> str;
	//	cout << "您输入的是字符串" << str << endl;
	//}

	//putback
	char in = cin.get();
	cin.putback(in);
	if (in >= '0' && in <= '9')
	{
		int num;
		cin >> num;
		cout << "您输入的是数字" << num << endl;
	}
	else
	{
		char str[1024];
		cin >> str;
		cout << "您输入的是字符串" << str << endl;
	}

}

//让用户输入0-9的数字

void test02()
{
	int num;

	while (true)
	{
		cin >> num;    //需要int，输入char，会对num产生破环，导致cin.fial()=1;需要清空标志位和缓存区才能接着输入
		while (cin.fail())
		{
			cin.clear();  //清空标志位
			cin.sync();	  //清空缓冲区
			cin.ignore(); //删除一个输入字符
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
		//cin.clear();  //清空标志位
		//cin.ignore(); //清空刚才的一个字符
		//cin.sync();	  //清空缓冲区
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