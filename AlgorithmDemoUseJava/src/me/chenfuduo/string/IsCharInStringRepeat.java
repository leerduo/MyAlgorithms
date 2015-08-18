package me.chenfuduo.string;


/**
 * 确定一个字符串中的所有字符是否全部不同
 * @author Administrator
 *
 */

public class IsCharInStringRepeat {
	public static void main(String[] args) {
		String str1 = "abcdefg";
		String str2 = "abccdefg";
		boolean b1 = isUniqueChars(str1);
		boolean b2 = isUniqueChars(str2);
		System.out.println("b1:" + b1);
		System.out.println("b2:" + b2);
	}
	
	public static boolean isUniqueChars(String str){  
		if (str.length() > 256) {
			return false;
		}
		boolean[] char_set = new boolean[256];
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			if (char_set[c]) {
				return false;
			}
			char_set[c] = true;
		}
		return true;
	}
	

}
