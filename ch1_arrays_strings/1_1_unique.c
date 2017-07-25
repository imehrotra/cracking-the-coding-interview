int unique_hash(char* string) {
	int len = strlen(string);
	char arr[128];
	memset(arr, 128, 0);
	for(int i=0; i<len; i++) {
		char c = string[i];
		char key = c;
		int index = hash(key)%len; //TODO hash func
		if (search_insert(arr, index, c)) { //ret 1 indicates false
			return 1; //false indication
		}
	}
	return 0;
}

int search_insert(char* arr, int index, char c) {
	char curr = arr[index];
	while(curr->next != NULL) { // !=NULL for clarity
		if (curr==c) {
			return 1;
		}
		curr = curr->next;
	}
	if (curr==c) {
		return 1;
	}
	return 0;
}