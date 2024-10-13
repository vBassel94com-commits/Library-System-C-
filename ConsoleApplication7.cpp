#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <dirent.h>
using namespace std;
int totalbooks = 0, j = 0, t = 0, k = 0, x = 0,Treasury=0;
struct Book
{
	string Title;
	string Author;
	string ISBN, Date;
	int Quantity;
};
struct Lending
{
	string StudentName;
	string RollNum;
	string Booktitle,Author,ISBN,Date;
	string DateofLending, DateofReturn;
	int FineForLateReturn;
	int OriginalQuantity;
	int QuantityofIssuedBook;
};
Lending A[10000];
Book List[10000];
Book List1[10000];
int TotQuantity, opt;
void MainMenu();
void StudentMenu();
void StudentSearchByName();
void StudentSearchByISBN();
void SearchBookStudent();
void SearchBookAdmin();
void AdminSearchByName();
void AdminSearchByISBN();
void BookList();


void ReturnBook()
{
	ofstream fout;
	ifstream fin;
	string Name, Rollno, RB;
	int i = 0;
	cout << "\n\t\t\t\t Enter your Name: ";
	cin.ignore();
	getline(cin, Name);
	cout << "\n\t\t\t\t Enter your Roll Number (e.g.22L-1234): ";
	getline(cin, Rollno);
	cin.ignore();
	cout << "\t\t\t\t Enter Book Name (Input Exact Name): ";
	getline(cin, RB);
	cin.ignore();
	DIR* dr;
	struct dirent* en;
	dr = opendir("Lending Files/.");
	if (dr != NULL)
	{
		en = readdir(dr);
		en = readdir(dr);
		while (en = readdir(dr))
		{
			//cout << en->d_name << "\n";
			string path = "C:\\Users\\Dell\\source\\repos\\ConsoleApplication7\\ConsoleApplication7\\Lending Files";
			path = path + "\\" + en->d_name;
			//cout << path << endl;
			fin.open(path);
			getline(fin, A[i].StudentName);
			getline(fin, A[i].RollNum);
			getline(fin, A[i].Booktitle);
			getline(fin, A[i].Author);
			getline(fin, A[i].ISBN);
			getline(fin, A[i].Date);
			getline(fin, A[i].DateofLending);
			getline(fin, A[i].DateofReturn);
			fin >> A[i].FineForLateReturn;
			fin >> A[i].OriginalQuantity;
			fin >> A[i].QuantityofIssuedBook;
			fin.close();
			i++;
			x++;
		}
		closedir(dr);
	}
	i = 0;
	while (i < x + 1)
	{
		if (Name == A[i].StudentName && Rollno == A[i].RollNum && RB == A[i].Booktitle)
		{   
			string BookFileName = "Book Files/" + RB + ".txt";
			fout.open(BookFileName.c_str());
			A[i].QuantityofIssuedBook;
			fout << A[i].ISBN << endl << A[i].Booktitle << endl << A[i].Author << endl << A[i].Date << endl << A[i].OriginalQuantity << endl;
			fout.close();
			int status;
			status = remove(("Lending Files/" + Rollno + ".txt").c_str());
			if (status == 0)
			{vc:
				cout << "\n\t\t\t\t Are You Returning Book Late?\n\t\t\t\t 1. Yes \n\t\t\t\t 2. No";
				cout << "\n\n\t\t\t\t Enter your Choice : ";
				cin >> opt;
				switch (opt)
				{
				case 1:
					fin.open("Treasury.txt");
					fin >> Treasury;
					fin.close();
					Treasury += A[i].FineForLateReturn;
					fout.open("Treasury.txt");
					fout << Treasury;
					fout.close();
					cout << "\n\t\t\t\t Fine Collected and Book Returned Successfully!";
					cout << endl;
					break;
				case 2:
					cout << "\n\t\t\t\t Book Returned Successfully!";
					cout << endl;
					break;
				default:
					cout << "\n\t\t\t\t Please Input Correct Option!!";
					goto vc;
				}
			cc:
				cout << "\n\t\t\t\t Do you want to return another Book or Return to Main Menu or Student menu? " << "\n\n\t\t\t\t 1. Return Book \n\n\t\t\t\t 2. Main Menu \n\n\t\t\t\t 3. Student Menu \n\n\t\t\t\t 4. Exit Program  ";
				cout << "\n\n\t\t\t\t Enter your Choice : ";
				cin >> opt;
				cout << endl;
				if (opt == 1)
				{
					ReturnBook();
				}
				else if (opt == 2)
				{
					MainMenu();
				}
				else if (opt == 3)
				{
					StudentMenu();
				}
				else if (opt == 4)
				{
					exit(0);
				}
				else
				{
					cout << "\n\t\t\t\t Invalid Option. Please Enter the Correct Option ";
					goto cc;
				}
			}
			t = 0;
		}
		else
		{
			t = 1;
		}
		i++;
	}
	if (t == 1)
	{
		cout << "\n\t\t\t\t Entered Book is not in Records";
	tt:
		cout << "\n\t\t\t\t Do you want to return another Book or Return to Main Menu or Student menu? " << "\n\n\t\t\t\t 1. Return Book \n\n\t\t\t\t 2. Main Menu \n\n\t\t\t\t 3. Student Menu \n\n\t\t\t\t 4. Exit Program  ";
		cout << "\n\n\t\t\t\t Enter your Choice: ";
		cin >> opt;
		cout << endl;
		if (opt == 1)
		{
			ReturnBook();
		}
		else if (opt == 2)
		{
			MainMenu();
		}
		else if (opt == 3)
		{
			StudentMenu();
		}
		else if (opt == 4)
		{
			exit(0);
		}
		else
		{
			cout << "\n\t\t\t\t Invalid Option. Please Enter the Correct Option ";
			goto tt;
		}
	}
}


void AdminMenu()
{
	int Choice;
	string BookFileName;
	ofstream fout;
	ifstream fin;
	int totalbooks = 0;
	do
	{
		fin.open("counter.txt");
		fin >> totalbooks;
		fin.close();
		cout << "\n\t\t\t\t ************ WELCOME ADMIN ************\n";
		cout << "\n\t\t\t\t Please Choose One Option:\n";
		cout << "\n\t\t\t\t 1. Add New Book\n\n\t\t\t\t 2. Remove A Book\n\n\t\t\t\t 3. Search to Add Book Quantity\n\n\t\t\t\t 4. View Treasury\n\n\t\t\t\t 5. Main Menu\n";
		cout << "\n\n\t\t\t\t Enter your Choice: ";
		cin >> Choice;
		cout << endl;
		if (Choice == 1)
		{
			int i = 0;
			cout << "\t\t\t\t Enter the ISBN Number: ";
			cin.ignore();
			getline(cin, List[totalbooks].ISBN);
			cout << "\n\t\t\t\t Enter the Book Title: ";
			getline(cin, List[totalbooks].Title);
			cin.ignore();
			cout << "\t\t\t\t Enter the Author of " << List[totalbooks].Title << ": ";
			getline(cin, List[totalbooks].Author);
			cin.ignore();
			cout << "\t\t\t\t Enter the Date of Publishing of " << List[totalbooks].Title << ": ";
			getline(cin, List[totalbooks].Date);
			cin.ignore();
			cout << "\t\t\t\t Enter the Quantity available: ";
			cin >> List[totalbooks].Quantity;
			cin.ignore();
			BookFileName = "Book Files/" + List[totalbooks].Title + ".txt";
			fout.open(BookFileName.c_str());
			fout << List[totalbooks].ISBN << endl << List[totalbooks].Title << endl << List[totalbooks].Author << endl << List[totalbooks].Date << endl << List[totalbooks].Quantity << endl;;
			cout << "\n\t\t\t\t Book is successfully registered:) " << endl;
			cin.ignore();
			fout.close();
			totalbooks++;
			fout.open("counter.txt");
			fout << totalbooks;
			fout.close();
		we:
			cout << "\n\t\t\t\t Do You Want to return to Main Menu or Admin Menu? " << "\n\n\t\t\t\t 1. Main Menu \n\n\t\t\t\t 2. Admin Menu: ";
			cout << "\n\n\t\t\t\t Enter your Choice: ";
			cin >> opt;
			cout << endl;
			if (opt == 1)
			{
				MainMenu();
			}
			else if (opt == 2)
			{
				AdminMenu();
			}
			else
			{
				cout << "\n\t\t\t\t Invalid Option. Please Input Correct Option ";
				goto we;
			}
		}

		else if (Choice == 2)
		{
			int status;
			string filename;
			cin.ignore();
			cout << "\t\t\t\t Enter the Name of File: ";
			getline(cin, filename);
			cin.ignore();
			status = remove(("Book Files/" + filename + ".txt").c_str());
			if (status == 0)
				cout << "\n\t\t\t\t File Deleted Successfully!";
			else
				cout << "\t\t\t\t Book is not registered. Kindly register it First.";
			cout << endl;
		we1:
			cout << "\n\t\t\t\t Do you want to return to Main Menu or Admin Menu? " << "\n\n\t\t\t\t 1. Main Menu \n\n\t\t\t\t 2. Admin Menu: ";
			cout << "\n\n\t\t\t\t Enter your Choice: ";
			cin >> opt;
			cout << endl;
			if (opt == 1)
			{
				MainMenu();
			}
			else if (opt == 2)
			{
				AdminMenu();
			}
			else
			{
				cout << "\n\t\t\t\t Invalid Option. Please Input Correct Option ";
				goto we1;
			}
		}
		else if (Choice == 3)
		{
			SearchBookAdmin();
		}
		else if (Choice == 4)
		{
			fin.open("Treasury.txt");
			fin >> Treasury;
			fin.close();
			cout << "\n\t\t\t\t Treasury Amount: " << Treasury;
			bh:
			cout << "\n\n\t\t\t\t Do You Want To Return To Admin Menu or Main Menu or Do You Want To Exit?\n\n\t\t\t\t 1. Admin Menu\n\t\t\t\t 2. Main Menu \n\t\t\t\t 3. Exit Program";
			cout << "\n\n\t\t\t\t Enter Your Choice: ";
			cin >> opt;
			if (opt == 1)
			{
				AdminMenu();
			}
			else if (opt == 2)
			{
				MainMenu();
			}
			else if (opt == 3)
			{
				exit(0);
			}
			else
			{
				cout << "\n\n\t\t\t\t Please Enter Correct Option.";
				goto bh;
			}
		}
		else if (Choice == 5)
		{
			MainMenu();
		}
		else
		{
			cout << "\n\t\t\t\t Invalid Option" << endl;
		}

	} while (exit == 0);

}

void AdminSearchByName()
{
	string searchTitle;
	ofstream fout;
	ifstream fin;
	cin.ignore();
	cout << "\n\t\t\t\t Enter the Name of the Book: ";
	getline(cin, searchTitle);
	DIR* dr;
	struct dirent* en;
	dr = opendir("Book Files/.");
	if (dr != NULL)
	{
		en = readdir(dr);
		en = readdir(dr);
		int i = 0;
		while (en = readdir(dr))
		{
			//cout << en->d_name << "\n";
			string path = "C:\\Users\\Dell\\source\\repos\\ConsoleApplication7\\ConsoleApplication7\\Book Files";
			path = path + "\\" + en->d_name;
			//cout << path << endl;
			fin.open(path);
			getline(fin, List1[i].ISBN);
			getline(fin, List1[i].Title);
			getline(fin, List1[i].Author);
			getline(fin, List1[i].Date);
			fin >> List1[i].Quantity;
			fin.close();
			i++;
			j++;
		}
		closedir(dr);
	}
	int i = 0;
	while (i < j + 1)
	{
		if (searchTitle == List1[i].Title)
		{
			int quan=0;
			cout << "\n\t\t\t\t Book found!!\n";
			cout << "\n\t\t\t\t Details are:\n";
			cout << "\n\t\t\t\t ISBN Number: " << List1[i].ISBN;
			cout << "\n\t\t\t\t Book Title: " << List1[i].Title;
			cout << "\n\t\t\t\t Book Author: " << List1[i].Author;
			cout << "\n\t\t\t\t Date of Publishing: " << List1[i].Date;
			cout << "\n\t\t\t\t Book Quantity: " << List1[i].Quantity << endl;
			yy:
			cout << "\n\n\t\t\t\t Do You Want To Add Book Quantity?\n\n\t\t\t\t 1. Yes\n\t\t\t\t 2. No";
			cout << "\n\n\t\t\t\t Enter Your Choice: ";
			cin >> opt;
			if (opt == 1)
			{
				cout << "\n\t\t\t\t Enter How Much Quantity Do You Want To Add: ";
				cin >> quan;
				string BookFileName = "Book Files/" + searchTitle + ".txt";
				fout.open(BookFileName.c_str());
				List1[i].Quantity += quan;
				fout << List1[i].ISBN << endl << List1[i].Title << endl << List1[i].Author << endl << List1[i].Date << endl << List1[i].Quantity << endl;
				fout.close();
			ty:
				cout << "\n\n\t\t\t\t Do You Want to Search Again Or Return To Admin Menu Or Main Menu?\n\n\t\t\t\t 1. Search To Add Quantity\n\t\t\t\t 2. Admin Menu\n\t\t\t\t 3. Main Menu ";
				cout << "\n\n\t\t\t\t Enter Your Choice: ";
				cin >> opt;
				if (opt == 1)
				{
					SearchBookAdmin();
				}
				else if (opt == 2)
				{
					AdminMenu();
				}
				else if (opt == 3)
				{
					MainMenu();
				}
				else
				{
					cout << "\n\t\t\t\t Invalid Option. Please Enter the Correct Option, ";
					goto ty;
				}
			}
			else if (opt == 2)
			{
				AdminMenu();
			}
			else
			{
				cout << "\n\n\t\t\t\t Please Enter Correct Option.";
				goto yy;
			}
		zz:
			cout << "\n\t\t\t\t Do you want to search another Book or Return to Main Menu or Admin menu? " << "\n\n\t\t\t\t 1. Search Again \n\n\t\t\t\t 2. Main Menu \n\n\t\t\t\t 3. Admin Menu \n\n\t\t\t\t 4. Exit Program  ";
			cout << "\n\n\t\t\t\t Enter your Choice: ";
			cin >> opt;
			cout << endl;
			if (opt == 1)
			{
				SearchBookAdmin();
			}
			else if (opt == 2)
			{
				MainMenu();
			}
			else if (opt == 3)
			{
				AdminMenu();
			}
			else if (opt == 4)
			{
				exit(0);
			}
			else
			{
				cout << "\n\t\t\t\t Invalid Option. Please Enter the Correct Option ";
				goto zz;
			}
			t = 0;
		}
		else
		{
			t = 1;
		}
		i++;
	}
	if (t == 1)
	{
		cout << "\n\t\t\t\t Book not Found." << endl << endl;
	we7:
		cout << "\n\t\t\t\t 1. Search Again \n\n\t\t\t\t 2. Admin Menu";
		cout << "\n\n\t\t\t\t Enter your Choice: ";
		cin >> opt;
		cout << endl;
		if (opt == 1)
		{
			SearchBookAdmin();
		}
		else if (opt == 2)
		{
			AdminMenu();
		}
		else
		{
			cout << "\n\t\t\t\t Invalid Option. Please Input Correct Option ";
			goto we7;
		}
	}

}


void AdminSearchByISBN()
{
	string searchISBN;
	ofstream fout;
	ifstream fin;
	cout << "\n\t\t\t\t Enter ISBN Number of the Book: ";
	cin >> searchISBN;
	DIR* dr;
	struct dirent* en;
	dr = opendir("Book Files/.");
	if (dr != NULL)
	{
		en = readdir(dr);
		en = readdir(dr);
		int i = 0;
		while (en = readdir(dr))
		{
			//cout << en->d_name << "\n";
			string path = "C:\\Users\\Dell\\source\\repos\\ConsoleApplication7\\ConsoleApplication7\\Book Files";
			path = path + "\\" + en->d_name;
			//cout << path << endl;
			fin.open(path);
			getline(fin, List1[i].ISBN);
			getline(fin, List1[i].Title);
			getline(fin, List1[i].Author);
			getline(fin, List1[i].Date);
			fin >> List1[i].Quantity;
			fin.close();
			i++;
			j++;
		}
		closedir(dr);
	}
	int i = 0;
	while (i < j + 1)
	{
		if (searchISBN == List1[i].ISBN)
		{
			cout << "\n\t\t\t\t Book found!!\n";
			cout << "\n\t\t\t\t Details are:\n";
			cout << "\n\t\t\t\t ISBN Number: " << List1[i].ISBN;
			cout << "\n\t\t\t\t Book Title: " << List1[i].Title;
			cout << "\n\t\t\t\t Book Author: " << List1[i].Author;
			cout << "\n\t\t\t\t Date of Publishing: " << List1[i].Date;
			cout << "\n\t\t\t\t Book Quantity: " << List1[i].Quantity << endl;
		yy:
			cout << "\n\n\t\t\t\t Do You Want To Add Book Quantity?\n\n\t\t\t\t 1. Yes\n\t\t\t\t 2. No";
			cout << "\n\n\t\t\t\t Enter Your Choice: ";
			cin >> opt;
			if (opt == 1)
			{
				int quan=0;
				cout << "\n\t\t\t\t Enter How Much Quantity Do You Want To Add: ";
				cin >> quan;
				string BookFileName = "Book Files/" + List1[i].Title + ".txt";
				fout.open(BookFileName.c_str());
				List1[i].Quantity += quan;
				fout << List1[i].ISBN << endl << List1[i].Title << endl << List1[i].Author << endl << List1[i].Date << endl << List1[i].Quantity << endl;
				fout.close();
				ty:
				cout << "\n\n\t\t\t\t Do You Want to Search Again Or Return To Admin Menu Or Main Menu?\n\n\t\t\t\t 1. Search To Add Quantity\n\t\t\t\t 2. Admin Menu\n\t\t\t\t 3. Main Menu ";
				cout << "\n\n\t\t\t\t Enter Your Choice: ";
				cin >> opt;
				if (opt == 1)
				{
					SearchBookAdmin();
				}
				else if (opt == 2)
				{
					AdminMenu();
				}
				else if (opt == 3)
				{
					MainMenu();
				}
				else
				{
					cout << "\n\t\t\t\t Invalid Option. Please Enter the Correct Option, ";
					goto ty;
				}
			}
			else if (opt == 2)
			{
				AdminMenu();
			}
			else
			{
				cout << "\n\n\t\t\t\t Please Enter Correct Option.";
				goto yy;
			}
		zz:
			cout << "\n\t\t\t\t Do you want to search another Book or Return to Main Menu or Admin Menu? " << "\n\n\t\t\t\t 1. Search Again \n\n\t\t\t\t 2. Main Menu \n\n\t\t\t\t 3. Admin Menu \n\n\t\t\t\t 4. Exit Program  ";
			cout << "\n\n\t\t\t\t Enter your Choice: ";
			cin >> opt;
			cout << endl;
			if (opt == 1)
			{
				SearchBookAdmin();
			}
			else if (opt == 2)
			{
				MainMenu();
			}
			else if (opt == 3)
			{
				AdminMenu();
			}
			else if (opt == 4)
			{
				exit(0);
			}
			else
			{
				cout << "\n\t\t\t\t Invalid Option. Please Enter the Correct Option, ";
				goto zz;
			}
			t = 0;
		}
		else
		{
			t = 1;
		}
		i++;
	}
	if (t == 1)
	{
		cout << "\t\t\t\t Book not Found.";
	we7:
		cout << "\n\t\t\t\t 1. Search Again \n\n\t\t\t\t 2. Admin Menu " << endl;
		cout << "\n\t\t\t\t Enter your Choice: ";
		cin >> opt;
		cout << endl;
		if (opt == 1)
		{
			SearchBookAdmin();
		}
		else if (opt == 2)
		{
			AdminMenu();
		}
		else
		{
			cout << "\n\t\t\t\t Invalid Option. Please Input Correct Option ";
			goto we7;
		}
	}
}

void SearchBookAdmin()
{
	{
		int c;
		cout << "\n\t\t\t\t Do You Want to Search By ISBN or Book Title?\n\n\t\t\t\t 1. Book Name \n\n\t\t\t\t 2. ISBN Number ";
		cout << "\n\n\t\t\t\t Enter your Choice: ";
		cin >> c;
		if (c != 1 && c != 2)
		{
			cout << "\n\t\t\t\t Invalid Option. Please Input Correct Option ";
			SearchBookAdmin();
		}
		if (c == 1)
		{
			AdminSearchByName();
		}
		if (c == 2)
		{
			AdminSearchByISBN();
		}
	}
}

void StudentSearchByName()
{
	string searchTitle;
	ofstream fout, fout1;
	ifstream fin, fin1;
	cin.ignore();
	cout << "\n\t\t\t\t Enter the Name of the Book: ";
	getline(cin, searchTitle);
	DIR* dr;
	struct dirent* en;
	dr = opendir("Book Files/.");
	if (dr != NULL)
	{
		en = readdir(dr);
		en = readdir(dr);
		int i = 0;
		while (en = readdir(dr))
		{
			//cout << en->d_name << "\n";
			string path = "C:\\Users\\Dell\\source\\repos\\ConsoleApplication7\\ConsoleApplication7\\Book Files";
			path = path + "\\" + en->d_name;
			//cout << path << endl;
			fin.open(path);
			getline(fin, List1[i].ISBN);
			getline(fin, List1[i].Title);
			getline(fin, List1[i].Author);
			getline(fin, List1[i].Date);
			fin >> List1[i].Quantity;
			fin.close();
			i++;
			j++;
		}
		closedir(dr);
	}
	int i = 0;
	while (i < j + 1)
	{
		if (searchTitle == List1[i].Title)
		{
			int opt1;
			string BookFile;
			cout << "\n\t\t\t\t Book found!!\n";
			cout << "\n\t\t\t\t Details are:\n";
			cout << "\n\t\t\t\t ISBN Number: " << List1[i].ISBN;
			cout << "\n\t\t\t\t Book Title: " << List1[i].Title;
			cout << "\n\t\t\t\t Book Author: " << List1[i].Author;
			cout << "\n\t\t\t\t Date of Publishing: " << List1[i].Date;
			cout << "\n\t\t\t\t Book Quantity: " << List1[i].Quantity << endl;
		vv:
			cout << "\n\n\t\t\t\t Do You Want To Lend Book?\n\n\t\t\t\t 1. Yes\n\n\t\t\t\t 2. No ";
			cout << "\n\n\t\t\t\t Enter your Choice : ";
			cin >> opt1;
			cout << endl;
			if (opt1 != 1 && opt1 != 2)
			{
				cout << "\n\t\t\t\t Invalid Option. Kindly Enter Correct Option.";
				goto vv;
			}
			else if (opt1 == 1)
			{
				if (List1[i].Quantity == 0)
				{
					cout << "\n\n\t\t\t\t Sorry The Book Is Out Of Stock :(";
				}
				else
				{
					cout << "\n\t\t\t\t Enter Your Name: ";
					cin.ignore();
					getline(cin, A[k].StudentName);
					cout << endl;
					cout << "\n\t\t\t\t Enter Your Roll Number (e.g 22L-1234): ";
					getline(cin, A[k].RollNum);
					cin.ignore();
					cout << "\n\t\t\t\t Enter Date Of Lending: ";
					getline(cin, A[k].DateofLending);
					cin.ignore();
					cout << "\n\t\t\t\t Enter Date Of Return: ";
					getline(cin, A[k].DateofReturn);
					cin.ignore();
					cout << "\n\t\t\t\t Enter Fine For Late Return: ";
					cin >> A[k].FineForLateReturn;
					cout << endl<<endl;
				ii:
					cout << "\t\t\t\t Enter Quantity Of Book You Want to Lend: ";
					cin >> A[k].QuantityofIssuedBook;
					cout << endl << endl;
					A[k].Booktitle = List1[i].Title;
					A[k].Author = List1[i].Author;
					A[k].ISBN = List1[i].ISBN;
					A[k].Date = List1[i].Date;
					A[k].OriginalQuantity = List1[i].Quantity;
					if (A[k].QuantityofIssuedBook > List1[i].Quantity || A[k].QuantityofIssuedBook == List1[i].Quantity)
					{
						cout << "\n\t\t\t\t Please Enter A Lesser Quantity.\n\n" << endl;
						goto ii;
					}
					string LendingFileName = "Lending Files/" + A[k].RollNum + ".txt";
					fout.open(LendingFileName.c_str());
					fout << A[k].StudentName << endl << A[k].RollNum << endl << A[k].Booktitle << endl << A[k].Author<<endl<< A[k].ISBN << endl << A[k].Date << endl << A[k].DateofLending <<endl<<A[k].DateofReturn<<endl<<A[k].FineForLateReturn << endl << A[k].OriginalQuantity << endl << A[k].QuantityofIssuedBook << endl;
					cout << "\n\t\t\t\t Book Issued :) " << endl;
					fout.close();
					string BookFileName = "Book Files/" + A[k].Booktitle + ".txt";
					fout.open(BookFileName.c_str());
					List1[i].Quantity = List1[i].Quantity - A[k].QuantityofIssuedBook;
					fout << List1[i].ISBN << endl << List1[i].Title << endl << List1[i].Author << endl << List1[i].Date << endl << List1[i].Quantity << endl;
					fout.close();
				}
			}

		zz:
			cout << "\n\t\t\t\t Do you want to search another Book or Return to Main Menu or Student menu? " << "\n\n\t\t\t\t 1. Search Again \n\n\t\t\t\t 2. Main Menu \n\n\t\t\t\t 3. Student Menu \n\n\t\t\t\t 4. Exit Program  ";
			cout << "\n\n\t\t\t\t Enter your Choice: ";
			cin >> opt;
			cout << endl;
			if (opt == 1)
			{
				SearchBookStudent();
			}
			else if (opt == 2)
			{
				MainMenu();
			}
			else if (opt == 3)
			{
				StudentMenu();
			}
			else if (opt == 4)
			{
				exit(0);
			}
			else
			{
				cout << "\n\t\t\t\t Invalid Option. Please Enter the Correct Option ";
				goto zz;
			}
			t = 0;
		}
		else
		{
			t = 1;
		}
		i++;
	}
	if (t == 1)
	{
		cout << "\n\t\t\t\t Book not Found." << endl << endl;
	
	we7:
		cout << "\n\t\t\t\t 1. Search Again \n\n\t\t\t\t 2. Student Menu";
		cout << "\n\n\t\t\t\t Enter your Choice: ";
		cin >> opt;
		cout << endl;
		if (opt == 1)
		{
			SearchBookStudent();
		}
		else if (opt == 2)
		{
			StudentMenu();
		}
		else
		{
			cout << "\n\t\t\t\t Invalid Option. Please Input Correct Option ";
			goto we7;
		}
	}

}

void StudentSearchByISBN()
{
	string searchISBN;
	ofstream fout;
	ifstream fin;
	cout << "\n\t\t\t\t Enter ISBN Number of the Book: ";
	cin >> searchISBN;
	DIR* dr;
	struct dirent* en;
	dr = opendir("Book Files/.");
	if (dr != NULL)
	{
		en = readdir(dr);
		en = readdir(dr);
		int i = 0;
		while (en = readdir(dr))
		{
			//cout << en->d_name << "\n";
			string path = "C:\\Users\\Dell\\source\\repos\\ConsoleApplication7\\ConsoleApplication7\\Book Files";
			path = path + "\\" + en->d_name;
			//cout << path << endl;
			fin.open(path);
			getline(fin, List1[i].ISBN);
			getline(fin, List1[i].Title);
			getline(fin, List1[i].Author);
			getline(fin, List1[i].Date);
			fin >> List1[i].Quantity;
			fin.close();
			i++;
			j++;
		}
		closedir(dr);
	}
	int i = 0;
	while (i < j + 1)
	{
		if (searchISBN == List1[i].ISBN)
		{
			cout << "\n\t\t\t\t Book found!!\n";
			cout << "\n\t\t\t\t Details are:\n";
			cout << "\n\t\t\t\t ISBN Number: " << List1[i].ISBN;
			cout << "\n\t\t\t\t Book Title: " << List1[i].Title;
			cout << "\n\t\t\t\t Book Author: " << List1[i].Author;
			cout << "\n\t\t\t\t Date of Publishing: " << List1[i].Date;
			cout << "\n\t\t\t\t Book Quantity: " << List1[i].Quantity << endl;
		vbn:
			int opt2;
			cout << "\n\n\t\t\t\t Do You Want To Lend Book?\n\n\t\t\t\t 1. Yes\n\n\t\t\t\t 2. No ";
			cout << "\n\n\t\t\t\t Enter your Choice: ";
			cin >> opt2;
			cout << endl;
			if (opt2 != 1 && opt2 != 2)
			{
				cout << "\n\t\t\t\t Invalid Option. Kindly Enter Correct Option.";
				goto vbn;
			}
			else if (opt2 == 1)
			{
				if (List1[i].Quantity == 0)
				{
					cout << "\n\n\t\t\t\t Sorry The Book Is Out Of Stock :(";
				}
				else
				{
					cout << "\n\t\t\t\t Enter Your Name: ";
					cin.ignore();
					getline(cin, A[k].StudentName);
					cout << endl;
					cout << "\n\t\t\t\t Enter Your Roll Number (e.g 22L-1234): ";
					getline(cin, A[k].RollNum);
					cin.ignore();
					cout << "\n\t\t\t\t Enter Date Of Lending: ";
					getline(cin, A[k].DateofLending);
					cin.ignore();
					cout << "\n\t\t\t\t Enter Date Of Return: ";
					getline(cin, A[k].DateofReturn);
					cin.ignore();
					cout << "\n\t\t\t\t Enter Fine For Late Return: ";
					cin >> A[k].FineForLateReturn;
					cout << endl << endl;
				ii:
					cout << "\t\t\t\t Enter Quantity Of Book You Want to Lend: ";
					cin >> A[k].QuantityofIssuedBook;
					cout << endl << endl;
					A[k].Booktitle = List1[i].Title;
					A[k].Author = List1[i].Author;
					A[k].ISBN = List1[i].ISBN;
					A[k].Date = List1[i].Date;
					A[k].OriginalQuantity = List1[i].Quantity;
					if (A[k].QuantityofIssuedBook > List1[i].Quantity || A[k].QuantityofIssuedBook == List1[i].Quantity)
					{
						cout << "\n\t\t\t\t Please Enter A Lesser Quantity.\n\n" << endl;
						goto ii;
					}
					string LendingFileName = "Lending Files/" + A[k].RollNum + ".txt";
					fout.open(LendingFileName.c_str());
					fout << A[k].StudentName << endl << A[k].RollNum << endl << A[k].Booktitle << endl << A[k].Author << endl << A[k].ISBN << endl << A[k].Date << endl << A[k].DateofLending << endl << A[k].DateofReturn << endl << A[k].FineForLateReturn << endl << A[k].OriginalQuantity << endl << A[k].QuantityofIssuedBook << endl;
					cout << "\n\t\t\t\t Book Issued :) " << endl;
					fout.close();
					string BookFileName = "Book Files/" + A[k].Booktitle + ".txt";
					fout.open(BookFileName.c_str());
					List1[i].Quantity = List1[i].Quantity - A[k].QuantityofIssuedBook;
					fout << List1[i].ISBN << endl << List1[i].Title << endl << List1[i].Author << endl << List1[i].Date << endl << List1[i].Quantity << endl;
					fout.close();
				}
			}
		zz:
			cout << "\n\t\t\t\tDo you want to search another Book or Return to Main Menu or Student Menu? " << "\n\n\t\t\t\t 1. Search Again \n\n\t\t\t\t 2. Main Menu \n\n\t\t\t\t 3. Student Menu \n\n\t\t\t\t 4. Exit Program  ";
			cout << "\n\n\t\t\t\tEnter your Choice: ";
			cin >> opt;
			cout << endl;
			if (opt == 1)
			{
				SearchBookStudent();
			}
			else if (opt == 2)
			{
				MainMenu();
			}
			else if (opt == 3)
			{
				StudentMenu();
			}
			else if (opt == 4)
			{
				exit(0);
			}
			else
			{
				cout << "\n\t\t\t\t Invalid Option. Please Enter the Correct Option ";
				goto zz;
			}
			t = 0;
		}
		else
		{
			t = 1;
		}
		i++;
	}
	if (t == 1)
	{
		cout << "\t\t\t\t Book not Found.";
	we7:
		cout << "\n\t\t\t\t 1. Search Again \n\n\t\t\t\t 2. Student Menu " << endl;
		cout << "\n\t\t\t\t Enter your Choice: ";
		cin >> opt;
		cout << endl;
		if (opt == 1)
		{
			SearchBookStudent();
		}
		else if (opt == 2)
		{
			StudentMenu();
		}
		else
		{
			cout << "\n\t\t\t\t Invalid Option. Please Input Correct Option ";
			goto we7;
		}
	}
}

void SearchBookStudent()
{
	string searchISBN;
	int c;
	cout << "\n\t\t\t\t Do You Want to Search By ISBN or Book Title?\n\n\t\t\t\t 1. Book Name \n\n\t\t\t\t 2. ISBN Number ";
	cout << "\n\n\t\t\t\t Enter your Choice: ";
	cin >> c;
	if (c != 1 && c != 2)
	{
		cout << "\n\t\t\t\t Invalid Option. Please Input Correct Option ";
		SearchBookStudent();
	}
	if (c == 1)
	{
		StudentSearchByName();
	}
	if (c == 2)
	{
		StudentSearchByISBN();
	}
}

void BookList()
{
	int k = 1;
	DIR* dr;
	struct dirent* en;
	dr = opendir("Book Files/.");
	if (dr)
	{

		cout << "\n\t\t\t\t ******************* BOOKLIST ******************\n";
		while ((en = readdir(dr)) != NULL)
		{
			cout << "\t\t\t\t";
			for (int i = 0; en->d_name[i] != '.'; i++)
			{
				cout << en->d_name[i];
			}
			cout << endl << endl;
			k++;
		}
		closedir(dr);
	}
we2:
	cout << "\n\t\t\t\t Do You Want to return to Main Menu or Student Menu? " << "\n\n\t\t\t\t 1. Main Menu \n\n\t\t\t\t 2. Student Menu " << endl;
	cout << "\n\t\t\t\t Enter your Choice: ";
	cin >> opt;
	cout << endl;
	if (opt == 1)
	{
		MainMenu();
	}
	else if (opt == 2)
	{
		StudentMenu();
	}
	else
	{
		cout << "\n\t\t\t\t Invalid Option. Please Input Correct Option ";
		goto we2;
	}
}

void StudentMenu()
{
	int i = 0;
	cout << "\n\t\t\t\t *************** WELCOME STUDENT ***************\n";
	cout << "\n\t\t\t\t Please Choose One Option:\n";
	cout << "\n\t\t\t\t 1. View BookList \n\n\t\t\t\t 2. Search to Lend/Issue a Book\n\n\t\t\t\t 3. Return an Issued Book \n\n\t\t\t\t 4. Main Menu \n\n\t\t\t\t 5. Exit Program\n";
	while (i != 1 && i != 2 && i != 3 && i != 4)
	{
		cout << "\n\t\t\t\t Enter your Choice: ";
		cin >> i;
		cout << endl;

		if (i != 1 && i != 2 && i != 3 && i != 4)
		{
			cout << "\n\t\t\t\t Please Enter Correct Option :(\n\t\t\t\t Press any key to Continue...\n";
			_getch();

		}
		else if (i == 1)
		{
			BookList();
		}
		else if (i == 2)
		{
			SearchBookStudent();
		}
		else if (i == 3)
		{
			ReturnBook();
		}
		else if (i == 4)
		{
			MainMenu();
			break;
		}
		else if (i == 5)
		{
			exit(0);
		}
	}
}

void LoginAdmin()
{
	string EnterAdminUsername;
	string EnterAdminPassword;
	string AdminUsername = "admin";
	string AdminPassword = "pass";
	int flag = false;
	bool flag1 = false;
	//Admin Username
	cout << "\t\t\t\t Enter Admin Username: ";
hello:
	cin >> EnterAdminUsername;
	if (AdminUsername.length() != EnterAdminUsername.length())
	{
		cout << "\t\t\t\t Invalid Username" << endl;
		cout << "\t\t\t\t Enter Admin Username again: ";
		goto hello;
	}
	else
	{
		int i = 0;
		while (EnterAdminUsername[i] != '\0')
		{
			if (EnterAdminUsername[i] == AdminUsername[i])
			{
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}
			i++;
		}
	}
	if (flag == false)
	{
		cout << "\t\t\t\t Invalid Username" << endl;
		cout << "\t\t\t\t Enter Admin Username again: ";
		goto hello;
	}

	//Admin Password
	else
	{
		cout << "\t\t\t\t Enter Admin Password: ";
	hello1:
		cin >> EnterAdminPassword;
		if (AdminPassword.length() != EnterAdminPassword.length())
		{
			cout << "\t\t\t\t Invalid Password" << endl;
			cout << "\t\t\t\t Enter Admin Password again: ";
			goto hello1;
		}

		else
		{
			int i = 0;
			while (AdminPassword[i] != '\0')
			{
				if (EnterAdminPassword[i] == AdminPassword[i])
				{
					flag1 = true;
					cout << endl;
					cout << "\t\t\t\t You are successfully Logged In \n" << endl;
					AdminMenu();
				}
				else
				{
					flag1 = false;
					break;
				}
				i++;
			}
			if (flag1 == false)
			{
				cout << "\n\t\t\t\t Invalid Password" << endl;
				cout << "\t\t\t\t Enter Admin Password again: ";
				goto hello1;
			}
		}
	}
}

string EnterStudentUsername;
int counter;
void Counter(string str)
{
	string Newfile, user;
	ifstream fin1;
	Newfile = str + ".txt";
	fin1.open(Newfile.c_str());
	if (fin1.fail())
	{
		counter++;
		fin1.close();
		return;
	}
	else
	{
		cout << endl << "\t\t\t\t This Username already exists. Please Try Again." << endl;
		fin1.close();
		return;
	}
}

void LoginStudent()
{
	int choice, i = 0, exit = 0;
	string ans, EnterStudentPassword, Filename, NewUsername, NewPassword, line, nusn;
	ofstream fout;
	ifstream fin;
	do
	{
		cout << "\t\t\t\t Do you want to Login or Sign Up " << endl << endl;
		cout << "\t\t\t\t 1. Login \n\n\t\t\t\t 2. Sign Up " << endl;
		cout << "\n\t\t\t\t Enter your Choice: ";
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{

			exit = 1;
			cout << "\t\t\t\t Enter your Username: ";
			cin >> EnterStudentUsername;
			cout << "\t\t\t\t Enter your Password: ";
			cin >> EnterStudentPassword;
			cout << endl;
			Filename = EnterStudentUsername + ".txt";
			fin.open(Filename.c_str());
			if (fin.fail())
			{
				cout << "\n\t\t\t\t You are not Registered, Kindly register before Logging In. \n" << endl;
				fin.close();
				exit = 0;
				continue;
			}
			getline(fin, NewUsername);
			getline(fin, NewPassword);
			if (EnterStudentUsername == NewUsername && EnterStudentPassword == NewPassword)
			{
				StudentMenu();
			}
			else
			{
				cout << "\n\t\t\t\t Wrong Username or Password! Try Again.\n" << endl;
			}
			cout << endl;
		}
		else if (choice == 2)
		{
			cout << "\t\t\t\t Create a Username: ";
			cin >> NewUsername;
			counter = 0;
		ee:
			Counter(NewUsername);
			if (counter == 0)
			{
				cout << "\t\t\t\t Enter Username again: ";
				cin >> NewUsername;
				goto ee;
			}
			else
			{
				cout << "\t\t\t\t Create a Password: ";
				cin >> NewPassword;
				Filename = NewUsername + ".txt";
				fout.open(Filename.c_str());
				fout << NewUsername << endl << NewPassword << endl;
				cout << "\n\t\t\t\t You are successfully registered:) \n" << endl;
				cout << endl;
				cin.ignore();
				fout.close();
			}
		}
		else
		{
			cout << "\n\t\t\t\t Wrong Input. Kindly Give Correct Input.";
			exit = 0;
		}
	} while (exit == 0);
}

void MainMenu()
{

	int key = 0;
	cout << "\n\t\t\t\t      Press any key to proceed to the Main Menu\n";
	_getch();
	cout << endl;
	cout << "\t\t\t\t ******************* MAIN MENU *******************\n";

	while (key != 1 && key != 2 && key != 3)
	{
		cout << "\n\t\t\t\t\t 1. Student\n\n\t\t\t\t\t 2. Librarian \n\n\t\t\t\t\t 3. Exit program\n\n ";
		cout << "\t\t\t\t        Enter your Choice: ";
		cin >> key;
		cout << endl;
		if (key == 1)
		{
			LoginStudent();
		}
		if (key == 2)
		{
			LoginAdmin();
		}
		if (key == 3)


		{
			cout << "\t\t\t\t Program terminated! We hope you had a Wonderful Experience.\n\n\n";
			exit(0);
		}
	}
}

int main()
{
	cout << "\t\t\t\t   ******************** Hello *******************    \n\t\t\t\t" << endl;
	cout << "\t\t\t\t\tWelcome to Library Management System!\n";
	cout << endl;
	MainMenu();
}