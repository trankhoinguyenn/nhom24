#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h> 
struct date{
	int ngay;
	int thang;
	int nam;
};
struct monHoc{
	char tenMh[50];
	float dtk;
	int stc;
	
};

typedef struct SinhVien{
	int count;	
	char MSV[30];
	char ten[50];
	char gioiTinh[5];
	date ngaySinh;
	char chuyenNganh[50];
	char Lop[30];
	monHoc mh[100];
	int tuoi;
	float diemTrungBinh;
	char hocLuc[10];
}SV;

void nhapSinhVien(SV *sv);
void inSinhVien(SV *sv);
void tinhTuoi(SV *sv);
void xepLoai(SV *sv);
void capNhatSinhVien(SV *sv);
void nhapDanhSachSinhVien(SV *&ds, int &n);
void xuatDanhSachSinhVien(SV *ds, int n);
void xuatDanhSachSinhVienTheoLop(SV *ds, int n);
void xoaSinhVienTheoMaSinhVien(SV *ds, int &n, char MSV[]);
void sapXepDanhSachSinhVienTheoTen(SV *ds, int n);
void xoaXuongDong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n'){
		x[len-1]='\0';
	}
}

void nhapSinhVien(SV *sv){
	printf("\n\t\tMSV: "); fflush(stdin); fgets(sv->MSV, sizeof(sv->MSV), stdin); xoaXuongDong(sv->MSV);
	printf("\t\tTen: "); fflush(stdin); fgets(sv->ten, sizeof(sv->ten), stdin); xoaXuongDong(sv->ten);
	printf("\t\tGioi tinh: "); fflush(stdin); fgets(sv->gioiTinh, sizeof(sv->gioiTinh), stdin); xoaXuongDong(sv->gioiTinh);
	printf("\t\tNgay sinh: "); scanf("%d", &sv->ngaySinh.ngay);
	printf("\t\tThang sinh: "); scanf("%d",  &sv->ngaySinh.thang);
	printf("\t\tNam sinh: "); scanf("%d",  &sv->ngaySinh.nam);
	fflush(stdin);
	printf("\t\tChuyen Nganh: "); fflush(stdin); fgets(sv->chuyenNganh, sizeof(sv->chuyenNganh), stdin);
	printf("\t\tNhap Lop: "); fflush(stdin); fgets(sv->Lop, sizeof(sv->Lop), stdin); 
	printf("\t\tNhap so luong mon hoc: ");
    scanf("%d",&sv->count);
    fflush(stdin);
    float sum=0,sumcreditNumber=0,average=0;
    for(int i=0;i<sv->count;i++ ){
    	printf("\n\t\tNhap mon hoc thu %d: " ,i+1);
    	printf("\t\tNhap ten mon hoc: ");
    	gets(sv->mh[i].tenMh);
    	fflush(stdin);
    	printf("\t\tNhap diem tong ket: ");
    	scanf("%f", &sv->mh[i].dtk);
    	fflush(stdin);
    	printf("\t\tNhap so tin chi: ");
    	scanf("%d", &sv->mh[i].stc);
    	fflush(stdin);
    	sum=sum+ sv->mh[i].stc * sv->mh[i].dtk;
		sumcreditNumber= sumcreditNumber+sv->mh[i].stc;
		
	}
    sv->diemTrungBinh =sum/sumcreditNumber;

}
void ThemSV(SV *&ds, int &n)// ham them Sinh vien
{
   
    printf("%d",n);
	SV *dst;
	dst=(SV*)malloc(n*sizeof(SV));
	for(int i=0;i<n;i++){
		*(dst+i)= *(ds+i);
	}
    
//    ds=(SV*)malloc(n*sizeof(SV));
    printf("\nNhap thong tin sinh vien muon them:\n");
    for(int i = n - 1 ; i > 0 ; i--)
    {
       capNhatSinhVien(dst+i);
       break;
    }
    delete[] ds;
    ds=(SV*)malloc(n*sizeof(SV));
	for(int i=0;i<n;i++){
		*(ds+i)= *(dst+i);
	}
	delete[] dst;
}
void inSinhVien(SV *sv){

//	printf("\n\t%s \t\t%s \t\t%d/%d/%d \t%s  \t\t%s \t\t%f",sv.MSV, sv.ten,sv.ngaySinh.ngay,sv.ngaySinh.thang,sv.ngaySinh.nam, sv.gioiTinh ,sv.Lop,sv.diemTrungBinh);
	printf("\n\t\t|%-15s| %-15s| %-15s| %-2d/%-2d/%-6d   |%-14.2f  |%-13s   |%s", sv->MSV, sv->ten, sv->gioiTinh, sv->ngaySinh.ngay, sv->ngaySinh.thang, sv->ngaySinh.nam, sv->diemTrungBinh, sv->hocLuc, sv->Lop);

}
void InThongTin(SV *sv){
	printf("\n\t\tMSV: %s " ,sv->MSV); 
	printf("\n\t\tTen: %s",sv->ten);  
	printf("\n\t\tGioi tinh: %s",sv->gioiTinh);
	printf("\n\t\tNgay sinh: %d/%d/%d",sv->ngaySinh.ngay,sv->ngaySinh.thang,sv->ngaySinh.nam); 
   	printf("\n\t\tChuyen Nganh: %s " ,sv->chuyenNganh);
	printf("\t\tLop: %s " ,sv->Lop);  
    float sum=0,sumcreditNumber=0,average=0;
    for(int i=0;i<sv->count;i++ ){
    	
    	printf("\t\tmon hoc: %s",sv->mh[i].tenMh);
    	printf("\t\tDiem Tong Ket: %f",sv->mh[i].dtk);
    	printf("\t\tSo Tin Chi: %d",sv->mh[i].stc);
    	
		
	}
   	printf("\n\t\tDiem Trung Binh: %f",sv->diemTrungBinh);
	
}


void tinhTuoi(SV *sv){
	time_t TTIME = time(0);
	tm* NOW = localtime(&TTIME);
	int namHienTai = NOW -> tm_year+1900;
	sv->tuoi = namHienTai - sv->ngaySinh.nam;
}

void xepLoai(SV *sv){
	if(sv->diemTrungBinh > 9){
		strcpy(sv->hocLuc, "XUAT SAC");
	}
	else if(sv->diemTrungBinh > 8){
		strcpy(sv->hocLuc, "GIOI");
	}
	else if(sv->diemTrungBinh > 7){
		strcpy(sv->hocLuc, "KHA");
	}
	else if(sv->diemTrungBinh > 5){
		strcpy(sv->hocLuc, "TRUNG BINH");
	}
	else{
		strcpy(sv->hocLuc, "YEU");
	}
}

void capNhatSinhVien(SV *sv){
	nhapSinhVien(sv);
	tinhTuoi(sv);
	xepLoai(sv);
}

void capNhatSV(SV *&ds, int &n) {
	char msv[30];
	printf("Vui Long Nhap Ma So Sinh Vien Can Chinh Sua: ");
	fflush(stdin); fgets(msv, sizeof(msv), stdin); xoaXuongDong(msv);
    int found = 0;
    for(int i = 0; i < n; i++) {

        if(strcmp(ds[i].MSV, msv) == 0){	
		found = 1;
            
            printf ("\n Cap nhat thong tin sinh vien co ma so: %s " ,msv);
            nhapSinhVien(&*(ds+i));
           capNhatSinhVien(ds+i);
            break;
		}
    }
    if (found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai.", msv);
    }
}
void nhapDanhSachSinhVien(SV *&ds, int &n){
	do{
		printf("\n\t\tNhap so luong sinh vien them vao: ");
		scanf("%d", &n);
	}while(n <= 0);
		ds=(SV*)malloc(n*sizeof(SV));
	for(int i = 0; i < n; i++){
		printf("\n\t\tNhap vao sinh vien thu %d: ", i+1);
		capNhatSinhVien(&*(ds+i));
	}
}

void xuatDanhSachSinhVien(SV *ds, int n){
	printf("\n\t\t|%-15s| %-15s| %-15s| %-15s| %-15s| %-15s| %-15s\n", "MSV", "Ten", "Gioi Tinh", "Ngay Sinh", "Diem TB", "XepLoai", "Ma Lop");
//	printf("\t%s \t%s \t%s \t%s \t%s \t%s \t%s", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Lop", "Diem Trung Binh", "Hoc Luc");
	for(int i = 0; i < n; i++){
	
		inSinhVien(ds+i);
	
	}
}
