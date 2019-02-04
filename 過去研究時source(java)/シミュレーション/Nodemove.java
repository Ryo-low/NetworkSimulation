import java.io.*;
import java.lang.*;
class Nodemove{
   public static void main (String args[])throws IOException{
      BufferedReader pp=new BufferedReader(new FileReader(args[0]+"-"+args[1]+"k"+args[2]+".txt"));
      BufferedWriter bw;
      BufferedWriter bw2;
      long start,end;   start=System.currentTimeMillis();
      int n=Integer.parseInt(args[1]);
      int k=Integer.parseInt(args[2]);
      int l=1;
      double rt2=k*(l*l)/(Math.PI*n);
      double nx[]=new double[(n+1)*4];
      double ny[]=new double[(n+1)*4];
      double mv[]=new double[n+1];
      double xmv[]=new double[(n+1)*4];
      double ymv[]=new double[(n+1)*4];
      double difx=0;
      double dify=0;
      double l2=l/2.0;
      double u=0.0;
      double mx=0.0;
      double nxc=0;
      double nyc=0;
      int s1[]=new int[n*k*4];
      int s2[]=new int[n*k*4];
      int ss1[]=new int[n*k*10];
      int ss2[]=new int[n*k*10];
      int dec[]=new int[2];
      int i=0;
      int c=0;
      int t=0;
      int tr=0;
      int c2=n;
      int test=0;
      int c1=0;
      dec[0]=-1;
      dec[1]=1;
      double cx=0;
      double cy=0;
      double c5=0;
      double c6=0;
      double c7=0;
      double c8=0;
      double angle=0.0;

      String d=pp.readLine();
      String[] dd=new String[4];
      for(t=1; t<=n; t++){                       //NodeMap read
         d=pp.readLine();
         dd=d.split(" ");
         nx[t]=Double.parseDouble(dd[2]);
         ny[t]=Double.parseDouble(dd[3]);
      }
      for(t=1; t<=n; t++){                     //mobility set
         u=Math.random();
         mv[t]=Math.pow(u,1/(1-4))-1;
      }
      for(t=1; t<=n; t++){
         System.out.println(" mv"+mv[t]);
      }
      for(tr=1; tr<=10; tr++){
         bw=new BufferedWriter(new FileWriter("moveres/rgns-"+args[1]+"k"+args[2]+"_"+tr+".txt"));
         bw2=new BufferedWriter(new FileWriter("moveres/rgn-"+args[1]+"k"+args[2]+"_"+tr+".txt"));
         c=0;
         c2=0;
         for(t=1; t<=n; t++){                 //Node move
            mx=Math.random()*Math.PI;
            ny[t]+=Math.sin(mx);
            nx[t]+=Math.cos(mx);
            if(nx[t]>=1){
               cx=Math.floor(nx[t]);
               nx[t]=nx[t]-cx;
            }
            if(nx[t]<0){
               c5=Math.abs(Math.floor(nx[t]));
               c6=nx[t]+c5;
               nx[t]=c6;
            }
            if(ny[t]>=1){
               ny[t]=ny[t]-(int)(ny[t]);
            }
            if(ny[t]<0){
               c7=Math.abs(Math.floor(ny[t]));
               c8=ny[t]+c7;
               ny[t]=c6;
            }
            //System.out.println(t+":"+mv[t]+":"+mx+" "+nx[t]+" : "+ny[t]);
         }
         /*for(int hosi=1; hosi<=n; hosi++){
            System.out.println(" :"+nx[hosi]);
         }*/
         bw.write("*Vertices "+n+"\n");      //kaki
         for(i=1; i<=n; i++){
            bw.write(i+" \""+i+"\" "+nx[i]+" "+ny[i]+"\n");
         }
         bw.write("*Edges\n");
         for(int s=1; s<=n; s++){      //Hani hantei
            for(c1=1; c1<=n; c1++){
               difx=0;
               dify=0;
               if(s<c1){
                  if(Math.abs(nx[s]-nx[c1])>=l2){
                     difx=Math.abs(Math.abs(nx[s]-nx[c1])-l);
                  }else{
                     difx=Math.abs(nx[s]-nx[c1]);
                  }
                  if(Math.abs(ny[s]-ny[c1])>l2){
                     dify=Math.abs(Math.abs(ny[s]-ny[c1])-l);
                  }else{
                     dify=Math.abs(ny[s]-ny[c1]);
                  }
                  if(rt2>=difx*difx+dify*dify){
                     c++;
                     s1[c]=s;
                     s2[c]=c1;
                  }
               }
            }
         }

         for(int ks=1; s1[ks]!=0; ks++){         //Link kaki
            bw.write(s1[ks]+" "+s2[ks]+" 1\n");
         }
/*         for(int m=1; m<=n; m++){             //Hukusei
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
*/      
         bw2.write("*Vertices "+c2+"\n");      
         for(i=1; i<=c2; i++){
            bw2.write(i+" \""+i+"\" "+nx[i]+" "+ny[i]+"\n");
         }
         bw2.write("*Edges\n");
         for(int km=1; ss1[km]!=0; km++){         //Mise kaki
            bw2.write(ss1[km]+" "+ss2[km]+" 1\n");
         }
         bw.close();
         bw2.close();
      }
      end=System.currentTimeMillis();
      System.out.println((end-start)+"millis");
      pp.close();
      
   }
}

