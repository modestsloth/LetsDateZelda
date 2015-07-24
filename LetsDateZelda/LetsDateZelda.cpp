
#include "stdafx.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <stdlib.h>

using namespace std;

enum ZCLASS { KNIGHT, SORCERESS, RANGER, THIEF, FIGHTER };
enum STAGE { STARTER, CHAMPION, TITAN };
enum STATE { EXPLORE, BATTLE, MENU, STORE, EXAMINE, INTERACT};

struct Stat
{
	int base;
	int individual;
	int actual;
};

struct Zelda
{
	string name = "ZELDA";
	int exp = 0;
	int affection = 0;

	Stat hp;
	Stat con;
	Stat dex;
	int items[6];	
};

struct Enemy
{
	string name;
	int lvl;
	int hp;
	int con;
	int dex;
}enemy;

struct Item
{
	int id;
	string name;
};

struct Room
{
	int x;
	int y;

	Room *left = NULL;
	Room *right = NULL;
	Room *down = NULL;
	Room *up = NULL;
};

//The struct for the characters that will be initialized
/*
	Stats that will be included in this area.
	-Health
	-Strength
	-Name
	-Intelligence
	-Happiness
	-Experience
	-Level
*/

struct Character
{
	int health;
	int strength;
	int intelligence;
	int happiness;
	int exp;
	int lvl;
	
	string name;
};

void modHealth(Character &mainToon, int mod);
void modStr(Character &mainToon, int mod);
void modInt(Character &mainToon, int mod);
void modHapp(Character &mainToon, int mod);
void modLvl(Character &mainToon, int mod);
void modExp(Character &mainToon, int mod);
void battleText(Character &mainToon, STATE &gamestate, int monster);
void op(string s);
void dot();
void ClearScreen();
/*
This fucntion is used to initialize the struct Character with the initial values on a new game creation
--Needs to work, for some reason the variables are not being initialized here
*/
void initChar(Character mainToon) {
	mainToon.health = 100;
	mainToon.strength = 10;
	mainToon.intelligence = 10;
	mainToon.happiness = 0;
	mainToon.exp = 0;
	mainToon.lvl = 1;
	mainToon.name = "Zelda";
}
/*
	This is the funtion that will be used to modify the health of the charcters
	Will also inlude funtions for modifying
	-Strngeth
	-happiness
	-Intelligence
	-ect
*/
void modHealth(Character &mainToon, int mod) {
	mainToon.health += mod;

	if (mainToon.health > 100) {
		mainToon.health = 100;
	}
}
void modStr(Character &mainToon, int mod) {
	mainToon.strength += mod;
}
void modInt(Character &mainToon, int mod) {
	mainToon.intelligence += mod;
}
void modHapp(Character &mainToon, int mod) {
	mainToon.happiness += mod;
}
void modLvl(Character &mainToon, int mod) {
	mainToon.lvl += mod;
}
void modExp(Character &mainToon, int mod) {
	mainToon.exp += mod;

	if (mainToon.exp >= 100) {
		modLvl(mainToon, 1);
	}
}

/*
	This function is to hold the battle Text for when an encounter happens
*/
void battleText(Character &mainToon, STATE &gamestate,int monster) {

	int hit = rand() % 10 + 1;
	int dmg = 2;
	int monHealth = 100;
	boolean cont = true;

	while (cont) {
		//SEt the correct dmg ratio based on what monster is fighting
		if (monster == 1) {
			dmg = rand() % 5 + 1;
			if (dmg > 3) {
				op("ZELDA: The Beast landed a critical hit!");
				dot();
			}
		}
		else if (monster == 2) {
			dmg = rand() % 10 + 1;
			if (dmg > 6) {
				op("ZELDA: The Beast landed a critical hit!");
				dot();
			}
		}
		else {
			dmg = rand() % 15 + 1;
			if (dmg > 10) {
				op("ZELDA: The Beast landed a critical hit!");
				dot();
			}
		}

		if (hit > 5) {
			op("ZELDA: We landed a critical hit Master!");
			dot();
		}
		cout << "You recieved " << dmg << " damage from the enemy" << endl;							cout << "You recieved " << dmg << " damage from the enemy" << endl;
		cout << "You dealt " << hit << " damage to the enemy" << endl;
		dot();
		modHealth(mainToon, -dmg);
		monHealth -= hit;

		op("ZELDA: I have taken a bit of damage Master!");
		cout << "Zelda has " << mainToon.health << " life left" << endl;
		dot();

		if (mainToon.health <= 0) {
			op("ZELDA: This is the farthest I can go Master");
			dot();
			mainToon.health = 100;
			gamestate = MENU;
			cont = false;
		}
		else if (monHealth <= 0) {
			op("ZELDA: We have slain the monster Master!");
			dot();
			gamestate = BATTLE;
			cont = false;
		}
	}
}

/*
	A function used to draw a lot of blank spaces to clear he screen, Temp solution
*/
void ClearScreen()
{
	cout << string(100, '\n');
}

void op(string s)
{	//all output is forwarded here
	for (unsigned int i = 0; i < s.length(); i++)
	{
		cout << s[i];
		Sleep(25);
	}
	Sleep(500);
	cout << "\n";
}

void dot()
{
	for (int i = 0; i < 5; i++)
	{
		cout << ".";
		Sleep(250);
	}
	cout << "\n";
}


int main()
{
	Character mainToon;
	//Initialize the new Character struct created
	mainToon.health = 100;
	mainToon.strength = 10;
	mainToon.intelligence = 10;
	mainToon.happiness = 0;
	mainToon.exp = 0;
	mainToon.lvl = 1;
	mainToon.name = "Zelda";

	//just jump into it
	string input;
	op("ZELDA: Hello, My name is Zelda, and I need your help!");
	op("ZELDA: Can you show me the way to the Sacred Grove?");
	dot();
	op("ZELDA: Thank you. Is there anything you'd like to do before we set off?");
	dot();

	STATE gamestate;
	gamestate = MENU;
	while (true)
	{
		if (gamestate == MENU)
		{
			op("ZELDA: What would you like to do before we go?");
			int c = 0;
			op("1. Go to the dungeon.");
			op("2. Go into town.");
			op("3. Examine your inventory.");
			op("4. Examine Zelda.");
			op("5. Talk to Zelda.");

			cin >> c;
			switch (c)
			{
			case 1:
				op("ZELDA: Great!, Let's not waste a single minute!");
				gamestate = EXPLORE;
				break;
			case 2:
				op("ZELDA: Good idea! We can get supplies!");
				gamestate = STORE;
				break;
			case 3:
				op("You look over your Inventory.");
				break;
			case 4:
				ClearScreen();
				op("You look over Zelda.");
				gamestate = EXAMINE;
				break;
			case 5:
				op("Speak with Zelda.");
				gamestate = INTERACT;
				break;
			default:
				break;
			}
		}
		
		else if (gamestate == EXPLORE)
		{
			dot();
			op("You help Zelda navigate the southern woods and locate the Sacred Grove.");
			op("ZELDA: Alright, so this is the place?");
			dot();
			op("ZELDA: Thank you for guiding me.");
			op("ZELDA: It would have taken ages for me to get here on my own.");
			op("ZELDA: Stay here. I'll be back soon.");
			dot();
			op("<Without hesitation she walks towards the temple entrance...>");
			dot();

			int size = 5;
			//set up the map
			Room *entrance;
			entrance = new Room;
			gamestate = BATTLE;

		}
		
		else if (gamestate == BATTLE)
		{
			//This is to simulate random battle exploration While testing the modification functions created

			/*
				The random number for Monster will be 
				Bat = 1
				wolf = 2
				bear = 3
			*/
			int monster = rand() % 3 + 1;

			op("Boss: Welcome to my domain Pitiful Human!");
			op("Boss: I hope to see your face before I consume your soul");
			op("Boss: If you can make it past my minions that is");
			dot();

			int a = 0;
			op("Zelda: What should we do Master?");
			op("1: Explore the dungeon");
			op("2: Exit the dungeon");

			cin >> a;
			switch (a)
			{
			case 1:
				//Scenario for a bat encounter
				if (monster == 1) {
					op("ZELDA: Master a Bat has appeared");
					dot();
					battleText(mainToon, gamestate, monster);	
				}
				else if (monster == 2) {
					op("ZELDA: Master a Wolf has appeared");
					dot();
					battleText(mainToon, gamestate,monster);
				}
				else {
					op("ZELDA: Master a Bear has appeared");
					dot();
					battleText(mainToon, gamestate,monster);
				}
				gamestate = BATTLE;
				break;
			case 2:
				op("ZELDA: We shall return to finish where we left off!");
				mainToon.health = 100;
				gamestate = MENU;
				break;
			default:
				break;
			}


		}
		//Impliment the gamestater that allows for you to monitor the characters stats on screen
		else if (gamestate == EXAMINE) {

			cout << "Name: " << mainToon.name << endl;
			cout << "Level: " << mainToon.lvl << endl;
			cout << "Experience: " << mainToon.exp << endl;
			cout << "Happiness: " << mainToon.happiness << endl;
			cout << "----------------" << endl;

			cout << "Health: " << mainToon.health << endl;
			cout << "Strength: " << mainToon.strength << endl;
			cout << "Intelligence: " << mainToon.intelligence << endl;
			cout << "----------------" << endl;
			cout << endl;

			gamestate = MENU;
		}
	}
	
    return 0;
}

