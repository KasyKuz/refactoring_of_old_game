#include "keyboard_Output.h"
#include "Pole.h"
#include "Letter.h"

void keyboard_Output::output_choose_move(){

    printf("print 1 and after enter word with coordinates (row , column, str/st - 0/1) on next line\n");
    printf("print 2 to finish inputing\n");
    printf("print 3 to finish game\n");
}

void keyboard_Output::output(string s)
{
	/* 
	setlocale(LC_ALL, "Russian");
	printf("%s\n", s);
	*/
	std::cout << s << std::endl;
}

void keyboard_Output::all_pole_output(Pole& pl)
{
	printf("   ");
	for (int i = 0; i < 15; i++) {
		printf("%d ", i + 1);
		if (i < 9) printf(" ");

	}
	printf("\n");
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < 15; i++) {

		printf("%d ", i + 1);
		if (i < 9) printf(" ");
		for (int j = 0; j < 15; j++) {
			if (pl.return_letter_from(i,j) == 'z') {
				printf("-  ");
			}
			else   printf("%c  ", pl.return_letter_from(i, j));


		}
		printf("\n");
	}
}
/* 
void keyboard_Output::player_information_output(Player& pl)
{
	setlocale(LC_ALL, "Russian");
	printf("-----information of %d player-----\n", pl.return_number());
}
void keyboard_Output::player_bank_output(Player& pl)
{
	setlocale(LC_ALL, "Russian");
	printf("-----information of %d player-----\n", pl.return_number());
}
*/
void keyboard_Output::player_information_output(int n, Letter* l, int score)
{
	setlocale(LC_ALL, "Russian");
	printf("-----information of %d player-----\n", n);
	printf("%d player score: %d\n", n,score);
	player_bank_output(l, n);
	printf("----------------------------------\n");
}

void keyboard_Output::player_bank_output(Letter *l, int n)
{
	setlocale(LC_ALL, "Russian");
	printf("bank of %d player: ", n);// play.return_number());
	for (int i = 0; i < 7; i++) {
		if (l[i].return_locked() == true) printf("%c ", l[i].return_value());
	}
	//play.return_bank_l(i).return_locked()
	printf("\n");
}
