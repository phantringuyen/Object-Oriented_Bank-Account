#include "CreditCard.h"

CreditCard::CreditCard()
{
	creditLimit = 30000000;
	interestRate = 0;
	latePenalty = 2000000;
	balance = 0;
	minPayment = 0;
}

CreditCard::~CreditCard()
{
	creditLimit = 0;
	interestRate = 0;
	latePenalty = 0;
	balance = 0;
	minPayment = 0;
}

double CreditCard::getBalance()
{
	cout << "So tien hien tai trong tai khoan quy khach la: " << balance;
	return balance;
}

bool CreditCard::charge(double amount)
{
	if (amount + balance <= creditLimit) {
		balance += amount;
		cout << " Thanh toan thanh cong !";

		historyList.push_back(PaymentHistory(account, amount));
		return true;
	}
	else {
		cout << " Thanh toan khong thanh cong !";
		return false;
	}
}

void CreditCard::payment(double amount)
{
	cout << " Lua chon thanh toan:";
	cout << "\n 1. Thanh toan het.";
	cout << "\n 2. Thanh toan so tien toi thieu.";
	cout << "\n Neu khong thanh toan se phai chiu phat !";
	int choice = 0;
	cout << " Nhap lua chon: "; cin >> choice;

	if (choice == 1) {
		balance -= amount;
		cout << "\n Thanh toan thanh cong !";
	}
	else if (choice == 2) {
		minPayment = 0.05 * amount;
		balance -= minPayment;
		cout << "\n Thanh toan thanh cong !";
	}
	else {
		cout << " Ban chap nhan chiu phat 2000000 VND + lai so tien trong ki sao ke nay !" << endl;
		balance -= latePenalty;
		balance -= interestRate;
	}
}

void CreditCard::showHistory()
{
	cout << "\n\t-- Lich su thanh toan -- \n";
	if (historyList.size() == 0)
		cout << " Ban chua thuc hien thanh toan nao!\n";
	else {
		for (auto& i : historyList)
			i.Xuat();
	}
}

void CreditCard::Nhap()
{
	cout << "\t-- Nhap thong tin cho tai khoan thanh toan --\n";
	cout << " So tai khoan: ";
	cin.ignore();
	getline(cin, account);

	do
	{
		cout << " Nhap so tien trong tai khoan: "; cin >> balance;
	} while (balance < creditLimit &&
		cout << " So tien trong tai khoan can lon hon han muc tin dung (30000000 VND)!");


	char ans = 0;
	do 
	{
		if (releaseCard() == false)
			break;
		cout << "\n Tiep tuc tao the ngan hang: "; cin >> ans;
	} while (ans == 'y'|| ans == 'Y');
}

bool CreditCard::releaseCard()
{
	if (CardList.size() < 6)
	{
		long number = 0;
		string day;
		cout << "\n\t--  Nhap --" << endl;
		if (CardList.size() == 0) { // thẻ chính 
			cout << " So the chinh: "; cin >> number;
		}
		else { // thẻ phụ
			cout << " So the phu: "; cin >> number;
		}
		cout << " Ngay phat hanh: ";
		cin.ignore();
		getline(cin, day);
		CardList.push_back(Card(number, day));
		return true;
	}
	else
	{
		cout << " Qua so luong the!" << endl;
		return false;
	}
}