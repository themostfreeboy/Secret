/*
01加密解密原理：
将每一个字符转化成10位二进制码，具体转化方法如下：
前三位为0~7之间的随机数v转化成的二进制数；
将0~7之间的随机数v加10变为10~17之间的新的随机数v；
一般输入的字符的ASC2码为33~126，将33~126转化为0~93，并加上加10转化为10~17之间的新的随机数v，将这个数转化为七位二进制数；
解密时只需将上述过程逆用即可。 
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int temp[10];
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
void plus(int x[],int y)
{
     int i;
     if(x[y]==0)      x[y]=1;
     else
     {
                x[y]=0;
                plus(x,y+1);
     }
}
void zhuanhuan(int x)
{
     int i;
     for(i=0;i<=9;i++)      temp[i]=0;
     for(i=1;i<=x;i++)
     {
                      plus(temp,0);
     }
}
main()
{
      printf("此为贾翔龙编的01加密解密程序，请先登录\n请输入用户名和密码\n");
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
                      int i,j,v=0,b[32768],u=0;
                      fscanf(p1,"%s",a);
                      for(i=0;a[i]!='\0';i++)
                      {
                                       v=suiji(v,8)+10;//产生10~17之间的随机数v 
                                       u=a[i]-33+v;//一般输入的字符ASC2码为33~126，将33~126转化为0~93，并加随机数v 
                                       zhuanhuan(v-10);
                                       for(j=2;j>=0;j--)
                                                 fprintf(p3,"%d",temp[j]);
                                       zhuanhuan(u);
                                       for(j=6;j>=0;j--)
                                                 fprintf(p3,"%d",temp[j]);
                                       
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
                      int b,i,j,v,u;
                      fscanf(p2,"%s",a);
                      b=strlen(a);
                      for(i=0;i<b/10;i++)
                      {
                                          j=10*i;
                                          /*”0“的ASC2码为48，”1“的ASC2码为49*/ 
                                          v=(a[j]-48)*4+(a[j+1]-48)*2+(a[j+2]-48)+10;
                                          u=(a[j+3]-48)*64+(a[j+4]-48)*32+(a[j+5]-48)*16+(a[j+6]-48)*8+(a[j+7]-48)*4+(a[j+8]-48)*2+(a[j+9]-48)-v+33;
                                          fprintf(p4,"%c",u);
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
