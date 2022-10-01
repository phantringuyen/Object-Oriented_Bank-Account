#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TaiKhoan
{
protected:
	string name;
	string cmnd;
	string phone;
	string email;
	string ngaySinh;

	string account;
	double soDu;

public:
	TaiKhoan();
	TaiKhoan(const TaiKhoan& ns);
	~TaiKhoan();

	string getAccount();
	double getSoDu();

	virtual void Nhap();
	virtual void Xuat();
};