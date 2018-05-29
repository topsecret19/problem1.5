public class MyClass {
    public static void main(String args[]) {
        String word1 = "Marwan";
        String word2= "Marwa";
        System.out.println(isOneAway(word1,word2));
    }
    public static boolean isOneAway(String str1, String str2){
        if(str1.length()>str2.length()+1 || str1.length()+1 < str2.length()){
            return false;
        }
        char[] content1= str1.toCharArray();
        char[] content2= str2.toCharArray();
        int n;
        int count=0;
        if(content1.length>content2.length){
            n= content2.length;
            count++;
        }else if(content1.length<content2.length){
            n= content1.length;
            count++;
        }else{
            n= content1.length;
        }
        for(int i=0; i<n; i++){
            if(content1[i]!=content2[i]){
                count++;
            }
        }
        return count <= 1;
    }
}