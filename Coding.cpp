
/*	Include Libraries	*/

#include <iostream>		//	For input and output functions
#include <string>		//	To allow of the string using
#include <windows.h>	//	For the wait functions
#include <time.h>		//	Get the current date and time
using namespace std;

/*	User/Teachers or Admin Structure	*/

struct users
{
	int arraycount;		//	It's only for value 1 because need the calculation of the total arrays which contain records 
	int userid;			//	User's ID unique
	string username;	//	Username for enter the system
	string password;	//	Password of the system
	string position;	//	1st Login users position might be a teacher
}usersarray[5];			//	Users array has maximum  users


/*	Courses/Programs Structure	*/

struct courses
{
	int course_no;			//	It's only for value 1 because need the calculation of the total arrays which contain records 
	string course_id;		//	Course ID unique
	string course_name;		//	Course or Program Name
	string course_desc;		//	Course or Program Description
	string course_date;		//	This is the date when the course start
	string course_duration;	//	Course duration
	char special_offer;		//	This is the char calue that 'Y' or 'N' if the program is in the special offer category
	string offer_desc;		//	If special offer 'Y' then what is the offer description such discount or add more module into the program
}coursesarray[10];			//	Maximum arrays 10 programs only if you want can change


struct programs
{
	int program_no;			//	It's only for value 1 because need the calculation of the total arrays which contain records 
	string program_id;		//	Course ID unique
	string program_name;	//	Course or Program Name
	string program_desc;	//	Course or Program Description
	string program_date;	//	This is the date when the course start
	string program_duration;		//	Course duration
	string program_special_offer;	//	This is the char calue that 'Y' or 'N' if the program is in the special offer category
	string program_offer_desc;		//	If special offer 'Y' then what is the offer description such discount or add more module into the program
}programsarray[10];		

/*	Students Structure	*/

struct students
{
	int student_no;			//	It's only for value 1 because need the calculation of the total arrays which contain records 
	string student_id;		//	Unique student ID
	int username;			//	This is the username for the students to enter the system
	string student_password;//	This is the password to enter the system
	string student_name;	//	Student name
	int student_age;		//	Student age
	string student_city;	//	Student city
	string student_program;	//	This variable used for enter the course id which is followed by the student but make sure same course id
}studentsarray[10];			//	Students array is able to store only 10 students records and we can adjust it if want


/*	Functions Declaration	*/

void pause();			//	This function is used instead system pause command
void wait(int second);	//	To use for delay a certain period
void cls();				//	To clear screen
void userslist();		//	This contain the list of users that who able to login the system
void loginmenu();		//	Validate the login username and password whether accurate or specious
void loginform();				//	Handle the login form for allow the users to login the system
void print(string print);		//	This fuction that is used for print any string or integer values in same line but it makes easy to print anything than the default way of cout << but not for integer values
void printl(string printl);		//	The fuction help us to print values in a new line but not for integer values
void exitrequest();				//	This is the function that helps the user to jump out from the system
void times();					//	To show the current time 
void dates();					//	To show the current date 
void teachermenu(string teachername);	//	This is the teacher menu and teacher name from the array
void studentmenu(string studentname);	//	This is the student menu and student name from the array
void loadingmenu();						//	Loading menu for the welcome
int totalprograms();					//	It's a functing to take counting value of the total courses from the array 
void search_programs(string search_text);	//	Course search and search keyword
int totalstudents();						//	It's a functing to take counting value of the total students from the array 
void search_students(string search_text);	//	Student search and search keyword
void samplecourse();	//	Sample Courses Information for first Use
void samplestudent();	//	Sample Courses Information for first Use
void helpmenu(); // help menu



/*	Global Variable Declaration	*/

int typeuserid;			//	This is the variable which is used by users to type their user id
string typepassword;	//	The same concept is used for the password as above
bool quit = false;		//	For the exit request
int user_arrayno;		//	This is the array no of the current user
int arraytotal_course;	//	This variable contains the total arrays filled on the courses for example how many courses we have ?
int arraytotal_students;//	This variable contains the total arrays filled on the students for example how many students now we have ?
int arraytotal_programs;


/*	Main Function	*/

void main()
{	// Start Main

	userslist();			//	Users name and password declaration of the first user or teacher from the function (modularise)
	system("color 1F");		//	Color design
	samplecourse();
	samplestudent();

	while (quit == false)	// While loop is running if the exit status equal to false
	{
		cls();				//	Clear screen 
		loadingmenu();		//	Welcome screen
		loginmenu();		//	Entered username and password is being tested by the login menu funtion whether correct or wrong and send the user to the appropriate department
		exitrequest();		//	Last exit request 
	}
	exit(0);				// If the user jump out from the while loop then he wants to exit

}	// End Main



/*	Functions	*/

/*	Login Menu Functions	*/

void loginmenu()
{
	bool found = false;	//	This is the boolean variable to indentity whether users found or not 
	int count = 1;		//	Login attempt count

	while(count <= 3)	//	If the tried attempt is less than 3 times start loop
	{ // Start while loop 1

	loginform();		//	Login form to allow the user to enter the username and password
	
	for (int i = 0; i < 100; i++)	//	This is the loop for get the infromation from the array maximum looping 100 times
	{ // Start for loop 2
		
		/* This is the teacher finding array */
		if (typeuserid == usersarray[i].userid && typepassword == usersarray[i].password)	//	If password and username matched
		{
			found = true;			// If found the user then found is true
			user_arrayno = i;		// Get the user's array no to call him in the future

			string teachername = usersarray[i].username;	//	Get teacher's name
			teachermenu(teachername);						//	Call the teacher menu
			
			pause();										//	Pause
			break;											//	Break the loop if found user
		}
		/* This is the student finding array */
		else if (typeuserid == studentsarray[i].username && typepassword == studentsarray[i].student_password)
		{
			found = true;		// If found the user then found is true
			user_arrayno = i;	// Get the user's array no to call him in the future

			string studentname = studentsarray[i].student_name;	//	Get student's name
			studentmenu(studentname);							//	Call the student menu
			
			pause();										//	Pause
			break;											//	Break the loop if found user
		}

	} // End for loop 2

	/*	If the user is still not found then found is false and call the alert menu	*/
	if (found == false)
	{ // Start if 3
		cls();
		printl("");
		printl("");
		printl("\t|-----------------------------------------------------------|");
		print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
		printl("\t|-----------------------------------------------------------|");
		printl("\t|                                                           |");
		printl("\t|                                                           |");
		printl("\t|                        Wrong !                            |");
		printl("\t|                     ------------                          |");
		printl("\t|                                                           |");
		printl("\t|	    You have entered wrong username or password     |");
		printl("\t|              please check and retry !                     |");
		printl("\t|                                                           |");
		printl("\t|                                                           |");
		printl("\t|                   Check carefully                         |");
		printl("\t|    before trying again. You have only 3 attempts          |");
		cout <<"\t|              You have tried   " << count << " attempt                   |" << endl;
		printl("\t|                                                           |");
		printl("\t|                                                           |");
		printl("\t|-----------------------------------------------------------|");
		pause ();
	} // End if 3

	count++;	//	Each tried time the count is increasing

	} // End while loop 1

	/*	When the count is eaqual to 4 times, Alert the user with 10 seconds waiting caution	*/
	if (count == 4)
	{ // Start if 4

		cls();
		printl("");
		printl("");
		printl("\t|-----------------------------------------------------------|");
		print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
		printl("\t|-----------------------------------------------------------|");
		printl("\t|                                                           |");
		printl("\t|                                                           |");
		printl("\t|                       Caution !                           |");
		printl("\t|                     ------------                          |");
		printl("\t|                                                           |");
		printl("\t|	    Your account has been blocked due               |");
		printl("\t|              so many failed attempts !                    |");
		printl("\t|                                                           |");
		printl("\t|                                                           |");
		printl("\t|            You need to wait for 10 seconds                |");
		printl("\t|                  before trying again                      |");
		printl("\t|                                                           |");
		printl("\t|                                                           |");
		printl("\t|                                                           |");
		printl("\t|-----------------------------------------------------------|");
		print ("\t\t\t* * * * * * * * * * *");
		printl ("");
		print ("\t\t\t");

			/*	This is the loding menu while the user waiting	*/
			for (int x = 1; x <= 10; x++ )
			{
				wait(1); print ("* ");
			}

		/*	Exit Request for the invalid user	*/
		printl ("");
		printl ("");
		print ("\t Do you want to exit ? 'Y' or 'N' ");
		char ex;
		cin >> ex;
		if ( ex == 'Y' || ex == 'y' )
		{
			exit(0);
		}
		main();	//	After 10 seconds call main menu again if the user does not type y

	} // End if 4
}


/*	Users details Function	*/

/*	Insert the first username and password into the array of teacher or management	*/
void userslist()
{
	usersarray[0].arraycount = 1;	//	Array count is always 1 to calculate the arrays quantity as earlier I explained
	usersarray[0].userid = 100;
	usersarray[0].username = "Aslam";
	usersarray[0].password = "100";
	usersarray[0].position = "Teacher";
}

/*	Sample Courses Information for first Use	*/
void samplecourse()
{
	totalprograms();
	for (int k = arraytotal_programs; k < 1 + arraytotal_programs; k++ )
	{
	programsarray[k].program_no = 1;			//	It's only for value 1 because need the calculation of the total arrays which contain records 
	programsarray[k].program_id = "A01";		//	Course ID unique
	programsarray[k].program_name = "Sample Course";		//	Course or Program Name
	programsarray[k].program_desc = "Diploma";		//	Course or Program Description
	programsarray[k].program_date = "2016/11/20";		//	This is the date when the course start
	programsarray[k].program_duration = "1 Month";	//	Course duration
	programsarray[k].program_special_offer = "Y";		//	This is the char calue that 'Y' or 'N' if the program is in the special offer category
	programsarray[k].program_offer_desc = "10 % Discount";	
	}
	
}

/*	Sample Student Information for first Use	*/
void samplestudent()
{
	totalstudents();
	for (int k = arraytotal_students; k < 1 + arraytotal_students; k++ )
	{
	studentsarray[k].student_no = 1;					//	It's only for value 1 because need the calculation of the total arrays which contain records 
	studentsarray[k].student_id = "ITST25";				//	Unique student ID
	studentsarray[k].username = 123;					//	This is the username for the students to enter the system
	studentsarray[k].student_password = "123";				//	This is the password to enter the system
	studentsarray[k].student_name = "A.Sample";				//	Student name
	studentsarray[k].student_age = 15;							//	Student age
	studentsarray[k].student_city = "Dehiwala, Colombo";		//	Student city
	studentsarray[k].student_program = "A01";					//	Program Number from the program list
	}

	
}


/*	Pause Function	*/

void pause()
{
	system("pause>null");
}

/*	Wait Function and seconds	*/

void wait(int second)
{
	Sleep(second*1000);
}

/*	Clear screen Function	*/

void cls()
{
	system("cls");
}

/*	Loginmenu Function	*/

void loginform()
{
	cls();
	printl("");
	printl("");
	printl("\t|-----------------------------------------------------------|");
	print ("\t| Welcome To                    		  ");dates(); printl(" |");
	printl("\t|-----------------------------------------------------------|");
	printl("\t|                                                           |");
	printl("\t|               ---------   -------------                   |");
	printl("\t|                   |             |                         |");
	printl("\t|                   |             |                         |");
	printl("\t|                   |             |                         |");
	printl("\t|                   |             |                         |");
	printl("\t|                   |             |                         |");
	printl("\t|   WORLD   OF      |             |     INSTITUTE           |");
	printl("\t|                   |             |                         |");
	printl("\t|                   |             |                         |");
	printl("\t|                   |             |                         |");
	printl("\t|                   |             |                         |");
	printl("\t|               ---------         |                         |");
	printl("\t|                                                           |");
	printl("\t|-----------------------------------------------------------|");
	printl("");
	print ("\tEnter User ID ->\t");
	cin >> typeuserid;				//	Type Username 
	print ("\tPassword ->\t\t");
	cin >> typepassword;			//	Type Password
}

/*	Print Function	*/

void print(string print)
{
		cout << print;
}

/*	Print new line Function	*/

void printl(string printl)
{
	cout << printl << endl;
}

/*	Exit request Function	*/

void exitrequest()
{
	char exitrequest;

		cls();
		printl("");
		printl("");
		printl("\t|-----------------------------------------------------------|");
		print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
		printl("\t|-----------------------------------------------------------|");
		printl("\t|                                                           |");
		printl("\t|                                                           |");
		printl("\t|                         Exit !                            |");
		printl("\t|                     ------------                          |");
		printl("\t|                                                           |");
		printl("\t|	   Do you want to exit the system or logout         |");
		printl("\t|              type 'Y' or somethingelse for exit           |");
		printl("\t|              type 'N' for continue                        |");
		printl("\t|              type 'L' for logout                          |");
		printl("\t|                                                           |");
		printl("\t|                                                           |");
		printl("\t|                                                           |");
		printl("\t|                                                           |");
		printl("\t|                                                           |");
		printl("\t|-----------------------------------------------------------|");
		printl("\t| Enter your choise here -->\t\t\t            |");
		printl("\t|-----------------------------------------------------------|");
		printl("");
		print ("\tType here -> "); cin >> exitrequest;

		/*	If exit request equal to Y, system will exit after 5 seconds	*/
		if (exitrequest == 'y' || exitrequest == 'Y' )
		{ // Start if 5

			quit = true;	// if quit equal to true the mainmenu is alerted to exit

			cls();
			printl("");
			printl("");
			printl("\t|-----------------------------------------------------------|");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|                          Bye !                            |");
			printl("\t|                      ------------                         |");
			printl("\t|                                                           |");
			print ("\t|	               Dear,");
			if (usersarray[user_arrayno].userid == typeuserid)
			{
				print (usersarray[user_arrayno].username);
			}
			else if ( studentsarray[user_arrayno].username == typeuserid )
			{
				print (studentsarray[user_arrayno].student_name);
			}
			printl ("	                    |");
			printl("\t|              Thank you and have a nice day :)             |");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|       The system will be closed within 5 seconds          |");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|-----------------------------------------------------------|");
			print ("\t\t\t* * * * * * ");
			printl ("");
			print ("\t\t\t");
				for (int x = 1; x <= 5; x++ )
				{
					wait(1); print ("* ");
				}
			exit(0);
		} 
		/*	If exit request equal to L, system will Logout after 5 seconds	*/
		else if (exitrequest == 'l' || exitrequest == 'L')
		{

			cls();
			printl("");
			printl("");
			printl("\t|-----------------------------------------------------------|");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|                          Bye !                            |");
			printl("\t|                      ------------                         |");
			printl("\t|                                                           |");
			print ("\t|	               Dear,");
			if (usersarray[user_arrayno].userid == typeuserid)
			{
				print (usersarray[user_arrayno].username);
			}
			else if ( studentsarray[user_arrayno].username == typeuserid )
			{
				print (studentsarray[user_arrayno].student_name);
			}
			printl ("	                    |");
			printl("\t|              Thank you and have a nice day :)             |");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|       The system will be log out within 5 seconds         |");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|-----------------------------------------------------------|");
			print ("\t\t\t* * * * * * ");
			printl ("");
			print ("\t\t\t");
				for (int x = 1; x <= 5; x++ )
				{
					wait(1); print ("* ");
				}

			loginmenu();	//	Once logout the system will call the login menu again
		}
		/*	If exit request equal to N, system will restart after 5 seconds	*/
		else if (exitrequest == 'n' || exitrequest == 'N') 
		{
			quit = false;	//	Quit equal to flase so the system will not be considered to exit

			cls();
			printl("");
			printl("");
			printl("\t|-----------------------------------------------------------|");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|                          Bye !                            |");
			printl("\t|                      ------------                         |");
			printl("\t|                                                           |");
			print ("\t|	               Dear,");
			if (usersarray[user_arrayno].userid == typeuserid)
			{
				print (usersarray[user_arrayno].username);
			}
			else if ( studentsarray[user_arrayno].username == typeuserid )
			{
				print (studentsarray[user_arrayno].student_name);
			}
			printl ("	                |");
			printl("\t|	                                                          |");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|       The system will restart within 5 seconds            |");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|                                                           |");
			printl("\t|-----------------------------------------------------------|");
			print ("\t\t\t* * * * * * ");
			printl ("");
			print ("\t\t\t");
				for (int x = 1; x <= 5; x++ )
				{
					wait(1); print ("* ");
				}

			/*	Once the system is restarted this function is transfer the user to the appropriate department	*/
			if ( usersarray[user_arrayno].userid == typeuserid )
			{
				string teachername = usersarray[user_arrayno].username;
				teachermenu(teachername);
			}
			else if ( studentsarray[user_arrayno].username == typeuserid )
			{
				string studentname = studentsarray[user_arrayno].student_name;
				studentmenu(studentname);
			}	
	} // End if 5
	
}

/*	Time Function	*/

void times()
{
time_t now = time(0);	
char* nowtime = ctime(&now);
tm *ltm = localtime(&now);
cout << 1 + ltm->tm_hour;
cout << ":";
cout << 1 + ltm->tm_min;
}

/*	Date Function	*/

void dates()
{
time_t nows = time(0);	
char* nowtimes = ctime(&nows);
tm *ltms = localtime(&nows);
cout << 1900 + ltms->tm_year;
cout << ".";
cout << 1 + ltms->tm_mon;
cout << ".";
cout << 1 + ltms->tm_mday;
}

/*	Teacher Menu Function	*/

void teachermenu(string teachername)
{
	int option;							//	Option on the menu
	string search_s;					//	Search Courses variable
	string search_st;					//	Search Students variable
	string edit_st;						//	Edit Student ID variable
	bool certificate_found = false;		//	Boolean for the certificate found status
	bool special_found = false;			//	Boolean for the special offers found status
	bool st = false;					//	Student Information Found 

	cls();
	printl("");
	printl("");
	printl("\t|-----------------------------------------------------------|");
	print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
	print ("\t| Teacher : ");
	print (teachername) ;
	print ("			              ");
	times(); 
	printl(" |");
	printl("\t|-----------------------------------------------------------|");
	printl("\t|                                                           |");
	printl("\t|\t1. Special Offers\t\t\t\t    |");
	printl("\t|                                                           |");
	printl("\t|\t2. Certificate Programs\t\t\t\t    |");
	printl("\t|                                                           |");
	printl("\t|\t3. Search Programs\t\t\t\t    |");
	printl("\t|                                                           |");
	printl("\t|\t4. Add Programs\t\t\t\t\t    |");
	printl("\t|                                                           |");
	printl("\t|\t5. Students Information\t\t\t\t    |");
	printl("\t|                                                           |");
	printl("\t|\t6. Manage Students\t\t\t\t    |");
	printl("\t|                                                           |");
	printl("\t|\t7. Exit\t\t\t\t\t\t    |");
	printl("\t|                                                           |");
	printl("\t|-----------------------------------------------------------|");
	printl("\t| Enter your choise here 1 to 7 or 99 for Help -->          |");
	printl("\t|-----------------------------------------------------------|");
	printl("");
	print ("\tType here -> "); cin >> option;
	

	switch (option)
	{
	case 1: 
			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Teacher : ");
			print (teachername) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Special Offers                                     |");
			printl("\t+-----------------------------------------------------------+");
			printl("");

			totalprograms();	//	Get the total arrays count that have already filled
			

			/*	Show Special Offers	*/
			for (int t = 0; t < arraytotal_programs; t++ )
			{ 
				/*	Show Special Offers if the programs contain 'Y' on its special offer variable	*/
				if ( programsarray[t].program_special_offer == "Y" || programsarray[t].program_special_offer == "y"  )
				{
				printl ("\t ID \t\t:\t " + programsarray[t].program_id);
				printl ("\t Name \t\t:\t " + programsarray[t].program_name);
				printl ("\t Desctiption \t:\t " + programsarray[t].program_desc);
				printl ("\t Duration \t:\t " + programsarray[t].program_desc);
				printl ("\t Date \t\t:\t " + programsarray[t].program_date);
				printl ("\t Offer Desc \t:\t " + programsarray[t].program_offer_desc);
				printl ("");
				printl("\t+-----------------------------------------------------------+");
				special_found = true;	//	If found, it's true
				}
			}

			/*	If not found any programs give message to the user	*/
			if (special_found == false)
			{
				printl ("\t No programs registered yet");
				printl ("");
				printl("\t+-----------------------------------------------------------+");
				printl ("");
			}

			/*	If the process completed then go to main menu	*/
			printl ("\tType any key to go main menu");
			pause();
			cls();
			teachermenu(teachername);

		break;
	case 2: 
			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Teacher : ");
			print (teachername) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Certificate Programs                               |");
			printl("\t+-----------------------------------------------------------+");
			printl("");

			totalprograms();//	Get the total arrays count that have already filled
			


			/*	Show Certificate Programs 	*/
			for (int t = 0; t < arraytotal_programs; t++ )
			{
				printl ("\t ID \t\t:\t " + programsarray[t].program_id);
				printl ("\t Name \t\t:\t " + programsarray[t].program_name);
				printl ("\t Desctiption \t:\t " + programsarray[t].program_desc);
				printl ("\t Duration \t:\t " + programsarray[t].program_desc);
				printl ("\t Date \t\t:\t " + programsarray[t].program_date);
				if ( programsarray[t].program_special_offer == "Y" || programsarray[t].program_special_offer == "y" )
				{
					printl ("\t Offer Desc \t:\t " + programsarray[t].program_offer_desc);
				}
				else
				{
					printl ("\t Offer Desc \t:\t Offer is not available");
				}
				printl ("");
				printl("\t+-----------------------------------------------------------+");
				certificate_found = true;	//	If found, it's true
			}

			/*	If not found any programs give message to the user	*/
			if (certificate_found == false)
			{
				printl ("\t No programs registered yet ");
				printl ("");
				printl("\t+-----------------------------------------------------------+");
				printl ("");
			}

			/*	If the process completed then go to main menu	*/
			printl ("\tType any key to go main menu");
			pause();
			cls();
			teachermenu(teachername);

		break;
	case 3:
			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Teacher : ");
			print (teachername) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Search Program                                     |");
			printl("\t+-----------------------------------------------------------+");
			printl("\t|                                                           |");
			printl("\t|    * Type Course ID or Name or Offer ?                    |");
			printl("\t|                                                           |");
			printl("\t+-----------------------------------------------------------+");
			print ("\t Enter here \t\t-->\t "); 

			cin >> search_s;	//	Type the program ID or Name for search 
			printl("\t-------------------------------------------------------------");
			
			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Teacher : ");
			print (teachername) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Search Program                                     |");
			printl("\t+-----------------------------------------------------------+");
			printl("");
			printl ("\t Results for your search keyword : "+ search_s);
			printl ("");
	
			totalprograms();

			/*	Search Course Function wants to run here	*/
			search_programs(search_s);

			/*	If the process completed then go to main menu	*/
			printl ("\tType any key to go main menu");
			pause();
			cls();
			teachermenu(teachername);
			
		break;
	case 4:
			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Teacher : ");
			print (teachername) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Add Programs                                       |");
			printl("\t+-----------------------------------------------------------+");
			printl("\t|                                                           |");
			printl("\t|    * How many programs you want to add ?                  |");
			printl("\t|                                                           |");
			printl("\t+-----------------------------------------------------------+");
			print ("\t Enter here \t\t-->\t "); 
			int h_programs;			//	Variable to type that how many program you want to add a time
			cin >> h_programs;
			printl("\t-------------------------------------------------------------");
	
			totalprograms();

			/*	Add Programs	
			int k = total arrays filled earlier; k < how much you want to add now + total arrays
			*/
			for (int k = arraytotal_programs ; k < h_programs + arraytotal_programs; k++ )
			{

				programsarray[k].program_no = 1;	//	No is always 1 to calculate array total

				print ("\t Course ID \t\t-->\t ");
				cin >> 	programsarray[k].program_id;
				printl (" ");

				print ("\t Course Name \t\t-->\t ");
				cin >> 	programsarray[k].program_name;
				printl (" ");

				print ("\t Course Description \t-->\t ");
				cin >> 	programsarray[k].program_desc;
				printl (" ");
	
				print ("\t Course Duration \t-->\t ");
				cin >> 	programsarray[k].program_duration;
				printl (" ");

				printl ("\t Special Offer ");
				print  ("\t 'Y' or 'N' \t\t-->\t ");
				cin >> 	programsarray[k].program_special_offer;
				printl (" ");

				/*	If the user type 'y' above the he wants to describe about course offer 	*/
				if ( programsarray[k].program_special_offer == "y" || programsarray[k].program_special_offer == "Y" )
				{
					print ("\t Offer Details \t\t-->\t ");
					cin >> 	programsarray[k].program_offer_desc;
					printl (" ");
				}

				printl ("\t Course Date ");
				print  ("\t YYYY/MM/DD \t\t-->\t ");
				cin >> 	programsarray[k].program_date;
				printl (" ");
				printl("\t-------------------------------------------------------------");
				printl (" ");

			}

			/*	Success Alert	*/
			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Teacher : ");
			print (teachername) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Add Programs                                       |");
			printl("\t+-----------------------------------------------------------+");
			printl("\t|                                                           |");
			printl("\t| * You have successfully updated press any key to go menu  |");
			printl("\t|                                                           |");
			printl("\t+-----------------------------------------------------------+");
			pause();
			cls();

			/*	Call menu again	*/
			teachermenu(teachername);

		break;
	case 5:
		
			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Teacher : ");
			print (teachername) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Student Informations                               |");
			printl("\t+-----------------------------------------------------------+");
			printl("");

			/*	Show total students information that you entered	*/
			totalstudents();

			for (int t = 1; t < arraytotal_students; t++ )
			{
				printl ("\t ID \t\t:\t " + studentsarray[t].student_id);
				printl ("\t Name \t\t:\t " + studentsarray[t].student_name);
				cout << "\t Age    \t:\t " << studentsarray[t].student_age << endl;
				printl ("\t City    \t:\t " + studentsarray[t].student_city);
				printl ("\t Program \t:\t " + studentsarray[t].student_program);
				cout << "\t Username \t:\t " << studentsarray[t].username << endl;
				printl ("\t Password  \t:\t " + studentsarray[t].student_password);
				printl ("");
				printl("\t+-----------------------------------------------------------+");
				st = true;
			}

			if (st == false)
			{
				printl ("\t No students registered yet");
				printl ("");
				printl("\t+-----------------------------------------------------------+");
				printl ("");
			}

			/*	If the process completed then go to main menu	*/
			printl ("\tType any key to go main menu");
			pause();
			cls();
			teachermenu(teachername);

		break;
	case 6:

			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Teacher : ");
			print (teachername) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Manage Students                                    |");
			printl("\t+-----------------------------------------------------------+");
			printl("\t|                                                           |");
			printl("\t|\t1. Add Student                                      |");
			printl("\t|                                                           |");
			printl("\t|\t2. Edit Student's Information                       |");
			printl("\t|                                                           |");
			printl("\t|\t3. Search Students                                  |");
			printl("\t|                                                           |");
			printl("\t|\t4. Exit                                             |");
			printl("\t|                                                           |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Enter your choise here 1 to 4 -->\t\t\t    |");
			printl("\t|-----------------------------------------------------------|");
			printl("");
			int option_manage_student;	//	Internal option for student menu
			print ("\tType here -> "); cin >> option_manage_student;
			
			if ( option_manage_student == 1 )
			{
				/*	Here I used the same concept that which is used for add programs	*/
				cls();
				printl("");
				printl("");
				printl("\t+-----------------------------------------------------------+");
				print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
				print ("\t| Teacher : ");
				print (teachername) ;
				print ("			              ");
				times(); 
				printl(" |");
				printl("\t|-----------------------------------------------------------|");
				printl("\t| Menu > Manage Students > Add Student                      |");
				printl("\t+-----------------------------------------------------------+");
				printl("\t|                                                           |");
				printl("\t|    * How many students you want to add ?                  |");
				printl("\t|                                                           |");
				printl("\t+-----------------------------------------------------------+");
				print ("\t Enter here \t\t-->\t "); 
				int h_students;
				cin >> h_students;
				printl("\t-------------------------------------------------------------");
				totalstudents();

				for (int k = arraytotal_students ; k < h_students + arraytotal_students; k++ )
				{

					studentsarray[k].student_no = 1;

					print ("\t  Student ID \t\t-->\t ");
					cin >> 	studentsarray[k].student_id;
					printl (" ");

					print ("\t  Student Name \t\t-->\t ");
					cin >> 	studentsarray[k].student_name;
					printl (" ");

					print ("\t  Student Age \t\t-->\t ");
					cin >> 	studentsarray[k].student_age;
					printl (" ");

					print ("\t  Student City \t\t-->\t ");
					cin >> 	studentsarray[k].student_city;
					printl (" ");

					//	Check if the program not found in our program list 
					int l = 0;
					while (l < 3 )
					{
						printl("");
						print ("\t  Student Program \t-->\t ");
						cin >> studentsarray[k].student_program;

						totalprograms();
						for (int y = 0; y < arraytotal_programs; y++)
						{
							if (studentsarray[k].student_program == programsarray[y].program_id)
							{
								l = 5;
								break;
							}

						}
						if ( l == 5)
						{
							break;
						}
						printl("");
						printl ("\t -----------------------------------------------------------");
						printl ("\t This course is not exist in our system please type again !!! ");
						cout << "\t You have only " << 3-l << " chanses !!! " << endl;
						totalprograms();
						printl ("\t -----------------------------------------------------------");
						printl ("\t These courses only exist in our system ");
						printl ("\t -----------------------------------------------------------");
						for (int j = 0; j < arraytotal_programs; j++)
						{
							cout << "\t Course ID   : " << programsarray[j].program_id << endl;
							cout << "\t Course Name : " << programsarray[j].program_name << endl;
							cout << endl;
						}
						printl ("\t -----------------------------------------------------------");
						if (l == 2)
						{
							printl ("\t  We have made your course id but still");
							printl ("\t  it's not available until you add from programs menu ");
							printl ("\t -----------------------------------------------------------");
						}
						l++;	
					}
					printl (" ");

					print ("\t  Student Username \t-->\t ");
					cin >> 	studentsarray[k].username;
					printl (" ");

					print ("\t  Student Password \t-->\t ");
					cin >> 	studentsarray[k].student_password;
					printl (" ");

					printl("\t-------------------------------------------------------------");
					printl (" ");

				}
				/*	Success Alert	*/
				cls();
				printl("");
				printl("");
				printl("\t+-----------------------------------------------------------+");
				print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
				print ("\t| Teacher : ");
				print (teachername) ;
				print ("			              ");
				times(); 
				printl(" |");
				printl("\t|-----------------------------------------------------------|");
				printl("\t| Menu > Manage Students > Add Student                      |");
				printl("\t+-----------------------------------------------------------+");
				printl("\t|                                                           |");
				printl("\t| * You have successfully updated press any key to go menu  |");
				printl("\t|                                                           |");
				printl("\t+-----------------------------------------------------------+");
				pause();
				cls();
				/*	Call menu again	*/
				teachermenu(teachername);
			}
			else if ( option_manage_student == 2 )
			{
				cls();
				printl("");
				printl("");
				printl("\t+-----------------------------------------------------------+");
				print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
				print ("\t| Teacher : ");
				print (teachername) ;
				print ("			              ");
				times(); 
				printl(" |");
				printl("\t|-----------------------------------------------------------|");
				printl("\t| Menu > Manage Students > Edit Student's Information       |");
				printl("\t+-----------------------------------------------------------+");
				printl("\t|                                                           |");
				printl("\t|    * Type Student ID and Edit or type 'no' for default    |");
				printl("\t|                                                           |");
				printl("\t+-----------------------------------------------------------+");
				print ("\t Enter here \t\t-->\t "); 

				cin >> edit_st;	//	Student ID that where you want to edit
				printl ("\t-------------------------------------------------------------");
				printl ("");
				totalstudents();
				bool found = false;

				/*	Edit Menu, If you don't want to edit some details then just type 'no' for string and '0' for integer values 	*/
				for (int t = 0; t < arraytotal_students; t++ )
				{
					if ( studentsarray[t].student_id == edit_st ) 
					{
						printl ("\t Name       : " + studentsarray[t].student_name );	//	Old Name
						print  ("\t Edit Name  : " );
						string name;
						cin >> name;													//	Enter the new name
						if ( name == "no" )												//	If name equal to no, don't edit
						{
							name = studentsarray[t].student_name;
						}
						studentsarray[t].student_name = name;							//	Change name
						printl ("\t-------------------------------------------------------------");

						cout << "\t Age        : " << studentsarray[t].student_age  << endl;
						printl  ("\t Edit Age" );
						print  ("\t Type '0' for default : " );
						int age;
						cin >> age;
						if ( age == 0 )
						{
							age = studentsarray[t].student_age;
						}
						studentsarray[t].student_age = age;
						printl ("\t-------------------------------------------------------------");

						printl ("\t City       : " + studentsarray[t].student_city );
						print  ("\t Edit City  : " );
						string city;
						cin >> city;
						if ( city == "no" )
						{
							city = studentsarray[t].student_city;
						}
						studentsarray[t].student_city = city;
						printl ("\t-------------------------------------------------------------");

					//	Check if the program not found in our program list 
					int n = 0;
					while (n < 3 )
					{
						printl ("");
						printl ("\t Program       : " + studentsarray[t].student_program );
						print  ("\t Edit Program  : " );
						string program;
						cin >> program;
						if ( program == "no" )
						{
							program = studentsarray[t].student_program;
						}
						studentsarray[t].student_program = program;
						printl ("\t-------------------------------------------------------------");

						totalprograms();
						for (int y = 0; y < arraytotal_programs; y++)
						{
							if (studentsarray[t].student_program == programsarray[y].program_id)
							{
								n = 5;
								break;
							}

						}
						if ( n == 5)
						{
							break;
						}
						printl("");
						printl ("\t -----------------------------------------------------------");
						printl ("\t This course is not exist in our system please type again !!! ");
						cout << "\t You have only " << 3-n << " chanses !!! " << endl;
						totalprograms();
						printl ("\t -----------------------------------------------------------");
						printl ("\t These courses only exist in our system ");
						printl ("\t -----------------------------------------------------------");
						for (int j = 0; j < arraytotal_programs; j++)
						{
							cout << "\t Course ID   : " << programsarray[j].program_id << endl;
							cout << "\t Course Name : " << programsarray[j].program_name << endl;
							cout << endl;
						}
						printl ("\t -----------------------------------------------------------");
						if (n == 2)
						{
							printl ("\t  We have made your course id but still");
							printl ("\t  it's not available until you add from programs menu ");
							printl ("\t -----------------------------------------------------------");
						}
						n++;	
					}


						printl ("\t Password      : " + studentsarray[t].student_password );
						print  ("\t Edit Password : " );
						string password;
						cin >> password;
						if ( password == "no" )
						{
							password = studentsarray[t].student_password;
						}
						studentsarray[t].student_password = password;
						printl ("\t-------------------------------------------------------------");

						cout << "\t Username      : " << studentsarray[t].username << endl;
						printl  ("\t Edit Username" );
						print  ("\t Type '0' for default : " );
						int username;
						cin >> username;
						if ( username == 0 )
						{
							username = studentsarray[t].username;
						}
						studentsarray[t].username = username;
						printl ("\t-------------------------------------------------------------");

						found = true;	//	TRUE when the student id found
						break;	//	Break the loop if the student found
					}
	
				}
				/*	IF not found studet id give alert message and call Menu */
				if ( found == false ) 
				{
					cout << "\t YOUR ID NOT FOUND !!! Please check the id and try again " << endl;
				}
				else if ( found == true )
				{
				/*	Success Alert	*/
				cls();
				printl("");
				printl("");
				printl("\t+-----------------------------------------------------------+");
				print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
				print ("\t| Teacher : ");
				print (teachername) ;
				print ("			              ");
				times(); 
				printl(" |");
				printl("\t|-----------------------------------------------------------|");
				printl("\t| Menu > Manage Students > Edit Student's Information       |");
				printl("\t+-----------------------------------------------------------+");
				printl("\t|                                                           |");
				printl("\t| * You have successfully updated press any key to go menu  |");
				printl("\t|                                                           |");
				printl("\t+-----------------------------------------------------------+");
				pause();
				cls();
				/*	Call menu again	*/
				teachermenu(teachername);
				}

				/*	If the process completed then go to main menu	*/
				printl ("\tType any key to go main menu");
				pause();
				cls();
				teachermenu(teachername);

			}
			else if ( option_manage_student == 3 )
			{
				cls();
				printl("");
				printl("");
				printl("\t+-----------------------------------------------------------+");
				print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
				print ("\t| Teacher : ");
				print (teachername) ;
				print ("			              ");
				times(); 
				printl(" |");
				printl("\t|-----------------------------------------------------------|");
				printl("\t| Menu > Manage Students > Search Student                   |");
				printl("\t+-----------------------------------------------------------+");
				printl("\t|                                                           |");
				printl("\t|    * Type Student ID or Name ?                    |");
				printl("\t|                                                           |");
				printl("\t+-----------------------------------------------------------+");
				print ("\t Enter here \t\t-->\t "); 

				cin >> search_st;
				printl("\t-------------------------------------------------------------");
			
				cls();
				printl("");
				printl("");
				printl("\t+-----------------------------------------------------------+");
				print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
				print ("\t| Teacher : ");
				print (teachername) ;
				print ("			              ");
				times(); 
				printl(" |");
				printl("\t|-----------------------------------------------------------|");
				printl("\t| Menu > Manage Students > Search Student                   |");
				printl("\t+-----------------------------------------------------------+");
				printl("");
				printl ("\t Results for your search keyword : "+ search_st);
				printl ("");

				/*	Search Function used for the student search	*/
				totalstudents();
				search_students(search_st);	//	Search function and search keyword


				/*	If the process complete call menu	*/
				printl ("\tType any key to go main menu");
				pause();
				cls();
				teachermenu(teachername);
				}
			else if ( option_manage_student == 4 )
			{
				exitrequest();	//	Exit Request
			}
			else
			{
				/*	Default case if the user enter wrong values into the menu	*/
				printl ("\t Type only the numbers that listed above !");
				pause();
				cls();
				teachermenu(teachername);
			}

		break;
	case 7:
		
		exitrequest();	//	Exit Request
		break;
	case 99:
		
		helpmenu();
		break;
	default:

		/*	Default case if the user enter wrong values into the menu	*/
		printl ("\t Type only the numbers that listed above !");
		pause();
		cls();
		teachermenu(teachername);
		break;
		
	}	//	Case End
	
}


/*	Student Menu Function	*/

void studentmenu(string studentname)
{
	string search_s_s;		// Programs Search Variable

	cls();
	printl("");
	printl("");
	printl("\t|-----------------------------------------------------------|");
	print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
	print ("\t| Student : ");
	print (studentname) ;
	print ("                                     ");
	times(); 
	printl("   |");
	printl("\t|-----------------------------------------------------------|");
	printl("\t|                                                           |");
	printl("\t|\t1. Special Offers\t\t\t\t    |");
	printl("\t|                                                           |");
	printl("\t|\t2. Registered Programs\t\t\t\t    |");
	printl("\t|                                                           |");
	printl("\t|\t3. Search Programs\t\t\t\t    |");
	printl("\t|                                                           |");
	printl("\t|\t4. My Profile\t\t\t\t\t    |");
	printl("\t|                                                           |");
	printl("\t|\t5. Exit\t\t\t\t\t\t    |");
	printl("\t|                                                           |");
	printl("\t|-----------------------------------------------------------|");
	printl("\t| Enter your choise here 1 to 5 or 99 for help -->          |");
	printl("\t|-----------------------------------------------------------|");
	printl("");
	print ("\tType here -> ");
	int option_student_menu;	//	Student option
	cin >> option_student_menu;

	bool special_found = false;			//	Special offer found
	bool special_found_prog = false;	//	Programs Found

	switch (option_student_menu)
	{
	case 1:
			/*	Here I used the same concept that which is used for show special programs	*/
			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Student : ");
			print (studentname) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Special Offers                                     |");
			printl("\t+-----------------------------------------------------------+");
			printl("");


			totalprograms();

			for (int t = 0; t < arraytotal_programs; t++ )
			{ 
				if ( programsarray[t].program_special_offer == "Y" || programsarray[t].program_special_offer == "y"  )
				{
				printl ("\t ID \t\t:\t " + programsarray[t].program_id);
				printl ("\t Name \t\t:\t " + programsarray[t].program_name);
				printl ("\t Desctiption \t:\t " + programsarray[t].program_desc);
				printl ("\t Duration \t:\t " + programsarray[t].program_duration);
				printl ("\t Date \t\t:\t " + programsarray[t].program_date);
				printl ("\t Offer Desc \t:\t " + programsarray[t].program_offer_desc);
				printl ("");
				printl("\t+-----------------------------------------------------------+");
				special_found = true;
				}
			}
			if (special_found == false)
			{
				printl ("\t No programs registered yet");
				printl ("");
				printl("\t+-----------------------------------------------------------+");
				printl ("");
			}

			printl ("\tType any key to go main menu");
			pause();
			cls();
			studentmenu(studentname);

		break;
	case 2:

			/*	Here I used the same concept that which is used for certificate programs But what program ID is containing on the student array, Here show only the studet's programs	*/
			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Student : ");
			print (studentname) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Registered Program                                 |");
			printl("\t+-----------------------------------------------------------+");
			printl("");

			totalprograms();
			
			for (int t = 0; t < arraytotal_programs; t++ )
			{ 
				/*	If the program ID and the student array program ID matched	*/
				if ( programsarray[t].program_id == studentsarray[user_arrayno].student_program )
				{
				printl ("\t ID \t\t:\t " + programsarray[t].program_id);
				printl ("\t Name \t\t:\t " + programsarray[t].program_name);
				printl ("\t Desctiption \t:\t " + programsarray[t].program_desc);
				printl ("\t Duration \t:\t " + programsarray[t].program_duration);
				printl ("\t Date \t\t:\t " + programsarray[t].program_date);
				printl ("\t Offer Desc \t:\t " + programsarray[t].program_offer_desc);
				printl ("");
				printl("\t+-----------------------------------------------------------+");
				special_found_prog = true;
				}
			}
			if (special_found_prog == false)
			{
				printl ("\t No programs registered yet");
				printl ("");
				printl("\t+-----------------------------------------------------------+");
				printl ("");
			}

			printl ("\tType any key to go main menu");
			pause();
			cls();
			studentmenu(studentname);

		break;
	case 3:
			/*	Here I used the same concept that which is used for search programs	*/
			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Student : ");
			print (studentname) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Search Program                                     |");
			printl("\t+-----------------------------------------------------------+");
			printl("\t|                                                           |");
			printl("\t|    * Type Course ID or Name or Offer ?                    |");
			printl("\t|                                                           |");
			printl("\t+-----------------------------------------------------------+");
			print ("\t Enter here \t\t-->\t "); 

			cin >> search_s_s;
			printl("\t-------------------------------------------------------------");
			
			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Student : ");
			print (studentname) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Search Program                                     |");
			printl("\t+-----------------------------------------------------------+");
			printl("");
			printl ("\t Results for your search keyword : "+ search_s_s);
			printl ("");

			totalprograms();

			/*	Search functions is used for search programs	*/
			search_programs(search_s_s);

			printl ("\tType any key to go main menu");
			pause();
			cls();
			studentmenu(studentname);

		break;
	case 4:

			cls();
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Student : ");
			print (studentname) ;
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > My Profile                                         |");
			printl("\t+-----------------------------------------------------------+");
			printl("");

			/*	View the current (user) student profile 	*/

			printl ("\t ID \t\t:\t " + studentsarray[user_arrayno].student_id);
			printl ("\t Name \t\t:\t " + studentsarray[user_arrayno].student_name);
			cout << "\t Age    \t:\t " << studentsarray[user_arrayno].student_age << endl;
			printl ("\t City    \t:\t " + studentsarray[user_arrayno].student_city);
			printl ("\t Program \t:\t " + studentsarray[user_arrayno].student_program);
			cout << "\t Username \t:\t " << studentsarray[user_arrayno].username << endl;
			printl ("\t Password  \t:\t " + studentsarray[user_arrayno].student_password);
			printl ("");
			printl("\t+-----------------------------------------------------------+");
				
			

			printl ("\tType any key to go main menu");
			pause();
			cls();
			studentmenu(studentname);

		break;
	case 5:

		exitrequest();	//	Exit request

		break;
	case 99:

		helpmenu();	//	Help Menu

		break;
	default:
		/*	Default case if the user enter wrong values into the menu	*/
		printl ("\t Type only the numbers that listed above !");
		break;
	}

	/*	Call menu	*/
	pause();
	studentmenu(studentname);
}

/*	Loading Menu Just for Welcome	*/
void loadingmenu()
{
	cls();
	printl("");
	printl("");
	printl("\t|-----------------------------------------------------------|");
	print ("\t| WELCOME                      		          ");dates(); printl(" |");
	printl("\t|-----------------------------------------------------------|");
	printl("\t|                                                           |");
	printl("\t|                                                           |");
	printl("\t|                                                           |");
	printl("\t|                                                           |");
	printl("\t|      Please wait while while the system is loading        |");
	printl("\t|                                                           |");
	printl("\t|                                                           |");
	printl("\t|                World Of IT Institute                      |");
	printl("\t|                                                           |");
	printl("\t|                                                           |");
	printl("\t|-----------------------------------------------------------|");
	printl("");
	print ("\t\t\t*    *    *    *    *    *   ");
	printl ("");
	print ("\t\t\t");
		//Y < 5
		/*	Animation for 5 seconds	*/
		for (int y = 1; y <= 2; y++ )
		{
			wait(1); print ("*    ");
		}
}

/*	Get total arrays filled from the courses array Function	*/

int totalprograms()
{
	arraytotal_programs = 0;
	for(int m = 0; m <= (sizeof(programsarray)/sizeof(*programsarray)); m++)
	{
	int arraycount = programsarray[m].program_no;
	arraytotal_programs = arraycount + arraytotal_programs;
	}
	return arraytotal_programs;
}

/*	Get total arrays filled from the students array Function	*/

int totalstudents()
{
	arraytotal_students = 0;
	for(int m = 0; m <= (sizeof(studentsarray)/sizeof(*studentsarray)); m++)
	{
	int arraycount = studentsarray[m].student_no;
	arraytotal_students = arraycount + arraytotal_students;
	}
	return arraytotal_students;
}


/*	Search Programs Function	*/

void search_programs(string search_text)
{
	totalprograms();
		bool found = false;
		for (int t = 0; t < arraytotal_programs; t++ )
		{
			if ( programsarray[t].program_id == search_text || programsarray[t].program_name == search_text || programsarray[t].program_offer_desc == search_text ) 
			{
			printl ("\t ID \t\t:\t " + programsarray[t].program_id);
			printl ("\t Name \t\t:\t " + programsarray[t].program_name);
			printl ("\t Desctiption \t:\t " + programsarray[t].program_desc);
			printl ("\t Duration \t:\t " + programsarray[t].program_duration);
			printl ("\t Date \t\t:\t " + programsarray[t].program_date);
			if ( programsarray[t].program_special_offer == "Y" || programsarray[t].program_special_offer == "y" )
			{
			printl ("\t Special Offer \t:\t " + programsarray[t].program_offer_desc);
			}
			printl ("");
			printl("\t+-----------------------------------------------------------+");
			found = true;
			break;
			}
		}
		if (found == false )
		{
			printl("\t Your search program not found in our system pls check again ");
			printl ("");
			printl("\t+-----------------------------------------------------------+");
		}
}

/*	Search Students Function	*/

void search_students(string search_text)
{
	totalstudents();
		bool found = false;
		for (int t = 0; t < arraytotal_students; t++ )
		{
			if ( studentsarray[t].student_id == search_text || studentsarray[t].student_name == search_text || studentsarray[t].student_program == search_text ) 
			{
			printl ("\t ID \t\t:\t " + studentsarray[t].student_id);
			printl ("\t Name \t\t:\t " + studentsarray[t].student_name);
			cout << "\t Age    \t:\t " << studentsarray[t].student_age << endl;
			printl ("\t City    \t:\t " + studentsarray[t].student_city);
			printl ("\t Program \t:\t " + studentsarray[t].student_program);
			cout << "\t Username \t:\t " << studentsarray[t].username << endl;
			printl ("\t Password  \t:\t " + studentsarray[t].student_password);
			printl ("");
			printl("\t+-----------------------------------------------------------+");
			found = true;
			break;
			}
		}
		if (found == false )
		{
			printl("\t Your search student not found in our system pls check again ");
			printl ("");
			printl("\t+-----------------------------------------------------------+");
		}
}

/*	Help Menu	*/
void helpmenu()
{
			cls();
			system("color 07");
			printl("");
			printl("");
			printl("\t+-----------------------------------------------------------+");
			print ("\t| Welcome to World of IT Institute		  ");dates(); printl(" |");
			print ("\t| Dear  :    ");
			if (usersarray[user_arrayno].userid == typeuserid)
			{
				print (usersarray[user_arrayno].username);
			}
			else if ( studentsarray[user_arrayno].username == typeuserid )
			{
				print (studentsarray[user_arrayno].student_name);
			}
			print ("			              ");
			times(); 
			printl(" |");
			printl("\t|-----------------------------------------------------------|");
			printl("\t| Menu > Help                                               |");
			printl("\t+-----------------------------------------------------------+");
			printl("");

			/*	View the current (user) student profile 	*/

			printl ("\t  Hi there ! What is the problem ?");
			printl ("");
			printl ("\t  1. Please type the numbers of the menu listed there");
			wait(1);
			printl ("\t  2. If you want to close then enter the exit menu number");
			wait(1);
			printl ("\t  3. Please carefully type numbers ");
			wait(1);
			printl ("\t  4. If you type letters on menu that will close ");
			wait(1);
			printl ("\t  5. Please make sure consider you type value number or letter ");
			wait(1);
			printl ("\t  6. If any issues feel free to contact my maker Aslam 072 3016663");
			printl ("");
			printl("\t+-----------------------------------------------------------+");
				
			

			printl ("\tType any key to go main menu");
			pause();
			cls();
			system("color 1F");
			/*	Once the system is restarted this function is transfer the user to the appropriate department	*/
			if ( usersarray[user_arrayno].userid == typeuserid )
			{
				string teachername = usersarray[user_arrayno].username;
				teachermenu(teachername);
			}
			else if ( studentsarray[user_arrayno].username == typeuserid )
			{
				string studentname = studentsarray[user_arrayno].student_name;
				studentmenu(studentname);
			}
}





/*

Made by Aslam Mohammed 
www.aslam.zz.mu

*/