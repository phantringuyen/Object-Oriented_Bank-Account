#include "PaymentAccount.h"

PaymentAccount::PaymentAccount()
{
	balance = 0; 
	soDu = 0;
	ngayPhatHanh = "\0";
}

PaymentAccount::~PaymentAccount()
{
	balance = 0;
	soDu = 0;

	ngayPhatHanh.clear();
	ngayPhatHanh = "\0";
	ngayPhatHanh.~basic_string();
}

void PaymentAccount::Nhap()
{
	cout << "\t -- Nhap thong tin cho tai khoan thanh toan --\n";
	cout << " So tai khoan: ";
	cin.ignore();
	getline(cin, account);

	cout << " Ngay phat hanh: ";
	cin.ignore();
	getline(cin, ngayPhatHanh);

	getBalance();
}

void PaymentAccount::NapTien()
{
	cout << "\n  NAP TIEN\n";
	cout << "Menh gia: 20000";
	cout << "\n          50000";
	cout << "\n          100000";
	cout << "\n          200000";
	cout << "\n          500000";
	int n;
	do {
		cout << "\nChon menh gia ban muon nap: ";cin >> n;
	} while ((n != 20000 && n != 50000 && n != 100000 && n != 200000 && n != 500000) && cout << "Menh gia khong hop le!\n");
	balance += n;
}

double PaymentAccount::getBalance()
{
	cout << "So tien hien tai trong tai khoan quy khach la: " << balance;
	return balance;
}

void PaymentAccount::setAccount(string a)
{
	account = a;
}

void PaymentAccount::setAmount(double am)
{
	soDu = am;
}

bool PaymentAccount::transferTo(double amount)
{
	string account_ht;
	string day;
	string nd;
	double money = 0.0;

	cout << "\n\t -- Thuc hien thanh toan --" << endl;

	cout << " Nhap so tai khoan huong thu: ";
	cin.ignore();
	getline(cin, account_ht);

	cout << " Nhap ngay giao dich: ";
	getline(cin, day);

	cout << " Nhap noi dung giao dich: ";
	getline(cin, nd);

	if (balance >= amount) {
		balance -= amount;
		historyList.push_back(PaymentHistory(account_ht, day, nd, amount));
		return true; // tt thanh cong
	}
	return false; // tt that bai (ko du tien trong tai khoan)
}

void PaymentAccount::showHistory()
{
	cout << "\n\t-- Lich su thanh toan -- \n";
	if (historyList.size() == 0)
		cout << " Ban chua thuc hien thanh toan nao!\n";
	else {
		for (auto& i : historyList)
			i.Xuat();
	}
}