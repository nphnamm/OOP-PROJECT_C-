#pragma once
#include"dslk.h"
#include"hotel.h"
void Menu() {
	LIST* l;
	KhoiTaoDSLK(l);
	cout << "\n";
	int i = 0, o, sl, rno;
	Room r2;
	string dname;
	Dish d2;
	Hotel* ht = ht->getHotel();
	Dish d[8] = {
		Dish("1","Bua Sang Thuong",100000,"Do An"),
		Dish("2","Bua Sang Buffet",200000,"Do An"),
		Dish("3","Bua Toi",200000,"Do Uong"),
		Dish("4","Bia",50000,"Do Uong"),
		Dish("5","Nuoc Suoi",20000,"Do Uong"),
		Dish("6","Snack",20000,"Do An"),
		Dish("7","Nuoc Ngot",40000,"Do Uong"),
		Dish("8","Ruou",150000,"Do An")
	};
	 Food fd;
	for (i = 0; i < 8; i++)
	{
		fd.dish[i] = d[i];
	}
	ht->food = fd;

	Room rm[5] = {
	   Room("Phong Don",1,300000,1,"100-199"),
	   Room("Phong Doi",2,400000,2,"200-299"),
	   Room("Phong Ba",3,500000,3,"300-399"),
	   Room("Phong Deluxe ",2,600000,4,"400-499"),
	   Room("Phong Suit",2,700000,5,"500-599"),
	};
	ht->setHotel(fd, rm);
dangnhap:
	DangNhap();
	ifstream filein;
	filein.open("Customer.txt", ios::in);
	if (filein.fail()) {
		cout << "\nFile k ton tai";
		system("pause");
	}
	else {
		/*RestaurantCustomer *rs= new RestaurantCustomer;
		Doc_1_Thong_Tin_sv(filein,rs);
		NODE* p = KhoiTaoNode(rs);
		ThemVaoCuoi(l, p);*/

	}
	textcolor(11);
	while (true)
	{
		system("cls");

	level1:	cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t\tCHUONG TRINH QUAN LY KHACH SAN \t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	1.Danh Sach Phong Dang Co\t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	2.Dat Phong              \t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	3.Don Phong              \t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	4.Danh Sach Do An        \t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	5.Dat Do An              \t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	6.In Hoa Don             \t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	7.Khong Hai Long         \t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	8.Give FeedBack          \t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	9.Danh Sach Phong Da Dat\t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	0.Thoat.                 \t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t--------------------Nhap Lua Chon Cua Ban------------------------\n";
		cout << "\t\t\t";
		cin >> sl;
		{
			if (sl == 1) {
				system("cls");
				textcolor(14);
				ht->displayAvailble();
				pressanykey();
				system("cls");
				textcolor(11);
				goto level1;
			}
			else if (sl == 2) {
				system("cls");
				textcolor(14);
				cout << "Nhap Thong Tin Khach Hang\n";
				FoodCustomer* room = new FoodCustomer();
				NODE* p = KhoiTaoNode(room);
				room->setData();
				system("cls");
				ThemVaoCuoi(l, p);
				ht->displayAvailble();
				cout << "\n\tNhap Loai Phong 1-5: ";
				cin >> rno;
				ht->bookRoom(l, rno);
				r2 = ht->getRoom(rno);
				room->allocateRoom(r2);
				Ghi_1_Thong_Tin_customer(room);
				pressanykey();
				system("cls");
				textcolor(11);
				goto level1;
			}
			else if (sl == 3) {
				textcolor(16);
				if (l->pHead == NULL)
				{
					cout << "\n\n-----------------------------------------------------------------------------------------\n\n";
					cout << "Vui Long Dat Phong Truoc!\n";
					pressanykey();
					cout << "\n\n-----------------------------------------------------------------\n\n";
				}
				else
				{
					int b = 0;
				vacate:
					cout << "Nhap So Phong Can Don\n";
					cin >> rno;
					for (NODE* k = l->pHead; k != NULL; k = k->pNext)
					{
						if (k->data->getsp() == rno) {

							cout << "Phong Da Duoc Don\n";
							b = 1;
							pressanykey();
						}
					}
					if (b == 0) {
						system("cls");
						cout << "\nVui Long Nhap Lai ";
						goto vacate;
					}
				}
				system("cls");
				textcolor(11);
				goto level1;
			}
			else if (sl == 4) {
				textcolor(16);
				system("cls");
				ht->displayMenu();
				pressanykey();
				system("cls");
				textcolor(11);
				goto level1;
			}
			else if (sl == 5) {
				system("cls");
				textcolor(6);
				if (l->pHead == NULL) {
					cout << "\nVui Long Nhap Thong Tin truoc\n";

					pressanykey();
					textcolor(11);
					goto level1;
				}
				else {
					o = 1;
					rewind(stdin);
					ht->displayMenu();
					int od;
					cout << "\nNhap Phong Muon Order ";
					cin >> od;
					for (NODE* k = l->pHead; k != NULL; k = k->pNext)
					{
						if (k->data->getsp() == od) {

							rewind(stdin);
							cout << "Nhap So Thu Tu Mon An Ban Muon Dat\n";
							getline(cin, dname);
							ht->takeOrder(dname);
							d2 = ht->getDish(dname);
							k->data->allocateDish(d2);
							Ghi_1_Thong_Tin_customer(k->data);
							break;

						}

					}

				}
				pressanykey();
				system("cls");

				if (o == 0)
				{
					cout << "\n\n-----------------------------------------------------------------------------------------\n\n";
					cout << "Khong Co Mon An Nao Giong Vay";
				}
				textcolor(11);
				goto level1;
			}
			else if (sl == 6) {
				textcolor(190);
				if (l->pHead == NULL)
				{
					cout << "\n\n------------------------------------------------------------------------------------------\n\n";

					cout << "Danh Sach Khach Hang Trong Khong Co Khach Hang De In Hoa Don\n";
					cout << "\n\n-----------------------------------------------------------------\n\n";
					pressanykey();
					system("cls");
				}
				else
				{

					system("cls");
				tk:
					cout << "\n\n-----------------------------------------------------------------\n\n";
					int px;
					cout << "\nNhap So Phong Can Xuat Hoa Don: ";
					cin >> px;
					int f = 0;
					for (NODE* k = l->pHead; k != NULL; k = k->pNext)
					{
						if (k->data->getsp() == px) {
							system("cls");
							k->data->printCustomer();
							k->data->viewTotalBill();
							XoaNodeCoKhoaBatKy(l, px);
							cout << "\n\t\t\t\tXin Cam On Quy Khach ";
							pressanykey();
							system("cls");
							textcolor(11);
							goto level1;
							cout << "\n\n-----------------------------------------------------------------\n\n";
							f = 1;
							pressanykey();
						}
					}
					if (f == 0) {
						system("cls");
						cout << "\nVui Long Nhap Lai:";
						goto tk;
					}

					system("cls");
					textcolor(11);
					goto level1;
				}
			}
			else if (sl == 7) {
				textcolor(4);
				if (l->pHead == NULL)

				{
					cout << "\n\n--------------------------------------------------------------------------------------------\n\n";
					cout << "Danh Sach Khach Hang Trong Khong The Goi Nhan Vien \n";
					cout << "\n\n-----------------------------------------------------------------\n\n";
					pressanykey();
					system("cls");
				}

				else
				{
					Employee e;
					e.performDuty();
					pressanykey();

				}
				system("cls");
				textcolor(11);
				goto level1;
			}
			else if (sl == 8) {
				if (l->pHead == NULL)
				{
					cout << "\n\n-----------------------------------------------------------------------------------\n\n";
					cout << "Danh Sach Khach Hang Trong Khong The Gui Phan Hoi\n";
					pressanykey();

				}
				else {

					ht->askFeedback();
					pressanykey();
				}
				system("cls");
				textcolor(11);
				goto level1;
			}
			else if (sl == 9) {
				textcolor(3);
				if (l->pHead == 0)
				{
					cout << "\n\n-----------------------------------------------------------------------------------\n\n";
					cout << "Danh Sach Khach Hang Trong\n";
					pressanykey();
				}
				else {
					system("cls");
					Displayds(l);
					pressanykey();
				}
				textcolor(11);
				goto level1;
			}
			else if (sl == 0) {

				exit(0);
			}

			else {
				cout << "\nVui Long Nhap Lai! ";
				pressanykey();
			}
		}
	}
	filein.close();
}
