#define FAILURE(char * message) printf(message); exit(1);

gen1CalcCatchProb(int catchrate, Ball ball, int hpMax, int hpCurr, Status status)
{
	double R;
	double pa,pbcomp,pc;
	switch(ball)
	{
	case POKE:
		R = 256.0;
	case GREAT:
		R = 201.0;
	case ULTRA:
		R = 151.0;
	case MASTER:
		return 1;
	default:
		printf("")
		exit(0);
	}
	switch(status)
	{
	case SLEEP:
	case FROZEN:
		pa = 25/R;
		break;
	break;
	case PARALYZED:
	case BURNED:
	case POISONED:
		pa = 12/R;
		break;
	case NONE:
		pa = 0;
		break;
	default:
		FAILURE()
	}
	pbcomp = (catchRate+1)/R;
	pc = (gen1Calcf(hpMax, ball, hpCurr)+1)/255.0;
	return pa+(pbcomp*pc);
}

int gen1Calcf(int hpMax, Ball ball, int hpCurr)
	{
	int f,ctemp,ballFactor;
	f = hpMax * 255;
	/*Ball factor is 8 for great, 12 for poke and ultra (?)*/
	switch(ball)
	{
	case GREAT:
		ballFactor=8;
		break;
	case POKE:
	case ULTRA:
		ballFactor=12;
		break;
	default:
		FAILURE()
	}
	/*All divisions are integer, rounded up to 1 if result is 0 to prevent divison by zero*/
	f = max(1,f/ballFactor);
	ctemp = max(1,currHP/4);
	f = max(1,f/ctemp);
	/*Return minimum of f, 255;*/
	return -(max(-f,-255));
}

gen1Calcd(int catchRate, Ball ball)
{
int ballFactor;
switch(ball)
{
case POKE:
	ballFactor = 255;
	break;
case GREAT:
	ballFactor = 200;
	break;
case ULTRA:
	ballFactor = 150;
	break;
default:
	FAILURE()
}
return (catchRate*100/ballFactor);
}

void gen1ShakeCheck(int catchrate, Ball ball, int hpMax, int hpCurr, Status status)
{
double d = gen1calcD() 
double oneshake,twoshake,threeshake;
if(d>=256)
{
printf("Ball shakes 3 times\n");
}
else
{
int f = gen1calcF();
int temp = d * f/255;
switch(status)
{
case SLEEP:
case FROZEN:
	temp += 10;
case PARALYZED:
case POISONED:
case BURNED:
	temp += 5;
default:
	FAILURE("")
}
if(temp<30)
printf("Ball shakes 1 time\n");
else if(temp<70)
printf("Ball shakes 2 times\n")'
else
printf("Ball shakes 3 times");
}
return;


}


