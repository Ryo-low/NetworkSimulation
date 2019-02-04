import java.io.*;
import java.lang.*;
class RGN{
   public static void main (String args[])throws IOException{
      BufferedWriter bw=new BufferedWriter(new FileWriter("rgns-"+args[0]+"k"+args[1]+".txt"));
      long start,end;   start=System.currentTimeMillis();
      int n=Integer.parseInt(args[0]);
      int k=Integer.parseInt(args[1]);
      int l=1;
      double rt2=k*(l*l)/(Math.PI*n);
      double nx[]=new double[(n+1)*5];
      double ny[]=new double[(n+1)*5];
      double difx=0;
      double dify=0;
      double l2=l/2.0;
      int s1[]=new int[n*k];
      int s2[]=new int[n*k];
      int ss1[]=new int[n*k*4];
      int ss2[]=new int[n*k*4];
      int c=0;

      for(int i=1; i<=n; i++){   //no-do iti
         nx[i]=Math.random()*l;
         ny[i]=Math.random()*l;
      }

      bw.write("*Vertices "+n+"\n");      //kaki
      for(int i=1; i<=n; i++){
         bw.write(i+" \""+i+"\" "+nx[i]+" "+ny[i]+"\n");
      }
      bw.write("*Edges\n");

      for(int s=1; s<=n; s++){      //Hani hantei
         for(int t=1; t<=n; t++){
            difx=0;
            dify=0;
            if(s<t){
               if(Math.abs(nx[s]-nx[t])>=l2){
                  difx=Math.abs(Math.abs(nx[s]-nx[t])-l);
               }else{
                  difx=Math.abs(nx[s]-nx[t]);
               }
               if(Math.abs(ny[s]-ny[t])>l2){
                  dify=Math.abs(Math.abs(ny[s]-ny[t])-l);
               }else{
                  dify=Math.abs(ny[s]-ny[t]);
               }
               if(rt2>=difx*difx+dify*dify){
                  c++;
                  s1[c]=s;
                  s2[c]=t;
               }
            }
         }
      }

      for(int ks=1; s1[ks]!=0; ks++){         //Link kaki
         bw.write(s1[ks]+" "+s2[ks]+" 1\n");
      }
      bw.close();
      BufferedWriter bw2=new BufferedWriter(new FileWriter("rgn-"+args[0]+"k"+args[1]+".txt"));
      int c2=n;
      double nxc=0;
      double nyc=0;

      for(int m=1; m<=n; m++){             //Hukusei
         if(nx[m]<=0.5 && ny[m]<=0.5){
            c2++;
            nyc=ny[m]+1;
            nx[c2]=nx[m];
            ny[c2]=nyc;

            c2++;
            nxc=nx[m]+1;
            nx[c2]=nxc;
            ny[c2]=nyc;

            c2++;
            nx[c2]=nxc;
            ny[c2]=ny[m];
         }
         if(nx[m]>=0.5 && ny[m]<=0.5){
            c2++;
            nxc=nx[m]-1;
            nx[c2]=nxc;
            ny[c2]=ny[m];

            c2++;
            nyc=ny[m]+1;
            nx[c2]=nxc;
            ny[c2]=nyc;

            c2++;
            nx[c2]=nx[m];
            ny[c2]=nyc;
         }
         if(nx[m]<=0.5 && ny[m]>=0.5){
            c2++;
            nxc=nx[m]+1;
            nx[c2]=nxc;
            ny[c2]=ny[m];

            c2++;
            nyc=ny[m]-1;
            nx[c2]=nxc;
            ny[c2]=nyc;

            c2++;
            nx[c2]=nx[m];
            ny[c2]=nyc;
         }
         if(nx[m]>=0.5 && ny[m]>=0.5){
            c2++;
            nyc=ny[m]-1;
            nx[c2]=nx[m];
            ny[c2]=nyc;

            c2++;
            nxc=nx[m]-1;
            nx[c2]=nxc;
            ny[c2]=nyc;

            c2++;
            nx[c2]=nxc;
            ny[c2]=ny[m];
         }
      }

      c=0;
      for(int sm=1; nx[sm]!=0; sm++){         //Link chk
         for(int tm=1; ny[tm]!=0; tm++){
            difx=0;
            dify=0;
            if(sm<tm){
               difx=Math.abs(nx[sm]-nx[tm]);
               dify=Math.abs(ny[sm]-ny[tm]);
               if(rt2>=difx*difx+dify*dify){
                  c++;
                  ss1[c]=sm;
                  ss2[c]=tm;
               }
            }
         }
      }
      
      bw2.write("*Vertices "+c2+"\n");      
      for(int i=1; i<=c2; i++){
         bw2.write(i+" \""+i+"\" "+nx[i]+" "+ny[i]+"\n");
      }
      bw2.write("*Edges\n");
      for(int km=1; ss1[km]!=0; km++){         //Mise kaki
         bw2.write(ss1[km]+" "+ss2[km]+" 1\n");
      }
      end=System.currentTimeMillis();
      System.out.println((end-start)+"millis");
      bw2.close();
   }
}

