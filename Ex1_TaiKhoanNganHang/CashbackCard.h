#pragma once
#include "CreditCard.h"
#include "PaymentHistory.h"
class CashbackCard : public CreditCard
{
	// cho phép người dùng nhận được số tiền hoàn lại trên mỗi giao dịch
	double cashBackRate;
	double currentCashBack;
public:
	CashbackCard();
	~CashbackCard();
	double getCurrentCashBack();
	bool charge(double amount);
	void redeemCashBack();
	void Nhap();
};