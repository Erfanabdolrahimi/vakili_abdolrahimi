#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <string.h>

using namespace std;

void add();
void editing();
void showall();
void deleting();
void sort_least();
void Searchfone();
void sell();
void sort();

void swap(string &s1, string &s2)
{
    string temp;
    temp = s1;
    s1 = s2;
    s2 = temp;
}

string Arr[400][11];
int Arrr[400][3];
int countt;
/*******************************************************************/
int main()
{
    int Key = 0;

    while (true)
    {
        system("cls");
        system("color 74");
        cout << "HI MY FREIND \n\n";
        cout << "\n 1. Add a phone.";
        cout << "\n 2. Remove a phone.";
        cout << "\n 3. sort phons by price.";
        cout << "\n 4. search a phone.";
        cout << "\n 5. Change mobile info";
        cout << "\n 6. sell a phone .";
        cout << "\n 7. print phons.";
        cout << "\n 8. print phons sorted by the most sold to the least ";
        cout << "\n 9. EXIT\n\n";
        cout << "\n ";
        cout << "\n\n Key : ";
        cin >> Key;
        switch (Key)
        {
        case 1:
            add();
            break;
        case 2:
            deleting();
            break;
        case 3:
            sort();

            break;
        case 4:
            Searchfone();
            break;
        case 5:
            editing();
            break;
        case 6:
            sell();
            break;
        case 7:
            showall();
            break;
        case 8:
            sort_least();
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "enter true nummber";
            main();
            break;
        }
        system("pause");
    }
}
/*******************************************************************/
void add()
{

    char name[12];
    char company[12];
    char os[12];
    char ram[12];
    char storage[12];
    char price[12];
    char color[12];
    char available[3];
    char sold[3];

    cin.ignore();

    cout << "\n Enter phone name :";
    cin.getline(name, 12);

    cout << " Enter Production Company :";
    cin.getline(company, 12);

    cout << " Enter OS :";
    cin.getline(os, 12);

    cout << " Enter Ram:";
    cin.getline(ram, 12);

    cout << " Enter Storage : ";
    cin.getline(storage, 12);

    cout << " Enter Price : ";
    cin.getline(price, 12);

    cout << " Enter Color :";
    cin.getline(color, 12);

    cout << " Enter Number of inventory:";
    cin.getline(available, 3);

    cout << " Enter Number sold :";
    cin.getline(sold, 3);

    ofstream myfile;

    myfile.open("mobile.txt", ios::app);

    myfile << name;
    myfile << "|";
    myfile << company;
    myfile << "|";
    myfile << os;
    myfile << "|";
    myfile << ram;
    myfile << "|";
    myfile << storage;
    myfile << "|";
    myfile << price;
    myfile << "|";
    myfile << color;
    myfile << "|";
    myfile << available;
    myfile << "|";
    myfile << sold;

    myfile << endl;

    myfile.close();

    int available1;
    int sold1;

    available1 = stoi(available);
    sold1 = stoi(sold);

    string H, I;
    Arr[countt][0] = name;
    Arr[countt][1] = company;
    Arr[countt][2] = os;
    Arr[countt][3] = ram;
    Arr[countt][4] = storage;
    Arr[countt][5] = price;
    Arr[countt][6] = color;
    Arr[countt][7] = H;
    Arr[countt][8] = I;

    Arrr[countt][0] = available1;
    Arrr[countt][1] = sold1;

    Arr[countt][9] = "1";
    Arrr[countt][2] = 1;

    countt++;
}
/*******************************************************************/
void editing()
{

    fstream myfile;
    fstream temp;
    myfile.open("mobile.txt", ios::in);
    temp.open("temp.txt", ios::out);

    char name[12];
    char company[12];
    char os[12];
    char ram[12];
    char storage[12];
    char price[12];
    char color[12];
    char available[3];
    char sold[3];
    char searchn[12];
    char searchc[12];

    cin.ignore();

    cout << "\n Enter phone name for edaiting information:";
    cin.getline(searchn, 12);

    cout << "\n please Enter company name for edaiting information:";
    cin.getline(searchc, 12);

    while (!myfile.eof())
    {
        myfile.getline(name, 12, '|');
        myfile.getline(company, 12, '|');
        myfile.getline(os, 12, '|');
        myfile.getline(ram, 12, '|');
        myfile.getline(storage, 12, '|');
        myfile.getline(price, 12, '|');
        myfile.getline(color, 12, '|');
        myfile.getline(available, 3, '|');
        myfile.getline(sold, 3);

        if ((strcmp(searchn, name) == 0) && (strcmp(searchc, company) == 0))
        {
            /* cout << "\n phone name:" << name;
             cout << "\n....................................................";
             cout << "\n company Name :" << company;
             cout << "\n....................................................";
             cout << "\n  Os :" << os;
             cout << "\n....................................................";
             cout << "\n tel Ram :" << ram;
             cout << "\n....................................................";
             cout << "\n storage :" << storage;
             cout << "\n....................................................";
             cout << "\n  price:" << price;
             cout << "\n....................................................";
             cout << "\n  color:" << color << endl;
             cout << "\n....................................................";
             cout << "\n Number of inventory:" << available << endl;
             cout << "\n....................................................";
             cout << "\n  Number sold:" << sold << endl;
             cout << "----------------------------------------------------------------------------------------" << endl;*/

            cout << " Enter OS :";
            cin.getline(os, 12);

            cout << " Enter Ram:";
            cin.getline(ram, 12);

            cout << " Enter Storage : ";
            cin.getline(storage, 12);

            cout << " Enter Price : ";
            cin.getline(price, 12);

            cout << " Enter Color :";
            cin.getline(color, 12);

            cout << "Enter Number of inventory:";
            cin.getline(available, 3);

            cout << "Enter Number sold :";
            cin.getline(sold, 3);

            temp << name
                 << "|"
                 << company
                 << "|"
                 << os
                 << "|"
                 << ram
                 << "|"
                 << storage
                 << "|"
                 << price
                 << "|"
                 << color << "|" << available << "|" << sold

                 << endl;
        }

        else
        {
            temp << name
                 << "|"
                 << company
                 << "|"
                 << os
                 << "|"
                 << ram
                 << "|"
                 << storage
                 << "|"
                 << price
                 << "|"
                 << color << "|" << available << "|" << sold

                 << endl;
        }
    }
    myfile.close();
    temp.close();

    myfile.open("mobile.txt", ios::out);
    temp.open("temp.txt", ios::in);
    while (!temp.eof())
    {

        temp.getline(name, 12, '|');
        temp.getline(company, 12, '|');
        temp.getline(os, 12, '|');
        temp.getline(ram, 12, '|');
        temp.getline(storage, 12, '|');
        temp.getline(price, 12, '|');
        temp.getline(color, 12, '|');
        temp.getline(available, 3, '|');
        temp.getline(sold, 3);

        myfile << name
               << "|"
               << company
               << "|"
               << os
               << "|"
               << ram
               << "|"
               << storage
               << "|"
               << price
               << "|"
               << color << "|" << available << "|" << sold

               << endl;
    }
    myfile.close();
    temp.close();
    remove("temp.txt");
    cout << "done!" << endl;
}
/*******************************************************************/
void deleting()
{

    fstream myfile;
    fstream temp;
    myfile.open("mobile.txt", ios::in);
    temp.open("temp.txt", ios::out);

    char name[12];
    char company[12];
    char os[12];
    char ram[12];
    char storage[12];
    char price[12];
    char color[12];
    char available[3];
    char sold[3];
    char searchn[12];
    char searchc[12];

    cin.ignore();

    cout << "\n Enter phone name for removing information:";
    cin.getline(searchn, 12);

    cout << "\n please Enter company name for removing information:";
    cin.getline(searchc, 12);

    while (!myfile.eof())
    {
        myfile.getline(name, 12, '|');
        myfile.getline(company, 12, '|');
        myfile.getline(os, 12, '|');
        myfile.getline(ram, 12, '|');
        myfile.getline(storage, 12, '|');
        myfile.getline(price, 12, '|');
        myfile.getline(color, 12, '|');
        myfile.getline(available, 3, '|');
        myfile.getline(sold, 3);

        if ((strcmp(searchn, name) == 0) && (strcmp(searchc, company) == 0))
        {
            continue;
        }

        else
        {

            temp << name
                 << "|"
                 << company
                 << "|"
                 << os
                 << "|"
                 << ram
                 << "|"
                 << storage
                 << "|"
                 << price
                 << "|"
                 << color << "|" << available << "|" << sold

                 << endl;
        }
    }

    myfile.close();
    temp.close();

    myfile.open("mobile.txt", ios::out);
    temp.open("temp.txt", ios::in);
    while (!temp.eof())
    {

        temp.getline(name, 12, '|');
        temp.getline(company, 12, '|');
        temp.getline(os, 12, '|');
        temp.getline(ram, 12, '|');
        temp.getline(storage, 12, '|');
        temp.getline(price, 12, '|');
        temp.getline(color, 12, '|');
        temp.getline(available, 3, '|');
        temp.getline(sold, 3);

        myfile << name
               << "|"
               << company
               << "|"
               << os
               << "|"
               << ram
               << "|"
               << storage
               << "|"
               << price
               << "|"
               << color << "|" << available << "|" << sold

               << endl;
    }
    myfile.close();
    temp.close();
    remove("temp.txt");
    cout << "done!" << endl;
}
/*******************************************************************/
void Searchfone()
{

    char name[12];
    char company[12];
    char os[12];
    char ram[12];
    char storage[12];
    char price[12];
    char color[12];
    char available[3];
    char sold[3];
    char searchn[12];
    char searchc[12];

    fstream myfile;
    myfile.open("mobile.txt", ios::in);

    cin.ignore();

    cout << "enter the phone name" << endl;
    cin.getline(searchn, 12);

    cout << "pleas enter the phone company" << endl;
    cin.getline(searchc, 12);

    while (!myfile.eof())
    {
        myfile.getline(name, 12, '|');
        myfile.getline(company, 12, '|');
        myfile.getline(os, 12, '|');
        myfile.getline(ram, 12, '|');
        myfile.getline(storage, 12, '|');
        myfile.getline(price, 12, '|');
        myfile.getline(color, 12, '|');
        myfile.getline(available, 3, '|');
        myfile.getline(sold, 3);

        if ((strcmp(searchn, name) == 0) && (strcmp(searchc, company) == 0))
        {
            cout << "\n phone name:         " << name;
            cout << "\n......................................";
            cout << "\n company Name :      " << company;
            cout << "\n......................................";
            cout << "\n Os :                " << os;
            cout << "\n......................................";
            cout << "\n tel Ram :           " << ram;
            cout << "\n......................................";
            cout << "\n storage :           " << storage;
            cout << "\n......................................";
            cout << "\n price:              " << price;
            cout << "\n......................................";
            cout << "\n color:              " << color;
            cout << "\n......................................";
            cout << "\n Number of inventory:" << available;
            cout << "\n......................................";
            cout << "\n Number sold:        " << sold << endl;
            cout << "----------------------------------------" << endl;
        }
    }

    myfile.close();
}
/*******************************************************************/
void showall()
{

    char name[12];
    char company[12];
    char os[12];
    char ram[12];
    char storage[12];
    char price[12];
    char color[12];
    char available[3];
    char sold[3];

    fstream myfile;
    myfile.open("mobile.txt", ios::in);

    while (!myfile.eof())
    {
        myfile.getline(name, 12, '|');
        myfile.getline(company, 12, '|');
        myfile.getline(os, 12, '|');
        myfile.getline(ram, 12, '|');
        myfile.getline(storage, 12, '|');
        myfile.getline(price, 12, '|');
        myfile.getline(color, 12, '|');
        myfile.getline(available, 3, '|');
        myfile.getline(sold, 3);

        cout << "\n phone name:" << name;
        cout << "\n....................................................";
        cout << "\n company Name :" << company;
        cout << "\n....................................................";
        cout << "\n  Os :" << os;
        cout << "\n....................................................";
        cout << "\n tel Ram :" << ram;
        cout << "\n....................................................";
        cout << "\n storage :" << storage;
        cout << "\n....................................................";
        cout << "\n  price:" << price;
        cout << "\n....................................................";
        cout << "\n  color:" << color << endl;
        cout << "\n....................................................";
        cout << "\n Number of inventory:" << available << endl;
        cout << "\n....................................................";
        cout << "\n  Number sold:" << sold << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
    }
}
/*******************************************************************/
void sell()
{

    fstream myfile;
    fstream temp;
    myfile.open("mobile.txt", ios::in);
    temp.open("temp.txt", ios::out);

    int available1;
    int sold1;
    string available2;
    string sold2;

    char name[12];
    char company[12];
    char os[12];
    char ram[12];
    char storage[12];
    char price[12];
    char color[12];
    char available[3];
    char sold[3];
    char searchn[12];
    char searchc[12];

    cin.ignore();

    cout << "enter the phone name" << endl;
    cin.getline(searchn, 12);

    cout << "pleas enter the phone company" << endl;
    cin.getline(searchc, 12);

    while (!myfile.eof())
    {
        myfile.getline(name, 12, '|');
        myfile.getline(company, 12, '|');
        myfile.getline(os, 12, '|');
        myfile.getline(ram, 12, '|');
        myfile.getline(storage, 12, '|');
        myfile.getline(price, 12, '|');
        myfile.getline(color, 12, '|');
        myfile.getline(available, 3, '|');
        myfile.getline(sold, 3);

        if ((strcmp(searchn, name) == 0) && (strcmp(searchc, company) == 0))
        {

            available1 = stoi(available);

            sold1 = stoi(sold);

            available1--;

            sold1++;

            available2 = to_string(available1);

            sold2 = to_string(sold1);

            available[0] = available2[0];
            available[1] = available2[1];
            available[2] = available2[2];

            sold[0] = sold2[0];
            sold[1] = sold2[1];
            sold[2] = sold2[2];

            temp << name
                 << "|"
                 << company
                 << "|"
                 << os
                 << "|"
                 << ram
                 << "|"
                 << storage
                 << "|"
                 << price
                 << "|"
                 << color << "|" << available << "|" << sold

                 << endl;
        }

        else
        {
            cout << "\nNot Find\n";

            temp << name
                 << "|"
                 << company
                 << "|"
                 << os
                 << "|"
                 << ram
                 << "|"
                 << storage
                 << "|"
                 << price
                 << "|"
                 << color << "|" << available << "|" << sold

                 << endl;
        }
    }

    myfile.close();
    temp.close();

    myfile.open("mobile.txt", ios::out);
    temp.open("temp.txt", ios::in);
    while (!temp.eof())
    {

        temp.getline(name, 12, '|');
        temp.getline(company, 12, '|');
        temp.getline(os, 12, '|');
        temp.getline(ram, 12, '|');
        temp.getline(storage, 12, '|');
        temp.getline(price, 12, '|');
        temp.getline(color, 12, '|');
        temp.getline(available, 3, '|');
        temp.getline(sold, 3);

        myfile << name
               << "|"
               << company
               << "|"
               << os
               << "|"
               << ram
               << "|"
               << storage
               << "|"
               << price
               << "|"
               << color << "|" << available << "|" << sold
               << endl;
    }
    myfile.close();
    temp.close();
    remove("temp.txt");
    cout << "done!" << endl;

    int a = 0, h, w, l, k;
    string q, t;

    for (int i = 0; i < countt + 1; i++)
    {

        if ((Arr[i][0] == searchn && Arr[i][1] == searchc) && Arr[i][9] == "1")
        {

            w = Arrr[i][0];
            k = w - 1;
            Arrr[i][0] = k;
            h = Arrr[i][1];
            l = h + 1;
            Arrr[i][1] = l;
        }
    }
}
/*******************************************************************/
void sort_least()
{
    int m = 0, n;

    for (int j = 0; j < countt + 1; j++)
    {

        if (Arrr[j][1] > m)
        {
            m = Arrr[j][1];
        }
    }

    int w = m + 1;

    for (int k = 0; k < w; k++)
    {

        for (int i = 0; i < countt; i++)
        {

            if (Arrr[i][1] == m && m > -1)
            {
                cout << "---------------------------------------------------------------------";
                cout << "\n  phone name:" << Arr[i][0];

                cout << "\n  company Name :" << Arr[i][1];

                cout << "\n  Os :" << Arr[i][2];

                cout << "\n  tel Ram :" << Arr[i][3];

                cout << "\n  storage :" << Arr[i][4];

                cout << "\n  price:" << Arr[i][5];

                cout << "\n  color:" << Arr[i][6] << endl;

                cout << "\n  Number of inventory:" << Arrr[i][0] << endl;

                cout << "\n  Number sold:" << Arrr[i][1] << endl;

                cout << "\n....................................................";
            }
        }
        m = m - 1;
    }
}
/*******************************************************************/
void sort()
{
    for (int j = 0; j < countt + 1; j++)
    {

        for (int i = 0; i < countt + 1; i++)
        {

            if (Arr[i][5] > Arr[i + 1][5] && Arr[i][9] == "1" && Arr[i + 1][9] == "1")
            {
                swap(Arr[i], Arr[i + 1]);
            }
        }
    }

    int a = 0;

    for (int i = 0; i < countt + 1; i++)
    {

        if (Arr[i][9] == "1")
        {

            cout << "--------------------------------member:" << a << "-------------------------" << endl;
            cout << "\n  phone name:" << Arr[i][0];

            cout << "\n  company Name :" << Arr[i][1];

            cout << "\n  Os :" << Arr[i][2];

            cout << "\n  tel Ram :" << Arr[i][3];

            cout << "\n  storage :" << Arr[i][4];

            cout << "\n  price:" << Arr[i][5];

            cout << "\n  color:" << Arr[i][6] << endl;

            cout << "\n  Number of inventory:" << Arrr[i][0] << endl;

            cout << "\n  Number sold:" << Arrr[i][1] << endl;
            cout << "---------------------------------------------------------------------------" << endl;
        }
        a++;
    }

    cout << "sorted" << endl;
}
/*******************************************************************/
