/*
   Program: Monthly Budget
   Programmer: Nathan Andrews
   Last modified: 9/29/19
   This program holds expensises in each category in MonthlyBudget
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// structure Monthly Budget
struct MonthlyBudget
{
	float housing,
		utilities,
		householdExpenses,
		transportation,
		food,
		medical,
		insurance,
		entertainment,
		clothing,
		Miscellaneous;
};

void getData(MonthlyBudget &);
void displayData(MonthlyBudget &, float[], float[], string[], string, float, float, float );

int main()
{
	MonthlyBudget student;

	getData(student);

	system("pause");
	return 0;
}

void getData(MonthlyBudget &student)
{
	//declare variables and size
	const int SIZE = 10;
	float MonthlyBudgetGoal[] = { 500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00 };
	float NewMonthlyBudget[SIZE];
	string Budget[SIZE], TotalBudget;
	float budgetGoal, budgetTotal, Total;

	// ask user for the aspect of the budget, stores the number and calculates the new monthly budget
	cout << "Enter how much you spent for housing: ";
	cin >> student.housing;
	NewMonthlyBudget[0] = MonthlyBudgetGoal[0] - student.housing;

	cout << "Enter how much you spent on utilities: ";
	cin >> student.utilities;
	NewMonthlyBudget[1] = MonthlyBudgetGoal[1] - student.utilities;

	cout << "Enter how much you spent on household expenses: ";
	cin >> student.householdExpenses;
	NewMonthlyBudget[2] = MonthlyBudgetGoal[2] - student.householdExpenses;

	cout << "Enter how much you spent on transportation: ";
	cin >> student.transportation;
	NewMonthlyBudget[3] = MonthlyBudgetGoal[3] - student.transportation;

	cout << "Enter how much you spent on food: ";
	cin >> student.food;
	NewMonthlyBudget[4] = MonthlyBudgetGoal[4] - student.food;

	cout << "Enter how much you spent on medical: ";
	cin >> student.medical;
	NewMonthlyBudget[5] = MonthlyBudgetGoal[5] - student.medical;

	cout << "Enter how much you spent on insurance: ";
	cin >> student.insurance;
	NewMonthlyBudget[6] = MonthlyBudgetGoal[6] - student.insurance;

	cout << "Enter how much you spent on entertainment: ";
	cin >> student.entertainment;
	NewMonthlyBudget[7] = MonthlyBudgetGoal[7] - student.entertainment;

	cout << "Enter how much you spent on clothing: ";
	cin >> student.clothing;
	NewMonthlyBudget[8] = MonthlyBudgetGoal[8] - student.clothing;

	cout << "Enter how much you spent on miscellaneous: ";
	cin >> student.Miscellaneous;
	NewMonthlyBudget[9] = MonthlyBudgetGoal[9] - student.Miscellaneous;

    // calculates budget totals and others
	for (int i = 0; i < 10; i++)
	{
		// figures which will be over or under
		if (NewMonthlyBudget[i] < 0)
			Budget[i] = " over";
		if (NewMonthlyBudget[i] > 0)
			Budget[i] = " under";

		// takes the number and eliminates the negative
		if (NewMonthlyBudget[i] < 0)
			NewMonthlyBudget[i] = NewMonthlyBudget[i] * -1;

		// adds the old budget together for the total
		budgetGoal = +MonthlyBudgetGoal[i];
		// adds the new budget together for the new total
		budgetTotal = +NewMonthlyBudget[i];

		// finds the the total by subtracting the old with the new total budget
		Total = budgetGoal - budgetTotal;

		// finds if the new total is over or under the old budget
		if (Total < 0)
			TotalBudget = " over";
		else if (Total > 0)
			TotalBudget = " under";
		else
			TotalBudget = " on";
	}

	displayData(student, MonthlyBudgetGoal, NewMonthlyBudget, Budget, TotalBudget, budgetGoal, budgetTotal, Total);
}

void displayData(MonthlyBudget &student, float MonthlyBudgetGoal[], float NewMonthlyBudget[], string Budget[], string TotalBudget, float budgetGoal, float budgetTotal, float Total)
{
	// displays the data
	cout << setprecision(2) << fixed;
	cout << "\nStudents new monthly budget.\n";
	cout << "Housing $" << student.housing << ". You are " << NewMonthlyBudget[0] << Budget[0] << " budget.\n";
	cout << "Utilities $" << student.utilities << ". You are " << NewMonthlyBudget[1] << Budget[1] << " budget.\n";
	cout << "Household $" << student.householdExpenses << ". You are " << NewMonthlyBudget[2] << Budget[2] << " budget.\n";
	cout << "Transportation $" << student.transportation << ". You are " << NewMonthlyBudget[3] << Budget[3] << " budget.\n";
	cout << "Food $" << student.food << ". You are " << NewMonthlyBudget[4] << Budget[4] << " budget.\n";
	cout << "Medical $" << student.medical << ". You are " << NewMonthlyBudget[5] << Budget[5] << " budget.\n";
	cout << "Insurance $" << student.insurance << ". You are " << NewMonthlyBudget[6] << Budget[6] << " budget.\n";
	cout << "Entertainment $" << student.entertainment << ". You are " << NewMonthlyBudget[7] << Budget[7] << " budget.\n";
	cout << "Clothing $" << student.clothing << ". You are " << NewMonthlyBudget[8] << Budget[8] << " budget.\n";
	cout << "Miscellaneous $" << student.Miscellaneous << ". You are " << NewMonthlyBudget[9] << Budget[9] << " budget.\n";
	cout << "Old total monthly budget $" << budgetGoal << ". \n";
	cout << "New total monthly budget $" << budgetTotal << ". \n";
	cout << "\nYou are $" << Total << TotalBudget << " the monthly budget.\n";
}
// "I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."