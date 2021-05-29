/*
 * ################################ Fruit Bowl ################################
 * Copyright: Deepak Singh.
 * Date: May, 2021
 *
 * You have a bowl on your counter with an even number of pieces of fruit in
 * it. Half of them are bananas, and the other half are apples. You need 3
 * apples to make a pie.
 *
 * Task
 * Your task is to evaluate the total number of pies that you can make with
 * the apples that are in your bowl given to total amount of fruit in the
 * bowl.
 *
 * Input Format
 * An integer that represents the total amount of fruit in the bowl.
 *
 * Output Format
 * An integer representing the total number of whole apple pies that you can
 * make. The two exceptions declared here lead to an error in the sololearn
 * tests, so they have been commented out.
 */
#include<iostream>
#include<exception>

using namespace std;

struct notEven : public exception {
   const char * what () const throw () {
      return "The input is not an even number";
   }
};

struct notPositive : public exception {
   const char * what () const throw () {
      return "The input is not a whole number";
   }
};


int main(int argc, char * argv[]){
/*
 * Input:
 * 1. numOfFruits - Number of fruits in the bowl
 * Output:
 * The function returns the number of pies that can be made.
 * Methodology:
 * The function first checks if the numberofFruits is even. It then finds
 * the quotient after division by 3.
 */
    try{
    	int numOfFruits = 0;
    	cin >> numOfFruits;
        if((numOfFruits <= 0))
            throw notPositive();
        if((numOfFruits%2 != 0))
        	throw notEven();

        int noOfPies = numOfFruits/6;
        cout << noOfPies;
        return 0;
    }
    catch(notEven msg){
        cout << msg.what() << endl;
    }
    catch(notPositive msg){
        cout << msg.what() << endl;
    }
    catch(std::exception){
        cout << "Input is not valid." << endl;
    }
}
