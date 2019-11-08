#define BUILD_TARGET LINUX
#include "Terminator.h"

#define ENTER "ENTER"

void start_game(void);

char noun1[20]; char noun2[20];
char noun3[20]; char noun4[20];
char noun5[20]; char noun6[20];
char noun7[20]; char noun8[20];
char noun9[20]; char name[20];
char job[20]; char adj1[20];
char adj2[20]; char adj3[20];
char adj4[20]; char adj5[20];
char adj6[20]; char adj7[20];
char verb1[20]; char f;

void title_case(char *str) {
	for (f=0; f<20; f++) {
		if (f == 0 || str[f - 1] == ' ' || str[f - 1] == '-') {
			if (str[f] == 'a') str[f] = 'A';
			else if (str[f] == 'b') str[f] = 'B';
			else if (str[f] == 'c') str[f] = 'C';
			else if (str[f] == 'd') str[f] = 'D';
			else if (str[f] == 'e') str[f] = 'E';
			else if (str[f] == 'f') str[f] = 'F';
			else if (str[f] == 'g') str[f] = 'G';
			else if (str[f] == 'h') str[f] = 'H';
			else if (str[f] == 'i') str[f] = 'I';
			else if (str[f] == 'j') str[f] = 'J';
			else if (str[f] == 'k') str[f] = 'K';
			else if (str[f] == 'l') str[f] = 'L';
			else if (str[f] == 'm') str[f] = 'M';
			else if (str[f] == 'n') str[f] = 'N';
			else if (str[f] == 'o') str[f] = 'O';
			else if (str[f] == 'p') str[f] = 'P';
			else if (str[f] == 'q') str[f] = 'Q';
			else if (str[f] == 'r') str[f] = 'R';
			else if (str[f] == 's') str[f] = 'S';
			else if (str[f] == 't') str[f] = 'T';
			else if (str[f] == 'u') str[f] = 'U';
			else if (str[f] == 'v') str[f] = 'V';
			else if (str[f] == 'w') str[f] = 'W';
			else if (str[f] == 'x') str[f] = 'X';
			else if (str[f] == 'y') str[f] = 'Y';
			else if (str[f] == 'z') str[f] = 'Z';
		}
	}
}

void tell_story() {
	clear();
	text_color(YELLOW);
	title_case(noun1); title_case(name);
	printf("Introducing %s-%s!\r\n\r\n", noun1, name);
	text_color(WHITE);
	printf("Mild-mannered %s by day,\r\n%s super-hero by night,\r\n", job, adj1);
	printf("%s-%s stands for truth,\r\n%s, and the American %s!\r\n", noun1, name, noun2, noun3);
	printf("This %s crime fighter can %s\r\n", adj2, verb1);
	printf("faster than the speed of light,\r\nhas a super-%s, and can lift\r\n", noun4);
	printf("%s %s without breaking a sweat.\r\n\r\n", adj3, noun5);

	printf("Press %s to go to the next page.", ENTER);
	get_char();
	clear();

	printf("Yes, %s-%s is a", noun1, name);
	if (adj1[0] == 'a' || adj1[0] == 'e' || adj1[0] == 'i' || adj1[0] == 'o' || adj1[0] == 'u')
		printf("n");
	printf(" %s hero,\r\n", adj1);
	printf("Fighting crime, saving %s\r\nfrom burning %s,\r\n", noun2, noun6);
	printf("and stopping villains' %s plots!\r\n", adj4);
	title_case(adj5);
	printf("Villains like the evil Dr. %s,\r\n", adj5);
	printf("who built a giant robotic %s,\r\n", noun7);
	title_case(adj7); title_case(noun9);
	printf("or the %s %s, whose army of ninja\r\n", adj7, noun9);
	printf("%s almost conquered the world!\r\n", noun8);
	printf("Step aside, Superman!\r\nStand by, Spider-Man,\r\n");
	printf("here comes %s-%s\r\nto save the day!\r\n\r\n", noun1, name);
	printf("Type \"done\" (without the quotes) to exitor anything else to play again.\r\n\r\n    ");
	get_string(noun1, 20);
	if (noun1[0] == 'd' && noun1[1] == 'o' && noun1[2] == 'n' && noun1[3] == 'e') return;
	start_game();
}

void start_game() {
	clear();

	for (f=0; f<20; f++) {
		noun1[f] = 0;
		noun2[f] = 0;
		noun3[f] = 0;
		noun4[f] = 0;
		noun5[f] = 0;
		noun6[f] = 0;
		noun7[f] = 0;
		noun8[f] = 0;
		noun9[f] = 0;
		name[f] = 0;
		job[f] = 0;
		verb1[f] = 0;
		adj1[f] = 0;
		adj2[f] = 0;
		adj3[f] = 0;
		adj4[f] = 0;
		adj5[f] = 0;
		adj6[f] = 0;
		adj7[f] = 0;
	}

	text_color(YELLOW);
	printf("\r\nEnter a noun (person/place/thing):\r\n\r\n    ");
	text_color(WHITE);
	get_string(noun9, 20);

	text_color(YELLOW);
	printf("\r\nEnter another noun:\r\n\r\n    ");
	text_color(WHITE);
	get_string(noun3, 20);

	text_color(YELLOW);
	printf("\r\nAnd another noun:\r\n\r\n    ");
	text_color(WHITE);
	get_string(noun4, 20);

	text_color(YELLOW);
	printf("\r\nEnter another noun:\r\n\r\n    ");
	text_color(WHITE);
	get_string(noun1, 20);

	text_color(YELLOW);
	printf("\r\nOne more noun:\r\n\r\n    ");
	text_color(WHITE);
	get_string(noun7, 20);

	text_color(YELLOW);
	printf("\r\nNow enter a plural noun:\r\n\r\n    ");
	text_color(WHITE);
	get_string(noun2, 20);

	clear();

	text_color(YELLOW);
	printf("\r\nGimme another plural noun:\r\n\r\n    ");
	text_color(WHITE);
	get_string(noun5, 20);

	text_color(YELLOW);
	printf("\r\nAnd another plural noun:\r\n\r\n    ");
	text_color(WHITE);
	get_string(noun8, 20);

	text_color(YELLOW);
	printf("\r\nLast plural noun, I promise:\r\n\r\n    ");
	text_color(WHITE);
	get_string(noun6, 20);

	text_color(YELLOW);
	printf("\r\nMan, woman, boy, girl, or an animal?\r\n\r\n    ");
	text_color(WHITE);
	get_string(name, 20);

	text_color(YELLOW);
	printf("\r\nEnter a job (lawyer, plumber, etc.):\r\n\r\n    ");
	text_color(WHITE);
	get_string(job, 20);

	clear();

	text_color(YELLOW);
	printf("\r\nAdjective (describing word):\r\n\r\n    ");
	text_color(WHITE);
	get_string(adj1, 20);

	text_color(YELLOW);
	printf("\r\nEnter another adjective:\r\n\r\n    ");
	text_color(WHITE);
	get_string(adj2, 20);

	text_color(YELLOW);
	printf("\r\nAnd another adjective:\r\n\r\n    ");
	text_color(WHITE);
	get_string(adj3, 20);

	text_color(YELLOW);
	printf("\r\nGimme another adjective:\r\n\r\n    ");
	text_color(WHITE);
	get_string(adj4, 20);

	text_color(YELLOW);
	printf("\r\nAnd another adjective:\r\n\r\n    ");
	text_color(WHITE);
	get_string(adj6, 20);

	clear();

	text_color(YELLOW);
	printf("\r\nOne more adjective:\r\n\r\n    ");
	text_color(WHITE);
	get_string(adj5, 20);

	text_color(YELLOW);
	printf("\r\nOkay, last adjective:\r\n\r\n    ");
	text_color(WHITE);
	get_string(adj7, 20);

	text_color(YELLOW);
	printf("\r\nVerb (action word):\r\n\r\n    ");
	text_color(WHITE);
	get_string(verb1, 20);

	tell_story();
}

int main() {
	startup();
	clear();

	text_color(YELLOW);
	center(18, "CHEESEBURGER-MAN");
	text_color(WHITE);
	printf("\r\nThis is a game designed to be goofy.\r\n");
	printf("It will ask you for a bunch of words.\r\n");
	printf("Type whatever you want and press %s.\r\n", ENTER);
	printf("Once the game has all the info it needs,\r\n");
	printf("it will turn the info into a story.\r\n");
	printf("You win if your story is really funny!\r\n\r\n\r\n");
	printf("Press %s to start the game.  ", ENTER);
	get_char();
	start_game();
	clear();
	done();
	return 0;
}
