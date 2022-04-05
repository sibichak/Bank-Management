
//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************


class Manager      //class declaration
{
private:                        //private member for class only
                 string firstname,secondname;  //declaring string variable
                 int num=0,opt,age;            //declaring integer variable
                 int sallary,i,fireid=0;
public:
                 void menu();                  //declaring function
                 void addemp();
                 void fireemp();
                 void promoteemp();
                 void currentemp();
                 void allemp();
}emp[30];                          //declaring class variable

void Manager::menu()                    //constructor
{
        int opt;
        initiate:
        cout<<"\n************ ABC Bank ******************"<<endl;
        cout<<"1.Add employee"<<endl;
        cout<<"2.Fire employee"<<endl;
        cout<<"3.Promote employee"<<endl;
        cout<<"4.Current employee"<<endl;
        cout<<"5.All Employee(Present&Past)"<<endl;
        cout<<"6.Exit "<<endl;
        cout<<"**************************************************"<<endl;
        cout<<"Enter a option(1-6): ";
        cin>>opt;
        cout<<"\n\n"<<endl;
        sub:
        switch(opt)
        {
        case 1:
                 Manager::addemp();
                 goto initiate;
                 break;
        case 2:
                 Manager::fireemp();
                 goto initiate;
                 break;
        case 3:
                 Manager::promoteemp();
                 goto initiate;
                 break;
        case 4:
                 Manager::currentemp();
                 goto initiate;
                 break;
        case 5:
                 Manager::allemp();
                 goto initiate;
                 break;
        case 6:
                 cout<<"Thank you!!for using my application. :-)"<<endl;
                 break;
        default:
                 cout<<"Wrong input,Try again: ";
                 cin>>opt;
                 goto sub;
                 break;
        }
}

void Manager::addemp()
{
        cout<<"Enter the number of employees you want to add(30 max): ";
        cin>>num;
        cout<<"\n";
        for(i=1;i<=num;i++)                    //looping
        {
                 cout<<"Enter the First Name of the Employee "<<i<<" (No space): ";
                 cin>>emp[i].firstname;
                 cout<<"Enter the Second Name of the Employee "<<i<<" (No space): ";
                 cin>>emp[i].secondname;
                 cout<<"Enter the Age of the employee "<<i<<" (Number digit only): ";
                 cin>>emp[i].age;
                 cout<<"Enter the sallary of the employee "<<i<<" (Number digit only): ";
                 cin>>emp[i].sallary;
                 cout<<"The ID of the employee is "<<i<<".";
                 cout<<"\n"<<endl;
        }
        cout<<"Records have been saved successfully!!\n\n"<<endl;
}

void Manager::fireemp()
{
        cout<<"Enter an ID to fire employee(You can only fire one employee in every program execution): ";
        cin>>fireid;
        cout<<"\n";
        con:
        if((fireid>1)&&(fireid<num))   //condition
{
        cout<<"The Employee(ID: "<<fireid<<") has been fired from job\n\n"<<endl;
        cout<<"\n**************Updated Employee List******************"<<endl;
        cout<<"NAME \t\t"<<" ID \t\t"<<" AGE \t\t"<<" Sallary"<<endl;
        for(i=1;i<fireid;i++)
        {
                 cout<<emp[i].firstname<<" "<<emp[i].secondname<<"\t\t"<<i<<"\t\t"<<emp[i].age<<"\t\t"<<emp[i].sallary<<endl;
        }

        for(i=fireid+1;i<=num;i++)
        {
                 cout<<emp[i].firstname<<" "<<emp[i].secondname<<"\t\t"<<i<<"\t\t"<<emp[i].age<<"\t\t"<<emp[i].sallary<<endl;
        }

        cout<<"\n"<<endl;
}
        else if(fireid==1)
        {
                 cout<<"The Employee(ID: "<<fireid<<") has been fired from job\n\n"<<endl;
                 cout<<"\n**************Updated Employee List******************"<<endl;
                 cout<<"NAME \t\t"<<" AGE \t\t"<<" Sallary"<<endl;
                 for(i=2;i<=num;i++)
                 {
                          cout<<emp[i].firstname<<" "<<emp[i].secondname<<"\t\t"<<i<<"\t\t"<<emp[i].age<<"\t\t"<<emp[i].sallary<<endl;
                 }
                 cout<<"\n"<<endl;
        }

        else if(fireid==num)
        {
                 cout<<"The Employee(ID: "<<fireid<<") has been fired from job\n\n"<<endl;
                 cout<<"\n**************Updated Employee List******************"<<endl;
                 cout<<"NAME \t\t"<<" AGE \t\t"<<" Sallary"<<endl;
                 for(i=1;i<num;i++)
                 {
                          cout<<emp[i].firstname<<" "<<emp[i].secondname<<"\t\t"<<i<<"\t\t"<<emp[i].age<<"\t\t"<<emp[i].sallary<<endl;
                 }
                 cout<<"\n"<<endl;
        }
        else
        {
                 cout<<"Wrong input,Try again: ";
                 cin>>fireid;
                 goto con;
        }

}

void Manager::promoteemp()
{
        int id,amnt=0;
        cout<<"Enter an ID to promote employee:  ";
        cin>>id;
        cout<<"\n"<<endl;
        cout<<"Enter the amount to be increased:  ";
        cin>>amnt;
        cout<<"\n"<<endl;
        for(i=id;i<=id;i++)
        {
                 emp[i].sallary=emp[i].sallary+amnt;
                 cout<<"The Employee(id:"<<id<<") is promoted to sallary: "<<emp[i].sallary<<" .Congratulations!!\n"<<endl;
        }
}

void Manager::currentemp()
{
        cout<<"\n**************Current Employee******************"<<endl;
        cout<<"NAME\t\t"<<" ID\t\t"<<" AGE \t\t"<<" Sallary"<<endl;
        if((fireid>1)&&(fireid<num))
{
        for(i=1;i<fireid;i++)
        {
                 cout<<emp[i].firstname<<" "<<emp[i].secondname<<"\t\t"<<i<<"\t\t"<<emp[i].age<<"\t\t"<<emp[i].sallary<<endl;
        }

        for(i=fireid+1;i<=num;i++)
        {
                 cout<<emp[i].firstname<<" "<<emp[i].secondname<<"\t\t"<<i<<"\t\t"<<emp[i].age<<"\t\t"<<emp[i].sallary<<endl;
        }

        cout<<"\n"<<endl;
}
        else if(fireid==1)
        {
                 for(i=2;i<=num;i++)
                 {
                          cout<<emp[i].firstname<<" "<<emp[i].secondname<<"\t\t"<<i<<"\t\t"<<emp[i].age<<"\t\t"<<emp[i].sallary<<endl;
                 }
                 cout<<"\n"<<endl;
        }

        else if(fireid==num)
        {
                 for(i=1;i<num;i++)
                 {
                          cout<<emp[i].firstname<<" "<<emp[i].secondname<<"\t\t"<<i<<"\t\t"<<emp[i].age<<"\t\t"<<emp[i].sallary<<endl;
                 }
                 cout<<"\n"<<endl;
        }

        else if(fireid==0)
        {
                 for(i=1;i<=num;i++)
                 {
                          cout<<emp[i].firstname<<" "<<emp[i].secondname<<"\t\t"<<i<<"\t\t"<<emp[i].age<<"\t\t"<<emp[i].sallary<<endl;
                 }
                 cout<<"\n"<<endl;
        }

}

void Manager::allemp()
{
        cout<<"********************All Employee***********************"<<endl;
        cout<<"*       Name          |   ID   |   Age    |  Sallary  *"<<endl;
        cout<<"*******************************************************\n"<<endl;
for(i=1;i<=num;i++)
{
        cout<<i<<". "<<emp[i].firstname<<"  "<<emp[i].secondname<<"     "<< i <<"      "<<emp[i].age<<"      "<<emp[i].sallary<<endl;
        cout<<"\n"<<endl;
}
}

class bank             //account
{
        int acno;
        char name[50];
        int deposit;
        char type;
public:
        void menus();
        void create_account();  //function to get data from user
        void show_account() const;      //function to show data on screen
        void modify();  //function to add new data
        void dep(int);  //function to accept amount and add to balance amount
        void draw(int); //function to accept amount and subtract from balance amount
        void report() const;    //function to show data in tabular format
        int retacno() const;    //function to return account number
        int retdeposit() const; //function to return balance amount
        char rettype() const;   //function to return type of account
        void write_account();
        void display_sp(int n);
        void modify_account(int n);
        void delete_account(int n);
        void display_all();
        void deposit_withdraw(int n, int option);
        void intro();

};         //class ends here
//***************************************************************
//      function to write in file
//****************************************************************

void bank::write_account()
{
        bank ac;
        ofstream outFile;
        outFile.open("account.dat",ios::binary|ios::app);
        ac.create_account();
        outFile.write(reinterpret_cast<char *> (&ac), sizeof(bank));
        outFile.close();
}

//***************************************************************
//      function to read specific record from file
//****************************************************************

void bank::display_sp(int n)
{
        bank ac;
        bool flag=false;
        ifstream inFile;
        inFile.open("account.dat",ios::binary);
        if(!inFile)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        cout<<"\nBALANCE DETAILS\n";

        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(bank)))
        {
                if(ac.retacno()==n)
                {
                        ac.show_account();
                        flag=true;
                }
        }
        inFile.close();
        if(flag==false)
                cout<<"\n\nAccount number does not exist";
}


//***************************************************************
//      function to modify record of file
//****************************************************************

void bank::modify_account(int n)
{
        bool found=false;
        bank ac;
        fstream File;
        File.open("account.dat",ios::binary|ios::in|ios::out);
        if(!File)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(bank));
                if(ac.retacno()==n)
                {
                        ac.show_account();
                        cout<<"\n\nEnter The New Details of account"<<endl;
                        ac.modify();
                        int pos=(-1)*static_cast<int>(sizeof(bank));
                        File.seekp(pos,ios::cur);
                        File.write(reinterpret_cast<char *> (&ac), sizeof(bank));
                        cout<<"\n\n\t Record Updated";
                        found=true;
                  }
        }
        File.close();
        if(found==false)
                cout<<"\n\n Record Not Found ";
}

//***************************************************************
//      function to delete record of file
//****************************************************************


void bank::delete_account(int n)
{
        bank ac;
        ifstream inFile;
        ofstream outFile;
        inFile.open("account.dat",ios::binary);
        if(!inFile)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        outFile.open("Temp.dat",ios::binary);
        inFile.seekg(0,ios::beg);
        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(bank)))
        {
                if(ac.retacno()!=n)
                {
                        outFile.write(reinterpret_cast<char *> (&ac), sizeof(bank));
                }
        }
        inFile.close();
        outFile.close();
        remove("account.dat");
        rename("Temp.dat","account.dat");
        cout<<"\n\n\tRecord Deleted ..";
}

//***************************************************************
//      function to display all accounts deposit list
//****************************************************************

void bank::display_all()
{
        bank ac;
        ifstream inFile;
        inFile.open("account.dat",ios::binary);
        if(!inFile)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
        cout<<"====================================================\n";
        cout<<"A/c no.      NAME           Type  Balance\n";
        cout<<"====================================================\n";
        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(bank)))
        {
                ac.report();
        }
        inFile.close();
}

//***************************************************************
//      function to deposit and withdraw amounts
//****************************************************************

void bank::deposit_withdraw(int n, int option)
{
        int amt;
        bool found=false;
        bank ac;
        fstream File;
        File.open("account.dat", ios::binary|ios::in|ios::out);
        if(!File)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(bank));
                if(ac.retacno()==n)
                {
                        ac.show_account();
                        if(option==1)
                        {
                                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
                                cout<<"\n\nEnter The amount to be deposited";
                                cin>>amt;
                                ac.dep(amt);
                        }
                        if(option==2)
                        {
                                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
                                cout<<"\n\nEnter The amount to be withdraw";
                                cin>>amt;
                                int bal=ac.retdeposit()-amt;
                                if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
                                        cout<<"Insufficience balance";
                                else
                                        ac.draw(amt);
                        }
                        int pos=(-1)*static_cast<int>(sizeof(ac));
                        File.seekp(pos,ios::cur);
                        File.write(reinterpret_cast<char *> (&ac), sizeof(bank));
                        cout<<"\n\n\t Record Updated";
                        found=true;
               }
         }
        File.close();
        if(found==false)
                cout<<"\n\n Record Not Found ";
}


//***************************************************************
//      INTRODUCTION FUNCTION
//****************************************************************


void bank::intro()
{
        cout<<"\n\n\n\t  BANK";
        cout<<"\n\n\tMANAGEMENT";
        cout<<"\n\n\t  SYSTEM";
        cout<<"\n\n\n\nMADE BY : your name";
        cout<<"\n\nSCHOOL : your school name";
        cin.get();
}
//*****************************************************************
void bank::menus()                    //constructor
{
        char ch;
        int num;
        //intro();
        do
        {
//                system("cls");

                cout<<"\n\n\t01. NEW ACCOUNT";
                cout<<"\n\n\t02. DEPOSIT AMOUNT";
                cout<<"\n\n\t03. WITHDRAW AMOUNT";
                cout<<"\n\n\t04. BALANCE ENQUIRY";
                cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
                cout<<"\n\n\t06. CLOSE AN ACCOUNT";
                cout<<"\n\n\t07. MODIFY AN ACCOUNT";
                cout<<"\n\n\t08. EXIT";
                cout<<"\n\n\tSelect Your Option (1-8) ";
                cin>>ch;
//                system("cls");
                switch(ch)
                {
                case '1':
                        write_account();
                        break;
                case '2':
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        deposit_withdraw(num, 1);
                        break;
                case '3':
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        deposit_withdraw(num, 2);
                        break;
                case '4':
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        display_sp(num);
                        break;
                case '5':
                        display_all();
                        break;
                case '6':
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        delete_account(num);
                        break;
                 case '7':
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        modify_account(num);
                        break;
                 case '8':
                        cout<<"\n\n\tThanks for using bank managemnt system";
                        break;
                 default :cout<<"\a";
                }
                cin.ignore();
                cin.get();
        }while(ch!='8');
       // return 0;
}

void bank::create_account()
{
        cout<<"\nEnter The account No. :";
        cin>>acno;
        cout<<"\n\nEnter The Name of The account Holder : ";
        cin.ignore();
        cin.getline(name,50);
        cout<<"\nEnter Type of The account (C/S) : ";
        cin>>type;
        type=toupper(type);
        cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
        cin>>deposit;
        cout<<"\n\n\nAccount Created..";
}

void bank::show_account() const
{
        cout<<"\nAccount No. : "<<acno;
        cout<<"\nAccount Holder Name : ";
        cout<<name;
        cout<<"\nType of Account : "<<type;
        cout<<"\nBalance amount : "<<deposit;
}


void bank::modify()
{
        cout<<"\nAccount No. : "<<acno;
        cout<<"\nModify Account Holder Name : ";
        cin.ignore();
        cin.getline(name,50);
        cout<<"\nModify Type of Account : ";
        cin>>type;
        type=toupper(type);
        cout<<"\nModify Balance amount : ";
        cin>>deposit;
}


void bank::dep(int x)
{
        deposit+=x;
}

void bank::draw(int x)
{
        deposit-=x;
}

void bank::report() const
{
        cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}


int bank::retacno() const
{
        return acno;
}

int bank::retdeposit() const
{
        return deposit;
}

char bank::rettype() const
{
        return type;
}


//***************************************************************
//      function declaration
//****************************************************************
void write_account();   //function to write record in binary file
void display_sp(int);   //function to display account details given by user
void modify_account(int);       //function to modify record of file
void delete_account(int);       //function to delete record of file
void display_all();             //function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();   //introductory screen function





//***************************************************************
//      function to write in file
//****************************************************************

void write_account()
{
        bank ac;
        ofstream outFile;
        outFile.open("account.dat",ios::binary|ios::app);
        ac.create_account();
        outFile.write(reinterpret_cast<char *> (&ac), sizeof(bank));
        outFile.close();
}

//***************************************************************
//      function to read specific record from file
//****************************************************************

void display_sp(int n)
{
        bank ac;
        bool flag=false;
        ifstream inFile;
        inFile.open("account.dat",ios::binary);
        if(!inFile)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        cout<<"\nBALANCE DETAILS\n";

        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(bank)))
        {
                if(ac.retacno()==n)
                {
                        ac.show_account();
                        flag=true;
                }
        }
        inFile.close();
        if(flag==false)
                cout<<"\n\nAccount number does not exist";
}


//***************************************************************
//      function to modify record of file
//****************************************************************

void modify_account(int n)
{
        bool found=false;
        bank ac;
        fstream File;
        File.open("account.dat",ios::binary|ios::in|ios::out);
        if(!File)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(bank));
                if(ac.retacno()==n)
                {
                        ac.show_account();
                        cout<<"\n\nEnter The New Details of account"<<endl;
                        ac.modify();
                        int pos=(-1)*static_cast<int>(sizeof(bank));
                        File.seekp(pos,ios::cur);
                        File.write(reinterpret_cast<char *> (&ac), sizeof(bank));
                        cout<<"\n\n\t Record Updated";
                        found=true;
                  }
        }
        File.close();
        if(found==false)
                cout<<"\n\n Record Not Found ";
}

//***************************************************************
//      function to delete record of file
//****************************************************************


void delete_account(int n)
{
        bank ac;
        ifstream inFile;
        ofstream outFile;
        inFile.open("account.dat",ios::binary);
        if(!inFile)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        outFile.open("Temp.dat",ios::binary);
        inFile.seekg(0,ios::beg);
        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(bank)))
        {
                if(ac.retacno()!=n)
                {
                        outFile.write(reinterpret_cast<char *> (&ac), sizeof(bank));
                }
        }
        inFile.close();
        outFile.close();
        remove("account.dat");
        rename("Temp.dat","account.dat");
        cout<<"\n\n\tRecord Deleted ..";
}

//***************************************************************
//      function to display all accounts deposit list
//****************************************************************

void display_all()
{
        bank ac;
        ifstream inFile;
        inFile.open("account.dat",ios::binary);
        if(!inFile)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
        cout<<"====================================================\n";
        cout<<"A/c no.      NAME           Type  Balance\n";
        cout<<"====================================================\n";
        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(bank)))
        {
                ac.report();
        }
        inFile.close();
}

//***************************************************************
//      function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int option)
{
        int amt;
        bool found=false;
        bank ac;
        fstream File;
        File.open("account.dat", ios::binary|ios::in|ios::out);
        if(!File)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(bank));
                if(ac.retacno()==n)
                {
                        ac.show_account();
                        if(option==1)
                        {
                                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
                                cout<<"\n\nEnter The amount to be deposited";
                                cin>>amt;
                                ac.dep(amt);
                        }
                        if(option==2)
                        {
                                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
                                cout<<"\n\nEnter The amount to be withdraw";
                                cin>>amt;
                                int bal=ac.retdeposit()-amt;
                                if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
                                        cout<<"Insufficience balance";
                                else
                                        ac.draw(amt);
                        }
                        int pos=(-1)*static_cast<int>(sizeof(ac));
                        File.seekp(pos,ios::cur);
                        File.write(reinterpret_cast<char *> (&ac), sizeof(bank));
                        cout<<"\n\n\t Record Updated";
                        found=true;
               }
         }
        File.close();
        if(found==false)
                cout<<"\n\n Record Not Found ";
}


//***************************************************************
//      INTRODUCTION FUNCTION
//****************************************************************


void intro()
{
        cout<<"\n\n\n\t  BANK";
        cout<<"\n\n\tMANAGEMENT";
        cout<<"\n\n\t  SYSTEM";
        cout<<"\n\n\n\nMADE BY : Sibi Ravichandran";
        cin.get();
}

//***************************************************************
//      INTRODUCTION FUNCTION
//****************************************************************


int main()
{
  char x;
  int y;
  intro();
  Manager sun; //(sun is object)
  bank moon;   // (moon is object)
  do
        {
//                system("cls");
                cout<<"\n\n\n\tMAIN MENU";
                cout<<"\n\n\t01. MANAGER";
                cout<<"\n\n\t02. STAFF";
                cout<<"\n\n\t03. EXIT";
                cout<<"\n\n\tSelect Your Option (1-3) ";
                cin>>x;
//                system("cls");
                switch(x)
                {
                case '1':
                        cout << "Welcome Manager\n";
                        sun.menu();
                        break;
                case '2':
                        cout << "Welcome Staff\n";
                        moon.menus();
                        break;
                 case '3':
                        cout<<"\n\n\tThanks for using bank managemnt system";
                        break;
                 default :cout<<"\a";
                }
                cin.ignore();
                cin.get();
        }while(x!='3');
        return 0;     // 1 manager class

        //manager obj;    //class object declaration
        //obj.menu(); //class function execution
        //return 0;


        // 2 bank main
        char ch;
        int num;
        intro();
        do
        {
//                system("cls");

                cout<<"\n\n\t01. NEW ACCOUNT";
                cout<<"\n\n\t02. DEPOSIT AMOUNT";
                cout<<"\n\n\t03. WITHDRAW AMOUNT";
                cout<<"\n\n\t04. BALANCE ENQUIRY";
                cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
                cout<<"\n\n\t06. CLOSE AN ACCOUNT";
                cout<<"\n\n\t07. MODIFY AN ACCOUNT";
                cout<<"\n\n\t08. EXIT";
                cout<<"\n\n\tSelect Your Option (1-8) ";
                cin>>ch;
//                system("cls");
                switch(ch)
                {
                case '1':
                        write_account();
                        break;
                case '2':
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        deposit_withdraw(num, 1);
                        break;
                case '3':
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        deposit_withdraw(num, 2);
                        break;
                case '4':
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        display_sp(num);
                        break;
                case '5':
                        display_all();
                        break;
                case '6':
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        delete_account(num);
                        break;
                 case '7':
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        modify_account(num);
                        break;
                 case '8':
                        cout<<"\n\n\tThanks for using bank managemnt system";
                        break;
                 default :cout<<"\a";
                }
                cin.ignore();
                cin.get();
        }while(ch!='8');
        return 0;
}

//***************************************************************
//                      END OF PROJECT
//***************************************************************


