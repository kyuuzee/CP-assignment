#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<vector>
#include<string>

using namespace std;
//Human class parent of doctor and patient
class Human{
protected:
    string name;
    string IC;
    char sex;
    int age;
    string address;
};
// Doctor class
class Doctor: public Human{
protected:
    string Hire_date;
    int Experience_Years;
    string Qualifications;
public:
    friend void add_Doctor();
    friend void sort_Doctor();
    friend void search_doc_date();
    friend void search_Doctor();
    friend void edit_Doctor();
    friend void delete_Doctor();
    friend void list_Doctor();
};

class Medicine{
protected:
    string name;
    int stock;
    float price;
public:
    friend void add_Medicine();
    friend void sort_Medicine();
    friend void search_Medicine();
    friend void edit_Medicine();
    friend void delete_Medicine();
    friend void list_Medicine();
    friend void search_med_stock();
};

class Patient : public Human{
protected:
    string record_number;
    string services;
    string disease;
    string admission_date;
    int specialist_room_number;
    float total_charge;
    float total_deposited;
    float total_money_to_return;
public:
    friend void add_Patient();
    friend void sort_Patient();
    friend void search_pat_service();
    friend void search_pat_date();
    friend void search_Patient();
    friend void edit_Patient();
    friend void delete_Patient();
    friend void list_Patient();
};

class Operation_Room{
protected:
    int operation_room_number;
    char availability;
public:
    friend void add_room();
    friend void sort_room();
    friend void list_room();
    friend void search_avail();
    friend void search_room();
    friend void edit_room();
    friend void delete_room();
};

//function to add a new doctor to the text file
void add_Doctor(){
    cin.get();
    Doctor d;
    cout << "Please enter the following information: \n";
    cout << "Full Name: \n";
    getline (cin, d.name);
    cout << "IC/Passport: \n";
    getline (cin, d.IC);
    cout << "Sex(m/f): \n";
    cin >> d.sex;
    while (d.sex != 'm' && d.sex != 'f'){
    cout << "Please enter a character that is m or f: ";
    cin >> d.sex;
    }
    cout << "Age: \n";
    cin >> d.age;
    cin.get();
    cout << "Address: \n";
    getline (cin, d.address);
    cout << "Hire date(DD/MM/YYYY) \n";
    getline (cin, d.Hire_date);
    cout << "Years of experience: \n";
    cin >> d.Experience_Years;
    cin.get();
    cout << "Qualifications \n";
    getline (cin, d.Qualifications);
    system("cls");

    //storing values in a file
    fstream docfile ("doc.txt",ios::app);
    //left and setw to ensure the value stored in text file looks nice
    docfile <<left <<setw(25)<<d.name <<left <<setw(15)<< d.IC<<left <<setw(5)<< d.sex<<left <<setw(5)<< d.age
            <<left <<setw(50)<<d.address <<left<<setw(15)<<d.Hire_date<<left<<setw(20)<<d.Experience_Years
            <<left <<d.Qualifications<<"\n";
    cout << "Record is successfully added\n";
    system("pause");
    docfile.close();
}

//function to add new medicine to the text file
void add_Medicine(){
    Medicine m;
    cin.get();
    cout << "Please enter the following information: \n";
    cout << "Name: \n";
    getline (cin, m.name);
    cout << "Stock: \n";
    cin >> m.stock;
    cout << "Price: \n";
    cin >> m.price;
    system("cls");

    //storing values in a file
    fstream medfile ("med.txt",ios::app);
    //left and setw to ensure the value stored in text file looks nice
    medfile <<left<<setw(20)<< m.name <<left<<setw(6)<< m.stock <<left<< m.price <<"\n";
    cout << "Record is successfully added\n";
    system("pause");
    medfile.close();
}

//function to add new patient to the text file
void add_Patient(){
    Patient p;
    cout << "Please enter the following information: \n";
    cout << "Record number: \n";
    cin >> p.record_number;
    cin.get();
    cout << "Full Name: \n";
    getline (cin, p.name);
    cout << "IC/Passport: \n";
    getline (cin, p.IC);
    cout << "Sex(m/f): \n";
    cin >> p.sex;
    while (p.sex != 'm' && p.sex != 'f'){
    cout << "Please enter a character that is m or f: ";
    cin >> p.sex;
    }
    cout << "Age: \n";
    cin >> p.age;
    cin.get();
    cout << "Address: \n";
    getline (cin, p.address);
    cout << "Services(Ordinary/Emergency): \n";
    getline (cin, p.services);
    cout << "Disease description: \n";
    getline (cin, p.disease);
    cout << "Admission date(DD/MM/YYYY): \n";
    getline (cin, p.admission_date);
    cout << "Specialist room number: \n";
    cin >> p.specialist_room_number;
    cout << "Total charge: \n";
    cin >> p.total_charge;
    cout << "Total deposited: \n";
    cin >> p.total_deposited;
    p.total_money_to_return = p.total_charge - p.total_deposited;
    system("cls");

    //storing values in a file
    fstream patfile ("pat.txt",ios::app);
    //left and setw to ensure the value stored in text file looks nice
    patfile <<left<<setw(20)<< p.name <<left<<setw(10)<< p.record_number <<left<<setw(15) <<p.IC
            <<left<<setw(4)<< p.sex <<left<<setw(5)<< p.age <<left<<setw(45)<<p.address<<left <<setw(10)<<p.services
            <<left<<setw(12)<<p.disease<<left<<setw(15)<<p.admission_date<<left<<setw(12)<<p.specialist_room_number
            <<left<<setw(8)<<p.total_charge <<left<<setw(14)<<p.total_deposited
            <<left<<p.total_money_to_return<<"\n";
    cout << "Record is successfully added\n";
    system("pause");
    patfile.close();

}

//function to add a new room to the text file
void add_room(){
    Operation_Room r;
    cout << "Please enter the following information: \n";
    cout << "Operation room number: \n";
    cin >> r.operation_room_number;
    cout << "Availability(Y/N): \n";
    cin >> r.availability;
    while (r.availability != 'Y' && r.availability != 'N'){
    cout << "Please enter a character that is Y or N: ";
    cin >> r.availability;
    break;
    }
    system("cls");

    //storing values in a file
    fstream roomfile ("room.txt",ios::app);
    //left and setw to ensure the value stored in text file looks nice
    roomfile <<left<<setw(13)<< r.operation_room_number <<left<< r.availability << "\n";
    cout << "Record is successfully added\n";
    system("pause");
    roomfile.close();
}

//function to search for a doctor with a specific name
void search_Doctor(){
    string keyword;
    string temp;
    bool notfound = 0;
    cin.get();
    cout << "Enter the name of the doctor: \n";
    getline(cin, keyword);
    fstream docfile ("doc.txt");
    docfile.seekg(0);
    //will display the columns on the top of the output panel so the display will look like a table
    cout<<left <<setw(25)<<"Name" <<left <<setw(15)<< "IC/Passport"<<left <<setw(5)<<"Sex"<<left <<setw(5)<< "Age"
            <<left <<setw(50)<<"Address" <<left<<setw(15)<<"Hire_date"<<left<<setw(20)<<"Experience_Years"
            <<left <<"Qualifications\n";
    //transfer everything in the text file into the string temp. find function will find the name user input
    while(getline(docfile, temp)){
            size_t found = temp.find(keyword);
            if (found != string::npos && found <25){  //it will only look at the first 25 characters to ensure it will only check the name section
            cout <<temp << "\n"; //result that is obtained is printed out
            notfound = 1;
        }
   }
   if (!notfound){
    system("cls");
    cout << "There is no doctor with this name in this hospital. \n";
   }
   system("pause");
   docfile.close();
}

//function to list doctor hired on a certain date
void search_doc_date () {

    string keyword;
    string temp;
    bool notfound = 0;
    cin.get();
    cout << "Enter the hired date: \n";
    getline(cin, keyword);
    fstream docfile ("doc.txt"); //opening file
    docfile.seekg(0);
    //header for data displayed
    cout<<left <<setw(25)<<"Name" <<left <<setw(15)<< "IC/Passport"<<left <<setw(5)<<"Sex"<<left <<setw(5)<< "Age"
            <<left <<setw(50)<<"Address" <<left<<setw(15)<<"Hire_date"<<left<<setw(20)<<"Experience_Years"
            <<left <<"Qualifications\n";
    while(getline(docfile, temp)){
            size_t found = temp.find(keyword);
            if (found != string::npos && found >99 && found <116 ){ //find date at position >99 & <116 in line

            cout <<temp << "\n";
            notfound = 1;
        }
   }
   if (!notfound){
    cout << "There is no doctor hired at this date in this hospital. \n";
   }
   docfile.close();
}

//function to search for a medicine with a specific name
void search_Medicine(){
    string keyword;
    string temp;
    bool notfound = 0;
    cin.get();
    cout << "Enter the name of the medicine: \n";
    getline(cin, keyword);
    system("cls");
    fstream medfile ("med.txt");
    medfile.seekg(0);
    //will display the columns on the top of the output panel so the display will look like a table
    cout << left<<setw(20)<<"Name" <<left<<setw(6)<< "Stock" <<left<< "Price\n";
    //transfer everything in the text file into the string temp. find function will find the name user input
    while(getline(medfile, temp)){
        size_t found = temp.find(keyword);
            if (found != string::npos && found <20){ //it will only look at the first 20 characters to ensure it will only check the name section
            cout << temp << "\n"; //result that is obtained is printed out
            notfound = 1;
        }
   }
   if (!notfound){
    system("cls");
    cout << "The medicine does not exist. \n";
   }
   medfile.close();
   system("pause");
}

//function to list the medicine that are out of stock
void search_med_stock(){
    string keyword;
    string temp;
    bool notfound = 0;
    system("cls");
    keyword = "0";
    fstream medfile ("med.txt"); //open file
    medfile.seekg(0);
    cout << left<<setw(20)<<"Name" <<left<<setw(6)<< "Stock" <<left<< "Price\n"; //header for data displayed
    while(getline(medfile, temp)){
        size_t found = temp.find(keyword);
            if (found != string::npos && found >19 && found<21 ){ //find the keyword at position >19 and <21 in line
            cout << temp << "\n";
            notfound = 1;
        }
   }
   if (!notfound){
    system("cls");
    cout << "No medicine is out of stock. \n";
   }
   medfile.close();
}

//function to search for a patient with a specific name or record number
void search_Patient(){
    string keyword;
    string temp;
    int choice;
    bool notfound = 0;
    cout << "Enter the way you wish to search: \n"
         << "1. Name \n"
         << "2. Record number \n"
         << "Choice:";
    cin >> choice;
    system("cls");
    cin.get();
    if (choice == 1){
    cout << "Enter the name of the patient: \n";
    getline(cin, keyword);
    system("cls");
    fstream patfile ("pat.txt");
    patfile.seekg(0);
    //will display the columns on the top of the output panel so the display will look like a table
    cout <<left<<setw(20)<< "Name" <<left<<setw(10)<< "Record_No" <<left<<setw(15) <<"IC/Passport"
            <<left<<setw(4)<< "Sex" <<left<<setw(5)<< "Age" <<left<<setw(45)<<"Address"<<left <<setw(10)<<"Services"
            <<left<<setw(12)<<"Disease"<<left<<setw(15)<<"Admission date"<<left<<setw(12)<<"Room_number"
            <<left<<setw(8)<<"Charge" <<left<<setw(14)<<"Total_deposit"
            <<left<<"Total left\n";
    //transfer everything in the text file into the string temp. find function will find the name user input
    while(getline(patfile, temp)){
        size_t found = temp.find(keyword);
        if (found != string::npos && found <20){ //it will only look at the first 20 characters to ensure it will only check the name section
            cout << temp << "\n";  //result that is obtained is printed out
            notfound=1;
        }
   }
   if (!notfound){
    system("cls");
    cout << "The record for the patient you are searching for does not exist. \n";
   }
   patfile.close();
    }
   else if(choice == 2){
    cout << "Enter the record number of the patient: \n";
    getline(cin, keyword);
    system("cls");
    fstream patfile ("pat.txt");
    patfile.seekg(0);
    //will display the columns on the top of the output panel so the display will look like a table
    cout <<left<<setw(20)<< "Name" <<left<<setw(10)<< "Record_No" <<left<<setw(15) <<"IC/Passport"
         <<left<<setw(4)<< "Sex" <<left<<setw(5)<< "Age" <<left<<setw(45)<<"Address"<<left <<setw(10)<<"Services"
         <<left<<setw(12)<<"Disease"<<left<<setw(15)<<"Admission_date"<<left<<setw(12)<<"Room_number"
         <<left<<setw(8)<<"Charge" <<left<<setw(14)<<"Total_deposit"
         <<left<<"Total_left\n";
    //transfer everything in the text file into the string temp. find function will find the record number user input
    while(getline(patfile, temp)){
        size_t found = temp.find(keyword);
        if (found != string::npos && found >19 && found <30){ //it will only look at the characters between 20 and 30 to ensure it will only check the record no section
            cout << temp << "\n";  //result that is obtained is printed out
            notfound=1;
        }
   }
   if (!notfound){
    system("cls");
    cout << "The record for the patient you are searching for does not exist. \n";
   }
   patfile.close();
   }
   else
    cout<< "Invalid option. \n";
}

//function to list patient admitted at date chosen by user
void search_pat_date() {

    string keyword;
    string temp;
    bool notfound = 0;
    cout << "Enter admission date: \n";
    cin >> keyword;
    system("cls");
    fstream patfile ("pat.txt");//open file
    patfile.seekg(0);
    //header for data displayed
    cout <<left<<setw(20)<< "Name" <<left<<setw(10)<< "Record_No" <<left<<setw(15) <<"IC/Passport"
         <<left<<setw(4)<< "Sex" <<left<<setw(5)<< "Age" <<left<<setw(45)<<"Address"<<left <<setw(10)<<"Services"
         <<left<<setw(12)<<"Disease"<<left<<setw(15)<<"Admission_date"<<left<<setw(12)<<"Room_number"
         <<left<<setw(8)<<"Charge" <<left<<setw(14)<<"Total_deposit"
         <<left<<"Total_left\n";
    while(getline(patfile, temp)){
        size_t found = temp.find(keyword);
        if (found != string::npos && found >120 && found<137){ //find date at position >120 & <137 in line
            cout << temp << "\n";
            notfound=1;
        }
   }
   if (!notfound){
    cout << "No patient was admitted on this date. \n";
   }
   patfile.close();
}

//function to list patient based on the service (ordinary/emergency)
void search_pat_service() {
    int choice;
    string keyword;
    string temp;
    bool notfound = 0;
    cout<< "Choose which services to be listed:" <<endl
        << "1. Ordinary" <<endl
        << "2. Emergency" <<endl
        << "Choice:";
    cin>> choice;
    system("cls");
    if (choice == 1) //keyword changes based on user's choice
        keyword = "Ordinary";
    else if (choice == 2)
        keyword = "Emergency";
    fstream patfile ("pat.txt"); //open file
    patfile.seekg(0);
    //header for data displayed
    cout <<left<<setw(20)<< "Name" <<left<<setw(10)<< "Record_No" <<left<<setw(15) <<"IC/Passport"
            <<left<<setw(4)<< "Sex" <<left<<setw(5)<< "Age" <<left<<setw(45)<<"Address"<<left <<setw(10)<<"Services"
            <<left<<setw(12)<<"Disease"<<left<<setw(15)<<"Admission date"<<left<<setw(12)<<"Room_number"
            <<left<<setw(8)<<"Charge" <<left<<setw(14)<<"Total_deposit"
            <<left<<"Total left\n";
    while(getline(patfile, temp)){
        size_t found = temp.find(keyword);
        if (found != string::npos && found >98 && found <110){ //find service at position >98 & < 110 in line
            cout << temp << "\n";
            notfound=1;
        }
   }
   if (!notfound){
    cout << "0 patient. \n";
   }
   patfile.close();

}

//function to search for a room with a specific number
void search_room(){
    string keyword;
    string temp;
    bool notfound = 0;
    cin.get();
    cout << "Enter the operation room number: \n";
    getline(cin, keyword);
    system("cls");
    fstream roomfile ("room.txt");
    roomfile.seekg(0);
    //will display the columns on the top of the output panel so the display will look like a table
    cout << left<<setw(13)<< "Room number" <<left<< "Availability\n";
    //transfer everything in the text file into the string temp. find function will find the name user input
    while(getline(roomfile, temp)){
        size_t found = temp.find(keyword);
            if (found != string::npos && found <13){//it will only look at the first 13 characters to ensure it will only check the name section
            cout << temp << "\n"; //result that is obtained is printed out
            notfound = 1;
        }
   }
   if (!notfound){
    system("cls");
    cout << "The operation room does not exist. \n";
   }
   roomfile.close();
    system("pause");
}

//function to list the operation room that are available
void search_avail(){
    string keyword;
    string temp;
    bool notfound = 0;
    system("cls");
    keyword = "Y"; //Y means that the room is available
    fstream roomfile ("room.txt"); //open file
    roomfile.seekg(0);
    //header for data displayed
    cout << left<<setw(13)<< "Room number" <<left<< "Availability\n";
    while(getline(roomfile, temp)){
        size_t found = temp.find(keyword);
            if (found != string::npos && found >12){ //find keyword at position >12 in line
            cout << temp << "\n";
            notfound = 1;
        }
   }
   if (!notfound){
    system("cls");
    cout << "No operation room available \n";
   }
   roomfile.close();
}

//function to edit anything about the doctor
void edit_Doctor(){
    string keyword;
    string temp;
    int choice;
    string edit;
    char ans;
    bool notfound = 0;
    bool modify = 0;
    cin.get();
    cout << "Enter the name of the doctor you want to edit: \n";
    getline(cin, keyword);
    system("cls");
    fstream docfile ("doc.txt");
    ofstream tmpfile ("tmp.txt");
    docfile.seekg(0);
    tmpfile.seekp(0);
    cout<<left <<setw(25)<<"Name" <<left <<setw(15)<< "IC/Passport"<<left <<setw(5)<<"Sex"<<left <<setw(5)<< "Age"
        <<left <<setw(50)<<"Address" <<left<<setw(15)<<"Hire_date"<<left<<setw(20)<<"Experience_Years"
        <<left <<"Qualifications\n";

    while(getline(docfile, temp)){
            size_t found = temp.find(keyword);
            if (found != string::npos && found <25){
                cout <<temp << "\n";
            notfound = 1;
            cout<<endl;
            cout << "Select the field you want to edit: \n"
                 << "1. Name\n"
                 << "2. IC/Passport\n"
                 << "3. Sex\n"
                 << "4. Age\n"
                 << "5. Address\n"
                 << "6. Hire date\n"
                 << "7. Experience years\n"
                 << "8. Qualifications\n"
                 << "Choice:" ;
            cin >> choice;
            cout << endl;
            cin.get();
                switch (choice)
                {
                case 1:
                    cout << "Enter the new name of the doctor: \n";
                    getline(cin, edit);
                    edit.resize(25); //resize the edit size to ensure consistency
                    temp.replace(0,25,edit); //the 1st to 25th character is replace by your edit input
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n"; //the edited line is stored into the tmpfile
                    modify =1;
                    break;
                case 2:
                    cout << "Enter the new IC/Passport of the doctor: \n";
                    getline(cin, edit);
                    edit.resize(15);
                    temp.replace(25,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 3:
                    cout << "Enter the new sex of the doctor: \n";
                    getline(cin, edit);
                    edit.resize(5);
                    temp.replace(40,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 4:
                    cout << "Enter the new age of the doctor: \n";
                    getline(cin, edit);
                    edit.resize(5);
                    temp.replace(45,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 5:
                    cout << "Enter the new address of the doctor: \n";
                    getline(cin, edit);
                    edit.resize(50);
                    temp.replace(50,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 6:
                    cout << "Enter the new hire date of the doctor: \n";
                    getline(cin, edit);
                    edit.resize(15);
                    temp.replace(100,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 7:
                    cout << "Enter the new experience in years of the doctor: \n";
                    getline(cin, edit);
                    edit.resize(20);
                    temp.replace(115,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 8:
                    cout << "Enter the new qualifications of the doctor: \n";
                    getline(cin, edit);
                    edit.resize(20);
                    temp.replace(135,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                default:
                    cout << "Invalid option.";
                }
            system("pause");
        }
   }
   if (!notfound){
    system("cls");
    cout << "There is no doctor with this name in this hospital. \n";
    system("pause");
   }
   docfile.close();
   tmpfile.close();
   if (modify){
        fstream docfile ("doc.txt");
        ofstream tmpfile ("tmp.txt",ios::app);
        docfile.seekg(0);
        tmpfile.seekp(0);

        while (getline(docfile, temp)){
            if (temp.substr(0,keyword.size()) != keyword) //anything that doesn't have the keyword will be transfer to the tmp file
                tmpfile<<temp<<"\n";
        }
        docfile.close();
        tmpfile.close();
        remove("doc.txt");
        rename("tmp.txt", "doc.txt");
   }
}

//function to edit anything about medicine
void edit_Medicine(){
    string keyword;
    string temp;
    int choice;
    string edit;
    string change;
    bool notfound = 0;
    bool modify = 0;
    cin.get();
    cout << "Enter the name of the medicine you want to edit: \n";
    getline(cin, keyword);
    system("cls");
    fstream medfile ("med.txt");
    ofstream tmpfile ("tmp.txt");
    medfile.seekg(0);
    tmpfile.seekp(0);

    cout << left<<setw(20)<<"Name" <<left<<setw(6)<< "Stock" <<left<< "Price\n";
    while(getline(medfile, temp)){
        size_t found = temp.find(keyword);
            if (found != string::npos && found <20){
            cout << temp << "\n";
            notfound = 1;
            cout << "\nSelect the field you want to edit: \n"
                 << "1. Name\n"
                 << "2. Stock\n"
                 << "3. Price\n"
                 << "Choice:";
            cin >> choice;
            cout<<endl;
            cin.get();
                switch (choice)
                {
                case 1:
                    cout << "Enter the new name of the medicine: \n";
                    getline(cin, edit);
                    edit.resize(20); //resize the edit size to ensure consistency
                    temp.replace(0,20,edit); //the 1st to 20th character is replace by your edit input
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n"; //the edited line is stored into the tmpfile
                    modify =1;
                    break;
                case 2:
                    cout << "Enter the new stock of the medicine: \n";
                    getline(cin, edit);
                    edit.resize(6);
                    temp.replace(20,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 3:
                    cout << "Enter the new price of the medicine: \n";
                    getline(cin, edit);
                    edit.resize(8);
                    temp.replace(26,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                default:
                    cout << "Invalid option.";
                }
            system("pause");
        }
   }
   if (!notfound){
    system("cls");
    cout << "The medicine does not exist. \n";
    system("pause");
   }
   medfile.close();
   tmpfile.close();
   if (modify){

    fstream medfile ("med.txt");
    ofstream tmpfile ("tmp.txt",ios::app);
    medfile.seekg(0);
    tmpfile.seekp(0);
    while (getline(medfile, temp)){
        if (temp.substr(0,keyword.size()) != keyword)
            tmpfile<<temp<<"\n"; //anything that doesn't have the keyword will be transfer to the tmp file
        }
        medfile.close();
        tmpfile.close();
        remove("med.txt");
        rename("tmp.txt", "med.txt");
   }
}

//function to edit anything about patient
void edit_Patient(){
    string keyword;
    string temp;
    int choice;
    int option;
    string edit;
    bool notfound = 0;
    bool modify = 0;
    cout << "Enter the way you wish to search for the patient: \n"
         << "1. Name \n"
         << "2. Record number \n"
         << "Choice:";
    cin >> choice;
    system("cls");
    if (choice == 1){
    cin.get();
    cout << "Enter the name of the patient you wish to edit: \n";
    getline(cin, keyword);
    system("cls");
    fstream patfile ("pat.txt");
    ofstream tmpfile ("tmp.txt");
    patfile.seekg(0);
    tmpfile.seekp(0);
    cout <<left<<setw(20)<< "Name" <<left<<setw(10)<< "Record_No" <<left<<setw(15) <<"IC/Passport"
            <<left<<setw(4)<< "Sex" <<left<<setw(5)<< "Age" <<left<<setw(45)<<"Address"<<left <<setw(10)<<"Services"
            <<left<<setw(12)<<"Disease"<<left<<setw(15)<<"Admission_date"<<left<<setw(12)<<"Room_number"
            <<left<<setw(8)<<"Charge" <<left<<setw(14)<<"Total_deposit"
            <<left<<"Total_left\n";
    while(getline(patfile, temp)){
        size_t found = temp.find(keyword);
        if (found != string::npos && found <21){
            cout << temp << "\n";
            notfound=1;
            cout << "\nSelect the field you want to edit: \n"
                 << "1. Name\n"
                 << "2. Record No\n"
                 << "3. IC/Passport\n"
                 << "4. Sex\n"
                 << "5. Age\n"
                 << "6. Address\n"
                 << "7. Services\n"
                 << "8. Disease\n"
                 << "9. Admission date\n"
                 << "10. Room number\n"
                 << "11. Payment details\n"
                 << "Choice:";
            cin >> option;
            cin.get();
            cout<<endl;
            switch (option)
                {
                case 1:
                    cout << "Enter the new name of the patient: \n";
                    getline(cin, edit);
                    edit.resize(20); //resize the edit size to ensure consistency
                    temp.replace(0,20,edit); //the 1st to 20th character is replace by your edit input
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n"; //the edited line is stored into the tmpfile
                    modify =1;
                    break;
                case 2:
                    cout << "Enter the new record no of the patient: \n";
                    getline(cin, edit);
                    edit.resize(10);
                    temp.replace(20,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 3:
                    cout << "Enter the new IC/Passport of the patient: \n";
                    getline(cin, edit);
                    edit.resize(15);
                    temp.replace(30,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 4:
                    cout << "Enter the new sex of the patient: \n";
                    getline(cin, edit);
                    edit.resize(4);
                    temp.replace(45,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 5:
                    cout << "Enter the new age of the patient: \n";
                    getline(cin, edit);
                    edit.resize(5);
                    temp.replace(49,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 6:
                    cout << "Enter the new address of the patient: \n";
                    getline(cin, edit);
                    edit.resize(45);
                    temp.replace(54,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 7:
                    cout << "Enter the new service(ordinary/emergency) of the patient: \n";
                    getline(cin, edit);
                    edit.resize(10);
                    temp.replace(99,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 8:
                    cout << "Enter the new disease of the patient: \n";
                    getline(cin, edit);
                    edit.resize(12);
                    temp.replace(109,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 9:
                    cout << "Enter the new admission date of the patient: \n";
                    getline(cin, edit);
                    edit.resize(15);
                    temp.replace(121,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 10:
                    cout << "Enter the new room number of the patient: \n";
                    getline(cin, edit);
                    edit.resize(12);
                    temp.replace(136,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 11:
                    cout << "Enter the new payment charge on the patient: \n";
                    getline(cin, edit);
                    edit.resize(8);
                    temp.replace(148,edit.size(),edit);
                    cout << "Enter the new total deposit of the patient: \n";
                    getline(cin, edit);
                    edit.resize(14);
                    temp.replace(156,edit.size(),edit);
                    cout << "Enter the new total amount left the patient has to pay: \n";
                    getline(cin, edit);
                    edit.resize(10);
                    temp.replace(170,edit.size(),edit);
                    tmpfile << temp <<"\n";
                    modify =1;
                    cout << "Information has been edited.\n";
                    break;
                default:
                    cout << "Invalid option!!!!!!";
                }
            system("pause");
        }
   }
   if (!notfound){
    system("cls");
    cout << "The record for the patient you are searching for does not exist. \n";
    system("pause");
   }
   patfile.close();
   tmpfile.close();
   if (modify){
        fstream patfile ("pat.txt");
        ofstream tmpfile ("tmp.txt",ios::app);
        patfile.seekg(0);
        tmpfile.seekp(0);

        while (getline(patfile, temp)){
            if (temp.substr(0,keyword.size()) != keyword) //anything that doesn't have the keyword will be transfer to the tmp file
                tmpfile<<temp<<"\n";
        }
        patfile.close();
        tmpfile.close();
        remove("pat.txt");
        rename("tmp.txt", "pat.txt");
   }
    }
   else if(choice == 2){
    cin.get();
    cout << "Enter the record number of the patient: \n";
    getline(cin, keyword);
    system("cls");
    fstream patfile ("pat.txt");
    ofstream tmpfile ("tmp.txt");
    patfile.seekg(0);
    tmpfile.seekp(0);
    cout <<left<<setw(20)<< "Name" <<left<<setw(10)<< "Record_No" <<left<<setw(15) <<"IC/Passport"
         <<left<<setw(4)<< "Sex" <<left<<setw(5)<< "Age" <<left<<setw(45)<<"Address"<<left <<setw(10)<<"Services"
         <<left<<setw(12)<<"Disease"<<left<<setw(15)<<"Admission_date"<<left<<setw(12)<<"Room_number"
         <<left<<setw(8)<<"Charge" <<left<<setw(14)<<"Total_deposit"
         <<left<<"Total_left\n";
    while(getline(patfile, temp)){
        size_t found = temp.find(keyword);
        if (found != string::npos && found >19 && found <30){
            cout << temp << "\n";
            notfound=1;
            cout << "\nSelect the field you want to edit: \n"
                 << "1. Name\n"
                 << "2. Record No\n"
                 << "3. IC/Passport\n"
                 << "4. Sex\n"
                 << "5. Age\n"
                 << "6. Address\n"
                 << "7. Services\n"
                 << "8. Disease\n"
                 << "9. Admission date\n"
                 << "10. Room number\n"
                 << "11. Payment details\n"
                 << "Choice:";
            cin >> option;
            cin.get();
            cout<<endl;
            switch (option)
                {
                case 1:
                    cout << "Enter the new name of the patient: \n";
                    getline(cin, edit);
                    edit.resize(20); //resize the edit size to ensure consistency
                    temp.replace(0,20,edit); //the 1st to 20th character is replace by your edit input
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n"; //the edited line is stored into the tmpfile
                    modify =1;
                    break;
                case 2:
                    cout << "Enter the new record no of the patient: \n";
                    getline(cin, edit);
                    edit.resize(10);
                    temp.replace(20,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 3:
                    cout << "Enter the new IC/Passport of the patient: \n";
                    getline(cin, edit);
                    edit.resize(15);
                    temp.replace(30,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 4:
                    cout << "Enter the new sex of the patient: \n";
                    getline(cin, edit);
                    edit.resize(4);
                    temp.replace(45,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 5:
                    cout << "Enter the new age of the patient: \n";
                    getline(cin, edit);
                    edit.resize(5);
                    temp.replace(49,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 6:
                    cout << "Enter the new address of the patient: \n";
                    getline(cin, edit);
                    edit.resize(45);
                    temp.replace(54,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 7:
                    cout << "Enter the new service(ordinary/emergency) of the patient: \n";
                    getline(cin, edit);
                    edit.resize(10);
                    temp.replace(99,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 8:
                    cout << "Enter the new disease of the patient: \n";
                    getline(cin, edit);
                    edit.resize(12);
                    temp.replace(109,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 9:
                    cout << "Enter the new admission date of the patient: \n";
                    getline(cin, edit);
                    edit.resize(15);
                    temp.replace(121,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 10:
                    cout << "Enter the new room number of the patient: \n";
                    getline(cin, edit);
                    edit.resize(12);
                    temp.replace(136,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                case 11:
                    cout << "Enter the new payment charge on the patient: \n";
                    getline(cin, edit);
                    edit.resize(8);
                    temp.replace(148,edit.size(),edit);
                    cout << "Enter the new total deposit of the patient: \n";
                    getline(cin, edit);
                    edit.resize(14);
                    temp.replace(156,edit.size(),edit);
                    cout << "Enter the new total amount left the patient has to pay: \n";
                    getline(cin, edit);
                    edit.resize(10);
                    temp.replace(170,edit.size(),edit);
                    tmpfile << temp <<"\n";
                    modify =1;
                    cout << "Information has been edited.\n";
                    break;
                default:
                    cout << "Invalid option.";
                }
            system("pause");
        }

   }
   if (!notfound){
    system("cls");
    cout << "The record for the patient you are searching for does not exist. \n";
    system("pause");
   }
   patfile.close();
   tmpfile.close();
   if (modify){
        fstream patfile ("pat.txt");
        ofstream tmpfile ("tmp.txt",ios::app);
        patfile.seekg(0);
        tmpfile.seekp(0);
        //if (tmpfile.is_open()){
        //cout << "No problem \n";}
        while (getline(patfile, temp)){
            if (temp.substr(20,keyword.size()) != keyword) //anything that doesn't have the keyword will be transfer to the tmp file
                tmpfile<<temp<<"\n";
        }
        patfile.close();
        tmpfile.close();
        remove("pat.txt");
        rename("tmp.txt", "pat.txt");
   }
   }
   else
    cout<< "Invalid option!!!! \n";
}

//function to edit anything about room
void edit_room(){
    string keyword;
    string temp;
    int choice;
    string edit;
    bool notfound = 0;
    bool modify = 0;
    cin.get();
    cout << "Enter the operation room number you want to edit: \n";
    getline(cin, keyword);
    system("cls");
    fstream roomfile ("room.txt");
    ofstream tmpfile ("tmp.txt");
    roomfile.seekg(0);
    tmpfile.seekp(0);
    cout << left<<setw(13)<< "Room number" <<left<< "Availability\n";

    while(getline(roomfile, temp)){
        size_t found = temp.find(keyword);
            if (found != string::npos && found <13){
            cout << temp << "\n";
            notfound = 1;
            cout << "\nSelect the field you want to edit: \n"
                 << "1. Room number\n"
                 << "2. Availability\n"
                 << "Choice:";
            cin >> choice;
            cout<<endl;
            cin.get();
            switch (choice)
                {
                case 1:
                    cout << "Enter the new room number: \n";
                    getline(cin, edit);
                    edit.resize(13); //resize the edit size to ensure consistency
                    temp.replace(0,13,edit); //the 1st to 13th character is replace by your edit input
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n"; //the edited line is stored into the tmpfile
                    modify =1;
                    break;
                case 2:
                    cout << "Enter the new availability: \n";
                    getline(cin, edit);
                    edit.resize(2);
                    temp.replace(13,edit.size(),edit);
                    cout << "Information has been edited.\n";
                    tmpfile << temp <<"\n";
                    modify =1;
                    break;
                default:
                    cout << "Invalid option.";
                }
            system("pause");
        }
   }
   if (!notfound){
    system("cls");
    cout << "The operation room does not exist. \n";
    system("pause");
   }
   roomfile.close();
   tmpfile.close();
   if (modify){
        fstream roomfile ("room.txt");
        ofstream tmpfile ("tmp.txt", ios::app);
        roomfile.seekg(0);
        tmpfile.seekp(0);
        while (getline(roomfile, temp)){
            if (temp.substr(0,keyword.size()) != keyword) //anything that doesn't have the keyword will be transfer to the tmp file
                tmpfile<<temp<<"\n";
        }
        roomfile.close();
        tmpfile.close();
        remove("room.txt");
        rename("tmp.txt", "room.txt");
   }
}

//function to delete doctor of your choice
void delete_Doctor(){
    string keyword;
    string temp;
    string del;
    char decision;
    bool notfound = 0;
    cin.get();
    cout << "Enter the name of the doctor you want to delete: \n";
    getline(cin, keyword);
    system("cls");
    fstream docfile ("doc.txt");
    docfile.seekg(0);
    cout<<left <<setw(25)<<"Name" <<left <<setw(15)<< "IC/Passport"<<left <<setw(5)<<"Sex"<<left <<setw(5)<< "Age"
            <<left <<setw(50)<<"Address" <<left<<setw(15)<<"Hire_date"<<left<<setw(20)<<"Experience_Years"
            <<left <<"Qualifications\n";
    while(getline(docfile, temp)){
            size_t found = temp.find(keyword);
            if (found != string::npos && found <25){
            cout <<temp << "\n";
            notfound = 1;
            docfile.close();
            cout << "Are you sure you want to delete this record?(Y/N)\n";
            cin >> decision;
            if (decision == 'Y' || decision =='y'){
                fstream docfile ("doc.txt");
                ofstream tmpfile ("tmp.txt");
                docfile.seekg(0);
                tmpfile.seekp(0);
                //if (tmpfile.is_open()){
                //cout << "No problem \n";}
                while (getline(docfile, del)){
                if (del.substr(0,keyword.size()) != keyword)
                tmpfile<<del<<"\n"; //information that is not the keyword will be stored in the tmpfile temporarily
                }
                docfile.close();
                tmpfile.close();
                remove("doc.txt");
                rename("tmp.txt", "doc.txt");
                cout << "Record successfully deleted.\n";
                system("pause");
            }
        }
   }
   if (!notfound){
    cout << "There is no doctor with this name in this hospital. \n";
    system("pause");
   }
   docfile.close();
}

//function to delete medicine of your choice
void delete_Medicine(){
    string keyword;
    string temp;
    string del;
    char decision;
    bool notfound = 0;
    cin.get();
    cout << "Enter the name of the medicine you want to delete: \n";
    getline(cin, keyword);
    system("cls");
    fstream medfile ("med.txt");
    medfile.seekg(0);
    cout << left<<setw(20)<<"Name" <<left<<setw(6)<< "Stock" <<left<< "Price\n";
    while(getline(medfile, temp)){
        size_t found = temp.find(keyword);
            if (found != string::npos && found <20){
            cout << temp << "\n";
            notfound = 1;
            medfile.close();
            cout << "Are you sure you want to delete this record?(Y/N)\n";
            cin >> decision;
            if (decision == 'Y' || decision =='y'){
            fstream medfile ("med.txt");
            ofstream tmpfile ("tmp.txt");
            medfile.seekg(0);
            tmpfile.seekp(0);
            //if (tmpfile.is_open()){
            //cout << "No problem \n";}
            while (getline(medfile, del)){
            if (del.substr(0,keyword.size()) != keyword) //information that is not the keyword will be stored in the tmpfile temporarily
                tmpfile<<del<<"\n";
            }
            medfile.close();
            tmpfile.close();
            remove("med.txt");
            rename("tmp.txt", "med.txt");
            cout << "Record successfully deleted.\n";
            system("pause");
        }
   }
   if (!notfound){
    system("cls");
    cout << "The medicine does not exist. \n";
    system("pause");
   }
   medfile.close();
    }
}

//function to delete patient of your choice
void delete_Patient(){
    string keyword;
    string temp;
    string del;
    char decision;
    bool notfound = 0;
    cin.get();
    cout << "Enter the record number of the patient you want to delete: \n";
    getline(cin, keyword);
    system("cls");
    fstream patfile ("pat.txt");
    patfile.seekg(0);
    cout <<left<<setw(20)<< "Name" <<left<<setw(10)<< "Record No" <<left<<setw(15) <<"IC/Passport"
         <<left<<setw(4)<< "Sex" <<left<<setw(5)<< "Age" <<left<<setw(45)<<"Address"<<left <<setw(10)<<"Services"
         <<left<<setw(12)<<"Disease"<<left<<setw(15)<<"Admission date"<<left<<setw(12)<<"Room number"
         <<left<<setw(8)<<"Charge" <<left<<setw(14)<<"Total deposit"
         <<left<<"Total left\n";
    while(getline(patfile, temp)){
        size_t found = temp.find(keyword);
        if (found != string::npos && found >19 && found <30){
            cout << temp << "\n";
            notfound=1;
            patfile.close();
            cout << "\nAre you sure you want to delete this record?(Y/N):\n";
            cin >> decision;
                if (decision == 'Y' || decision =='y'){
                fstream patfile ("pat.txt");
                ofstream tmpfile ("tmp.txt");
                patfile.seekg(0);
                tmpfile.seekp(0);

                while (getline(patfile, del)){
                if (del.substr(20,keyword.size()) != keyword) //information that is not the keyword will be stored in the tmpfile temporarily
                tmpfile<<del<<"\n";
                }
                patfile.close();
                tmpfile.close();
                remove("pat.txt");
                rename("tmp.txt", "pat.txt");
                cout << "Record successfully deleted.\n";
                system("pause");
                }
        }
   }
   if (!notfound){
    cout << "The record for the patient you are searching for does not exist. \n";
    system("pause");
   }
   patfile.close();
}

//function to delete room of your choice
void delete_room(){
    string keyword;
    string temp;
    string del;
    char decision;
    bool notfound = 0;
    cin.get();
    cout << "Enter the operation room number you want to delete: \n";
    getline(cin, keyword);
    system("cls");
    fstream roomfile ("room.txt");
    roomfile.seekg(0);
    cout << left<<setw(13)<< "Room number" <<left<< "Availability\n";
    while(getline(roomfile, temp)){
        size_t found = temp.find(keyword);
            if (found != string::npos && found <13){
            cout << temp << "\n";
            notfound = 1;
            roomfile.close();
            cout << "Are you sure you want to delete this record?(Y/N)\n";
            cin >> decision;
            if (decision == 'Y' || decision =='y'){
                fstream roomfile ("room.txt");
                ofstream tmpfile ("tmp.txt");
                roomfile.seekg(0);
                tmpfile.seekp(0);

                while (getline(roomfile, del)){
                if (del.substr(0,keyword.size()) != keyword) //information that is not the keyword will be stored in the tmpfile temporarily
                tmpfile<<del<<"\n";
                }
                roomfile.close();
                tmpfile.close();
                remove("room.txt");
                rename("tmp.txt", "room.txt");
                cout << "Record successfully deleted.\n";
                system("pause");
                }
        }
   }
   if (!notfound){
    cout << "The operation room does not exist. \n";
    system("pause");
   }
   roomfile.close();

}

//function to list doctor alphabetically
void sort_Doctor() {

    string line;
    vector <string> doc;

    ifstream file("doc.txt"); //open file

    while (getline(file, line)) {
        if(line.size() > 0){
            doc.push_back(line); //inserting data from txt file into vector
        }
    }

    file.close();

    //sort doctor
    for (int i=0; i<doc.size();i++) {
        for(int j=0; j<(doc.size()-1); j++) {
            if (doc[j] > doc[j+1]) {
                string temp = doc[j];
                doc[j] = doc[j+1];
                doc[j+1] = temp;
            }
        }
    }
    //display doctor
    cout<<left <<setw(25)<<"Name" <<left <<setw(15)<< "IC/Passport"<<left <<setw(5)<<"Sex"<<left <<setw(5)<< "Age"
    <<left <<setw(50)<<"Address" <<left<<setw(15)<<"Hire_date"<<left<<setw(20)<<"Experience_Years"
    <<left <<"Qualifications\n";

    for (int i=0; i<doc.size(); i++){
        cout<<doc[i]<<endl;
    }

}

//function to list medicine alphabetically
void sort_Medicine() {

    string line;
    vector <string> med;

    ifstream file("med.txt"); //open file

    while (getline(file, line)) {
        if(line.size() > 0){
            med.push_back(line); //put data from txt file into vector
        }
    }

    file.close();

    //sort medicine
    cout << left<<setw(20)<<"Name" <<left<<setw(6)<< "Stock" <<left<< "Price\n";
    for (int i=0; i<med.size();i++) {
        for(int j=0; j<(med.size()-1); j++) {
            if (med[j] > med[j+1]) {
                string temp = med[j];
                med[j] = med[j+1];
                med[j+1] = temp;
            }
        }
    }
    //display medicine
    for (int i=0; i<med.size(); i++){
        cout<<med[i]<<endl;
    }

}

//function to list patient alphabetically
void sort_Patient() {

    string line;
    vector <string> pat;

    ifstream file("pat.txt"); //open file

    while (getline(file, line)) {
        if(line.size() > 0){
            pat.push_back(line); //put data from txt file into vector
        }
    }

    file.close();

    //sort patient
    for (int i=0; i<pat.size();i++) {
        for(int j=0; j<(pat.size()-1); j++) {
            if (pat[j] > pat[j+1]) {
                string temp = pat[j];
                pat[j] = pat[j+1];
                pat[j+1] = temp;
            }
        }
    }
    //display patient
    cout <<left<<setw(20)<< "Name" <<left<<setw(10)<< "Record_No" <<left<<setw(15) <<"IC/Passport"
            <<left<<setw(4)<< "Sex" <<left<<setw(5)<< "Age" <<left<<setw(45)<<"Address"<<left <<setw(10)<<"Services"
            <<left<<setw(12)<<"Disease"<<left<<setw(15)<<"Admission date"<<left<<setw(12)<<"Room_number"
            <<left<<setw(8)<<"Charge" <<left<<setw(14)<<"Total_deposit"
            <<left<<"Total left\n";
    for (int i=0; i<pat.size(); i++){
        cout<<pat[i]<<endl;
    }

}

//function to list room alphabetically
void sort_room() {

    string line;
    vector <string> room;

    ifstream file("room.txt"); //open file

    while (getline(file, line)) {
        if(line.size() > 0){
            room.push_back(line); //insert data into vector
        }
    }
    file.close();

    //sort room
    for (int i=0; i<room.size();i++) {
        for(int j=0; j<(room.size()-1); j++) {
            if (room[j] > room[j+1]) {
                string temp = room[j];
                room[j] = room[j+1];
                room[j+1] = temp;
            }
        }
    }
    //display room
    cout << left<<setw(13)<< "Room number" <<left<< "Availability\n";
    for (int i=0; i<room.size(); i++){
        cout<<room[i]<<endl;
    }

}

//function to list all the doctors in file
void list_Doctor() {

    string line;
    vector <string> doc;

    ifstream file("doc.txt");//open file

    while (getline(file, line)) {
        if(line.size() > 0){
            doc.push_back(line); //insert into vector
        }
    }

    file.close();

    //data header
    cout<<left <<setw(25)<<"Name" <<left <<setw(15)<< "IC/Passport"<<left <<setw(5)<<"Sex"<<left <<setw(5)<< "Age"
    <<left <<setw(50)<<"Address" <<left<<setw(15)<<"Hire_date"<<left<<setw(20)<<"Experience_Years"
    <<left <<"Qualifications\n";

    //display doctor
    for (int i=0; i<doc.size(); i++){
        cout<<doc[i]<<endl;
    }
}

//function to list all the medicines in file
void list_Medicine() {

    string line;
    vector <string> med;

    ifstream file("med.txt");//open file

    while (getline(file, line)) {
        if(line.size() > 0){
            med.push_back(line);//put into vector
        }
    }

    file.close();
    //data header
    cout << left<<setw(20)<<"Name" <<left<<setw(6)<< "Stock" <<left<< "Price\n";
    //display medicine
    for (int i=0; i<med.size(); i++){
        cout<<med[i]<<endl;
    }
}

//function to list all patients in file
void list_Patient() {

    string line;
    vector <string> pat;

    ifstream file("pat.txt"); //open file

    while (getline(file, line)) {
        if(line.size() > 0){
            pat.push_back(line); //put into vector
        }
    }

    file.close();

    //data header
    cout <<left<<setw(20)<< "Name" <<left<<setw(10)<< "Record_No" <<left<<setw(15) <<"IC/Passport"
            <<left<<setw(4)<< "Sex" <<left<<setw(5)<< "Age" <<left<<setw(45)<<"Address"<<left <<setw(10)<<"Services"
            <<left<<setw(12)<<"Disease"<<left<<setw(15)<<"Admission date"<<left<<setw(12)<<"Room_number"
            <<left<<setw(8)<<"Charge" <<left<<setw(14)<<"Total_deposit"
            <<left<<"Total left\n";
    //display patients
    for (int i=0; i<pat.size(); i++){
        cout<<pat[i]<<endl;
    }
}

//function to list all rooms in file
void list_room() {

    string line;
    vector <string> room;

    ifstream file("room.txt");//open file

    while (getline(file, line)) {
        if(line.size() > 0){
            room.push_back(line);//put into vector
        }
    }
    file.close();

    //data header
    cout << left<<setw(13)<< "Room number" <<left<< "Availability\n";
    //display rooms
    for (int i=0; i<room.size(); i++){
        cout<<room[i]<<endl;
    }
}

//at the start for the system will ask user for password
void check_password(){
    string pass;
    string password;
    fstream passfile ("pass.txt", ios::app);
    passfile.seekg(0,ios::end);
    //if the position of the pointer at the file is at 0 as its end pointer it means there is no password and user will have to set one
    if (passfile.tellg() == 0){
        cout << "No password has been set for this system yet.\nPlease set a password:\n";
        getline(cin, password);
        password.resize(50); //change whatever that is input to size 50 for the purpose of consistency
        passfile << password;
    }
    //if the position is not 0 it means a password was previously set and users will have to enter their password to access database
    else if (passfile.tellg() != 0){
        cout << "Please enter the password: \n";
        fstream passfile("pass.txt");
        passfile.seekg(0);

        getline(cin, password);
        password.resize(50);//change whatever that is input to size 50 for the purpose of consistency
        getline(passfile, pass);
            if (pass != password){
                cout << "Wrong password\n";
                exit(EXIT_FAILURE); //shut down the system
            }
    }
    passfile.close();
}

//function to reset the password if users wish to do so
void set_password(){
    cin.get();
    string password;
    string temp;
    string edit;
    string change;
    fstream passfile ("pass.txt");
    ofstream tmpfile ("tmp.txt");
    passfile.seekg(0);
    tmpfile.seekp(0);
    cout << "Enter the new password: \n";
    getline(cin, password);
    password.resize(50);
    while (getline(passfile,temp)){
        temp.replace(0,password.size(),password);
        cout << "Password has been changed\n";
        tmpfile << temp << "\n";
    }
    passfile.close();
    tmpfile.close();
    remove("pass.txt");
    rename("tmp.txt", "pass.txt");
    system("cls");
}

//function to display the menu for doctor's section
void doctor_menu() {

    char choice;
    do {
        system("cls");
        cout<< "Choose the options below: " <<endl
            << "1. Add doctor" <<endl
            << "2. Search doctor" <<endl
            << "3. Edit doctor" <<endl
            << "4. List doctor" <<endl
            << "5. Delete doctor" << endl
            << "6. Back to main menu"<<endl
            << "Choice:";
        cin>>choice; //ask user's input
        system ("cls");
        switch (choice) {
            case '1':
                add_Doctor();
                break;
            case '2':
                search_Doctor();
                break;
            case '3':
                edit_Doctor();
                break;
            case '4':
                cout<< "Choose way to display record"<<endl
                    << "1. List all doctors" <<endl
                    << "2. Alphabetical order" <<endl
                    << "3. Hired date" <<endl
                    << "Choice:";
                cin>>choice; //ask user's input for listing
                system("cls");
                switch (choice) {
                    case '1':
                        list_Doctor();
                        break;
                    case '2':
                        sort_Doctor();
                        break;
                    case '3':
                        search_doc_date();
                        break;
                    default:
                        cout<< "Invalid input" <<endl;
                        break;
                }
                system("pause");
                system("cls");
                break;
            case '5':
                delete_Doctor();
                break;
            case '6':
                break; //break straight away for exiting
            default:
                cout<<"Invalid input\n";
                break;
        }

    } while (choice >= '1' && choice <= '5');
}

//function to display the menu for patient's section
void patient_menu() {
    char choice;
    do {system("cls");
        cout<< "Choose the options below: " <<endl
            << "1. Add patient" <<endl
            << "2. Search patient" <<endl
            << "3. Edit patient" <<endl
            << "4. List patient" <<endl
            << "5. Delete patient" << endl
            << "6. Back to main menu"<<endl
            << "Choice:";
        cin>>choice; //ask for user's input
        system ("cls");
        switch (choice) {
            case '1':
                add_Patient();
                break;
            case '2':
                search_Patient();
                system("pause");
                break;
            case '3' :
                edit_Patient();
                break;
            case '4':
                cout<< "Choose way to display record"<<endl
                    << "1. List all patients" <<endl
                    << "2. Alphabetical order" <<endl
                    << "3. Selected date" <<endl
                    << "4. Services" << endl
                    << "Choice:";
                cin>>choice; //ask for user's input for listing
                system("cls");
                switch (choice) {
                    case '1':
                        list_Patient();
                        break;
                    case '2':
                        sort_Patient();
                        break;
                    case '3':
                        search_pat_date();
                        break;
                    case '4':
                        search_pat_service();
                        break;
                    default:
                        cout<< "Invalid input" <<endl;
                        break;
                    }
                    system("pause");
                    system("cls");
                    break;
            case '5':
                delete_Patient();
                break;
            case '6':
                break; //break because exit
            default:
                cout<<"Invalid input";
                break;
        }

    } while (choice >= '1' && choice <= '5');

}

//function to display the menu for medicine's section
void medicine_menu() {

    char choice;
    do {
        system("cls");
        cout<< "Choose the options below: " <<endl
            << "1. Add medicine" <<endl
            << "2. Search medicine" <<endl
            << "3. Edit medicine" <<endl
            << "4. List medicine" <<endl
            << "5. Delete medicine" << endl
            << "6. Back to main menu"<<endl
            << "Choice:";
        cin>>choice; //ask user's input
        system ("cls");
        switch (choice) {
            case '1':
                add_Medicine();
                break;
            case '2':
                search_Medicine();
                break;
            case '3':
                edit_Medicine();
                break;
            case '4':
                cout<< "Choose way to display record"<<endl
                    << "1. List all medicine" <<endl
                    << "2. Alphabetical order" <<endl
                    << "3. Out of stock" <<endl
                    << "Choice:";
                cin>>choice; //ask user's input for listing
                system("cls");
                switch (choice) {
                    case '1':
                        list_Medicine();
                        break;
                    case '2':
                        sort_Medicine();
                        break;
                    case '3':
                        search_med_stock();
                        break;
                    default:
                        cout<< "Invalid input" <<endl;
                        break;
                }
                system("pause");
                system("cls");
                break;
            case '5':
                delete_Medicine();
                break;
            case '6':
                break; //break because exit
            default:
                cout<<"Invalid input";
                break;
        }

    } while (choice >= '1' && choice <= '5');
}

//function to display the menu for operation room's section
void operation_room_menu() {

    char choice;
    do {
        system("cls");
        cout<< "Choose the options below: " <<endl
            << "1. Add operation room" <<endl
            << "2. Search operation room" <<endl
            << "3. Edit operation room" <<endl
            << "4. List operation room" <<endl
            << "5. Delete operation room" << endl
            << "6. Back to main menu"<<endl
            << "Choice:";
        cin>>choice; //ask user's input
        system ("cls");
        switch (choice) {
            case '1':
                add_room();
                break;
            case '2':
                search_room();
                break;
            case '3':
                edit_room();
                break;
            case '4':
                cout<< "Choose way to display record"<<endl
                    << "1. List all operation rooms" <<endl
                    << "2. Ascending order" <<endl
                    << "3. Availability" <<endl
                    << "Choice:";
                cin>>choice;//ask user's input for listing
                system("cls");
                switch (choice) {
                    case '1':
                        list_room();
                        break;
                    case '2':
                        sort_room();
                        break;
                    case '3':
                        search_avail();
                        break;
                    default:
                        cout<< "Invalid input" <<endl;
                        break;
                }
                system("pause");
                system("cls");
                break;
            case '5':
                delete_room();
                break;
            case '6':
                break; //break straight away for exit
            default:
                cout<<"Invalid input";
                break;
        }

    } while (choice >= '1' && choice <= '5');
}

int main () {

    check_password();
    system("cls");

    char choice;

    do {
        cout<<"Welcome to MMU Hospital" <<endl
        <<"Please choose which database you wish to access." <<endl
        <<"1. Doctor" <<endl
        <<"2. Patient" <<endl
        <<"3. Medicine" <<endl
        <<"4. Operation room" <<endl
        <<"5. Reset password" <<endl
        <<"6. Exit" << endl
        <<"Choice:";
        cin>> choice; //ask for user's input
        system("cls");
        switch(choice) {
            case '1' :
                doctor_menu();
                break;
            case '2':
                patient_menu();
                break;
            case '3':
                medicine_menu();
                break;
            case '4':
                operation_room_menu();
                break;
            case '5':
                set_password();
                break;
            case '6':
                break; //break straight away for exit
            default:
                cout<<"Invalid option. \n";
                system("pause");
                system("cls");
                break;
        }

    } while (choice !='6');

return 0;
}

