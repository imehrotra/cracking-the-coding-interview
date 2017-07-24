#include <bool.h>
#include <math.h>
#include <string.h>

bool str_edit(char* a, char* b) {
	int alen = strlen(a);
	int blen = strlen(b);

	if(alen==blen) {
		return check_replace(a, b, alen);
	} else if (math.abs(alen-blen)==1){
		return check_ins_rem(a,b,alen,blen);
	} else {
		return false;
	}
}

bool check_replace(char* a, char* b, int len) {
	if(strcmp(a,b,len)==0) { //not needed
		return true;
	}
	int diff_cnt = 0;
	for(int i=0; i<len; i++) {
		if(a[i]!=b[i]) {
			diff_cnt++;
		} //add check
	}
	return (diff_cnt<=1);
}

//remember to change loop condition 
//TODO comment
// use char?
// questions about c?
//check styling conventions
bool check_ins_rem(char* a, char* b, int alen, int blen) {
	int small, a_long, b_long = 0;
	if (alen < blen) { //change to abs?
		small = alen;
		b_long = 1; // not strictly needed
	} else {
		small = blen;
		a_long = 1;
	}
	if(strncmp(a, b, small)==0) { //not needed
		return true;
	} //check strncmp
	int i, j, k, diff_cnt = 0; //check syntax
	while (i < small) {
		if(a[j]!=b[k]) {
			diff_cnt++;
			if (a_long) {
				j++;
			} else {
				k++;
			}
		} else {
			j++;
			k++;
		}
		if (diff_cnt>1) {
			return false;
		}
	}
	return true;
}