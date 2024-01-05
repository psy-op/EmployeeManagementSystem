#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int id=1000;
// employee class with all the sets and gets required for the code and computes the annual salary and returns 0 if its under 0.
class employee{
    private:
        int employeeID; 
        string firstName;
        string lastName; 
        float workingHours; 
        float costPerHour;
        float deduction; 
        double annualSalary;
    public:
    employee(){
        id++;
        employeeID=id;
    }

    int get_employeeID(){
        return employeeID;
    }
    string get_firstName(){
        return firstName;
    }
    string get_lastName(){
        return lastName;
    }
    float get_workingHours(){
        return workingHours;
    }
    float get_costPerHour(){
        return costPerHour;
    }
    float get_deduction(){
        return deduction;
    }
    double get_annualSalary(){
        annualSalary=(workingHours*costPerHour*52)-(52*deduction);
        if(annualSalary<0){
            return 0;
        }else{
        return annualSalary;
        }
    }
    void set_firstName(string fName){
        firstName=fName;
    }
    void set_lastName(string lName){
        lastName=lName;
    }

    void set_hours(float hours){
        workingHours=hours;
    }
    void set_cost(float cost){
        costPerHour=cost;
    }
    void set_deduct(float deduct){
        deduction=deduct;   
    }
};
int counter;
int num;
//class hrm with the fucntions of add, delete, edit , search
class HRM{
    public:
    employee emp[100];
    // add fucntion that adds an employee
    void add(string first,string last,int hours,int pay,int ded){
        char lo;
        bool Loop=true;
    
        num=counter;
        emp[num].set_firstName(first);
        emp[num].set_lastName(last);
        emp[num].set_hours(hours);
        emp[num].set_cost(pay);
        emp[num].set_deduct(ded);
        
        
}

//fucntion add2 used to read from the file and put the file empoyees into the array first before adding any new ones
void add2(string first,string last,int hours,int pay,int ded){
        num=counter;
        emp[num].set_firstName(first);
        emp[num].set_lastName(last);
        emp[num].set_hours(hours);
        emp[num].set_cost(pay);
        emp[num].set_deduct(ded);
        counter++;
}

//fucntion search that loops the id array to find the employee required and prints their info, while asking if the use wants to search another employee
void search(string first,string last,int hours,int pay,int ded){
    int idtemp;
    bool Loop=true;
    char lo;

    int m=0;
    do{
        bool found=false;
       cout<<"\nEnter Employee Id To search: ";
       cin>>idtemp;
       for(int i=0;i<num+1;i++){
           if(emp[i].get_employeeID()==idtemp){
               m=i;
            found=true;
        }
    
       }
       if(found){
       cout<<"Employee ID\tFirst Name\tLast Name\tSalary per year($)"<<endl;
        cout<<"-----------\t----------\t----------\t----------------------"<<endl;
        cout<<emp[m].get_employeeID()<<"\t\t"<<emp[m].get_firstName()<<"\t\t"<<emp[m].get_lastName()<<"\t\t"<<emp[m].get_annualSalary()<<endl;
        }else{
            cout<<"Employee ID not found."<<endl;
        }
       cout<<"Do you want to search for another employee(y/n)? ";
        cin>>lo;
        if(lo=='n' || lo=='N'){
        Loop=false;
    
        }
    }while(Loop);

};

//fucntion delete which uses the search algrithm used in the search fucntion to find the user and delete it from the array while moving the other arrays to the next line and asking the user if they want to delete another employee
void del(){
    int idtemp;
    bool Loop=true;
    char lo;
    bool found=false;
        do{
        int m=0;
        cout<<"\nEnter Employee Id To delete: ";
        cin>>idtemp;

        for(int i=0;i<num+1;i++){
           if(emp[i].get_employeeID()==idtemp){
               for(int j=i; j<(num+1); j++){
                emp[j] = emp[j+1];
                m=i;
                found=true;
                num--;
               }
            }
       }
       counter--;
       if(found){
            
            cout<<"Employee deleted."<<endl;
            
        }else{
            cout<<"Employee ID not found."<<endl;
        }
       cout<<"Do you want to delete another employee(y/n)? ";
        cin>>lo;
        if(lo=='n' || lo=='N'){
        Loop=false;
    
        }
        }while(Loop);
        }

//edit which searchs for the employee using the same algorithm and uses a switch case to ask the user for what does he want to change about the employee
void edit(){
    int select2;
    int idtemp;
    bool Loop=true;
    char lo;
    bool found=false;
    do{
        int m=0;
       cout<<"\nEnter Employee Id To search: ";
       cin>>idtemp;
       for(int i=0;i<num+1;i++){
           if(emp[i].get_employeeID()==idtemp){
               m=i;
            found=true;
        }
    
       }
       if(found){
        do{
           cout<<"Choose what to update for the employee: "<<endl;
           cout<<"1.   First name."<<endl;
           cout<<"2.   Last name."<<endl;
           cout<<"3.   Working hours."<<endl;
           cout<<"4.   Pay Per hour."<<endl;
           cout<<"5.   Deduction."<<endl;
           cout<<"6.   Exit"<<endl;
        cout<<"   Please Enter Your Choice: ";
    cin>>select2;
    string fName;
        string lName;
        float hours;
        float x;
        float cost;
        float y;
        float deduct;
        float u;
    switch(select2){
        case 1:
        cout<<"Please enter the first name of the employee: ";
        cin>>fName;
        emp[m].set_firstName(fName);
        break;

        case 2:
        cout<<"Please enter the last name of the employee: ";
        cin>>lName;
        emp[m].set_lastName(lName);
        break;

        case 3:
        cout<<"How many hours do they work?(1-60): ";
        cin>>x;
        while(x<1 || x>60){
            cout<<"Plese enter a valid number."<<endl;
            cout<<"How many hours do they work?: ";
            cin>>x;
            }
        hours=x;
        emp[m].set_hours(hours);
        break;

        case 4:
        cout<<"How much do they get paid for an hour?: ";
        cin>>y;
        while(y<1){
            cout<<"Plese enter a valid number."<<endl;
            cout<<"How much do they get paid for an hour?: ";
            cin>>y;
            }
        cost=y;
        emp[m].set_cost(cost);
        break;

        case 5:
        cout<<"How much do they get deducted?: ";
        cin>>u;
        while(u<=0){
            cout<<"Plese enter a valid number."<<endl;
            cout<<"How much do they get deducted?: ";
            cin>>u;
            }
        deduct=u;
        emp[m].set_deduct(deduct);
        break;
    }
    }while(select2!=6);

        }else{
            cout<<"Employee ID not found."<<endl;
        }
       cout<<"Do you want to search for another employee(y/n)? ";
        cin>>lo;
        if(lo=='n' || lo=='N'){
        Loop=false;
    
        }
    }while(Loop);


};
};


//main where we read the file and create an H object
//and prints the menu in a do while loops in a switch case which asks the user for the inputs for the add fucntion
//the it rewrites the file with the new arrays and then ends the program.

int main(){
HRM H;
    ifstream file1("Employee.txt");
    string first;
    string last;
    int hours;
    int pay;
    int ded;
    
    while(!file1.eof()){
    if(file1.eof()){
        break;
        }
        file1>>first;
        file1>>last;
        file1>>hours;
        file1>>pay;
        file1>>ded;
        H.add2(first,last,hours,pay,ded);
        
    }

    int select;
    do{
    cout<<">>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<";
                cout<<"\n";
                cout<<"1:   To Add New Employee Details"<<endl;
                cout<<"2:   To Remove an Employee Details"<<endl;
                cout<<"3:   To Modify Existing Employee Details"<<endl;
                cout<<"4:   To Search for Employee"<<endl;
                cout<<"5:   To Exit     "<<endl;

                cout<<"   Please Enter Your Choice: ";
        cin>>select;
        string fName;
        string lName;
        float hours;
        float x;
        float cost;
        float y;
        float deduct;
        float u;
        char lo;
        bool Loop=true;

        switch(select){
            case 1:
            do{
            cout<<"Please enter the first name of an employee: ";
            cin>>fName;

            cout<<"Please enter the last name of an employee: ";
            cin>>lName;

            cout<<"How many hours do they work?(1-60): ";
            cin>>x;
            while(x<1 || x>60){
                cout<<"Plese enter a valid number."<<endl;
                cout<<"How many hours do they work?: ";
                cin>>x;
             }
            hours=x;

            cout<<"How much do they get paid for an hour?: ";
            cin>>y;
            while(y<1){
                cout<<"Plese enter a valid number."<<endl;
                cout<<"How much do they get paid for an hour?: ";
                cin>>y;
                }
            cost=y;

            cout<<"How much do they get deducted?: ";
            cin>>u;
            while(u<=0){
                cout<<"Plese enter a valid number."<<endl;
                cout<<"How much do they get deducted?: ";
                cin>>u;
                }
            deduct=u; 

            H.add(fName,lName,hours,cost,deduct);
            cout<<"The employee with the following information has been added to the system:"<<endl;
            cout<<"Employee ID\tFirst Name\tLast Name\tSalary per year($)"<<endl;
            cout<<"-----------\t----------\t----------\t----------------------"<<endl;
            cout<<H.emp[num].get_employeeID()<<"\t\t"<<H.emp[num].get_firstName()<<"\t\t"<<H.emp[num].get_lastName()<<"\t\t"<<H.emp[num].get_annualSalary()<<endl;
            cout<<"Do you want to add another employee(y/n)? ";
            cin>>lo;
            if(lo=='n' || lo=='N'){
                Loop=false;
            }
            counter++;
            if (num==100){
            cout<<"Reached 100 employes"<<endl;
            break;
        }        
        }while(Loop);
            
        break;
        case 2:
        H.del();
        break;
        case 3:
        H.edit();
        break;
        case 4:
        H.search(first,last,hours,pay,ded);
        break;
        case 5:
        ofstream file2("Employee.txt");
        for(int i=0;i<num+1;i++){
            file2<<H.emp[i].get_firstName()<<
            " "<<H.emp[i].get_lastName()<<
            " "<<H.emp[i].get_workingHours()<<
            " "<<H.emp[i].get_costPerHour()<<
            " "<<H.emp[i].get_deduction()<<endl;
        };
        exit(0);
        break;
                }

}while(select!=5);
}
