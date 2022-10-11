class Solution {
    public static int romanToInt(String s) {

        Map<Character,Integer> mapping = new HashMap<>();
        mapping.put('I',1);
        mapping.put('V',5);
        mapping.put('X',10);
        mapping.put('L',50);
        mapping.put('C',100);
        mapping.put('D',500);
        mapping.put('M',1000);
        
        //Add last character value
        int num=mapping.get(s.charAt(s.length() -1));
        
        for(int i = s.length()-2;i>=0;i--){
            
            //if value of ith character is smaller than i+1th character ,subtract e.g IX
        if(mapping.get(s.charAt(i)) < mapping.get(s.charAt(i+1))){
            
            num=num-mapping.get(s.charAt(i));
        }
            else {
                num=num + mapping.get(s.charAt(i));
            }
        }
        
        return num;
    }
}
