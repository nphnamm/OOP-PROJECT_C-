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
	for (int i = 0; i < dem - 1; i++) {
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

