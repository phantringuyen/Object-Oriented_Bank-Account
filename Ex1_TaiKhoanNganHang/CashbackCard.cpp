#include "CashbackCard.h"

CashbackCard::CashbackCard()
{
	cashBackRate = 0;
	currentCashBack = 0;
	balance = 0;
}

CashbackCard::~CashbackCard()
{
	cashBackRate = 0;
	currentCashBack = 0;
}

double CashbackCard::getCurrentCashBack()
{
	return currentCashBack;
}

bool CashbackCard::charge(double amount)
{
	if (amount + balance <= creditLimit) {
		balance += amount;
		currentCashBack = amount * cashBackRate;
		//cout << " Thanh toan thanh cong !";
		return true;
	}
	else {
		//cout << " Thanh toan khong thanh cong !";
		return false;
	}
}

void CashbackCard::redeemCashBack()
{
	balance -= currentCashBack;
	currentCashBack = 0;
	cout << "\n => Hoan tien thanh cong!" << endl;
}

void CashbackCard::Nhap()
{
	cout << "\t -- Nhap thong tin cho tai khoan thanh toan --\n";
	cout << " So tai khoan: ";
	cin.ignore();
	getline(cin, account);

	cout << " Ngay phat hanh: ";
	cin.ignore();
	getline(cin, ngayPhatHanh);

	cout << " CashBackRate: "; cin >> cashBackRate;
}