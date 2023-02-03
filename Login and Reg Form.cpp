#include<bits/stdc++.h>
using namespace std;

/*
    """
    created on Fri Feb 3 16:10:00 2023
    @author:Abdallah Gaber
    """

    #in this project we will create a login and registration for.
    this form will consist of:
    1- Login
    2- Registration
    3- Forget Password
    4- Exit

    # we will ask the user to choose one of the previous options
        and we will go on the project depending on the option.
*/

void login();
void registration();
void forget();
int main()
{

    /*
        # at first we will create the general shape of the form
    */
    cout<<"\t\t\t ______________________________________________________\n\n";
    cout<<"\t\t\t                 Welcome to Login Page                  \n\n";
    cout<<"\t\t\t ______________        MENU      _______________________\n";
    cout<<"                                                               \n";
    cout<<"\t\t\t| Press 1 to Login in                    |"<<endl;
    cout<<"\t\t\t| Press 2 to Registration                |"<<endl;
    cout<<"\t\t\t| Press 3 if you forget the password     |"<<endl;
    cout<<"\t\t\t| Press 4 to Exit                        |"<<endl;

    // accepting the user choice
    int choice;
    cout<<"\n\t\t\tEnter Your Choice : ";
    cin>>choice;
    cout<<endl;

    /*
        #secondly we the switch statement to response on the user choice
    */
    switch(choice){
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forget();
        break;
    case 4:
        cout<<"\t\t\t thank you!\n";
        break;
    default:
        system("cls");   // to clear the screen and reprint the next things
        cout<<"\t\t\t please choose an option from the above\n";
        main();
    }
}

    /*
        #thirdly we create the functions
    */
    // here we ask the user to enter the usreName and password and we make a check on them
    // we have a file full of userNames and Passwords
    void login(){
        system("cls");        // to clear the previous menu
        string userName , password, name, pass;
        cout<<"\t\t\t Enter the User Name and Password , Please!\n";
        cout<<"\t\t\t the USERNAME: ";
        cin>>userName;
        cout<<"\t\t\t The PASSWORD: ";
        cin>>password;

        // Now we will make a check if the userName and password in our records file
        ifstream file_data("Login_data.txt");  // ifstream is to read data from a file
        int counter = 0; //  flag
        while(file_data>>name>>pass){ // this means if the id and pass exist in the file
            if(name == userName && pass == password){
                counter = 1;
                system("cls");
            }
        file_data.close();

        if(counter == 1){
            cout<<"\t\t\t"<<userName<<"\n\t\t\tYour LOGIN is Successful\n";
            cout<<"\t\t\tThanks for Logging in \n";
            main();
        }else{
            system("cls");
            cout<<"\n\t\t\t LOGIN ERROR \n\t\t\t Check Your Name and Password";
            main();
        }
    }
}
    // now we will create the registration function
    void registration(){
        string reg_userName , reg_password,name,pass;
        system("cls");
        cout<<"\n\t\t\t Welcome to the Registration Page\n";
        cout<<"\t\t\t Enter the USERNAME :";
        cin>>reg_userName;
        cout<<"\t\t\t Enter the PASSWORD :";
        cin>>reg_password;

        ofstream file_data("Login_data.txt", ios::app);  // ofstream is to enter data to a file
        file_data<<reg_userName<<" "<<reg_password;
        system("cls");
        cout<<"\n\t\t\t Registration Successful\n";
        main();
    }

    void forget(){
        system("cls");
        int option;
        cout<<"\n\t\t\t You forget your password?! Don't Worry\n";
        cout<<"\t\t\t Press 1 to search your account by name\n";
        cout<<"\t\t\t Press 2 to back to the main menu\n";
        cout<<"\t\t\t Enter Your Choice :";
        cin>>option;

        switch(option){

        case 1:
            {
                int counter =0;
                string userName , name , pass;
                cout<<"\t\t\t Enter the Name you remember: ";
                cin>>userName;

                ifstream file_data("Login_data.txt");
                while(file_data>>name>>pass){
                    if(userName == name){
                        counter =1;

                    }
                }
                file_data.close();
                if(counter == 1){
                    cout<<"\t\t\t Your Account is Found \n";
                    cout<<"\t\t\t Your Password is: "<<pass<<endl;
                    main();
                }else{
                    cout<<"\t\t\t Your Account is not Found \n";
                }
            }
            break;
        case 2:
            main();
            break;
        default:
            cout<<"\t\t\t Wrong Choice! , Try Again\n";
            forget();
        }
    }
