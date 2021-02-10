#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ItemCollection.hpp"
#include <math.h>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
    //divider = pow(10, i)
    //remainder = x % divider (7)
    //x -= remainder (1234560)
    //remainder = x % divider (60)
    //x -= remainder (1234500)
    //...
    //if divider == pow(10, 6) then
    //d = x / divider
    //return d 
    unsigned int divider;
    unsigned int digit = 1;
    //take off the trailing digits
    for (unsigned i = 1; i < (7 - digit + 1); i++) {
	divider = pow(10, i);
	int remainder = barcode % divider;
	barcode -= remainder;
    }
    //take off the leading digits
    for (unsigned i = 6; i > (7 - digit - 1); i--) {
	    divider = pow(10, i);
	    if (i == (7 - digit))
		    barcode = barcode / divider;
	    else
		    barcode = barcode % divider;
    }
    return barcode; 
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
    unsigned int divider;
    unsigned int digit = 2;
    //take off the trailing digits
    for (unsigned i = 1; i < (7 - digit + 1); i++) {
	divider = pow(10, i);
	int remainder = barcode % divider;
	barcode -= remainder;
    }
    //take off the leading digits
    for (unsigned i = 6; i > (7 - digit - 1); i--) {
	    divider = pow(10, i);
	    if (i == (7 - digit))
		    barcode = barcode / divider;
	    else
		    barcode = barcode % divider;
    }
    return barcode;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
    unsigned int divider;
    unsigned int digit = 3;
    //take off the trailing digits
    for (unsigned i = 1; i < (7 - digit + 1); i++) {
	divider = pow(10, i);
	int remainder = barcode % divider;
	barcode -= remainder;
    }
    //take off the leading digits
    for (unsigned i = 6; i > (7 - digit - 1); i--) {
	    divider = pow(10, i);
	    if (i == (7 - digit))
		    barcode = barcode / divider;
	    else
		    barcode = barcode % divider;
    }
    return barcode;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
    unsigned int divider;
    unsigned int digit = 4;
    //take off the trailing digits
    for (unsigned i = 1; i < (7 - digit + 1); i++) {
	divider = pow(10, i);
	int remainder = barcode % divider;
	barcode -= remainder;
    }
    //take off the leading digits
    for (unsigned i = 6; i > (7 - digit - 1); i--) {
	    divider = pow(10, i);
	    if (i == (7 - digit))
		    barcode = barcode / divider;
	    else
		    barcode = barcode % divider;
    }
    return barcode;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
    unsigned int divider;
    unsigned int digit = 5;
    //take off the trailing digits
    for (unsigned i = 1; i < (7 - digit + 1); i++) {
	divider = pow(10, i);
	int remainder = barcode % divider;
	barcode -= remainder;
    }
    //take off the leading digits
    for (unsigned i = 6; i > (7 - digit - 1); i--) {
	    divider = pow(10, i);
	    if (i == (7 - digit))
		    barcode = barcode / divider;
	    else
		    barcode = barcode % divider;
    }
    return barcode;
}

// function to return the hash value based on the sixth digit
unsigned int hashfct6(unsigned int barcode) {
    unsigned int divider;
    unsigned int digit = 6;
    //take off the trailing digits
    for (unsigned i = 1; i < (7 - digit + 1); i++) {
	divider = pow(10, i);
	int remainder = barcode % divider;
	barcode -= remainder;
    }
    //take off the leading digits
    for (unsigned i = 6; i > (7 - digit - 1); i--) {
	    divider = pow(10, i);
	    if (i == (7 - digit))
		    barcode = barcode / divider;
	    else
		    barcode = barcode % divider;
    }
    return barcode;
}

// function to return the hash value based on the seventh digit
unsigned int hashfct7(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int divider;
    for (int i = 6; i > 0; i--) {
	    divider = pow(10, i);
	    barcode = barcode % divider;
    }
    return barcode;
}


// Constructor for struct Item
Item::Item(string itemColor, string itemShape, string itemBrand,
		 unsigned int barcode):itemColor_(itemColor),itemShape_(itemShape), itemBrand_(itemBrand),
				       barcode_(barcode)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemColor;
    string itemShape;
    string itemBrand;
    unsigned int barcode;
    while (myfile >> itemColor >> itemShape >> itemBrand >> barcode) {
			if (itemColor.size() > 0)
      	addItem(itemColor, itemShape, itemBrand, barcode);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemCollection::addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode) {
  // TO BE COMPLETED
  // function that adds the specified pair of glasses to main display (i.e., to all hash tables)
	Item glasses = Item(itemColor, itemShape, itemBrand, barcode);

	//only need key and value
	hT1.insert({barcode, glasses});
	hT2.insert({barcode, glasses});
	hT3.insert({barcode, glasses});
	hT4.insert({barcode, glasses});
	hT5.insert({barcode, glasses});
	hT6.insert({barcode, glasses});
	hT7.insert({barcode, glasses});
}

bool ItemCollection::removeItem(unsigned int barcode) {
  // TO BE COMPLETED
  // function that removes the pair of glasses specified by the barcode from the display
  // if pair is found, then it is removed and the function returns true
  // else returns false
  	if (hT1.find(barcode) == hT1.end())
		return false;
	else
		hT1.erase(barcode);
	if (hT2.find(barcode) == hT2.end())
		return false;
	else
		hT2.erase(barcode);
	if (hT3.find(barcode) == hT3.end())
		return false;
	else
		hT3.erase(barcode);
	if (hT4.find(barcode) == hT4.end())
		return false;
	else
		hT4.erase(barcode);
	if (hT5.find(barcode) == hT5.end())
		return false;
	else
		hT5.erase(barcode);
	if (hT6.find(barcode) == hT6.end())
		return false;
	else
		hT6.erase(barcode);
	if (hT7.find(barcode) == hT7.end())
		return false;
	else
		hT7.erase(barcode);
	return true;
}

unsigned int ItemCollection::bestHashing() {
  // TO BE COMPLETED
  // function that decides the best hash function, i.e. the ones among
  // fct1-fct7 that creates the most balanced hash table for the current
  // ItemCollection data member allItems

	// Hints:
	// Calculate the balance of each hashtable, one by one.
	//hT1
	unsigned int minLoc1 = 0;
	unsigned int maxLoc1 = 0;
        unsigned int balance[7];
	for (unsigned i=1; i<10; ++i) {
		//bucket_size is a member function of unordered_map
		if (hT1.bucket_size(i) < hT1.bucket_size(minLoc1)) {
			minLoc1 = i;
		}
		if (hT1.bucket_size(i) > hT1.bucket_size(maxLoc1)) {
			maxLoc1 = i;
		}
  	}
	// Then, calculate the lowest balance
	unsigned int balance1 = hT1.bucket_size(maxLoc1) - hT1.bucket_size(minLoc1);
	// insert into balance array
	balance[0] = balance1;	 	
	
	//hT2
	unsigned int minLoc2 = 0;
	unsigned int maxLoc2 = 0;
	for (unsigned i=1; i<10; ++i) {
		//bucket_size is a member function of unordered_map
		if (hT2.bucket_size(i) < hT2.bucket_size(minLoc2)) {
			minLoc2 = i;
		}
		if (hT2.bucket_size(i) > hT2.bucket_size(maxLoc2)) {
			maxLoc2 = i;
		}
  	}
	// Then, calculate the lowest balance
	unsigned int balance2 = hT2.bucket_size(maxLoc2) - hT2.bucket_size(minLoc2);
	// insert into balance array
	balance[1] = balance2;	 	


	//hT3
	unsigned int minLoc3 = 0;
	unsigned int maxLoc3 = 0;
	for (unsigned i=1; i<10; ++i) {
		//bucket_size is a member function of unordered_map
		if (hT3.bucket_size(i) < hT3.bucket_size(minLoc3)) {
			minLoc3 = i;
		}
		if (hT3.bucket_size(i) > hT3.bucket_size(maxLoc3)) {
			maxLoc3 = i;
		}
  	}
	// Then, calculate the lowest balance
	unsigned int balance3 = hT3.bucket_size(maxLoc3) - hT3.bucket_size(minLoc3);
	// insert into balance array
	balance[2] = balance3;	

	//hT4
	unsigned int minLoc4 = 0;
	unsigned int maxLoc4 = 0;
	for (unsigned i=1; i<10; ++i) {
		//bucket_size is a member function of unordered_map
		if (hT4.bucket_size(i) < hT4.bucket_size(minLoc4)) {
			minLoc4 = i;
		}
		if (hT4.bucket_size(i) > hT4.bucket_size(maxLoc4)) {
			maxLoc4 = i;
		}
  	}
	// Then, calculate the lowest balance
	unsigned int balance4 = hT4.bucket_size(maxLoc4) - hT4.bucket_size(minLoc4);
	// insert into balance array
	balance[3] = balance4;


	//hT5
	unsigned int minLoc5 = 0;
	unsigned int maxLoc5 = 0;
	for (unsigned i=1; i<10; ++i) {
		//bucket_size is a member function of unordered_map
		if (hT5.bucket_size(i) < hT5.bucket_size(minLoc5)) {
			minLoc5 = i;
		}
		if (hT5.bucket_size(i) > hT5.bucket_size(maxLoc5)) {
			maxLoc5 = i;
		}
  	}
	// Then, calculate the lowest balance
	unsigned int balance5 = hT5.bucket_size(maxLoc5) - hT5.bucket_size(minLoc5);
	// insert into balance array
	balance[4] = balance5;


	//hT6
	unsigned int minLoc6 = 0;
	unsigned int maxLoc6 = 0;
	for (unsigned i=1; i<10; ++i) {
		//bucket_size is a member function of unordered_map
		if (hT6.bucket_size(i) < hT6.bucket_size(minLoc6)) {
			minLoc6 = i;
		}
		if (hT6.bucket_size(i) > hT6.bucket_size(maxLoc6)) {
			maxLoc6 = i;
		}
  	}
	// Then, calculate the lowest balance
	unsigned int balance6 = hT6.bucket_size(maxLoc6) - hT6.bucket_size(minLoc6);
	// insert into balance array
	balance[5] = balance6;

	//hT7
	unsigned int minLoc7 = 0;
	unsigned int maxLoc7 = 0;
	for (unsigned i=1; i<10; ++i) {
		//bucket_size is a member function of unordered_map
		if (hT7.bucket_size(i) < hT7.bucket_size(minLoc7)) {
			minLoc7 = i;
		}
		if (hT7.bucket_size(i) > hT7.bucket_size(maxLoc7)) {
			maxLoc7 = i;
		}
  	}
	// Then, calculate the lowest balance
	unsigned int balance7 = hT7.bucket_size(maxLoc7) - hT7.bucket_size(minLoc7);
	// insert into balance array
	balance[6] = balance7;

	//find the minimum balance
	//this is the index, not the balance value
	unsigned int minBalance = 0;
	for (unsigned int i = 0; i < 7; i++) {
		if (balance[i] < balance[minBalance])	
			minBalance = i;
	}
	//offset for index-0 base
	return minBalance+1;
}

// ALREADY COMPLETED
size_t ItemCollection::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}
