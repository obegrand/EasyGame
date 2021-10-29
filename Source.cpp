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
	//������� ������� ������� ��� ���� � ��������� �
	random = randik_vsego;

	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	cout << "����� ���������� � -����� ����������-" << endl;
	cout << "��� ��� �����?\n";
	cin >> hero1.name;
	system("CLS");
	cout << "� ��� ���?\n";
	cin >> hero2.name;
	system("CLS");

	cout << "�� �������� " << hero1.name << " ������ ���� �������� " << hero2.name << endl;
	cout << "    [Enter]     " << endl;
	//������ ����
	int raund = 0;
	do {
		raund++;
		cout << "����� - " << raund << endl;
		if (raund % 2 == 1)
		{
			cout << "\n��� �� ����������� ������?\n[1]�����\n[2]������ (������� ���� ���������)\n[3]������� ����� (�������� 2 ����)\n[4]������\n";
			int chose_action;
			cin >> chose_action;
			cout << endl;
			switch (chose_action)
			{
				//	[1]�����
			case 1:
				if (hero2.armor == true)
				{
					hero1.chance = random(75, -25);
					if (hero1.chance >= 10) {
						hero1.damage = random(10, 10);
						hero2.hp -= hero1.damage;
						cout << "������� - ����� ����� 1: " << hero1.damage << "                �� 2 �����  " << hero2.hp << endl;
					}
					else
					{
						cout << "������� - ������" << endl;
					}
				}
				else
				{
					hero1.chance = random(100, 0);
					if (hero1.chance >= 10) {
						hero1.damage = random(10, 10);
						hero2.hp -= hero1.damage;
						cout << "������� - ����� ����� 1: " << hero1.damage << "                �� 2 �����  " << hero2.hp << endl;
						hero1.armor = false;
					}
					else
					{
						cout << "������� - ������" << endl;
						hero1.armor = false;
					}
				}
				break;

				//	[2]������ (������� ���� ���������)
			case 2:

				hero1.armor = true;
				break;

				//	[3]������� ����� (�������� 2 ����)
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
							cout << "������� -  �������� ����� | ����� 1 | ����� : " << hero1.damage << "                �� 2 �����  " << hero2.hp << endl;
							hero1.power = false;
							hero1.armor = false;
						}
						else
						{
							cout << "������� - ������" << endl;
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
							cout << "������� -  �������� ����� | ����� 1 | ����� : " << hero1.damage << "                �� 2 �����  " << hero2.hp << endl;
							hero1.power = false;
							hero1.armor = false;
						}
						else
						{
							cout << "������� - ������" << endl;
							hero1.power = false;
							hero1.armor = false;
						}
					}
				}
				break;

				//	[4]������
			case 4:
				system("cls");
				cout << hero2.name << " ������� ������\n" << "������� - " << hero1.name << endl;
				system("pause");
				break;

			default:break;
			}
		}
		else //*******************************************************************************************************************************
		{
			cout << "\n��� �� ����������� ������?\n[1]�����\n[2]������ (������� ���� ���������)\n[3]������� ����� (�������� 2 ����)\n[4]������\n";
			int chose_action;
			cin >> chose_action;
			cout << endl;
			switch (chose_action)
			{
				//	[1]�����
			case 1:
				if (hero1.armor == true)
				{
					hero1.chance = random(75, -25);
					if (hero2.chance >= 10) {
						hero2.damage = random(10, 10);
						hero1.hp -= hero1.damage;
						cout << "������� - ����� ����� 2: " << hero2.damage << "                �� 1 �����  " << hero1.hp << endl;
					}
					else
					{
						cout << "������� - ������" << endl;
					}
				}
				else
				{
					hero2.chance = random(100, 0);
					if (hero2.chance >= 10) {
						hero2.damage = random(10, 10);
						hero1.hp -= hero2.damage;
						cout << "������� - ����� ����� 2: " << hero2.damage << "                �� 1 �����  " << hero1.hp << endl;
						hero2.armor = false;
					}
					else
					{
						cout << "������� - ������" << endl;
						hero2.armor = false;
					}
				}
				break;

				//	[2]������ (������� ���� ���������)
			case 2:

				hero2.armor = true;
				break;

				//	[3]������� ����� (�������� 2 ����)
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
							cout << "������� -  �������� ����� | ����� 2 | ����� : " << hero2.damage << "                �� 1 �����  " << hero1.hp << endl;
							hero2.power = false;
							hero2.armor = false;
						}
						else
						{
							cout << "������� - ������" << endl;
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
							cout << "������� -  �������� ����� | ����� 2 | ����� : " << hero2.damage << "                �� 1 �����  " << hero1.hp << endl;
							hero2.power = false;
							hero2.armor = false;
						}
						else
						{
							cout << "������� - ������" << endl;
							hero2.power = false;
							hero2.armor = false;
						}
					}
				}
				break;

				//	[4]������
			case 4:
				system("cls");
				cout << hero1.name << " ������� ������\n" << "������� - " << hero2.name << endl;
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
		cout << " ������ �� " << hero1.name;
	}
	else
	{
		cout << " ������ �� " << hero2.name;
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