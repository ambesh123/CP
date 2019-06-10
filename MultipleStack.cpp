#include<iostream>
using namespace std;
#define MAX 10
#define emp -999
	int a[MAX],A=0,B=MAX-1;
void insA(int);
void insB(int);
void delA();
void delB();
void display();
main()
{

	for(int i=0;i<MAX;i++)a[i]=emp;
	int ch=0,data;
	while(ch!=6)
	{
	 cout<<"\nEnter choice: \n1.Stack A insert 2.Stack A POP\n3.Stack B insert 4.Stack B POP\n5.Display 6.Exit\n";
	 cin>>ch;
	 switch(ch)
	 {
	 	case 1: cout<<"Enter Element: "; cin>>data; insA(data);
	 		break;
	 	case 2: delA();
	 		break;
	 	case 3: cout<<"Enter Element: "; cin>>data; insB(data);
	 		break;
	 	case 4: delB();
	 		break;
	 	case 5: display();
	 		break;
	 	default: cout<<"What the hell?\n";
	 } 
    }
}

void insA(int data)
{
 if(A==B)cout<<"OverFlow!";
 else{
 
 a[A]=data;	A++;}
}
void insB(int data)
{
 if(A==B)cout<<"OverFlow!";
 else
 {a[B]=data;	B--;}
}
void delA()
{ if(A==0)cout<<"UnderFlow!";
 else{
 a[A]=emp; A--;
}
}
void delB()
{ if(B==MAX-1)cout<<"UnderFlow";
  else{
  a[B]=emp; B++;}
}
void display()
{ int i=0;
  cout<< "\nStack A: "; if(A==0)cout<<"Empty!"; else while(i<A){cout<<a[i]<<" "; i++;}
  i=MAX-1;
  cout<< "\nStack B: "; if(B==MAX-1)cout<<"Empty!"; else while(i>B){cout<<a[i]<<" "; i--;}
}
