#include <iostream>
#include <ctime>	
#include <string>
#define DEBUG

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


int attack(int hpEnemy,bool power,bool armorEnemy)
{
	int chance, damage=0;
	if (armorEnemy == true) { chance = random(75, -25); } //-25 ‰Ó (-25+75) = 50
	else { chance = random(100, 0); }
	
	if (chance >= 20)
	{
		if (power == true) { damage = random(10, 10)*2,5; }
		else { damage = random(10, 10); } //ÓÚ 10 ‰Ó (10+10) = 20
		hpEnemy -= damage;
#ifdef DEBUG
		cout << "ƒ≈¡¿√ - ƒ¿Ã¿√¿               " << damage << endl;
		cout << "ƒ≈¡¿√ - —»À¿                 " << power << endl;
#endif	
		return hpEnemy;
	}
	else
	{
#ifdef	DEBUG
		cout << "ƒ≈¡¿√ - ƒ¿Ã¿√¿               œ–ŒÃŒ’" << endl;
		cout << "ƒ≈¡¿√ - —»À¿                 "<< power << endl;
#endif
		return hpEnemy;
	}
}





bool endGame(int Heal_1,int Heal_2)
{
	if (Heal_1 > 0 && Heal_2 > 0)
	{
		return true;
	}
	else return false;
}





