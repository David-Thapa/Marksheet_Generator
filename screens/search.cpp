#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
//WhiteSpace is Important
using namespace std;

class MarkSheet
{
    string subject = "Statistics";
    int fullMarks = 100;
    int marksObtained = 40;
    string remarks = (marksObtained < 40)? "Fail" : "Pass";
    string Remarks;
    int fullMarksTotal = 0,totalMarks = 0,count = 0;
    public:
    void create()
    {
        cout<<endl<<"\t\t "<<setfill('-')<<setw(79)<<"-"<<setfill(' ')<<endl
        <<"\t\t|"<<setw(80)<<"|"<<endl
        <<"\t\t|"<<left<<setw(79)<<"                              STUDENT'S MARK SHEET"<<"|"<<endl
        <<"\t\t|"<<setw(80)<<right<<"|"<<endl
        <<"\t\t|"<<setw(23)<<"Name of Student"<<setw(30)<<" "<<setw(26)<<left<<": David Thapa"<<"|"<<endl
        <<"\t\t|"<<setw(15)<<right<<"Roll No"<<setw(38)<<" "<<setw(26)<<left<<": 191804"<<"|"<<endl
        <<"\t\t|"<<setw(13)<<right<<"Grade"<<setw(40)<<" "<<setw(26)<<left<<": A"<<"|"<<endl
        <<"\t\t|"<<setw(80)<<right<<"|"<<endl
        //WhiteSpace is essential
        <<"\t\t|"<<setw(16)<<left<<"    S.No"
        <<setw(16)<<"Subject"
        <<setw(16)<<"Full Marks"
        <<setw(16)<<"Marks Obtained"
        <<setw(15)<<"     Remarks"<<"|"<<endl;
        //TO DO
        for (int i = 0; i < 4; i++)
        {
            
            cout<<"\t\t|"<<"      "<<setw(4)<<i;
            if(subject.size() < 14)
            {
                cout<<"    "<<setw(18)<<subject;
            }
            else
            {
                cout<<setw(22)<<subject;
            }
            cout<<"    "<<setw(12)<<fullMarks
            <<"     "<<setw(11)<<marksObtained
            <<"     "<<setw(10)<<remarks<<"|"<<endl;
            totalMarks += marksObtained;
            fullMarksTotal += fullMarks;
            (remarks == "Pass")? count++ : count;
        }
        cout<<"\t\t|"<<setw(14)<<" "
        <<setw(17)<<"Grand Total"
        <<"     "<<setw(11)<<fullMarksTotal
        <<"     "<<setw(11)<<totalMarks
        <<"      "<<setw(10)<<((count == 4)?"Passed":"Failed")<<"|"<<endl
        <<"\t\t|"<<setw(80)<<right<<"|"<<endl
        <<"\t\t "<<setfill('-')<<setw(79)<<"-"<<setfill(' ')<<endl;      
    }

    void createFile()
    {
        fstream file;
        file.open("file.txt",ios::out);
        file<<endl<<"\t\t "<<setfill('-')<<setw(79)<<"-"<<setfill(' ')<<endl
        <<"\t\t|"<<setw(80)<<"|"<<endl
        <<"\t\t|"<<left<<setw(79)<<"                              STUDENT'S MARK SHEET"<<"|"<<endl
        <<"\t\t|"<<setw(80)<<right<<"|"<<endl
        <<"\t\t|"<<setw(23)<<"Name of Student"<<setw(30)<<" "<<setw(26)<<left<<": David Thapa"<<"|"<<endl
        <<"\t\t|"<<setw(15)<<right<<"Roll No"<<setw(38)<<" "<<setw(26)<<left<<": 191804"<<"|"<<endl
        <<"\t\t|"<<setw(13)<<right<<"Grade"<<setw(40)<<" "<<setw(26)<<left<<": A"<<"|"<<endl
        <<"\t\t|"<<setw(80)<<right<<"|"<<endl
        <<"\t\t|"<<setw(16)<<left<<"    S.No"
        <<setw(16)<<"Subject"
        <<setw(16)<<"Full Marks"
        <<setw(16)<<"Marks Obtained"
        <<setw(15)<<"     Remarks"<<"|"<<endl;
        //TO DO
        for (int i = 0; i < 4; i++)
        {
            
            file<<"\t\t|"<<"      "<<setw(4)<<i;
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

void Search()
{
    system("clear");
    MarkSheet marksheet;
    marksheet.create();
    marksheet.createFile();
    system("pause");
}

