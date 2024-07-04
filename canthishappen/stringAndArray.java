package canthishappen;

import java.util.Arrays;

public class stringAndArray {
    public static boolean isAnagram(String s, String t) {
        char[] sArray = s.toCharArray();
        char[] tArray = t.toCharArray();
        Arrays.sort(sArray);
        Arrays.sort(tArray);
        if(Arrays.equals(sArray, tArray)){
            return true;
        }
        return false;
    }
    public static void main(String args[]){
        boolean x = isAnagram("anagram", "nagaram");
        System.out.println(x);
    }
}
