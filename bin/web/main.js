let data = {};
data.noun1 = ""; data.noun2 = "";
data.noun3 = ""; data.noun4 = "";
data.noun5 = ""; data.noun6 = "";
data.noun7 = ""; data.noun8 = "";
data.noun9 = ""; data.name = "";
data.job = ""; data.adj1 = "";
data.adj2 = ""; data.adj3 = "";
data.adj4 = ""; data.adj5 = "";
data.adj6 = ""; data.adj7 = "";
data.verb1 = "";

function title_case(str) {
    let s = "";
	for (let f=0; f<str.length; f++)
		if (f == 0 || str[f - 1] == ' ' || str[f - 1] == '-')
            s += str[f].toUpperCase();
        else s += str[f];
    return s;
}

function add_field(label, variable) {
	let l = document.createElement("label");
	let i = document.createElement("input");
	l.appendChild(document.createTextNode(label));
	l.appendChild(i);
	i.onchange = function(e) { data[variable] = e.target.value; };
	document.body.appendChild(l);
}

function tell_story() {
    let hero = title_case(data.noun1) + "-" + title_case(data.name);
    let html = "<h1>Introducing " + hero + "</h1>"
        + "<p>Mild-mannered " + data.job + " by day, " + data.adj1 + " super-hero by night, "
	    + hero + " stands for truth, " + data.noun2 + ", and the American " + data.noun3 + "!  "
	    + "This " + data.adj2 + " crime fighter can " + data.verb1 + " "
	    + "faster than the speed of light, has a super-" + data.noun4 + ", and can lift "
	    + data.adj3 + " " + data.noun5 + " without breaking a sweat.</p><p>"
		+ "Yes, " + hero + " is a ";
	if (data.adj1[0] == 'a' || data.adj1[0] == 'e' || data.adj1[0] == 'i' || data.adj1[0] == 'o' || data.adj1[0] == 'u')
		html += "n";
    html += data.adj1 + " hero, "
	    + "fighting crime, saving " + data.noun2 + " from burning " + data.noun6 + " "
	    + "and stopping villains' " + data.adj4 + " plots!  ";
	data.adj5 = title_case(data.adj5);
	html += "Vilains like the evil Dr. " + data.adj5 + ", "
	    + "who built a giant robotic " + data.noun7 + ", "
	data.adj7 = title_case(data.adj7); data.noun9 = title_case(data.noun9);
	html += "or the " + data.adj7 + " " + data.noun9 + ", whose army of ninja "
	    + data.noun8 + " almost conquered the world!</p><p>"
	    + "Step aside, Superman!<br />Stand by, Spider-Man,<br />"
	    + "Here comes " + hero + " to save the day!</p>"
        + "<button onclick='start_game();'>Play Again</button>"
    document.body.innerHTML = html;
}

function start_game() {
	data = {};
	data.noun1 = ""; data.noun2 = "";
	data.noun3 = ""; data.noun4 = "";
	data.noun5 = ""; data.noun6 = "";
	data.noun7 = ""; data.noun8 = "";
	data.noun9 = ""; data.name = "";
	data.job = ""; data.adj1 = "";
	data.adj2 = ""; data.adj3 = "";
	data.adj4 = ""; data.adj5 = "";
	data.adj6 = ""; data.adj7 = "";
	data.verb1 = "";
	document.body.innerHTML = "";
	add_field("Enter a noun (person/place/thing):", "noun9");
	add_field("Enter another noun:", "noun3");
	add_field("And another noun:", "noun4");
	add_field("Enter another noun:", "noun1");
	add_field("One more noun:", "noun7");
	add_field("Now enter a plural noun:", "noun2");
	add_field("Gimme another plural noun:", "noun5");
	add_field("And another plural noun:", "noun8");
	add_field("Last plural noun, I promise:", "noun6");
	add_field("Man, woman, boy, girl, or an animal?", "name");
	add_field("Enter a job (lawyer, plumber, etc.):", "job");
	add_field("Adjective (describing word):", "adj1");
	add_field("Enter another adjective:", "adj2");
	add_field("And another adjective:", "adj3");
	add_field("Gimme another adjective:", "adj4");
	add_field("And another adjective:", "adj6");
	add_field("One more adjective:", "adj5");
	add_field("Okay, last adjective:", "adj7");
	add_field("Verb (action word):", "verb1");
	let b = document.createElement("button");
	b.onclick = tell_story;
	b.innerText = "Go";
	document.body.appendChild(b);
	document.querySelectorAll("input")[0].focus();
}

function main() {
	document.body.innerHTML = "<h1>CHEESEBURGER-MAN</h1>"
		+ "<p>This is a game designed to be goofy.  "
		+ "It will ask you for a bunch of words.  "
		+ "Fill out the form then press the Go button.  "
		+ "Once the game has all the info it needs,"
		+ "it will turn the info into a story.  You win if your story is really funny!</p>"
		+ "<button onclick='start_game();'>Start Game</button>";
	document.querySelector("button").focus();
}
