#include <iostream>  // For basic I/O
#include <string>    // Includes the string class
#include <cstdlib>   // For various library functions
#include <iomanip>   // For manipulating output
#include <fstream>   // For writing to files

using namespace std;

//*********  Structure and Class Definitions  *********
struct items
{
    string first_name;
    string last_name;

    string record_number;

    string first_grade;
    string second_grade;
    string third_grade;
    string fourth_grade;
    string fifth_grade;
    string sixth_grade;

    items *next;
};// End of struct items

//*****  End of Structure and Class Definitions  ******
//**************  Function Prototypes  ****************
void title_screen();
void menu_screen(items* start);
items* pop_list();
void input_screen(items* p);
void error_screen();
void transition();
void disp_table(items* start);
void prn_display(items* start);
//void s_s_menu(items* start);
void search(items* start);
items* output_screen(items* i);
void prn_output(items* p, double average, char letter);
items* load_file();
void save_to_file(items* p);
items* edit_screen(items* p);
//void sort(items i_arr[], int num_entry);
void exit_screen();


//**************   End of Prototypes   ****************

int main()
{
    items* start = NULL;

    //**********  Start Splash Screen  ************
    title_screen();

    //***********  End Splash Screen   ************
    //***********  Start Menu Screen  *************
    menu_screen(start);

    //***********  End Menu Screen  ***************
    return 0;
}// End of int main()

//-----------------------------------------

void title_screen()
{
    cout << endl << endl;
    cout << "          ____________________________________________________________" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |       M I R A M A R   C O L L E G E   S T U D E N T      |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                G R A D I N G   S Y S T E M               |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                  Programmer: Zayn Ashraf                 |" << endl;
    cout << "          |                      Date: 05-22-24                      |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          ------------------------------------------------------------" << endl;
    cout << "                                       ||                             " << endl;
    cout << "                                       ||                             " << endl;
    cout << "                                     ------                           " << endl;
    cout << endl << endl << endl << endl << endl;
    transition();
}// End of void title_screen()

//-----------------------------------------

void menu_screen(items* start)
{
    string resp = "XXX"; // User response for menu

    do
    {
        system("cls");
        cout << endl;
        cout << "                     MIRAMAR COLLEGE STUDENT GRADING SYSTEM" << endl << endl << endl;
        cout << "                                 |-----------|" << endl;
        cout << "                                 | MAIN MENU |" << endl;
        cout << "                                 |-----------|" << endl;
        cout << endl << endl;
        cout << "             *I* nput" << endl;
        cout << "             *D* isplay Table" << endl;
        cout << "             *S* earch" << endl;
        cout << "             *L* oad File" << endl;
        cout << "             Save to *F* ile" << endl;
        cout << "             *E* xit" << endl << endl;
        cout << "                           Enter I, D, S, L, F, or E: "; getline(cin, resp);
        if(resp.empty()) resp = "XXX";

        switch(resp.at(0))
        {
            case 'I':
            case 'i':
                start = pop_list();
                break;
            case 'D':
            case 'd':
                disp_table(start);
                break;
            case 'S':
            case 's':
                search(start);
                break;
            case 'L':
            case 'l':
                start = load_file();
                break;
            case 'F':
            case 'f':
                save_to_file(start);
                break;
            case 'E':
            case 'e':
                exit_screen();
                break;
            default:
                cout << endl << "             ERROR - Wrong input. Press <ENTER> to try again ";
                cin.get();


        }// End of switch(resp.at(0))
    }while(toupper(resp.at(0)) != 'E');
}// End of void menu_screen(items* start)

//-----------------------------------------

items* pop_list()
{
    system("cls");

    items* list = NULL;
    items* p = new items;
    items* q = NULL;
    string resp = "XXX";

    cout << endl << endl << endl;
    cout << "                 M I R A M A R   C O L L E G E   S T U D E N T      " << endl;
    cout << "                                                                    " << endl;
    cout << "                          G R A D I N G   S Y S T E M               " << endl;
    cout << endl << endl << endl << endl << endl << endl << endl;
    cout << "Enter a data record (Y/N): "; getline(cin, resp);
    if(resp.empty()) resp = "XXX";

    if(toupper(resp.at(0)) == 'Y')
    {
        list = p;

        //input data
        input_screen(p);

        cout << endl << endl << endl;
        cout << "                 M I R A M A R   C O L L E G E   S T U D E N T      " << endl;
        cout << "                                                                    " << endl;
        cout << "                          G R A D I N G   S Y S T E M               " << endl;
        cout << endl << endl << endl << endl << endl << endl << endl;
        cout << "Enter a data record (Y/N): "; getline(cin, resp);
        if(resp.empty()) resp = "XXX";
    }

    while(toupper(resp.at(0)) == 'Y')
    {
        q = new items;

        //input data
        input_screen(q);

        p->next = q;
        p = p->next;

        cout << endl << endl << endl;
        cout << "                 M I R A M A R   C O L L E G E   S T U D E N T      " << endl;
        cout << "                                                                    " << endl;
        cout << "                          G R A D I N G   S Y S T E M               " << endl;
        cout << endl << endl << endl << endl << endl << endl << endl;
        cout << "Enter a data record (Y/N): "; getline(cin, resp);
        if(resp.empty()) resp = "XXX";
    }// End of while(toupper(resp.at(0)) == 'Y')

    return list;
}// End of items* pop_list()

//-----------------------------------------

void input_screen(items* p)
{
    system("cls");

    cout << endl;
    cout << "                     MIRAMAR COLLEGE STUDENT GRADING SYSTEM" << endl;
    cout << endl;
    cout << "                                DATA INPUT SCREEN" << endl;
    cout << endl << endl;
    cout << "                          Enter Data and Press <ENTER>" << endl;
    cout << endl << endl;


    cout << "             First Name:  "; getline(cin, p->first_name);
    if(p->first_name.empty()) p->first_name = "XXX";


    cout << "             Last Name:  "; getline(cin, p->last_name);
    cout << endl;
    if(p->last_name.empty()) p->last_name = "XXX";


    cout << "             Record Number:  "; getline(cin, p->record_number);
    cout << endl;
    if(p->record_number.empty()) p->record_number = "XXX";


    cout << "             Grade 1:  "; getline(cin, p->first_grade);
    if(p->first_grade.empty()) p->first_grade = "XXX";
    while(p->first_grade.at(0) < '0' || p->first_grade.at(0) > '9')
    {
        error_screen();
        getline(cin, p->first_grade);
        if(p->first_grade.empty()) p->first_grade = "XXX";
        system("cls");
    }// End of while(p->first_grade.at(0) < '0' || p->first_grade.at(0) > '9')


    cout << "             Grade 2:  "; getline(cin, p->second_grade);
    if(p->second_grade.empty()) p->second_grade = "XXX";
    while(p->second_grade.at(0) < '0' || p->second_grade.at(0) > '9')
    {
        error_screen();
        getline(cin, p->second_grade);
        if(p->second_grade.empty()) p->second_grade = "XXX";
        system("cls");
    }//End of while(p->second_grade.at(0) < '0' || p->second_grade.at(0) > '9')


    cout << "             Grade 3:  "; getline(cin, p->third_grade);
    if(p->third_grade.empty()) p->third_grade = "XXX";
    while(p->third_grade.at(0) < '0' || p->third_grade.at(0) > '9')
    {
        error_screen();
        getline(cin, p->third_grade);
        if(p->third_grade.empty()) p->third_grade = "XXX";
        system("cls");
    }// End of while(p->third_grade.at(0) < '0' || p->third_grade.at(0) > '9')


    cout << "             Grade 4:  "; getline(cin, p->fourth_grade);
    if(p->fourth_grade.empty()) p->fourth_grade = "XXX";
    while(p->fourth_grade.at(0) < '0' || p->fourth_grade.at(0) > '9')
    {
        error_screen();
        getline(cin, p->fourth_grade);
        if(p->fourth_grade.empty()) p->fourth_grade = "XXX";
        system("cls");
    }// End of while(p->fourth_grade.at(0) < '0' || p->fourth_grade.at(0) > '9')


    cout << "             Grade 5:  "; getline(cin, p->fifth_grade);
    if(p->fifth_grade.empty()) p->fifth_grade = "XXX";
    while(p->fifth_grade.at(0) < '0' || p->fifth_grade.at(0) > '9')
    {
        error_screen();
        getline(cin, p->fifth_grade);
        if(p->fifth_grade.empty()) p->fifth_grade = "XXX";
        system("cls");
    }// End of while(p->fifth_grade.at(0) < '0' || p->fifth_grade.at(0) > '9')


    cout << "             Grade 6:  "; getline(cin, p->sixth_grade);
    if(p->sixth_grade.empty()) p->sixth_grade = "XXX";
    while(p->sixth_grade.at(0) < '0' || p->sixth_grade.at(0) > '9')
    {
        error_screen();
        getline(cin, p->sixth_grade);
        if(p->sixth_grade.empty()) p->sixth_grade = "XXX";
        system("cls");
    }// End of while(p->sixth_grade.at(0) < '0' || p->sixth_grade.at(0) > '9')

    p->next = NULL;

    cout << endl << endl << endl << endl;
    transition();
}// End of void input_screen(items* p)

//-----------------------------------------

void error_screen()
{
    system("cls");
    cout << endl << endl << endl << endl << endl;
    cout << "                                     UH OH!" << endl << endl;
    cout << "                       SEEMS YOU ENTERED THE WRONG VALUE!" << endl << endl << endl;
    cout << "                                 0          0" << endl;
    cout << "                                    ------" << endl;
    cout << "                                   |      |" << endl;
    cout << "                                  ----------" << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "                         Please Enter a Numeric Value: ";
}// End of void error_screen()

//-----------------------------------------

void transition()
{
    string resp = "XXX";
    cout << "                            Press <ENTER> to Continue"; getline(cin, resp);
    system("cls");
}// End of void transition()

//-----------------------------------------

void disp_table(items* start)
{
    system("cls");

    string resp = "XXX"; // User input for print option
    double total = 0.0; // Stores the combined total of grades 1-6
    double average = 0.0; // Represents the grade average
    char letter = ' '; // Letter grade (A, B, C, D, or F)

    cout << "                     MIRAMAR COLLEGE STUDENT GRADING SYSTEM" << endl;
    cout << "                               DISPLAY TABLE" << endl << endl;
    cout << setw(15) << "First Name" << "  " << setw(10) << "Last Name"
         << "  " << setw(12) << "Record Number" << "  " << setw(12) << "Grade Average"
         << "  " << setw(12) << "Letter" << endl;

    items* p = start;
    while(p != NULL)
    {
        total = stod(p->first_grade) + stod(p->second_grade) +
                stod(p->third_grade) + stod(p->fourth_grade) +
                stod(p->fifth_grade) + stod(p->sixth_grade);
        // stod function is used to convert every string into a double
        // Doubles are added together to get total
        average = total/6; // Total is divided by 6 to get average

        if(average > 89) letter = 'A';
        else if(average > 79) letter = 'B';
        else if(average > 69) letter = 'C';
        else if(average > 59) letter = 'D';
        else letter = 'F';

        cout << setw(15) << p->first_name << "  " << setw(10) << p->last_name
            << "  " << setw(12) << p->record_number << "  " << setw(12)
            << setprecision(4) << average << "  " << setw(12) << letter << endl;

        p = p->next;
    }// End of while(p != NULL)

    cout << endl << "Print this screen (Y/N): "; getline(cin, resp);
    if(resp.empty()) resp = "XXX";

    if(toupper(resp.at(0)) == 'Y') prn_display(start);


}// End of void disp_table(items* start)

//-----------------------------------------

void prn_display(items* start)
{
    ofstream ofile;
    ofile.open("table.prn");

    double total = 0.0; // Stores the combined total of grades 1-6
    double average = 0.0; // Represents the grade average
    char letter = ' '; // Letter grade (A, B, C, D, or F)

    ofile << "                     MIRAMAR COLLEGE STUDENT GRADING SYSTEM" << endl;
    ofile << "                               DISPLAY TABLE" << endl << endl;
    ofile << setw(15) << "First Name" << "  " << setw(10) << "Last Name"
         << "  " << setw(12) << "Record Number" << "  " << setw(12) << "Grade Average"
         << "  " << setw(12) << "Letter" << endl;

    items* p = start;
    while(p != NULL)
    {
        total = stod(p->first_grade) + stod(p->second_grade) +
                stod(p->third_grade) + stod(p->fourth_grade) +
                stod(p->fifth_grade) + stod(p->sixth_grade);
        // stod function is used to convert every string into a double
        // Doubles are added together to get total
        average = total/6; // Total is divided by 6 to get average

        if(average > 89) letter = 'A';
        else if(average > 79) letter = 'B';
        else if(average > 69) letter = 'C';
        else if(average > 59) letter = 'D';
        else letter = 'F';

        ofile << setw(15) << p->first_name << "  " << setw(10) << p->last_name
              << "  " << setw(12) << p->record_number << "  " << setw(12)
              << setprecision(4) << average << "  " << setw(12) << letter << endl;

        p = p->next;
    }// End of while(p != NULL)

    ofile.close();
}// End of void prn_display(items* start)

//-----------------------------------------

/*void s_s_menu(items* start)
{
    string resp = "XXX"; // User response for menu

    do
    {
        system("cls");
        cout << endl;
        cout << "                     MIRAMAR COLLEGE STUDENT GRADING SYSTEM" << endl << endl << endl;
        cout << "                                 |-----------|" << endl;
        cout << "                                 | MAIN MENU |" << endl;
        cout << "                                 |-----------|" << endl;
        cout << endl << endl;
        cout << "             *S* earch" << endl;
        cout << "             *E* xit" << endl;
        cout << "                           Enter S or E: "; getline(cin, resp);
        if(resp.empty()) resp = "XXX";

        switch(resp.at(0))
        {
            case 'S':
            case 's':
                search(start);
                break;
            case 'E':
            case 'e':
                break;
            default:
                cout << endl << "             ERROR - Wrong input. Press <ENTER> to try again ";
                cin.get();
        }
    }while(toupper(resp.at(0)) != 'E');
}// End of void s_s_menu(items* start)*/

//-----------------------------------------

void search(items* start)
{
    system("cls");
    string resp = "XXX";

    cout << endl << endl << endl;
    cout << "                 M I R A M A R   C O L L E G E   S T U D E N T      " << endl;
    cout << endl << "                          G R A D I N G   S Y S T E M               " << endl;
    cout << endl << "                        S E A R C H I N G   S C R E E N" << endl;
    cout << endl << endl << endl << endl << endl << endl;
    cout << "Enter the first name or record number to locate:  "; getline(cin, resp);
    if(resp.empty()) resp = "XXX";

    items* p = start;
    while(p != NULL && p->first_name != resp && p->record_number != resp) // Searches by first name
        // Case sensitive
    {
        p = p->next;
    }// End of while(ctr < num_entry && i_arr[ctr] != resp)

    if(p == NULL)
    {
        cout << endl << "             Item NOT found. Press <ENTER> " << cin.get();

    }
    else
    {
        p = output_screen(p);
    }
}// End of void search(items* start)

//-----------------------------------------

items* output_screen(items* p)
{
    system("cls");

    string resp = "XXX"; // User input for print option
    double total = 0.0; // Stores the combined total of grades 1-6
    double average = 0.0; // Represents the grade average
    char letter = ' '; // Letter grade (A, B, C, D, or F)

    total = stod(p->first_grade) + stod(p->second_grade) + stod(p->third_grade) +
            stod(p->fourth_grade) + stod(p->fifth_grade) + stod(p->sixth_grade);
    // stod function is used to convert every string into a double
    // Doubles are added together to get total
    average = total/6; // Total is divided by 6 to get average

    if(average > 89) letter = 'A';
    else if(average > 79) letter = 'B';
    else if(average > 69) letter = 'C';
    else if(average > 59) letter = 'D';
    else letter = 'F';

    cout << endl;
    cout << "                     MIRAMAR COLLEGE STUDENT GRADING SYSTEM" << endl << endl;
    cout << "                               DATA OUTPUT SCREEN" << endl << endl;
    cout << "             First Name-  " << p->first_name << endl;
    cout << "             Last Name-  " << p->last_name << endl;
    cout << endl;
    cout << "             Record Number-  " << p->record_number << endl;
    cout << endl;
    cout << "             Grade 1-  " << p->first_grade << endl;
    cout << "             Grade 2-  " << p->second_grade << endl;
    cout << "             Grade 3-  " << p->third_grade << endl;
    cout << "             Grade 4-  " << p->fourth_grade << endl;
    cout << "             Grade 5-  " << p->fifth_grade << endl;
    cout << "             Grade 6-  " << p->sixth_grade << endl;
    cout << endl;
    cout << "             Grade Average-  " << setprecision(4) << average << endl;
    // Round to two decimal places
    cout << "             Letter Grade-  " << letter << endl;
    cout << endl << endl;
    cout << "Print this screen (Y/N): "; getline(cin, resp);

    if(resp.empty()) resp = "XXX";
    if(toupper(resp.at(0)) == 'Y') prn_output(p, average, letter);

    cout << "Edit this screen (Y/N): "; getline(cin, resp);

    if(resp.empty()) resp = "XXX";
    if(toupper(resp.at(0)) == 'Y') p = edit_screen(p);

    return p;
}// End of items* output_screen(items* i)

//-----------------------------------------

void prn_output(items* p, double average, char letter)
{
    ofstream ofile;
    ofile.open("receipt.prn");

    ofile << endl;
    ofile << "                     MIRAMAR COLLEGE STUDENT GRADING SYSTEM" << endl;
    ofile << endl;
    ofile << "                               DATA OUTPUT SCREEN" << endl;
    ofile << endl;
    ofile << "             First Name-  " << p->first_name << endl;
    ofile << "             Last Name-  " << p->last_name << endl;
    ofile << endl;
    ofile << "             Record Number-  " << p->record_number << endl;
    ofile << endl;
    ofile << "             Grade 1-  " << p->first_grade << endl;
    ofile << "             Grade 2-  " << p->second_grade << endl;
    ofile << "             Grade 3-  " << p->third_grade << endl;
    ofile << "             Grade 4-  " << p->fourth_grade << endl;
    ofile << "             Grade 5-  " << p->fifth_grade << endl;
    ofile << "             Grade 6-  " << p->sixth_grade << endl;
    ofile << endl;
    ofile << "             Grade Average-  " << setprecision(4) << average << endl;
    // Round to two decimal places
    ofile << "             Letter Grade-  " << letter << endl;

    ofile.close();
}// End of void prn_output(items* p, double average, char letter)

//-----------------------------------------

void save_to_file(items* p)
{
    system("cls");
    cout << endl << endl << endl;
    cout << "                 M I R A M A R   C O L L E G E   S T U D E N T      " << endl;
    cout << "                                                                    " << endl;
    cout << "                          G R A D I N G   S Y S T E M               " << endl;
    cout << endl << endl << endl << endl << endl;
    cout << "Saving to file..." << endl;

    ofstream ofile;
    ofile.open("myfile.dat");

    while(p != NULL)
    {
        ofile << p->first_name << endl;
        ofile << p->last_name << endl;
        ofile << p->record_number << endl;
        ofile << p->first_grade << endl;
        ofile << p->second_grade << endl;
        ofile << p->third_grade << endl;
        ofile << p->fourth_grade << endl;
        ofile << p->fifth_grade << endl;

        if(p->next == NULL) // If statement to stop the final line in file from being blank
            ofile << p->sixth_grade;
        else
            ofile << p->sixth_grade << endl;

        p = p->next;
    }// End of while(p != NULL)
    ofile.close();

    cout << endl << endl << "Writing is complete." << endl;

    transition();
}// End of void save_to_file(items* p)

//-----------------------------------------

items* load_file()
{
    system("cls");
    cout << endl << endl << endl;
    cout << "                 M I R A M A R   C O L L E G E   S T U D E N T      " << endl;
    cout << "                                                                    " << endl;
    cout << "                          G R A D I N G   S Y S T E M               " << endl;
    cout << endl << endl << endl << endl << endl << endl << endl;
    cout << "Loading file..." << endl;

    ifstream ifile;
    ifile.open("myfile.dat");

    items* list = NULL;
    items* p = new items;
    items* q = NULL;
    char ch = 'X';

    if(!ifile.eof())
    {
        p = new items;
        getline(ifile, p->first_name);
        getline(ifile, p->last_name);
        getline(ifile, p->record_number);
        getline(ifile, p->first_grade);
        getline(ifile, p->second_grade);
        getline(ifile, p->third_grade);
        getline(ifile, p->fourth_grade);
        getline(ifile, p->fifth_grade);
        getline(ifile, p->sixth_grade);

        p->next = NULL;
        list = p;
    }

    while(!ifile.eof())
    {
        q = new items;
        getline(ifile, q->first_name);
        getline(ifile, q->last_name);
        getline(ifile, q->record_number);
        getline(ifile, q->first_grade);
        getline(ifile, q->second_grade);
        getline(ifile, q->third_grade);
        getline(ifile, q->fourth_grade);
        getline(ifile, q->fifth_grade);
        getline(ifile, q->sixth_grade);

        q->next = NULL;
        p->next = q;
        p = p->next;
    }// End of while((ch == ifile.peek()) != EOF)

    ifile.close();
    cout << endl << endl << "Loading is complete." << endl;
    transition();

    return list;
}// End of items* load_file()

//-----------------------------------------

items* edit_screen(items* p)
{
    string resp = "XXX"; // User response for menu

    do
    {
        system("cls");
        cout << endl;
        cout << "                    MIRAMAR COLLEGE STUDENT GRADING SYSTEM" << endl << endl;
        cout << "                                DATA EDIT SCREEN" << endl << endl;
        cout << "            *F* irst Name-  " << p->first_name << endl;
        cout << "            *L* ast Name-  " << p->last_name << endl << endl;
        cout << "            *R* ecord Number-  " << p->record_number << endl << endl;
        cout << "            Grade *1* -  " << p->first_grade << endl;
        cout << "            Grade *2* -  " << p->second_grade << endl;
        cout << "            Grade *3* -  " << p->third_grade << endl;
        cout << "            Grade *4* -  " << p->fourth_grade << endl;
        cout << "            Grade *5* -  " << p->fifth_grade << endl;
        cout << "            Grade *6* -  " << p->sixth_grade << endl << endl;
        cout << "            E *x* it     " << endl << endl << endl;
        cout << "                           Enter Your Desired Field: "; getline(cin, resp);
        if(resp.empty()) resp = "XXX";

        switch(resp.at(0))
        {
            case 'F':
            case 'f':
                cout << "                           Enter Your Desired Input: ";
                getline(cin, p->first_name);
                if(p->first_name.empty()) p->first_name = "XXX";
                break;
            case 'L':
            case 'l':
                cout << "                           Enter Your Desired Input: ";
                getline(cin, p->last_name);
                if(p->last_name.empty()) p->last_name = "XXX";
                break;
            case 'R':
            case 'r':
                cout << "                           Enter Your Desired Input: ";
                getline(cin, p->record_number);
                if(p->record_number.empty()) p->record_number = "XXX";
                break;
            case '1':
                cout << "                           Enter Your Desired Input: ";
                getline(cin, p->first_grade);
                if(p->first_grade.empty()) p->first_grade = "XXX";
                while(p->first_grade.at(0) < '0' || p->first_grade.at(0) > '9')
                {
                    error_screen();
                    getline(cin, p->first_grade);
                    if(p->first_grade.empty()) p->first_grade = "XXX";
                    system("cls");
                }// End of while(p->first_grade.at(0) < '0' || p->first_grade.at(0) > '9')
                break;
            case '2':
                cout << "                           Enter Your Desired Input: ";
                getline(cin, p->second_grade);
                if(p->second_grade.empty()) p->second_grade = "XXX";
                while(p->second_grade.at(0) < '0' || p->second_grade.at(0) > '9')
                {
                    error_screen();
                    getline(cin, p->second_grade);
                    if(p->second_grade.empty()) p->second_grade = "XXX";
                    system("cls");
                }// End of while(p->second_grade.at(0) < '0' || p->second_grade.at(0) > '9')
                break;
            case '3':
                cout << "                           Enter Your Desired Input: ";
                getline(cin, p->third_grade);
                if(p->third_grade.empty()) p->third_grade = "XXX";
                while(p->third_grade.at(0) < '0' || p->third_grade.at(0) > '9')
                {
                    error_screen();
                    getline(cin, p->third_grade);
                    if(p->third_grade.empty()) p->third_grade = "XXX";
                    system("cls");
                }// while(p->third_grade.at(0) < '0' || p->third_grade.at(0) > '9')
                break;
            case '4':
                cout << "                           Enter Your Desired Input: ";
                getline(cin, p->fourth_grade);
                if(p->fourth_grade.empty()) p->fourth_grade = "XXX";
                while(p->fourth_grade.at(0) < '0' || p->fourth_grade.at(0) > '9')
                {
                    error_screen();
                    getline(cin, p->fourth_grade);
                    if(p->fourth_grade.empty()) p->fourth_grade = "XXX";
                    system("cls");
                }// End of while(p->fourth_grade.at(0) < '0' || p->fourth_grade.at(0) > '9')
                break;
            case '5':
                cout << "                           Enter Your Desired Input: ";
                getline(cin, p->fifth_grade);
                if(p->fifth_grade.empty()) p->fifth_grade = "XXX";
                while(p->fifth_grade.at(0) < '0' || p->fifth_grade.at(0) > '9')
                {
                    error_screen();
                    getline(cin, p->fifth_grade);
                    if(p->fifth_grade.empty()) p->fifth_grade = "XXX";
                    system("cls");
                }// End of while(p->fifth_grade.at(0) < '0' || p->fifth_grade.at(0) > '9')
                break;
            case '6':
                cout << "                           Enter Your Desired Input: ";
                getline(cin, p->sixth_grade);
                if(p->sixth_grade.empty()) p->sixth_grade = "XXX";
                while(p->sixth_grade.at(0) < '0' || p->sixth_grade.at(0) > '9')
                {
                    error_screen();
                    getline(cin, p->sixth_grade);
                    if(p->sixth_grade.empty()) p->sixth_grade = "XXX";
                    system("cls");
                }// End of while(sixth_grade.at(0) < '0' || sixth_grade.at(0) > '9')
                break;
            case 'X':
            case 'x':
                break;
            default:
                cout << endl << "             ERROR - Wrong input. Press <ENTER> to try again ";
                cin.get();
        }// End of switch(resp.at(0))
    }while(toupper(resp.at(0)) != 'X');

    return p;
}// End of items* edit_screen(items* p)

//-----------------------------------------

/*void sort(items i_arr[], int num_entry)
{
    items table;

    for(int i = 0; i < num_entry - 1; i++)
    {
        for (int j = i + 1; j < num_entry; j++)
        {
            if(i_arr[i].last_name.at(0) > i_arr[j].last_name.at(0)) // Sorts by last name
                // Under the assumption that the first letter is capitalized
            {
                table = i_arr[i];
                i_arr[i] = i_arr[j];
                i_arr[j] = table;
            }
        }// End of for (int j = i + 1; j < num_entry; j++)
    }// End of for(int i = 0; i < num_entry - 1; i++)
    disp_table(i_arr, num_entry);
}// End of void sort(items i_arr[], int num_entry)*/

//-----------------------------------------

void exit_screen()
{
    system("cls");

    cout << endl << endl;
    cout << "          ____________________________________________________________" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |       M I R A M A R   C O L L E G E   S T U D E N T      |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                G R A D I N G   S Y S T E M               |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                     Have a Nice Day!                     |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          |                                                          |" << endl;
    cout << "          ------------------------------------------------------------" << endl;
    cout << "                                       ||                             " << endl;
    cout << "                                       ||                             " << endl;
    cout << "                                     ------                           " << endl;
    cout << endl << endl << endl << endl << endl;
}// End of void exit_screen()
