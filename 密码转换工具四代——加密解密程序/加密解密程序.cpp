/*
���ܽ���ԭ��
���õ������ܷ����Ȳ���һ5~9֮������������������Ϊ�������ܴ���n��ÿ�μ��ܷ�ʽ��ͬ��
ÿ�μ��ܾ��Ȳ���һ5~9֮����������������v����ԭ�����ַ�ASC2���v������ASC2��33~126�ż��ܣ�����126�ŵ��ٴδ�33��������127�ż�Ϊ33�ţ�С��33�ŵ�ͬ��
ÿ�ν������vת��ΪӢ����ĸ��ASC2���65����0��ӦA��9��ӦJ���м����ƣ����ܺ��ASC2��ŵ�ת��Ϊ��ĸ��������v�󹹳�һ�����У� 
���˼��ܵ��������ٽ�����һ�μ��ܣ�
��󽫵������ܴ���n������ASC2���65�������ŵ��������ռ���������ǰ�������������һ�μ��ܺ���������У�
����ʱֻ�轫�����������ã����ν�����ȡ�����n��v��������Ӧ��������ת��Ϊԭ���ļ��ɡ�
�˳����ص㣺
�˳���ɽ�Ӣ�Ĵ�Сд�����֡������ַ����м��ܽ��ܣ��ݲ�֧�ֺ��ֺͿո���ܽ��ܣ��ܽ�ͬһ�����ڲ�ͬ�ļ����¼��ܳɲ�ͬ�����ģ����ⲻͬ�����Ļ���ܳ���ͬ�����ģ�����ʱ���ܵ����ģ�
��������Ӧ���û����������½�˳���ֻ���ڴ˳���Դ������login��������Ӽ��ɣ���ӷ��㡣
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
    //�����ڴ���������Ķ�Ӧ���û��������룬��ʽͬ�ϼ��ɣ���ӷ���
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
    //��������� 
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
      printf("��Ϊ��������ļ��ܽ��ܳ������ȵ�¼\n�������û���������\n");
      m:;
      printf("�û���:");
      char zx[1024];
      scanf("%s",zx);
      printf("���룺") ;
      char zxx[1024];
      scanf("%s",zxx);
      if(login(zx,zxx)==1)
      {
              system("CLS"); //�������� 
              printf("��ϲ���½�ɹ����뽫Ҫת�����������뵽�ı��ĵ��У����ı��ĵ��浽��˳�����ͬ���ļ����£������ı��ĵ�����Ϊ����ת��������.txt������ת������������뵽�ı��ĵ��У����ı��ĵ�����Ϊ���軹ԭ������.txt����Ȼ��浽�˳�������Ŀ¼\n��ѡ�����ͣ�\n1��������ת��Ϊ������ʽ\n2����������ʽ�����뻹ԭΪԭ����\n");
              int z;
              mm:;
              scanf("%d",&z);
              if(z==1)
              {
                      FILE *p1,*p3;
                      p1=fopen("��ת��������.txt","r");
                      p3=fopen("ת���������.txt","w");
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
                      p2=fopen("�軹ԭ������.txt","r");
                      p4=fopen("��ԭ�������.txt","w");
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
                  printf("\n�������������������������\n");
                  goto mm;
              }
              printf("\n��ת����ϣ���������˳�\n��������\n");
              getch();
      }
      else
      {
            printf("\n\n�Բ�����������û�������������\n�����µ�¼\n");
            goto m;
      }
}
