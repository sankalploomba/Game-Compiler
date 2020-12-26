#include <iostream>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#define t_factor 1000
#endif

#ifdef linux
#include <unistd.h>
#define t_factor 1
#endif

#define NL cout<<endl;
#define AGENT "\u26F9"
#define ARENA "  "
#define OBJECT "\u26BD"

using namespace std;

class Display
{
	public:
		string a[15][15];
		int obj_x,obj_y;
		int x,y,nrow,ncolumn,i,j;
		bool isPause=false,inst=true;
		
		Display()
		{
			y=13;		x=13;
			nrow=14;	ncolumn=14;
			i=0;		j=0;
			init();
			bound();
			obj();
			show();
			srand (time(NULL));
		}
		
		int bound();
		int init();
		int obj();
		
		int show();
		int Update(char s);
		int movUp();
		int movDown();
		int movLeft();
		int movRight();
		void pause();

};

int Display::bound()
{
	//Vertical Lines
	for (i = 1; i < nrow; i++)
	{
		a[i][0]="\u2503";
		a[i][ncolumn]="\u2503";
	}
	
	//Horizontal Lines
	for (i = 1; i <ncolumn; i++)
	{
		a[0][i]="\u2501";
		a[nrow][i]="\u2501";
	}
	
	//Corners
	a[0][0]="\u250F"; a[nrow][0]="\u2517"; a[0][ncolumn]="\u2513"; a[ncolumn][ncolumn]="\u251B";
	return 1;
}
int Display::init()
{
	for (i = 1; i < nrow; i++)
		for (j = 1; j < ncolumn; j++)
			a[i][j]=ARENA;

	a[x][y]=AGENT;
	return 1;
}
int Display::obj()
{
	obj_x=rand()%13 + 1;
	obj_y=rand()%13 + 1;

	a[obj_y][obj_x]=OBJECT;
	return 1;
}
int Display::show()
{
	if(inst==true)
	{
		system("clear");
		
		cout<<"CONTROLS"<<endl;
		cout<<"W - Move Up"<<endl<<"S - Move Down"<<endl<<"A - Move Left"<<endl<<"D - Move Right"<<endl<<"P - Pause/Resume"<<endl<<"Q - Quit"<<endl<<"Enter - To submit command"<<endl;
		
		sleep(10 * t_factor);
		inst=false;
	}
	
	system("clear");
	NL
	for (i = 0; i <= nrow; i++)
	{
		cout<<setw(30);
		for (j = 0; j <= ncolumn; j++)
		{
			cout<<a[i][j];
		}
		NL
	}
	NL
	return 1;
}
int Display::Update(char s)
{
	if(!isPause){
		switch (s)
		{
			case 'A':
			{
						if(x==1)
							cout<<"Error: Trying to go out of Arena.";

						else
						{
							a[y][x--]=ARENA; a[y][x]=AGENT;
							
							if(x==obj_x && y==obj_y)
								obj();
						}
						break;
			}	
			case 'D':
			{
						if(x==13)
							cout<<"Error: Trying to go out of Arena.";
						
						else
						{
							a[y][x++]=ARENA; a[y][x]=AGENT;
							
							if(x==obj_x && y==obj_y)
								obj();
						}
						break;
			}
			case 'W':
			{
						if(y==1)
							cout<<"Error: Trying to go out of Arena.";
						
						else
						{
							a[y--][x]=ARENA; a[y][x]=AGENT;
							
							if(y==obj_y && x==obj_x)
								obj();
						}
						break;
			}
			case 'S':
			{
						if(y==13)
							cout<<"Error: Trying to go out of Arena.";
						
						else
						{
							a[y++][x]=ARENA; a[y][x]=AGENT;
							
							if(y==obj_y && x==obj_x)
								obj();
						}
						break;
			}
		}
		show();
	}
	else
		show();

	return 1;
}

int Display::movUp()
{
	Update('W');
	return 1;
}
int Display::movDown()
{
	Update('S');
	return 1;
}
int Display::movLeft()
{
	Update('A');
	return 1;
}
int Display::movRight()
{
	Update('D');
	return 1;
}

void Display::pause()
{ 
	if(isPause)
	{
		cout<<"Game Resumed"<<endl;
		isPause=false;
	}
	else
	{
		cout<<"Game Paused"<<endl;
		isPause=true;
	}
}

