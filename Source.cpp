#include <iostream>
#include <ctime>	
#include <string>
#include "action.h"

#define DEBUG
#define all_clear system("CLS");

using namespace std;


struct hero
{

	
	string name;
	int hp = 50;
	int damage;
	double chance = 0.5;
	bool armor = false;
	bool power = false;

}hero1, hero2;


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	cout << "����� ���������� � -�������� ����-" << endl;
	cout << "������� ��� ������� ������\n";
	cin >> hero1.name;
	system("CLS");
	cout << "������� ��� ������� ������\n";
	cin >> hero2.name;
	system("CLS");


	if ((hero2.name == "anatoliy") || (hero1.name == "anatoliy")) { cout << "�� ������� ����� ����� ������� ���� ����� ��������� � �������� (�� � ����)" << endl; } //|| "Anatoliy" || "Tolik" || "Toly" || "Tolynchik" || "tolik" ||"t0lyn" ||"anat0liy" ||"onatoliy" ||"TOLYNCHIK" ||"ANATOLIY" ||"TOLIK" ||"NIGGER" 
	else cout << "�� ������� ����� ����� " << hero1.name << " � " << hero2.name << endl;




	//������ ����

	int raund = 0;

	do
	{
		raund++;
		cout << "����� - " << raund << " [ ";
		if (main_hero(raund) == true)
		{
			cout << hero1.name;
		}
		if (main_hero(raund) == false)
		{
			cout << hero2.name;
		}
		cout << " ]" << endl;

		cout << "\n��� �� ����������� ������?\n[1]�����\n[2]������ (������� ���� ���������)\n[3]������� ����� (�������� 2 ����)\n[4]������\n";
		int chose_action;
		cin >> chose_action;
		cout << endl;
		switch (chose_action)
		{
			//	[1]�����
		case 1:
			if (main_hero(raund) == true)
			{
				hero1.power = false;
				hero2.hp = attack(hero2.hp, hero1.power, hero2.armor);
				cout << "�� " << hero2.name << " �����: " << hero2.hp << endl; //"<< main_hero(raund)+1 <<"
			}
			if (main_hero(raund) == false)
			{
				hero2.power = false;
				hero1.hp = attack(hero1.hp, hero2.power, hero1.armor);
				cout << "�� " << hero1.name << " �����: " << hero1.hp << endl; // "<< main_hero(raund)+1 <<"
			}
			break;

			//	[2]������ (������� ���� ���������)
		case 2:
			if (main_hero(raund) == true)
			{
				hero1.armor = true;
			}
			if (main_hero(raund) == false)
			{
				hero2.armor = true;
			}
			break;

			//	[3]������� ����� (�������� 2 ����)
		case 3:
			if (main_hero(raund) == true) // hero 1 and power 1
			{
				if (hero1.power == true)
				{
					hero2.hp = attack(hero2.hp, hero1.power, hero2.armor);
					cout << "�� " << hero2.name << " �����: " << hero2.hp << endl;
					hero1.power = false;
				}
				else 
				{
					hero1.power = true;
#ifdef DEBUG		
					cout << "����� - ����                 " << hero1.power << endl;
#endif
				}
			}
			if (main_hero(raund) == false)
			{
				if (hero2.power == true)
				{
					hero1.hp = attack(hero1.hp, hero2.power, hero1.armor);
					cout << "�� " << hero1.name << " ����� " << hero1.hp << endl;
					hero2.power = false;
				}
				else
				{
					hero2.power = true;
#ifdef DEBUG		
					cout << "����� - ����                 " << hero2.power << endl;
#endif
				}
			}
				break;

				//	[4]������
		case 4:
			if (main_hero(raund) == true)
			{
				system("cls");
				cout << hero1.name << " ������� ������\n" << "������� - " << hero2.name << endl;
				hero1.hp = 0;
				system("pause");
			}
			if (main_hero(raund) == false)
			{
				system("cls");
				cout << hero2.name << " ������� ������\n" << "������� - " << hero1.name << endl;
				hero2.hp = 0;
				system("pause");
			}
			break;
			//
		case 5:

			break;

			default:break;
		}
			cout << "-----------------------------" << endl;
			delay(-2);
			system("cls");
			if (raund > 100) { system("pause"); }
		
	}while (endGame(hero1.hp, hero2.hp));


		if (hero1.hp > hero2.hp)
		{
			cout << " ������ �� " << hero1.name << endl;
		}
		else
		{
			cout << " ������ �� " << hero2.name << endl;
		}
		system("pause");
		return 0;
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