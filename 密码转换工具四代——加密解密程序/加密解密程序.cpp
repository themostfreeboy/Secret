/*
加密解密原理：
采用迭代加密法，先产生一5~9之间的任意整数随机数，为迭代加密次数n，每次加密方式相同；
每次加密均先产生一5~9之间的任意整数随机数v，用原明文字符ASC2码加v，采用ASC2中33~126号加密，大于126号的再次从33号算起，如127号即为33号，小于33号的同理；
每次将随机数v转化为英文字母，ASC2码加65，即0对应A，9对应J，中间类推，加密后的ASC2码放到转化为字母后的随机数v后构成一新序列； 
将此加密的新序列再进行下一次加密；
最后将迭代加密次数n经过“ASC2码加65”处理后放到整个最终加密密文最前方，后面是最后一次加密后的密文序列；
解密时只需将上述过程逆用，依次解密提取随机数n、v，并将对应法则逆用转换为原明文即可。
此程序特点：
此程序可将英文大小写、数字、特殊字符进行加密解密，暂不支持汉字和空格加密解密，能将同一明文在不同的加密下加密成不同的密文，而这不同的密文会解密成相同的明文，即当时加密的明文；
允许多组对应的用户名与密码登陆此程序，只需在此程序源代码中login函数中添加即可，添加方便。
*/
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <cstdlib>
#include<stdlib.h>
#include<time.h>
int login(char name[],char code[])
{
    int tag=0,i;
    char data[100][2][100];
    strcpy(data[0][0],"1705");
    strcpy(data[0][1],"1705");
    //可以在此添加其它的对应的用户名和密码，格式同上即可，添加方便
    for(i=0;data[i][0][0]!='\0';i++)
    {
                if(strcmp(data[i][0],name)==0&&strcmp(data[i][1],code)==0)
                {
                               tag=1;
                               break;         
                }
    }
    return tag;
}
int suiji(int x,int y)
{
    //产生随机数 
    time_t t;
    srand((unsigned) time(&t));
    x=rand()%y;
    return x;
}
char zhuanhuan(int x)
{
     char y;
     y=x+65;
     return y;
}
int fanzhuanhuan(char x)
{
     int y;
     y=x-65;
     return y;
}
void jiami(char x[])
{
     int b,i,v;
     b=strlen(x);
     v=suiji(v,5)+5;
     for(i=b;i>=1;i--)
     {
                      if(x[i-1]+v>126)      x[i]=x[i-1]+v-94;
                             else           x[i]=x[i-1]+v;
     }
     x[0]=zhuanhuan(v);
}
void jiemi(char x[])
{
     int b,i,v;
     b=strlen(x);
     v=fanzhuanhuan(x[0]);
     for(i=1;i<b;i++)
     {
                      if(x[i]-v<33)         x[i-1]=x[i]-v+94;
                             else           x[i-1]=x[i]-v;
     }
     x[b-1]='\0';
}
main()
{
      printf("此为贾翔龙编的加密解密程序，请先登录\n请输入用户名和密码\n");
      m:;
      printf("用户名:");
      char zx[1024];
      scanf("%s",zx);
      printf("密码：") ;
      char zxx[1024];
      scanf("%s",zxx);
      if(login(zx,zxx)==1)
      {
              system("CLS"); //清屏函数 
              printf("恭喜你登陆成功，请将要转换的密码输入到文本文档中，将文本文档存到与此程序相同的文件夹下，并将文本文档命名为“需转换的密码.txt”，或将转换后的密码输入到文本文档中，将文本文档命名为“需还原的密码.txt”，然后存到此程序所在目录\n请选择类型：\n1、将密码转换为加密形式\n2、将加密形式的密码还原为原密码\n");
              int z;
              mm:;
              scanf("%d",&z);
              if(z==1)
              {
                      FILE *p1,*p3;
                      p1=fopen("需转换的密码.txt","r");
                      p3=fopen("转换后的密码.txt","w");
                      char a[32768];
                      int i,n;
                      n=suiji(n,5)+5;
                      fscanf(p1,"%s",a);
                      for(i=1;i<=n;i++)
                      {
                                      jiami(a);
                              
                      }
                      fprintf(p3,"%c",zhuanhuan(n));
                      for(i=0;a[i]!='\0';i++)
                      {
                                   fprintf(p3,"%c",a[i]);
                      }
                      fclose(p1);
                      fclose(p3);
              }
              else if(z==2)
              {
                      FILE *p2,*p4;
                      p2=fopen("需还原的密码.txt","r");
                      p4=fopen("还原后的密码.txt","w");
                      char a[32768];
                      int n,b,i;
                      fscanf(p2,"%s",a);
                      b=strlen(a);
                      n=fanzhuanhuan(a[0]);
                      for(i=0;i<b-1;i++)
                      {
                                         a[i]=a[i+1];
                      }
                      a[b-1]='\0';
                      for(i=1;i<=n;i++)
                      {
                                       jiemi(a);
                      }
                      for(i=0;a[i]!='\0';i++)
                      {
                                   fprintf(p4,"%c",a[i]);
                      }
                      fclose(p2);
                      fclose(p4);
              }
              else
              {
                  printf("\n你输入的数据有误，请重新输入\n");
                  goto mm;
              }
              printf("\n已转换完毕，按任意键退出\n贾翔龙编\n");
              getch();
      }
      else
      {
            printf("\n\n对不起，你输入的用户名或密码有误\n请重新登录\n");
            goto m;
      }
}
