#pragma once
#include <iostream>
#include <string>

//�������� ( ������������� ����� )
void delay(double kol_sec = -1.0);
//������ ( �� 0 �� 100)
int random(int max = 100, int min = 0);
//�������� ����� ����
bool endGame(int Heal_1, int Heal_2);
//�����
int attack(int hpEnemy, bool power, bool armorEnemy, int raund, int hero1hp, int hero2hp);
//��� ���
int main_hero(int raund);
//������������ �����
void attackVisual(int damage, bool armorEnemy, bool raund, int hp1, int hp2);
//������������ �������
void attackVisualMiss(int damage, bool armorEnemy, bool raund, int hp1, int hp2);