
#include "stdafx.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>

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
			do
			{
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
			} while (c != 1 && c != 2 && c != 3 && c != 4 && c != 5);
			
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



		}
		else if (gamestate == BATTLE)
		{

		}
	}
	
    return 0;
}

