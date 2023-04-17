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
void xuatDanhSachSinhVienTheoLop(SV *ds, int n){
	char lop[30];
	printf("\n\t\tNhap ma lop can hien thi: "); fflush(stdin); fgets(lop, sizeof(lop), stdin); xoaXuongDong(lop);
	
	printf("\t\tDanh sach sinh vien thuoc lop %s: ", lop);
	
	printf("\n\t\t%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "MSV", "Ten", "Gioi Tinh", "Ngay Sinh", "Diem TB", "XepLoai", "Ma Lop");
	int count=0;

	for(int i = 0; i < n; i++){
		if(strstr(strupr(ds[i].Lop), strupr(lop))){
				
				count++;
				inSinhVien(ds+i);
			printf("\n\n\t\t------------------------------------------------------------------------------------");
		}
	}
	if(count==0){
		printf("\n\t\tKhong Co Sinh Vien Thuoc Lop Nay");
	}
}

void timSinhVienTheoMasv(SV *ds, int n){
	char Msv[30];
	int count=0;
	printf("\n\t\tNhap Ma so sinh vien can tim: "); fflush(stdin); fgets(Msv, sizeof(Msv), stdin); xoaXuongDong(Msv);
	for(int i = 0; i < n; i++){
		if(strstr(strupr(ds[i].MSV), strupr(Msv))){
				InThongTin(ds+i);
				count++;
				
				printf("\n\n\t\t------------------------------------------------------------------------------------");
		}
	}
	if(count==0){
		printf("\n\t\tMa so sinh vien khong hop le");
	}
	
}

void timSinhVienTheoTen(SV *ds, int n){
	char ten[30];
	int count=0;
	printf("\n\t\tNhap Ten sinh vien can tim: "); fflush(stdin); fgets(ten, sizeof(ten), stdin); xoaXuongDong(ten);
	for(int i = 0; i < n; i++){
		
		if(strstr(strupr(ds[i].ten), strupr(ten))){
				InThongTin(ds+i);
				count++;
				printf("\n\n\t\t------------------------------------------------------------------------------------");
			
		}
	}
	if(count==0){
		printf("\n\t\tKHong Tim Thay Sinh Vien Can Tim ");
		
	}

}

void xoaSinhVienTheoMSV(SV *ds, int &n){
	
	char MSV[30];
	int temp=0;
    printf("\n\t\tNhap MSV can xoa: "); 
	fflush(stdin); fgets(MSV, sizeof(MSV), stdin); xoaXuongDong(MSV);
					
	for(int i = 0; i < n; i++){
		if(strcmp(ds[i].MSV, MSV) == 0){
			temp++;
			for(int j = i; j < n; j++){
				ds[j] = ds[j+1];
			}
			n-=1;
			return;
		}
	}
	if(temp==0){
		printf("\t\tMa So Sinh Vien Khong Hop Le!");
	}else{
		printf("\t\tBan da xoa thanh cong sinh vien co ma so %s",MSV);
	}
}
void sapXepDanhSachSinhVienTheoID(SV *ds, int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(strcmp(strupr(ds[i].MSV), strupr(ds[j].MSV))>0){
				SV temp = ds[i];
				ds[i]= ds[j];
				ds[j] = temp;
			}
		}
	}
}

void sapXepDanhSachSinhVienTheoTen(SV *ds, int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(strcmp(strupr(ds[i].ten), strupr(ds[j].ten))>0){
				SV temp = ds[i];
				ds[i]= ds[j];
				ds[j] = temp;
			}
		}
	}
}

void xuatVaoFile(SV *ds, int n){
	char tenFile[50];
	printf("\nNhap vao duong dan va ten file: ");
	fflush(stdin);
	fgets(tenFile, sizeof(tenFile), stdin);
	xoaXuongDong(tenFile);
	FILE *f;
	f = fopen(tenFile, "wb");
	if(f == NULL){
		printf("\nLoi tao or mo file.");
		exit(1);
	}
	fwrite(&n, sizeof(n), 1, f);
	for(int i = 0; i < n; i++){
		fwrite((ds+i), sizeof(SV), 1, f);
	}
	fclose(f);
	
}
void nhapTuFile(SV *&ds, int &n){
	char tenFile[50];
	printf("\nNhap duong dan va ten file: ");
	fflush(stdin);
	fgets(tenFile, sizeof(tenFile), stdin); xoaXuongDong(tenFile);
	FILE *f;
	f = fopen(tenFile, "rb");
	if(f == NULL){
		printf("\nLoi tao file or mo file.");
		exit(1);
	}
	fread(&n, sizeof(n), 1, f);
	for(int i = 0; i < n; i++){
		fread((ds+i), sizeof(SV), 1, f);
	}
	fclose(f);
}

void nhapPhimBatKy(){
		printf("\n\t\tNHAP PHIM BAT KI DE TIEP TUC...\n");
        getch();
        system("cls");
}

void SetColor(WORD color){ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
int Display1()              // To use arrow keys in the menu
{   int a=0,i=1;
   
    	printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t >> Them Sinh Vien Vao He Thong                                       *");
		printf("\n\t\t*\t\t In Danh Sach Sinh Vien Hien Co                                       *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo Ten                                          *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo ID                                           *");
		printf("\n\t\t*\t\t Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                        *");
		printf("\n\t\t*\t\t Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach               *");
		printf("\n\t\t*\t\t In Ra Danh Sach Sinh Vien Theo Ten Lop                               *");
		printf("\n\t\t*\t\t Xoa Thong Tin Sinh Vien Theo Id                                      *");
		printf("\n\t\t*\t\t Chinh Sua Thong Tin Sinh Vien                                        *");
		printf("\n\t\t*\t\t Ghi File                                                             *");
		printf("\n\t\t*\t\t Doc File                                                             *"); 
		printf("\n\t\t*\t\t Thoat Khoi Chuong Trinh                                              *");
		printf("\n\t\t***************************************************************************************");
	while(1)
    {
        a=getch();
        if(a==72)                                      // input code for UP Arrow key
        {
            i--;
        }
        else if(a==80)                                 // input code for DOWN Arrow key
        {
            i++;
        }
        else if(a==13)                                 // input code for Enter key
        {
            return i;
        }
        else
        {
         continue;
        }


        if(i<=0)                                       // To keep the value of i between 1 and 11
            i=1;
        else if(i>12)
            i=12;
        else;

        if(i==1)
        {
            system("cls");
           
	      	printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t >> Them Sinh Vien Vao He Thong                                       *");
		printf("\n\t\t*\t\t In Danh Sach Sinh Vien Hien Co                                       *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo Ten                                          *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo ID                                           *");
		printf("\n\t\t*\t\t Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                        *");
		printf("\n\t\t*\t\t Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach               *");
		printf("\n\t\t*\t\t In Ra Danh Sach Sinh Vien Theo Ten Lop                               *");
		printf("\n\t\t*\t\t Xoa Thong Tin Sinh Vien Theo Id                                      *");
		printf("\n\t\t*\t\t Chinh Sua Thong Tin Sinh Vien                                        *");
		printf("\n\t\t*\t\t Ghi File                                                             *");
		printf("\n\t\t*\t\t Doc File                                                             *"); 
		printf("\n\t\t*\t\t Thoat Khoi Chuong Trinh                                              *");
		printf("\n\t\t***************************************************************************************");
		
        }
        else if(i==2)
        {
                system("cls");
           
	  	printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t Them Sinh Vien Vao He Thong                                          *");
		printf("\n\t\t*\t\t >> In Danh Sach Sinh Vien Hien Co                                    *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo Ten                                          *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo ID                                           *");
		printf("\n\t\t*\t\t Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                        *");
		printf("\n\t\t*\t\t Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach               *");
		printf("\n\t\t*\t\t In Ra Danh Sach Sinh Vien Theo Ten Lop                               *");
		printf("\n\t\t*\t\t Xoa Thong Tin Sinh Vien Theo Id                                      *");
		printf("\n\t\t*\t\t Chinh Sua Thong Tin Sinh Vien                                        *");
		printf("\n\t\t*\t\t Doc File                                                             *");
		printf("\n\t\t*\t\t Ghi File                                                             *"); 
		printf("\n\t\t*\t\t Thoat Khoi Chuong Trinh                                              *");
		printf("\n\t\t***************************************************************************************");
		
        }
        else if(i==3)
        {
            system("cls");
           
		printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t Them Sinh Vien Vao He Thong                                          *");
		printf("\n\t\t*\t\t In Danh Sach Sinh Vien Hien Co                                       *");
		printf("\n\t\t*\t\t >> Tim Kiem Sinh Vien Theo Ten                                       *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo ID                                           *");
		printf("\n\t\t*\t\t Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                        *");
		printf("\n\t\t*\t\t Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach               *");
		printf("\n\t\t*\t\t In Ra Danh Sach Sinh Vien Theo Ten Lop                               *");
		printf("\n\t\t*\t\t Xoa Thong Tin Sinh Vien Theo Id                                      *");
		printf("\n\t\t*\t\t Chinh Sua Thong Tin Sinh Vien                                        *");
		printf("\n\t\t*\t\t Ghi File                                                             *");
		printf("\n\t\t*\t\t Doc File                                                             *"); 
		printf("\n\t\t*\t\t Thoat Khoi Chuong Trinh                                              *");
		printf("\n\t\t***************************************************************************************");
		}
        else if(i==4)
        {
           system("cls");
           
		printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t Them Sinh Vien Vao He Thong                                          *");
		printf("\n\t\t*\t\t In Danh Sach Sinh Vien Hien Co                                       *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo Ten                                          *");
		printf("\n\t\t*\t\t >> Tim Kiem Sinh Vien Theo ID                                        *");
		printf("\n\t\t*\t\t Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                        *");
		printf("\n\t\t*\t\t Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach               *");
		printf("\n\t\t*\t\t In Ra Danh Sach Sinh Vien Theo Ten Lop                               *");
		printf("\n\t\t*\t\t Xoa Thong Tin Sinh Vien Theo Id                                      *");
		printf("\n\t\t*\t\t Chinh Sua Thong Tin Sinh Vien                                        *");
		printf("\n\t\t*\t\t Ghi File                                                             *");
		printf("\n\t\t*\t\t Doc File                                                             *"); 
		printf("\n\t\t*\t\t Thoat Khoi Chuong Trinh                                              *");
		printf("\n\t\t***************************************************************************************");
		}
        else if(i==5)
        {
             system("cls");
           
	  	printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t Them Sinh Vien Vao He Thong                                          *");
		printf("\n\t\t*\t\t In Danh Sach Sinh Vien Hien Co                                       *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo Ten                                          *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo ID                                           *");
		printf("\n\t\t*\t\t >> Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                     *");
		printf("\n\t\t*\t\t Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach               *");
		printf("\n\t\t*\t\t In Ra Danh Sach Sinh Vien Theo Ten Lop                               *");
		printf("\n\t\t*\t\t Xoa Thong Tin Sinh Vien Theo Id                                      *");
		printf("\n\t\t*\t\t Chinh Sua Thong Tin Sinh Vien                                        *");
		printf("\n\t\t*\t\t Ghi File                                                             *");
		printf("\n\t\t*\t\t Doc File                                                             *"); 
		printf("\n\t\t*\t\t Thoat Khoi Chuong Trinh                                              *");
		printf("\n\t\t***************************************************************************************");
		}
        else if(i==6)
        {
           system("cls");
           
  		printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t Them Sinh Vien Vao He Thong                                          *");
		printf("\n\t\t*\t\t In Danh Sach Sinh Vien Hien Co                                       *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo Ten                                          *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo ID                                           *");
		printf("\n\t\t*\t\t Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                        *");
		printf("\n\t\t*\t\t >> Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach            *");
		printf("\n\t\t*\t\t In Ra Danh Sach Sinh Vien Theo Ten Lop                               *");
		printf("\n\t\t*\t\t Xoa Thong Tin Sinh Vien Theo Id                                      *");
		printf("\n\t\t*\t\t Chinh Sua Thong Tin Sinh Vien                                        *");
		printf("\n\t\t*\t\t Ghi File                                                             *");
		printf("\n\t\t*\t\t Doc File                                                             *"); 
		printf("\n\t\t*\t\t Thoat Khoi Chuong Trinh                                              *");
		printf("\n\t\t***************************************************************************************");
        }
        else if(i==7)
        {
       system("cls");
  		printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t Them Sinh Vien Vao He Thong                                          *");
		printf("\n\t\t*\t\t In Danh Sach Sinh Vien Hien Co                                       *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo Ten                                          *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo ID                                           *");
		printf("\n\t\t*\t\t Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                        *");
		printf("\n\t\t*\t\t Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach               *");
		printf("\n\t\t*\t\t >> In Ra Danh Sach Sinh Vien Theo Ten Lop                            *");
		printf("\n\t\t*\t\t Xoa Thong Tin Sinh Vien Theo Id                                      *");
		printf("\n\t\t*\t\t Chinh Sua Thong Tin Sinh Vien                                        *");
		printf("\n\t\t*\t\t Ghi File                                                             *");
		printf("\n\t\t*\t\t Doc File                                                             *"); 
		printf("\n\t\t*\t\t Thoat Khoi Chuong Trinh                                              *");
		printf("\n\t\t***************************************************************************************");
        }
        else if(i==8)
        {
           system("cls");
           
		printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t Them Sinh Vien Vao He Thong                                          *");
		printf("\n\t\t*\t\t In Danh Sach Sinh Vien Hien Co                                       *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo Ten                                          *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo ID                                           *");
		printf("\n\t\t*\t\t Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                        *");
		printf("\n\t\t*\t\t Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach               *");
		printf("\n\t\t*\t\t In Ra Danh Sach Sinh Vien Theo Ten Lop                               *");
		printf("\n\t\t*\t\t >> Xoa Thong Tin Sinh Vien Theo Id                                   *");
		printf("\n\t\t*\t\t Chinh Sua Thong Tin Sinh Vien                                        *");
		printf("\n\t\t*\t\t Ghi File                                                             *");
		printf("\n\t\t*\t\t Doc File                                                             *"); 
		printf("\n\t\t*\t\t Thoat Khoi Chuong Trinh                                              *");
		printf("\n\t\t***************************************************************************************");
        }
        else if(i==9)
        {
            system("cls");
           
		printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t Them Sinh Vien Vao He Thong                                          *");
		printf("\n\t\t*\t\t In Danh Sach Sinh Vien Hien Co                                       *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo Ten                                          *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo ID                                           *");
		printf("\n\t\t*\t\t Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                        *");
		printf("\n\t\t*\t\t Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach               *");
		printf("\n\t\t*\t\t In Ra Danh Sach Sinh Vien Theo Ten Lop                               *");
		printf("\n\t\t*\t\t Xoa Thong Tin Sinh Vien Theo Id                                      *");
		printf("\n\t\t*\t\t >> Chinh Sua Thong Tin Sinh Vien                                     *");
		printf("\n\t\t*\t\t Ghi File                                                             *");
		printf("\n\t\t*\t\t Doc File                                                             *"); 
		printf("\n\t\t*\t\t Thoat Khoi Chuong Trinh                                              *");
		printf("\n\t\t***************************************************************************************");
        }
          else if(i==10)
        {
           system("cls");
           
	            
		printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t Them Sinh Vien Vao He Thong                                          *");
		printf("\n\t\t*\t\t In Danh Sach Sinh Vien Hien Co                                       *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo Ten                                          *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo ID                                           *");
		printf("\n\t\t*\t\t Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                        *");
		printf("\n\t\t*\t\t Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach               *");
		printf("\n\t\t*\t\t In Ra Danh Sach Sinh Vien Theo Ten Lop                               *");
		printf("\n\t\t*\t\t Xoa Thong Tin Sinh Vien Theo Id                                      *");
		printf("\n\t\t*\t\t Chinh Sua Thong Tin Sinh Vien                                        *");
		printf("\n\t\t*\t\t >> Ghi File                                                          *");
		printf("\n\t\t*\t\t Doc File                                                             *"); 
		printf("\n\t\t*\t\t Thoat Khoi Chuong Trinh                                              *");
		printf("\n\t\t***************************************************************************************");
        }
          else if(i==11)
        {
           system("cls");
           
			printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t Them Sinh Vien Vao He Thong                                          *");
		printf("\n\t\t*\t\t In Danh Sach Sinh Vien Hien Co                                       *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo Ten                                          *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo ID                                           *");
		printf("\n\t\t*\t\t Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                        *");
		printf("\n\t\t*\t\t Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach               *");
		printf("\n\t\t*\t\t In Ra Danh Sach Sinh Vien Theo Ten Lop                               *");
		printf("\n\t\t*\t\t Xoa Thong Tin Sinh Vien Theo Id                                      *");
		printf("\n\t\t*\t\t Chinh Sua Thong Tin Sinh Vien                                        *");
		printf("\n\t\t*\t\t Ghi File                                                             *");
		printf("\n\t\t*\t\t >> Doc File                                                          *"); 
		printf("\n\t\t*\t\t Thoat Khoi Chuong Trinh                                              *");
		printf("\n\t\t***************************************************************************************");
        }
        else if(i==12)
        {
           system("cls");
           
		printf("\n\n\t\t**********   CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LY THONG TIN SINH VIEN  **********");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*                                                                                     *");
		printf("\n\t\t*\t\t Them Sinh Vien Vao He Thong                                          *");
		printf("\n\t\t*\t\t In Danh Sach Sinh Vien Hien Co                                       *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo Ten                                          *");
		printf("\n\t\t*\t\t Tim Kiem Sinh Vien Theo ID                                           *");
		printf("\n\t\t*\t\t Sap Xep Sinh Vien Theo Ten Va In Ra Danh Sach                        *");
		printf("\n\t\t*\t\t Sap Xep Thong Tin Sinh Vien Theo Id Va In Ra Danh Sach               *");
		printf("\n\t\t*\t\t In Ra Danh Sach Sinh Vien Theo Ten Lop                               *");
		printf("\n\t\t*\t\t Xoa Thong Tin Sinh Vien Theo Id                                      *");
		printf("\n\t\t*\t\t Chinh Sua Thong Tin Sinh Vien                                        *");
		printf("\n\t\t*\t\t Ghi File                                                             *");
		printf("\n\t\t*\t\t Doc File                                                             *"); 
		printf("\n\t\t*\t\t >> Thoat Khoi Chuong Trinh                                           *");
		printf("\n\t\t***************************************************************************************");
        }
        else{}
        
    }
    
}
