public class OneAway{
	public static void main(String[]args){
		System.out.println("Input String 1: ");
		String a = IO.readString();
		System.out.println("Input String 2: ");
		String b = IO.readString();
		boolean check = OneEdit(a,b);
		System.out.println(check);
	}
	public static boolean OneEdit(String a, String b){
		if(a.equals(b)){
			return true;
		}else if(a.length() == b.length()){
			return replaceCheck(a, b);
		}
		else{
			return removeOrInsert(a, b);
		}
	}
	public static boolean replaceCheck(String a, String b){
		int flag = 0;
		for(int i = 0; i<a.length();i++){
			if(flag>1){
				return false;
			}if(a.charAt(i)!=b.charAt(i)){
				flag++;
			}
		}
		return true;
	}
	public static boolean removeOrInsert(String a, String b){
		if(Math.abs(a.length() - b.length()) >1){
			return false;
		}
		int small_i = 0;
		char a_long = 'n';
		char b_long = 'n';
		if(a.length()>b.length()){
			small_i = b.length();
			a_long = 'y';
		}else{
			small_i = a.length();
			b_long = 'y';
		}	
		int a_i = 0;
		int b_i = 0;
		int diff_count= 0;
		while(a_i<small_i&&b_i<small_i){
			if(diff_count>1){
				return false;
			}
			if(a.charAt(a_i)==b.charAt(b_i)){
				a_i++;
				b_i++;
				continue;
			}else{
				diff_count++;
				if(a_long == 'y'){
					if(a.charAt(a_i+1)==b.charAt(b_i)){
						a_i+=2;
						b_i++;
					}else{
						return false;
					}
				}else{
					if(b.charAt(b_i+1)==a.charAt(a_i)){
						b_i+=2;
						a_i++;
					}else{
						return false;
					}
				}
			}
		}
		return true;
	}
}