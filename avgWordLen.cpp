/*
 * ########################### Average Word Length ###########################
 * Copyright: Deepak Singh.
 * Date: May, 2021
 *
 * You are in a college level English class, your professor wants you to
 * write an essay, but you need to find out the average length of all the
 * words you use. It is up to you to figure out how long each word is and to
 * average it out.
 *
 * Task:
 * Takes in a string, figure out the average length of all the words and
 * return a number representing the average length. Remove all punctuation.
 * Round up to the nearest whole number.
 *
 * Input Format:
 * A string containing multiple words.
 *
 * Output Format:
 * A number representing the average length of each word, rounded up to the
 * nearest whole number.
 *
 * Sample Input:
 * this phrase has multiple words
 *
 * Sample Output:
 * 6
 */
#include<iostream>
#include<string>
#include<cmath>

using namespace std;
int main(int argc, char * argv[]){
/*
 * Input:
 * 1. origString - takes a string as input
 * Output:
 * The function returns the average length rounded upto a whole length
 * Methodology:
 * First the number of words are calculated by removing starting and ending
 * spaces. The spaces from the paragraph are then removed. The average
 * length is then rounded up. Only alphabets are counted in length.
 */
    try{
    	string origString = "";
        int numOfWords = 1, length = 0;
        unsigned int i = 0;
        char checkCharac;
    	char space[] = {" "};
    	getline(cin, origString);

    	//Remove whitespaces from start and end of string
    	checkCharac = origString.at(0);
    	if(checkCharac == space[0]){
    		origString.erase(origString.begin());
    	}
    	checkCharac = origString.at(origString.size() - 1);
    	if(checkCharac == space[0]){
    		origString.erase(origString.end());
    	}

    	while(i < origString.size()){
            int asciiVal = int(origString[i]);
             if( ((asciiVal >= 65) and (asciiVal <= 90)) or ((asciiVal >= 97) and (asciiVal <= 122)) )
                length = length + 1;
            if(asciiVal == 32)
                numOfWords = numOfWords + 1;
            i = i + 1;
    	}
        int avgLength = ceil(float(length)/numOfWords);
        cout << avgLength;

        return 0;
    }
    catch(std::exception){
        cout << "Input is not string." << endl;
    }
}
