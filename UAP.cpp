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


void dadu1(){
	WINDOW * win2 = newwin (7,13,12,54);
	refresh();
	box(win2,0,0);
	mvwprintw(win2,3,6,"0");
	wrefresh(win2);
}

void dadu2(){
	WINDOW * win2 = newwin (7,13,12,54);
	refresh();
	box(win2,0,0);		
	mvwprintw(win2,1,1,"0");
	mvwprintw(win2,5,11,"0");
	wrefresh(win2);
}

void dadu3(){
	WINDOW * win2 = newwin (7,13,12,54);
	refresh();
	box(win2,0,0);	
	mvwprintw(win2,1,1,"0");
	mvwprintw(win2,3,6,"0");
	mvwprintw(win2,5,11,"0");
	wrefresh(win2);		
}

void dadu4(){
	WINDOW * win2 = newwin (7,13,12,54);
	refresh();
	box(win2,0,0);	
	mvwprintw(win2,1,1,"0");
	mvwprintw(win2,5,11,"0");
	mvwprintw(win2,1,11,"0");
	mvwprintw(win2,5,1,"0");
	wrefresh(win2);	
}

void dadu5(){
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

void dadu6(){
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

void kocok(){
	
	string kocok [6] = {"dadu1","dadu2","dadu3","dadu4","dadu5","dadu6"};
	
	
	
	for(int i=0;i<6;i++){
		
		kocok [i];
		refresh();
		Sleep(100);
		clear();
		
	}
	
}

void gamedadu(){
    float bilangan[memory];
    short int tebakan;
    short int dadu;
	
	srand(time(NULL));
	dadu = rand()%6+1;
	echo();
	
	WINDOW * win3 = newwin (7,21,12,50);
	refresh();
	box(win3,0,0);
	wrefresh(win3);
	mvwprintw(win3,1,4,"TEBAKAN ANDA");
	wrefresh(win3);
mvwscanw(win3,3,10,"%d", &tebakan);
	refresh();
	clear();
	kocok();
	
	switch (dadu){
		
		case 1:
		dadu1();
		break;
		
		case 2:
		dadu2();
		break;
		
		case 3:
		dadu3();
		break;
		
		case 4:
		dadu4();
		break;
		
		case 5:
		dadu5();
		break;
		
		case 6:
		dadu6();
		break;
	}
		
	if(tebakan == dadu){
		
		mvprintw(9,54,"Anda Benar !");
		refresh();
		
		}
		else{
			mvprintw(9,54,"Anda Salah !");
			refresh();
				}
			
			char y;
			noecho();
			mvprintw(21,40,"Apakah anda ingin bermain lagi?(y/n) : ");
			y = getch();
			clear();
			
			if(y =='y'){
				goto k;
			}
			else{
				mvprintw(10,46,"Terimakasih telah bermain!");
				Sleep(700);
				exit;
			}
}

int lanjut(){
	clear();
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
	Sleep(700);
	wclear(win1);
	refresh();
	
	box(win1,0,0);
	mvwprintw(win1,3,16," ");
	wrefresh(win1);
	Sleep(700);
	wclear(win1);
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
	Sleep(700);
	wclear(win1);
	refresh();
	
	box(win1,0,0);
	mvwprintw(win1,3,16," ");
	wrefresh(win1);
	Sleep(700);
	wclear(win1);
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
	mvwprintw(win1,17,52,"Press any key !");
	wrefresh(win1);	                                                                                                                                        
	getch();
	Sleep(1000);
	clear();
	gamedadu();
}

void tidak(){
	clear();
	printw("MAAF ANDA BELUM CUKUP UMUR");
	
}

void menu(){
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	
	WINDOW * win1 = newwin (0,0,0,0);
	refresh();
	box(win1,0,0);
	mvwprintw(win1,12,45,"Apakah anda di atas 18 tahun ?");
	mvwprintw(win1,17,50,"IYA");
	mvwprintw(win1,17,65,"TIDAK");
	wrefresh(win1);
	
	char pos ;
	int selection;
	
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
