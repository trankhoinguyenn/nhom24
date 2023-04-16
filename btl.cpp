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

void menu(int chon, SV *ds, int n){
	int flat = 1;
	int sl;
	bool daNhap = false;
	do{
	system("cls");
    sl= Display1();
    	
    	switch(sl){
    		case 1:
    							system("cls");
								if(daNhap){
								n++;
								ThemSV(ds,n);
    							}
    							else{
                    			printf("\n\t\tBAN DA CHON NHAP DANH SACH SINH VIEN\n");   			
    							nhapDanhSachSinhVien(ds, n);
    							printf("\n\t\tBAN DA NHAP THANH CONG");
    							printf("\n");
    							daNhap = true;
                				}
    							nhapPhimBatKy();
    							system("cls");
    							break;
    		case 2:
    							if(daNhap){
								printf("\n\t\tBAN DA CHON XUAT DANH SACH SINH VIEN\n");
								xuatDanhSachSinhVien(ds, n);
    							}
    							else{
                    			printf("\n\t\tHAY NHAP DANH SACH SINH VIEN TRUOC!\n");
                				}
    							nhapPhimBatKy();
								 system("cls");
								break;
    		case 3:
    							
								if(daNhap){
								timSinhVienTheoTen(ds,n);
    						    
    						    }
    						    else{
                    			printf("\n\t\tHAY NHAP DANH SACH SINH VIEN TRUOC!\n");
                				}
    							nhapPhimBatKy();
    							break;
    		case 4:
    							if(daNhap){
								timSinhVienTheoMasv(ds,n);
 								}
    							else{
                    			printf("\n\t\tHAY NHAP DANH SACH SINH VIEN TRUOC!\n");
                				}
								nhapPhimBatKy();
								 system("cls");
								break;
    						
    		case 5:
    						
								if(daNhap){
								printf("\n\t\tBAN DA CHON SAP XEP DANH SACH THEO TEN\n");
								sapXepDanhSachSinhVienTheoTen(ds, n);
                                printf("\n\t\tDanh sach sau khi sap xep theo ten: \n");
                                xuatDanhSachSinhVien(ds, n);
                                }
                                else{
                    			printf("\n\t\tHAY NHAP DANH SACH SINH VIEN TRUOC!\n");
                				}
								nhapPhimBatKy(); 
								break;
    							
    		case 6:
    							if(daNhap){
								printf("\n\t\tBAN DA CHON SAP XEP DANH SACH THEO TEN\n");
								sapXepDanhSachSinhVienTheoID(ds, n);
                                printf("\n\t\tDanh sach sau khi sap xep theo ten: \n");
                                xuatDanhSachSinhVien(ds, n);
                                }
                                else{
                    			printf("\n\t\tHAY NHAP DANH SACH SINH VIEN TRUOC!\n");
                				}
								nhapPhimBatKy(); 
								break;
    							
    		case 7:
    							char lop[20];
    							if(daNhap){
    							printf("\n\t\tBAN DA CHON XUAT DANH SACH SINH VIEN THEO LOP\n");
    						
    							xuatDanhSachSinhVienTheoLop(ds, n);
    							}
								else{
                    			printf("\n\t\tHAY NHAP DANH SACH SINH VIEN TRUOC!\n");
                				}
								nhapPhimBatKy();
    							break;
			case 8:
								
    							if(daNhap){
    							printf("\n\t\tBAN DA CHON XOA SINH VIEN THEO MSV\n");
								xoaSinhVienTheoMSV(ds, n);
	                            printf("\n\t\tDanh sach sinh vien sau khi xoa: \n");
	                            xuatDanhSachSinhVien(ds, n);	 
	                        	}
	                        	else{
                    			printf("\n\t\tHAY NHAP DANH SACH SINH VIEN TRUOC!\n");
                				}
	                            nhapPhimBatKy(); system("cls");
	                            break;
								
			case 9:
								if(daNhap){
    							printf("\n\t\tBAN DA CHON SUA THONG TIN SINH VIEN\n");
    							fflush(stdin);
    							capNhatSV(ds,n);
	                        	}
	                        	else{
                    			printf("\n\t\tHAY NHAP DANH SACH SINH VIEN TRUOC!\n");
                				}
	                            nhapPhimBatKy(); system("cls");
    							break;
								
    		case 10: 
    							printf("\nBAN DA CHON XUAT DANH SACH SINH VIEN VAO FILE\n");
								xuatVaoFile(ds,n);
								nhapPhimBatKy();
								break;
    					
								
            case 11: 
			                   
								printf("\nBAN DA CHON XUAT DANH SACH SINH VIEN VAO FILE\n");
								nhapTuFile(ds, n);
								nhapPhimBatKy();
								break; 
								
			
						
			default:
                printf("\n\t\tBan Chon Thoat Chuong Trinh!");
                printf("\n\t\tBam phim bat ky de thoat..\n");
                printf("\n");
                getch();
                break;					                   
		}
		
	}
	while(sl!=12);
}

int main(){
    int n, chon;
    SV *ds;
    system("color 35");
    SetColor(767);
    menu(chon, ds, n);
}
