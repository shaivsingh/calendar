#include<stdio.h>
#include<stdlib.h>
void main()
{
	int year,m;
	
	printf("Enter date in mm-yyyy : ");
	scanf("%d-%d",&m,&year);
	calendar(year,m);
	getch();
}
int calendar(int year,int m)
{
		if(m>12)
	{
		year = year + 1;
		m = m - 12;
	}
	else if(m<1)
	{
		year = year - 1;
		m= 12 - abs(m);
	}
	system("cls");
	int i,cd,j,fdy,d,ds=0,first_day_month,leap,choice;
	char *months[]={" ","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	if((year%4==0 && year%100!=0) || (year%100==0 && year%400==0))
		leap = 29;
	else
		leap = 28;
	fdy=first_day_year(year);
	int days[] = {fdy,31,leap,31,30,31,30,31,31,30,31,30,31};
	
	for(i=0;i<m;i++)
	{
		ds = ds + days[i];
	}
	//printf("%d\n",ds);
	first_day_month = ds%7;
	//printf("%d\n",first_day_month);
	d=1;
		printf("\n\t\t\t%d\t",year);
		puts(months[m]);
		printf("\tMon\tTue\tWed\tThu\tFri\tSat\tSun\n\t");
	if(first_day_month<5)
		cd = 5;
	else
		cd = 6;
	for(i=1;i<=cd;i++)
	{
		for(j=1;j<=7;j++)
		{
			if(first_day_month>0)
			{
				printf("-\t");
				first_day_month--;
			}
			else
			{
				printf("%d\t",d);
				d++;
				if(d>days[m])
				{
					printf("\n");
					d=1;
					break;
				}
			}
		}
		printf("\n\t");
	}
	printf("Up arrow key : Next year, same month \n");
	printf("\tDown arrow key : Previous year, same month\n"); 
	printf("\tRight arrow key : Same year, next month\n"); 
	printf("\tLeft arrow key : Same year, previous month\n");
	printf("\tPress 'ESC' to exit\n\t");
	choice = getkey();
	printf("%d",choice);
	switch(choice)
	{
		case 72:
			year = year + 1;
			calendar(year,m);
		 break;
		case 80:
			year = year - 1;
			calendar(year,m);
			break;
		case 77:
			m = m + 1;
			calendar(year,m);
			break;
		case 75:
			m = m - 1;
			calendar(year,m);
			break;
		case 27:
			exit(0);
	}
	return 0;
}

int first_day_year(int year)
{
	int leapdays, firstday, yr; 
	long int normaldays, totaldays; 
	yr = year; 
	normaldays = (yr-1)*365; 
	leapdays = (yr-1)/4-(yr-1) /100 +(yr - 1)/400; 
	totaldays = normaldays + leapdays; 
	firstday = totaldays % 7; 
	return firstday;
}
int getkey()
{
int ch;
ch = _getch();
if (ch == 224)
ch = _getch();
return ch;
}
