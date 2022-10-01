#include "PaymentHistory.h"

PaymentHistory::PaymentHistory()
{
	account_ht = "\0";
	day = "\0";
	nd = "\0";
	money = 0;
}

PaymentHistory::PaymentHistory(string acc, string _day, string _nd, double _money)
{
	account_ht = acc;
	day = _day;
	nd = _nd;
	money = _money;
}

PaymentHistory::PaymentHistory(string acc, double _money)
{
	account_ht = acc;
	money = _money;
}

PaymentHistory::~PaymentHistory()
{
	account_ht.clear();
	account_ht = "\0";
	account_ht.~basic_string();

	day.clear();
	day = "\0";
	day.~basic_string();

	nd.clear();
	nd = "\0";
	nd.~basic_string();

	money = 0;
}

void PaymentHistory::Nhap()
{
	cout << " Nhap so tai khoan huong thu: ";
	cin.ignore();
	getline(cin, account_ht);
	cout << " Nhap ngay giao dich: ";
	getline(cin, day);
	cout << " Nhap noi dung giao dich: ";
	getline(cin, nd);
}

void PaymentHistory::Xuat()
{
	cout << " So tai khoan: " << account_ht << endl;
	cout << " So tien chuyen khoan: " << money << endl;
	cout << " Ngay giao dich: " << day << endl;
	cout << " Noi dung chuyen khoan: " << nd << endl;
}