#include<math.h>

#define FAILURE(char * message) printf(message); exit(1);

double gen34Calca(Status status, Ball ball, int catchRate, int hpMax, int hpCurr)
{
double ballbonus;
catchrateBonus
double statusbonus;
switch(status)
	{
	case FROZEN:
	case SLEEPING:
		statusbonus = 2;
		break;
	case PARALYZED:
	case BURNED:
	case POISONED:
		statusbonus = 1.5;
		break;
	case NONE:
		statusbonus = 1;
		break;
	default:
		FAILURE("");
	}
	int maxhpterm = 3*hpMax;
	int currhpterm = 2*hpCurr;
	double a;
	a = maxhpterm - currhpterm;
	a *= catchrate*ballbonus;
	a /= maxhpterm;
	a *= statusbonus;
	return a;
}

void gen34ShakeCheck(int b)
{
double p = b/65535.0;
printf("1 shake :  %.2lf%%\n",(1-p)*100);
printf("2 shakes : %.2lf%%\n",(p*(1-p))*100);
printf("3 shakes : %.2lf%%\n",(p*p*(1-p))*100);
printf("4 shakes (caught): %.2lf%%\n",(p*p*p)*100);
return;
}

double gen34CatchProb(int a)
{
return(((double)(a))/255.0);
}

double gen34calcb(int a)
{
double b = 1048560.0;
b /= sqrt(sqrt(16711680.0/a));
return b;
}