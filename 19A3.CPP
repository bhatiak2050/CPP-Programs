#include<fstream.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<dos.h>

struct Data                        //Data for all puzzles stored in file
{
	int sums[8];
        long int code;
        int mid;
        char level[9];
};
struct leader                      //Data for leaderboard file
{
	char name[10];
        long int code;
        struct Time { int m, s;};
        Time time;
};

class game
{

        int mat[3][3], i, j, pos, f, ran;
        Data st;
        ifstream fin;
        clock_t s, e;

public:
        game()                              //Constructor
        {
		for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                	mat[i][j] = 0;
                for(i=0;i<8;i++) st.sums[i]=0;
                ran=0;
        }

        void resetmat()
        {
        	for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                	mat[i][j] = 0;
        }

        void intro()
        {
        	cout<<"\t\t\t\t#1to9Puzzles\n";
                cout<<"\nWelcome to 1to9puzzles!\nThe objective of this game is to enter numbers in a 3x3 grid where \nthe sums of the corrosponding rows, columns and diagonals are given.\nThe game is won when the numbers in each row, column and diagonal match the \nsums.\n";
                cout<<"Rules:\n1)Only the numbers 1 to 9 can be used.\n";
                cout<<"2)The numbers cannot be repeated\n";
                draw();
        }

        void draw()                        //Draw main board
        {

        	cout<<"\n\n   -------------\n";

                int asc = 65;
       		for(i=0;i<3;i++)
        	{
        		cout<<"   |  ";
        		for(j=0;j<3;j++)
			cout<<mat[i][j]<<"  ";

                        if(st.sums[i]==0) cout<<"| "<<(char)asc++<<"\n";
        		else cout<<"| "<<st.sums[i]<<"\n";
        	}
        	cout<<"   -------------\n";
                if(st.sums[3]==0) cout<<(char)asc++<<"    ";
                else cout<<st.sums[3]<<"   ";

                for(i=4;i<7;i++)
		{
                	if(st.sums[i]==0) cout<<(char)asc++<<"   ";
        		else cout<<st.sums[i]<<"  ";
                }

                if(st.sums[7]==0) cout<<"  "<<(char)asc++;
                else cout<<"  "<<st.sums[7];
	}

        void getdata()                      //Get user data
        {
        	clrscr();
                resetmat();
                char ch[9];
                long int cod;
                int k=0, choice;
                fin.open("DATA.bin", ios::in | ios::binary);

                play:
                cout<<"Gameplay: \n1)Play\n2)View highscore\n3)Exit\nEnter your choice\n";
                cin>>choice;

                if(cin.fail()!=0 || choice!=1&&choice!=2&&choice!=3)
        	{
        		cin.clear();
			cin.ignore(INT_MAX, '\n');
    			cout<<"Invalid. Please enter either 1, 2 or 3\n";
			goto play;
        	}

                else if(choice==1);
                else if(choice==2)
		{
			viewhighscore();
                        cout<<endl;
                        goto play;
                }
                else if(choice==3) exit(0);

                retry:
        	cout<<"\nEnter your choice of difficulty in words (Easy, Medium, Hard)\n";
                gets(ch);

                if(strcmp(ch, "easy")==0)
                	strcpy(ch, "Easy");

                else if(strcmp(ch, "medium")==0)
                	strcpy(ch, "Medium");

                else if(strcmp(ch, "hard")==0)
                	strcpy(ch, "Hard");

                else if(strcmp(ch, "Easy")==0 || strcmp(ch, "Medium")==0 || strcmp(ch, "Hard")==0 );

                else
		{ cout<<"Please enter again"; goto retry; }

                while(k==0)
                {
                    	ran++;
                        srand(time(0)+13*pos*pow(-1, ran)*ran);
                        pos = (rand()%34)+1;
                        pos*=32;

                        fin.seekg(pos, ios::beg);
                	fin.read((char*)&st, sizeof(st));

                	if(strcmp(st.level , ch)==0)
                	{
				mat[1][1]=st.mid; k=1;
			}
                }
        }

        void gameplay()
        {
        	int check=0, var=1;
        	clrscr();
                s=clock();
                cout<<"Puzzle #"<<st.code;
                draw();
                while(check==0)
                {

        	if(var==1)
                {
                cout<<"\n\nEnter the first row\n";
                for(i=0;i<3;i++) cin>>mat[0][i];
                var=2;
                }

                if(cin.fail())
        	{
        		cin.clear();
			cin.ignore(INT_MAX, '\n');
    			cout<<"Invalid. Try again";
                        var=1;
                        continue;
        	}
                if(mat[0][0]>9||mat[0][1]>9||mat[0][2]>9)
                {
                        cout<<"Invalid. Try again";
                        var=1;
                        continue;
                }

                if(var==2)
                {
                cout<<"Enter the second row (omitting the middle number)\n";
                for(i=0;i<3;i=i+2) cin>>mat[1][i];
                var=3;
                }
                if(cin.fail())
        	{
        		cin.clear();
			cin.ignore(INT_MAX, '\n');
    			cout<<"Invalid. Try again\n";
                        var=2;
                        continue;
        	}
                if(mat[1][0]>9||mat[1][2]>9)
                {
                        cout<<"Invalid. Try again\n";
                        var=2;
                        continue;
                }

                if(var==3)
                {
                cout<<"Enter the third row\n";
                for(i=0;i<3;i++) cin>>mat[2][i];
                }
                if(cin.fail())
        	{
        		cin.clear();
			cin.ignore(INT_MAX, '\n');
    			cout<<"Invalid. Try again\n";
                        var=3;
                        continue;
        	}
                if(mat[2][0]>9||mat[2][1]>9||mat[2][2]>9)
                {
                        cout<<"Invalid. Try again\n";
                        var=3;
                        continue;
                }

                check=1;
                }

                clrscr();
                draw();
                e=clock();
                f = (e-s)/CLK_TCK;

                cout<<"\n\nValidating solution from PC...\n\n";
                delay(1000);
                getsolution();
        }

        void getsolution()
        {
                long product;
                int a[3][3], flagc=0;
         	int A,b,c,d,e,f,g,h,I;
                e=mat[1][1];

                for(i=0;i<9;i++)               //Loop 1
                {

                if(flagc==1) break;

                A=i+1;
                for(j=0;j<9;j++)               //Loop 2
                {
                	product=1;

                        b=j+1;
                 	c=st.sums[0]-A-b;
                        g=st.sums[3]-c-e;
                        h=st.sums[5]-b-e;
                        I=st.sums[7]-A-e;
                        d=st.sums[4]-A-g;
                        f=st.sums[6]-c-I;

                        product = A*b*c*d*e;
                        product = product*f*g*h*I;

                        if(product==362880)
                        {

                        if(mat[0][0]==A&&mat[0][1]==b&&mat[0][2]==c&&
                           mat[1][0]==d&&mat[1][1]==e&&mat[1][2]==f&&
                           mat[2][0]==g&&mat[2][1]==h&&mat[2][2]==I)
                        {
			    cout<<"The solution is correct!\n";
                            save();
                        }

                        else
			{
			cout<<"The solution is incorrect\n";
                        cout<<"Would you like to view the solution? (y/n): ";
                        char choice; cin>>choice;

                        if(choice=='y')
                        {
                        	mat[0][0]=A; mat[0][1]=b; mat[0][2]=c;
                                mat[1][0]=d; mat[1][1]=e; mat[1][2]=f;
                                mat[2][0]=g; mat[2][1]=h; mat[2][2]=I;
                                cout<<"\nThe correct solution is: ";
                                draw();
                                cout<<endl;
                        }
                        }
                        flagc=1;
                        break;
                        }
                }                            //Loop 2
        	}                            //Loop 1

                if(flagc==0) cout<<"No solution to this puzzle\n";
                fin.close();
        }

        void save()
        {
        	cout<<"Would you like to save your progress? (y/n) ";
                char choice; cin>>choice;
                if(choice=='y')
                {
                	leader obj;
                        fstream fout("LEADER.bin", ios::app | ios::binary);
                        if(!fout)
                        {
                        fstream fout("LEADER.bin", ios::out | ios::binary);
                        }
                        cout<<"Enter your name\n";
                        gets(obj.name);
                        obj.code = st.code;
                        obj.time.s = f%60;
                        obj.time.m = f/60;
                        fout.write((char*)&obj, sizeof(obj));
                        fout.close();
                }

        }

        void viewhighscore()
        {
        	ifstream finn("LEADER.bin", ios::in || ios::binary);
                leader obj;
                if(!finn)
                {
                	cout<<"Cannot open file.\n";
                        getch();
                        exit(0);
                }

                cout<<"Name\t\tPuzzle No.\tTime\n";
                finn.read((char*)&obj, sizeof(obj));
                while(finn.eof()==0)
                {
                        puts(obj.name);
                        cout<<"\t\t"<<obj.code;
                        cout<<"\t\t"<<obj.time.m<<" min "<<obj.time.s<<" sec"<<endl;
                        finn.read((char*)&obj, sizeof(obj));
                }
                finn.close();
	}
};

void main()
{
	clrscr();
        game ob;
	ob.intro();
        getch();

        char ch='y';
        while(ch=='y')
        {
        ob.getdata();
        cout<<"\nLoading\n";
        delay(1000);
        ob.gameplay();
        cout<<"\nWant to Play again? (y/n)\n";
        cin>>ch;
        }
}