/*ver_11*/
import java.io.*;
import java.lang.*;
class average_exe{
   static void swap(int[] sm1,int[] sm2,int l,int r){
      int t=sm1[l];
      sm1[l]=sm1[r];
      sm1[r]=t;
      int t2=sm2[l]; 
      sm2[l]=sm2[r]; 
      sm2[r]=t2;
   }
   static void quicksort(int[] sm1,int[] sm2,int left, int right){
      int pl = left;
      int pr = right;
      int x = sm1[(pl+pr)/2];

      do{
         while(sm1[pl] < x) pl++;
         while(sm1[pr] > x) pr--;
         if(pl <= pr)
            swap(sm1,sm2,pl++,pr--);
      }
      while(pl<=pr);
      if(left < pr) quicksort(sm1,sm2,left, pr);
      if(pl < right) quicksort(sm1,sm2,pl, right);
   }
   static void route(int[][] route,int[] sm1,int[] sm2,int[] ns,int[] nl,int n,int k){
      int lzc=0;
      int clz=0;
      int zn=0;                        //Link 0 ko
      int [] Lz= new int [n];        //Link 0 list
/*$ java rt3 model n k*/
      int [] hs = new int [n+1];
      int [] lk = new int [k*50];
      int [] node = new int [n+1];
      int [] math = new int [n+1];
      int a=0;
      int b=0;
      int d=0;
      int e=0;
      int f=0;
      int g=0;
      int h=0;
      int m=0;
      int p=0;
      int cn=0;
      int now_n=0;
      int flag=0;
      int hop=0;
      int be=0;
      int beh=0;
      int nlc=0;
      int hopc=0;
      int con=0;
      int ls=0;
      int cl=0;
      int ll=0;
      /*count*/
      int c=0;
      int hc=0;
      int c1=0;
      int c2=0;
      int c3=0;
      int c4=0;
      int c5=0;
      int c6=0;
      int c7=0;
      int c8=0;
      int c9=0;
      int d1=0;
      c3=1;
      cn=n-1-zn;

      for(c1=1; c1<=n; c1++){           //route[][] -1 reset
         for(c2=1; c2<=n; c2++){
            route[c1][c2]=-1;
         }
      }

      for(a=1; a<=n; a++){                //kizyun a   startBC
         for(b=1; b<=n; b++){             //hs[] -1 reset
            hs[b]=-1;
         }
         c7=1;                            //reset
         node= new int [n+1];
         math= new int [n+1];
         hs[a]=0;                         //hs[] mine 0
         route[a][a]=0;                   //route[][] mine 0
         lzc=nl[a];
         if(lzc==0){                      //Link0 skip
            continue;
         }
         for(c3=0; c3<lzc; c3++){         //1hopBC
            hs[sm2[ns[a]+c3]]=1;
            route[a][sm2[ns[a]+c3]]=sm2[ns[a]+c3];
         }
         hop=1;
         flag=0;
 
         while(flag==0){                     //NoLook or 
            hop++;
            flag=1;
            for(c4=1; c4<=n; c4++){          //hs[1~n] look
               beh=hop-1;
               be=hs[c4];
               if(beh==be){                  //TargetN
                  nlc=nl[c4];
                  c5=0;
                  while(c5<nlc){
                     hopc=hs[sm2[ns[c4]+c5]];
                     if(hopc==-1){           //New N Look
                        hs[sm2[ns[c4]+c5]]=hop;
                        node[c7]=sm2[ns[c4]+c5];
                        math[c7]=hop;
                        c7++;
                        flag=0;
                     }
                     c5++;
                  }
               }
            }
         }                                   //Bc fin
         for(c8=1; c8<=n; c8++){
            ls=0;
            cl=c8;
            m=hs[cl];
            if(m<=1){
               continue;
            }
            while(hs[cl]>1){
               con=0;
               lk = new int [k*50];
               for(d1=0; d1<nl[cl]; d1++){  //link kakunou
                  if(hs[cl]>hs[sm2[ns[cl]+d1]]){
                     con++;
                     lk[con]=sm2[ns[cl]+d1];
                  }
               }
               cl=lk[(int)(Math.random()*con)+1];
            }
            route[a][c8]=cl;
         }

         //System.out.println(a+" fin");

      }
   }
   public static void main (String args[])throws IOException{
      long start,end;      start=System.currentTimeMillis();
      BufferedReader pp=new BufferedReader(new FileReader("NetModel/"+args[0]+"-"+args[1]+"k"+args[2]+".txt"));
      String s=pp.readLine();
      String[] ss;
      ss=s.split(" ");
      int n=Integer.parseInt(ss[1]);
      double nx[]=new double[n+1];
      double ny[]=new double[n+1];
      int k=Integer.parseInt(args[2]);
      int r=0;
      int l=0;
      int c=0;
      int c2=0;
      int sk=0;
      int i=0;
      sk =1000;
      for(i=1; i<=n; i++){
         s=pp.readLine();
         ss=s.split(" ");
         nx[i]=Double.valueOf(ss[2]);
         ny[i]=Double.valueOf(ss[3]);
      }
      s=pp.readLine();
      while((s=pp.readLine())!=null){
         c2++;
      }
      pp.close();
      BufferedReader br=new BufferedReader(new FileReader("NetModel/"+args[0]+"-"+args[1]+"k"+args[2]+".txt"));
      for(i=-1; i<=n; i++){
         s=br.readLine();
      }
      int [][] route = new int[n+1][n+1];
      int[] sm1=new int[c2*2+1];
      int[] sm2=new int[c2*2+1];
      int ns[]= new int[n+1];
      int nl[]= new int[n+1];
      int Hrin=0;
      while((s=br.readLine())!=null){
         ss=s.split(" ");
         r=Integer.parseInt(ss[0]);
         l=Integer.parseInt(ss[1]);
         c++;
         sm1[c]=r;
         sm2[c]=l;
         c++;
         sm2[c]=r;
         sm1[c]=l;
         nl[r]++;
         nl[l]++;
      }
      quicksort(sm1,sm2,1, sm1.length-1);
      int ic=0;
      int in=0;
      ic=1;
      for(in=1; in<=n; in++){
         ns[in]=ic;
         ic +=nl[in];
      }
/*-------------sort,index,finish-----------------*/
      route(route,sm1,sm2,ns,nl,n,k);
/*--------------route make finish----------------*/
      double pac=0;
      double pack=Double.valueOf(args[3]);         //spawn %
      int turn=0;
      pac=pack*n;
      int max=0;
      turn=10000;
      max=(int)(pac*turn);
      int map[][]=new int[n+1][(int)(pac)*turn/n*2];
      int spon[]=new int[max+2];
      int tage[]=new int[max+2];
      int sc[]=new int[max+2];
      int nex[]=new int[max+2];
      int sai[]=new int[max+1];
      int sac[]=new int[max+1];
      int buf[]=new int[n+1];
      int can[]=new int[n+1];
      int Tn[]=new int[n+1];
      //int dbuf[]=new int[n+1];
      int keep[]=new int[6];
      int get[]=new int[6];
      int tc=0;
      int e1=0;
      int e2=0;
      int e3=0;      //pac num
      int e4=0;
      int e5=0;
      int e6=0;
      int e7=0;
      int e8=0;
      int e9=0;
      int f1=0;
      int f2=0;
      int f3=0;      //pac num
      int f4=0;
      int f5=0;
      int f6=0;
      int f7=0;
      int f8=0;
      int f9=0;
      int g1=0;
      int g2=0;
      int g3=0;      //pac num
      int g4=0;
      int g5=0;
      int h1=0;
      int h2=0;
      int h3=0;      //pac num
      int h4=0;
      int h5=0;
      int h6=0;
      int i1=0;
      int i2=0;
      int i3=0;      //pac num
      int i4=0;
      int i5=0;
      int i6=0;
      int i7=0;
      int i8=0;
      int i9=0;
      int k1=0;
      int k2=0;
      int k3=0;      //pac num
      int k4=0;
      int k5=0;
      int k6=0;
      int k7=0;
      int k8=0;
      int k9=0;
      int k10=0;
      int k11=0;
      int m1=0;
      int m2=0;
      int m3=0;      //pac num
      int m4=0;
      int m5=0;
      int m6=0;
      int m7=0;
      int m8=0;
      int m9=0;
      int o1=0;
      double o2=0;
      int o3=0;      //pac num
      int o4=0;
      int o5=0;
      int o6=0;
      int o7=0;
      int o8=0;
      int o9=0;
      int po=0;      //pack num
      int sp=0;      //saiP
      int hp=0;      //sacP
      int kp=0;      //keep Num
      int ca=0;
      double pkr=0;
      pkr=pack;
      int saka=0;
      int maki=0;
      int you=0; 
      double A=0.0;            //Ttatu
      double L=0.0;            //Haki
      double R=0.0;        //%
      int flag=0;
      double rt2=k/(Math.PI*n);
      double difx=0.0;
      double dify=0.0;
      double l2=1/2.0;

      int ek=k+2;              //ex % !!!!!!!!!!!!
      double kk=1.8;
      double rt3=Math.sqrt(rt2)*kk;
      rt3=rt3*rt3;
      double ex=1.02;
      double rt[]=new double[n+1];
      double et[]=new double[n+1];
      int exe[]=new int[n+1];
      double Bave[]=new double[n+1];
      int fl=0;
      int t=0;
      int exturn=0,ext=0,inv=0;
      inv=50;
      i=0;
      c=0;
      for(e1=1; e1<=n; e1++){
         rt[e1]=rt2;
      }
      BufferedWriter bw=new BufferedWriter(new FileWriter("result/average_exe"+kk+"Inv"+inv+","+n+"k"+args[2]+".txt",true));

      for(e1=1; e1<=turn; e1++){            //start
         System.out.print("turn:"+e1);
         g2=0;
         sac=new int[max];
         hp=0;
         for(g2=1; g2<=pac; g2++){                       //spawn
            g4=0;
            while(g4<1){
               g1=(int)(Math.random()*n)+1;    //spawn
               g3=(int)(Math.random()*n)+1;    //tage
               g4=route[g1][g3];
            }
            g5=buf[g1];
            po++;
            if(g5<5){
               buf[g1]++;
               map[g1][buf[g1]]=po;
            }else{
               sac[hp]=po;
               nex[po]=g1;
               sc[po]++;
               hp++;
            }
            spon[po]=g1;
            tage[po]=g3;
         }                                      //fin
         can=new int[n+1];
         e2=0;
         while(sai[e2]!=0){                   //sai set
            e3=sai[e2];
            map[nex[e3]][6+can[nex[e3]]]=e3;
            can[nex[e3]]++;
            e2++;
         }
         sai=new int[max];
         sp=0;
         for(e4=1; e4<=n; e4++){              //Trans
            e5=buf[e4];
            m1=e5;
            if(e5>2){
               e5=2;
               for(e6=1; e6<=e5; e6++){
                  e7=map[e4][e6];                //e7=packNum
                  e8=route[e4][tage[e7]];         //e8=nextN
                  map[e8][6+can[e8]]=e7;
                  can[e8]++;
                  map[e4][e6]=0;
                  buf[e4]--;
               }
               for(m2=3; m2<=m1; m2++){
                  map[e4][m2-2]=map[e4][m2];
                  map[e4][m2]=0;
               }
            }else{
               for(e6=1; e6<=e5; e6++){
                  e7=map[e4][e6];                //e7=packNum
                  e8=route[e4][tage[e7]];         //e8=nextN
                  map[e8][6+can[e8]]=e7;
                  can[e8]++;
                  map[e4][e6]=0;
                  buf[e4]--;
               }
            } 
         }
 //test//
 //test fin//
         Tn=new int[n+1];
         tc=0;
         kp=0;
         sp=0;
         for(f1=1; f1<=n; f1++){              //GetP
            f2=can[f1];
            if(f2==0){
               continue;
            }
            f3=5-buf[f1];
            e9=5-buf[f1];
            f4=can[f1];
            keep=new int[15];
            kp=0;
            get=new int[6];
            ca=0;
            if(f3>f4){                        //came min
               tc++;
               Tn[tc]=f1;
               while(f4>ca){
                  f5=6+(int)(Math.random()*f2);
                  f6=map[f1][f5];
                  flag=0;
                  for(f7=1; f7<=ca; f7++){
                     f8=keep[f7];
                     if(f8==f5){
                        flag=1;
                     }
                  }
                  if(flag==0){
                     ca++;
                     get[ca]=f6;
                     keep[ca]=f5;
                     map[f1][f5]=-2;
                  }
               }
            }else{                            //buf min
               while(f3>ca){
                  f5=6+(int)(Math.random()*f2);
                  f6=map[f1][f5];
                  flag=0;
                  for(f7=1; f7<=kp; f7++){
                     f8=keep[f7];
                     if(f8==f5){
                        flag=1;
                     }
                  }
                  if(flag==0){
                     kp++;
                     keep[kp]=f5;
                     f9=tage[f6];
                     can[f1]--;
                     map[f1][f5]=-1;
                     if(f9!=f1){
                        ca++;
                        get[ca]=f6;
                     }else{                   //Ttatu
                        A++;
                     }
                  }
                  f4=can[f1];
                  if(f3>f4){
                     f3=f4;
                  }
               }
            }
            for(i1=1; i1<=ca; i1++){          //get
               buf[f1]++;
               i3=buf[f1];
               map[f1][i3]=get[i1];
            }
            h1=0;
            h2=map[f1][6+h1];
            while(h2!=0){                     //sai youQ
               if(h2>0){
                  sac[hp]=h2;
                  sp++;
                  hp++;
                  sc[h2]++;
                  nex[h2]=spon[h2];
               }
               map[f1][6+h1]=0;
               h1++;
               h2=map[f1][6+h1];
            }
         }                                   //move fin
         for(i3=1; i3<=tc; i3++){             //T.tatu
            i4=Tn[i3];
            i5=buf[i4];
            i6=1;
            while(i6<=i5){
               i7=map[i4][i6];
               i8=tage[i7];
               if(i4==i8){
                  A++;
                  i9=i6;
                  map[i4][i6]=0;
                  buf[i4]--;
                  while(i9<=i5){
                     map[i4][i9]=map[i4][i9+1];
                     map[i4][i9+1]=0;
                     i9++;
                  }
                  i5=buf[i4];
                  i6--;
               }
               i6++;
            }
         }
/*-----------------my curry out-----------------*/
         exturn++;
         ext=exturn/inv;
         for(o8=1; o8<=n; o8++){
            Bave[o8]+=Bave[o8];
         }
         for(o6=1; o6<=ext; o6++){
            exturn=exturn-inv;
            for(o9=1; o9<=n; o9++){          //Average Math
               et[o9]=Bave[o9]/e1;
            }
            fl=0;
            for(o1=1; o1<=n; o1++){          //Buf chk
               o2=et[o1];
               if(o2>=4){
                  fl=1;
                  o3=nl[o1];
                  for(o4=0; o4<o3; o4++){
                     o5=sm2[ns[o1]+o4];
                     rt[o5]=rt3;      //rt ex
                     exe[o5]=1;
                  }
               }
            }
            for(o7=1; o7<=fl; o7++){
               c2=0;
               sm1=new int[(n*ek+1)*15];
               sm2=new int[(n*ek+1)*15];
               ns=new int[n+1];
               nl=new int[n+1];
               for(i=1; i<=n; i++){      //Hanni hantei
                  for(t=i+1; t<=n; t++){
                     difx=0;
                     dify=0;
                     if(Math.abs(nx[i]-nx[t])>=l2){
                        difx=Math.abs(Math.abs(nx[i]-nx[t])-1);
                     }else{
                        difx=Math.abs(nx[i]-nx[t]);
                     }
                     if(Math.abs(ny[i]-ny[t])>l2){
                        dify=Math.abs(Math.abs(ny[i]-ny[t])-1);
                     }else{
                        dify=Math.abs(ny[i]-ny[t]);
                     }
                     if(rt[i]>=difx*difx+dify*dify){
                        c2++;
                        sm1[c2]=i;
                        sm2[c2]=t;
                        c2++;
                        sm1[c2]=t;
                        sm2[c2]=i;
                        nl[i]++;
                        nl[t]++;
                     }
                  }
               }
               quicksort(sm1,sm2,1,c2);
               ic=1;
               for(in=1; in<=n; in++){
                  ns[in]=ic;
                  ic +=nl[in];
               }
               route(route,sm1,sm2,ns,nl,n,ek);
            }
            et=new double[n+1];
         }
/*-------------------finish-----------------*/
         k1=hp-sp;
         k2=hp;
         k3=sp;
         hp=0;
         sp=0;
         for(k8=0; k8<k1; k8++){
            k9=sac[k8];
            sai[sp]=k9;
            sp++;
         }
         for(k5=k1; k5<k2; k5++){         //Haki
            k6=sac[k5];
            k7=sc[k6];
            if(k7<6){
               sai[sp]=k6;
               sp++;
            }else{
               tage[k6]=-1;
               L++;
            }
         }
         System.out.print("\r");
      }
      System.out.println();
      //System.out.println(A);
      //System.out.println(L);
      R=A+L;
      R=A/R;
      /*for(m1=1; m1<=n; m1++){
         if(exe[m1]==1){
            System.out.print(m1+" ");
         }
      }*/
      
      System.out.println("R= "+R);
      bw.write(pkr+" "+R+"\n");
      br.close();
      bw.close();
      end=System.currentTimeMillis();
      System.out.println(end-start+"mili");
      //long aho = (end-start)/1000;
      //System.out.println(aho+"腱");
   }
}
