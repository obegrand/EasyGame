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
	cout << "Äîáðî ïîæàëîâàòü â - ÁÈÒÂÀ ÄÂÓÕ ÑÂÅÐÕ ÐÀÇÓÌÎÂ -" << endl;
	in_file << "-----------------------------------------------------" << endl;
	in_file << "Äîáðî ïîæàëîâàòü â - ÁÈÒÂÀ ÄÂÓÕ ÑÂÅÐÕ ÐÀÇÓÌÎÂ -" << endl;
	cout << "Ââåäèòå èìÿ ïåðâîãî èãðîêà\n";
	cin >> hero1.name;
	system("CLS");
	cout << "Ââåäèòå èìÿ âòîðîãî èãðîêà\n";
	cin >> hero2.name;
	system("CLS");
	in_file << "Áèòâà ìåæäó " << hero1.name << " è " << hero2.name << endl;
	if ((hero2.name == "anatoliy") || (hero1.name == "anatoliy")) { cout << "Äà íà÷í¸òñÿ áèòâà ìåæäó ÂÅËÈÊÈÌ ÂÑÅß ÐÓÑÑÈ ÀÍÀÒÎËÈÅÌ È òóïî÷êîì (òû â ìóòå)" << endl; } //|| "Anatoliy" || "Tolik" || "Toly" || "Tolynchik" || "tolik" ||"t0lyn" ||"anat0liy" ||"onatoliy" ||"TOLYNCHIK" ||"ANATOLIY" ||"TOLIK" ||"NIGGER" 
	else cout << "Äà íà÷í¸òñÿ áèòâà ìåæäó " << hero1.name << " è " << hero2.name << endl;

	//íà÷àëî èãðû
	int raund = 0;
	do
	{
		raund++;
		cout << "Ðàóíä - " << raund << " [ ";
		in_file << "Ðàóíä - " << raund << " [ ";
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

		cout << "\n×òî âû ñîáèðàåòåñü äåëàòü?\n[1]Àòàêà\n[2]Çàùèòà (ïîâûøàåò øàíñ óêëîíåíèÿ)\n[3]Ñèëüíàÿ àòàêà (çàíèìàåò 2 õîäà)\n[4]Ñäàòñÿ\n";
		int chose_action;
		cin >> chose_action;
		in_file << chose_action << endl;
		cout << endl;
		switch (chose_action)
		{
			//	[1]Àòàêà
		case 1:
			if (main_hero(raund) == true)
			{
				hero1.armor = false;
				hero1.power = false;
				hero2.hp = attack(hero2.hp, hero1.power, hero2.armor, main_hero(raund), hero1.hp, hero2.hp);
#ifdef DEBUG		
				cout << "ÄÅÁÀÃ - ÕÏ                " << hero2.hp << endl;
#endif
			}
			if (main_hero(raund) == false)
			{
				hero2.armor = false;
				hero2.power = false;
				hero1.hp = attack(hero1.hp, hero2.power, hero1.armor, main_hero(raund), hero1.hp, hero2.hp);
#ifdef DEBUG		
				cout << "ÄÅÁÀÃ - ÕÏ                " << hero1.hp << endl;
#endif
			}
			break;

			//	[2]Çàùèòà (ïîâûøåò øàíñ óêëîíåíèÿ)
		case 2:
			if (main_hero(raund) == true)
			{
				hero1.armor = true;
#ifdef DEBUG		
				cout << "ÄÅÁÀÃ - ÁÐÎÍß                " << hero1.armor << endl;
#endif
			}
			if (main_hero(raund) == false)
			{
				hero2.armor = true;
#ifdef DEBUG		
				cout << "ÄÅÁÀÃ - ÁÐÎÍß                 " << hero2.armor << endl;
#endif
			}
			break;

			//	[3]Ñèëüíàÿ àòàêà (çàíèìàåò 2 õîäà)
		case 3:
			if (main_hero(raund) == true) // hero 1 and power 1
			{
				hero1.armor = false;
				if (hero1.power == true)
				{
					hero2.hp = attack(hero2.hp, hero1.power, hero2.armor, main_hero(raund), hero1.hp, hero2.hp);
					//cout << "ÕÏ " << hero2.name << " ÃÅÐÎß: " << hero2.hp << endl;
					hero1.power = false;
				}
				else
				{
					hero1.power = true;
#ifdef DEBUG		
					cout << "ÄÅÁÀÃ - ÑÈËÀ                 " << hero1.power << endl;
#endif
				}
			}
			if (main_hero(raund) == false)
			{
				hero2.armor = false;
				if (hero2.power == true)
				{
					hero1.hp = attack(hero1.hp, hero2.power, hero1.armor, main_hero(raund), hero1.hp, hero2.hp);
					//cout << "ÕÏ " << hero1.name << " ÃÅÐÎß " << hero1.hp << endl;
					hero2.power = false;
				}
				else
				{
					hero2.power = true;
#ifdef DEBUG		
					cout << "ÄÅÁÀÃ - ÑÈËÀ                 " << hero2.power << endl;
#endif
				}
			}
			break;

			//	[4]Ñäàòñÿ
		case 4:
			if (main_hero(raund) == true)
			{
				system("cls");
				cout << hero1.name << " ïîçîðíî ñäàëñÿ\n" << "Ïîáåäèë - " << hero2.name << endl;
				in_file << hero1.name << " ïîçîðíî ñäàëñÿ\n" << "Ïîáåäèë - " << hero2.name << endl;
				hero1.hp = 0;
				system("pause");
			}
			if (main_hero(raund) == false)
			{
				system("cls");
				cout << hero2.name << " ïîçîðíî ñäàëñÿ\n" << "Ïîáåäèë - " << hero1.name << endl;
				in_file << hero2.name << " ïîçîðíî ñäàëñÿ\n" << "Ïîáåäèë - " << hero1.name << endl;
				hero2.hp = 0;
				system("pause");
			}
			break;

		case 676:

			if (main_hero(raund) == true)
			{
				cout << " âàì íå âèäàíî ïîâåçëî ÍÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀ \n --==Ê Ð È Ò  Ï À Ï È × À==-- - \n\n 1% íà ïðîê  \n Ó " << hero2.name << " [" << hero2.hp << "] " << " ÕÏ\n\n";
				in_file << " âàì íå âèäàíî ïîâåçëî ÍÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀ \n --==Ê Ð È Ò  Ï À Ï È × À==-- - \n\n 1% íà ïðîê  \n Ó " << hero2.name << " [" << hero2.hp << "] " << " ÕÏ\n\n";
				hero2.hp = -9999;
			}
			if (main_hero(raund) == false)
			{
				cout << " âàì íå âèäàíî ïîâåçëî ÍÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀ \n --==Ê Ð È Ò  Ï À Ï È × À==-- - \n\n 1% íà ïðîê  \n Ó " << hero1.name << " [" << hero1.hp << "] " << " ÕÏ\n\n";
				in_file << " âàì íå âèäàíî ïîâåçëî ÍÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀ \n --==Ê Ð È Ò  Ï À Ï È × À==-- - \n\n 1% íà ïðîê  \n Ó " << hero1.name << " [" << hero1.hp << "] " << " ÕÏ\n\n";
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
		cout << " Ïîáåäà çà " << hero1.name << endl;
		cout << string(5, '-') << string(length1 + 2, '=') << string(5, '-') << endl;
		in_file << string(5, '-') << string(length1 + 2, '=') << string(5, '-') << endl;
		in_file << " Ïîáåäà çà " << hero1.name << endl;
		in_file << string(5, '-') << string(length1 + 2, '=') << string(5, '-') << endl;
	}
	else
	{
		cout << string(5, '-') << string(length2 + 2, '=') << string(5, '-') << endl;
		cout << " Ïîáåäà çà " << hero2.name << endl;
		cout << string(5, '-') << string(length2 + 2, '=') << string(5, '-') << endl;
		in_file << string(5, '-') << string(length2 + 2, '=') << string(5, '-') << endl;
		in_file << " Ïîáåäà çà " << hero2.name << endl;
		in_file << string(5, '-') << string(length2 + 2, '=') << string(5, '-') << endl;
	}
	system("pause");
	return 0;
}