#include "TaiKhoan.h"
string TaiKhoan::getAccount()
{
	return account;
}

double TaiKhoan::getSoDu()
{
	return soDu;
}

TaiKhoan::TaiKhoan()
{
	name = "\0";
	cmnd = "\0";
	phone = "\0";
	email = "\0";
	ngaySinh = "\0";
}
TaiKhoan::TaiKhoan(const TaiKhoan& tk)
{
	name = tk.name;
	cmnd = tk.cmnd;
	phone = tk.phone;
	email = tk.email;
	ngaySinh = tk.ngaySinh;
}
TaiKhoan::~TaiKhoan()
{
	name.clear();
	name = "\0";
	name.~basic_string();

	cmnd.clear();
	cmnd = "\0";
	cmnd.~basic_string();

	phone.clear();
	phone = "\0";
	phone.~basic_string();

	email.clear();
	email = "\0";
	email.~basic_string();

	ngaySinh.clear();
	ngaySinh = "\0";
	ngaySinh.~basic_string();
}
void TaiKhoan::Nhap()
{
	cout << "\t -- Nhap --\n";
	cout << " Ho va ten: ";
	//cin.ignore();
	getline(cin, name);

	cout << " Ngay/thang/nam sinh: ";
	//cin.ignore();
	getline(cin, ngaySinh);

	cout << " Chung minh nhan dan/Can cuoc cong dan: ";
	getline(cin, cmnd);

	cout << " So dien thoai: ";
	getline(cin, phone);

	cout << " Email: ";
	getline(cin, email);
}

void TaiKhoan::Xuat()
{
	cout << "\n\t-- Xac nhan lai thong tin ca nhan --";
	cout << "\n Ho va Ten: " << name;
	cout << "\n Ngay/thang/nam sinh: " << ngaySinh;
	cout << "\n Chung minh nhan dan/Can cuoc cong dan: " << cmnd;
	cout << "\n So dien thoai: " << phone;
	cout << "\n Email: " << email;

	cout << "\n\t -- Cac dieu khoan ngan hang --" << endl;
	cout << " 1. Have the right to use the allowed balance on the account to make lawful and legal payment ordersrate." << endl;
	cout << " 2. To be able to choose to use payment means, servicesand payment utilities suitable to the needs of customers." << endl;
	cout << " 3. To authorize others to use the account in accordance with the law and bank's regulations." << endl;
	cout << " 4. To request bank to execute legal and valid payment orders with information on transactions payment transactions." << endl;
	cout << " 5. To request bank to temporarily lock and close the account when necessary; be sent notice to bank about the arisings." << endl;
}