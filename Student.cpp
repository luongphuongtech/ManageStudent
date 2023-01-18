#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include "Person.cpp"
using namespace std;
class Student: public Person{
    private:
        double math;
        double physical;
        double chemistry;
    public:
    Student(){
    }
     Student(int id,string name,string sex,int age,double math, double physical, double chemistry): Person(id,name,sex,age){
        this->math=math;
        this->physical=physical;
        this->chemistry=chemistry;
     } 
     void setMath(double math) { this->math=math;}
     void setPhysical(double physical) { this->physical=physical;}
     void setChemistry(double chemistry) { this->chemistry=chemistry;}
     double getMath() { return math;}
     double getPhysical() { return physical;}
     double getChemistry() { return chemistry;}
     friend double CPA(Student St);
};
void printLine(int n){
    for(int i=0;i<n;i++){
        cout<<"_";
    }
    cout<<endl;
}
double CPA(Student St){
        return (St.math+St.physical+St.chemistry)/3;
}
void Rank(Student st[],int n,int id)
{
    int m,r=n;
    for(int i=0;i<n;i++){
        if(st[i].getId()==id){
            m=i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(CPA(st[m])>CPA(st[i])){
            r=n-1;
        }
    }
    cout<<" Rank of student id "<< id<<" is"<< r<<endl;
}
int maxID(vector<Student> student){
    int n=student.size();
    int max=student[0].getId();
    for(int i=0;i<n;i++){
        if(student[i].getId()>max){
            max=student[i].getId();
        }
    }
    return max;
}
void inputstudent(Student &st,int id){
    string name;
    string sex;
    int age;
    double math;
    double physical;
    double chemistry;
    cout<<"\n Enter name: ";
     cin>>(name);
    cout<<" Enter sex: ";
    cin>>(sex);
    cout<<" Enter age: ";
    cin>>age;
    cout<<" Enter math score: ";
    cin>>math;
    cout<<" Enter physical score: ";
    cin>>physical;
    cout<<" Enter chemistry score: ";
    cin>>chemistry;
    st.setId(id);
    st.setName(name);
    st.setSex(sex);
    st.setAge(age);
    st.setMath(math);
    st.setPhysical(physical);
    st.setChemistry(chemistry);
}
void NewStudent(vector<Student> student,int id){
    printLine(30);
    int n=student.size();
    cout<<"enter the student "<<n+1<<":"<<endl;
    Student s;
    inputstudent(s,id);
    student.push_back(s);
    printLine(30);
}
 void deleteStudent(Student *st,int *n,int id){
        int m,d=0;
        Student *p;
    for(int i=0;i<*n;i++){
        if(st[i].getId()==id){
            m=i;
            break;
          }
          d++;
    }
    if(d==0){
         cout<<"id does not exist"<<endl;
    }
    else{
        st=st+m;
       for(int i=m;i<*n;i++){
            p=st+1;
            *st=*p;
            st++;
        }
         printLine(30);
         cout<<"complete removing student id  "<<id<<endl;
         printLine(30);
     }
    }
    void publicInfor(Student st){
        cout<<"ID"<<"    "<<"Name"<<"    "<<"Sex"<<"    "<<"Age"<<"    "<<endl;
        cout<<st.getId()<<"    "<<st.getName()<<"    "<<st.getSex()<<"    "<<st.getAge()<<endl;
    }
    void FindName(Student st,string name)
        {
        
            if(st.getName()==name){
                    cout<<"id    "<<"name    "<<"sex    "<<"age    "<<endl;
                    publicInfor(st);
                }   
            else{
                cout<<"id does not exist"<<endl;
            }
        }
       void ShowRank(vector<Student> st,int n){
       n=st.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(CPA(st[i])>CPA(st[i])){
                    swap(st[i],st[j]);
                }
            }
        }
        printLine(30);
        cout<<"    id    "<<"name    "<<"sex    "<<"age    "<<endl;
        for(int i=0;i<n;i++){
            cout<<"rank: "<<i+1<<"    ";
            publicInfor(st[i]);
        }
        printLine(30);
    }  
    void updateStudent(vector<Student> student,int n,int id){
        n=student.size();
    Student *q;
    int d=0;
    for(int i=0;i<n;i++){
        if(id==student[i].getId()){
            q=&student[i];
            break;
        }
        d++;
    }
    if(d==0){
        cout<<"id does not exist";
    }
    else{
        inputstudent(*q,id);
    }
}
int main(){
   Student st;
   inputstudent(st,7);
   publicInfor(st);
}
 
