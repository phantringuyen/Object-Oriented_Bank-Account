#pragma once
#include "CreditCard.h"
#include "PaymentAccount.h"
class RewardCard : public CreditCard
{
	double rewardRate;
	double currentPoints;
public:
	RewardCard();
	~RewardCard();
	double getCurrentPoints();
	bool charge(double amount);
	bool payWithPoints(int pAmount);

	void Nhap();
};