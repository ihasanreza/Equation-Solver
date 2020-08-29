#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
const int row=5,col=5;
int mat1[row][col];
int constant[row][1];
void swap (int&,int&);
int det(int , int [row][col]);
int main()
{   
	system("Color F5");

	cout<<"-------------------------------\"SYSTEM OF EQUATIONS\"----------------------------\n\n";
	cout<<"---------------------------------SEMESTER PROJECT-------------------------------\n";
	cout<<"GROUP MEMBERS:\n\n";
	cout<<"1. Mehdi Imam\t\t\t(CS_124)\n2. Muhammad Ammar\t\t(CS_126)\n3. Muhammad Hassan\t\t(CS_118)\n4. Muhammad Tahseen\t\t(CS_119)\n\n";
	for (int i=0; i<80; i++)
		cout<<"=";
	cout<<endl;

	int n; char ch, dummy;
	do{
		cout << "1. anX + bnY = cn\n"
			 << "2. anX + bnY + cnZ = dn\n"
			 << "3. anX + bnY + cnZ + dnP = en\n"
			 << "4. anX + bnY + cnZ + dnP + enQ = fn\n\n";
	cout<<"Enter your choice here:    ";
	cin >> n;
	switch (n)
	{
	case 1:
		{
			float dx, dy, d;
			cout << "\nEnter coefficients by pressing tab and then press enter:\n\n";
l2:			cout << "\tx\ty \n"
			  << "------------------\n";
			for (int i=0; i<n+1; i++)		// Taking input the elements of Matrix (values of x & y)
			{
				cout <<i+1<<"  |\t";
				for (int j=0; j<n+1; j++)
				{
				cin >> mat1[i][j];
			    }
			}								// Matrix input ends here

			cout << "\nEnter constants by pressing tab and then press enter:\n\n";
			cout << "c"  <<"  |\t";
			for (int i=0; i<n+1; i++)			// Taking input the constant Matrix
			{
				for (int j=0; j<n; j++)
				{
					cin >> constant[i][j];
				}
			}									// Constant input ends here
			system("cls");

			cout << "\nAre these your equations?\t(y/n)\n\n";
			cout <<"(" << mat1[0][0] << "x) + (" << mat1[0][1]<<"y) = " << constant[0][0] <<endl
				 <<"(" << mat1[1][0] << "x) + (" << mat1[1][1]<<"y) = " << constant[1][0] <<endl;
			cout << "\t\t"; 
			cout<<"\nEnter your choice here:           "; 
			cin >> dummy;

			if (dummy=='Y' || dummy=='y')
			{

			d= det(n+1,mat1);						// Calculating determinant of Matix of x and y
			if(d==0)
			{
				cout<<"\t\t\tMATH ERROR!\n";
				break;
			}
			for (int i=0; i<n+1; i++)		// Creating Ax Matrix
			{	
				for (int j=0;j<n; j++)
				{
				swap (mat1[i][j],constant[i][j]);
				}
			}
			cout << endl;
			dx=det(n+1,mat1);					//Finding determinant of Ax Matrix

			cout<<"Answers are found to be: \n";
			cout << endl << "X= "<<dx<<"/"<<d<<"      OR     "<<(dx/d)<<endl;	//Dispay X

			// For Y
		for (int i=0; i<n+1; i++)			// Getting original Matrix back
			{	
				
				for (int j=0;j<n; j++)
				swap (constant[i][j],mat1[i][j]);
				
			}

			for (int i=0; i<n+1; i++)		// Creating Ay Matrix
			{	
				
				for (int j=1;j<n+1; j++)
				swap (mat1[i][j],constant[i][j-1]);
				
			}
			dy=det(n+1,mat1);					// Findind determinant of Ay Matrix

			cout <<endl<< "Y= " <<dy<<"/"<<d<<"      OR      "<<(dy/d)<<endl<<endl;		// Display Y
			for(int i=0; i<80; i++)
				cout<<"*";
			break;
			}					//if dummy
			else
			{
				cout << "\n\n\t*Try again*\n\n";
				goto l2;
			}
	}    //end case 1
	case 2:
			{
			float d,dx, dy, dz;
			cout << "\nEnter coefficients by pressing tab and then press enter:\n\n";
			cout << "\tx\ty\tz\t \n"
			  << "--------------------------\n";
			for (int i=0; i<n+1; i++)		// Taking input the elements of Matrix (values of x & y)
			{
				cout <<i+1<<"  |\t";
				for (int j=0; j<n+1; j++)
				{
					cin >> mat1[i][j];
			    }
			}								// Matrix input ends here

			cout << "\nEnter constants by pressing tab and then press enter:\n\n";
			cout << "c"  <<"  |\t";
			for (int i=0; i<n+1; i++)			// Taking input the constant Matrix
			{
				for (int j=0; j<1; j++)
				{
					cin >> constant[i][j];
				}
			}									// Constant input ends here
				system("cls");

			cout << "\nAre these your equations?\t(y/n)\n\n";
			cout << "(" << mat1[0][0] << "x) + (" << mat1[0][1] << "y) + (" << mat1[0][2] << "z) = " << constant[0][0] <<endl
				 << "(" << mat1[1][0] << "x) + (" << mat1[1][1] << "y) + (" << mat1[1][2] << "z) = " << constant[1][0] <<endl
				 << "(" << mat1[2][0] << "x) + (" << mat1[2][1] << "y) + (" << mat1[2][2] << "z) = " << constant[2][0] <<endl;
			cout<<"\nEnter your choice here:           "; 
			cin >> dummy;



			d=det(n+1,mat1);						// Calculating determinant of Matix of x and y
			if(d==0)
			{
				cout<<"\t\t\tMATH ERROR!\n";
				break;
			}
			for (int i=0; i<n+1; i++)		// Creating Ax Matrix
			{	
				
				for (int j=0;j<n-1; j++)
				swap (mat1[i][j],constant[i][j]);
				
			}
			cout << endl;
			dx=det(n+1,mat1);			//Finding determinant of Ax Matrix

			cout<<"Answers are found to be: \n";
			cout << endl << "X= "<<dx<<"/"<<d<<"      OR      "<<(dx/d)<<endl;	//Dispay X
			// For Y
		for (int i=0; i<n+1; i++)			// Getting original Matrix back
			{	
				
				for (int j=0;j<n-1; j++)
				swap (constant[i][j],mat1[i][j]);
				
			}

			for (int i=0; i<n+1; i++)		// Creating Ay Matrix
			{	
				
				for (int j=1;j<n; j++)
				swap (mat1[i][j],constant[i][j-1]);
				
			}
			dy=det(n+1,mat1);					// Findind determinant of Ay Matrix
            cout <<endl<< "Y= " <<dy<<"/"<<d<<"      OR      "<<(dy/d)<<endl;		// Display Y
			for (int i=0; i<n+1; i++)			// Getting original Matrix back
			{	
				
				for (int j=1;j<n; j++)
				swap (constant[i][j-1],mat1[i][j]);
				
			}

			for (int i=0; i<n+1; i++)		// Creating Az Matrix
			{	
				
				for (int j=2;j<n+1; j++)
				swap (mat1[i][j],constant[i][j-2]);
				
			}
			dz=det(n+1,mat1);
			cout << endl << "Z= "<<dz<<"/"<<d<<"      OR      "<<(dz/d)<<endl<<endl;	//Dispay Z
			for(int i=0; i<80; i++)
				cout<<"*";
			break;
	    }	//end case 2
	case 3:
			{
			double d, dx, dy, dz, dp;
			cout << "\nEnter coefficients by pressing tab and then press enter:\n\n";
			cout << "\tx\ty\tz\tp\t \n"
			  << "----------------------------------\n";
			for (int i=0; i<n+1; i++)		// Taking input the elements of Matrix (values of x & y)
			{
				cout <<i+1<<"  |\t";
				for (int j=0; j<n+1; j++)
				{
					cin >> mat1[i][j];
			    }
			}								// Matrix input ends here

			cout << "\nEnter constants by pressing tab and then press enter:\n\n";
			cout << "c"  <<"  |\t";
			for (int i=0; i<n+1; i++)			// Taking input the constant Matrix
			{
				for (int j=0; j<1; j++)
				{
					cin >> constant[i][j];
				}
			}									// Constant input ends here
			system("cls");

			cout << "\nAre these your equations?\t(y/n)\n\n";
			cout << "(" << mat1[0][0] << "x) + (" << mat1[0][1] << "y) + (" << mat1[0][2] << "z) + (" << mat1[0][3] << "p) = " << constant[0][0] <<endl
				 << "(" << mat1[1][0] << "x) + (" << mat1[1][1] << "y) + (" << mat1[1][2] << "z) + (" << mat1[1][3] << "p) = " << constant[1][0] <<endl
				 << "(" << mat1[2][0] << "x) + (" << mat1[2][1] << "y) + (" << mat1[2][2] << "z) + (" << mat1[2][3] << "p) = " << constant[2][0] <<endl
				 << "(" << mat1[3][0] << "x) + (" << mat1[3][1] << "y) + (" << mat1[3][2] << "z) + (" << mat1[3][3] << "p) = " << constant[3][0] <<endl;
			cout<<"\nEnter your choice here:           "; 
			cin >> dummy;

			d= det(n+1,mat1);						// Calculating determinant of Matix of x and y
			if(d==0)
			{
				cout<<"\t\t\tMATH ERROR!\n";
				break;
			}
			for (int i=0; i<n+1; i++)		// Creating Ax Matrix
			{	
				
				for (int j=0; j<n-2; j++)
				swap (mat1[i][j],constant[i][j]);
				
			}
			cout << endl;
			dx=det(n+1,mat1);					//Finding determinant of Ax Matrix

			cout<<"Answers are found to be: \n";
			cout << endl << "X= "<<dx<<"/"<<d<<"      OR      "<<(dx/d)<<endl;	//Dispay X

			// For Y
		for (int i=0; i<n+1; i++)			// Getting original Matrix back
			{	
				
				for (int j=0;j<n-2; j++)
				swap (constant[i][j],mat1[i][j]);
				
			}

			for (int i=0; i<n+1; i++)		// Creating Ay Matrix
			{	
				
				for (int j=1;j<n-1; j++)
				swap (mat1[i][j],constant[i][j-1]);
				
			}
			dy=det(n+1,mat1);					// Findind determinant of Ay Matrix
            cout << "\nY= " <<dy<<"/"<<d<<"      OR      "<<(dy/d)<<endl;		// Display Y
			for (int i=0; i<n+1; i++)			// Getting original Matrix back
			{	
				
				for (int j=1;j<n-1; j++)
				swap (constant[i][j-1],mat1[i][j]);
				
			}

			for (int i=0; i<n+1; i++)		// Creating Az Matrix
			{	
				
				for (int j=2;j<n; j++)
				swap (mat1[i][j],constant[i][j-2]);
				
			}
			dz=det(n+1,mat1);
			cout << endl << "Z= "<<dz<<"/"<<d<<"      OR      "<<(dz/d)<<endl;	//Dispay Z
			for (int i=0; i<n+1; i++)			// Getting original Matrix back
			{	
				for (int j=2;j<n; j++)
				swap (constant[i][j-2],mat1[i][j]);
				
			}

			for (int i=0; i<n+1; i++)		// Creating Az Matrix
			{	
				
				for (int j=3;j<n+1; j++)
				swap (mat1[i][j],constant[i][j-3]);
				
			}
			dp=det(n+1,mat1);
			cout << endl << "P= "<<dp<<"/"<<d<<"      OR      "<<(dp/d)<<endl<<endl;	//Dispay P
			for(int i=0; i<80; i++)
				cout<<"*";
			break;
	    }	//end case 3
		case 4:
			{
			double d, dx, dy, dz, dp,dq;
			cout << "\nEnter coefficients by pressing tab and then press enter:\n\n";
			cout << "\tx\ty\tz\tp\tq \n"
			  << "-----------------------------------------\n";
			for (int i=0; i<n+1; i++)		// Taking input the elements of Matrix (values of x & y)
			{
				cout <<i+1<<"  |\t";
				for (int j=0; j<n+1; j++)
				{
					cin >> mat1[i][j];
			    }
			}								// Matrix input ends here

			cout << "\nEnter constants by pressing tab and then press enter:\n\n";
			cout << "c"  <<"  |\t";
			for (int i=0; i<1; i++)			// Taking input the constant Matrix
			{
				for (int j=0; j<n-3; j++)
				{
					cin >> constant[i][j];
				}
			}									// Constant input ends here
			system("cls");

			cout << "\nAre these your equations?\t(y/n)\n\n";
			cout << "(" << mat1[0][0] << "x) + (" << mat1[0][1] << "y) + (" << mat1[0][2] << "z) + (" << mat1[0][3] << "p) + (" << mat1[0][4] << "q) = " << constant[0][0] <<endl
				 << "(" << mat1[1][0] << "x) + (" << mat1[1][1] << "y) + (" << mat1[1][2] << "z) + (" << mat1[1][3] << "p) + (" << mat1[1][4] << "q) = " << constant[1][0] <<endl
				 << "(" << mat1[2][0] << "x) + (" << mat1[2][1] << "y) + (" << mat1[2][2] << "z) + (" << mat1[2][3] << "p) + (" << mat1[2][4] << "q) = " << constant[2][0] <<endl
				 << "(" << mat1[3][0] << "x) + (" << mat1[3][1] << "y) + (" << mat1[3][2] << "z) + (" << mat1[3][3] << "p) + (" << mat1[3][4] << "q) = " << constant[3][0] <<endl
				 << "(" << mat1[4][0] << "x) + (" << mat1[4][1] << "y) + (" << mat1[4][2] << "z) + (" << mat1[4][3] << "p) + (" << mat1[4][4] << "q) = " << constant[4][0] <<endl;
			cout<<"\nEnter your choice here:           "; 
			cin >> dummy;

			d= det(n+1,mat1);						// Calculating determinant of Matix of x and y
			if(d==0)
			{
				cout<<"\t\t\tMATH ERROR!\n";
				break;
			}
			for (int i=0; i<n+1; i++)		// Creating Ax Matrix
			{	
				{
				for (int j=0;j<n-3; j++)
				swap (mat1[i][j],constant[i][j]);
				}
			}
			cout << endl;
			dx=det(n+1,mat1);					//Finding determinant of Ax Matrix

			cout<<"Answers are found to be: \n";
			cout << endl << "X= "<<dx<<"/"<<d<<"      OR      "<<(dx/d)<<endl;	//Dispay X
			

			// For Y
		for (int i=0; i<n+1; i++)			// Getting original Matrix back
			{	
				
				for (int j=0;j<n-3; j++)
				swap (constant[i][j],mat1[i][j]);
				
			}
		
			for (int i=0; i<n+1; i++)		// Creating Ay Matrix
			{	
				
				for (int j=1;j<n-2; j++)
				swap (mat1[i][j],constant[i][j-1]);
				
			}
			dy=det(n+1,mat1);					// Findind determinant of Ay Matrix
            cout <<endl<< "Y= " <<dy<<"/"<<d<<"      OR      "<<(dy/d)<<endl;		// Display Y
			for (int i=0; i<n+1; i++)			// Getting original Matrix back
			{	
				
				for (int j=1;j<n-2; j++)
				swap (constant[i][j-1],mat1[i][j]);
				
			}

			for (int i=0; i<n+1; i++)		// Creating Az Matrix
			{	
				
				for (int j=2;j<n-1; j++)
				swap (mat1[i][j],constant[i][j-2]);
				
			}
			dz=det(n+1,mat1);
			cout << endl << "Z= "<<dz<<"/"<<d<<"      OR      "<<(dz/d)<<endl;	//Dispay Z
		
			for (int i=0; i<n+1; i++)			// Getting original Matrix back
			{	
				
				for (int j=2;j<n-1; j++)
				swap (constant[i][j-2],mat1[i][j]);
				
			}

			for (int i=0; i<n+1; i++)		// Creating Ap Matrix
			{	
				
				for (int j=3;j<n; j++)
				swap (mat1[i][j],constant[i][j-3]);
				
			}
			dp=det(n+1,mat1);
			cout << endl << "P= "<<dp<<"/"<<d<<"      OR      "<<(dp/d)<<endl;	//Dispay P
			
			for (int i=0; i<n+1; i++)			// Getting original Matrix back
			{	
				
				for (int j=3;j<n; j++)
				swap (constant[i][j-3],mat1[i][j]);
				
			}

			for (int i=0; i<n+1; i++)		// Creating Aq Matrix
			{	
				
				for (int j=4;j<n+1; j++)
				swap (mat1[i][j],constant[i][j-4]);
				
			}
			dq=det(n+1,mat1);
			cout << endl << "Q= "<<dq<<"/"<<d<<"      OR      "<<(dp/d)<<endl<<endl;	//Dispay Q
			for(int i=0; i<80; i++)
				cout<<"*";
			break;
	    }	//end case 4
		default : cout << "\nINVALID ENTRY!\n\n"; 
			for(int i=0; i<80; i++)
				cout<<"*";
			break;
	}	//end switch
	cout << "\n\nDo you want to continue?          (y/n)"<<endl;
	cout<<"\nEnter your choice here:             ";
	cin >> ch;
  }
	while (ch=='y');
	cout<<"\n---------------------------------------THANK YOU!-------------------------------\n\n";
	getch();	
	return 0;
}  //end main


int det (int n,int a[row][col])
{
  int  d = 0, k, subi, subj, i, j, temp[row][col];
  if(n==2) 
  {
    d=(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
    return d;
  } 
  else 
  {
    for(k=0;k<n;k++)
	{
      subi = 0;
      subj = 0;
      for(i=1;i<n;i++)           //expanding by means of R1
	  {
        for( j=0;j<n;j++) 
		{
          if(j==k) 
		  {
            continue;
          }
          temp[subi][subj] = a[i][j];
          subj++;
          if(subj==n-1) 
		  {
            subi++;
            subj = 0;
          }
        }
      }
      d=d+(a[0][k]*pow(-1.0,k  )*det(n-1,temp));
     }
    return d;
  }
}
void swap (int& a,int& b)
{
int temp;
temp=a;
a=b;
b=temp;
}
