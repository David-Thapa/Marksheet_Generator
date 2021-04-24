#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<vector>
#include<conio.h>
#pragma once

using namespace std;

class CSV
{
    vector<string> row;
    string line, word, fileName;
    fstream csv,file;
    char data;
    int count = 0;

    public:
    void read_record()
    {
        csv.open("screens/data/CSV/list.csv", ios::in);
        cin.ignore();
        cout << "\t\tName of the student or roll no\n\t\t: ";
        getline(cin,fileName);
        while (getline(csv,line))
        {
            row.clear();
            count++;
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (row[0] == fileName)
            {
                show(fileName);
                break;
            }
            else if(row[1] == fileName)
            {
                show(row[0]);
                break;
            }

        }
        if (count == 0)
            cout << "Record not found\n";
        
        file.close();
        csv.close();
    }
    void show(string fileName)
    {
        file.open("screens/data/Marksheet/"+fileName + ".txt",ios::in);

        while(file>>noskipws>>data)
        {
            cout<<data;
        }
    }

};

class Marksheet : public CSV
{
    string name, rollNo, grade, remarks[50], Remark, subject[50],word,temp;
    int marksObtained[50], choice, percentage;
    const int fullMarks = 100;
    int fullMarksTotal = 0,totalMarks = 0,pass = 0, fail = 0;
    fstream file,csv;
    vector<string> literals;

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
        for (int i = 0; i < choice; i++)
        {
            system("clear");
            cin.ignore();
            cout<<"Enter the name of "<<i+1<<" Subject: ";
            getline(cin,subject[i]);
            cout<<"Enter Marks obtained: ";
            cin>>marksObtained[i];
            remarks[i] = (marksObtained[i] < 40)? "Fail" : "Pass";
            totalMarks += marksObtained[i];
            fullMarksTotal += fullMarks;
        }
        percentage = totalMarks / choice;
    }
    void create()
    {
        file.open("screens/data/Marksheet/" + name + ".txt",ios::out);
        csv.open("screens/data/CSV/list.csv",ios::out | ios::app);

        (percentage >= 90)? grade = "A+"
        : (percentage >= 80)? grade = "A"
        : (percentage >= 70)? grade = "B+"
        : (percentage >= 60)? grade = "B"
        : (percentage >= 50)? grade = "C+"
        : (percentage >= 40)? grade = "C"
        : (percentage >= 30)? grade = "D+"
        : (percentage >= 20)? grade = "D"
        : grade = "E";

        file<<endl<<"\t\t "<<setfill('-')<<setw(79)<<"-"<<setfill(' ')<<endl
            <<"\t\t|"<<setw(80)<<"|"<<endl
            <<"\t\t|"<<left<<setw(79)<<"                              STUDENT'S MARK SHEET"<<"|"<<endl
            <<"\t\t|"<<setw(80)<<right<<"|"<<endl
            <<"\t\t|"<<setw(23)<<"Name of Student"<<setw(30)<<" "<<setw(26)<<left<<": " + name<<"|"<<endl
            <<"\t\t|"<<setw(15)<<right<<"Roll No"<<setw(38)<<" "<<setw(26)<<left<<": " + rollNo<<"|"<<endl
            <<"\t\t|"<<setw(13)<<right<<"Grade"<<setw(40)<<" "<<setw(26)<<left<<": " + grade<<"|"<<endl
            <<"\t\t|"<<setw(80)<<right<<"|"<<endl
            <<"\t\t|"<<setw(16)<<left<<"    S.No"
            <<setw(16)<<"Subject"
            <<setw(16)<<"Full Marks"
            <<setw(16)<<"Marks Obtained"
            <<setw(15)<<"     Remarks"<<"|"<<endl;
        csv<<name<<","
            <<rollNo<<",";
        //TO DO
        for (int i = 0; i < choice; i++)
        {
            file<<"\t\t|"<<"      "<<setw(4)<<i+1;
            file<<"    "<<setw(18)<<subject[i];
            file<<"    "<<setw(12)<<fullMarks
                <<"     "<<setw(11)<<marksObtained[i]
                <<"     "<<setw(10)<<remarks[i]<<"|"<<endl;
            (remarks[i] == "Pass")? pass++ : fail++;
            
            csv<<subject[i]<<","<<marksObtained[i]<<",";
        }
        Remark = ((pass == choice && fail == 0)?"Passed":"Failed");
        csv<<"Grade"<<","<<grade<<","<<"Remark"<<","<<Remark<<endl;
        file<<"\t\t|"<<setw(14)<<" "
            <<setw(17)<<"Grand Total"
            <<"     "<<setw(11)<<fullMarksTotal
            <<"     "<<setw(11)<<totalMarks
            <<"      "<<setw(10)<<Remark<<"|"<<endl
            <<"\t\t|"<<setw(80)<<right<<"|"<<endl
            <<"\t\t "<<setfill('-')<<setw(79)<<"-"<<setfill(' ')<<endl;
        file.close();
        csv.close();
    }

    void list()
    {
        bool onlyOnce = false;
        csv.open("screens/data/CSV/list.csv", ios::in);
        system("clear");
        while (getline(csv,temp))
        {
            literals.clear();
            stringstream s(temp);

            while(getline(s,word,','))
            {
                literals.push_back(word);
            }
            if(!onlyOnce)
            {
                onlyOnce = true;
                for (int i = 0; i < literals.size() - 1; i++)
                {
                    if(i == 0)
                        cout<<"Roll No";

                    else if (i == 1)
                        cout<<setw(20)<<left<<"      Name";
                    
                    else
                    {
                        if(literals[i] == "Grade")
                        {
                            cout<<setw(10)<<literals[i];
                            i++;
                        }
                        else if (literals[i] == "Remark")
                        {
                            cout<<setw(10)<<literals[i]<<endl;
                        }
                        else
                        {
                            cout<<setw(20)<<literals[i];
                            i++;
                        }
                    }
                }
            }
            for (int i = 0; i < literals.size() - 1; i++)
            {
                if(i == 0)
                    cout<<literals[1];

                else if (i == 1)
                    cout<<setw(20)<<"    "+literals[0];
                
                else
                {
                    if(literals[i] == "Grade")
                    {
                        i++;
                        cout<<setw(10)<<"   " + literals[i];
                    }
                    else if (literals[i] == "Remark")
                    {
                        i++;
                        cout<<setw(10)<<" " + literals[i]<<endl;
                    }
                    else
                    {
                        i++;
                        cout<<setw(20)<<"      " + literals[i];
                    }
                }
            }
        }
        system("pause");
        csv.close();
    }
    
    void Delete()
    {
        int value = 0;
        string fileName, str;
        vector<string> temp[100];
        csv.open("screens/data/CSV/list.csv",ios::in);

        for (int i = 0; getline(csv,str); i++)
        {
            stringstream s(str);

            while(getline(s,word,','))
            {
                temp[i].push_back(word);
            }
            value++;
        }
        csv.close();
        file.open("screens/data/CSV/list.csv",ios::out | ios::trunc);
        cout<<"Enter the Name of Student: ";
        cin.ignore();
        getline(cin,fileName);
        remove(("screens/data/Marksheet/" + fileName + ".txt").c_str());

        for (int j = 0; j < value; j++)
        {
             if(fileName == temp[j][0])
            {
                continue;
            }
            else
            {
                for (int k = 0; k < (temp[j].size())-1; k++)
                {
                    file<<temp[j][k]<<",";
                }
                file<<temp[j][(temp[j].size()) - 1]<<endl;
            }
        }

        file.close();

        cout<<"Succesfully Deleted."<<endl;
        system("pause");
    }
    
};

void Authi(string &password)
{
    string pass ="";
    char ch;
    bool trigger = true;
    while (trigger)
    {
        system("clear");
        try
        {
            cout<<"Type Password: ";
            ch = _getch();
            while(ch != 13)     //character 13 is enter
            {
                pass.push_back(ch);
                cout << '*';
                ch = _getch();
            }
            if(pass == password)
            {
                trigger = false;
            }
            else
                throw pass;
        }
        catch(...)
        {
            cout<<endl<<"\nWrong Password!!!"<<endl;
            system("pause");
        }
        
    }
}

void Admin(string &password)
{
    bool logedIn = true;
    Marksheet marksheet;
    int choice;
    Authi(password);
    while(logedIn)
    {
        system("clear");
        cout<<"1. Add Marksheet.\n2. Delete Marksheet\n3. List the File\n4. SignOut"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            system("clear");
            marksheet.addData();
            marksheet.create();
            logedIn = true;
            break;

            case 2:
            system("clear");
            marksheet.Delete();
            logedIn = true;
            break;

            case 3:
            system("clear");
            marksheet.list();
            logedIn = true;
            break;

            case 4:
            logedIn = false;
            break;

            default:
            logedIn = true;
        }
    }
}