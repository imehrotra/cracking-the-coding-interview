int permutation(char* c, char* b) {
	int alen = strlen(a);
	int blen = strlen(b);

	if (alen!=blen) {
		return 1;
	}

	for (int i=0; i<alen; i++) {
		key = a[i];
		arr[key]++; //val
	}

	for (int j=0; j<blen; j++) {
		key = b[j];
		if(arr[key]==0) {
			return 1;
		}
		arr[key]--;
	}
	return 0;
}