/*
01���ܽ���ԭ��
��ÿһ���ַ�ת����10λ�������룬����ת���������£�
ǰ��λΪ0~7֮��������vת���ɵĶ���������
��0~7֮��������v��10��Ϊ10~17֮����µ������v��
һ��������ַ���ASC2��Ϊ33~126����33~126ת��Ϊ0~93�������ϼ�10ת��Ϊ10~17֮����µ������v���������ת��Ϊ��λ����������
����ʱֻ�轫�����������ü��ɡ� 
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
      printf("��Ϊ���������01���ܽ��ܳ������ȵ�¼\n�������û���������\n");
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
                      int i,j,v=0,b[32768],u=0;
                      fscanf(p1,"%s",a);
                      for(i=0;a[i]!='\0';i++)
                      {
                                       v=suiji(v,8)+10;//����10~17֮��������v 
                                       u=a[i]-33+v;//һ��������ַ�ASC2��Ϊ33~126����33~126ת��Ϊ0~93�����������v 
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
                      p2=fopen("�軹ԭ������.txt","r");
                      p4=fopen("��ԭ�������.txt","w");
                      char a[32768];
                      int b,i,j,v,u;
                      fscanf(p2,"%s",a);
                      b=strlen(a);
                      for(i=0;i<b/10;i++)
                      {
                                          j=10*i;
                                          /*��0����ASC2��Ϊ48����1����ASC2��Ϊ49*/ 
                                          v=(a[j]-48)*4+(a[j+1]-48)*2+(a[j+2]-48)+10;
                                          u=(a[j+3]-48)*64+(a[j+4]-48)*32+(a[j+5]-48)*16+(a[j+6]-48)*8+(a[j+7]-48)*4+(a[j+8]-48)*2+(a[j+9]-48)-v+33;
                                          fprintf(p4,"%c",u);
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
