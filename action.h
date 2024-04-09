#pragma once
#include <iostream>
#include <string>

//задержка ( отрицательное число )
void delay(double kol_sec = -1.0);
//рандом ( от 0 до 100)
int random(int max = 100, int min = 0);
//проверка конца игры
bool endGame(int Heal_1, int Heal_2);
//атака
int attack(int hpEnemy, bool power, bool armorEnemy, int raund, int hero1hp, int hero2hp);
//чей ход
int main_hero(int raund);
//визуализация атаки
void attackVisual(int damage, bool armorEnemy, bool raund, int hp1, int hp2);
//визуализация промоха
void attackVisualMiss(int damage, bool armorEnemy, bool raund, int hp1, int hp2);