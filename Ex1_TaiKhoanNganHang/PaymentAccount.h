#pragma once
#include "TaiKhoan.h"
#include "PaymentHistory.h"
class PaymentAccount : public TaiKhoan
{
private:
	double balance; // so du
	string ngayPhatHanh;
	vector<PaymentHistory> historyList;
public:
	PaymentAccount();
	~PaymentAccount();
	void Nhap();

	void setAccount(string);
	void setAmount(double);

	void NapTien();
	double getBalance();
	bool transferTo(double amount);
	void showHistory();
};