#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class PaymentHistory
{
	string account_ht;
	string day;
	string nd;
	double money;
public:
	PaymentHistory();
	PaymentHistory(string acc, string _day, string _nd, double _money);
	PaymentHistory(string acc, double _money);
	~PaymentHistory();
	void Nhap();
	virtual void Xuat();
};