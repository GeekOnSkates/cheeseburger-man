#define BUILD_TARGET C64
#include "Terminator.h"

#if BUILD_TARGET == C64
	#define ENTER "RETURN"
#else
	#define ENTER "ENTER"
#endif

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
	printf("Introducing %s-%s!\n\n", noun1, name);
	text_color(WHITE);
	printf("Mild-mannered %s by day,\n%s super-hero by night,\n", job, adj1);
	printf("%s-%s stands for truth,\n%s, and the American %s!\n", noun1, name, noun2, noun3);
	printf("This %s crime fighter can %s\n", adj2, verb1);
	printf("faster than the speed of light,\nhas a super-%s, and can lift\n", noun4);
	printf("%s %s without breaking a sweat.\n\n", adj3, noun5);
	
	printf("Press %s to go to the next page.", ENTER);
	get_char();
	clear();
	
	printf("Yes, %s-%s is a", noun1, name);
	if (adj1[0] == 'a' || adj1[0] == 'e' || adj1[0] == 'i' || adj1[0] == 'o' || adj1[0] == 'u')
		printf("n");
	printf(" %s hero,\n", adj1);
	printf("Fighting crime, saving %s\nfrom burning %s,\n", noun2, noun6);
	printf("and stopping villains' %s plots!\n", adj4);
	title_case(adj5);
	printf("Vilains like the evil Dr. %s,\n", adj5);
	printf("who built a giant robotic %s,\n", noun7);
	title_case(adj7); title_case(noun9);
	printf("or the %s %s, whose army of ninja\n", adj7, noun9);
	printf("%s almost conquered the world!\n", noun8);
	printf("Step aside, Superman!\nStand by, Spider-Man,\n");
	printf("here comes %s-%s\nto save the day!\n\n", noun1, name);
	printf("Type \"done\" (without the quotes) to exitor anything else to play again.\n\n    ");
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
	printf("\nEnter a noun (person/place/thing):\n\n    ");
	text_color(WHITE);
	get_string(noun9, 20);
	
	text_color(YELLOW);
	printf("\nEnter another noun:\n\n    ");
	text_color(WHITE);
	get_string(noun3, 20);
	
	text_color(YELLOW);
	printf("\nAnd another noun:\n\n    ");
	text_color(WHITE);
	get_string(noun4, 20);
	
	text_color(YELLOW);
	printf("\nEnter another noun:\n\n    ");
	text_color(WHITE);
	get_string(noun1, 20);
	
	text_color(YELLOW);
	printf("\nOne more noun:\n\n    ");
	text_color(WHITE);
	get_string(noun7, 20);
	
	text_color(YELLOW);
	printf("\nNow enter a plural noun:\n\n    ");
	text_color(WHITE);
	get_string(noun2, 20);
	
	clear();
	
	text_color(YELLOW);
	printf("\nGimme another plural noun:\n\n    ");
	text_color(WHITE);
	get_string(noun5, 20);
	
	text_color(YELLOW);
	printf("\nAnd another plural noun:\n\n    ");
	text_color(WHITE);
	get_string(noun8, 20);
	
	text_color(YELLOW);
	printf("\nLast plural noun, I promise:\n\n    ");
	text_color(WHITE);
	get_string(noun6, 20);
	
	text_color(YELLOW);
	printf("\nMan, woman, boy, girl, or an animal?\n\n    ");
	text_color(WHITE);
	get_string(name, 20);
	
	text_color(YELLOW);
	printf("\nEnter a job (lawyer, plumber, etc.):\n\n    ");
	text_color(WHITE);
	get_string(job, 20);
	
	clear();
	
	text_color(YELLOW);
	printf("\nAdjective (describing word):\n\n    ");
	text_color(WHITE);
	get_string(adj1, 20);
	
	text_color(YELLOW);
	printf("\nEnter another adjective:\n\n    ");
	text_color(WHITE);
	get_string(adj2, 20);
	
	text_color(YELLOW);
	printf("\nAnd another adjective:\n\n    ");
	text_color(WHITE);
	get_string(adj3, 20);
	
	text_color(YELLOW);
	printf("\nGimme another adjective:\n\n    ");
	text_color(WHITE);
	get_string(adj4, 20);
	
	text_color(YELLOW);
	printf("\nAnd another adjective:\n\n    ");
	text_color(WHITE);
	get_string(adj6, 20);
	
	clear();
	
	text_color(YELLOW);
	printf("\nOne more adjective:\n\n    ");
	text_color(WHITE);
	get_string(adj5, 20);
	
	text_color(YELLOW);
	printf("\nOkay, last adjective:\n\n    ");
	text_color(WHITE);
	get_string(adj7, 20);
	
	text_color(YELLOW);
	printf("\nVerb (action word):\n\n    ");
	text_color(WHITE);
	get_string(verb1, 20);
	
	tell_story();
}

int main() {
	startup();
	clear();
	
	#if BUILD_TARGET == C64
		POKE(53280L, 9);
		printf("\n");
	#endif
	
	#if BUILD_TARGET == C64
		// Setup - see around page 9 of https://www.commodore.ca/manuals/c64_users_guide/c64-users_guide-07-creating_sound.pdf
		// Clearly, this was designed for coders who are also DJs, or professional sound engineers or expert audio ninja or something :D
		// Kinda makes me want to go back to the VIC-20 for a bit.
		for (f = 0; f < 24; f++)
			POKE(54272L + f, 0);
		//POKE(54274L, 8);	// see my question on Everything C64
		POKE(54275L, 15);	// see my question on Everything C64
		POKE(54296L, 15);	// volume = max
		POKE(54276L, 65);	// voice 1 start square wave
		POKE(54277L, 64);	// voice 1 medium attack no decay
		POKE(54278L, 128);	// voice 1 high sustain 
		
		// Shooting at plapying a "simple" C note (simple for seasoned pros and Ultimate Audio Gurus; apparently not for us mere mortals). :P
		POKE(54273L, 34);
		POKE(54272L, 75);
		for (f = 0; f<100; f++);
		POKE(54272L, 0);
		POKE(54273L, 0);
	#endif
	
	text_color(YELLOW);
	center(18, "CHEESEBURGER-MAN");
	text_color(WHITE);
	printf("\nThis is a game designed to be goofy.\n");
	printf("It will ask you for a bunch of words.\n");
	printf("Type whatever you want and press %s.\n", ENTER);
	printf("Once the game has all the info it needs,");
	#if BUILD_TARGET != C64
		printf("\n");
	#endif
	printf("it will turn the info into a story.\n");
	printf("You win if your story is really funny!\n\n\n");
	printf("Press %s to start the game.  ", ENTER);
	get_char();
	start_game();
	clear();
	done();
	return 0;
}
