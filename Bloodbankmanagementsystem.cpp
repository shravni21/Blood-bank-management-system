#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cstring>
#include<math.h>
using namespace std;

struct node
{
    char user[15];
    char pass[15];
    struct node *left, *right;
} * root;

struct node *newnode(char item[], char item1[])
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->user, item);
    strcpy(newnode->pass, item1);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void inorder(struct node *l)
{
    struct node *temp;
    temp = l;

    if (temp != NULL)
    {
        inorder(temp->left);
        cout << " " << temp->user << " " << temp->pass << endl;
        inorder(temp->right);
    }
}
struct node *insert(struct node *l, char x[], char x1[])
{
    int z;
    struct node *temp;
    temp = l;

    if (temp == NULL)
    {
        return newnode(x, x1);
    }

    int i, j;
    int ch, ch1;

    char y[15];
    strcpy(y, temp->user);

    for (i = 0; i < 5; i++)
    {
        ch = y[i];
        ch = ch - 96;
        ch1 = x[i];
        ch1 = ch1 - 96;

        if (ch == ch1)
        {
            continue;
        }
        else if (ch < ch1)
        {
            z = 0;
            break;
        }
        else if (ch > ch1)
        {
            z = 1;
            break;
        }
    }

    if (z == 1)
    {
        temp->left = insert(temp->left, x, x1);
    }
    else if (z == 0)
    {
        temp->right = insert(temp->right, x, x1);
    }
    return temp;
}

struct node *search(struct node *l, char x[], char x1[])
{
    struct node *temp;
    temp = l;
    if (temp == NULL || (strcmp(temp->user, x) == 0) && (strcmp(temp->pass, x1) == 0))
    {
        return temp;
    }
    int i, j, z;
    int ch, ch1;

    char y[15];
    strcpy(y, temp->user);

    for (i = 0; i < 5; i++)
    {
        ch = y[i];
        ch = ch - 96;
        ch1 = x[i];
        ch1 = ch1 - 96;

        if (ch == ch1)
        {
            continue;
        }
        else if (ch < ch1)
        {
            z = 0;
            break;
        }
        else if (ch > ch1)
        {
            z = 1;
            break;
        }
    }
    if (z == 0)
    {
        return search(temp->right, x, x1);
    }
    else
    {
        return search(temp->left, x, x1);
    }
}

class Home
{
public:
    Home()
    {
        string line;
        ofstream home_details;
        home_details.open("home.txt", ios::out);

        home_details << "=================================================================================" << endl;
        home_details << "--------------------------BLOOD BANK MANAGEMENT SYSTEM---------------------------" << endl;
        home_details<<"_________****  The blood is red gold in time of saving a life. ****_________"<<endl;
        home_details << "=================================================================================" << endl;
        home_details << "\n\n";
        home_details << "CAMP DETAILS:-" << endl;
        home_details << "=================================================================================" << endl;
        home_details << "Hello everyone..." << endl;
        home_details << "\tWe have arranged for a blood bank camp at 'SHRI GURU GOBIND SINGHJI INSTITUTE OF ENGINEERING AND TECHNOLOGY' , NANDED..." << endl;
        home_details << "We welcome you all to attend the camp and save the valuable life of others." << endl;
        home_details << "For further details contact blood bank." << endl;
        home_details << "Mail id : wakdeshravni@gmail.com" << endl;
        home_details << "CONTACT NO : 8432713596" << endl;
        home_details << "=================================================================================" << endl;
        home_details << "\n\n";
        home_details << "AVAILABLE BLOOD GROUPS:-" << endl;
        home_details << "=================================================================================" << endl;
        home_details << "\tA+\tA-\tB+\tB-\tO+\tO-\tAB+\tAB-" << endl;
        home_details << "=================================================================================" << endl;
        home_details << "In case of need of blood. Contact..." << endl;
        home_details << "Mail id : blood_bank@gmail.com" << endl;
        home_details << "CONTACT NO : 8900003626" << endl;
        home_details << "=================================================================================" << endl;

        home_details.close();
    }

    void display_home_details()
    {
        string line;
        ifstream home_dis;
        home_dis.open("home.txt", ios::in);

        while (!home_dis.eof())
        {
            getline(home_dis, line);
            cout << line << endl;
        }
        home_dis.close();
    }
};

int count = 0;

class Donor_registration
{
public:
    char name[50];
    char blood[10];
    char phone[20];
    int age;
    int offset1;
    char user_id[10];
    char uname[20];
    char password[10];
    int n, num;
    int flag = 0;

    void get_details_donor()
    {
        string line;
        fstream donor;
        donor.open("Donor details.txt", ios::app | ios::in);

        fstream donor_user;
        donor_user.open("Donor user details.txt", ios::app | ios::in);

        fstream donor_pass;
        donor_pass.open("Donor password details.txt", ios::app | ios::in);

        cout << "Enter name : " << flush;
        cin >> name;
        n = 1;
        cout << "Enter blood group : " << flush;
        while (n == 1)
        {
            cin >> blood;
            if ((strcmp(blood, "AB+") == 0) || (strcmp(blood, "AB-") == 0) || (strcmp(blood, "B+") == 0) || (strcmp(blood, "B-") == 0) || (strcmp(blood, "A+") == 0) || (strcmp(blood, "A-") == 0) || (strcmp(blood, "O+") == 0) || (strcmp(blood, "O-") == 0))
            {
                break;
            }
            else
            {
                cout << "Invalid blood group!!!" << endl;
                cout << "Enter valid blood group : " << flush;
                try
                {
                    if ((strcmp(blood, "AB+") == 0) || (strcmp(blood, "AB-") == 0) || (strcmp(blood, "B+") == 0) || (strcmp(blood, "B-") == 0) || (strcmp(blood, "A+") == 0) || (strcmp(blood, "A-") == 0) || (strcmp(blood, "O+") == 0) || (strcmp(blood, "O-") == 0))
                    {
                        throw 5;
                    }
                }
                catch (...)
                {
                }
            }
        }
        n = 1;
        cout << "Enter phone no : " << flush;
        while (n == 1)
        {
            cin >> phone;
            num = strlen(phone);

            if (num == 10)
            {
                break;
            }
            else
            {
                cout << "Invalid phone number!!!" << endl;
                try
                {
                    if (num != 10)
                    {
                        throw 0;
                    }
                }
                catch (int x)
                {
                    cout << "Enter valid phone number : " << flush;
                }
            }
        }
        n = 1;
        cout << "Enter age : " << flush;
        while (n == 1)
        {
            cin >> age;
            if (age >= 18 && age <= 120)
            {
                n = 0;
                continue;
            }
            else
            {
                cout << "Invalid age!!!" << endl;
                cout << "Enter valid age!!!" << endl;
                try
                {
                    if (age <= 18 && age >= 120)
                    {
                        throw 0;
                    }
                }
                catch (int x)
                {
                }
            }
        }
        n = 1;
        cout << "Enter user_id[Only 5 characters] : " << flush;
        cin >> user_id;
        n = 1;
        cout << "Enter password[Only 5 characters] : " << flush;
        while (n == 1)
        {
            cin >> password;
            num = strlen(password);
            if (num == 5)
            {
                n = 0;
                continue;
            }
            else
            {
                cout << "Invalid password!!!" << endl;
                try
                {
                    if (num != 5)
                    {
                        throw 0;
                    }
                }
                catch (int x)
                {
                    cout << "Enter valid password : " << flush;
                }
            }
        }
        donor << "DONOR NAME : ";
        donor << name << flush;
        donor << "\t";
        donor << "BLOOD GROUP : ";
        donor << blood << flush;
        donor << "\t";
        donor << "PHONE NUMBER :";
        donor << phone << flush;
        donor << "\t";
        donor << "AGE : ";
        donor << age;
        donor << "\t";
        donor << "User name : ";
        donor << user_id;
        donor << "\t";
        donor_user << user_id;
        donor_user << "\n";
        donor << "\t";
        donor << "Password : ";
        donor << password;
        donor << "\t";
        donor_pass << password;
        donor_pass << "\n";
        donor << "\n";

        donor.close();
        donor_user.close();
        donor_pass.close();
    }
};

int count1 = 0;

class Acceptor_registration
{
public:
    char name[50];
    char blood[10];
    char phone[20];
    int age;
    char user_id[10];
    char password[10];
    int n, num;

    void get_details_acceptor()
    {
        string line;
        fstream acceptor;
        acceptor.open("Acceptor details.txt", ios::app | ios::in);

        fstream acceptor_use;
        acceptor_use.open("Acceptor user details.txt", ios::app | ios::in);

        cout << "Enter name : " << flush;
        cin >> name;
        n = 1;
        cout << "Enter blood group : " << flush;
        while (n == 1)
        {
            cin >> blood;
            if ((strcmp(blood, "AB+") == 0) || (strcmp(blood, "AB-") == 0) || (strcmp(blood, "B+") == 0) || (strcmp(blood, "B-") == 0) || (strcmp(blood, "A+") == 0) || (strcmp(blood, "A-") == 0) || (strcmp(blood, "O+") == 0) || (strcmp(blood, "O-") == 0))
            {
                break;
            }
            else
            {
                cout << "Invalid blood group!!!" << endl;
                cout << "Enter valid blood group : " << flush;
                try
                {
                    if ((strcmp(blood, "AB+") == 0) || (strcmp(blood, "AB-") == 0) || (strcmp(blood, "B+") == 0) || (strcmp(blood, "B-") == 0) || (strcmp(blood, "A+") == 0) || (strcmp(blood, "A-") == 0) || (strcmp(blood, "O+") == 0) || (strcmp(blood, "O-") == 0))
                    {
                        throw 5;
                    }
                }
                catch (...)
                {
                }
            }
        }
        n = 1;
        cout << "Enter phone no : " << flush;
        while (n == 1)
        {
            cin >> phone;
            num = strlen(phone);

            if (num == 10)
            {
                break;
            }
            else
            {
                cout << "Invalid phone number!!!" << endl;
                try
                {
                    if (num != 10)
                    {
                        throw 0;
                    }
                }
                catch (int x)
                {
                    cout << "Enter valid phone number : " << flush;
                }
            }
        }
        n = 1;
        cout << "Enter age : " << flush;
        while (n == 1)
        {
            cin >> age;
            if (age >= 1 && age <= 120)
            {
                n = 0;
                continue;
            }
            else
            {
                cout << "Invalid age!!!" << endl;
                cout << "Enter valid age!!!" << endl;
                try
                {
                    if (age <= 1 && age >= 120)
                    {
                        throw 0;
                    }
                }
                catch (int x)
                {
                }
            }
        }
        n = 1;
        cout << "Enter user_id[Only 5 characters] : " << flush;
        int offset2;
        cin >> user_id;
        n = 1;
        cout << "Enter password[Only 5 characters] : " << flush;
        while (n == 1)
        {
            cin >> password;
            num = strlen(password);
            if (num == 5)
            {
                n = 0;
                continue;
            }
            else
            {
                cout << "Invalid password!!!" << endl;
                try
                {
                    if (num != 5)
                    {
                        throw 0;
                    }
                }
                catch (int x)
                {
                    cout << "Enter valid password : " << flush;
                }
            }
        }
        acceptor << "Acceptor NAME : ";
        acceptor << name << flush;
        acceptor << "\t";
        acceptor << "BLOOD GROUP : ";
        acceptor << blood << flush;
        acceptor << "\t";
        acceptor << "PHONE NUMBER :";
        acceptor << phone << flush;
        acceptor << "\t";
        acceptor << "AGE : ";
        acceptor << age;
        acceptor << "\t";
        acceptor << "USER_NAME : ";
        acceptor << user_id << flush;
        acceptor_use << user_id;
        acceptor_use << "\n";
        acceptor << "\t";
        acceptor << "PASSWORD : ";
        acceptor << password << flush;
        acceptor_use << password;
        acceptor_use << "\n";
        acceptor << "\n";
        acceptor.close();
    }
};

class Admin : public Donor_registration, public Acceptor_registration
{
public:
    void get_donor_data()
    {
        int ch;
        fstream donor;
        fstream acceptor;
        string line, search1;
        int offset;

        cout << "------------------------" << endl;
        cout << "Donor Details:-" << endl;
        cout << "------------------------" << endl;
        donor.open("Donor details.txt", ios::in);
        if (donor.is_open())
        {
            while (!donor.eof())
            {
                getline(donor, line);
                cout << line;
                cout << "\n";
            }
        }
        donor.close();
        cout << "\n";
    }

    void get_acceptor_details()
    {
        fstream acceptor;
        string line, search1;
        cout << "------------------------" << endl;
        cout << "Acceptor Details:-" << endl;
        cout << "------------------------" << endl;
        acceptor.open("Acceptor details.txt", ios::in);
        if (acceptor.is_open())
        {
            while (!acceptor.eof())
            {
                getline(acceptor, line);
                cout << line;
                cout << "\n";
            }
        }
        acceptor.close();
        cout << "\n"
             << endl;
    }
    void search_blood_group()
    {
        fstream donor;
        string line, search1;
        int offset;
        cout << "------------------------" << endl;
        cout << "Search Blood group:-" << endl;
        cout << "------------------------" << endl;
        cout << "Enter blood group : " << flush;
        cin >> search1;
        donor.open("Donor details.txt", ios::in);
        if (donor.is_open())
        {
            while (!donor.eof())
            {
                getline(donor, line);
                if (((offset = line.find(search1, 0))) != string::npos)
                {
                    cout << line;
                }
                cout << endl;
            }
        }
        donor.close();
        cout << "\n";
    }
};
int main()
{
    int choice, ch, i = 0, j = 0, k, l;
    char u[10], p[10];
    char search1[20];
    string line;
    int offset;
    Home h;
    Donor_registration d[100];
    Acceptor_registration a[100];
    Admin ad;
    fstream donor;
    fstream acceptor;
    string line1;
    int n;
    struct node *root = NULL, *root1 = NULL;
    int x, y;
    string a1, a2;
    char b2[a2.size() + 1];
    char b1[a1.size() + 1];

    fstream donor_user, donor_pass;
    donor_user.open("Donor user details.txt", ios::app | ios::in);
    donor_pass.open("Donor password details.txt", ios::app | ios::in);
    if (donor_user.is_open() && donor_pass.is_open())
    {
        while (!donor_user.eof() && !donor_pass.eof())
        {
            getline(donor_user, line);
            getline(donor_pass, line1);
            strcpy(b1, line.c_str());
            strcpy(b2, line1.c_str());
            root = insert(root, b1, b2);
        }
        // inorder(root);
    }
    donor_user.close();
    donor_pass.close();

    while (1)
    {
        cout << "1.Home 2.Registration 3.Donor Module 4.Acceptor Module 5.Admin 6.Exit" << endl;
        cout << "Enter the choice : " << flush;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Home details:-" << endl;
            h.display_home_details();
            break;

        case 2:
            cout << "Enter the choice[1.Donor Registration 2.Acceptor Registration]" << endl;
            cin >> ch;

            switch (ch)
            {
            case 1:
                cout << "------------------------" << endl;
                cout << "Donor Registration:-" << endl;
                cout << "------------------------" << endl;
                if (i <= 100)
                {
                    d[i].get_details_donor();
                    i++;
                    count++;
                }

                root = insert(root, d[i - 1].user_id, d[i - 1].password);
                break;

            case 2:
                cout << "------------------------" << endl;
                cout << "Acceptor Registration:-" << endl;
                cout << "------------------------" << endl;
                if (j <= 100)
                {
                    a[j].get_details_acceptor();
                    j++;
                    count1++;
                }
                break;
            }
            cout << "Successfully Registered!!!" << endl;
            cout << "---------------------------------" << endl;
            break;

        case 3:
            cout << "------------------------" << endl;
            cout << "Donor Module:-" << endl;
            cout << "------------------------" << endl;
            cout << "Enter user_id[Only 5 characters]" << endl;
            cin >> u;
            cout << "Enter password[Only 5 characters]" << endl;
            cin >> p;
            n = 1;
            root1 = search(root, u, p);
            while (n == 1)
            {
                if (root1 != NULL)
                {
                    cout << "Logged in!!!" << endl;
                    n = 0;
                    donor_user.open("Donor details.txt", ios::in);
                    if (donor_user.is_open())
                    {
                        while (!donor_user.eof())
                        {
                            getline(donor_user, line);
                            if (((offset = line.find(u, 0))) != string::npos)
                            {
                                cout << line;
                                cout << endl;
                            }
                        }
                    }
                    donor_user.close();
                    cout << "\n";
                }
                else
                {
                    cout << "Wrong user name and password!!!" << endl;
                    n = 0;
                    break;

                case 4:
                    cout << "------------------------" << endl;
                    cout << "Acceptor Module:-" << endl;
                    cout << "------------------------" << endl;
                    cout << "Enter user_id[Only 5 characters]" << endl;
                    cin >> u;
                    cout << "Enter password[Only 5 characters]" << endl;
                    cin >> p;
                    acceptor.open("Acceptor details.txt", ios::in);
                    if (acceptor.is_open())
                    {
                        while (!acceptor.eof())
                        {
                            getline(acceptor, line);
                            if (((offset = line.find(u, 0))) != string::npos)
                            {
                                if (((offset = line.find(p, 0))) != string::npos)
                                {
                                    cout << line;
                                }
                                cout << endl;
                            }
                        }
                        acceptor.close();
                        cout << "\n";
                        break;

                    case 5:
                        cout << "------------------------" << endl;
                        cout << "Admin Module:-" << endl;
                        cout << "------------------------" << endl;
                        cout << "1.Home 2.Donor module 3.Acceptor module 4.Search blood 5.Exit" << endl;

                        do
                        {
                            cout << "Enter the choice" << endl;
                            cin >> ch;

                            switch (ch)
                            {
                            case 1:
                                cout << "Home details:-" << endl;
                                h.display_home_details();
                                break;

                            case 2:
                                ad.get_donor_data();
                                break;

                            case 3:
                                ad.get_acceptor_details();
                                break;

                            case 4:
                                ad.search_blood_group();
                                break;
                            }
                        } while (ch != 5);
                        break;

                    case 6:
                        cout << "Exit:-)" << endl;
                        exit(0);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
