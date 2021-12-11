#include <iostream>
#include <time.h>
#include <ncurses.h>
#include <windows.h>
#define memory 100
	
using namespace std;
WINDOW * win1; // window untuk menu
WINDOW * win2; // window untuk dadu
WINDOW * win3; // window untuk input user




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
