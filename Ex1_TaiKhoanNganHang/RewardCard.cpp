#include "RewardCard.h"

RewardCard::RewardCard()
{
	rewardRate = 0;
	currentPoints = 0;
	balance = 0;
}

RewardCard::~RewardCard()
{
	rewardRate = 0;
	currentPoints = 0;
}

double RewardCard::getCurrentPoints()
{
	return currentPoints;
}

bool RewardCard::charge(double amount)
{
	if (amount + balance <= creditLimit) {
		balance += amount;
		currentPoints = amount * rewardRate;
		//Thanh toan thanh cong
		return true;
	}
	else {
		// Thanh toan khong thanh cong 
		return false;
	}
}
bool RewardCard::payWithPoints(int pAmount)
{
	
	if (pAmount > currentPoints)
		return false;
	else {
		currentPoints -= pAmount;
		return true;
	}
}

void RewardCard::Nhap()
{
	cout << "\t -- Nhap thong tin cho tai khoan thanh toan --\n";
	cout << " So tai khoan: ";
	cin.ignore();
	getline(cin, account);

	cout << " Ngay phat hanh: ";
	cin.ignore();
	getline(cin, ngayPhatHanh);

	cout << " rewardRate: "; cin >> rewardRate;
}