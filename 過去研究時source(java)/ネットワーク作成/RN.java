import java.io.*;
import java.lang.*;
class RN{
  public static int n;
  public static int k;
  public static int i;
  public static int j;
  public static int z;
  public static int a;
  public static int b;
  public static int L;
  public static int tmp;
  public static int rN1;
  public static int rN2;
  public static int[][] s;
  public static int count=0;
  public static int Rcount=0;
  public static int recount=0;
  public static long start,end;
  public static String name;

 public static void main(String args[])throws Exception{
  start = System.currentTimeMillis(); 
  n = Integer.parseInt(args[0]);
  k = Integer.parseInt(args[1]);
  BufferedWriter w = new BufferedWriter(new FileWriter("RN-"+n+"k"+k+".txt"));
  L = n*k/2; //全体リンク  
    s = new int[n+1][k*3]; 
  for(i=0; i < L; i++){
    random();
    for(z=1;z < s[rN1].length; z++){
     if(s[rN1][z] == 0){
      s[rN1][z] = rN2;
      break;
     } 
    } 
  } 

  w.write("*Vertices "+n+"\n"); //ノード数の書き込み 
  for(i = 1; i<=n; i++){
   w.write(i + " \"NODE_" + i + "\"" + " ic Red" + "\n");
  }

  w.write("*Edges"+"\n"); 
  for(i = 1; i<s.length; i++){
   j = 1;
  for(j = 1; j<s[i].length; j++){
    if(s[i][j] == 0){break;}
     w.write(i+" "+s[i][j]+" 1\n");
   }
  }

  w.close();

  end = System.currentTimeMillis(); 
  System.out.println((end - start)+"millisec");
 }

 public static void random(){
    rN1 = 0;
    rN2 = 0;
   while(rN1==rN2){
    rN1 = (int)((Math.random())*n+1);
    rN2 = (int)((Math.random())*n+1);
   }
   if(rN1>rN2){
    tmp = rN1;
    rN1 = rN2;
    rN2 = tmp; 
   }
   for(j=1; j<s[rN1].length;j++){
    if(rN2==s[rN1][j]){
     random(); 
    }
   }
 }
}
