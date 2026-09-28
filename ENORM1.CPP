#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

enum Gender {
    M, F, TG
};

enum Class {
    FY = 1,
    SY,
    TY,
    BTECH
};

class Dept {

private:

    int did;
    char sf[18];
    char ff[100];
    static int seq;

public:

    Dept();
    Dept(char s[], char f[]);

    void display();

    int get_did();
    char* get_sf();
    char* get_ff();

};

int Dept::seq = 1;

Dept::Dept() {

    cout << "Enter the short form of dept: ";
    cin >> sf;

    cout << endl;

    cout << "Enter the full form of dept: ";
    cin >> ff;

    cout << endl;

    did = seq++;
}

Dept::Dept(char s[], char f[]) {

    strcpy(sf, s);
    strcpy(ff, f);

    did = seq++;
}

void Dept::display() {

    cout << did << " | "
         << sf << " | "
         << ff << endl;
}

int Dept::get_did() {

    return did;
}

char* Dept::get_sf() {

    return sf;
}

char* Dept::get_ff() {

    return ff;
}

class Student {

private:

    unsigned long prn;
    char name[100];
    int year;

    Gender gen;
    Class _class;

    Dept dept;

    int isCancelled;

    static int seq;

public:

    Student(Dept d);

    unsigned long get_prn();

    int get_iscancelled();

    int get_dept();

    void cancel_admission();

    void display();

};

int Student::seq = 1;

Student::Student(Dept d) {

    clrscr();

    cout << "========== STUDENT ADMISSION ==========\n\n";

    cout << "Enter name: ";
    cin >> name;

    cout << endl;

    cout << "Enter Year of Admission (ex: 2025) = ";
    cin >> year;

    cout << endl;

    int ch;

    while(1) {

        cout << "Gender (0:M | 1:F | 2:TG) = ";
        cin >> ch;

        if(cin.fail()) {

            cin.clear();
            cin.ignore(100, '\n');

            continue;
        }

        if(ch >= 0 && ch <= 2) {

            switch(ch) {

                case 0:
                    gen = M;
                    break;

                case 1:
                    gen = F;
                    break;

                case 2:
                    gen = TG;
                    break;
            }

            break;
        }

        cout << "Invalid choice! Enter again.\n";
    }

    cout << endl;

    while(1) {

        cout << "Class (1:FY | 2:SY | 3:TY | 4:BTECH) = ";
        cin >> ch;

        if(cin.fail()) {

            cin.clear();
            cin.ignore(100, '\n');

            continue;
        }

        if(ch >= 1 && ch <= 4) {

            switch(ch) {

                case 1:
                    _class = FY;
                    break;

                case 2:
                    _class = SY;
                    break;

                case 3:
                    _class = TY;
                    break;

                case 4:
                    _class = BTECH;
                    break;
            }

            break;
        }

        cout << "Invalid choice! Enter again.\n";
    }

    dept = d;

    prn = 100000000L
          + (year % 100L) * 1000000L
          + (long)_class * 100000L
          + (long)dept.get_did() * 10000L
          + seq++;

    isCancelled = 0;

    cout << "\nStudent admitted successfully!";
    cout << "\nGenerated PRN = " << prn << endl;
}

unsigned long Student::get_prn() {

    return prn;
}

int Student::get_iscancelled() {

    return isCancelled;
}

int Student::get_dept() {

    return dept.get_did();
}

void Student::cancel_admission() {

    isCancelled = 1;
}

void Student::display() {

    cout << "\n--------------------------------------------\n";

    cout << "PRN        : " << prn << endl;

    cout << "Name       : " << name << endl;

    cout << "Year       : " << year << endl;

    cout << "Gender     : ";

    switch(gen) {

        case M:
            cout << "Male";
            break;

        case F:
            cout << "Female";
            break;

        case TG:
            cout << "TG";
            break;
    }

    cout << endl;

    cout << "Class      : ";

    switch(_class) {

        case FY:
            cout << "FY";
            break;

        case SY:
            cout << "SY";
            break;

        case TY:
            cout << "TY";
            break;

        case BTECH:
            cout << "BTECH";
            break;
    }

    cout << endl;

    cout << "Department : "
         << dept.get_sf()
         << " - "
         << dept.get_ff()
         << endl;

    cout << "Status     : ";

    if(isCancelled == 1)
        cout << "Cancelled";
    else
        cout << "Active";

    cout << endl;

    cout << "--------------------------------------------\n";
}

void main() {

    clrscr();

    int choice;

    Student *students[50];

    Dept *depts[10];

    int studentCount = 0;

    int deptCount = 0;

    int i;

    depts[deptCount++] =
        new Dept("COMP", "Computer Engineering");

    do {

        clrscr();

        cout << "============================================\n";
        cout << "         STUDENT ADMISSION SYSTEM\n";
        cout << "============================================\n\n";

        cout << "1) Student\n";
        cout << "2) Dept\n";
        cout << "3) Exit\n\n";

        cout << "Choice = ";

        cin >> choice;

        switch(choice) {

            case 1: {

                int studentChoice;

                do {

                    clrscr();

                    cout << "============================================\n";
                    cout << "             STUDENT MENU\n";
                    cout << "============================================\n\n";

                    cout << "1. Admission\n";
                    cout << "2. Search student\n";
                    cout << "3. List all active admissions\n";
                    cout << "4. Cancel admission\n";
                    cout << "5. Display cancelled admissions\n";
                    cout << "6. Department-wise admission count\n";
                    cout << "7. Back to Main Menu\n\n";

                    cout << "Choice = ";

                    cin >> studentChoice;

                    switch(studentChoice) {

                        case 1: {

                            if(studentCount >= 50) {

                                cout << "\nStudent limit reached!";

                                getch();

                                break;
                            }

                            if(deptCount == 0) {

                                cout << "\nNo departments available!";

                                getch();

                                break;
                            }

                            int dChoice;

                            clrscr();

                            cout << "========== SELECT DEPARTMENT ==========\n\n";

                            for(i = 0; i < deptCount; i++) {

                                cout << depts[i]->get_did()
                                     << ". "
                                     << depts[i]->get_sf()
                                     << " - "
                                     << depts[i]->get_ff()
                                     << endl;
                            }

                            cout << "\nEnter Department ID = ";

                            cin >> dChoice;

                            Dept *selectedDept;

                            selectedDept = NULL;

                            for(i = 0; i < deptCount; i++) {

                                if(depts[i]->get_did() == dChoice) {

                                    selectedDept = depts[i];

                                    break;
                                }
                            }

                            if(selectedDept == NULL) {

                                cout << "\nInvalid Department ID!";

                                getch();

                                break;
                            }

                            students[studentCount++] =
                                new Student(*selectedDept);

                            cout << "\nAdmission Successful!";

                            getch();

                            break;
                        }

                        case 2: {

                            unsigned long targetPrn;

                            int found = 0;

                            clrscr();

                            cout << "========== SEARCH STUDENT ==========\n\n";

                            cout << "Enter PRN to search: ";

                            cin >> targetPrn;

                            for(i = 0; i < studentCount; i++) {

                                if(students[i]->get_prn() == targetPrn) {

                                    students[i]->display();

                                    found = 1;

                                    break;
                                }
                            }

                            if(!found) {

                                cout << "\nStudent not found!";
                            }

                            getch();

                            break;
                        }

                        case 3: {

                            int foundActive = 0;

                            clrscr();

                            cout << "============================================\n";
                            cout << "           ACTIVE ADMISSIONS\n";
                            cout << "============================================\n";

                            for(i = 0; i < studentCount; i++) {

                                if(students[i]->get_iscancelled() == 0) {

                                    students[i]->display();

                                    foundActive = 1;
                                }
                            }

                            if(!foundActive) {

                                cout << "\nNo active admissions found!";
                            }

                            getch();

                            break;
                        }

                        case 4: {

                            unsigned long targetPrn;

                            int found = 0;

                            clrscr();

                            cout << "========== CANCEL ADMISSION ==========\n\n";

                            cout << "Enter PRN to cancel admission: ";

                            cin >> targetPrn;

                            for(i = 0; i < studentCount; i++) {

                                if(students[i]->get_prn() == targetPrn) {

                                    found = 1;

                                    if(students[i]->get_iscancelled() == 1) {

                                        cout << "\nAdmission is already cancelled!";
                                    }

                                    else {

                                        students[i]->cancel_admission();

                                        cout << "\nAdmission cancelled successfully!";
                                    }

                                    break;
                                }
                            }

                            if(!found) {

                                cout << "\nStudent not found!";
                            }

                            getch();

                            break;
                        }

                        case 5: {

                            int foundCancelled = 0;

                            clrscr();

                            cout << "============================================\n";
                            cout << "          CANCELLED ADMISSIONS\n";
                            cout << "============================================\n";

                            for(i = 0; i < studentCount; i++) {

                                if(students[i]->get_iscancelled() == 1) {

                                    students[i]->display();

                                    foundCancelled = 1;
                                }
                            }

                            if(!foundCancelled) {

                                cout << "\nNo cancelled admissions found!";
                            }

                            getch();

                            break;
                        }

                        case 6: {

                            int dChoice;

                            int admissionCount;

                            clrscr();

                            cout << "============================================\n";
                            cout << "       DEPARTMENT-WISE ACTIVE COUNT\n";
                            cout << "============================================\n\n";

                            for(i = 0; i < deptCount; i++) {

                                admissionCount = 0;

                                int j;

                                for(j = 0; j < studentCount; j++) {

                                    if(students[j]->get_dept()
                                       == depts[i]->get_did()
                                       &&
                                       students[j]->get_iscancelled() == 0) {

                                        admissionCount++;
                                    }
                                }

                                cout << depts[i]->get_sf()
                                     << " : "
                                     << admissionCount
                                     << " active admissions"
                                     << endl;
                            }

                            getch();

                            break;
                        }

                    }

                } while(studentChoice != 7);

                break;
            }

            case 2: {

                int deptChoice;

                do {

                    clrscr();

                    cout << "============================================\n";
                    cout << "              DEPT MENU\n";
                    cout << "============================================\n\n";

                    cout << "1) Add dept\n";
                    cout << "2) List all depts\n";
                    cout << "3) Back to Main Menu\n\n";

                    cout << "Choice = ";

                    cin >> deptChoice;

                    switch(deptChoice) {

                        case 1: {

                            if(deptCount < 10) {

                                depts[deptCount++] =
                                    new Dept();

                                cout << "\nDepartment added successfully!";
                            }

                            else {

                                cout << "\nDepartment limit reached!";
                            }

                            getch();

                            break;
                        }

                        case 2: {

                            clrscr();

                            cout << "============================================\n";
                            cout << "              ALL DEPARTMENTS\n";
                            cout << "============================================\n\n";

                            cout << "ID | Short Form | Full Form\n";

                            cout << "--------------------------------------------\n";

                            for(i = 0; i < deptCount; i++) {

                                depts[i]->display();
                            }

                            getch();

                            break;
                        }

                    }

                } while(deptChoice != 3);

                break;
            }

            case 3:

                cout << "\nExiting Student Admission System...";

                break;

            default:

                cout << "\nInvalid choice!";

                getch();

        }

    } while(choice != 3);

    for(i = 0; i < studentCount; i++) {

        delete students[i];
    }

    for(i = 0; i < deptCount; i++) {

        delete depts[i];
    }

    getch();
}