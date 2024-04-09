#include <iostream>
#include <ctime>	
#include <fstream>	
#include <string>
#include "action.h"
//#define DEBUG
#define all_clear system("CLS");

using namespace std;

struct hero
{
	string name;
	int hp = 50;
	int damage = 0;
	double chance = 0.5;
	bool armor = false;
	bool power = false;
}hero1, hero2;

int main()
{
	fstream in_file("battle_log.txt", ios::in | ios::app);
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	system("CLS");
	cout << "����� ���������� � - ����� ���� ����� ������� -" << endl;
	in_file << "-----------------------------------------------------" << endl;
	in_file << "����� ���������� � - ����� ���� ����� ������� -" << endl;
	cout << "������� ��� ������� ������\n";
	cin >> hero1.name;
	system("CLS");
	cout << "������� ��� ������� ������\n";
	cin >> hero2.name;
	system("CLS");
	in_file << "����� ����� " << hero1.name << " � " << hero2.name << endl;
	if ((hero2.name == "anatoliy") || (hero1.name == "anatoliy")) { cout << "�� ������� ����� ����� ������� ���� ����� ��������� � �������� (�� � ����)" << endl; } //|| "Anatoliy" || "Tolik" || "Toly" || "Tolynchik" || "tolik" ||"t0lyn" ||"anat0liy" ||"onatoliy" ||"TOLYNCHIK" ||"ANATOLIY" ||"TOLIK" ||"NIGGER" 
	else cout << "�� ������� ����� ����� " << hero1.name << " � " << hero2.name << endl;

	//������ ����
	int raund = 0;
	do
	{
		raund++;
		cout << "����� - " << raund << " [ ";
		in_file << "����� - " << raund << " [ ";
		if (main_hero(raund) == true) {
			cout << hero1.name;
			in_file << hero1.name;
		}
		if (main_hero(raund) == false) {
			cout << hero2.name;
			in_file << hero2.name;
		}
		cout << " ]" << endl;
		in_file << " ]" << endl;

		cout << "\n��� �� ����������� ������?\n[1]�����\n[2]������ (�������� ���� ���������)\n[3]������� ����� (�������� 2 ����)\n[4]������\n";
		int chose_action;
		cin >> chose_action;
		in_file << chose_action << endl;
		cout << endl;
		switch (chose_action)
		{
			//	[1]�����
		case 1:
			if (main_hero(raund) == true)
			{
				hero1.armor = false;
				hero1.power = false;
				hero2.hp = attack(hero2.hp, hero1.power, hero2.armor, main_hero(raund), hero1.hp, hero2.hp);
#ifdef DEBUG		
				cout << "����� - ��                " << hero2.hp << endl;
#endif
			}
			if (main_hero(raund) == false)
			{
				hero2.armor = false;
				hero2.power = false;
				hero1.hp = attack(hero1.hp, hero2.power, hero1.armor, main_hero(raund), hero1.hp, hero2.hp);
#ifdef DEBUG		
				cout << "����� - ��                " << hero1.hp << endl;
#endif
			}
			break;

			//	[2]������ (������� ���� ���������)
		case 2:
			if (main_hero(raund) == true)
			{
				hero1.armor = true;
#ifdef DEBUG		
				cout << "����� - �����                " << hero1.armor << endl;
#endif
			}
			if (main_hero(raund) == false)
			{
				hero2.armor = true;
#ifdef DEBUG		
				cout << "����� - �����                 " << hero2.armor << endl;
#endif
			}
			break;

			//	[3]������� ����� (�������� 2 ����)
		case 3:
			if (main_hero(raund) == true) // hero 1 and power 1
			{
				hero1.armor = false;
				if (hero1.power == true)
				{
					hero2.hp = attack(hero2.hp, hero1.power, hero2.armor, main_hero(raund), hero1.hp, hero2.hp);
					//cout << "�� " << hero2.name << " �����: " << hero2.hp << endl;
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
				hero2.armor = false;
				if (hero2.power == true)
				{
					hero1.hp = attack(hero1.hp, hero2.power, hero1.armor, main_hero(raund), hero1.hp, hero2.hp);
					//cout << "�� " << hero1.name << " ����� " << hero1.hp << endl;
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
				in_file << hero1.name << " ������� ������\n" << "������� - " << hero2.name << endl;
				hero1.hp = 0;
				system("pause");
			}
			if (main_hero(raund) == false)
			{
				system("cls");
				cout << hero2.name << " ������� ������\n" << "������� - " << hero1.name << endl;
				in_file << hero2.name << " ������� ������\n" << "������� - " << hero1.name << endl;
				hero2.hp = 0;
				system("pause");
			}
			break;

		case 676:

			if (main_hero(raund) == true)
			{
				cout << " ��� �� ������ ������� ������������������������������������������������������ \n --==� � � �  � � � � � �==-- - \n\n 1% �� ����  \n � " << hero2.name << " [" << hero2.hp << "] " << " ��\n\n";
				in_file << " ��� �� ������ ������� ������������������������������������������������������ \n --==� � � �  � � � � � �==-- - \n\n 1% �� ����  \n � " << hero2.name << " [" << hero2.hp << "] " << " ��\n\n";
				hero2.hp = -9999;
			}
			if (main_hero(raund) == false)
			{
				cout << " ��� �� ������ ������� ������������������������������������������������������ \n --==� � � �  � � � � � �==-- - \n\n 1% �� ����  \n � " << hero1.name << " [" << hero1.hp << "] " << " ��\n\n";
				in_file << " ��� �� ������ ������� ������������������������������������������������������ \n --==� � � �  � � � � � �==-- - \n\n 1% �� ����  \n � " << hero1.name << " [" << hero1.hp << "] " << " ��\n\n";
				hero1.hp = -9999;
			}


			break;

		default:break;
		}

		delay(-2);
		system("cls");
		if (raund > 100) { system("pause"); }

	} while (endGame(hero1.hp, hero2.hp));

	int length1 = hero1.name.size();
	int length2 = hero2.name.size();

	if (hero1.hp > hero2.hp)
	{
		cout << string(5, '-') << string(length1+2, '=') << string(5, '-') << endl;
		cout << " ������ �� " << hero1.name << endl;
		cout << string(5, '-') << string(length1 + 2, '=') << string(5, '-') << endl;
		in_file << string(5, '-') << string(length1 + 2, '=') << string(5, '-') << endl;
		in_file << " ������ �� " << hero1.name << endl;
		in_file << string(5, '-') << string(length1 + 2, '=') << string(5, '-') << endl;
	}
	else
	{
		cout << string(5, '-') << string(length2 + 2, '=') << string(5, '-') << endl;
		cout << " ������ �� " << hero2.name << endl;
		cout << string(5, '-') << string(length2 + 2, '=') << string(5, '-') << endl;
		in_file << string(5, '-') << string(length2 + 2, '=') << string(5, '-') << endl;
		in_file << " ������ �� " << hero2.name << endl;
		in_file << string(5, '-') << string(length2 + 2, '=') << string(5, '-') << endl;
	}
	system("pause");
	return 0;
}