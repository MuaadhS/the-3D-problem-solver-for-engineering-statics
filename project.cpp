
#include<iostream>
#include<cmath> 
#include<iomanip>
#include <stdlib.h> //to use system("cls");


using namespace std;

class angle 
{
	public:
		const static float PI = 3.14159265; 
		const static int deg = 180;
		
		// will be called when we need to convert an angle from radians to cartasian and vice versa
};


void opt1(); // for option 1 in menu
float opt2(); // for option 2 in menu
float opt3(); // for option 3 in menu
void opt4();// for option 4 in menu

float calcopt2(float, float); // calculations for option 2
float calcopt3(float[], float[], int); // calculations for option 3
float calcopt4(float [][3]); // to find the determinant

int main()
{
	char ans;
	do
	{
	
		int choice;
	
	
		cout<<endl<<" ---------------------------- WELCOME TO THE 3D PROBLEM SOLVER ------------------------------------"<<endl;
	
		cout<<"MAIN MENU:"<<endl;
		cout<<"1-Cartesian Vectors Convertor."<<endl;
		cout<<"2-Find The Missing Angle."<<endl;
		cout<<"3-Dot Product"<<endl;
		cout<<"4-Equilibrium Calculator"<<endl;
		cout<<"Please enter a number from main menu: ";
		cin>>choice;
	
		while(choice<1 || choice>4)
		{
			cout<<"Invalide input please enter a number from menu: ";
			cin>>choice; // will keep asking the user to input a valid number from menu
		}
		switch (choice)
		{
			case 1: 
			{
			system("cls"); // to clear the screen
			opt1();
			};break;
			case 2: 
			{
			system("cls");
			opt2();
			};break;
			case 3: 
			{
			system("cls");
			opt3();
			};break;
			case 4: 
			{
			system("cls");
			opt4();
			};break;
		}
	
	
	cout<<endl<<endl<<"Do you want to continue?"<<endl;
	cout<<"If yes enter the key Y or y. if not press any key to exit. "<<endl;
	cout<<"Your answer:";
	cin>>ans;
	
	system("cls");
	}while(ans=='Y'||ans=='y'); // do while loop to keep the program running until the user close it
	cout<<endl<<"Thank you!";
	
	
	
	
	return 0;
}

void opt1()
{
	
	int coor[3],i;
	float f,fx,fy,fz,ux,uy,uz,x,y,z,mag_coor; // forces and unit vectors 
	char axis= 119; // to display the coordintates x,y,z
	
	cout<<setprecision(3)<<showpoint<<fixed; // to display 3 decimal numbers
	
	cout<<"_______________________________________________________________________________"<<endl;
	cout<<"Enter the x, y and z coordinate (R) of the force:"<<endl;
	
	for(int i=0;i<3;i++)
	{
	axis=axis+1; // x , y , z
		cout<<"\nEnter the "<<axis<<" coordinate:";
		cin>>coor[i]; // array for the coordinates
	}
	
	x=pow(coor[0],2);
	y=pow(coor[1],2);
	z=pow(coor[2],2);
	
	mag_coor=sqrt(x+y+z);
	
	
	
	cout<<endl<<"Magnitude of the coordinate is "<<mag_coor<<endl;
	
	ux=coor[0]/mag_coor;
	uy=coor[1]/mag_coor;
	uz=coor[2]/mag_coor;
	cout<<"The unit vector: ("<<ux<<")i + ("<<uy<<")j + ("<<uz<<")k"<<endl<<endl;
	
	cout<<"Enter the magnitude of the force:";
	cin>>f;
	fx=f*ux;
	fy=f*uy;
	fz=f*uz;
	
	cout<<endl<<"Force in cartisean form:"<<endl;
	cout<<"("<<fx<<")i + ("<<fy<<")j + ("<<fz<<")k";
}
float opt2()
{
   float x, y, ang;
   
   cout<<setprecision(3)<<showpoint<<fixed;
   
   cout<<"_______________________________________________________________________________"<<endl;
   cout<<"Enter the first angle: ";
   cin>>x;
   cout<<"Enter the second angle: ";
   cin>>y;
   ang=calcopt2(x, y); // calculations in calopt2() function
   cout<<"The missing angle is: "<<ang<<endl;
}
float opt3()
{
	const int SIZE=3;
	float vec1[SIZE], vec2[SIZE];
	char axis=119;
	float ang;
	
	cout<<setprecision(3)<<showpoint<<fixed;
	
	cout<<"_______________________________________________________________________________"<<endl;
	cout<<"Enter vector1 <x,y,z>: "<<endl;
	
	for(int i=0;i<SIZE;i++)
	{
	axis=axis+1;
		cout<<"Enter the "<<axis<<" value:";
		cin>>vec1[i];
	}
	axis=119;
	cout<<endl<<"Enter vector2 <x,y,z>: "<<endl;
	for(int j=0; j<SIZE; j++)
	{
		axis=axis+1;
		cout<<"Enter the "<<axis<<" value:";
		cin>>vec2[j];
	}
	cout<<endl<<"Vector 1 is: <"<<vec1[0]<<","<<vec1[1]<<","<<vec1[2]<<">"<<endl;
	cout<<"Vector 2 is: <"<<vec2[0]<<","<<vec2[1]<<","<<vec2[2]<<">"<<endl;
	
	ang=calcopt3(vec1, vec2, SIZE); // calculations in calopt3() function
	cout<<"The angle is: "<<ang<<endl;
}
void opt4()
{
	const int rows=3;
	const int cols1=3;
	const int cols2=1;
	
	float mat[rows][cols1], mat2[rows][cols2], temp[rows][cols2];
	float det, det2, det3 , det4;
	int set;
	char axis=119;

	cout<<setprecision(3)<<showpoint<<fixed;
	
	cout<<"_______________________________________________________________________________"<<endl;
	cout<<"Please follow the sample to avoid confusion."<<endl;
	cout<<"The last numbers to the right are for equality"<<endl;
	cout<<"For example the equations : Fx = 1F1 + 2F2 + 3F3 = 4"<<endl;
	cout<<"                            Fy = 5F1 + 6F2 + 7F3 = 8"<<endl;
	cout<<"                            Fz = 9F1 + 0F2 + 1F3 = 2"<<endl;
	cout<<"would be written as follows:"<<endl;
	cout<<"     F1 F2 F3"<<endl;
	cout<<"Fx:  1  2  3  4"<<endl;
	cout<<"Fy:  5  6  7  8"<<endl;
	cout<<"Fz:  9  0  1  2"<<endl;
	
	cout<<"Enter your values:"<<endl;
	for(int i=0; i<rows;i++)
	{
		set=0; //to update set as thee loop is executed  
		axis=axis+1;
		cout<<"F"<<axis<<": ";
		for(int j=0; j<cols1; j++)
		{
		cin>>mat[i][j]; // the main matrix 3x3
		set+=1;
		while(set==3) // if the condition is true the number would be input to another matrix
		{
		cin>>mat2[0][i];
		set++;
		}
		}
	}

	det=calcopt4(mat); // function calcopt4() only calcuates the determinant
	

	for(int x=0; x<rows; x++)
	{
	temp[x][0]=mat[x][0];
	mat[x][0]=mat2[x][0];	
	}  // swaping colomns inside the matrixes
	
	det2=calcopt4(mat); // get the determinant for the modified matrix
    
    for(int x=0; x<rows; x++)
    {
    	mat[x][0]=temp[x][0];
	}
	// swap back 
	for(int x=0; x<rows; x++)
	{
	temp[x][0]=mat[x][1];
	mat[x][1]=mat2[x][0];	
	} 

	det3=calcopt4(mat);
    
    for(int x=0; x<rows; x++)
    {
    	mat[x][1]=temp[x][0];
	}
	
	
	for(int x=0; x<rows; x++)
	{
	temp[x][0]=mat[x][2];
	mat[x][2]=mat2[x][0];	
	} 

	det4=calcopt4(mat);
    
    for(int x=0; x<rows; x++)
    {
    	mat[x][2]=temp[x][0];
	}
	
	float f1, f2, f3;
	
	cout<<"\nthe answer is: "<<endl;
	
	f1=det2/det;
	f2=det3/det;
	f3=det4/det;
	
	
	cout<<"F1= "<<f1<<endl;
	cout<<"F2= "<<f2<<endl;
	cout<<"F3= "<<f3<<endl;

}

float calcopt2(float x, float y)
{
angle obj;	// class object

	float z;
	
	cout<<setprecision(3)<<showpoint<<fixed;
    
	x=x * (obj.PI / obj.deg); // values from class
    y=y * (obj.PI / obj.deg); // converting degrees to radians
	
	z= acos(sqrt(1-pow(cos(x),2)-pow(cos(y),2))); // missing angle formula
	z= z * (obj.deg / obj.PI); // radians to degrees
	return z;
}

float calcopt3(float vec1[], float vec2[], int SIZE)
{
	angle obj; // class object
	float ang, dot=0,rad, x1, y1, z1, x2, y2, z2;
	
	for(int i=0; i<SIZE; i++)
	{
		dot+=vec1[i]*vec2[i];
	}
	cout<<"The dot product is: "<<dot<<endl;
	
	x1=pow(vec1[0],2);
	y1=pow(vec1[1],2);
	z1=pow(vec1[2],2);
	
	float mag_vec1=sqrt(x1+y1+z1);
	
	x2=pow(vec2[0],2);
	y2=pow(vec2[1],2);
	z2=pow(vec2[2],2);
	
	float mag_vec2=sqrt(x2+y2+z2);
	
	rad=acos(dot/(mag_vec2*mag_vec1));
	ang=(rad*obj.deg)/obj.PI; // radians to degrees
	return ang;
}

float calcopt4(float mat[][3])
{
	float det;
	
	det=mat[0][0]*(mat[1][1]*mat[2][2]-mat[2][1]*mat[1][2]) 
    -mat[0][1]*(mat[1][0]*mat[2][2]-mat[2][0]*mat[1][2]) 
    +mat[0][2]*(mat[1][0]*mat[2][1]-mat[2][0]*mat[1][1]); // fixed for 3x3 matrixes
	
	
	return det;
}
