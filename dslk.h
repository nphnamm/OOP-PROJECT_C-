#pragma once
#include"hotel.h"


void Prinlist(LIST* l) {
	NODE* pTmp = l->pHead;
	if (pTmp == NULL)
	{
		cout << "Danh sach rong";
		return;
	}
	while (pTmp != NULL)
	{
		RoomCustomer* cs;
		cs = pTmp->data;
		cs->printCustomer();
		system("pause");
		pTmp = pTmp->pNext;
	}
}
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
			customer << cs->getcustAddress() << ",";
			customer << cs->getcustPhone() << ",";
			customer << cs->getcustCMND() << ",";
			customer << cs->r.roomNo << ",";
			customer << cs->r.sp << ",";
			customer << cs->r.roomType << ",";
			customer << cs->d.dishName << ",";
			customer << cs->d.dishType << ",";
			customer << cs->d.price << ",";
			customer << cs->bill;
			customer.seekp(1, 1);
			customer << endl;
			cout << "Room Booked & Details saved";
		}
		else
			cout << "Details not saved! ";
	}
	else {
		customer.open("Customer.txt", ios::in);
		cout << "\n \t BAN CO MUON LUU THONG TIN KHONG?(y/n) :";
		cin >> o;
		if (o == 'y' || o == 'Y')
		{

			customer << cs->getCustID() << ",";
			customer << cs->getcustname() << ",";
			customer << cs->getcustAddress() << ",";
			customer << cs->getcustPhone() << ",";
			customer << cs->getcustCMND() << ",";
			customer << cs->r.roomNo << ",";
			customer << cs->r.sp << ",";
			customer << cs->r.roomType << ",";
			customer << cs->d.dishName << ",";
			customer << cs->d.dishType << ",";
			customer << cs->d.price << ",";
			customer << cs->bill;
			customer.seekp(1, 1);
			customer << endl;
			cout << "Room Booked & Details saved";
		}
		else
			cout << "Details not saved! ";
	}
	customer.close();
	getch();

}


void Doc_1_Thong_Tin_sv(ifstream& filein, FoodCustomer* rs) {
	int id;
	string n;
	string a;
	string p;
	string C;
	filein >> id;
	rs->setCustID(id);
	filein.seekg(1, 1);
	getline(filein, n, ',');
	rs->setCname(n);
	getline(filein, a, ',');
	rs->setAddress(a);
	getline(filein, p, ',');
	rs->setphone(p);
	getline(filein, C, ',');
	rs->setCMND(C);
	filein >> rs->r.roomNo;
	filein.seekg(1, 1);
	filein >> rs->r.sp;
	filein.seekg(1, 1);
	getline(filein, rs->r.roomType, ',');
	getline(filein, rs->d.dishName, ',');
	getline(filein, rs->d.dishType, ',');
	filein >> rs->bill;
	filein.seekg(1, 1);
	string temp;
	getline(filein, temp);

}

//void Doc_Danh_Sach_Sinh_Vien(ifstream& filein, LIST* l) {
//	while (!filein.eof()) {
//		//b??c 1 ??c thông tin ;
//		RestaurantCustomer* rs = new RestaurantCustomer;
//		NODE* n = KhoiTaoNode(rs);
//		Doc_1_Thong_Tin_sv(filein, rs);
//		//b??c 2 : kh?i t?o node sv
//		//b??c 3 : thêm sinh viên vào dslk ??n các sinh viên ;
//		ThemVaoCuoi(l, n);
//
//		if (filein.eof()) {
//			return;
//		}
//	}
//
//
//
//}
void XoaNodeCoKhoaBatKy(LIST* l, int x) {

	if (l->pHead->data->getsp() == x) {
		XoaDau(l);
		return;
	}
	if (l->pTail->data->getsp() == x) {
		XoaCuoi(l);
		return;
	}
	NODE* g = new NODE; //node g la node tro den node nam truoc node can xoa
	for (NODE* k = l->pHead; k != NULL; k = k->pNext) {
		//phat hien phan tu can xoa
		if (k->data->getsp() == x) {
			g->pNext = k->pNext;
			delete k;
			return;
		}

		g = k;
	}
}
void Displayds(LIST* l) {
	const char separator = ' ';
	const int NoWidth = 8;
	const int GuestWidth = 25;
	const int AddressWidth = 25;
	const int RoomWidth = 20;
	const int ContactNoWidth = 20;
	cout << "\n\t\t\t    DANH SACH KHACH HANG DA DAT PHONG";
	cout << "\n\t\t\t   -----------------------";
	cout << "\n\n +---------+--------------------------+--------------------------+---------------------+---------------------+";
	cout << "\n | ID.     |         Guest Name       |         Address          |        Room Type    |    Contact No.      |";
	cout << "\n +---------+--------------------------+--------------------------+---------------------+---------------------+";
	for (NODE* k = l->pHead; k != NULL; k = k->pNext)
	{
		cout << "\n |" << setw(NoWidth) << setfill(separator) << k->data->getCustID() << " |";
		cout << setw(GuestWidth) << setfill(separator) << k->data->getcustname() << " |";
		cout << setw(AddressWidth) << setfill(separator) << k->data->getcustPhone() << " |";
		cout << setw(RoomWidth) << setfill(separator) << k->data->getsp() << " |";
		cout << setw(ContactNoWidth) << setfill(separator) << k->data->getcustCMND() << " |";

	}
	cout << "\n +---------+--------------------------+--------------------------+---------------------+---------------------+";
	getchar();
}
void DangNhap() {
	string dname, tk, mk;
	Hotel ht;
	rewind(stdin);
	cout << setw(60) << "NHAP TAI KHOAN : ";
	getline(cin, tk);
	cout << setw(59) << "NHAP MAT KHAU  :";
	getline(cin, mk);
	while (tk != ht.getacc() || mk != ht.getpss()) {
		system("cls");
		cout << setw(70) << "NHAP LAI TAI KHOAN VA MAT KHAU \n";
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