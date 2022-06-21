#include <iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Student{
public:
    char name[50];
    static string S[5];
    static float credit[5];
    int m[5];
    int roll;
    float cgpa=0.00;
    static int count2;
    float per = 0;
    void getdata()
    {
        count2++;
        cout << "\nEnter the first name of student : "<<count2<<endl;
         cin>>name;
    r:
        cout << "Enter the roll no of student : "<<count2<<endl;
        cin >> roll;
        try
        {
            if (roll<=10000||roll>=100000)
                throw roll;
        }
        catch (int x)
        {
            cout << "input correct roll number" << endl;
            goto r;
        }
        for (int i = 0; i < 5; i++)
        {
            m:
            cout << "enter marks of "<<S[i]<< endl;
            cin >> m[i];
            try
            {
                if (m[i]<0||m[i]>100)
                    throw m[i];
            }
            catch (int x)
            {
                cout << "incorrect input of marks" << endl;
                goto m;
            }
        }
        per = (m[0] + m[1] + m[2] + m[3] + m[4]) / 5.00;
        cout << "\n";
    }
    void display()
    {
        int k;
        char a;
        cout<<"\n*************************************\n";
        cout << "Student name : " << name << endl;
        cout << "Roll no : " << roll << endl;
        cout<<"_____________________________________\n";
        cout << "Subject               marks    grade\n";
        cout<<"_____________________________________\n";
        for (int i = 0; i < 5; i++)
        {
            cout << S[i];
            for(int j=0;j<23-S[i].size();j++)
            {
                cout<<" ";
            }
            cout<<m[i];
            cout<<"      ";
            int b=0;
            float d;
            for(k=90;k>10;k=k-20)
            {
                if(m[i]>=k)
                    {
                        a='A'+b;
                        d=(k+10)/10.00;
                        cgpa+=d*credit[i];
                       cout<<a<<"+";
                       break;
                    }
                else if(m[i]>=k-10)
                {
                    a='A'+b;
                    d=(k)/10.00;
                    cgpa+=d*credit[i];
                    cout<<a;
                    break;
                }
                b++;
            }
            cout<<endl;
        }
        cgpa=cgpa/(credit[0]+credit[1]+credit[2]+credit[3]+credit[4]);
         cout<<"_____________________________________\n";
        cout << "percentage : " << per <<"\t cgpa : "<<setprecision(3)<<cgpa<<endl;
        cout<<"\n*************************************\n";
        cout << "\n\n";
    }

    void edit()
    {
        int n;
        cout<<"*******************************";
        cout << "\nEnter 1 to change name\n";
        cout << "Enter 2 to change roll no\n";
        cout << "Enter 3 to change marks of Physics\n";
        cout << "Enter 4 to change marks of Chemistry\n";
        cout << "Enter 5 to change marks of Maths \n";
        cout << "Enter 6 to change marks of Electrical Science\n";
        cout << "Enter 7 to change marks of Computer Science\n";
        cout<<"*******************************";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "\nenter new name\n";
            cin >> name;
            break;
        case 2:
        l:
            cout << "\nenter new roll no\n";
            cin >> roll;
            try
            {
                if (roll <= 0)
                    throw roll;
            }
            catch (int x)
            {
                cout << "input correct roll number" << endl;
                goto l;
            }
            break;
        case 3:
        b:
            cout << "\nenter new marks\n";
            cin >> m[0];
            try
            {
                if (m[0] < 0)
                    throw m[0];
            }
            catch (int x)
            {
                cout << "incorrect marks" << endl;
                goto b;
            }
            break;
        case 4:
            c:
            cout << "\nenter new marks\n";
            cin >> m[1];
            try
            {
                if (m[1] < 0)
                    throw m[1];
            }
            catch (int x)
            {
                cout << "incorrect marks" << endl;
                goto c;
            }
            break;
        case 5:
        d:
            cout << "\nenter new marks\n";
            cin >> m[2];
            try
            {
                if (m[2] < 0)
                    throw m[2];
            }
            catch (int x)
            {
                cout << "incorrect marks" << endl;
                goto d;
            }
            break;
        case 6:
        e:
            cout << "\nenter new marks\n";
            cin >> m[3];
            try
            {
                if (m[3] < 0)
                    throw m[3];
            }
            catch (int x)
            {
                cout << "incorrect marks" << endl;
                goto e;
            }
            break;
        case 7:
        f:
            cout << "\nenter new marks\n";
            cin >> m[4];
            try
            {
                if (m[4] < 0)
                    throw m[4];
            }
            catch (int x)
            {
                cout << "incorrect marks" << endl;
                goto f;
            }
            break;
        }
    }
    void Delete()
    {
        cout<<"\n***Data of Student deleted successfully***\n";
        count2--;
    }
};
int Student::count2=0;
float Student::credit[5]={3,4,3,4,4};
string Student::S[5]={"Physics","Chemistry","Maths","Electrical science","Computer Science"};

void intro()
{
    cout << "\n\n\n\t\t  STUDENT";
    cout << "\n\n\t\tREPORT CARD";
    cout << "\n\n\t\t  PROJECT";
    cout << "\n\n\n\tMADE BY : ";
    cout << "\n\t\tTanishk Agarwal\n\t\tAaryan Nehra\n\t\tRishabh Chauhan\n\t\tShrey Gurbaxani";
    cin.get();
}
int main()
{
    intro();
    system("cls");
    int x, i, j, count1, z,w,k,v;
    cout << "Enter the total no of students\n";
    cin >> x;
    Student *s[35];
    Student *temp=new Student;
    for (i=0;i<x;i++)
    {
        s[i]=new Student;
        s[i]->getdata();
        a:
        try
        {
            for( k=0;k<x;k++)
           {
            for( v=k+1;v<x;v++)
            {
             if(s[k]->roll==s[v]->roll)
              {
                  throw 'a';
              }
            }
           }
        }
        catch(...)
        {
            cout<<"Roll number of 2 students can not be same\n";
             cout<<"press 1 to change roll no of : "<<s[k]->name<<""<<endl;
             cout<<"press 2 to change roll no of : "<<s[v]->name<<endl;
             cin>>w;

             if(w==1)
             {
                 cout<<"enter the new roll no\n";
                 cin>>s[k]->roll;
             }
             else
             {
                cout<<"enter the new roll no\n";
                 cin>>s[v]->roll;
             }
             goto a;
        }
    }

    while(count1!=1)
    {
      float r[Student::count2];
                 for (i=0;i<Student::count2;i++)
                  {
                     r[i]=s[i]->per;
                   }
        cout<<"\nEnter 1 to display result of all students\n";
        cout<<"Enter 2 to display result of a particular student\n";
        cout<<"Enter 3 to calculate rank of a student\n";
        cout<<"Enter 4 to edit profile of a student\n";
        cout<<"Enter 5 to add a student details and marks\n";
        cout<<"Enter 6 to delete data of a Student\n";
        cout<<"enter 0 to quit\n";
        cin >> z;
        switch (z)
        {
        case 1:
            for (i = 0; i < Student::count2; i++)
            {
                s[i]->display();
            }
            break;
        case 2:
            int y;
            cout << "\nEnter the roll no of student whose result has to be displayed\n";
            cin >> y;
            for (i = 0; i < Student::count2; i++)
            {
                if (y == s[i]->roll)
                {
                    s[i]->display();
                    y=0;
                    break;
                }
            }
            if(y!=0)
            cout<<"!!!!Entered roll no not found!!!!\n";
            break;
        case 3:
            y=0;
            cout<<"\n_______________________\n";
                     for (i=0;i<Student::count2;i++)
                     {
                      for (j=i+1;j<Student::count2;j++)
                        {
                    if (r[i]<r[j])
                    {
                        int temp = r[i];
                        r[i] = r[j];
                        r[j] = temp;
                    }
                       }
                     }
            for (i=0;i<Student::count2;i++)
            {
                for (j=0;j<Student::count2;j++)
                {
                    if (r[i]==s[j]->per)
                    {
                    if(r[i+1]!=s[j]->per)
                    {
                        cout <<i+1<< " rank is secured by " << s[j]->name << endl;
                    }
                    else if(r[i+1]==s[j]->per)
                        {
                             for(int k=j+1;k<Student::count2;k++)
                             {
                                 if(r[i]==s[k]->per)
                                 {
                                     cout<<i+1<<" rank is secured by "<<s[k]->name<<endl;
                                     cout<<i+1<<" rank is secured by "<<s[j]->name<<endl;
                                     i++;
                                     y++;
                                     break;
                                 }
                             }
                        }
                    }
                    if(y==1)
                    {
                        break;
                    }

                }
            }
            cout<<"_________________________\n";
            cout << "\n";
            break;
          case 4:
            cout << "\nenter the roll no of student whose profile has to be edited\n";
            cin>>y;

            for (i=0;i<Student::count2;i++)
            {
                if (y==s[i]->roll)
                {
                    s[i]->edit();
                    y=0;
                    break;
                }
            }
             if(y!=0)
             cout<<"!!!!Entered roll no not found!!!!\n";
            break;
        case 5:
            s[Student::count2]->getdata();
            b:
        try
        {
            for(int k=0;k<x;k++)
           {
            for(int v=k+1;v<x;v++)
            {
             if(s[k]->roll==s[v]->roll)
              {
                  throw 'c';
              }
            }
           }
        }
        catch(...)
        {
            cout<<"Roll number of 2 students can not be same\n";
             cout<<"press 1 to change roll no of : "<<s[k]->name<<endl;
             cout<<"press 2 to change roll no of"<<s[v]->name<<endl;
             cin>>w;
             if(w==1)
             {
                 cout<<"enter the new roll no\n";
                 cin>>s[k]->roll;
             }
             else
             {
                cout<<"enter the new roll no\n";
                 cin>>s[v]->roll;
             }
             goto b;
        }
            break;
        case 6:
            cout<<"enter the roll no of Student whose record has to be deleted\n";
            cin>>y;
            for (i=0;i<Student::count2;i++)
            {
                if (y==s[i]->roll)
                {
                    y=0;
                    x=i;
                }
            }
            if(y!=0)
            {   cout<<"!!!!Entered roll no not found!!!!\n";
                break;
            }
            else{
                for(j=x;j<Student::count2-1;j++)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
            s[Student::count2]->Delete();
            break;
            }
        case 0:
            count1++;
        }
    }
    return 0;
}
