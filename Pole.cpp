#define _CRT_SECURE_NO_WARNINGS
#include "Pole.h"
#include <time.h>
#include <stdio.h>
//#include "dictionary_interface.h"
//#include "file_dict.h"
//#include "Constructor.h"
void Pole::pole_z()
{
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			pole[i][j] = 'z';
		}
	}
}



void Pole::pole_print()
{
	printf("   ");
	for (int i = 0; i < 15; i++) {
		printf("%d ", i + 1);
		if (i < 9) printf(" ");

	}
	printf("\n");
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < 15; i++) {
		
		printf("%d ", i+1);
		if (i < 9) printf(" ");
		for (int j = 0; j < 15; j++) {
		if (pole[i][j] == 'z') {
			printf("-  ");
		}
		else   printf("%c  ", pole[i][j]);


		}
		printf("\n");
	}
}

string Pole::return_pole_word(int flag, int num)
{
	//string p="zzzzzzzzzzzzzzz";
	//string pp;
	char p[16];
	string pp;
	if (num < 0 || num >= 15) {
		//printf("wrong number of row or column\n");
		//string pp( p);
		p[0] = '\0';
		pp = (string)p;
		return pp;

	}
	else {
		if (flag == 0) { //it's a row
			for (int i = 0; i < 15; i++) {
				//p.replace(i, i-1, 1, pole[num][i]);
				p[i] = pole[num][i];
			}
		}
		else if (flag == 1) { //it's a column
			for (int i = 0; i < 15; i++) {
				p[i] = pole[i][num];
				//p.replace(i, i-1, 1, pole[i][num]);
			}
		}
		else {
			//printf("wrong flag\n");
			//string pp(p);
			p[0] = '\0';
			pp = (string)p;
			return pp;
		}
	}
	p[15] = '\0';
	pp = (string)p;
	//string s_com = "zzzzëàâåëàñzzzz";
	return pp;

}


void Pole::write_word(string s,int flag, int count, int i , int j)
{
	int u = 0;
	if (i < 0 || i >= 15 || j < 0 || j >= 15) {
		//printf("wrong coordinats\n");
		return;
	}
	if (flag == 0) { //it's a row
	
		for (int y = j; y < j + count; y++) { 
			pole[i][y] = s[y - j]; 
		}
	}
	else if (flag == 1) { //it's a column
		for (int x = i; x < i + count; x++) { pole[x][j] = s[x - i]; }
	}
	else {
		///printf("wrong flag\n");
		return;
	}

}

char Pole::return_letter_from(int x, int y)
{
	return pole[x][y];
}

Pole::Pole(string ss)
{
	pole_z();
	for (int i = 4; i <= 10; i++) {
		pole[7][i] = ss[i - 4];
	}

	
	
}

Pole::Pole(void)
{
}



Pole::Pole(Pole& p)
{
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			pole[i][j] =p.return_letter_from(i,j);
		}
	}
}

