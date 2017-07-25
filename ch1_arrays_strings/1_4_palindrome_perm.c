#include <bool.h>

bool palindrome_perm(char* s) {
	int len = strlen(s);
	bool odd = len%2;
	char arr[128];
	for (int i=0; i<len; i++;) {
		char key = s[i];
		arr[key]++;
	}
	int num_even = 0;
	int num_odd = 0;
	for(int j=0; j<128; j++) {
		if(arr[j]%2) {
			num_odd++;
		} else {
			num_even++;
		}
	}
	if ((odd && num_odd==1) || ((odd==0) && num_odd==0)) {
		return true;
	}
	return false;
}