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
			customer << cs->r.STT << ",";
			customer << cs->r.noOfroom << ",";
			customer << cs->r.roomType << ",";
			customer << cs->d.dishName << ",";
			customer << cs->d.dishType << ",";
			customer << cs->d.price << ",";
			customer << cs->bill;
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
			customer << cs->getcustAddress() << ",";
			customer << cs->getcustPhone() << ",";
			customer << cs->getcustCMND() << ",";
			customer << cs->r.STT << ",";
			customer << cs->r.noOfroom << ",";
			customer << cs->r.roomType << ",";
			customer << cs->d.dishName << ",";
			customer << cs->d.dishType << ",";
			customer << cs->d.price << ",";
			customer << cs->bill;
			customer.seekp(1, 1);
			customer << endl;
			cout << "Da Dat Phong & Da Luu Thong Tin";
		}
		else
			cout << "Thong Tin Khong Duoc Luu! ";
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
	filein >> rs->r.STT;
	filein.seekg(1, 1);
	filein >> rs->r.noOfroom;
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

