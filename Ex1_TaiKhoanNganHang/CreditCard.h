#pragma once
#include "TaiKhoan.h"
#include "PaymentHistory.h"
#include "Card.h"
class CreditCard : public TaiKhoan
{
	vector<Card> CardList;
	vector<PaymentHistory> historyList;
protected:
	double creditLimit; // Hạn mức tín dụng
	double interestRate; // Lãi suất
	double latePenalty; // Phí trả chậm
	double balance; // Số dư hiện tại
	double minPayment; // Thanh toán tối thiểu
	string ngayPhatHanh;

public:
	CreditCard();
	~CreditCard();
	double getBalance();
	bool charge(double amount);
	void payment(double amount);
	void showHistory();
	bool releaseCard();

	virtual void Nhap();
	//virtual void Xuat();
};
