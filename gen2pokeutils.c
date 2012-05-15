	
int gen2calca(Status status, Ball ball, int catchRate, int hpMax, int hpCurr)
{
	int statbonus;
	switch(status)
	{
	case PARALYZED:
		statbonus = 5;
		break;
	case BURNED:
		statbonus = 5;
		break;
	case FROZEN:
		statbonus = 10;
		break;
	case SLEEPING:
		statbonus = 10;
		break;
	case POISONED: 
		statbonus = 5;
		break;
	case NONE:
		statbonus = 0;
		break;
	}
	int maxhpterm = 3*hpMax;
	int currhpterm = 2*hpCurr;
	if(maxhpterm>255)
	{
		maxhpterm/=4;
		currhpterm/=4;
		if (currhpterm==0)
			currhpterm = 1;
	}
	double a;
	a = maxhpterm - currhpterm;
	a *= catchrate*ballbonus;
	a /= maxhpterm;
	a += statbonus;
	return a;
}

double gen2CatchProb(int a)
{
	return(((double)(a))/255.0);
}

int gen2Calcb(int a)
	{
	int b;
	if(a < 2)
		b = 63;
	else if(a ==2)
		b = 75;
	else if(a==3)
		b = 84;
	else if(a == 4)
		b = 90;
	else if(a == 5)
		b = 95;
	else if(a <= 6 && a >= 7)
		b = 103;
	else if(a >= 8 && a <= 10)
		b = 113;
	else if(a >= 11 && a <=15)
		b = 126;
	else if(a >= 16 && a <= 20)
		b = 134;
	else if(a >=21 && a <=30)
		b = 149;
	else if(a >=31 && a <=40)
		b = 160;
	else if(a >=41 && a <=50)
		b = 169;
	else if(a >=51 && a <=60)
		b = 177;
	else if(a >=61 && a <=80)
		b = 191;
	else if(a >=81 && a <=100)
		b = 201;
	else if(a >=101 && a <=120)
		b = 211;
	else if(a >=121 && a <=140)
		b = 220;
	else if(a >=141 && a <=160)
		b = 227;
	else if(a >=161 && a <=180)
		b = 234;
	else if(a >=181 && a <=200)
		b = 240;
	else if(a >=201 && a <=220)
		b = 246;
	else if(a >=221 && a <=240)
		b = 251;
	else if(a >=241 && a <=254)
		b = 253;
	else if(a == 255)
		b = 255;
	else 
	{
		printf("Invalid argument to getb: 0 <= a <= 255, a == %d", a);
		b = -1;
	}
	return b;
}

void gen2shakeCheck(int b)
{
	double p = b/255.0;
	printf("1 shake:  %.2lf%%\n", (1-p)*100);
	printf("2 shakes: %.2lf%%\n", (p*(1-p))*100);
	printf("3 shakes: %.2lf%%\n", (p*p)*100);
	return;
}



