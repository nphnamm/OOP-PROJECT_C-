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
class Dish;
class FoodCustomer;
class Food;
class Hotel;
class Room;


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
	int STT;
	string listRoom;
	int noOfroom;
	

public:
	Room(string roomType, int noOfBeds, double rent, int roomNo, string listRoom);
	void setRoom();
	Room();
	~Room();
	int getsp() {
		return this->noOfroom;
	}
};
Room::Room(string roomType, int noOfBeds, double rent, int STT, string listRoom)
{
	this->roomType = roomType;
	this->noOfBeds = noOfBeds;
	this->rent = rent;
	this->STT = STT;
	this->listRoom = listRoom;
	this->noOfroom = 0;

}

void Room::setRoom()
{
	cout << "Enter Room Type, No of beds, Rent, RoomNo\n";
	cin >> this->roomType;
	cin >> this->noOfBeds;
	cin >> this->rent;
	cin >> this->STT;
	cin >> this->listRoom;
	
}
Room::Room()
{

}
Room::~Room() {

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
	~Dish();
};
Dish::Dish(string stt, string dishName, double price, string dishType)
{
	this->stt = stt;
	this->dishName = dishName;
	this->price = price;
	this->dishType = dishType;

}
Dish::~Dish(){

}

class Customer :public Room
{
private:
	string custName;
	string custAddress;
	int custID;
	int custAge;
	string custPhone;
	string custCMND;
	string checkInTime;
	static int id;
	string CheckOutTime;

public:
	Customer();
	~Customer();
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

	int getCustID() {
		return custID;
	}

	string getcustname() {
		return custName;

	}
	int getAge() {
		return custAge;
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
		custID = id;

	}
	void setCname(string newname) {
		custName= newname;

	}
	void setAddress(string add) {
		custAddress = add;

	}
	void setphone(string phone) {
		custPhone = phone;
	}
	void setCMND(string CMND) {
		custCMND=CMND;
	}
	void setAge(int age) {
		custAge = age;
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
Customer::~Customer()
{
}
void Customer::setData()
{

	time_t now = time(0);
	string dt = ctime(&now);
	this->checkInTime = dt;

	rewind(stdin);
	cout << "\n\n\tNhap Ten:";
	getline(cin, custName);
	rewind(stdin);
	cout << "\n\tNhap Tuoi:";
	cin >> custAge;
	rewind(stdin);
	cout << "\n\tNhap Dia Chi :";
	getline(cin, custAddress);
	rewind(stdin);
	//yêu cầu nhập lại số điện thoại bắt đầu bằng số không không nhập chữ cái và ít hơn mươi kí tự
	//Họ và Tên:Nguyễn Minh Thắng;
	//Mã Sinh Viên: 6151071075
	//Nhóm 29
	cout << "\nNhap So Dien Thoai :";
	getline(cin, custPhone);
	while (custPhone[0] > '0' || custPhone.length() > 10) {
	nl:
		cout << "\nNhap Lai So Dien Thoai :";
		getline(cin, custPhone);
		for (; i < custPhone.length(); i++) {
			if ((custPhone[i] >= 'a' && custPhone[i] <= 'z') || (custPhone[i] >= 'A' && custPhone[i] <= 'Z')) {
				cout << "\nVui Long Nhap Lai";
				goto nl;
			}

		}
	}
	cout << "\n\tNhap So Chung Minh Nhan Dan : ";
	getline(cin, custCMND);
	this->custID;
}
void Customer::printCustomer()
{

	time_t now = time(0);
	string dt = ctime(&now);
	this->CheckOutTime = dt;
	cout << "\n\n-----------------------------------------------------------------\n\n";
	cout << "ID :: " << custID << endl;

	cout << "Ho Va Ten :: " << custName << endl;

	cout << "Tuoi :: " << custAge << endl;

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
	
public:

	~RoomCustomer();
	void allocateRoom(Room r1);
	void printCustomer();
	float viewTotalBill();
	void checkOut();
	int getsp() {
		return this->r.noOfroom;

	}

};

void RoomCustomer::allocateRoom(Room r1)
{
	this->r = r1;
}
void RoomCustomer::printCustomer()
{

	Customer::printCustomer();

	cout << "Loai Phong :: " << r.roomType << endl;
	cout << "So Phong :: " << r.noOfroom << endl;
}
float RoomCustomer::viewTotalBill()
{
	this->bill = r.rent;
	cout << "Hoa Don :: " << this->bill;
	return bill;
}
RoomCustomer::~RoomCustomer() {

}

class FoodCustomer :public RoomCustomer
{
public:
	double bill;
	Dish d;
public:
	FoodCustomer();
	~FoodCustomer();
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
FoodCustomer::~FoodCustomer() {

}

class Food
{
public:
	Dish dish[8];

public:
	
	Dish getDish(string dnam);
	~Food()

};

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
Food::~Food() {

}
int CheckRoom(LIST* l, int r) {
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
	
	string hotelName;
	string hotelAddress;
	string acc="baitaplon";
	string pss="123";
public:
	Food food;
	Room room[5];
public:
	~Hotel() ;
	void setHotel(Food f, Room rs[5]);
	Room getRoom(int rno);
	Dish getDish(string dsh);
	void displayAvailble();
	void displayMenu();
	void bookRoom(LIST* l, int r);
	void askFeedback();
	void getCustomerData(Customer* c);
	void vacateRoom(int rno);
	void takeOrder(string dnm);
	void DangNhap();
	void Displayds(LIST* l);
	void Printcus(LIST* l);
	void PrintBill(LIST* l);
	void callepl(LIST* l);
	int CheckRoom(LIST* l, int r);
<<<<<<< HEAD
	int DemFeedBack()
=======
	void searchcmnd(LIST* l);
>>>>>>> ee21698ed6a4dd707b2f6275767f1631a6cc3c7e

	Hotel(string hname, string add)
	{
		this->hotelName = hname;
		this->hotelAddress = add;

	}

	string getacc() {
		return acc;
	}
	string getpss() {
		return pss;

	}
};
<<<<<<< HEAD

=======
//Yêu cầu xuất những phòng có trùng chứng minh nhân dân
//Họ Và tên :Nguyen Phan Hoai Nam
//Mã SV: 6151071075
//Nhóm :29
void Hotel::searchcmnd(LIST* l) {
search:
	string ncmnd;
	cout << "\nNhap so CMND De Tim Phong: ";
	getline(cin, ncmnd);
	int c = 0;
	for (NODE* k = l->pHead; k != NULL; k = k->pNext)
	{
		if (k->data->getcustCMND() == ncmnd) {
			system("cls");
			cout << "\n\t\tThong Tin Khach Hang Phong " << k->data->getsp();
			k->data->printCustomer();
			k->data->viewTotalBill();

			c = 1;
			pressanykey();

		}

	}
	if (c == 0) {
		cout << "\nVui Long Nhap Lai ! Hoac Nhap 0 De Thoat.";
		system("cls");
		goto search;
	}
	else {
		system("cls");
		textcolor(11);
		return;
	}

}
>>>>>>> ee21698ed6a4dd707b2f6275767f1631a6cc3c7e
Hotel::~Hotel() {
	
}
void Hotel::setHotel(Food f, Room rs[5])
{
	int i;

	for (i = 0; i < 5; i++)
	{
		this->room[i] = rs[i];
	}
	for (i = 0; i < 8; i++)
		this->food.dish[i] = f.dish[i];
	
}
Room Hotel::getRoom(int rno)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (room[i].STT == rno)
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
		const int RTWidth = 27;
		const int NumbWidth = 27;
		const int RentWidth = 22;
		const int SPWidth = 22;
		cout << "\n\n-------------------------------------------------------Chi Tiet Phong-------------------------------------------------\n\n";
	
	
		cout << "\n\n +----+----------------------------+----------------------------+-----------------------+-----------------------+";
		cout << "\n | NO |          Loai Phong        |          So Giuong         |        Gia Tien       |      So Phong.        |";
		cout << "\n +----+----------------------------+----------------------------+-----------------------+-----------------------+";
		for (i = 0; i < 5; i++)
		{
			
				
				cout << "\n |" << setw(NoWidth) << setfill(separator) << room[i].STT << " |";
				cout << setw(RTWidth) << setfill(separator) << room[i].roomType << " |";
				cout << setw(NumbWidth) << setfill(separator) << room[i].noOfBeds << " |";
				cout << setw(RentWidth) << setfill(separator) << room[i].rent << " |";
				cout << setw(SPWidth) << setfill(separator) << room[i].listRoom << " |";
		
		}
		cout << "\n +----+----------------------------+----------------------------+-----------------------+-----------------------+";

}
void Hotel::displayMenu()
{
	const char separator = ' ';
		const int NoWidth = 25;
		const int DishWidth = 27;
		const int PriceWidth = 27;
		const int RTWidth = 27;
		cout << "\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°MENU°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n ";
		cout << "\n\n +--------------------------+----------------------------+----------------------------+----------------------------+";
		cout << "\n |                        NO|         Ten Mon An         |           Gia Tien         |         Loai Mon An        |";
		cout << "\n +--------------------------+----------------------------+----------------------------+----------------------------+";
		for (int i = 0; i < 8; i++)
		{
			
			cout << "\n |" << setw(NoWidth) << setfill(separator) << food.dish[i].stt << " |";
			cout << setw(DishWidth) << setfill(separator) << food.dish[i].dishName << " |";
			cout << setw(PriceWidth) << setfill(separator) << food.dish[i].price << " |";
			cout << setw(RTWidth) << setfill(separator) << food.dish[i].dishType << " |";
		}
		cout << " \n +--------------------------+----------------------------+----------------------------+----------------------------+";
		cout << "\n\n";
	
}
int Hotel::CheckRoom(LIST* l, int r) {
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
void Hotel::bookRoom(LIST* l, int r)
{
	int i, c = 0;
bk:
	for (i = 0; ; i++)
	{
		int sphong;
		if (room[i].STT == r) {

			if (r == 1) {
			st1:
				cout << "\nNhap so phong 100-200: ";
				cin >> sphong;
				c = CheckRoom(l, sphong);
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

				room[i].noOfroom = sphong;
			}
			if (r == 2) {
			st2:
				cout << "\nNhap so phong 200-300: ";
				cin >> sphong;
				c = CheckRoom(l, sphong);
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
				room[i].noOfroom = sphong;
			}
			if (r == 3) {
			st3:
				cout << "\nNhap so phong 300-400: ";
				cin >> sphong;
				c = CheckRoom(l, sphong);
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
				room[i].noOfroom = sphong;
			}
			if (r == 4) {
			st4:

				cout << "\nNhap so phong 400-500: ";
				cin >> sphong;
				c = CheckRoom(l, sphong);
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
				room[i].noOfroom = sphong;

			}
			if (r == 5) {
			st5:
				cout << "\nNhap so phong 500-600: ";
				cin >> sphong;
				c = CheckRoom(l, sphong);
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
				room[i].noOfroom = sphong;

			}
			cout << "\nVui Long Nhap So Ngay Ban O ";
			int sn;
			cin >> sn;
			while (sn < 1) {
				cout << "\nVui Long Nhap Lai";;
				cin >> sn;
			}
			room[i].rent = room[i].rent * sn;
			break;
		}
		else if ((room[i].STT != r)) {
			while (r >= 6 || r < 1)
			{
				cout << "\nVui Long Nhap Lai :";
				cin >> r;
				goto bk;
			}
		}


	}

}
<<<<<<< HEAD
	// yêu cầu đánh giá mứcc độ hài lòng từ 1 đến 5 và tính trung bình mức độ hài lòng của khách hàng
	//Họ Tên:Nguyễn Hoàng Nam Kha
	//Mã Sinh Viên:6151071007
	//Nhóm 29
	int Hotel::DemFeedBack() {
		int numLines = 0;
		ifstream in("FeedBack.txt");

		while (in.good())
		{
			std::string line;
			std::getline(in, line);
			++numLines;
		}
		return numLines;
	}
=======

>>>>>>> ee21698ed6a4dd707b2f6275767f1631a6cc3c7e
	void askFeedback()
	{
		int f;
		string cname;
		ofstream feedback;
		feedback.open("feedback.txt", ios::app);
		feedback << "\t\t\tTen Khach Hang\t : ";
		cout << "\t\t\tNhap Ten Cua ban :";
		cin >> cname;
		feedback << cname << "\t\t\t";
		cout << " \t\t\tCam On Thoi Gian Cua Ban! \n\t\t\tBan Danh Gia Khach San Cua Chung Toi Nhu The Nao? \n\t\t\tCham Diem Tu 1-5\n";
		cout << " \t\t\t";
		cin >> f;
		while (f > 5 || f <= 0) {
			cout << "\n\t\t\tVui Long Nhap Lai Cham Diem Tu 1-5:\n";
			cout << " \t\t\t";
			cin >> f;
		}
		feedback << ",Feedback\t: ";
		feedback << f << "\n";
		feedback.close();
		cout << "\t\t\t Cam On Danh Gia Cua Ban!" << endl;

		ifstream in("FeedBack.txt");
		string tname;
		string name;
		string tfd;
		int diem;
		int tdiem = 0;
		int dem = DemFeedBack() - 1;
		for (int i = 0; i < dem; i++) {
			getline(in, tname, ':');

			getline(in, name, ',');

			getline(in, tfd, ':');
			in >> diem;

			tdiem = diem + tdiem;


		}
		cout << "\n\t\t\tDiem Danh Gia Trung Binh La:" << (float)tdiem / dem;
		system("pause");
		
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
	for (i = 0; i < 5; i++)
	{
		if (room[i].STT == rno)
		{
			j = 1;
			
			cout << "Cam On! Hen Gap Lai Ban.\n" << endl;
		}
	}
	if (j == 0)
		cout << "Xin Loi!So Phong Khong Hop Le\n";
}
void Hotel::takeOrder(string dnm)
{	
	int i;
	for (i = 0; i < 8; i++)
	{
		if (food.dish[i].stt == dnm)
		{
			
			cout << "Dat Do An Thanh Cong\n" << endl;
		}
		else {
			cout << "\Vui Long Nhap Lai";
			return;
		}

	}
	
	return;
}
void Hotel::Displayds(LIST* l) {
	const char separator = ' ';
	const int NoWidth = 8;
	const int GuestWidth = 25;
	const int AddressWidth = 25;
	const int RoomWidth = 20;
	const int ContactNoWidth = 20;
	cout << "\n\t\t\t    DANH SACH KHACH HANG DA DAT PHONG";
	cout << "\n\t\t\t   -----------------------";
	cout << "\n\n +---------+--------------------------+--------------------------+---------------------+---------------------+";
	cout << "\n | ID.     |       Ten Khach Hang     |          Tuoi            |       Loai Phong    |       So CMND       |";
	cout << "\n +---------+--------------------------+--------------------------+---------------------+---------------------+";
	for (NODE* k = l->pHead; k != NULL; k = k->pNext)
	{
		cout << "\n |" << setw(NoWidth) << setfill(separator) << k->data->getCustID() << " |";
		cout << setw(GuestWidth) << setfill(separator) << k->data->getcustname() << " |";
		cout << setw(AddressWidth) << setfill(separator) << k->data->getAge() << " |";
		cout << setw(RoomWidth) << setfill(separator) << k->data->getsp() << " |";
		cout << setw(ContactNoWidth) << setfill(separator) << k->data->getcustCMND() << " |";

	}
	cout << "\n +---------+--------------------------+--------------------------+---------------------+---------------------+";
	getchar();
}
void Hotel::DangNhap() {
	string dname, tk, mk;
	
	rewind(stdin);
	cout << setw(60) << "NHAP TAI KHOAN : ";
	getline(cin, tk);
	cout << setw(59) << "NHAP MAT KHAU  :";
	getline(cin, mk);
	while (tk != acc || mk != pss) {
		system("cls");
		cout << endl;
		cout << setw(80) << "MAT KHAU HOAC TAI KHOAN SAI VUI LONG NHAP LAI \n";
		cout << setw(60) << "NHAP TAI KHOAN : ";
		getline(cin, tk);
		cout << setw(59) << "NHAP MAT KHAU  :";
		getline(cin, mk);

	}
	char s = 219;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 250);
	for (int i = 0; i < 110; i++)
	{
		if (i < 20)
			Sleep(1);
		else if (i < 80)
			Sleep(1);
		else
			Sleep(1);
		cout << s;
	}
	SetConsoleTextAttribute(hConsole, 130);
	Sleep(100);
}
void Hotel::Printcus(LIST* l) {
search:
	int rn;
	cout << "\nNhap So Phong Can Xem Thong Tin: ";
	cin >> rn;
	for (NODE* k = l->pHead; k != NULL; k = k->pNext)
	{
		if (k->data->getsp() == rn) {
			system("cls");
			k->data->printCustomer();
			k->data->viewTotalBill();
			break;
			pressanykey();
			system("cls");
			textcolor(11);

		}
		else {
			cout << "\nVui Long Nhap Lai!";
			goto search;
		}
	}
}

	void Hotel::callepl(LIST * l) {
	search:
		int rn;
		int f = 0;
		cout << "\n\t\t\tNhap So Phong Cua Ban: ";
		cin >> rn;
		for (NODE* k = l->pHead; k != NULL; k = k->pNext)
		{
			if (k->data->getsp() == rn) {
				cout << "\n\t\t\tNhan Vien Cua Chung Toi Dang Den Phong Cua Ban...\n\n";
				f = 1;
			}

		}
		if (f == 0) {
			cout << "\n\t\t\tVui Long Nhap Lai\n\n";
			goto search;
		}


	}




