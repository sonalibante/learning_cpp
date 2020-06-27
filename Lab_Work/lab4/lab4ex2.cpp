//Lab 4 exercise 2
//Fall 2018
//js236

#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 6;

struct MonthlyBudget
{
    string category;
    double allocated;
    double spent;
};

void getSpent(MonthlyBudget B[])
{
    cout << "During the past month:\n";
    for(int i = 0 ; i<SIZE;i++)
    {
        cout << "How much was spent on "<< B[i].category<<" ? ";
        cin  >> B[i].spent;
    }
}

void displayTable(MonthlyBudget B[])
{
    cout << "Categories:    " << setw(10) << "Budget:" << setw(15)
         << "Spent:" << setw(15) << "Over-Under" <<endl;
    for(int i = 0 ; i<SIZE;i++)
    {
        cout << setw(15)<< left <<B[i].category<< right
        << setw(10)<< B[i].allocated
        << setw(15)<< B[i].spent
        << setw(15)<< B[i].allocated - B[i].spent<<endl;
    }
}

double calcOverUnder(MonthlyBudget B[])
{
    double totalB=0;
    double totalS=0;
    
    for(int i = 0 ; i<SIZE;i++)
    {
        totalB=totalB+B[i].allocated;
        totalS=totalS+B[i].spent;
    }
    return totalB-totalS;
}

int main()
{
    MonthlyBudget budget[SIZE]={
        {"Housing",500.00,0.00},
        {"Transportation",50.00,0.00},
        {"Food", 250.00,0.00},
        {"Entertainment",150.00,0.00},
        {"Clothing",75.00,0.00},
        {"Other",50.00,0.00}
    };
    
    cout << fixed << setprecision(2);
    getSpent(budget);
    displayTable(budget);
    
    double total = calcOverUnder(budget);
    if(total<0)
        cout<<"The total money spent is $"<< -total <<" over the budget."<<endl;
    else
        cout<<"The total money spent is $"<< total <<" under the budget."<<endl;

    return 0;
}




