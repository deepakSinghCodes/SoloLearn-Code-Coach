/*
 * ################################ Pig Latin ################################
 * Copyright: Deepak Singh.
 * Date: May, 2021
 *
 * You have two friends who are speaking Pig Latin to each other! Pig Latin is
 * the same words in the same order except that you take the first letter of
 * each word and put it on the end, then you add 'ay' to the end of that.
 * ("road" = "oadray")
 *
 * Task:
 * Your task is to take a sentence in English and turn it into the same
 * sentence in Pig Latin!
 *
 * Input Format:
 * A string of the sentence in English that you need to translate into Pig
 * Latin. (no punctuation or capitalization)
 *
 * Output Format:
 * A string of the same sentence in Pig Latin.
 *
 * E.g.:
 * "nevermind youve got them"
 * to
 * "evermindnay ouveyay otgay hemtay"
 */
#include<iostream>
#include<string>

using namespace std;
int main(int argc, char * argv[]){
/*
 * Input:
 * 1. origString - takes a string as input
 * Output:
 * The function returns a string in pig latin
 * Methodology:
 * A single word input is treated differently, but for others based on the
 * space we will store the first letter and make changes to the current word
 */
    try{
    	string origString = "", outputString = "";
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

        if(origString.size() == 1){
            outputString = "ay" + origString;
        }
        else{
            char firstLetter = origString.at(0);

            for (unsigned int i = 1; i < origString.size(); i++){
                if(origString.at(i-1) == space[0]){
                    firstLetter = origString.at(i);
                }
                else{
                	if(origString.at(i) != space[0]){
                		outputString = outputString + origString[i];
                	}
                	else{
                		outputString = outputString + firstLetter + "ay ";
                	}
                }
            }
            outputString = outputString + firstLetter + "ay";
        }
	cout << outputString;
	return 0;
    }
    catch(std::exception){
        cout << "Input is not string." << endl;
    }
}
