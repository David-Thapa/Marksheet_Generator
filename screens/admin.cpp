#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

class Marksheet
{
    string subject = "Statistics";
    string name,rollNo;
    int choice;
    int fullMarks = 100;
    int marksObtained = 40;
    string remarks = (marksObtained < 40)? "Fail" : "Pass";
    string Remarks;
    int fullMarksTotal = 0,totalMarks = 0,count = 0;
    fstream file;
    public:
    void addData()
    {
        cin.ignore();
        cout<<"Enter name of Student: ";
        getline(cin,name);
        cout<<"Enter Roll No: ";
        cin>>rollNo;
        cout<<"How many subject:";
        cin>>choice;
        // cout<<"Enter the name of Subject and Marks: ";
    }
    void create()
    {
        file.open(name +".txt",ios::out);   
        file<<endl<<"\t\t "<<setfill('-')<<setw(79)<<"-"<<setfill(' ')<<endl
        <<"\t\t|"<<setw(80)<<"|"<<endl
        <<"\t\t|"<<left<<setw(79)<<"                              STUDENT'S MARK SHEET"<<"|"<<endl
        <<"\t\t|"<<setw(80)<<right<<"|"<<endl
        <<"\t\t|"<<setw(23)<<"Name of Student"<<setw(30)<<" "<<setw(26)<<left<<": " + name<<"|"<<endl
        <<"\t\t|"<<setw(15)<<right<<"Roll No"<<setw(38)<<" "<<setw(26)<<left<<": " + rollNo<<"|"<<endl
        <<"\t\t|"<<setw(13)<<right<<"Grade"<<setw(40)<<" "<<setw(26)<<left<<": A"<<"|"<<endl
        <<"\t\t|"<<setw(80)<<right<<"|"<<endl
        <<"\t\t|"<<setw(16)<<left<<"    S.No"
        <<setw(16)<<"Subject"
        <<setw(16)<<"Full Marks"
        <<setw(16)<<"Marks Obtained"
        <<setw(15)<<"     Remarks"<<"|"<<endl;
        //TO DO
        for (int i = 0; i < choice; i++)
        {
            
            file<<"\t\t|"<<"      "<<setw(4)<<i+1;
            if(subject.size() < 14)
            {
                file<<"    "<<setw(18)<<subject;
            }
            else
            {
                file<<setw(22)<<subject;
            }
            file<<"    "<<setw(12)<<fullMarks
            <<"     "<<setw(11)<<marksObtained
            <<"     "<<setw(10)<<remarks<<"|"<<endl;
            totalMarks += marksObtained;
            fullMarksTotal += fullMarks;
            (remarks == "Pass")? count++ : count;
        }
        file<<"\t\t|"<<setw(14)<<" "
        <<setw(17)<<"Grand Total"
        <<"     "<<setw(11)<<fullMarksTotal
        <<"     "<<setw(11)<<totalMarks
        <<"      "<<setw(10)<<((count == 4)?"Passed":"Failed")<<"|"<<endl
        <<"\t\t|"<<setw(80)<<right<<"|"<<endl
        <<"\t\t "<<setfill('-')<<setw(79)<<"-"<<setfill(' ')<<endl;
        file.close();
    }

};

void Admin()
{
    bool logedIn = true;
    Marksheet marksheet;
    int choice;
    while(logedIn)
    {
        system("clear");
        cout<<"1. Add Marksheet.\n2. Update Marksheet\n3. SignOut"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            marksheet.addData();
            marksheet.create();
            system("clear");
            logedIn = true;
            break;

            case 2:
            logedIn = true;
            break;

            case 3:
            logedIn = false;
            break;

            default:
            logedIn = true;
        }
    }
}