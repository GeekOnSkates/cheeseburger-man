#define BUILD_TARGET C64
#include "Terminator.h"

#if BUILD_TARGET == C64
	#define ENTER "RETURN"
#else
	#define ENTER "ENTER"
#endif

char noun1[20];
char noun2[20];
char noun3[20];
char noun4[20];
char noun5[20];
char noun6[20];
char noun7[20];
char name[20];
char job[20];
char adj1[20];
char adj2[20];
char adj3[20];
char adj4[20];
char adj5[20];
char verb1[20];

void tell_story() {
	clear();
	text_color(YELLOW);
	printf("Introducing %s-%s!\n\n", noun1, name);
	text_color(WHITE);
	printf("Mild-mannered %s by day,\n%s super-hero by night,\n", job, adj1);
	printf("%s-%s stands for truth, %s, and the American %s!\n", noun1, name, noun2, noun3);
	printf("This %s crime fighter can %s\n", adj2, verb1);
	printf("faster than the speed of light, and has a super-%s,\nand is able to lift\n", noun4);
	printf("%s %s without breaking a sweat.\n\n", adj3, noun5);
	printf("Yes, %s-%s is a %s hero,\n", noun1, name, adj1);
	printf("Fighting crime, saving %s from burning %s,\n", noun2, noun6);
	printf("and stopping super-villains' %s plots!\n", adj4);
	printf("Vvilains like the evil Dr. %s,\n", adj5);
	printf("who built a giant robotic %s,\n", noun7);
	printf("or the %s %s, whose army of ninja\n", adj3, noun3);
	printf("%s almost conquered the world!\n", noun5);
	printf("Step aside, Superman!  Stand by, Spider-Man,\n");
	printf("here comes %s-%s to save the day!\n\n", noun1, name);
	printf("Press ESCAPE to exit, or %s to play again.", ENTER);
	/*
that time when %s-%s defeated the the %s %s,
whose army of %s almost conquered the %s!
	*/
	get_char();
}

void start_game() {
	clear();
	
	text_color(YELLOW);
	printf("\nEnter a noun (person/place/thing):\n\n    ");
	text_color(WHITE);
	get_string(noun1, 20);
	
	text_color(YELLOW);
	printf("\nEnter another noun:\n\n    ");
	text_color(WHITE);
	get_string(noun3, 20);
	
	text_color(YELLOW);
	printf("\nAnd another noun:\n\n    ");
	text_color(WHITE);
	get_string(noun4, 20);
	
	text_color(YELLOW);
	printf("\nOne more noun:\n\n    ");
	text_color(WHITE);
	get_string(noun7, 20);
	
	text_color(YELLOW);
	printf("\nNow enter a plural noun:\n\n    ");
	text_color(WHITE);
	get_string(noun2, 20);
	
	text_color(YELLOW);
	printf("\nGimme another plural noun:\n\n    ");
	text_color(WHITE);
	get_string(noun5, 20);
	
	text_color(YELLOW);
	printf("\nAnd another plural noun:\n\n    ");
	text_color(WHITE);
	get_string(noun6, 20);
	
	text_color(YELLOW);
	printf("\nMan, woman, boy, girl, or animal?\n\n    ");
	text_color(WHITE);
	get_string(name, 20);
	
	text_color(YELLOW);
	printf("\nEnter a job (lawyer, plumber, etc.):\n\n    ");
	text_color(WHITE);
	get_string(job, 20);
	
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
	printf("\nOne more adjective:\n\n    ");
	text_color(WHITE);
	get_string(adj5, 20);
	
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
		POKE(53280L, YELLOW);
		printf("\n");
	#endif
	text_color(YELLOW);
	center(18, "CHEESEBURGER MAN");
	text_color(WHITE);
	printf("\nThis is a game designed to be goofy.\n");
	printf("It will ask you for a bunch of words.\n");
	printf("Type whatever you want and press %s.\n", ENTER);
	printf("Once the game has all the info it needs,");
	printf("it will turn the info into a story.\n");
	printf("You win if your story is really funny!\n\n\n");
	printf("Press %s to start the game.  ", ENTER);
	get_char();
	start_game();
	clear();
	done();
	return 0;
}
