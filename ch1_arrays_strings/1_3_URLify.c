int URLify(char* s) {
	int len = strlen(s);
	//get index of last char
	int last_i; //reading index

	for(last_i = len-1; s[i]==' '; last_i--); //should make it while loop
	int index; //placing index
	for (index=len-1; index >= 0; index--) {
		if(s[last_i]==' ') {
			insert_space(s, index); //TODO
			index -= 2;
		} else {
			s[index] = s[last_i];
		}
		last_i--;
	}
	return 0;
}

int insert_space(char* s, int index) {
	s[i]='0';
	s[i-1]='2';
	s[i-2]='%';
	return 0;
}