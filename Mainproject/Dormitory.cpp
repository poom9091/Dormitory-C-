#include<iostream>
#include<string>
#include<iomanip>
#include<time.h>
#include<fstream>
#include<sstream>
using namespace std;
void admin(char m);
void Cus(char n);
void rate(char r); //กำหนดอัตราค่าน้ำค่าไฟ
void waterele(char b); //ตรวจสอบค่าน้ำค่าไฟ 
int LogIn();
void Register();//ลงทะเบียนลูกค้า
void ADEROOM();//เพิ่มห้อง,ลบห้อง,แก้ไขห้อง
void add();//เพิ่มห้อง
void del();//ลบห้อง
void edit();//แก้ไขห้อง
void maketable(string table[][7]);//เก็บผลจากไฟล์Data of roomเป็น array
void maketableUser(string tableuser[][6]);//เก็บผลจากไฟล์ Data of Userเป็น array
void maketabletochackin(string chackin[][7]);//เก็บผลจากไฟล์Userroom เป็น array
void avali(string table[][7],string avilid[][7]);//คำนวณดูห้องว่าง
void availability();//แสดงห้องว่าง
void selectavail();//เลือกห้องว่าง
void selectroom(string tableuser[][6],string chackin[][7],string user[3]);//เลือกห้องว่าง
void makefile(string table[][7]);////เขียนไฟล์ Data of Room 
void fileuserandroom(string tableuser[][6],string table[][7],string chackin[][7],string user[]);//สร้างไฟล์ User and room
void ExecutiveSummaryReport();//รายงานสรุปสำหรับผู้บริหาร
void Revenue(); //รายรับ
void Expenditure();//รายจ่าย
void SummaryPayroom();//ห้องที่จ่ายเงินแล้ว
void ProfitLoss();//กำไรขาดทุน
void Payroom();//จ่ายเงินค่าเช่า
void PayMoney(string chackin[][7]);//ยืนยันการจ่ายเงิน
void menuCancelroom(); //ยกเลิกการเช่าห้อง
void Cancelroom(string chackin[][7]);//ยืนยันการยกเลิกเช่าห้อง
void random();//random ค่าน้ำ ค่าไฟ
void Customerlistsummary();//สรุปรายการลูกค้า
string convert(float Number);// แปลง ค่าน้ำค่าไฟเป็น string
void waterele(string ratewaterele[]);//เก็บอัตราค่าน้ำค่าไฟจากไฟล์
char menu1,menu2,menu3;
float water,ele;
string table[100][7],tableuser[100][6],chackin[100][7],ratewaterele[2];
string roomofuser;//เก็บห้องของผู้ login
int KindOfRoom;//เก็บประเภทห้องที่อยู่อาศัย
int Count=0;//เก็บวันและเดือนห้องที่อยู่อาศัย
void edittable(string num);
void main()
{
	random();
	do{
	cout << "**************BAIPOON DORMITORY**************" << endl<< endl;
	cout << "Menu main >>" << endl<< endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<<"1. Admin/Dormitory Officer" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left << "2. Customer" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "3. Sign out" << endl;
	cout <<endl<<setfill(' ')<<setw(15)<<" "<<setw(15)<<left<< "Enter menu : ";
	cin >> menu1;
	if(menu1=='1')
	{
		admin(menu1);
	}
	if(menu1=='2')
	{
		if(LogIn()==1){			
			do{
				cout<<"What kind of room are you in? (1.Mount,2.Day) : ";
				cin>>KindOfRoom;
				if(KindOfRoom!=1&&KindOfRoom!=2) cout<<"You enter wrong number"<<endl;
			}while(KindOfRoom!=1&&KindOfRoom!=2);
			if(KindOfRoom==1){
				cout<<"How many months have you been there? ";
				cin>>Count;
			}
			else if(KindOfRoom==2){
				cout<<"How many days have you been there? ";
				cin>>Count;
			}
			Cus(menu1);
		}
	}
	}while(menu1!='3');

}
void admin(char m)
{
	do{
	cout << "\n===========================================" << endl<< endl;
	cout << "****Admin/Dormitory Officer****" << endl<< endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "1.Register" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "2.Add , Delete ,  Edit  Rental rooms" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "3.Check availability" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "4.Rent transaction" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "5.Set water tariff rate" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "6.Report all rental reports" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "7.Exit" << endl<< endl;
	cout <<setfill(' ')<<setw(15)<<" "<<setw(10)<<left<< "Enter menu : ";
	cin >> menu2;
	if(menu2=='1')
	{
		Register();
	}
	if(menu2=='2')
	{
		ADEROOM();
	}
	if(menu2=='3')
	{
		availability();
	}
	if(menu2=='4')
	{
		selectavail();
	}
	if(menu2=='5')
	{
		rate(menu2);
	}
	if(menu2=='6')
	{
		ExecutiveSummaryReport();
	}
	}while(menu2!='7');
}
void Cus(char n)
{
	do{
	cout << "===========================================" << endl;
	cout << "\n****Customer****" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "1.Check rent" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "2.Pay the rent" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "3.Cancel room" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "4.Summary report" << endl;
	cout <<setfill(' ')<<setw(10)<<" "<<setw(10)<<left<< "5.Exit" << endl;
	cout <<setfill(' ')<<setw(15)<<" "<<setw(10)<<left<< "Enter menu : ";
	cin >> menu3;
	if(menu3=='1')
	{
		waterele(menu3);
	}
	if(menu3=='2')
	{
		Payroom();
	}
	if(menu3=='3')
	{
		menuCancelroom();
	}
	if(menu3=='4')
	{
		Customerlistsummary();
	}
	if(menu3=='5'){
		roomofuser="0";
	}
	}while(menu3!='5');
	
}

void rate(char r)
{
	ifstream InFile;
	ofstream OutFile;
	OutFile.open("waterelebill.txt",ios_base::out | ios_base::app);
	cout <<endl<< "===Set water tariff rate===" << endl;
	cout << "Enter water bill : ";
	cin >> water;
	
	cout << "Enter eletricity bill : ";
	cin >> ele;
	OutFile << water << " " << ele << endl;
	OutFile.close();

}

void waterele(char b)
{
	maketabletochackin(chackin);
	waterele(ratewaterele);
		for(int r=0;r<100;r++){
		if(roomofuser==chackin[r][2]){
			int water = atoi(chackin[r][5].c_str());
			int ele = atoi(chackin[r][6].c_str());
			int ratewater= atoi(ratewaterele[0].c_str());
			int rateele= atoi(ratewaterele[1].c_str());
			cout<<""<<setfill('=')<<setw(46)<<""<<endl;
			cout<<setfill(' ')<<setw(10)<<left<<"|  Rates";
			cout<<setfill(' ')<<setw(15)<<left<<"|  Water bill";
			cout<<setfill(' ')<<setw(20)<<left<<"|  Electricity bill";
			cout<<setfill(' ')<<setw(10)<<left<<"|"<<endl;
			cout<<""<<setfill('-')<<setw(46)<<""<<endl;
			if(KindOfRoom==1) {
				cout<<setfill(' ')<<"|"<<setw(9)<<left<<chackin[r][4];
				cout<<setfill(' ')<<"|"<<setw(14)<<left<<water * ratewater;
				cout<<setfill(' ')<<"|"<<setw(19)<<left<<ele * rateele;
				cout<<setfill(' ')<<"|"<<setw(9)<<left<<endl;
				cout<<setfill('=')<<setw(46)<<""<<endl;
			}
			else if(KindOfRoom==2){
				cout<<setfill(' ')<<"|"<<setw(9)<<left<<chackin[r][3];
				cout<<setfill(' ')<<"|"<<setw(14)<<left<<0;
				cout<<setfill(' ')<<"|"<<setw(19)<<left<<0;
				cout<<setfill(' ')<<"|"<<setw(9)<<left<<endl;
				cout<<setfill('=')<<setw(46)<<""<<endl;
			}
			
		}
	}

}
int  LogIn(){
	for(int r=0;r<100;r++){
		for(int c=0;c<7;c++){
			tableuser[r][c]="";
				chackin[r][c]="";
		}
	}
	maketableUser(tableuser);//เก็บผลจากไฟล์ Data of Userเป็น array
	maketabletochackin(chackin);//เก็บผลจากไฟล์Userodroom เป็น array
	string user[2];
	int chack,rowuser;
	cout << "\n===========================================" << endl<< endl;
		do{
			chack=0;
			cout<<"Username :";
			cin>>user[0];
			for(int i=0;i<100;i++){
				if(user[0]==chackin[i][1]){
					chack=1;
					rowuser=i;
				}
			}
			if(user[0]=="0") return 0;
			if(chack==0){
				cout<<"Do not have this Username (Enter 0 to Exit)"<<endl;
			}
		}while(chack==0);
		do{
			chack=0;
			cout<<"Password : ";
			cin>>user[1];
			for(int r=0;r<100;r++){
				if(user[0]==tableuser[r][0]&&user[1]==tableuser[r][1]){
					chack=1;
					cout<<"Login complete"<<endl;
					roomofuser=chackin[rowuser][2];
					cout<<endl<<"=========================="<<"Room "<<roomofuser<<"=========================="<<endl;
					return 1;
				}
			}
			chack=0;
			cout<<"Password Wrong"<<endl;
			return 0;
		}while(chack==0);
}

void Register(){
	ifstream infile;
	ofstream  outfile;
	string user[5];
	string table[100][100];
	int tof=0;
	outfile.open("Data of User.txt",ios_base::app);
	infile.open("Data of User.txt");
	for(int r=0;r<100;r++){
		for(int c=0;c<5;c++){
		infile>>table[r][c];
		}
	}
	infile.close();
	cout << "\n===========================================" << endl<< endl;
	cout<<"Enter Firstname : ";
	cin>>user[2];
	cout<<"Enter Lastname : ";
	cin>>user[3];
	do{
		cout<<"Enter Numberphone : ";
		cin>>user[4];
	}while(user[4].length()!=10);
	cout<<"Enter Username : ";
	cin>>user[0];
	do{
		cout<<"Enter Password : ";
		cin>>user[1];
	}while(user[1].length()<7);
	for(int i=0;i<100;i++){
		if(user[0]==table[i][0]){
			i=200;
			tof=1;
		}else if(user[1]==table[i][1]){
			i=200;
			tof=1;
		}
	}
	if(tof==0){
		for(int i=0;i<5;i++){
			outfile<<setfill(' ')<<setw(15)<<left<<user[i];		
		}
		outfile<<endl;
	}else if(tof==1){
		cout<<"ERROR"<<endl;
	}
	outfile.close();
}

void ADEROOM(){
	int choice;
	ifstream infile;
	ofstream  outfile;
	string table[100][7];
	do{
		cout<<setfill('*')<<setw(30)<<""<<endl;
		cout<<setfill(' ')<<setw(30)<<left<<"  1.Add Room "<<endl;
		cout<<setfill(' ')<<setw(30)<<left<<"  2.Delect Room "<<endl;
		cout<<setfill(' ')<<setw(30)<<left<<"  3.Edit Room "<<endl;
		cout<<setfill(' ')<<setw(30)<<left<<"  4.Back to Mainmanu "<<endl;
		cout<<setfill('*')<<setw(30)<<""<<endl;
		cout<<" Select Manu : ";
		cin>>choice;
		switch (choice){
			case 1 :add();
				break;
			case 2 :del();
				break;
			case 3 :edit();
				break;
			case 4 :break;
			default:
				cout<<setfill('*')<<setw(30)<<""<<endl;
				cout<<"Please Select Manu Again"<<endl;
				break;
		}
	}while(choice != 4);
}
void add(){
	ifstream infile;
	ofstream  outfile;
	string table[100][7];
	maketable(table);
	int tof=0,digi=0;
	string option[7];
	outfile.open("Data of Room.txt",ios_base::app);
	cout<<setfill('*')<<setw(30)<<""<<endl;
	do{
		cout<<" Enter Status (1. Full,2. Emply ) : ";
		cin>>option[0];
	}while(option[0]!="1"&&option[0]!="2");
	do{
		cout<<" Enter Room : ";
		cin>>option[1];
	}while(option[1].length()>3&&option[1].length()<0);
	cout<<" Enter Building : ";
	cin>>option[2];
	cout<<" Enter Type of Room : ";
	cin>>option[3];
	do{
		digi=0;
		cout<<" Enter Price of Room a Day : ";
		cin>>option[4];
		char tab[1024];
		strcpy(tab, option[4].c_str());
			for (int i=0; i<strlen(tab); i++){
				if (isdigit(tab[i])==0) {
					digi=1;
				}
			}
	}while(digi!=0);
	do{
		digi=0;
		cout<<" Enter Price of Room a Mount : ";
		cin>>option[5];
		char tab[1024];
		strcpy(tab, option[5].c_str());
			for (int i=0; i<strlen(tab); i++){
				if (isdigit(tab[i])==0) {
					digi=1;
				}
			}
	}while(digi!=0);
	cout<<" Enter Furniger : ";
	cin>>option[6];
	for(int i=0;i<100;i++){
		if(option[1]==table[i][1]){
			i=200;
			tof=1;
			cout<<setfill('*')<<setw(30)<<""<<endl;
			cout<<"You can not add this room"<<endl;
		}
	}
	if(tof==0){
		for(int i=0;i<7;i++){
				outfile<<setfill(' ')<<setw(15)<<left<<option[i];		
		}outfile<<endl;
		cout<<setfill('*')<<setw(30)<<""<<endl;
		cout<<"Add room complete "<<endl;
	}
}
void del(){
	ifstream infile;
	ofstream  outfile;
	string table[100][7];
	maketable(table);
	int tof=0,check=0;
	string rtd;
	cout<<setfill('*')<<setw(30)<<""<<endl;
	cout<<" Select Room  to Delete : ";
	cin>>rtd;
	if(tof==0){
		for(int i=0;i<100;i++){
			if(table[i][1]==rtd){
				outfile.open("Data of Room.txt",ios_base::out);
				for(int r=0;r<100;r++){
						if(table[r][0]!=""){
							if(r!=i){
								for(int c=0;c<7;c++){
									outfile<<setfill(' ')<<setw(15)<<left<<table[r][c];
								}outfile<<endl;
							}
						}
				}
				i=100;
				cout<<setfill('*')<<setw(30)<<""<<endl;
				cout<<" Delete room complete "<<endl;
				outfile.close();
				check=1;
			}else if(i==99&&table[i][1]!=rtd&&check==0){
				cout<<setfill('*')<<setw(30)<<""<<endl;
				cout<<" Not Fount"<<endl;
			}
		}
	}
}
void edit(){
	ifstream infile;
	ofstream  outfile;
	string table[100][7];
	string edit[7];
	maketable(table);
	int check=0,digi=0;
	string rte;
	cout<<endl<<" Select Room  to Edit : ";
	cin>>rte;
	for(int i=0;i<100;i++){
		if(table[i][1]==rte){
			outfile.open("Data of Room.txt",ios_base::out);
			cout<<setfill('*')<<setw(30)<<""<<endl;
			do{
				cout<<" Enter Status (1. Full,2. Emply ) : ";
				cin>>edit[0];
			}while(edit[0]!="1"&&edit[0]!="2");
			do{
				cout<<" Enter Room : ";
				cin>>edit[1];
			}while(edit[1].length()>3&&edit[1].length()<0);
			cout<<" Enter Building : ";
			cin>>edit[2];
			cout<<" Enter Type of Room : ";
			cin>>edit[3];
			do{
		digi=0;
		cout<<" Enter Price of Room a Day : ";
		cin>>edit[4];
		char tab[1024];
		strcpy(tab, edit[4].c_str());
			for (int i=0; i<strlen(tab); i++){
				if (isdigit(tab[i])==0) {
					digi=1;
				}
			}
	}while(digi!=0);
	do{
		digi=0;
		cout<<" Enter Price of Room a Mount : ";
		cin>>edit[5];
		char tab[1024];
		strcpy(tab, edit[5].c_str());
			for (int i=0; i<strlen(tab); i++){
				if (isdigit(tab[i])==0) {
					digi=1;
				}
			}
	}while(digi!=0);
			cout<<"Enter Furniger : ";
			cin>>edit[6];
			for(int c=0;c<7;c++){
				table[i][c]=edit[c];
			}
			for(int r=0;r<100;r++){
				if(table[r][0]!=""){
					for(int c=0;c<7;c++){
						outfile<<setfill(' ')<<setw(15)<<left<<table[r][c];
					}outfile<<endl;
				}
			}
			cout<<setfill('*')<<setw(30)<<""<<endl;
			cout<<"Edit room complete "<<endl;
			outfile.close();
			check=1;
		}
		else if(i==99&&table[i][1]!=rte&&check==0){
			cout<<setfill('*')<<setw(30)<<""<<endl;
			cout<<" Not Fount"<<endl;
		}
	}
}
void maketable(string table[][7]){
	ifstream infile;
	ofstream  outfile;
	infile.open("Data of room.txt");
	for(int r=0;r<100;r++){
		for(int c=0;c<7;c++){
			infile>>table[r][c];
		}
	}
	infile.close();
}
void maketableUser(string tableuser[][6]){
	ifstream infile;
	ofstream  outfile;
	infile.open("Data of User.txt");
	for(int r=0;r<100;r++){
		for(int c=0;c<5;c++){
		infile>>tableuser[r][c];
		}
	}
	infile.close();
}
void  maketabletochackin(string chackin[][7]){
	ifstream infile;
	ofstream  outfile;
	infile.open("UserRoom.txt");
	for(int r=0;r<100;r++){
		for(int c=0;c<7;c++){
		infile>>chackin[r][c];
		}
	}
	infile.close();
}
void availability(){
	string avilid[100][7];
	string table[100][7];
	ifstream InFile;
	ofstream OutFile;
	cout << "				---------------------------------------					" << endl;
	cout << "				|           Check availability        |					" << endl;
	cout << "				---------------------------------------					" << endl;
	avali( table, avilid);
}
void avali(string table[][7],string avilid[][7])
{
	int CT[3];
	for(int i =0; i<3; i++){
		CT[i] = 0;
	}
	ifstream infile;
	ofstream  outfile;
	infile.open("Data of room.txt");
	for(int r=0;r<100;r++)
	{	
		for(int c=0;c<7;c++)
		{
			infile>>table[r][c];
		}
	}
	cout << setfill('-')<<setw(110)<<'-'<<endl;
	cout << setfill(' ')<<setw(5) << " Room Status "<<setw(2)<<right<< " : ";
	cout << setw(8) << " Room Code "<<setw(5)<<right<< " : ";
	cout << setw(11) << " Building "<<setw(5)<<right<< " : ";
	cout << setw(10) << " Kind of Room "<< " : ";
	cout << setw(10) << " Price/Day "<<setw(4)<<right<< " : ";
	cout << setw(10) << " Price/Month "<<setw(3)<<right<< " : ";
	cout << setw(10) << " Furniture "<<setw(5)<<right<< " : " << endl;
	cout << setfill('-')<<setw(110)<<'-'<< endl;
	for(int r=0;r<100;r++)
	{
		if(table[r][0] == "2"){
			for(int c=0;c<7;c++)
			{
				cout << setfill(' ') <<  setw(10) <<left<< table[r][c] <<setw(6)<<right<< " : ";
			}
			cout << endl;
			if(table[r][2] == "1"&&table[r][0] == "2")
				{
					CT[0]+=1;
				}
			else if(table[r][2] == "2"&&table[r][0] == "2")
				{
					CT[1]+=1;
				}
			else if(table[r][2] == "3"&&table[r][0] == "2")
				{
					CT[2]+=1;
				}
		}

	}
	cout << setfill('-')<<setw(110)<<'-'<<endl;
	cout << endl;
	cout << "Building 1 have room availability : " << CT[0] << endl;
	cout << "Building 2 have room availability : " << CT[1] << endl;
	cout << "Building 3 have room availability : " << CT[2] << endl;
}
void selectavail(){
	ifstream infile;
	ofstream  outfile;
	string user[3];
	string table[100][7];//ไฟล์ ห้อง 
	string tableuser[100][6];//ไฟล์ user	
	maketable(table);	
	selectroom(tableuser,table,user);
	makefile(table);
}
void makefile(string table[][7]){
	ifstream infile;
	ofstream  outfile;
	outfile.open("Data of Room.txt",ios_base::out);
	for(int r=0;r<100;r++){
			if(table[r][0]!=""){
				for(int c=0;c<7;c++){
					outfile<<setfill(' ')<<setw(15)<<left<<table[r][c];
				}outfile<<endl;
			}
	}
	outfile.close();
}
void selectroom(string tableuser[][6],string table[][7],string user[3]){
	ifstream infile;
	ofstream  outfile;
	int chack;
	int row,rowuser;
	string chackin[100][7];//ไฟล์ User and room 
	maketableUser(tableuser);
	cout << "\n===========================================" << endl<< endl;
	do{
		chack=0;
		cout<<"Select room  : ";
		cin>>user[0];
		for(int i=0;i<100;i++){
			if(user[0]==table[i][1]&&table[i][0]=="2"){
				chack=1;
				row=i;
			}else if(user[0]=="0") chack=1;
		}
		if(chack==0){
			cout<<"Do not have this room (Enter 0 to Exit)"<<endl;
		}
	}while(chack==0);
	if(user[0]!="0"){
		do{
			chack=0;
			cout<<"Username :";
			cin>>user[1];
			for(int i=0;i<100;i++){
				if(user[1]==tableuser[i][0]){
					chack=1;
					rowuser=i; 
				}else if(user[1]=="0") chack=1;
			}
			if(chack==0){
				cout<<"Do not have this Username (Enter 0 to Exit)"<<endl;
			}
		}while(chack==0);
	}
	if(user[1]!="0"&&user[0]!="0"){
		do{
			chack=0;
			cout<<"Password : ";
			cin>>user[2];
			if(user[2]==tableuser[rowuser][1]){
				chack=1;
				table[row][0]="1";

				fileuserandroom(tableuser, table,chackin,user);
				cout << "\n===========================================" << endl<< endl;
				cout<<"Check in complete"<<endl;
			}else if(user[2]=="0") chack=1;
			else{
				chack=0;
				cout<<"Password Wrong (Enter 0 to Exit)"<<endl;
			}
		}while(chack==0);
	}
}
void fileuserandroom(string tableuser[][6],string table[][7],string chackin[][7],string user[]){
	ifstream infile;
	ofstream  outfile;
	outfile.open("UserRoom.txt",ios_base::app);
		outfile<<setfill(' ')<<setw(15)<<left<<"0";
		outfile<<setfill(' ')<<setw(15)<<left<<user[1];
		outfile<<setfill(' ')<<setw(15)<<left<<user[0];
		for(int r=0;r<100;r++){
			if(table[r][1]==user[0])
				outfile<<setfill(' ')<<setw(15)<<left<<table[r][4];
		}
		for(int r=0;r<100;r++){
			if(table[r][1]==user[0])
				outfile<<setfill(' ')<<setw(15)<<left<<table[r][5];
		}
		outfile<<setfill(' ')<<setw(15)<<left<<"0";
		outfile<<setfill(' ')<<setw(15)<<left<<"0";
		outfile<<endl;
		edittable("1");
}
void PayMoney(string chackin[][7]){
	
	for(int i=0;i<100;i++){
		if(roomofuser==chackin[i][2]){
			chackin[i][0]="1";
			ifstream infile;
			ofstream  outfile;
			outfile.open("UserRoom.txt",ios_base::out);
			for(int r=0;r<100;r++){
				if(chackin[r][0]!=""){
					for(int c=0;c<7;c++){
						outfile<<setfill(' ')<<setw(15)<<left<<chackin[r][c];
					}outfile<<endl;
				}
			}

		}
	}
}
void Payroom(){
	maketabletochackin(chackin);
	int pay;
	for(int c=0;c<100;c++){
		if(chackin[c][2]==roomofuser&&(chackin[c][0]=="1"||chackin[c][0]=="2")){
			cout<<"You have already paid the rent. "<<endl;
		}else if(chackin[c][2]==roomofuser&&chackin[c][0]=="0"){
			do{
				cout<<"Do you want to pay rent (1.Yes,2.No): ";
				cin>>pay;
				if(pay==1) PayMoney(chackin);
			}while(pay != 1&&pay != 2);
		}
	}

}
void menuCancelroom(){
	int anwer;
	cout<<"Do you want to cancel rental (1.Yes,2.No) : ";
	cin>>anwer;
	if (anwer==1) Cancelroom(chackin);
}
void Cancelroom(string chackin[][7]){
	for(int i=0;i<100;i++){
		if(chackin[i][2]==roomofuser&&chackin[i][0]=="0"){
			cout<<"You can not cancle rental because you do not pay the rent."<<endl;
		}
		if(chackin[i][2]==roomofuser&&(chackin[i][0]=="1"||chackin[i][0]=="2")){
			ifstream infile;
			ofstream  outfile;
			maketabletochackin(chackin);
			outfile.open("UserRoom.txt",ios_base::out);
			for(int r=0;r<100;r++){
				if(chackin[r][0]!=""){
					if(r!=i){
						for(int c=0;c<7;c++){
							outfile<<setfill(' ')<<setw(15)<<left<<chackin[r][c];							
						}outfile<<endl;
					}else if (r==i){
						int moneyout;
						if(KindOfRoom==1) moneyout=atoi(chackin[r][5].c_str())+atoi(chackin[r][6].c_str())+atoi(chackin[r][4].c_str());
						else if (KindOfRoom==2) moneyout=atoi(chackin[r][5].c_str())+atoi(chackin[r][6].c_str())+atoi(chackin[r][3].c_str());
						string money;
						ifstream infile;
						ofstream  outfile;
						infile.open("moneyout.txt");
						infile>>money;
						infile.close();
						moneyout+=atoi(money.c_str());
						outfile.open("moneyout.txt");
						outfile<<moneyout;
						outfile.close();
					}
				}
			}
			outfile.close();
			edittable("2");
			cout<<"Canceled complete"<<endl;
		}
	}
}
void ExecutiveSummaryReport(){
	int choice;
	do{
		cout<<"===========================   Executive Summary Report   ==========================="<<endl<<endl;
		cout<<" 1. Revenue"<<endl;
		cout<<" 2. Expenditure"<<endl;
		cout<<" 3. Payroom"<<endl;
		cout<<" 4. Profit and Loss"<<endl;
		cout<<" 5. Back to menu"<<endl;
		cout<<"Enter Menu : ";
		cin>>choice;
		switch(choice){
		case 1 : Revenue();
			break;
		case 2 : Expenditure();
			break;
		case 3 : SummaryPayroom();
			break;
		case 4 : ProfitLoss();
			break;
		case 5 : break;
		default: cout<<"You select wrong menu"<<endl;
		}
	}while(choice!=5);
}
void Revenue(){
	maketabletochackin(chackin);
	int total=0,total1=0;
	for(int r=0;r<100;r++){
			if(chackin[r][0]=="1"){
				for(int c=4;c<7;c++){
					int num=atoi(chackin[r][c].c_str());
					total+=num;
				}
		}
		if(chackin[r][0]=="2"){
			for(int c=3;c<7;c++){
				if(c!=4){
					int num=atoi(chackin[r][c].c_str());
					total1+=num;
				}
			}
		}
	}
	cout<<""<<setfill('=')<<setw(30)<<""<<endl;
	cout<<setfill(' ')<<setw(30/1.5)<<right<<"Revenue "<<endl;
	cout<<""<<setfill('-')<<setw(30)<<""<<endl;
	cout<<setfill(' ')<<setw(15/1.5)<<right<<"Mount";
	cout<<setfill(' ')<<setw(5)<<right<<"|";
	cout<<setfill(' ')<<setw(15/1.5)<<right<<"Day"<<endl;
	cout<<""<<setfill('-')<<setw(30)<<""<<endl;
	cout<<setfill(' ')<<setw(15/1.5)<<right<<total;
	cout<<setfill(' ')<<setw(5)<<right<<"|";
	cout<<setfill(' ')<<setw(15/1.5)<<right<<total1<<endl;
	cout<<""<<setfill('-')<<setw(30)<<""<<endl;
	cout<<setfill(' ')<<setw(20/1.5)<<right<<"Total : "<<total+total1<<endl;
	cout<<""<<setfill('=')<<setw(30)<<""<<endl;
	ofstream  outfile;
	outfile.open("Revenue.txt");
	outfile<<""<<setfill('=')<<setw(30)<<""<<endl;
	outfile<<setfill(' ')<<setw(30/1.5)<<right<<"Revenue "<<endl;
	outfile<<""<<setfill('-')<<setw(30)<<""<<endl;
	outfile<<setfill(' ')<<setw(15/1.5)<<right<<"Mount";
	outfile<<setfill(' ')<<setw(5)<<right<<"|";
	outfile<<setfill(' ')<<setw(15/1.5)<<right<<"Day"<<endl;
	outfile<<""<<setfill('-')<<setw(30)<<""<<endl;
	outfile<<setfill(' ')<<setw(15/1.5)<<right<<total;
	outfile<<setfill(' ')<<setw(5)<<right<<"|";
	outfile<<setfill(' ')<<setw(15/1.5)<<right<<total1<<endl;
	outfile<<""<<setfill('-')<<setw(30)<<""<<endl;
	outfile<<setfill(' ')<<setw(20/1.5)<<right<<"Total : "<<total+total1<<endl;
	outfile<<""<<setfill('=')<<setw(30)<<""<<endl;
	outfile.close();

}
void Expenditure(){
	maketabletochackin(chackin);
	int totalwater=0,totalele=0,homemom=9000,office=12000,total;
	for(int r=0;r<100;r++){
		int water=atoi(chackin[r][5].c_str());
		totalwater+=water;
		int ele=atoi(chackin[r][6].c_str());
		totalwater+=ele;

	}
	total=homemom+office+totalwater+totalele;
	cout<<""<<setfill('=')<<setw(80)<<""<<endl;
	cout<<setfill(' ')<<setw(45)<<right<<"Expenditure "<<endl;
	cout<<""<<setfill('-')<<setw(80)<<""<<endl;
	cout<<setfill(' ')<<setw(20/1.5)<<right<<"Water";
	cout<<setfill(' ')<<setw(5)<<right<<"|";
	cout<<setfill(' ')<<setw(20/1.5)<<right<<"Ele";
	cout<<setfill(' ')<<setw(5)<<right<<"|";
	cout<<setfill(' ')<<setw(20/1.5)<<right<<"homemom";
	cout<<setfill(' ')<<setw(5)<<right<<"|";
	cout<<setfill(' ')<<setw(20/1.5)<<right<<"office"<<endl;
	cout<<""<<setfill('-')<<setw(80)<<""<<endl;
	cout<<setfill(' ')<<setw(20/1.5)<<right<<totalwater;
	cout<<setfill(' ')<<setw(5)<<right<<"|";
	cout<<setfill(' ')<<setw(20/1.5)<<right<<totalele;
	cout<<setfill(' ')<<setw(5)<<right<<"|";
	cout<<setfill(' ')<<setw(20/1.5)<<right<<homemom;
	cout<<setfill(' ')<<setw(5)<<right<<"|";
	cout<<setfill(' ')<<setw(20/1.5)<<right<<office<<endl;
	cout<<""<<setfill('-')<<setw(80)<<""<<endl;
	cout<<setfill(' ')<<setw(20/1.5)<<right<<"Total : "<<total<<endl;
	cout<<""<<setfill('=')<<setw(80)<<""<<endl;
	ofstream  outfile;
	outfile.open("Expenditure.txt");
	outfile<<""<<setfill('=')<<setw(80)<<""<<endl;
	outfile<<setfill(' ')<<setw(45)<<right<<"Expenditure "<<endl;
	outfile<<""<<setfill('-')<<setw(80)<<""<<endl;
	outfile<<setfill(' ')<<setw(20/1.5)<<right<<"Water";
	outfile<<setfill(' ')<<setw(5)<<right<<"|";
	outfile<<setfill(' ')<<setw(20/1.5)<<right<<"Ele";
	outfile<<setfill(' ')<<setw(5)<<right<<"|";
	outfile<<setfill(' ')<<setw(20/1.5)<<right<<"homemom";
	outfile<<setfill(' ')<<setw(5)<<right<<"|";
	outfile<<setfill(' ')<<setw(20/1.5)<<right<<"office"<<endl;
	outfile<<""<<setfill('-')<<setw(80)<<""<<endl;
	outfile<<setfill(' ')<<setw(20/1.5)<<right<<totalwater;
	outfile<<setfill(' ')<<setw(5)<<right<<"|";
	outfile<<setfill(' ')<<setw(20/1.5)<<right<<totalele;
	outfile<<setfill(' ')<<setw(5)<<right<<"|";
	outfile<<setfill(' ')<<setw(20/1.5)<<right<<homemom;
	outfile<<setfill(' ')<<setw(5)<<right<<"|";
	outfile<<setfill(' ')<<setw(20/1.5)<<right<<office<<endl;
	outfile<<""<<setfill('-')<<setw(80)<<""<<endl;
	outfile<<setfill(' ')<<setw(20/1.5)<<right<<"Total : "<<total<<endl;
	outfile<<""<<setfill('=')<<setw(80)<<""<<endl;
	outfile.close();
}
void SummaryPayroom(){
	maketabletochackin(chackin);
	ofstream  outfile;
	outfile.open("Payroom.txt");
	outfile<<"Room pay : ";
	cout<<""<<setfill('=')<<setw(30)<<""<<endl;
	cout<<"Room pay : ";
	for(int r=0;r<100;r++){
		if(chackin[r][0]!=""){
			if(chackin[r][0]!="0"){
				cout<<chackin[r][2]<<"     ";
				outfile<<chackin[r][2]<<"     ";
			}
		}

	}cout<<endl;

	outfile<<endl;
	cout<<"Room do not pay : ";
	outfile<<"Room do not pay : ";
	
	for(int r=0;r<100;r++){
		if(chackin[r][0]!=""){
			if(chackin[r][0]=="0"){
				cout<<chackin[r][2]<<"     ";
				outfile<<chackin[r][2]<<"     ";
			}
		}
	}cout<<endl;
	cout<<""<<setfill('=')<<setw(30)<<""<<endl;
	outfile<<endl;
}
void ProfitLoss(){
	ifstream infile;
	ofstream  outfile;
	infile.open("Revenue.txt");
	string table1[100];
	for(int r=0;r<100;r++){
		infile>>table1[r];
		}	
	infile.close();
	int Profit=atoi(table1[13].c_str());//รายได้
	infile.open("Expenditure.txt");
	for(int r=0;r<100;r++){
		infile>>table1[r];
		}	
	infile.close();
	int Loss=atoi(table1[21].c_str());//รายจ่าย
	cout<<""<<setfill('=')<<setw(30)<<""<<endl;
	int money1,money2;
	if(Profit<Loss){
		money1=0;
		money2=Loss-Profit;
	}else if(Profit<Loss){
		money1=Profit-Loss;
		money2=0;
	}
	cout<<"Profit : "<<money1<<endl;
	cout<<"Loss : "<<money2<<endl;
	cout<<""<<setfill('=')<<setw(30)<<""<<endl;
	outfile.open("ProfitLoss.txt");
	outfile<<"Profit : "<<money1<<endl;
	outfile<<"Loss : "<<money2<<endl;
	outfile.close();
}
void waterele(string ratewaterele[]){
	ifstream infile;
	ofstream  outfile;
	infile.open("waterelebill.txt");
	for(int c=0;c<2;c++){
		infile>>ratewaterele[c];
	}
	infile.close();
}
void random()
{
	srand(time(0));
	maketabletochackin(chackin);
	ifstream InFile;
	ofstream OutFile;
	OutFile.open("UserRoom.txt");
	ostringstream ss;
	for(int r=0;r<100;r++)
	{
		if(chackin[r][0] != ""){
		
			for(int c=0;c<7;c++)
			{
				if(c != 5&&c!=6){
					OutFile << setfill(' ')<<setw(15) << left<<chackin[r][c];
				}
				if(c==5){	
					float w = rand()%50;
					string wat = convert(w);
					OutFile << setfill(' ')<<setw(15) << left<<wat;
				}else if(c==6){
					float e = rand()%50;
					string elec = convert(e);
					OutFile << setfill(' ')<<setw(15) << left<<elec;
				}

			}OutFile << endl;
			
		}
	}
	OutFile.close();

}
string convert(float Number){
     std::ostringstream ss;
     ss << Number;
     return ss.str();
}
void Customerlistsummary(){
	maketabletochackin(chackin);
	waterele(ratewaterele);
	string roomoutfile=roomofuser+".txt";
	int ratewater= atoi(ratewaterele[0].c_str());
	int rateele= atoi(ratewaterele[1].c_str());
	int totalwater=0,totalele=0;
	for (int w = 0;w<Count;w++){
		totalwater += rand()%50;
		totalele += rand()%50;
	}
	cout<<""<<setfill('=')<<setw(46)<<""<<endl;
	cout<<setfill(' ')<<setw(10)<<left<<"|  Rates";
	cout<<setfill(' ')<<setw(15)<<left<<"|  Water bill";
	cout<<setfill(' ')<<setw(20)<<left<<"|  Electricity bill";
	cout<<setfill(' ')<<setw(10)<<left<<"|"<<endl;
	cout<<""<<setfill('-')<<setw(46)<<""<<endl;
	for(int r=0;r<100;r++){
		if(roomofuser==chackin[r][2]){
			if(KindOfRoom==1){
				int ratemount=atoi(chackin[r][4].c_str());
				cout<<setfill(' ')<<"|"<<setw(9)<<left<<ratemount*Count;
				cout<<setfill(' ')<<"|"<<setw(14)<<left<<totalwater*ratewater;
				cout<<setfill(' ')<<"|"<<setw(19)<<left<<totalele*rateele;
				cout<<setfill(' ')<<"|"<<setw(9)<<left<<endl;
				cout<<setfill('=')<<setw(46)<<""<<endl;
				ofstream  outfile;
				outfile.open("Summary list "+roomoutfile);
				outfile<<"You have been here for "<<Count<<" months"<<endl;
				outfile<<""<<setfill('=')<<setw(46)<<""<<endl;
				outfile<<setfill(' ')<<setw(10)<<left<<"|  Rates";
				outfile<<setfill(' ')<<setw(15)<<left<<"|  Water bill";
				outfile<<setfill(' ')<<setw(20)<<left<<"|  Electricity bill";
				outfile<<setfill(' ')<<setw(10)<<left<<"|"<<endl;
				outfile<<""<<setfill('-')<<setw(46)<<""<<endl;
				outfile<<setfill(' ')<<"|"<<setw(9)<<left<<ratemount*Count;
				outfile<<setfill(' ')<<"|"<<setw(14)<<left<<totalwater*ratewater;
				outfile<<setfill(' ')<<"|"<<setw(19)<<left<<totalele*rateele;
				outfile<<setfill(' ')<<"|"<<setw(9)<<left<<endl;
				outfile<<setfill('=')<<setw(46)<<""<<endl;
				outfile.close();
			}else if(KindOfRoom==2){
				int rateday=atoi(chackin[r][3].c_str());
				cout<<setfill(' ')<<"|"<<setw(9)<<left<<rateday*Count;
				cout<<setfill(' ')<<"|"<<setw(14)<<left<<0;
				cout<<setfill(' ')<<"|"<<setw(19)<<left<<0;
				cout<<setfill(' ')<<"|"<<setw(9)<<left<<endl;
				cout<<setfill('=')<<setw(46)<<""<<endl;
				ofstream  outfile;
				outfile.open("Summary list "+roomoutfile);
				outfile<<"You have been here for "<<Count<<" Day"<<endl;
				outfile<<""<<setfill('=')<<setw(46)<<""<<endl;
				outfile<<setfill(' ')<<setw(10)<<left<<"|  Rates";
				outfile<<setfill(' ')<<setw(15)<<left<<"|  Water bill";
				outfile<<setfill(' ')<<setw(20)<<left<<"|  Electricity bill";
				outfile<<setfill(' ')<<setw(10)<<left<<"|"<<endl;
				outfile<<""<<setfill('-')<<setw(46)<<""<<endl;
				outfile<<setfill(' ')<<"|"<<setw(9)<<left<<rateday*Count;
				outfile<<setfill(' ')<<"|"<<setw(14)<<left<<0;
				outfile<<setfill(' ')<<"|"<<setw(19)<<left<<0;
				outfile<<setfill(' ')<<"|"<<setw(9)<<left<<endl;
				outfile<<setfill('=')<<setw(46)<<""<<endl;
				outfile.close();
			}
		}
	}
}
void edittable(string num){
	ofstream outfile;
	maketable(table);
			for(int i=0;i<100;i++){
				if(table[i][0]!=""){
					if(table[i][1]==roomofuser){
						table[i][0]=num;
					}
				}
			}
	makefile(table);
}