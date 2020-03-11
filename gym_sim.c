#include <stdio.h>
//#include <math.h>

float money=100,stamina=100 , max_stamina=100, next_lvl=100 , exp;
int lvl=1;
void stats(int day,int stamina , float money) //int day , int stamina , float money
{
	printf("Nick\n"); // nick
	printf("Dzien %i\n",day); // dzien
	int o,i=(int)stamina/10;
	int cont=i;
	printf("[");
	for(i;i>0;i--) printf("#");
	if(cont<10)
		{
			for(o=10-cont;o>0;o--) printf(" ");
		}
	printf("] %i/%i\n",(int)stamina , (int)max_stamina);
	printf("%0.2f$\n",money); // pieniadze
	printf("lvl: %i\t",lvl);
	printf("%0.2f / %0.2f\n",exp , next_lvl);
	//printf("Dzik\n"); // ranga
	printf("===============================\n");
}

void not_enought_stamina()
{
	printf("\n Nie masz wystarczajaco sily ! Odpocznij!");
	Sleep(1500);
}

void not_enought_money()
{
	printf("\n Nie masz wystarczajaco pieniedzy ! Idz do pracy!");
	Sleep(1500);
}

void workout(stamina_pkt ,exp_pkt)
{
	if((stamina-stamina_pkt)>=0) 
	{
		stamina-=stamina_pkt;
		exp_f(exp_pkt);
	}
	else
	{
		not_enought_stamina();
	}
}

void exp_f(exp_pkt)
{
	exp+=exp_pkt;
	if(exp==next_lvl)
	{
		lvl_up();
	}
}

void lvl_up()
{
	exp=0;
	next_lvl*=1.5;
	lvl++;
}

void shop(int price, float stamina_pkt)
{
	if(money-price>=0)
	{
		money-=price;
		max_stamina+=stamina_pkt;
	}
	else
	{
		not_enought_money();
	}
}

int main()
{	
	int opcja=0,day=0;
	while(1)
	{
	int przerwa=0;
	system("cls");
	stats(day , (int)stamina , money);
	printf("1.Silka\n2.Sklep\n3.Odpoczynek\n4.Praca\n\n5.Wyjdz z gry\n");
	printf("Wybor: "); scanf("%i",&opcja);
	switch(opcja)
	{
		case 1:
			{
				while(przerwa==0)
				{
				system("cls");
				stats(day , (int)stamina , money);
				printf("1.Klata -10pkt +5xp.\n2.Bicek -5pkt +2xp.\n3.Nogi -20pkt. +10xp\n4.Cardio -10pkt. +5xp\n\n5.Powrot\n");
				printf("Wybor: s"); scanf("%i",&opcja);
				switch(opcja)
				{
					case 1:
						{
							workout(10,5);
							break;
						}
					case 2:
						{
							workout(5,2);
							break;
						}
					case 3:
						{
							workout(20,10);
							break;
						}
					case 4:
						{
							workout(10,5);
							break;
						}
					case 5:
						{
							przerwa=1;
							break;
						}
				}
				}	
			}
		case 2:
			{
				while(przerwa==0)
				{
					system("cls");
					stats(day , (int)stamina , money);
					printf("1.Bia³ko +20pkt. -40$\n\n2.Powrot\n");
					printf("Wybor: "); scanf("%i",&opcja);
					switch(opcja)
					{
						case 1:
							{
								shop(40,20);
								break;
							}
						case 2:
							{
								przerwa=1;
								break;
							}
					}
				}
				break;
			}
		case 3:
			{
				stamina = max_stamina;
				day++;
				break;
			}
		case 4:
			{
				break;
			}
		case 5:
			{
				//zapisz
				return 0;
			}
		default: printf("Nie ma takiego numeru\n"); Sleep(1500); system("cls");
	}
	}
}
