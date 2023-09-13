
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<iomanip>
#include<ctype.h>
#define max 50
using namespace std;

int num=0; //Number of records in the file (initially 0)

class employee
{
private:
	//Data members related to the employee records
	char name[20];
	char designation[20];
	int exp;
	int no;
	int age;
	int salary;
	char AnyLoan;
	int HRA;
	int PF;
	int tax;
	int MealAllowance;
	int TransportAllowance;
	int MedicalAllowance;
	int LoanBalance;
	int LoanDebit;
	int grosspay;
	int workingHours;
	int DA;

public:
	int id;
	//Functions related to the employee records
    void getrecords();
    void saverecords();
	bool isFilePresent();
	void insert();
    friend int cndns(employee &emp);
	void list();
	void menu();
	void deletes();
	void search();
    void editmenu();
    void editname(int);
    void editid(int);
    void editdes(int);
    void editexp(int);
    void editage(int);
    void editsalary(int);
    void edit();
    void displayPayslip();
};
employee emp[max],tempemp[max]; //Declaration of the objects emp and tempemp for class employee


class GUI {

public:
	//Functions related to the GUI
    void Cdelay(int);
	void gotoXY(int, int);
	void borderNoDelay(int, int,int, int);
	void border(int,int,int,int);
    void intro();
};


void employee::getrecords()
{
	FILE *fp;
	fp = fopen("Records.txt","r"); //Opening the file 'Records.txt' for read-only
	int c=0;
	if(fp!=NULL)
	{
		while(feof(fp)==0)
		{
			fscanf(fp,"%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&emp[c].name,&emp[c].id,&emp[c].designation,&emp[c].exp,&emp[c].age,&emp[c].salary,&emp[c].AnyLoan,&emp[c].HRA,&emp[c].PF,&emp[c].tax,&emp[c].MealAllowance,&emp[c].TransportAllowance,&emp[c].MedicalAllowance,&emp[c].LoanBalance,&emp[c].LoanDebit,&emp[c].grosspay,&emp[c].workingHours,&emp[c].DA); //Storing the record data from the file into 'fp'
			c++;
		}
		num=c;
	}
	fclose(fp); //Closing the file
}

void employee::saverecords()
{
	if(num==0)
	{
		system("del Records.txt");
	}
	else
	{
		FILE *fp;
		fp = fopen("Records.txt","w"); //Opening the file 'Records.txt' for write-only
		for(int i=0;i<num;i++)
		{
			fprintf(fp,"%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",emp[i].name,emp[i].id,emp[i].designation,emp[i].exp,emp[i].age,emp[i].salary,emp[i].AnyLoan,emp[i].HRA,emp[i].PF,emp[i].tax,emp[i].MealAllowance,emp[i].TransportAllowance,emp[i].MedicalAllowance,emp[i].LoanBalance,emp[i].LoanDebit,emp[i].grosspay,emp[i].workingHours,emp[i].DA); //Stores the newly added records in the file
		}
		fclose(fp);
	}
}

void GUI::Cdelay(int msec)
{
    long goal = msec + (clock());
    while (goal > (clock()));
}

bool employee::isFilePresent()
{
	FILE *fp; //Declaration of the file pointer
	fp = fopen("Records.txt","r"); //Opening the file
	if(fp==NULL)
		return false; //If the pointer is NULL, this means that the file is not present
	else
		return true; //If the pointer is not NULL, this means that the file is present
}

void GUI::gotoXY(int X, int Y)
{
    COORD coordinates;
    coordinates.X = X;
    coordinates.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates); //This function is used to format the cursor position into a specific location on the screen
}

void GUI::borderNoDelay(int xLenS, int yLenS, int xLenE, int yLenE)
{

    xLenS=2;
    yLenS=2;
    xLenE=76;
    yLenE=24;

	system("cls");
	gotoXY(xLenS,yLenS);printf("%c",201);

	gotoXY(xLenS,yLenE);printf("%c",200);

    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        gotoXY(i,yLenS);
        printf("%c",205);
        gotoXY(i,yLenE);
        printf("%c",205);
    }
    gotoXY(xLenE,yLenS);printf("%c",187);
    gotoXY(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {
        gotoXY(xLenS, i);
        printf("%c",186);
        gotoXY(xLenE, i);
        printf("%c",186);
    }
    printf("\n\n");
}

void GUI::border(int xLenS, int yLenS, int xLenE, int yLenE)
{
    xLenS=2;
    yLenS=2;
    xLenE=76;
    yLenE=24;

	system("cls");
	gotoXY(xLenS,yLenS);printf("%c",201);

	gotoXY(xLenS,yLenE);printf("%c",200);

    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        Cdelay(15);
        gotoXY(i,yLenS);
        printf("%c",205);
        gotoXY(i,yLenE);
        printf("%c",205);

    }
    gotoXY(xLenE,yLenS);printf("%c",187);
    gotoXY(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {
        Cdelay(15);
        gotoXY(xLenS, i);
        printf("%c",186);
        gotoXY(xLenE, i);
        printf("%c",186);
    }
    printf("\n\n");
}

void employee::insert()
{

    GUI g;
	g.borderNoDelay(2,2,76,24); //Instant border is created
	int i=num;
    int ans;
    int sal,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal,LoanDeb,h,DA;
	char loan;
	//friend int cndns(employee &emp);
	num+=1;
	// Takes input of new employee records from user
	g.gotoXY(28,4);
	printf("Insert New Record");
	g.gotoXY(10,6);
	cout<<"Name : ";
	cin>>emp[i].name;
	g.gotoXY(10,8);
	cout<<"Designation : ";
	cin>>emp[i].designation;
	g.gotoXY(10,10);
	cout<<"Years of Experience : ";
	cin>>emp[i].exp;
	g.gotoXY(10,12);
	cout<<"Age : ";
	cin>>emp[i].age;
	g.gotoXY(10,14);
	cout<<"Enter Working Hours : ";
	cin>>h;
	sal = h*300;
	emp[i].workingHours = h;
	do
	{
		g.gotoXY(10,16);
		cout<<"Any Loan (Y/N) ?: \b \b";
		loan=getche();
		if(loan=='Y'|| loan == 'y' || loan =='n' || loan == 'N')
			break;
	}while(1);
	if(loan=='y'|| loan=='Y')
	{
	g.gotoXY(10,18);
	cout<<"Enter Loan Balance : ";
	cin>>LoanBal;
	}
	else
	{
		LoanBal=0;
	}
	g.gotoXY(10,20);
	cout<<"id : ";
	cin>>emp[i].id;
    no=emp[i].id;
	//Taxes, DA, PF, HRA, HRA, LoanDeb and calculated
	TAX =  0.04 * sal;
	DA = 1.20 * sal;
	PF = 0.12 * sal;
	HRA = sal * 0.27;
	MealA = 300;
	MedicalA = 300;
	TransportA = 300;
	LoanDeb = sal * 0.09;
	if(LoanDeb > LoanBal)
	{
		LoanBal = 0;
		LoanDeb = LoanBal;
	}
	//Following calculated data are stored in the record
	emp[i].salary = sal;
	emp[i].DA = DA;
	emp[i].tax=TAX;
	emp[i].PF = PF;
	emp[i].HRA = HRA;
	emp[i].MealAllowance = MealA;
	emp[i].MedicalAllowance = MedicalA;
	emp[i].TransportAllowance = TransportA;
	emp[i].LoanBalance = LoanBal-LoanDeb;
	emp[i].AnyLoan = loan;
	emp[i].LoanDebit = LoanDeb;
	emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
	getch();
}

int cndns( employee &emp)
{
    GUI g;
    int flag=0;
    try
    {
        if(emp.no>50)
	{
		throw(emp.no);
	}
    }
    catch(int &no)
    {
        g.gotoXY(10,22);
        cout<<"Invalid Range"<<endl;
        flag=1;
    }
    if(flag==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void GUI::intro()
{
    GUI g;
	//Title of the project and group members are displayed
	g.gotoXY(27,4); printf("PAYROLL MANAGEMENT SYSTEM");
	g.gotoXY(4,10);cout << "Kamakshi Sarbhai";
	g.gotoXY(4,12);cout << "Shivam Gupta";
	g.gotoXY(4,14);cout << "Aditya Parulekar";
    g.gotoXY(27,20);printf("Press Any key to Continue...");
    getch();

}

void employee::list()
{
	GUI g;
	g.borderNoDelay(2,2,76,24);
	g.gotoXY(20,4);
	printf("       ******** List of the Employees ********");
	g.gotoXY(6,6);
	cout<<"Name\tid\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
	g.gotoXY(6,7);
	cout<<"------------------------------------------------------------------"<<endl;
	for(int i=0,j=8;i<=num-1;i++,j++) //Loop that all the records consecutively throughout the array of objects
	{
		g.gotoXY(6,j);
		cout<<emp[i].name;
		g.gotoXY(19,j);
		cout<<emp[i].id;
		g.gotoXY(26,j);
		cout<<emp[i].designation;
		g.gotoXY(47,j);
		cout<<emp[i].exp;
		g.gotoXY(58,j);
		cout<<emp[i].age;
		g.gotoXY(66,j);
		cout<<emp[i].grosspay;
	}
	getch();
}

void employee::menu()
{
    GUI g;

	g.borderNoDelay(2,2,76,24);
	g.gotoXY(16,4);
	printf("*****  Payroll Management System Project  ***** ");
	//Displays the menu of operations to choose from
	g.gotoXY(12,6);
	cout<<"Press i ----> Insert New Record.";
	g.gotoXY(12,8);
	cout<<"Press  e ----> Edit a Record.";
	g.gotoXY(12,10);
	cout<<"Press  d ----> Delete a Record.";
	g.gotoXY(12,12);
	cout<<"Press  s ----> Search a Record.";
	g.gotoXY(12,14);
	cout<<"Press  l ----> List The Employee Table.";
	g.gotoXY(12,16);
	cout<<"Press  p ----> Print Employee PaySlip.";
	g.gotoXY(12,18);
	cout<<"Press  q ----> Quit Program.";
	g.gotoXY(16,22);
	cout<<"Enter Your Option -----> ";
}

void employee::deletes()
{
    GUI g;
	for(int i=0;i<num;i++)
	{
		tempemp[i]=emp[i];
	}

	g.borderNoDelay(2,2,76,24);
	int id;
	int check=-1;
	g.gotoXY(28,4);
	printf("Delete a Record");
	g.gotoXY(10,6);
	cout<<"Enter the Jobid To Delete That Record  :";
	cin>>id;
	int i,j;
	for(i=0;i<=num-1;i++) //Loops through the whole file and checks for employee id which matches with the inputted id
	{
	 	if(emp[i].id==id)
		{
			check=i;
		}
	}
	if(check!=-1) //Deletes the target record if found, given by 'check != -1'
	{
		for(i=0,j=0;i<=num-1;i++,j++)
		{
			if(i==check)
			{
				i++;
			}
			emp[j]=tempemp[i];
		}
		num--; //Since record is deleted, value of num decreases by 1
	}
}

void employee::search()
{
    GUI g;
	g.borderNoDelay(2,2,76,24);
	int jobid;
	bool found = false; //Record is initially not found
	g.gotoXY(10,4);
	cout<<"You can Search only through the Jobid of an Employee";
	g.gotoXY(10,6);
	cout<<"Enter id Of the Employee : ";
	cin>>jobid;
	for(int i=0;i<=num-1;i++) //Loops through all the records in the file
	{
		if(emp[i].id==jobid) //If the record's employee id matches with the target id, that record is displayed
		{
			g.gotoXY(6,8);
			cout<<"Name\tid\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
			g.gotoXY(6,9);
			cout<<"------------------------------------------------------------------"<<endl;
			g.gotoXY(6,11);
			cout<<emp[i].name;
			g.gotoXY(19,11);
			cout<<emp[i].id;
			g.gotoXY(26,11);
			cout<<emp[i].designation;
			g.gotoXY(47,11);
			cout<<emp[i].exp;
			g.gotoXY(58,11);
			cout<<emp[i].age;
			g.gotoXY(66,11);
			cout<<emp[i].grosspay;
			found = true;
		}
	}
	if(!found) //Displays 'No records Found...!!!' if record with employee id equal to target id is not found
	{
		g.gotoXY(26,11);
		cout<<"No records Found...!!!\a";
	}
	getch();
}


void employee::editmenu()
{
    GUI g;
	g.borderNoDelay(2,2,76,24);
	g.gotoXY(28,4);
	cout << "Edit An Entry";
	g.gotoXY(10,6);
	//Asks which information of an employee is to be editted
	cout<<"What Do You Want To edit";
	g.gotoXY(12,8);
	cout<<"n ---------> Name ";
	g.gotoXY(12,9);
	cout<<"c ---------> id ";
	g.gotoXY(12,10);
	cout<<"d ---------> Designation";
	g.gotoXY(12,11);
	cout<<"e ---------> Experience ";
	g.gotoXY(12,12);
	cout<<"a ---------> Age";
	g.gotoXY(12,13);
	cout<<"s ---------> Salary";
	g.gotoXY(12,14);
	cout<<"q ---------> QUIT";
	g.gotoXY(10,16);
	cout<<"Enter Choice ---->>>  ";
}


//Following 6 functions are used to edit different information about the target employee record
void employee::editname(int i)
{
    GUI g;
	g.gotoXY(10,18);
	cout<<"Enter New Name----->  ";
	cin>>emp[i].name;
}

void employee::editid(int i)
{
    GUI g;
	g.gotoXY(10,18);
	cout<<"Enter New Job id----->  ";
	cin>>emp[i].id;
}
void employee::editdes(int i)
{
    GUI g;
	g.gotoXY(10,18);
	cout<<"enter new designation----->  ";
	cin>>emp[i].designation;
}

void employee::editexp(int i)
{
    GUI g;
	g.gotoXY(10,18);
	cout<<"Enter new Years of Experience";
	cin>>emp[i].exp;
}
void employee::editage(int i)
{
    GUI g;
	g.gotoXY(10,18);
	cout<<"Enter new Age ";
	cin>>emp[i].age;
}

void employee::editsalary(int i)
{
    GUI g;
	int sal,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal=emp[i].LoanBalance,LoanDeb,DA;
	char loan;
	g.gotoXY(10,18);
	cout<<"Enter new Salary ";
	cin>>sal;
	// Data related to the salary of the employee is changed according to the new salary
	DA = 1.20 * sal;
	TAX =  0.04 * sal;
	PF = 0.12 * sal;
	HRA = 4000;
	MealA = 300;
	MedicalA = 300;
	TransportA = 300;
	LoanDeb = sal * 0.09;
	if(LoanDeb > LoanBal)
	{
		LoanBal = 0;
		LoanDeb = LoanBal;
	}
	emp[i].salary = sal;
	emp[i].tax=TAX;
	emp[i].PF = PF;
	emp[i].HRA = HRA;
	emp[i].MealAllowance = MealA;
	emp[i].MedicalAllowance = MedicalA;
	emp[i].TransportAllowance = TransportA;
	emp[i].LoanBalance = LoanBal;
	emp[i].AnyLoan = loan;
	emp[i].LoanDebit = LoanDeb;
	emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
}

void employee::edit()
{
    GUI g;
	g.borderNoDelay(2,2,76,24);
	int jobid;
	g.gotoXY(28,4);
	printf("Edit a Record");
	int i;
	char option;
	g.gotoXY(10,6);
	cout<<"Enter the jobid To Edit : ";
	cin>>jobid;
	editmenu();
	// Loops through all the employee records and searches for a record with employee id equal to the target id
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].id==jobid) //Once target id is found, the edit options are displayed for that record and receives input according to the information to be editted. This is looped until user decides to exit
		{
			while((option=cin.get())!='q')
			{
				switch(option)
				{
					case 'n':
						editname(i);
						break;
					case 'c':
						editid(i);
						break;
					case 'd':
						editdes(i);
						break;
					case 'e':
						editexp(i);
						break;
					case 'a':
						editage(i);
						break;
					case 's':
						editsalary(i);
						break;
				}
   				editmenu();
			}
		}
	}
}


void employee::displayPayslip()
{
    GUI g;
	system("cls");
	g.borderNoDelay(2,2,76,24);
	g.gotoXY(10,4);
	int id,i;
	cout<<"Enter Employee Job id :";
	cin>>id;
	for(i=0;i<=num-1;i++) //Loops through all the records in the file
	{
		if(emp[i].id==id) //Once target id is found, the following data is displayed according to that employee's payslip
		{
			g.gotoXY(12,6);
			cout<<"Name : "<<emp[i].name;
			g.gotoXY(45,6);
			cout<<"Working Hours : "<<emp[i].workingHours<<" Hrs";
			g.gotoXY(6,8);
			cout<<"Earnings :-";
			g.gotoXY(8,10);
			cout<<"Basic Pay : "<<emp[i].salary<<endl;
			g.gotoXY(8,12);
			cout<<"HRA(27% of Basic): "<<emp[i].HRA<<endl;
			g.gotoXY(8,14);
			cout<<"DA (120% of Basic):"<<emp[i].DA;
			g.gotoXY(8,16);
			cout<<"Meal Allowance : "<<emp[i].MealAllowance<<endl;
			g.gotoXY(8,18);
			cout<<"Medical Alowance : "<<emp[i].MedicalAllowance<<endl;
			g.gotoXY(8,20);
			cout<<"Transport Allowance : "<<emp[i].TransportAllowance<<endl;
			g.gotoXY(40,8);
			cout<<"Deductions :- "<<endl<<endl;
			g.gotoXY(42,10);
			cout<<"PF : "<<emp[i].PF<<endl;
			g.gotoXY(42,12);
			cout<<"Tax : "<<emp[i].tax<<endl;
			g.gotoXY(42,14);
			int l = emp[i].AnyLoan;
			char l2 = toupper(l);
			cout<<"Loan Status : "<<l2<<endl;
			g.gotoXY(42,16);
			cout<<"Loan Debit This Month : "<<emp[i].LoanDebit<<endl;
			g.gotoXY(42,18);
			cout<<"Loan Balance : "<<emp[i].LoanBalance<<endl;
			g.gotoXY(32,22);
			cout<<"Total Gross Pay : "<<emp[i].grosspay;
		}
	}
	getch();
}





int main()
{
	employee emp;
	GUI g;
    int ans;
	g.border(2,2,76,24);
	g.intro(); //Starting screen is displayed
    emp.menu(); //Menu is displayed
    emp.getrecords(); //Records are fetched
    char option;
    if(emp.id==0 && emp.isFilePresent())
    	num--;
	// Menu with all operations that can be performed is displayed. User may input which operation to perform and the respective operation is performed
	while(1)
	{
		option=getch();
		switch(option)
		{
			case 'l':
				emp.list();
				break;
			case 'i':
				emp.insert();
				ans=cndns(emp);
				if(ans==0)
                {
                    exit(0);
                }
                else
                {
                    g.gotoXY(10,22);
                    cout << "Recorded";
                }
				break;
			case 'd':
				emp.deletes();
				break;
			case 'e':
				emp.edit();
				break;
			case 's':
				emp.search();
				break;
			case 'p':
				emp.displayPayslip();
				break;
			case 'q':
				emp.saverecords();
				exit(0);
		}
		emp.menu();
	}
	return 0;
}
