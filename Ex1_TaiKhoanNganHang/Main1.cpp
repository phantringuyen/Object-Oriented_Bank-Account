#include "CashbackCard.h"
#include "CreditCard.h"
#include "PaymentAccount.h"
#include "RewardCard.h"
#include "TaiKhoan.h"

int main()
{
	cout << " Tao tai khoan" << endl;

	TaiKhoan acc;
	bool menu = 1;
	while (menu)
	{
		acc.Nhap();
		acc.Xuat();
		menu = 0;
		cout << "\n 1. Tai khoan thanh toan.";
		cout << "\n 2. Tai khoan the tin dung.";
		cout << "\n 3. Tai khoan the tich diem.";
		cout << "\n 4. Tai khoan the hoan tien.";

		int ans = 0;
		cout << "\n => Hay chon loai tai khoan can tao: "; cin >> ans;
		if (ans == 1) //Tai khoan thanh toan
		{
			PaymentAccount pa;
			pa.Nhap();

			pa.NapTien();
			pa.getBalance(); // xuat ra so tien trong tai khoan

			cout << "\n\tThuc hien giao dich ";

			double money = 0;
			cout << "\n Nhap so tien giao dich: "; cin >> money;
			if (pa.transferTo(money) == true)
				cout << " => Chuyen khoan thanh cong !" << endl;
			else 
				cout << " => Chuyen khoan khong thanh cong. Hay kiem tra lai so du trong tai khoan !" << endl;
	
			pa.showHistory();

		}
		else if (ans == 2) // Tai khoan the tin dung
		{
			cout << "\n Can han muc 30000000 VND de mo tai khoan nay!";

			CreditCard cc;
			cc.Nhap();
			cc.getBalance();
			cout << "\n\tThuc hien giao dich ";
			double money = 0;
			cout << "\n Nhap so tien giao dich: "; cin >> money;
			if (cc.charge(money) == true)
				cout << " => Thanh toan thanh cong !" << endl;
			else
				cout << " => Thanh toan khong thanh cong. Hay kiem tra lai so du trong tai khoan !" << endl;

			cc.showHistory();

			cout << "\n\t-- Den han thanh toan --";
			cc.payment(money);

			cc.getBalance();
		}
		else if (ans == 3) // Tai khoan the tich diem
		{
			RewardCard rc;
			cout << "\n Mo tai khoan the tich diem";
			cout << " So diem hien tai trong tai khoan: ";
			rc.getCurrentPoints();

			rc.Nhap();
			double money = 0;
			cout << " Nhap so tien giao dich: "; cin >> money;
			if (rc.charge(money) == true)
				cout << " => Thanh toan thanh cong !" << endl;
			else
				cout << " => Thanh toan khong thanh cong. Hay kiem tra lai so du trong tai khoan !" << endl;
			/*-----------------------------------------*/
			cout << " So diem hien tai trong tai khoan: ";
			rc.getCurrentPoints();

			cout << "\n -- Thanh toan bang diem --";
			int point = 0;
			cout << " Nhap so diem can thanh toan"; cin >> point;
			if (rc.payWithPoints(point) == true)
				cout << " => Thanh toan thanh cong !" << endl;
			else
				cout << " => Thanh toan khong thanh cong. Hay kiem tra lai so diem trong tai khoan !" << endl;

		}
		else if (ans == 4) // Tai khoan the hoan tien
		{
			CashbackCard cbc;
			cout << "\n Mo tai khoan the hoan tien";
			cout << " So tien co the hoan lai hien tai trong tai khoan: ";
			cbc.getCurrentCashBack();

			cbc.Nhap();
			double money = 0;
			cout << " Nhap so tien giao dich: "; cin >> money;
			if (cbc.charge(money) == true)
				cout << " => Thanh toan thanh cong !" << endl;
			else
				cout << " => Thanh toan khong thanh cong. Hay kiem tra lai so du trong tai khoan !" << endl;
			/*-----------------------------------------*/
			cout << " So tien co the hoan lai hien tai trong tai khoan: ";
			cbc.getCurrentCashBack();

			cout << "\n -- Tien hanh hoan tien --";
			cbc.redeemCashBack();
		}
	}

	cout << "  Thank you for using this program.";
	cout << "\n\tHave a nice day!\n";
	return 0;
}