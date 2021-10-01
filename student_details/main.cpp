#include <iostream>
#include <iomanip>

using namespace std;
int n,i;
struct info
    {
        string name;
        int rollNo;
        float marks;
    };

class student
{
public:
void getdata(info s1[],int n)
{



    for(int i=0;i<n;i++)
    {
    cout<<"Enter Information of student: "<<i+1<<endl;

    cout<<"Enter name of the student: ";
    cin>>s1[i].name;
   cout<<"Enter Roll number: ";
    cin>>s1[i].rollNo;
    cout<<"Enter marks: ";
    cin>>s1[i].marks;
    cout<<endl;
    }


}
void showdata(info s1 [],int n)

{


    for(int i=0;i<n;i++)
    {
    cout<<"\nInformation of Student: "<<i+1;
    cout<<"\nName: "<<s1[i].name;
     cout<<"\nRoll number: "<<s1[i].rollNo;
    cout<<"\nMarks: "<<s1[i].marks;
     cout<<endl;

    }
}
void rollNoSort(info s1[],int n)
{

    int temp;
    int tempr;
    string tempn;
    for(int i=0; i<n-1;i++)//pass
    {
        for(int j=0;j<(n-i-1);j++)//comparision
        {
            if(s1[j].rollNo  > s1[j+1].rollNo)
            {
                temp=s1[j].rollNo;
                s1[j].rollNo=s1[j+1].rollNo;
                s1[j+1].rollNo=temp;

                tempn=s1[j].name;
                s1[j].name=s1[j+1].name;
                s1[j+1].name=tempn;

                 tempr=s1[j].marks;
                s1[j].marks=s1[j+1].marks;
                s1[j+1].marks=tempr;
                }}}

}

void insertionSort(info s1[],int n)
{
    for(int i=1;i<n;i++)//
    {
        string key = s1[i].name;//current value
        int j = i -1;
        while(s1[j].name >key && j>=0)//comparing current value with previous value
        {
             s1[j+1].name=s1[j].name;//move the element by position 1
             j--;
        }
        s1[j+1].name=key ;


    }





}
void alpha(info s1[],int n)
{
     cout<<"------------------------"<<endl;
    cout<<"NAME OF STUDENT "<<endl;
    for(int i=0;i<n;i++)
    {
       cout<<i+1<<". "<<s1[i].name<<endl;
    }
    cout<<"------------------------"<<endl;
}
void searchName(info s1[],int n)
{  string namesearch;
    cout<<"Enter name to be searched: ";
cin>>namesearch;
    int start =0;
    int End = n-1;

    bool flag = true;

    while(start<=End)
    {
        int mid = (End+start/2);
        if(s1[mid].name==namesearch)
        {
           cout<<"------------------------"<<endl;
           cout<<"Name : "<<s1[mid].name <<endl;
           cout<<"Roll no :"<<s1[mid].rollNo<<endl;
           cout<<"Marks :"<<s1[mid].marks<<endl;
            cout<<"------------------------"<<endl;
           flag = false;

           break;
        }
        else if(s1[mid].name<namesearch)
        {
            start = mid +1;
        }
        else
        {
            End = mid -1;
        }
    }
if(flag)
{
    cout<<"Not found ";
}

}
void showsortrollno(info s1[],int n)
{
    cout<<"-----------|----------------|----------|"<<endl;
    cout<<" Roll No   |       Name     |    Marks |"<<endl;
    cout<<"-----------|----------------|----------|"<<endl;
    for(int i =0;i<n;i++)
    {
    cout<<left<<setw(11)<<s1[i].rollNo<<"|"<<left<<setw(16)<<s1[i].name<<"|"<<left<<setw(10)<<s1[i].marks<<"|"<<endl;}
    cout<<"-----------|----------------|----------|"<<endl;


}
};

int main()
{   cout<<"Enter Number  of student: ";
    cin>>n;
    info s1[n];
    student obj1;
     int method;
    do
    {
        cout<<"------------------------"<<endl;
        cout<<"select method :";
        cout<<"\n1.Enter data :";
        cout<<"\n2.show details alphabetical order :";
        cout<<"\n3.show details  roll number wise  :";
        cout<<"\n4.search  name :";
        cout<<"\n5.exit "<<endl;
        cout<<"------------------------"<<endl;
        cout<<endl;

        cout<<"Enter method : ";
        cin>>method;
        cout<<endl;
        cout<<"------------------------"<<endl;
        switch(method)
        {
        case 1:
            {
                obj1.getdata(s1,n );
                break;
            }
        case 2:
            {
                obj1.insertionSort(s1,n);
                obj1.alpha(s1,n);

                  break;
            }
        case 3:
            {
                obj1.rollNoSort(s1,n );
                obj1.showsortrollno(s1,n);

                 break;
            }
        case 4 :
            {
              obj1.insertionSort(s1,n);

              obj1.searchName( s1, n);

              break;
            }
        case 5:
            {
                cout<<"exiting.........";
                break;
            }
        default:
            {
                cout<<"Enter valid method "<<endl;
                break;
            }
        }



    }while(method!=5);




    return 0;
}
