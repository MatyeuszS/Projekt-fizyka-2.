#include <stdio.h>
#include <math.h>
main()
{
	double h0 = 100;
	double a = -9.81;
	double dt = 0.1;
	double t = 0;
	double h1 = h0;
	double vy = 0;
	double vp = 0;
	
	FILE *plik=NULL;
	
	plik=fopen("algorytm.txt", "w");
	
	if(plik==NULL)
	{
		perror("Blad Otwarcia Pliku\n");
		return 13;
	}
	else
	{
		fprintf(plik, "t[s],         y(t)[m],       vy(t)[m/s]\n");
		fprintf(plik, "%f      %f     %f\n", t, h1, vy);
		while(h1>0)
		{
			t=t+dt;
			vy=vy+a*dt;
			h1=h1+vy*dt;
			printf("vy=%f", h1);
			fprintf(plik, "%f      %f      %f\n", t, h1, -vy);	
		}
	
	}
	
}
