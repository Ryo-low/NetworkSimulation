import java.io.*;
import java.lang.*;
class BA{
   public static void main (String args[])throws IOException{
      BufferedWriter bw=new BufferedWriter(new FileWriter("BA-"+args[0]+"k"+args[1]+".txt"));
      long start,end;      start=System.currentTimeMillis();
      int n=Integer.parseInt(args[0]);                     //ノード数
      int m=Integer.parseInt(args[1])/2;                      //投擲回数
      int list[]=new int[n*m+1-6]; //清野上
      int lis[]=new int[n*m+1-6];   //清野下
      int link[]=new int[n*m*2+1];    //川手
      int d[]=new int[m+1];         //選択ノード格納
      int s=0;              //清野カウント
      int c=0;              //川手カウント
      int t=1;
      int flag=0;
      int o=0;
      int i=0;
      int g=0;
      for(i=1; i<4; i++){       //４ノードの完全グラフ
         for(g=1; g<=4; g++){
            if(i!=g && i<g){
              s++;
              c++;
              link[c]=i;
              c++;
              link[c]=g;
              list[s]=i;
              lis[s]=g;
           }
        }
      }
      //System.out.println(s);
      //System.out.println(c);
      int j=0;
      int k=0;
      for(i=5; i<=n; i++){             //ノード数分回す
         for(j=1; j<=m; j++){          //ダーツをm回投げるで
            o=(int)(Math.random()*c+1);  //とりま部屋番号をoに
            t=1;
            flag=0;
            while(t<d.length){             //川手配列見てくか
              if(link[o]==link[d[t]]){       //o番目入ってないか？
                 j--;                     //被ってたらﾀｲﾑﾘｰﾌﾟ
                 flag=1;                  //被ってたらﾌﾗｸﾞ立て
                 break;                   //while抜け
              }
              t++;
            }
            if(flag==0){                  //ﾌﾗｸﾞ立ってなかったら
              d[j]=o;                    //oをj番目に入れるやで           
           }
        }
        for(k=1; k<=m; k++){
           c++;
           link[c]=i;
           c++;
           link[c]=link[d[k]];
           s++;
           list[s]=i;
           lis[s]=link[d[k]];
        }
     }
     bw.write("*Vertices "+n+"\n");      //書き込み
     for(i=1; i<=n; i++){
         bw.write(i+" "+"\""+i+"\""+" ic Red\n");
     }
     bw.write("*Edges\n");

     for(i=1; i<list.length; i++){
        bw.write(list[i]+" "+lis[i]+" 1\n");    
     }
     end=System.currentTimeMillis();
     System.out.println((end-start)+"millis");
     bw.close();
   }
}
