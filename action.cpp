#include <iostream>
#include <ctime>	
#include <string>
//#define DEBUG

using namespace std;

void delay(double kol_sec = -1)
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

int random(int max = 100, int min = 0)
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

int main_hero(int raund)
{
	if (raund % 2 == 1) //1,3,5,7...
	{
		return 1;
	}
	else return 0;
}



bool endGame(int Heal_1,int Heal_2)
{
	if (Heal_1 > 0 && Heal_2 > 0)
	{
		return true;
	}
	else return false;
}

void attackVisual(int damage, bool armorEnemy,bool raund, int hp1, int hp2)
{
	if (raund == 1)
	{
		if (armorEnemy == true)
		{
			cout << endl;
			cout << "  O    " << damage << "   O  " << endl;
			cout << " /|\\,/ " << "->" << " @/|\\ " << endl;
			cout << " / \\   " << "  " << "  / \\ " << endl;
			cout << "[" << hp1 << "]" << "       " << "[" << hp2-damage << "]" << endl;
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "  O    " << damage << "   O  " << endl;
			cout << " /|\\,/ " << "->" << "  /|\\ " << endl;
			cout << " / \\   " << "  " << "  / \\ " << endl;
			cout << "[" << hp1 << "]" << "       " << "[" << hp2-damage << "]" << endl;
			cout << endl;
		}
	}
	else
	{
		if (armorEnemy == false)
		{
			cout << endl;
			cout << "  O    " << damage << "     O  " << endl;
			cout << " /|\\   " << "<-" << "  \\,/|\\ " << endl;
			cout << " / \\   " << "  " << "    / \\ " << endl;
			cout << "[" << hp1-damage << "]" << "        " << "[" << hp2 << "]" << endl;
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "  O    " << damage << "    O  " << endl;
			cout << " /|\\@  " << "<-" << " \\,/|\\ " << endl;
			cout << " / \\   " << "  " << "   / \\ " << endl;
			cout << "["<< hp1 - damage <<"]" << "       " << "[" << hp2 << "]" << endl;
			cout << endl;
		}
	}
}

void attackVisualMiss(int damage, bool armorEnemy, bool raund, int hp1, int hp2)
{
	if (raund == 1)
	{
		if (armorEnemy == true)
		{
			cout << endl;
			cout << "  O   " << "Miss" << "  O  " << endl;
			cout << " /|\\,/ " << "->" << " @/|\\ " << endl;
			cout << " / \\   " << "  " << "  / \\ " << endl;
			cout << "[" << hp1 << "]" << "       " << "[" << hp2 << "]" << endl;
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "  O   " << "Miss" << "  O  " << endl;
			cout << " /|\\,/ " << "->" << "  /|\\ " << endl;
			cout << " / \\   " << "  " << "  / \\ " << endl;
			cout << "[" << hp1 << "]" << "       " << "[" << hp2  << "]" << endl;
			cout << endl;
		}
	}
	else
	{
		if (armorEnemy == false)
		{
			cout << endl;
			cout << "  O   " << "Miss" << "    O  " << endl;
			cout << " /|\\   " << "<-" << "  \\,/|\\ " << endl;
			cout << " / \\   " << "  " << "    / \\ " << endl;
			cout << "[" << hp1  << "]" << "        " << "[" << hp2 << "]" << endl;
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "  O   " << "Miss" << "   O  " << endl;
			cout << " /|\\@  " << "<-" << " \\,/|\\ " << endl;
			cout << " / \\   " << "  " << "   / \\ " << endl;
			cout << "[" << hp1  << "]" << "       " << "[" << hp2 << "]" << endl;
			cout << endl;
		}
	}
}


int attack(int hpEnemy, bool power, bool armorEnemy, int raund, int hp1, int hp2)
{
	int chance, damage = 0;
	bool armorEnemy1 = armorEnemy;
	int raund2 = raund;
	if (armorEnemy == true) { chance = random(75, -25); } //-25 ‰Ó (-25+75) = 50
	else { chance = random(100, 0); }

	if (chance == 99)
	{
		if (power == true) { damage = 676; }
		else { damage = 676; } //ÓÚ 10 ‰Ó (10+10) = 20
		cout << " ‚‡Ï ÌÂ ‚Ë‰‡ÌÓ ÔÓ‚ÂÁÎÓ Õ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿ \n   – » “ œ ¿ œ » ◊ ¿ - \n\n\n\n1% Ì‡ ÔÓÍ   " << damage << endl;
		hpEnemy -= damage;
		return hpEnemy;
	}


		if (chance >= 20)
		{
			if (power == true) { damage = random(10, 10) * 2,5; }
			else { damage = random(10, 10); } //ÓÚ 10 ‰Ó (10+10) = 20
#ifdef DEBUG
			cout << "ƒ≈¡¿√ - ƒ¿Ã¿√¿               " << damage << endl;
			cout << "ƒ≈¡¿√ - —»À¿                 " << power << endl;
#endif	
			attackVisual(damage, armorEnemy1, raund2,hp1,hp2);
			hpEnemy -= damage;
			return hpEnemy;
		}
		else
		{
#ifdef	DEBUG
			cout << "ƒ≈¡¿√ - ƒ¿Ã¿√¿               œ–ŒÃŒ’" << endl;
			cout << "ƒ≈¡¿√ - —»À¿                 " << power << endl;
#endif
			attackVisualMiss(damage, armorEnemy1, raund2, hp1, hp2);
			return hpEnemy;
		}
	
}