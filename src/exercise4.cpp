/*******************************************************************************
 *	PART 4 - Functions
 *==============================================================================
 *  References:
 *		`Slides on Functions`
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;


// Function Prototypes Here
void printVector(vector<string> set);
void sortVec(vector<string> &set);


int main()
{
	vector<string> set1 = {"banana","apple","pear"};
	vector<string> set2 = {"abs", "aas", "aaa", "at", "zebra"};

	// Call your sorting function on the sets
	// REPLACE WITH YOUR CODE


	// Print the sets
	// REPLACE WITH YOUR CODE

	return 0;
}

/**
 * Create a print vector function
 * input:  set1 
 * output on one line: {'apple, banana, pear'}
 */
void printVector(vector<string> set)
{

}


/**
* Create your alphabetical sort function here
* input:  set1 
* output on one line: {'apple, banana, pear'}
*/
void sortVec(vector<string> &set)
{
	// Extra question: Why is this function pass by reference?
	// What would happen if it was pass by value
}