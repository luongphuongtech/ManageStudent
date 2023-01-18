#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
using namespace std;
class Person{
   private:
    int id;
    string name;
    string sex;
    int age;
    public:
    Person(){}
    Person(int id,string name,string sex,int age){
        this->id=id;
        this->name=name;
        this->sex=sex;
        this->age=age;
    }
    void setId(int id){this->id=id;}
    void setName(string name) { this->name=name; }
    void setSex(string sex) { this->sex=sex; }
    void setAge(int age) { this->age=age; }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    string getSex(){
        return sex;
    }

    int getAge(){
        return age;
    }
};
