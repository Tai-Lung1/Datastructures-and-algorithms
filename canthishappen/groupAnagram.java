package canthishappen;
import java.util.*;

public class groupAnagram {
    List<List<String>> dynamicArray = new ArrayList<>();
    int k=0;
    public boolean isAnagram(String s, String t) {
        char[] sArray = s.toCharArray();
        char[] tArray = t.toCharArray();
        Arrays.sort(sArray);
        Arrays.sort(tArray);
        if(Arrays.equals(sArray, tArray)){
            return true;
        }
        return false;
    }
    public boolean checkGrpAnagram(String tocheckstr){
        for (List<String> row : dynamicArray) {
            if(isAnagram(dynamicArray.get(k).get(0),tocheckstr)){
                dynamicArray.get(k).add(tocheckstr);
                return true;
            }
            else{
                k++;
            }
        }
        List<String> row = new ArrayList<>();
        row.add(tocheckstr);
        return true;
    }
    public List<List<String>> groupAnagrams(String[] strs) {
        for(int i=0;i<strs.length;i++)
        {
            checkGrpAnagram(strs[i]);
        }
        return dynamicArray;
    }
}