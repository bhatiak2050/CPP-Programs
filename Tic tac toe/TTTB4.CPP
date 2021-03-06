#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<dos.h>

void far line(int x1, int y1, int x2, int y2);
void intro();
void about();
void rules();
void resetA();

void hvh();
void hvc();
int set();
int check();
void brains();

char a[9] = {'X', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
int o[9]={0, 0, 0, 0, 0};

char* ch="X";
int i, j, play=0, pos=0, count=0;

void main()
{
	beg:
        play=0;
	int gdriver = DETECT, mode;
	initgraph(&gdriver, &mode, "c:\\tc\\bgi");
	cleardevice();

	int x = getmaxx();
	int y = getmaxy();

        //Printing main screen
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 7);
	outtextxy(((x/2)-170), (y-400), "Tic Tac Toe");
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	outtextxy((x-638), (y-30), "By Karan Bhatia");
	outtextxy((x-80), (y-30), "Beta 4");
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);

        //Printing Menu
	line(150, 200, 500, 200);
	line(150, 310, 500, 310);
	line(150, 200, 150, 310);
	line(500, 200, 500, 310);
	outtextxy(155, 205, "1. About game");
	outtextxy(155, 225, "2. Rules");
	outtextxy(155, 245, "3. Human vs. Computer");
	outtextxy(155, 265, "4. Human vs. Human");
	outtextxy(155, 285, "5. Exit");

        //Get user choice
	cin>>play;
        if(cin.fail())
        {
        	cin.clear();
		cin.ignore();
    		cout<<"Invalid. Try again\n";
                delay(500);
        	goto beg;
        }


	again:
	resetA();
	//closegraph();

        //Print Tic Tac Toe
	initgraph(&gdriver, &mode, "c:\\tc\\bgi");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	line(250, 200, 400, 200);
	line(250, 250, 400, 250);
	line(300, 150, 300, 300);
	line(350, 150, 350, 300);
	outtextxy(255, 155, "1");
	outtextxy(305, 155, "2");
	outtextxy(355, 155, "3");
	outtextxy(255, 205, "4");
	outtextxy(305, 205, "5");
	outtextxy(355, 205, "6");
	outtextxy(255, 255, "7");
	outtextxy(305, 255, "8");
	outtextxy(355, 255, "9");

	if(play==1)
	{	about(); goto beg;}
	else if(play==2)
	{	rules(); goto beg;}
	else if(play==3)
		hvc();
	else if(play==4)
		hvh();
	else if(play==5)
		exit(0);
        else goto beg;
	getch();

	cout<<"\nPlay again ? (y/n)";
	char ag; cin>>ag;
	if(ag=='y'|| ag=='Y') goto again;
}
void hvc()
{
	int q, d, full;
        count=0;
	reenter:

        //choose character
	cout<<"Enter X or O\n";
	cin>>ch;

        //Check Character
	if(*ch=='X' || *ch=='x') *ch='X';
        else if(*ch=='O' || *ch=='o') *ch='O';
	else
	{ cout<<"Invalid. Try again\n"; goto reenter; }

	clock_t s, e;          //Timer
	s = clock();

	int c[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; //Store CPU moves
	int p[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; //Store Player moves

        //Gameplay
	for(i=0;i<9;i++)
	{
	renum:
	cout<<"Where to put "<<*ch<<" ?(1-9)";   //Enter position
	cin>>pos;

        if(cin.fail())   //Check Integrety of position
        {
        	cin.clear();
		cin.ignore();
    		cout<<"Invalid. Try again\n";
        	goto renum;
        }

        //Check position occupied
	if(p[0]==pos || p[1]==pos || p[2]==pos || p[3]==pos ||    //This block of code
	p[4]==pos || p[5]==pos || p[6]==pos || p[7]==pos ||       //appears to have never
	p[8]==pos || p[9]==pos)                                   //executed?!?
	{cout<<"Position occupied. Try again\n"; goto renum; }

	p[i]=pos;	//Store position for player
        o[i]=pos;

        //Print character
	q = set();
   	if(q==1) break;    //Game over
	else if(q==2) { i--; continue; }   //Invalid character
        /*else if(q==0)
        {
        	for(d=0;d<9;d++)
                {
                	if(o[d]==0)
                        {
                        	full=0;
                                goto eto;
                        }
                        else
				full=1;
                }
        	if(full==1) {cout<<"draw"; break;}
                eto:
	} */

        //CPU's Turn

	cout<<"CPU is choosing\n";
	retry:
	e=clock();
	double f = (e-s)/CLK_TCK;
       	if(f>=120.0)
	{
      		cout<<"\nDraw";  	          //Check if Draw
		line(250, 150, 390, 290);
		line(390, 150, 250, 290);
		goto end;
        }

        //Generate Random Number
	/*srand(time(0));
	pos = (rand()%9)+1;
        if(pos%2==0)
        {
            	srand(time(0)+i);
		pos = (rand()%9)+1;
        }
        else if(i>0)    */
		brains();

        //Check if position occupied
	for(j=0;j<=i;j++)
	if(c[j]==pos || p[j]==pos) goto retry;

	c[i]=pos;
	o[i]=pos;         //Store CPU position
	q = set();         //Print CPU position
	if(q==1) break;    //Game over

	}
        end:
}
void hvh()
{
	reenter:

        //Choose character
	cout<<"Enter X or O\n";
	cin>>ch;

        //Check character
	if(*ch=='X' || *ch=='x') *ch='X';
        else if(*ch=='O' || *ch=='o') *ch='O';
	else
	{ cout<<"Invalid. Try again\n"; goto reenter; }

        //Gameplay
	for(i=0;i<9;i++)
	{
		renum:

                //Enter position
		cout<<"Where to put "<<*ch<<"? (1-9)";
		cin>>pos;

                if(cin.fail())     //Check integrety of position
                {
                	cin.clear();
                        cin.ignore();
                        cout<<"Invalid. Try again\n";
                        goto renum;
                }

                //Check position occcupied
		if(o[0]==pos || o[1]==pos || o[2]==pos || o[3]==pos ||
		   o[4]==pos || o[5]==pos || o[6]==pos || o[7]==pos ||
		   o[8]==pos || o[9]==pos)
		{cout<<"Position occupied. Try again\n"; goto renum; }

		o[i]=pos;       //Store position

		int q = set();
		if(q==1) break;   //Game over
		else if(q==2){ i--; continue; }
                if(i==8)
		{	cout<<"Draw";
                	line(250, 150, 390, 290);
                        line(390, 150, 250, 290);
                }
	}
}
int set()
{
	//Display character on Tic tac toe screen
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
	switch(pos)
	{
	case 1:{ outtextxy(255, 155, ch); a[0] = *ch;}
	break;
	case 2:{ outtextxy(305, 155, ch); a[1] = *ch;}
	break;
	case 3:{ outtextxy(355, 155, ch); a[2] = *ch;}
	break;
	case 4:{ outtextxy(255, 205, ch); a[3] = *ch;}
	break;
	case 5:{ outtextxy(305, 205, ch); a[4] = *ch;}
	break;
	case 6:{ outtextxy(355, 205, ch); a[5] = *ch;}
	break;
	case 7:{ outtextxy(255, 255, ch); a[6] = *ch;}
	break;
	case 8:{ outtextxy(305, 255, ch); a[7] = *ch;}
	break;
	case 9:{ outtextxy(355, 255, ch); a[8] = *ch;}
	break;
	default:
	{	cout<<"Please enter a number\nbetween 1 to 9\n";
		return 2;}
        }

        //Change character
        if(*ch=='X') *ch='O';
        else *ch='X';

        //Check game status
        int q = check();
        return q;
}
int check()
{
	//Check if row or column or diagonal contain same character
	if(a[0] == a[1] && a[1] == a[2])
	{	cout<<"Player "<<a[0]<<" won";
		line(250, 170, 400, 170); return 1;}
	else if(a[3] == a[4] && a[4] == a[5])
	{	cout<<"Player "<<a[3]<<" won";
		line(250, 220, 400, 220); return 1;}
	else if(a[6] == a[7] && a[7] == a[8])
	{	cout<<"Player "<<a[6]<<" won";
		line(250, 270, 400, 270); return 1;}
	else if(a[0] == a[3] && a[3] == a[6])
	{	cout<<"Player "<<a[0]<<" won";
		line(270, 150, 270, 300); return 1;}
	else if(a[1] == a[4] && a[4] == a[7])
	{	cout<<"Player "<<a[1]<<" won";
		line(320, 150, 320, 300); return 1;}
	else if(a[2] == a[5] && a[5] == a[8])
	{	cout<<"Player "<<a[2]<<" won";
		line(370, 150, 370, 300); return 1;}
	else if(a[0] == a[4] && a[4] == a[8])
	{	cout<<"Player "<<a[0]<<" won";
		line(250, 150, 390, 290); return 1;}
	else if(a[2] == a[4] && a[4] == a[6])
	{	cout<<"Player "<<a[2]<<" won";
		line(390, 150, 250, 290); return 1;}
	else;
        return 0;

}

void brains()
{
	int u=0;
	count++;
        if(count>=7)
	{
		if(count>=8)
		{
		if(count>=9)
		{
		if(count>=10)
		{
		if(count>=11)
		{
		if(count>=12)
		{
		if(count>=13)
		{
		if(count>=14)
		{
		if(count>=15)
		{
		goto d2;
		}
		goto d1;
		}
		goto c3;
		}
		goto c2;
		}
		goto c1;
		}
		goto r3;
		}
		goto r2;
		}
		goto r1;
		}
	}
        //Row 1
        r1:
	if(a[0] == a[1])
        {u=1;	pos = 3;}
        else if(a[1] == a[2])
        {u=1;	pos = 1;}
        else if(a[0] == a[2])
        {u=1;	pos = 2;}
        //Row 2
        r2:
        if(a[3] == a[4])
        {u=1;	pos = 6;}
        else if(a[4] == a[5])
        {u=1;	pos = 4;}
        else if(a[3] == a[5])
        {u=1;	pos = 5;}
        //Row 3
        r3:
        if(a[6] == a[7])
        {u=1;	pos = 9;}
        else if(a[7] == a[8])
        {u=1;	pos = 7;}
        else if(a[6] == a[8])
        {u=1;	pos = 8;}
        //Column 1
        c1:
        if(a[0] == a[3])
        {u=1;	pos = 7;}
        else if(a[3] == a[6])
        {u=1;	pos = 1;}
        else if(a[0] == a[7])
        {u=1;	pos = 4;}
        //Column 2
        c2:
        if(a[1] == a[4])
        {u=1;	pos = 8;}
        else if(a[4] == a[7])
        {u=1;	pos = 2;}
        else if(a[1] == a[7])
        {u=1;	pos = 5;}
        //Column 3
        c3:
        if(a[2] == a[5])
        {u=1;	pos = 9;}
        else if(a[5] == a[8])
        {u=1;	pos = 3;}
        else if(a[2] == a[8])
        {u=1;	pos = 6;}
        //Diagonal 1
        d1:
        if(a[0] == a[4])
        {u=1;	pos = 9;}
        else if(a[4] == a[8])
        {u=1;	pos = 1;}
        else if(a[0] == a[8])
        {u=1;	pos = 5;}
        //Diagonal 2
        d2:
        if(a[2] == a[4])
        {u=1;	pos = 7;}
        else if(a[4] == a[6])
        {u=1;	pos = 3;}
        else if(a[2] == a[6])
        {u=1;	pos = 5;}
        else
        {
        	if(u==1) goto out;
        	srand(time(0));
		pos = (rand()%9)+1;
        }
        out:
}
void about()
{       cleardevice();
	cout<<"Tic-tac-toe (also known as Noughts and crosses or Xs and Os) is a paper-and-pencil game for two players, X and O, who take turns marking the spaces in a 3�3 grid. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game.";

	cout<<"Game of Tic-tac-toe, won by X Players soon discover that best play from both parties leads to a draw. Hence, Tic-tac-toe is most often played by young children. Because of the simplicity of Tic-tac-toe, it is often used as a pedagogical tool for teaching the concepts of good sportsmanship and the branch of artificial intelligence that deals with the searching of game trees. It is straightforward to write a computer program to play Tic-tac-toe perfectly, to enumerate the 765 essentially different positions (the state space complexity), or the 26,830 possible games up to rotations and reflections (the game tree complexity) on this space";
        getch();
        play=0;
        //closegraph();
}
void rules()
{
	cleardevice();
	cout<<"The rules are simple. The first player enters a number between 1 to 9 (without repeating any number) and presses enter. An X or O appears in that position. Simillarly the next player enters a number between 1 to 9. Each player's turn alternates till the game is either won or draw.";
        getch();
        play=0;
        //closegraph();
}
void resetA()
{
	int i, j;
        for(i=0, j=97;i<9;i++, j++)
	{	a[i]=(char)j; }
	for(i=0;i<9;i++) o[i]=0;
}