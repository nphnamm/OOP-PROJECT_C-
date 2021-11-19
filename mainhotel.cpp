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
class Hotel;
class Room;
class RoomService;
class FoodCustomer;
class Food;

void pressanykey() {
	printf("\n\nNhan phim bat ki de tiep tuc ...");
	getch();
	system("cls");
}
//c?u trúc node
struct NODE {
	FoodCustomer* data;
	NODE* pNext;
};
//c?u trúc ds node
struct LIST {
	NODE* pHead;
	NODE* pTail;


};
//khoi tao danh sach node
void KhoiTaoDSLK(LIST*& l) {
	l = new LIST;
	l->pHead = NULL;
	l->pTail = NULL;


}
//khoi tao node
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
//them node vao cuoi 
void ThemVaoCuoi(LIST*& l, NODE* p) {
	if (l->pHead == NULL) {
		l->pHead = l->pTail = p;

	}
	else {

		l->pTail->pNext = p;

		l->pTail = p;


	}
}
// xoa node dau 
void XoaDau(LIST* l) {
	if (l->pHead == NULL) {
		return;
	}
	NODE* p = l->pHead;
	l->pHead = l->pHead->pNext;
	delete p;


}
// xoa node cuoi
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
//chinh mau chu
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
	int getsp() {
		return this->noOfroom;
	}
	Room(string roomType, int noOfBeds, double rent, int STT, string listRoom)
	{
		this->roomType = roomType;
		this->noOfBeds = noOfBeds;
		this->rent=rent ;
		this->STT = STT;
		this->listRoom = listRoom;

		

	}
	void setRoom()
	{
		cout << "Enter Room Type, No of beds, Rent, RoomNo\n";
		cin >> this->roomType;
		cin >> this->noOfBeds;
		cin >> this->rent;
		cin >> this->STT;
		cin >> this->listRoom;
		

	}

	Room()
	{

	}






};

class Dish
{
public:
	string dishName;
	double price;
	string dishType;
	string stt;

public:
	Dish(string stt, string dishName, double price, string dishType)
	{
		this->stt = stt;
		this->dishName = dishName;
		this->price = price;
		this->dishType = dishType;

	}
	Dish()
	{

	}
};

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
	int sp;
	static int id;
	string CheckOutTime;

public:
	virtual int getsp() {
		return 0;
	}
	int getCustID() {
		return custID;
	}
	int getAge() {
		return custAge;
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
		custID = id;

	}
	void setCname(string newname) {
		this->custName = newname;

	}
	void setAddress(string add) {
		custAddress = add;

	}
	void setphone(string phone) {
		custPhone = phone;
	}
	void setCMND(string CMND) {
		custCMND = CMND;
	}
	void setAge(int age) {
		custAge = age;
	}
	void setsp(	int spnew) {
		sp = spnew;
	}


	Customer()
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

	void setData()
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
		cout << "\n\tNhap So Dien Thoai :";
		getline(cin, custPhone);
		cout << "\n\tNhap So Chung Minh Nhan Dan : ";
		getline(cin, custCMND);
		this->custID;
	}
	virtual void printCustomer()
	{

		time_t now = time(0);
		string dt = ctime(&now);
		this->CheckOutTime = dt;
		ifstream filein;
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
	virtual float viewTotalBill() {
		return 0;
	}
	virtual void allocateRoom(Room r1) {
	}
	virtual void allocateDish(Dish d1) {
	}
	virtual void checkout() {
	}
	

};
int Customer::id = 100;


class RoomCustomer : public Customer
{
public:
	double bill;
	Room r;

public:

	
	void allocateRoom(Room r1)
	{
		this->r = r1;
	}

	void printCustomer()
	{

		Customer::printCustomer();

		cout << "Loai Phong :: " << r.roomType << endl;
		cout << "So Phong :: " << r.noOfroom << endl;
		

	}
	float viewTotalBill()
	{
		this->bill = r.rent;
		cout << "Hoa Don :: " << this->bill;
		return bill;
	}
	int getsp() {
		return this->r.noOfroom;

	}
	
	void setbill(double nbill) {
		this->bill = nbill;
	}

};


class FoodCustomer :public RoomCustomer
{
public:
	double bill;
	Dish d;
	
public:
	FoodCustomer() {
		this->bill = 0;
		this->d.dishName = "None";
		this->d.dishType = "None";
		this->d.price = 0;
	}


	void allocateDish(Dish d1)
	{
		this->d = d1;
	}

	float viewTotalBill()
	{

		this->bill = d.price + r.rent;
		cout << "Hoa Don Cua Ban La :: " << (size_t)this->bill << endl;
		return this->bill;
	}
	float totalbill() {
		this->bill = d.price + r.rent;
		return this->bill;
	}
	void printCustomer()
	{

		RoomCustomer::printCustomer();

		cout << "Ten Mon An  :: " << d.dishName << endl;
		cout << "Loai Mon An :: " << d.dishType << endl;
		cout << "Gia Mon An::" << d.price << endl;

	}
	void setbill(double nbill) {
		this->bill = nbill;
	}

};




class Food
{
public:
	Dish dish[8];

public:

	Dish getDish(string d)
	{
		int i;
		for (i = 0; i < 8; i++)
		{

			if (dish[i].stt == d)

			{
				return dish[i];
			}
		}
	}
	

};

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
	
	string hotelName;
	string hotelAddress;
	string acc = "baitaplon";
	string pass = "123";
public:

	Food food;
	Room room[6];
	
public:
	
	Hotel(string name, string add) {
		this->hotelName = name;
		this->hotelAddress = add;

	}

	void setHotel(Food f, Room rs[5])
	{
		int i;

		for (i = 0; i < 5; i++)
		{
			this->room[i] = rs[i];
		}
		for (i = 0; i < 8; i++)
			this->food.dish[i] = f.dish[i];

	}


	Room getRoom(int rno)
	{
		int i;
		for (i = 0; i < 6; i++)
		{
			if (room[i].STT == rno)
				return room[i];
		}
	}
	Dish getDish(string dsh)
	{
		int i;
		for (i = 0; i < 8; i++)
		{
			if (food.dish[i].stt == dsh)
				return food.dish[i];
		}
	}
	void displayAvailble() {
		int i;
		const char separator = ' ';
		const int NoWidth = 3;
		const int RTWidth = 25;
		const int NumbWidth = 25;
		const int RentWidth = 20;
		const int SPWidth = 20;
		cout << "\n\n-------------------------------------------------------Chi Tiet Phong-------------------------------------------------\n\n";
		cout << endl;
	
		cout << "\n\n +----+--------------------------+--------------------------+---------------------+---------------------+";
		cout << "\n | NO |         Loai Phong       |         So Giuong        |       Gia Tien      |     So Phong.       |";
		cout << "\n +----+--------------------------+--------------------------+---------------------+---------------------+";
		for (i = 0; i < 5; i++)
		{
			
				
				cout << "\n |" << setw(NoWidth) << setfill(separator) << room[i].STT << " |";
				cout << setw(RTWidth) << setfill(separator) << room[i].roomType << " |";
				cout << setw(NumbWidth) << setfill(separator) << room[i].noOfBeds << " |";
				cout << setw(RentWidth) << setfill(separator) << room[i].rent << " |";
				cout << setw(SPWidth) << setfill(separator) << room[i].listRoom << " |";
		
		}
		cout << "\n +----+--------------------------+--------------------------+---------------------+---------------------+";
		
	}

	void displayMenu()
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

	void bookRoom(LIST* l, int r)
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

					room[i].noOfroom = sphong;
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
					room[i].noOfroom = sphong;
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
					room[i].noOfroom = sphong;
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
					room[i].noOfroom = sphong;

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


	void askFeedback()
	{
		int f;
		string cname;
		ofstream feedback;
		feedback.open("feedback.txt", ios::app);
		feedback << "Ten Khach Hang\t : ";
		cout << "\t\t\tNhap Ten Cua ban \n \t\t\t";
		cin >> cname;
		feedback << cname << "\t\t\t";
		cout << "\t\t\tCam On Thoi Gian Cua Ban! \n\t\t\t Ban Danh Gia Khach San Cua Chung Toi Nhu The Nao? \n\t\t\t Cham Diem Tu 1-10\n";
		cout << "\t\t\t";
		cin >> f;
		feedback << "Feedback\t: ";
		feedback << f << "\n";
		feedback.close();
		cout << " \t\t\tCam On Danh Gia Cua Ban!" << endl;
	}



	void vacateRoom(int rno)
	{
		int i, j = 0;
		for (i = 0; i < 6; i++)
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
	void takeOrder(string dnm)
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
	void Displayds(LIST* l) {
		const char separator = ' ';
		const int NoWidth = 8;
		const int GuestWidth = 25;
		const int AddressWidth = 25;
		const int RoomWidth = 20;
		const int ContactNoWidth = 20;
		cout << "\n\t\t\t\t    DANH SACH KHACH HANG DA DAT PHONG";
		cout << "\n\t\t\t\t   -----------------------------------";
		
		cout << "\n\n +---------+--------------------------+--------------------------+---------------------+---------------------+";
		cout << "\n | ID.     |       Ten Khach Hang     |          Tuoi            |       So Phong      |       So CMND       |";
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
	void Printcus(LIST* l) {
	search:
		int rn;
		cout << "\n\t\t\tNhap So Phong Can Xem Thong Tin: ";
		cin >> rn;
		for (NODE* k = l->pHead; k != NULL; k = k->pNext)
		{
			if (k->data->getsp() == rn) {
				system("cls");
				k->data->printCustomer();
				k->data->viewTotalBill();
				
				pressanykey();

				system("cls");
				textcolor(11);

			}
			
		}
		return;
	}
	void callepl(LIST *l) {
	search:
		int rn;
		int f = 0;
		cout << "\n\t\t\tNhap So Phong Cua Ban ";
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
		
		return;
	}

	void login() {
		string  tk, mk;
		cout << setw(60) << "NHAP TAI KHOAN : ";
		getline(cin, tk);
		cout << setw(59) << "NHAP MAT KHAU  :";
		getline(cin, mk);
		while (tk != acc || mk != pass) {
			system("cls");
			cout << endl;
			cout << setw(80) << "MAT KHAU HOAC TAI KHOAN SAI VUI LONG NHAP LAI \n";
			cout << setw(60) << "NHAP TAI KHOAN: ";
			getline(cin, tk);

			cout << setw(60) << "NHAP MAT KHAU :";
			getline(cin, mk);

		}
	}

};




void Ghi_1_Thong_Tin_customer(FoodCustomer* cs) {

	ofstream customer;
	char o;
	if (!customer.eof()) {
		customer.open("Customer.txt", ios::app);
		cout << "\n \t BAN CO MUON LUU THONG TIN KHONG?(y/n) :";
		cin >> o;
		if (o == 'y' || o == 'Y')
		{

			customer << cs->getCustID() << ",";
			customer << cs->getcustname() << ",";
			customer << cs->getAge() << ",";
			customer << cs->getcustAddress() << ",";
			customer << cs->getcustPhone() << ",";
			customer << cs->getcustCMND() << ",";
			customer << cs->r.STT << ",";
			customer << cs->r.noOfroom << ",";
			customer << cs->r.roomType << ",";
			customer << cs->d.dishName << ",";
			customer << cs->d.dishType << ",";
			customer << cs->d.price << ",";
			customer << cs->r.rent << ",";
			customer.seekp(1, 1);
			customer << endl;
			cout << "Da Dat Phong & Da Luu Thong Tin";
		}
		else
			cout << "Thong Tin Khong Duoc Luu! ";
	}
	else {
		customer.open("Customer.txt", ios::in);
		cout << "\n \t BAN CO MUON LUU THONG TIN KHONG?(y/n) :";
		cin >> o;
		if (o == 'y' || o == 'Y')
		{

			customer << cs->getCustID() << ",";
			customer << cs->getcustname() << ",";
			customer << cs->getAge() << ",";
			customer << cs->getcustAddress() << ",";
			customer << cs->getcustPhone() << ",";
			customer << cs->getcustCMND() << ",";
			customer << cs->r.STT << ",";
			customer << cs->r.noOfroom << ",";
			customer << cs->r.roomType << ",";
			customer << cs->d.dishName << ",";
			customer << cs->d.dishType << ",";
			customer << cs->d.price << ",";
			
			customer << cs->r.rent << ",";
			customer << endl;
			cout << "Da Dat Phong & Da Luu Thong Tin";
		}
		else
			cout << "Thong Tin Khong Duoc Luu! ";
	}
	customer.close();
	getch();

}

int Dem() {
	int numLines = 0;
	ifstream in("Customer.txt");
	//while ( ! in.eof() )
	while (in.good())
	{
		std::string line;
		std::getline(in, line);
		++numLines;
	}
	return numLines;
}
void Doc_file_Thong_Tin_sv(ifstream& filein, LIST* l) {
	int id;
	string n;
	int t;
	int stt;
	string r;
	string a;
	string p;
	string C;
	double nb;
	int dem = Dem();
	cout << n;
	for (int i = 0; i < dem-1; i++) {
		FoodCustomer* rs = new FoodCustomer;
		NODE* x = KhoiTaoNode(rs);
		filein >> id;
		rs->setCustID(id);
		filein.seekg(1, 1);

		getline(filein, n, ',');
		rs->setCname(n);

		filein >> t;
		rs->setAge(t);
		filein.seekg(1, 1);

		getline(filein, a, ',');
		rs->setAddress(a);

		getline(filein, p, ',');
		rs->setphone(p);

		getline(filein, C, ',');
		rs->setCMND(C);
		
		filein >> rs->r.STT;
		filein.seekg(1, 1);
	

		filein >> rs->r.noOfroom;
		filein.seekg(1, 1);
		
		getline(filein, rs->r.roomType, ',');
	
		getline(filein, rs->d.dishName, ',');
		

		getline(filein, rs->d.dishType, ',');
	

		filein >> rs->d.price;
		filein.seekg(1, 1);
		
		filein >> rs->r.rent;
		filein.seekg(1, 1);
		
		
		string temp;
		getline(filein, temp);
		ThemVaoCuoi(l, x);
	}
}

void XoaNodeCoKhoaBatKy(LIST* l, int x) {

	if (l->pHead->data->getsp() == x) {
		XoaDau(l);
		return;
	}
	if (l->pTail->data->getsp() == x) {
		XoaCuoi(l);
		return;
	}
	NODE* g = new NODE; 
	for (NODE* k = l->pHead; k != NULL; k = k->pNext) {
	
		if (k->data->getsp() == x) {
			g->pNext = k->pNext;
			delete k;
			return;
		}

		g = k;
	}
}

void Menu() {
	int check = 0;
	LIST* l;
	KhoiTaoDSLK(l);
	cout << "\n";
	int i = 0, sl,  rno;
	Room r2;
	string dname, tk, mk;
	Dish d2;
	Hotel* ht = new Hotel("Khach San 5*","Thu Duc");
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


	Food res;
	for (i = 0; i < 8; i++)
	{
		res.dish[i] = d[i];
	}
	ht->food = res;

	Room rm[5] = {
	   Room("Phong Don",1,300000,1,"100-199"),
	   Room("Phong Doi",2,400000,2,"200-299"),
	   Room("Phong Ba",3,500000,3,"300-399"),
	   Room("Phong Deluxe ",2,600000,4,"400-499"),
	   Room("Phong Suit",2,700000,5,"500-599"),
	};

	ht->setHotel(res, rm);
	ht->login();
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
	ifstream filein;
	filein.open("Customer.txt", ios::in);
	if (filein.fail()) {
		cout << "\nFile k ton tai";
		system("pause");
	}
	else {

		
		Doc_file_Thong_Tin_sv(filein, l);

	}


	textcolor(11);
	while (true)
	{
		system("cls");
		
	level1:	cout <<"\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t                           \t\t\t\t°\n";
		cout << "\t\t\t°\t\tCHUONG TRINH QUAN LY KHACH SAN \t\t\t°\n";
		cout << "\t\t\t°\t                           \t\t\t\t°\n";
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
		cout << "\t\t\t°\t	6.Xem Thong Tin Mot Khach Hang\t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	7.Danh Sach Phong Da Dat\t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	8.In Hoa Don             \t\t\t°\n";
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	9.Khong Hai Long         \t\t\t°\n"; 
		cout << "\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\t\t\t°\t	10.Give FeedBack          \t\t\t°\n";
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
				FoodCustomer* fc = new FoodCustomer();
				NODE* p = KhoiTaoNode(fc);
				fc->setData();
				check++;
				system("cls");
				ThemVaoCuoi(l, p);
				ht->displayAvailble();
				cout << "\n\tNhap Loai Phong 1-5: ";
				cin >> rno;
				ht->bookRoom(l,rno);
				r2 = ht->getRoom(rno);
				fc->allocateRoom(r2);
				Ghi_1_Thong_Tin_customer(fc);
				pressanykey();
				system("cls");
				textcolor(11);
				goto level1;
			}
			else if (sl == 3) {
				textcolor(16);
				if (l->pHead==NULL)
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
					cout << "\t\t\tNhap So Phong Can Don: ";
					cin >> rno;
					for (NODE* k = l->pHead; k != NULL; k = k->pNext)
					{
						if (k->data->getsp() == rno) {

							cout << "\t\t\tPhong Da Duoc Don\n";
							b = 1;
							pressanykey();
						}
					}
					if (b == 0) {
						system("cls");
						cout << "\n\t\t\tVui Long Nhap Lai ";
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
				textcolor(43);
				goto level1;
			}

			else if (sl == 5) {
				system("cls");
				textcolor(7);
				if (l->pHead == NULL) {
					cout << "\nVui Long Nhap Thong Tin truoc\n";
					
					pressanykey();
					textcolor(11);
					goto level1;
				}
				else {
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
							textcolor(11);
							break;

						}

					}

				}
				pressanykey();
				system("cls");
				textcolor(11);
				goto level1;
			}
			else if (sl == 6) {
			textcolor(7);
			if (l->pHead == NULL) {
				cout << "\n\t\tDanh Sach Trong Khong Co Thong Tin De Hien Thi";
				pressanykey();
				system("cls");
				textcolor(11);
				goto level1;
			}
			else {
				ht->Printcus(l);
				system("cls");
				textcolor(11);
				goto level1;
			}
			}
			else if (sl == 7) {
			textcolor(15);
			if (l->pHead == 0)
			{
				cout << "\n\n-----------------------------------------------------------------------------------\n\n";
				cout << "Danh Sach Khach Hang Trong\n";
				pressanykey();

			}
			else {
				system("cls");
				ht->Displayds(l);
				pressanykey();
			}
			textcolor(11);
			goto level1;
			}
			else if (sl == 8) {
			textcolor(190);
				if (l->pHead==NULL)
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
			else if (sl == 9) {
			textcolor(4);
			if (l->pHead==NULL)

				{
					cout << "\n\n--------------------------------------------------------------------------------------------\n\n";
					cout << "Danh Sach Khach Hang Trong Khong The Goi Nhan Vien \n";
					cout << "\n\n-----------------------------------------------------------------\n\n";
					pressanykey();
					system("cls");
				}

				else
				{
					ht->callepl(l);
					pressanykey();

				}
			system("cls");
			textcolor(11);
				goto level1;
			}
			else if (sl == 10) {
				if (l->pHead == NULL)
				{
					cout << "\n\n-----------------------------------------------------------------------------------\n\n";
					cout << "Danh Sach Khach Hang Trong Khong The Gui Phan Hoi\n";
					pressanykey();

				}
				else{

					ht->askFeedback();
				pressanykey();
				
				
				}
				system("cls");
				textcolor(11);
				goto level1;
				}

			
			
			
			else if (sl == 0) {
				exit(0);
			}
			else {
				textcolor(7);
				cout << "\nVui Long Nhap Lai! ";
				pressanykey();
				textcolor(11);
			}
		}
	}
	filein.close();
}
int main()
{
	Menu();
	system("pause");
	return 0;
}

