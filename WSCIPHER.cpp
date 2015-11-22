//W's Cipher by Drew Saltarelli
//String Manipulation Approach
//O(n log n)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main ()
{

    const int MAXCHAR = 80;
    int k1, k2, k3;
    int s1[MAXCHAR], s2[MAXCHAR], s3[MAXCHAR];
    unsigned s1size, s2size, s3size;
    bool generate = false;

    while ((cin >> k1 >> k2 >> k3) && (k1 + k2 + k3 != 0)) {
	unsigned i;
	string instring;
	int target;

	cin.ignore (80, '\n');
	cin >> instring;     // ok, no spaces
	if (generate)
	    reverse (instring.begin (), instring.end ());
	string outstring (instring);

	s1size = s2size = s3size = 0;

	for (i = 0; i < instring.size (); i++) {
	    if (instring[i] >= 'a' && instring[i] <= 'i')
		s1[s1size++] = i;
	    else if (instring[i] >= 'j' && instring[i] <= 'r')
		s2[s2size++] = i;
	    else
		s3[s3size++] = i;
	}

	for (i = 0; i < s1size; i++) {
	    target = s1[(i + k1) % s1size];
	    outstring[target] = instring[s1[i]];
	}


	for (i = 0; i < s2size; i++) {
	    target = s2[(i + k2) % s2size];
	    outstring[target] = instring[s2[i]];
	}
	

	for (i = 0; i < s3size; i++) {
	    target = s3[(i + k3) % s3size];
	    outstring[target] = instring[s3[i]];
	}
	

	if (generate) {
	    cout << k1 << " " << k2 << " " << k3 << endl;
	    reverse (outstring.begin (), outstring.end ());
	}

	

	cout << outstring << endl;

    }
    return 0;
}
