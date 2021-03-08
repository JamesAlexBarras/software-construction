/* FILE NAME: project1_Barras_jab0217.cpp 
// AUTHOR: James Alexander Barras  (jab0217)
// COMPILER USED: This is what the server says it is (c++ (GCC) 4.8.5 20150623 (Red Hat 4.8.5-44)), it's whichever one the AU server uses (c++11 maybe?). 
//
// I used this website to figure out how to initialize variables in C++:  https://www.geeksforgeeks.org/different-ways-to-initialize-a-variable-in-c-c/
//`
// I used this website to understand the cout.setf and cout.precision commands as indicated in the Project1_hints.pdf file: https://mathbits.com/MathBits/CompSci/DataBasics/formatting.htm
//
// I used this website to understand the cout/cin commands and the >>/<< operations as indicated in the Project1_hints.pdf file: http://www.cplusplus.com/doc/tutorial/basic_io/
//
// I was directed to this website by a TA in piazza to figure out how to deal with non numerical inputs:  https://stackoverflow.com/questions/12721911/c-how-to-verify-is-the-data-input-is-of-the-correct-datatype
//
// comments about outside resources
//
*/

 #include <iostream>
 #include <limits>
using namespace std;

int main() {
 
   double loan = -1;
   double interestRate = -1;
   double multiplier;
   double payment = -1;
   int monthCounter = 0;
   double totalPaid = 0;
   bool conditionSatisfied = false; 
   double interest = 0;
   double principal = 0;
   bool insufficient = true;

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   while (conditionSatisfied == false) {
   
      while (loan <= 0) {
      
         cout << "\nLoan Amount: ";
         cin >> loan;
      
         if (!cin) {
            cout << "Invalid loan";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
         }
      
         if (loan <= 0) {
            cout << "Invalid loan";
         }
      
      
      
      } 
   
      while (interestRate < 0) {
      
         cout << "Interest Rate (% per year): ";
         cin >> interestRate;
      
      
         if (!cin) {
            cout << "Invalid interest rate\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            interestRate = -1;
            continue;
         }
      
         if (interestRate < 0) {
            cout << "Invalid interst rate\n";
         }
      
      
      }
   
      interestRate = interestRate / 12;
      multiplier = interestRate / 100;
   
      while ((payment <= 0) || (insufficient == true)) {
      
         cout << "Monthly Payments: ";
         cin >> payment;
      
         if (!cin) {
            cout << "Invalid payment\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
         }
      
         if (payment <=  0) {
            cout << "Invalid payment\n";
            continue; 
         }
         if (payment <= (loan * multiplier)) {
            cout << "Insufficient payment\n";
            insufficient = true;
            continue;
         }
         insufficient = false;
      
      }
   
      conditionSatisfied = true;
   }

   cout << endl;

//cout << "loan: " << loan << "\tpayment: " << payment << "\tinterest rate: " << interestRate;

   cout << "*****************************************************************\n"
      << "\tAmortization Table\n"
      << "*****************************************************************\n"
      << "Month\tBalance\t\tPayment\t\tRate\tInterest\tPrincipal\n";

   while (loan > 0) {
   
      if (monthCounter == 0) {
         cout << monthCounter++ << "\t$" << loan;
      
         if (loan < 1000) cout << "\t";
      
         cout << "\t" << "N/A\t\tN/A\tN/A\t\tN/A\n";
      }
      else {
      
         if ((loan * (1 + multiplier)) >= payment) {
         //formatting
            interest = (loan * multiplier);
            principal = payment - interest;
            loan = (loan - principal);
            totalPaid = totalPaid + interest;
         
         
            cout << monthCounter++ << "\t$" << loan;
            if (loan < 1000) cout << "\t";
            cout << "\t$" << payment << "\t\t" << interestRate << "\t$" << interest << "\t\t$" << principal << "\n";
         
         } 
         else if ((loan * (1 + multiplier)) < payment) {
         // last month formatting
            interest = (loan * multiplier);
            payment = loan + interest;
            principal = loan;
            loan = loan - principal;
            totalPaid = totalPaid + interest;
         
         
            cout << monthCounter++ << "\t$" << loan;
            if (loan < 1000) cout << "\t";
            cout << "\t$" << payment << "\t\t" << interestRate << "\t$" << interest << "\t\t$" << principal << "\n";
         
         }
      }
   }

   cout << "****************************************************************\n";
   cout << "\nIt takes " << --monthCounter << " months to pay off the loan.\n"
      << "Total interest paid is: $" << totalPaid;
   cout << endl << endl;
   return 0;

}
