def str_edit(a, b):
	alen = len(a)
	blen = len(b)

	if(alen == blen):
		return check_replace(a, b, alen)
	elif (abs(alen-blen== 1)):
		return check_ins_rem(a,b,alen,blen)
	else:
		return False;

def check_replace(a, b, slen):
	if(a == b): #not needed
		return True

	diff_cnt = 0
	for i,j in zip(a, b):
		if(i!=j):
			diff_cnt += 1
		if (diff_cnt > 1):
			break

	return (diff_cnt <= 1)

#TODO comments
def check_ins_rem(a, b, alen, blen):
	if (alen > blen):
		a_long = 1
	
	j = 0
	k = 0
	diff_cnt = 0

	while (j < alen and k < blen):
		if(a[j] != b[k]):
			diff_cnt+=1
			if (a_long):
				j+=1
			else:
				k+=1
		else:
			j+=1
			k+=1

		if (diff_cnt > 1):
			return False

	return True

if __name__ == "__main__":
	print "T: " + str(str_edit("pale","ple"))
	print "T: " + str(str_edit("pales","pale"))
	print "T: " + str(str_edit("pale","bale"))
	print "F: " + str(str_edit("pale","bake"))