#include<iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <cmath>
using namespace std;
 struct congnhan
{
	char ten[30];
	int nam;
	int sogiolam;
 };
 typedef congnhan cn;
void nhapcn(cn &cn) {
	fflush(stdin);
    cout << "\n Nhap ten: "; 
	gets(cn.ten);
    cout << " \nNhap nam: "; 
	cin >> cn.nam;
    cout << "\nNhap so gio lam: "; 
	cin >> cn.sogiolam;
	
}
void xuatcn(cn &cn){
	cout<<"\t ten cong nhan: "<<cn.ten;
	cout<<"\t Nam: "<< cn.nam;
	cout <<"\t So gio lam: "<< cn.sogiolam;
}
void nhap(cn a[], int n) {
    for(int i = 0; i< n; ++i){
		cout<<"\n Nhap sinh vien thu " <<i + 1;
    	nhapcn(a[i]);
}
}
void xuat(cn a[], int n){
    for(int i = 0; i< n; ++i){
		cout<<"\n thong tin sinh vien thu " <<i + 1;
    	xuatcn(a[i]);
}
}
int main()
{
	int n;
	cn a[100];
	cout <<"Nhap so cong nhan: ";
	cin >> n;
	cout<<"\nNhap danh sach sinh vien\n";
	nhap(a,n);
	xuat(a,n);
	return 0;
}
