#define BUILD_TARGET C64
#include "Terminator.h"

#if BUILD_TARGET == C64
	#define ENTER "RETURN"
#else
	#define ENTER "ENTER"
#endif

// TO-DO: Delete any of these that I don't end up needing, to save RAM
const char *adj =		"An adjective is a describing word.\nExamples include:\nbig, yellow, cheesy, awesome, and weird.";
const char *noun =		"A noun is a person, place, or thing\nExamples include:\ndog, computer, office, and banana.";
const char *pronoun =	"A pronoun is the name of a noun.\nExamples include:\nBob, Alice, McDonald's, and Nintendo.";
const char *verb =		"A verb is an action word.\nExamples include:\nWalk, swim, sit, and eat.";

char noun1[20];
char noun2[20];
char noun3[20];
char noun4[20];
char noun5[20];
char name[20];
char job[20];
char adj1[20];
char adj2[20];
char adj3[20];
char verb1[20];

void tell_story() {
	clear();
	text_color(YELLOW);
	printf("Introducing %s-%s!\n\n", noun1, name);
	text_color(WHITE);
	printf("Mild-mannered %s by day,\n%s hero by night,\n", job, adj1);
	printf("%s-%s stands for truth, %s, and the American %s!\n", noun1, name, noun2, noun3);
	printf("This %s crime fighter can %s\n", adj2, verb1);
	printf("faster than the speed of light, and has a super-%s!, and is ablen\n", noun4);
	printf("to lift %s %s without breaking a sweat.\n", adj3, noun5);
	/*
and also super-%s!  Yes, %s-%s is a %s hero,
Fighting crime, saving %s from burning %s,
and stopping super-villains' %s plots!
That's right, super-vilains like the evil
Doctor %s, who once built a giant robotic %s,
and tried to destroy the %s.  Then there was
that time when %s-%s defeated the the %s %s,
whose army of %s almost conquered the %s!
Step aside, Superman!  Stand by, Spider-Man,
here comes %s-%s to save the day!
	*/
	get_char();
}

void start_game() {
	clear();
	
	text_color(YELLOW);
	printf("Enter a noun (person/place/thing):\n\n    ");
	text_color(WHITE);
	get_string(noun1, 20);
	
	text_color(YELLOW);
	printf("\nEnter a plural noun:\n\n    ");
	text_color(WHITE);
	get_string(noun2, 20);
	
	text_color(YELLOW);
	printf("\nEnter another noun:\n\n    ");
	text_color(WHITE);
	get_string(noun3, 20);
	
	text_color(YELLOW);
	printf("\nAnd another noun:\n\n    ");
	text_color(WHITE);
	get_string(noun4, 20);
	
	text_color(YELLOW);
	printf("\nSorry, I need another noun:\n\n    ");
	text_color(WHITE);
	get_string(noun5, 20);
	
	text_color(YELLOW);
	printf("\nMan, woman, boy, girl, or animal?\n\n    ");
	text_color(WHITE);
	get_string(name, 20);
	
	text_color(YELLOW);
	printf("\nEnter a job title:\n\n    ");
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
	printf("\nVerb (action word):\n\n    ");
	text_color(WHITE);
	get_string(verb1, 20);
	
	tell_story();
}

int main() {
	startup();
	clear();
	text_color(YELLOW);
	center(18, "CHEESEBURGER MAN");
	text_color(WHITE);
	printf("\nThis is a game designed to be goofy.\n");
	printf("It will ask you for a bunch of words,\n");
	printf("then you type an answer and press %s.\n", ENTER);
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
