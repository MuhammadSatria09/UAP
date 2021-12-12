#include <time.h>
#include <ncurses.h>
#include <windows.h>
#include <string>
#define memory 100		//untuk mengatasi bug input scanw

using namespace std;

WINDOW * win1; // window untuk menu (Fullscreen)
WINDOW * win2; // window untuk dadu
WINDOW * win3; // window untuk input user

    short int dadu; //Menyimpan data hasil acak untuk dadu yang ingin di tebak
	int saldo = 100; //Sakdo pemain yang akan dikurangkan atau ditambahkan
	int taruhan; //Taruhan pemain
	
	string peraturan[3] = {"1. Dilarang menggunakan cheat","2. Pemain harus berusia minimal 18 tahun","3. Pemain akan diberikan saldo awal $100"};
	string cara[3] = {"1. Pemain diminta untuk memasukkan jumlah taruhan", "2. Pemain diminta untuk menebak angka 1-6" , "3. Selamat bermain"};
	//Peraturan dan tata cara bermain
	
	
void loading(){		//animasi loading bar beserta peringatan
	curs_set(0);
	start_color();
	init_pair(2, COLOR_BLACK, COLOR_WHITE);		//format warna dengan font berwarna hitam dan background putih
	WINDOW * win1 = newwin(0,0,0,0);
	refresh();
	box(win1,0,0);
	
	for(int t= 1;t<=20;t++){
		
	wattron(win1,COLOR_PAIR(2));	
	mvwprintw(win1,10,50+t," ");
	wattroff(win1,COLOR_PAIR(2));
	mvwprintw(win1,12,57,"Loading");
	
	if(t<10){
	mvwprintw(win1,14,47,"Berjudi adalah sebuah dosa");
	mvwprintw(win1,15,54,"Galatia 5:24");
	mvwprintw(win1,16,42,"Barang siapa menjadi milik Yesus, ");
	mvwprintw(win1,17,50,"ia telah menyalibkan");
	mvwprintw(win1,18,34,"daging dengan segala hawa nafsu dan keinginannya.");
	wrefresh(win1);
	Sleep(350);
	}
	else{
	mvwprintw(win1,14,47,"Berjudi adalah sebuah dosa");
	mvwprintw(win1,15,52,"Al-Ma'idah : 90");
	mvwprintw(win1,16,40,"    Wahai orang-orang yang beriman!");
	mvwprintw(win1,17,19,"Sesungguhnya minuman keras, berjudi, (berkurban untuk) berhala, dan mengundi nasib ");
	mvwprintw(win1,18,25,"dengan anak panah, adalah perbuatan keji dan termasuk perbuatan setan.");
	mvwprintw(win1,19,30,"Maka jauhilah (perbuatan-perbuatan) itu agar kamu beruntung.");
	wrefresh(win1);
	Sleep(350);	
	}
}
	wattroff(win1,COLOR_PAIR(2));
		
}


void dadu1(){		//menampilkan gambar untuk dadu ber angka 1
	curs_set(0);
	WINDOW * win2 = newwin (7,13,12,54);
	refresh();
	box(win2,0,0);
	mvwprintw(win2,3,6,"0");
	wrefresh(win2);
}

void dadu2(){		//menampilkan gambar untuk dadu ber angka 2
	curs_set(0);
	WINDOW * win2 = newwin (7,13,12,54);
	refresh();
	box(win2,0,0);		
	mvwprintw(win2,1,1,"0");
	mvwprintw(win2,5,11,"0");
	wrefresh(win2);
}

void dadu3(){		//menampilkan gambar untuk dadu ber angka 3
	curs_set(0);
	WINDOW * win2 = newwin (7,13,12,54);
	refresh();
	box(win2,0,0);	
	mvwprintw(win2,1,1,"0");
	mvwprintw(win2,3,6,"0");
	mvwprintw(win2,5,11,"0");
	wrefresh(win2);		
}

void dadu4(){		//menampilkan gambar untuk dadu ber angka 4
	curs_set(0);
	WINDOW * win2 = newwin (7,13,12,54);
	refresh();
	box(win2,0,0);	
	mvwprintw(win2,1,1,"0");
	mvwprintw(win2,5,11,"0");
	mvwprintw(win2,1,11,"0");
	mvwprintw(win2,5,1,"0");
	wrefresh(win2);	
}

void dadu5(){		//menampilkan gambar untuk dadu ber angka 5
	curs_set(0);
	WINDOW * win2 = newwin (7,13,12,54);
	refresh();
	box(win2,0,0);
	mvwprintw(win2,1,1,"0");
	mvwprintw(win2,5,1,"0");
	mvwprintw(win2,3,6,"0");
	mvwprintw(win2,1,11,"0");
	mvwprintw(win2,5,11,"0");
	wrefresh(win2);		
}

void dadu6(){		//menampilkan gambar untuk dadu ber angka 6
	curs_set(0);
	WINDOW * win2 = newwin (7,13,12,54);
	refresh();
	box(win2,0,0);
	mvwprintw(win2,1,1,"0");
	mvwprintw(win2,3,1,"0");
	mvwprintw(win2,5,1,"0");
	mvwprintw(win2,1,11,"0");
	mvwprintw(win2,3,11,"0");
	mvwprintw(win2,5,11,"0");
	wrefresh(win2);
}

void kocok(){		//Animasi pengocokan dadu
	
		
	for(int i=0;i<5;i++){
		dadu1();
		Sleep(100);
		clear();
		dadu2();
		Sleep(100);
		clear();
		dadu3();
		Sleep(100);
		clear();
		dadu4();
		Sleep(100);
		clear();
		dadu5();
		Sleep(100);
		clear();
		dadu6();
		Sleep(100);
		clear();		
	}
	
}

void gamedadu(){			//Inti game
	k:
	clear();
	WINDOW * win1 = newwin(0,0,0,0);	//window fullscreen
	refresh();
	box(win1,0,0);
	mvwprintw(win1,3,100 ,"Saldo Anda");
	mvwprintw(win1,4,104,"$");
	mvwprintw(win1,4,105,"%d",saldo);
	
	wrefresh(win1);
    float bilangan[memory];	//mengatasi bug input scanw
    short int tebakan;		//menyimpan data tebakan pemain
	
	srand(time(NULL));		//penghasil angka acak untuk dadu yang akan ditebak
	dadu = rand()%6+1;		//menghasilkan angka dari 1-6
	curs_set(1)	;
	echo();					//echo berfungsi untuk membuat input user tertera di layar
	
	WINDOW * win3 = newwin (7,21,12,50);
	refresh();
	box(win3,0,0);
	wrefresh(win3);
	mvwprintw(win3,1,4,"TARUHAN ANDA");
	wrefresh(win3);
	mvwprintw(win3,3,9,"$");
mvwscanw(win3,3,10,"%d", &taruhan);		//menerima input user untuk nominal taruhan
	refresh();
	wclear(win3);
	refresh();
	
	box(win3,0,0);
	wrefresh(win3);
	mvwprintw(win3,1,4,"TEBAKAN ANDA");
	wrefresh(win3);
mvwscanw(win3,3,10,"%d", &tebakan);		//menerima input user untuk angka tebakan pema
	refresh();
	wclear(win3);
	wclear(win1);
	kocok();							//menampilkan animasi pengocokan dadu
	
	refresh();
	box(win1,0,0);
	wrefresh(win1);
	
	switch (dadu){		//switch case untuk hasil pengacakan angka oleh rand
		
		case 1:			//tampilan jika hasil rand merupakan 1
		clear();	
		dadu4();
		Sleep(200);
		clear();
		dadu5();
		Sleep(400);
		clear();
		dadu6();
		Sleep(600);	
		clear();
		dadu1();
		break;
		
		case 2:			//tampilan jika hasil rand merupakan 2
		clear();	
		dadu5();
		Sleep(200);
		clear();
		dadu6();
		Sleep(400);
		clear();
		dadu1();
		Sleep(600);	
		clear();
		dadu2();
		break;
		
		case 3:			//tampilan jika hasil rand merupakan 3
		clear();	
		dadu6();
		Sleep(200);
		clear();
		dadu1();
		Sleep(400);
		clear();
		dadu2();
		Sleep(600);	
		clear();
		dadu3();
		break;
		
		case 4:			//tampilan jika hasil rand merupakan 4
		clear();	
		dadu1();
		Sleep(200);
		clear();
		dadu2();
		Sleep(400);
		clear();
		dadu3();
		Sleep(600);	
		clear();	
		dadu4();
		break;
		
		case 5:			//tampilan jika hasil rand merupakan 5
		clear();	
		dadu2();
		Sleep(200);
		clear();
		dadu3();
		Sleep(400);
		clear();
		dadu4();
		Sleep(600);	
		clear();	
		dadu5();
		break;
		
		case 6:			//tampilan jika hasil rand merupakan 6
		clear();	
		dadu3();
		Sleep(200);
		clear();
		dadu4();
		Sleep(400);
		clear();
		dadu5();
		Sleep(600);	
		clear();
		dadu6();
		break;
	}
		
		
	if(tebakan == dadu){			//pengecekan hasil pengacakan dadu dan tebakan pemain
		curs_set(0);	
		mvprintw(9,54,"Anda Benar !");
		refresh();
		saldo = saldo + taruhan;	//jika menang menambahkan saldo dengan jumlah taruhan pemain
		mvwprintw(win1,4,105,"%d",saldo);
		mvprintw(23,50,"Saldo anda saat ini");
		mvprintw(24,58,"$");
		mvprintw(24,59,"%d",saldo);
		
		}
		else{
			mvprintw(9,54,"Anda Salah !");
			refresh();
			saldo = saldo - taruhan;	//jika kalah mengurangi saldo dengan jumlah taruhan pemain
			mvwprintw(win1,4,105,"%d",saldo);
			mvprintw(23,50,"Saldo anda saat ini");
			mvprintw(24,58,"$");
			mvprintw(24,59,"%d",saldo);
				}
			char y;
			noecho();					//noecho membuat input user tidak tercetak di layar
			if(saldo>0){
			mvprintw(21,40,"Apakah anda ingin bermain lagi?(y/n) : ");
			y = getch();
			clear();
			
			if(y =='y'){
				goto k;					//kembali ke menu input taruhan dan angka
			}
			else{
				mvprintw(15,46,"Terimakasih telah bermain!");	//menghetikan permainan
				Sleep(700);
			}
	}
			else{
				mvprintw(21,60-16,"MAAF SALDO ANDA TIDAK MENCUKUPI");	//menghentikan permainan dengan paksa
				getch();
			}
}

void dadu21(){	//animasi "dadu 21" berkelap kelip
	curs_set(0);
	WINDOW * win1 = newwin (0,0,0,0);
	refresh();
	box(win1,0,0);
	mvwprintw(win1,3,16,"    ,---,       ,---,           ,---,                                ,----,       ,---,");
	mvwprintw(win1,4,16,"  .'  .' `\\    '  .' \\        .'  .' `\\           ,--,             .'   .' \\   ,`--.' | ");
	mvwprintw(win1,5,16,",---.'     \\  /  ;    '.    ,---.'     \\        ,'_ /|           ,----,'    | /    /  : ");
	mvwprintw(win1,6,16,"|   |  .`\\  |:  :       \\   |   |  .`\\  |  .--. |  | :           |    :  .  ;:    |.' '  ");
	mvwprintw(win1,7,16,"|   ' '  ;  :|  :  ' ;.   : |   ' '  ;  :|  ' | |  . .           `----'/  ;     '   ' ; ");
	mvwprintw(win1,8,16,"'   | ;  .  ||  |  ;/  \\   \\'   | ;  .  ||  | ' |  | |             /  ;  /      |   | | ");
	mvwprintw(win1,9,16,"|   | :  |  ''  :  | \\  \\ ,'|   | :  |  ':  | | :  ' ;            ;  /  /-,     '   : ; ");
	mvwprintw(win1,10,16,"'   : | /  ; |  |  '  '--'  '   : | /  ; |  ; ' |  | '           /  /  /.`|     |   | '  ");
	mvwprintw(win1,11,16,"|   | '` ,/  |  :  :        |   | '` ,/  :  | : ;  ; |         ./__;      :     '   : | ");
	mvwprintw(win1,12,16,";   :  .'    |  | ,'        ;   :  .'    '  :  `--'   \\        |   :    .'      ;   |.' ");
	mvwprintw(win1,13,16,"|   ,.'      `--''          |   ,.'      :  ,      .-./        ;   | .'         '---'   ");
	mvwprintw(win1,14,16,"'---'                       '---'         `--`----'            `---'                    ");
	wrefresh(win1);
	Sleep(200);
	wclear(win1);
	refresh();
	
	box(win1,0,0);
	mvwprintw(win1,3,16," ");
	wrefresh(win1);
	Sleep(200);
	wclear(win1);
	refresh();
	
}

void lanjut(){	//jika user menyatakan telah di atas umur
		curs_set(0);
	for(int i=0;i<=3;i++){	//mengulangi animasi kelap kelip "dadu 21" sebanyak 5 kali
		dadu21();
	
	}

	WINDOW * win1 = newwin (0,0,0,0);
	refresh();
	box(win1,0,0);
	mvwprintw(win1,3,16,"    ,---,       ,---,           ,---,                                ,----,       ,---,");
	mvwprintw(win1,4,16,"  .'  .' `\\    '  .' \\        .'  .' `\\           ,--,             .'   .' \\   ,`--.' | ");
	mvwprintw(win1,5,16,",---.'     \\  /  ;    '.    ,---.'     \\        ,'_ /|           ,----,'    | /    /  : ");
	mvwprintw(win1,6,16,"|   |  .`\\  |:  :       \\   |   |  .`\\  |  .--. |  | :           |    :  .  ;:    |.' '  ");
	mvwprintw(win1,7,16,"|   ' '  ;  :|  :  ' ;.   : |   ' '  ;  :|  ' | |  . .           `----'/  ;     '   ' ; ");
	mvwprintw(win1,8,16,"'   | ;  .  ||  |  ;/  \\   \\'   | ;  .  ||  | ' |  | |             /  ;  /      |   | | ");
	mvwprintw(win1,9,16,"|   | :  |  ''  :  | \\  \\ ,'|   | :  |  ':  | | :  ' ;            ;  /  /-,     '   : ; ");
	mvwprintw(win1,10,16,"'   : | /  ; |  |  '  '--'  '   : | /  ; |  ; ' |  | '           /  /  /.`|     |   | '  ");
	mvwprintw(win1,11,16,"|   | '` ,/  |  :  :        |   | '` ,/  :  | : ;  ; |         ./__;      :     '   : | ");
	mvwprintw(win1,12,16,";   :  .'    |  | ,'        ;   :  .'    '  :  `--'   \\        |   :    .'      ;   |.' ");
	mvwprintw(win1,13,16,"|   ,.'      `--''          |   ,.'      :  ,      .-./        ;   | .'         '---'   ");
	mvwprintw(win1,14,16,"'---'                       '---'         `--`----'            `---'                    ");
	mvwprintw(win1,20,52,"Press any key !");
	wrefresh(win1);	         
	noecho();                                                                                                                               
	getch();
	clear();

	kembali:
	clear();
	box(win1,0,0);
	refresh();
	
	//menu sebelum memulai loading gane
char sec;
	mvprintw(14,50,"1. Peraturan Bermain");	//menjelaskan peraturan bermain game
	mvprintw(15,50,"2. Cara Bermain");		//menjelaskan cara memainkan game
	mvprintw(16,50,"3. Mulai Bermain");		//memulai permainan

	sec=getch();
	
	if(sec=='1'){
		clear();
		box(win1,0,0);
		for(int x=0;x<3;x++){
			mvprintw(14+x,45,"%s",peraturan[x].c_str());
		}
		attron(COLOR_PAIR(1));
		mvprintw(19,56,"KEMBALI");
		attroff(COLOR_PAIR(1));
		getch();
		clear();
		WINDOW * win1 = newwin(0,0,0,0);
		box(win1,0,0);
		refresh();
		wrefresh(win1);
		goto kembali;
	}
	if(sec=='2'){
		clear();
		box(win1,0,0);
		for(int x=0;x<3;x++){
			mvprintw(14+x,45,"%s",cara[x].c_str());
		}
		attron(COLOR_PAIR(1));
		mvprintw(19,56,"KEMBALI");
		attroff(COLOR_PAIR(1));
		getch();
		clear();
		WINDOW * win1 = newwin(0,0,0,0);
		box(win1,0,0);
		refresh();
		wrefresh(win1);
		goto kembali;
	}
	if(sec=='3'){
		clear();
		box(win1,0,0);
		
		loading();	
		gamedadu();
	}
	
}

void tidak(){		//jika user mengaku bahwa masih berada di bawah umur
	curs_set(0);
	clear();
	mvprintw(15,47,"MAAF ANDA BELUM CUKUP UMUR");
	
}

void menu(){		//menu pernyataan apakah pemain berada di atas umur
	curs_set(0);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	
	WINDOW * win1 = newwin (0,0,0,0);
	refresh();
	box(win1,0,0);
	mvwprintw(win1,12,45,"Apakah anda di atas 18 tahun ?");
	mvwprintw(win1,17,50,"IYA");
	mvwprintw(win1,17,65,"TIDAK");
	wrefresh(win1);
	
	char pos ;		//mengindikasikan tombol yang di tekan user
	int selection;	//menyimpan pilihan user
	
	for(int i=0; ; ){
		noecho();
		 pos = getch();
		if(pos == 75 ){
		
			wattron(win1,COLOR_PAIR(1));
			mvwprintw(win1,17,50,"IYA");		
			wattroff(win1,COLOR_PAIR(1));
			mvwprintw(win1,17,65,"TIDAK");
			wrefresh(win1);
			selection = 1;
		}
		
		if(pos == 77){
			wattroff(win1,COLOR_PAIR(1));
			mvwprintw(win1,17,50,"IYA");		
			wattron(win1,COLOR_PAIR(1));
			mvwprintw(win1,17,65,"TIDAK");
			wrefresh(win1);
			selection = 2;
		}
		
		if(pos == '\n'){
			
			if(selection == 1){
				lanjut();
				break;
				
			}
			if(selection == 2){
				tidak();
				break;
			}
			
		}
		
	}
	
}

int main(){
		
	initscr();

	menu();
	
	getch();
	
	endwin();
	
}
