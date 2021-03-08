/* Filename: project2_Barras_jab0217.cpp
 * Name: James Barras (jab0217)
 * Compiler: compiled using AU server's compiler (c++11 I believe?)
 *
 * External resources:
 *
 * I used this website to figure out the use of the "srand (time(NULL))" call: https://mathbits.com/MathBits/CompSci/LibraryFunc/rand.htm
 *
 */

 #include <iostream>
 #include <stdlib.h>
 #include <assert.h>
 #include <ctime>
 
using namespace std;
 
 //
 // Base functions
 //
 //
 
 // checks to see if two are alive
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
 
   if ((A_alive == true) && (B_alive == true)) {
      return true;
   }
   else if ((A_alive == true) && (C_alive == true)) {
      return true;
   }
   else if ((B_alive == true) && (C_alive == true)) {
      return true;
   }

   return false;
}
 

 //Aaron shoots and Bob and Charlie
void Aaron_shoots1(bool& B_alive, bool& C_alive){
   assert((B_alive == true) || (C_alive == true));

 //srand (time(NULL));
   int odds = rand() % 100;
   bool hits = false; 
   int accuracy = 33;

   if (odds < accuracy) {
      hits = true;
   }

   if (C_alive == true) {
      if (hits == true) {
         C_alive = false;
      //cout << "Aaron shot charlie\n";
      }
      return;
   }

   if (B_alive == true) {
      if (hits == true) {
         B_alive = false;
      //cout << "aaron shot bob\n";
      }
      return;
   }

}


 //Bob shoots at Aaron and charlie
void Bob_shoots(bool& A_alive, bool& C_alive) {
   assert((A_alive == true) || (C_alive == true)); 

 //srand (time(NULL));
   int odds = rand() % 100;
   bool hits = false;
   int accuracy = 50;

   if (odds < accuracy) {
      hits = true;
   }

   if (C_alive == true) {
      if (hits == true) {
         C_alive = false;
      //cout << "bob shot charlie\n";
      }
      return;
   }

   if (A_alive == true) {
      if (hits == true) {
         A_alive = false;
      //cout << "bob shot aaron\n";
      }
      return;
   }

}

 
 //Charlie shoots at Aaron and Bob
void Charlie_shoots(bool& A_alive, bool& B_alive) {
   assert((A_alive == true) || (B_alive == true));


   if (B_alive == true) {
      B_alive = false;
   //cout << "charlie shot bob\n";
      return;
   }

   if (A_alive == true) {
      A_alive = false;
   //cout << "charlie shot aaron\n";
      return;
   }

}


 //Aaron waits if both are alive, then makes his move
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
 //srand (time(NULL));
 
   int odds = rand() % 100;
   bool hits = false;
   int accuracy = 33;

   if (odds < accuracy) {
      hits = true;
   }

   if ((C_alive == true) && (B_alive == true)) {
      return;
   }

   if (C_alive == true) {
      if (hits == true) {
         C_alive = false;
      //cout << "Hit the target\n";
      }
      return;
   }

   if (B_alive == true) {
      if (hits == true) {
         B_alive = false;
      //cout << "Hit the target\n";
      }
      return;
   }

}

 //pause method
void Press_any_key(void) {
   cout << "Press and key to continue...";
   cin.ignore().get();
}

 //
 // Tests for base functions
 //
 //

 // Test for at least two alive function
void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
 
//
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   bool A_alive = true;
   bool B_alive = true;
   bool C_alive = true;
   bool answer = at_least_two_alive(A_alive, B_alive, C_alive);
   assert(answer == true);
   cout << "\tCase passed ...\n";

//
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   A_alive = false;
   B_alive = true;
   C_alive = true;
   bool anser1 = at_least_two_alive(A_alive, B_alive, C_alive);
   assert(anser1 == true);
   cout << "\tCase passed ...\n";

//
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   A_alive = true;
   B_alive = false;
   C_alive = true;
   bool anser2 = at_least_two_alive(A_alive, B_alive, C_alive);
   assert(anser2 == true);
   cout << "\tCase passed ...\n";
 
//
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   A_alive = true;
   B_alive = true;
   C_alive = false;
   bool anser3 = at_least_two_alive(A_alive, B_alive, C_alive);
   assert(anser3 == true);
   cout << "\tCase passed ...\n";

//
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   A_alive = false;
   B_alive = false;
   C_alive = true;
   bool anser4 = at_least_two_alive(A_alive, B_alive, C_alive);
   assert(anser4 == false);
   cout << "\tCase passed ...\n";

//
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   A_alive = false;
   B_alive = true;
   C_alive = false;
   bool anser5 = at_least_two_alive(A_alive, B_alive, C_alive);
   assert(anser5 == false);
   cout << "\tCase passed ...\n";

//
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   A_alive = true;
   B_alive = false;
   C_alive = false;
   bool anser6 = at_least_two_alive(A_alive, B_alive, C_alive);
   assert(anser6 == false);
   cout << "\tCase passed ...\n";

//
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   A_alive = false;
   B_alive = false;
   C_alive = false;
   bool anser7 = at_least_two_alive(A_alive, B_alive, C_alive);
   assert(anser7 == false);
   cout << "\tCase passed ...\n";
 
}

 //Test to test aaron_shoots1 function
void test_Aaron_shoots1(void) {
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
 
   cout << "\tCase 1: Bob alive, Charlie alive\n"
      << "\t\tAaron is shooting at Charlie\n";
   bool B_alive = true;
   bool C_alive = true;
   Aaron_shoots1(B_alive, C_alive);

//
   cout << "\tCase 2: Bob dead, Charlie alive\n"
      << "\t\tAaron is shooting at Charlie\n";
   B_alive = false;
   C_alive = true;
   Aaron_shoots1(B_alive, C_alive);

//
   cout << "\tCase 3: Bob alive, Charlie dead\n"
      << "\t\tAaron is shooting at Bob\n";
   B_alive = true;
   C_alive = false;
   Aaron_shoots1(B_alive, C_alive);

}

 //Test to test bob_shoots function
void test_Bob_shoots(void) {
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

   cout << "\tCase 1: Aaron alive, Charlie alive\n"
      << "\t\tBob is shooting at Charlie\n";
   bool A_alive = true;
   bool C_alive = true;
   Bob_shoots(A_alive, C_alive);

//
   cout << "\tCase 2: Aaron dead, Charlie alive\n"
      << "\t\tBob is shooting at Charlie\n";
   A_alive = false;
   C_alive = true;
   Bob_shoots(A_alive, C_alive);

//
   cout << "\tCase 3: Aaron alive, Charlie dead\n"
      << "\t\tBob is shooting at Aaron\n";
   A_alive = true;
   C_alive = false;
   Bob_shoots(A_alive, C_alive); 
 
}

 //Test to test Charlie_shoots function
void test_Charlie_shoots(void) {
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

   cout << "\tCase 1: Aaron alive, Bob alive\n"
      << "\t\tCharlie is shooting at Bob\n";
   bool A_alive = true;
   bool B_alive = true;
   Charlie_shoots(A_alive, B_alive);

//
   cout << "\tCase 2: Aaron dead, Bob alive\n"
      << "\t\tCharlie is shooting at Bob\n";
   A_alive = false;
   B_alive = true;
   Charlie_shoots(A_alive, B_alive);

//
   cout << "\tCase 3: Aaron alive, Bob dead\n"
      << "\t\tCharlie is shooting at Aaron\n";
   A_alive = true;
   B_alive = false; 
   Charlie_shoots(A_alive, B_alive); 
 
}

 //Test to test Aaron shoots2 function
void test_Aaron_shoots2(void) {
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

   cout << "\tCase 1: Bob alive, Charlie alive\n"
      << "\t\tAaron intentionally misses his first shot\n"
      << "\t\tBoth Bob and Charlie are alive.\n";
   bool B_alive = true;
   bool C_alive = true;
   Aaron_shoots2(B_alive, C_alive);

//
   cout << "\tCase 2: Bob dead, Charlie alive\n"
      << "\t\tAaron is shooting at Charlie\n";
   B_alive = false;
   C_alive = true;
   Aaron_shoots2(B_alive, C_alive);

//
   cout << "\tCase 3: Bob alive, Charlie dead\n"
      << "\t\tAaron is shooting at Bob\n";
   B_alive = true;
   C_alive = false;
   Aaron_shoots2(B_alive, C_alive);

}

 //
 // Main method
 //
 //

int main() {
   cout.setf(ios::fixed);
   cout.precision(2);

   cout << "*** Welcome to James's duel Simulator ***\n";
   srand(time(0));

 //tests
   test_at_least_two_alive();
   Press_any_key();
   test_Aaron_shoots1();
   Press_any_key();
   test_Bob_shoots();
   Press_any_key();
   test_Charlie_shoots();
   Press_any_key();
   test_Aaron_shoots2();
   Press_any_key();

 //strategy 1
   cout << "Ready to test strategy 1 (run 10000 times):\n";
   Press_any_key();

   int Awins1 = 0;
   int Bwins = 0;
   int Cwins = 0;
   bool A_alive;
   bool B_alive;
   bool C_alive;
 
   for(int i = 0; i < 10000; i++) {
   
      A_alive = true;
      B_alive = true;
      C_alive = true;
   
   //cout << "next game\n";
   
      while(at_least_two_alive(A_alive, B_alive, C_alive)) {
      
      //cout << "next round\n";
      
         if (A_alive == true) {
            Aaron_shoots1(B_alive, C_alive);
         } 
         if (B_alive == true) {
            Bob_shoots(A_alive, C_alive);
         }
         if (C_alive == true) {
            Charlie_shoots(A_alive, B_alive);
         }
      
      /* 
      int a = 0;
      int b = 0;
      int c = 0;
      
      if (A_alive) {
      a = 1;
      }
      if (B_alive) {
      b = 1;
      }
      if (C_alive) {
      c = 1;
      }
      
      
      cout << "Aaron: " << a
      << "\nBob: " << b
      << "\nCharlie: " << c << endl;
      //Press_any_key();
      */
      
      
      }
      if (A_alive == true) {
         Awins1++;
      }
      if (B_alive == true) {
         Bwins++;
      }
      if (C_alive == true) {
         Cwins++;
      }
   
   /* 
   cout << "Awins: " << Awins1
      << "\nBwins: " << Bwins
      << "\nCwins: " << Cwins << endl;
   Press_any_key();
   */
   
   }

/*
cout << "Awins: " << Awins1
     << "\nBwins: " << Bwins
     << "\nCwins: " << Cwins << endl;
*/

   cout << "Aaron won " << Awins1 << "/10000 duels or " << static_cast<double>(Awins1) / 10000 * 100 << "%\n"
      << "Bob won " << Bwins << "/10000 duels or " << static_cast<double>(Bwins) / 10000 * 100 << "%\n"
      << "Charlie won " << Cwins << "/10000 duels or " << static_cast<double>(Cwins) / 10000 * 100 << "%\n"
      << endl;

 
 //Strategy 2
   cout << "Ready to test strategy 2 (run 10000 times):\n";
   Press_any_key();

   int Awins2 = 0; 
   Bwins = 0;
   Cwins = 0;

   for(int i = 0; i < 10000; i++) {
      A_alive = true;
      B_alive = true;
      C_alive = true;
   
      while(at_least_two_alive(A_alive, B_alive, C_alive)) {
         if (A_alive == true) {
            Aaron_shoots2(B_alive, C_alive);
         }
         if (B_alive == true) {
            Bob_shoots(A_alive, C_alive);
         }
         if (C_alive == true) {
            Charlie_shoots(A_alive, B_alive);
         }
      
      }
      if (A_alive == true) {
         Awins2++;
      }
      if (B_alive == true) {
         Bwins++;
      }
      if (C_alive == true) {
         Cwins++;
      }
   }

   cout << "Aaron won " << Awins2 << "/10000 duels or " <<  static_cast<double>(Awins2) / 10000 * 100 << "%\n"
      << "Bob won " << Bwins << "/10000 duels or " <<  static_cast<double>(Bwins) / 10000 * 100 << "%\n"
      << "Charlie won " << Cwins << "/10000 duels or " << static_cast<double>(Cwins) / 10000 * 100 << "%\n"
      << endl;

 //checking to see which strategy is better for Aaron
   if (Awins1 > Awins2) {
      cout << "Strategy 1 is better than strategy 2.\n";
   }
   else {
      cout << "Strategy 2 is better than strategy 1.\n";
   }

   return 0;
}
