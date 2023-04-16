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
	
