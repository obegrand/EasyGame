#include <iostream>
#include <ctime>	
#include <string>
//#include "header.h"
#define DEBUG
#define all_clear system("CLS");

using namespace std;

struct hero
{
	string name;
	int hp = 100;
	int damage;
	double chance = 0.5;
	bool armor = false;
	bool power = false;
}hero1, hero2;

void delay(int kol_sec = -1)
{
	int start_temp_time = time(NULL);
	while (true)
	{
		int now_temp_time = time(NULL);
		int razn = start_temp_time - now_temp_time;
		//cout << razn;
		if (razn == kol_sec) break;
	}
}

int randik_vsego(int max = 100, int min = 0)
{
	if (min > 0)
	{
		return rand() % max + min;
	}
	else
	{
		return rand() % max;
	}
}

int  main()
{
	int (*random)(int max, int min);
	//называй функцию рандома как хочь и используй её
	random = randik_vsego;

	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	cout << "Добро пожаловать в -БИТВА НАЧИНАЕТСЯ-" << endl;
	cout << "Как вас зовут?\n";
	cin >> hero1.name;
	system("CLS");
	cout << "А вас как?\n";
	cin >> hero2.name;
	system("CLS");

	cout << "Че зарубишь " << hero1.name << " против меня ВЕЛИКОГО " << hero2.name << endl;
	cout << "    [Enter]     " << endl;
	//начала кода
	int raund = 0;
	do {
		raund++;
		cout << "Раунд - " << raund << endl;
		if (raund % 2 == 1)
		{
			cout << "\nЧто вы собераетесь делать?\n[1]Атака\n[2]Защита (повышет шанс уклонения)\n[3]Сильная атака (занимает 2 хода)\n[4]Сдатся\n";
			int chose_action;
			cin >> chose_action;
			cout << endl;
			switch (chose_action)
			{
				//	[1]Атака
			case 1:
				if (hero2.armor == true)
				{
					hero1.chance = random(75, -25);
					if (hero1.chance >= 10) {
						hero1.damage = random(10, 10);
						hero2.hp -= hero1.damage;
						cout << "ОТЛАДКА - ДАМАГ ГЕРОЯ 1: " << hero1.damage << "                ХП 2 ГЕРОЯ  " << hero2.hp << endl;
					}
					else
					{
						cout << "ОТЛАДКА - Промох" << endl;
					}
				}
				else
				{
					hero1.chance = random(100, 0);
					if (hero1.chance >= 10) {
						hero1.damage = random(10, 10);
						hero2.hp -= hero1.damage;
						cout << "ОТЛАДКА - ДАМАГ ГЕРОЯ 1: " << hero1.damage << "                ХП 2 ГЕРОЯ  " << hero2.hp << endl;
						hero1.armor = false;
					}
					else
					{
						cout << "ОТЛАДКА - Промох" << endl;
						hero1.armor = false;
					}
				}
				break;

				//	[2]Защита (повышет шанс уклонения)
			case 2:

				hero1.armor = true;
				break;

				//	[3]Сильная атака (занимает 2 хода)
			case 3:
				if (hero1.power == false) { hero1.power = true; }
				else
				{
					if (hero2.armor == true)
					{
						hero1.chance = random(75, -25);
						if (hero1.chance >= 10)
						{
							hero1.damage = random(10, 10) * 2;
							hero2.hp -= hero1.damage;
							cout << "ОТЛАДКА -  УСИЛИНАЯ АТАКА | ГЕРОЯ 1 | ДАМАГ : " << hero1.damage << "                ХП 2 ГЕРОЯ  " << hero2.hp << endl;
							hero1.power = false;
							hero1.armor = false;
						}
						else
						{
							cout << "ОТЛАДКА - Промох" << endl;
							hero1.power = false;
							hero1.armor = false;
						}
					}
					else
					{
						hero1.chance = random(100, 0);
						if (hero1.chance >= 10) {
							hero1.damage = random(10, 10) * 2;
							hero2.hp -= hero1.damage;
							cout << "ОТЛАДКА -  УСИЛИНАЯ АТАКА | ГЕРОЯ 1 | ДАМАГ : " << hero1.damage << "                ХП 2 ГЕРОЯ  " << hero2.hp << endl;
							hero1.power = false;
							hero1.armor = false;
						}
						else
						{
							cout << "ОТЛАДКА - Промох" << endl;
							hero1.power = false;
							hero1.armor = false;
						}
					}
				}
				break;

				//	[4]Сдатся
			case 4:
				system("cls");
				cout << hero2.name << " позорно сдался\n" << "Победил - " << hero1.name << endl;
				system("pause");
				break;

			default:break;
			}
		}
		else //*******************************************************************************************************************************
		{
			cout << "\nЧто вы собераетесь делать?\n[1]Атака\n[2]Защита (повышет шанс уклонения)\n[3]Сильная атака (занимает 2 хода)\n[4]Сдатся\n";
			int chose_action;
			cin >> chose_action;
			cout << endl;
			switch (chose_action)
			{
				//	[1]Атака
			case 1:
				if (hero1.armor == true)
				{
					hero1.chance = random(75, -25);
					if (hero2.chance >= 10) {
						hero2.damage = random(10, 10);
						hero1.hp -= hero1.damage;
						cout << "ОТЛАДКА - ДАМАГ ГЕРОЯ 2: " << hero2.damage << "                ХП 1 ГЕРОЯ  " << hero1.hp << endl;
					}
					else
					{
						cout << "ОТЛАДКА - Промох" << endl;
					}
				}
				else
				{
					hero2.chance = random(100, 0);
					if (hero2.chance >= 10) {
						hero2.damage = random(10, 10);
						hero1.hp -= hero2.damage;
						cout << "ОТЛАДКА - ДАМАГ ГЕРОЯ 2: " << hero2.damage << "                ХП 1 ГЕРОЯ  " << hero1.hp << endl;
						hero2.armor = false;
					}
					else
					{
						cout << "ОТЛАДКА - Промох" << endl;
						hero2.armor = false;
					}
				}
				break;

				//	[2]Защита (повышет шанс уклонения)
			case 2:

				hero2.armor = true;
				break;

				//	[3]Сильная атака (занимает 2 хода)
			case 3:
				if (hero2.power == false) { hero2.power = true; }
				else
				{
					if (hero1.armor == true)
					{
						hero2.chance = random(75, -25);
						if (hero2.chance >= 10)
						{
							hero2.damage = random(10, 10) * 2;
							hero1.hp -= hero2.damage;
							cout << "ОТЛАДКА -  УСИЛИНАЯ АТАКА | ГЕРОЯ 2 | ДАМАГ : " << hero2.damage << "                ХП 1 ГЕРОЯ  " << hero1.hp << endl;
							hero2.power = false;
							hero2.armor = false;
						}
						else
						{
							cout << "ОТЛАДКА - Промох" << endl;
							hero2.power = false;
							hero2.armor = false;
						}
					}
					else
					{
						hero2.chance = random(100, 0);
						if (hero2.chance >= 10) {
							hero2.damage = random(10, 10) * 2;
							hero1.hp -= hero2.damage;
							cout << "ОТЛАДКА -  УСИЛИНАЯ АТАКА | ГЕРОЯ 2 | ДАМАГ : " << hero2.damage << "                ХП 1 ГЕРОЯ  " << hero1.hp << endl;
							hero2.power = false;
							hero2.armor = false;
						}
						else
						{
							cout << "ОТЛАДКА - Промох" << endl;
							hero2.power = false;
							hero2.armor = false;
						}
					}
				}
				break;

				//	[4]Сдатся
			case 4:
				system("cls");
				cout << hero1.name << " позорно сдался\n" << "Победил - " << hero2.name << endl;
				system("pause");
				break;

			default:break;
			}
		}
		delay();
		system("cls");
		if (hero1.hp <= 0 || hero2.hp <= 0) { goto go; }            //************************
	} while (true);

go:																	//**************************
	if (hero1.hp > hero2.hp)
	{
		cout << " Победа за " << hero1.name;
	}
	else
	{
		cout << " Победа за " << hero2.name;
	}
	system("pause");
	return true;
}


//	[name_1]             [name_2]
//	  O        damage       O
//	 /|\,/     --->>       /|\
//	 / \                   / \
//	[|||||]               [|||||] 

//	[name_1]             [name_2]
//	  O        damage      O
//	 /|\       <<---    \,/|\
//	 / \                  / \
//	[|||||]               [|||||] 