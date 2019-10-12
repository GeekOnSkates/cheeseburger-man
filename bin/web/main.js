let noun1 = ""; let noun2 = "";
let noun3 = ""; let noun4 = "";
let noun5 = ""; let noun6 = "";
let noun7 = ""; let noun8 = "";
let noun9 = ""; let name = "";
let job = ""; let adj1 = "";
let adj2 = ""; let adj3 = "";
let adj4 = ""; let adj5 = "";
let adj6 = ""; let adj7 = "";
let verb1 = ""; let f = 0;

function title_case(str) {
    let s = "";
	for (let f=0; f<str.length; f++)
		if (f == 0 || str[f - 1] == ' ' || str[f - 1] == '-')
            s += str[f].toUpperCase();
        else s += str[f];
    return s;
}

void tell_story() {
    let hero = title_case(noun1) + "-" + title_case(name);
    let html = "<h1>Introducing " + hero + "</h1>";
        + "<p>Mild-mannered " + job + " by day, " + adj1 + " super-hero by night, "
	    + hero + " stands for truth, " + noun2 + ", and the American " + noun3 + "!  "
	    + "This " + adj2 + " crime fighter can " + verb1 + " "
	    + "faster than the speed of light, has a super-" + noun4 + ", and can lift "
	    + adj3 + " " + noun5 + " without breaking a sweat.</p>"
		+ "Yes, " + hero + " is a ";
	if (adj1[0] == 'a' || adj1[0] == 'e' || adj1[0] == 'i' || adj1[0] == 'o' || adj1[0] == 'u')
		html += "n";
    html += adj1 + " hero, "
	    + "Fighting crime, saving " + noun2 + " from burning " + noun6 + " ";
	    + "and stopping villains' " + adj4 + " plots!  ";
	adj5 = title_case(adj5);
	    + "Vilains like the evil Dr. " + adj5 + ", "
	    + "who built a giant robotic " + noun7 + ", "
	adj7 = title_case(adj7); noun9 = title_case(noun9);
	html += "or the " + adj7 + " " + noun9 + ", whose army of ninja "
	    + noun8 + " almost conquered the world!</p><p>"
	    + "Step aside, Superman!<br />Stand by, Spider-Man,<br />"
	    + "here comes " + hero + "to save the day!</p>"
        + "<button onclick='start_game();'>Play Again</button>"
    document.body.innerHTML = html;
}

void start_game() {
	document.body.innerHTML = "";
    
    // LEFT OFF HERE

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
	
	document.body.innerHTML = "";
	
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
	
	document.body.innerHTML = "";
	
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
	
	document.body.innerHTML = "";
	
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
	document.body.innerHTML = "";
	
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
	get_let();
	start_game();
	document.body.innerHTML = "";
	done();
	return 0;
}
