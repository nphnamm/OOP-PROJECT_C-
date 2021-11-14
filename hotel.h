#pragma once
#include <iostream>
#include<string>
#include<stdlib.h>
#include<ctime>
#include<stdbool.h>
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<vector>
#include<time.h>
#include<windows.h>
#include <ctype.h>
using namespace std;


class Customer;
class RoomCustomer;
class Employee;
class Dish;
class FoodCustomer;
class Restaurant;
class Hotel;
class Room;
class RoomService;

void pressanykey() {
	printf("\n\nNhan phim bat ki de tiep tuc ...");
	getch();
	system("cls");
}
struct NODE {
	FoodCustomer* data;
	NODE* pNext;
};
//
struct LIST {
	NODE* pHead;
	NODE* pTail;


};
// KH?i t?o c?u trúc danh sách 
void KhoiTaoDSLK(LIST*& l) {
	l = new LIST;
	l->pHead = NULL;
	l->pTail = NULL;


}
NODE* KhoiTaoNode(FoodCustomer* x) {

	NODE* p = new NODE;
	if (p == NULL) {
		cout << " \nkhong du bo nho de cap phat ";
		return NULL;

	}
	p->data = x;
	p->pNext = NULL;
	return p;

}

void ThemVaoCuoi(LIST*& l, NODE* p) {
	if (l->pHead == NULL) {
		l->pHead = l->pTail = p;

	}
	else {

		l->pTail->pNext = p;

		l->pTail = p;


	}
}
void XoaDau(LIST* l) {
	if (l->pHead == NULL) {
		return;
	}
	NODE* p = l->pHead;
	l->pHead = l->pHead->pNext;
	delete p;


}
void XoaCuoi(LIST* l) {

	NODE* p;
	for (NODE* k = l->pHead; k != NULL; k = k->pNext) {
		if (k->pNext == l->pTail) {
			delete l->pTail;
			k->pNext = NULL;
			l->pTail = k;
		}
	}
}
void textcolor(int color) {

	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleColor, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0; wAttributes |= color;
	SetConsoleTextAttribute(hConsoleColor, wAttributes);

}

class Room
{
public:
	string roomType;
	int noOfBeds;
	double rent;
	int roomNo;
	string dsphong;
	int sp;
	int status;

public:
	Room(string roomType, int noOfBeds, double rent, int roomNo, string dsphong);
	void setRoom();
	Room();
	void displayDetail();
	void vacateRoom(int rno);
	void displayAvailable(Room r[6]);
	int getsp() {
		return this->sp;
	}
};
Room::Room(string roomType, int noOfBeds, double rent, int roomNo, string dsphong)
{
	this->roomType = roomType;
	this->noOfBeds = noOfBeds;
	this->rent = rent;
	this->roomNo = roomNo;
	this->dsphong = dsphong;
	this->status = 0;
	this->sp = 0;

}
void Room::setRoom()
{
	cout << "Enter Room Type, No of beds, Rent, RoomNo\n";
	cin >> this->roomType;
	cin >> this->noOfBeds;
	cin >> this->rent;
	cin >> this->roomNo;
	cin >> this->dsphong;
	status = 0;

}
Room::Room()
{

}
void Room::displayDetail()
{

	cout << "Room Type :: " << this->roomType << endl;
	cout << "Number of Beds :: " << this->noOfBeds << endl;
	cout << "Rent :: " << this->rent << endl;
	cout << "Room Number ::" << this->roomNo << endl;

}
void Room::vacateRoom(int rno)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		if (this->roomNo == rno)
			this->status = 0;
	}
}
void Room::displayAvailable(Room r[6])
{
	int i;
	for (i = 0; i < 6; i++)
	{
		if (r[i].status == 0)
			r[i].displayDetail();
	}
}
class Dish
{
public:
	string dishName;
	double price;
	string dishType;
	string stt;

public:
	Dish(string stt, string dishName, double price, string dishType);
	Dish()
	{

	}
};
Dish::Dish(string stt, string dishName, double price, string dishType)
{
	this->stt = stt;
	this->dishName = dishName;
	this->price = price;
	this->dishType = dishType;

}


class Customer :public Room
{
private:
	string custName;
	string custAddress;
	int custID;
	string custPhone;
	string custCMND;
	string checkInTime;
	static int id;
	string CheckOutTime;

public:
	int getCustID() {
		return custID;
	}
	string getcustname() {
		return custName;

	}
	string getcustAddress() {
		return custAddress;
		
	}
	string getcustPhone() {
		return custPhone;
	}
	string getcustCMND() {
		return custCMND;

	}
	string getcit() {
		return checkInTime;

	}
	string getcot() {
		return CheckOutTime;

	}
	void setCustID(int id) {
		custID == id;

	}
	void setCname(string newname) {
		custName== newname;

	}
	void setAddress(string add) {
		custAddress == add;

	}
	void setphone(string phone) {
		custPhone = phone;
	}
	void setCMND(string CMND) {
		custCMND=CMND;
	}
	Customer();
	void setData();
	virtual void printCustomer();
	virtual float viewTotalBill() {
		return 0;
	}
	virtual void allocateRoom(Room r1) {
	}
	virtual void allocateDish(Dish d1) {
	}
	virtual void checkout() {
	}
	virtual int getsp() {
		return 0;
	}

};
Customer::Customer()
{
	time_t c = time(0);
	string dt = ctime(&c);
	this->custName = " ";
	this->custAddress = " ";
	this->custPhone = " ";
	this->custCMND = " ";
	this->checkInTime = dt;
	this->custID = id++;

}
void Customer::setData()
{

	time_t now = time(0);
	string dt = ctime(&now);
	this->checkInTime = dt;

	rewind(stdin);
	cout << "\nNhap Ten:";
	getline(cin, custName);
	rewind(stdin);
	cout << "\nNhap Dia Chi :";
	getline(cin, custAddress);
	rewind(stdin);
	cout << "\nNhap So Dien Thoat :";
	getline(cin, custPhone);
	cout << "\nNhap So Chung Minh Nhan Dan : ";
	getline(cin, custCMND);
	this->custID;
}
void Customer::printCustomer()
{

	time_t now = time(0);
	string dt = ctime(&now);
	this->CheckOutTime = dt;

	cout << "ID :: " << custID << endl;

	cout << "Ho Va Ten :: " << custName << endl;

	cout << "Dia Chi :: " << custAddress << endl;

	cout << "So Dien Thoai :: " << custPhone << endl;

	cout << "CMND :: " << custCMND << endl;

	cout << "Gio Vao ::" << checkInTime;

	cout << "Gio Ra ::" << CheckOutTime;
}
int Customer::id = 99;

class RoomCustomer : public Customer
{
public:
	float bill;
	Room r;
	int bookStatus;

public:

	float viewTotalbill();
	void allocateRoom(Room r1);
	void printCustomer();
	float viewTotalBill();
	void checkOut();
	int getsp() {
		return this->r.sp;

	}

};
float RoomCustomer::viewTotalbill()
{
	cout << "Hoa Don =" << bill;
	return bill;
}
void RoomCustomer::allocateRoom(Room r1)
{
	this->r = r1;
}
void RoomCustomer::printCustomer()
{

	Customer::printCustomer();

	cout << "Loai Phong :: " << r.roomType << endl;
	cout << "So Phong :: " << r.sp << endl;
}
float RoomCustomer::viewTotalBill()
{
	this->bill = r.rent;
	cout << "Hoa Don :: " << this->bill;
	return bill;
}
void RoomCustomer::checkOut()
{
	cout << "Hoa Don Cua Ban La: " << this->bill << "/-" << endl;
	this->bill = 0;
	this->r.status = 0;
	cout << "Cam On Ban! Hen Gap Lai Ban.\n" << endl;
}

class FoodCustomer :public RoomCustomer
{
public:
	double bill;
	Dish d;
	int orderStatus;
public:
	FoodCustomer();
	float viewTotalbill();
	void allocateDish(Dish d1);
	float viewTotalBill();
	void printCustomer();

};
FoodCustomer::FoodCustomer() {
	this->bill = 0;
	this->d.dishName = "None";
	this->d.dishType = "None";
	this->d.price = 0;
}
float FoodCustomer::viewTotalbill()
{
	cout << "Tong Hoa Don Cua Ban La: " << bill;
	return bill;
}
void FoodCustomer::allocateDish(Dish d1)
{
	this->d = d1;
}
float FoodCustomer::viewTotalBill()
{

	this->bill = d.price + r.rent;
	cout << "Hoa Don Cua Ban La :: " << (size_t)this->bill << endl;
	return this->bill;
}
void FoodCustomer::printCustomer()
{

	RoomCustomer::printCustomer();

	cout << "Ten Mon An  :: " << d.dishName << endl;
	cout << "Loai Mon An :: " << d.dishType << endl;
	cout << "Gia Mon An::" << d.price << endl;

}

class Employee
{

public:

	void performDuty()
	{
		cout << "Nhan Vien Cua Chung Toi Dang Den...\n\n";
	}
};

class Food
{
public:
	Dish dish[8];

public:
	void displayDish(Dish d);
	Dish getDish(string dnam);
	void displayMenu();

};
void Food::displayDish(Dish d)
{
	cout << " Dish Name :: " << d.dishName << endl;
	cout << " Price :: " << d.price << endl;
	cout << " Dish Type :: " << d.dishType;

}
Dish Food::getDish(string dnam)
{
	int i;
	for (i = 0; i < 8; i++)
	{

		if (dish[i].stt == dnam)

		{
			return dish[i];
		}
	}
}
void Food::displayMenu()
{
	int i;
	for (i = 0; i < 8; i++)
	{
		displayDish(dish[i]);
	}

}
int BookRoom(LIST* l, int r) {
	int n = 0;
	for (NODE* k = l->pHead; k != NULL; k = k->pNext)
	{

		if (k->data->getsp() == r) {

			cout << "\nPhong Nay Da Duoc Dat ";
			pressanykey();
			n = 1;
		}

	}
	return n;
}
class Hotel :public FoodCustomer
{
private:
	static Hotel* QLHotel;
	string hotelName;
	string hotelAddress;
	string acc;
	string pss;
public:

	Food food;
	Room room[6];
private:

	Hotel(string hname, string add)
	{
		this->hotelName = hname;
		this->hotelAddress = add;
	}
public:
	Hotel() {
		this->acc = "nam";
		this->pss = "123";
	}
	string getacc() {
		return acc;
	}
	string getpss() {
		return pss;

	}

	static Hotel* getHotel()
	{
		if (!QLHotel)
			QLHotel = new Hotel("KHACH SAN UTC2 ","Quan 9");
		return QLHotel;
	}

	void setHotel(Food r, Room rs[5]);
	Room getRoom(int rno);
	Dish getDish(string dsh);
	void displayAvailble();
	void displayMenu();
	void bookRoom(LIST* l, int r);
	void askFeedback();
	void getCustomerData(Customer* c);
	void vacateRoom(int rno);
	void takeOrder(string dnm);
};
void Hotel::setHotel(Food r, Room rs[5])
{
	int i;

	for (i = 0; i < 5; i++)
	{
		this->room[i] = rs[i];
	}
	for (i = 0; i < 8; i++)
		this->food.dish[i] = r.dish[i];

}
Room Hotel::getRoom(int rno)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		if (room[i].roomNo == rno)
			return room[i];
	}
}
Dish Hotel::getDish(string dsh)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		if (food.dish[i].stt == dsh)
			return food.dish[i];
	}
}
void Hotel::displayAvailble() {
	int i;
	const char separator = ' ';
	const int NoWidth = 3;
	const int RTWidth = 25;
	const int NumbWidth = 25;
	const int RentWidth = 20;
	const int SPWidth = 20;
	cout << "\n\n-------------------------------------------------------Chi Tiet Phong-----------------------------------------------------\n\n";
	cout << endl;

	cout << "\n\n +----+--------------------------+--------------------------+---------------------+---------------------+";
	cout << "\n | NO |         Loai Phong       |         So Giuong        |       Gia Tien      |     So Phong.       |";
	cout << "\n +----+--------------------------+--------------------------+---------------------+---------------------+";
	for (i = 0; i < 6; i++)
	{
		if (room[i].status == 0)
		{

			cout << "\n |" << setw(NoWidth) << setfill(separator) << room[i].roomNo << " |";
			cout << setw(RTWidth) << setfill(separator) << room[i].roomType << " |";
			cout << setw(NumbWidth) << setfill(separator) << room[i].noOfBeds << " |";
			cout << setw(RentWidth) << setfill(separator) << room[i].rent << " |";
			cout << setw(SPWidth) << setfill(separator) << room[i].dsphong << " |";
		}
	}
	cout << "\n +----+--------------------------+--------------------------+---------------------+---------------------+";

}
void Hotel::displayMenu()
{
	const char separator = ' ';
	const int NoWidth = 25;
	const int DishWidth = 25;
	const int PriceWidth = 25;
	const int RTWidth = 25;
	cout << "\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°MENU°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n ";
	cout << "\n\n +--------------------------+--------------------------+--------------------------+--------------------------+";
	cout << "\n |                        NO|        Ten Mon An        |           Gia Tien       |        Loai Mon An       |";
	cout << "\n +--------------------------+--------------------------+--------------------------+--------------------------+";
	for (int i = 0; i < 8; i++)
	{
		cout << "\n |" << setw(NoWidth) << setfill(separator) << food.dish[i].stt << " |";
		cout << setw(DishWidth) << setfill(separator) << food.dish[i].dishName << " |";
		cout << setw(PriceWidth) << setfill(separator) << food.dish[i].price << " |";
		cout << setw(RTWidth) << setfill(separator) << food.dish[i].dishType << " |";
	}
	cout << "\n +--------------------------+--------------------------+--------------------------+--------------------------+";
	cout << "\n\n";
}
void Hotel::bookRoom(LIST* l, int r)
{
	int i, c = 0;
bk:
	for (i = 0; ; i++)
	{
		int sphong;
		if (room[i].roomNo == r) {

			if (r == 1) {
			st1:
				cout << "\nNhap so phong 100-200: ";
				cin >> sphong;
				c = BookRoom(l, sphong);
				if (c == 1) {
					system("cls");
					cout << "\nVui Long Nhap lai !";
					goto st1;
				}
				while (sphong > 200 || sphong <= 100) {

					system("cls");
					cout << "\nSo Phong Khong Hop Le Vui Long Nhap Lai !\n";
					goto st1;
				}

				room[i].sp = sphong;
			}
			if (r == 2) {
			st2:
				cout << "\nNhap so phong 200-300: ";
				cin >> sphong;
				c = BookRoom(l, sphong);
				if (c == 1) {
					system("cls");
					cout << "\nVui Long Nhap lai !";

					goto st2;
				}
				while (sphong > 300 || sphong <= 200) {
					system("cls");
					cout << "\nSo Phong Khong Hop Le Vui Long Nhap Lai !\n";
					goto st2;
				}
				room[i].sp = sphong;
			}
			if (r == 3) {
			st3:
				cout << "\nNhap so phong 300-400: ";
				cin >> sphong;
				c = BookRoom(l, sphong);
				if (c == 1) {
					system("cls");
					cout << "\nVui Long Nhap Lai !\n";
					goto st3;
				}
				while (sphong > 400 || sphong <= 300) {
					system("cls");
					cout << "\nSo Phong Khong Hop Le Vui Long Nhap Lai !\n";
					goto st3;
				}
				room[i].sp = sphong;
			}
			if (r == 4) {
			st4:

				cout << "\nNhap so phong 400-500: ";
				cin >> sphong;
				c = BookRoom(l, sphong);
				if (c == 1) {
					system("cls");
					cout << "\nVui Long Nhap Lai !\n";
					goto st4;
				}
				while (sphong > 500 || sphong <= 400) {
					system("cls");
					cout << "\nSo Phong Khong Hop Le Vui Long Nhap Lai !\n";
					goto st4;
				}
				room[i].sp = sphong;

			}
			if (r == 5) {
			st5:
				cout << "\nNhap so phong 500-600: ";
				cin >> sphong;
				c = BookRoom(l, sphong);
				if (c == 1) {
					system("cls");
					cout << "\nVui Long Nhap lai";

					goto st5;
				}
				while (sphong > 600 || sphong <= 500) {

					system("cls");
					cout << "\nSo Phong Khong Hop Le Vui Long Nhap Lai !\n";
					goto st5;
				}
				cout << "\nDat Phong Thanh Cong";
				room[i].sp = sphong;

			}
			cout << "\nVui Long Nhap So Ngay Ban O ";
			int sn;
			cin >> sn;
			while (sn < 1) {
				cout << "\nVui Long Nhap Lai";;
				cin >> sn;
			}
			room[i].rent = room[i].rent * sn;
			cout << "\nDat Phong Thanh Cong";
			break;
		}
		else if ((room[i].roomNo != r)) {
			while (r >= 6 || r < 1)
			{
				cout << "\nVui Long Nhap Lai :";
				cin >> r;
				goto bk;
			}
		}


	}

}
void Hotel::askFeedback()
{
	int f;
	string cname;
	ofstream feedback;
	feedback.open("feedback.txt", ios::app);
	feedback << "Ten Khach Hang\t : ";
	cout << "Nhap Ten Cua ban \n";
	cin >> cname;
	feedback << cname << "\t\t\t";
	cout << " Cam On Thoi Gian Cua Ban! \n Ban Danh Gia Khach Sab Cua Chung Toi Nhu The Nao? \n Cham Diem Tu 1-10\n";
	cin >> f;
	feedback << "Feedback\t: ";
	feedback << f << "\n";
	feedback.close();
	cout << " Cam On Danh Gia Cua Ban!" << endl;
}

void Hotel::getCustomerData(Customer* c)
{
	cout << " Ho va Ten :: " << c->getcustname() << endl;
	cout << " Dia chi :: " << c->getcustAddress() << endl;
	cout << " So Dien Thoai  :: " << c->getcustPhone() << endl;
	cout << " CMND :: " << c->getcustCMND() << endl;
	cout << " Gio Vao:: " << c->getcit() << endl;
}
void Hotel::vacateRoom(int rno)
{
	int i, j = 0;
	for (i = 0; i < 6; i++)
	{
		if (room[i].roomNo == rno)
		{
			j = 1;
			room[i].status = 0;
			cout << "Cam On! Hen Gap Lai Ban.\n" << endl;
		}
	}
	if (j == 0)
		cout << "Xin Loi!So Phong Khong Hop Le\n";
}
void Hotel::takeOrder(string dnm)
{
	int i, j = 0;
	for (i = 0; i < 8; i++)
	{
		if (food.dish[i].stt == dnm)
		{
			j = 1;
			cout << "Dat Do An Thanh Cong\n" << endl;
		}

	}
	if (j == 0)

		cout << "Xin Loi!,Vui Long Nhap Lai\n";
	return;
}
Hotel* Hotel::QLHotel = 0;

