#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
char jiami1(char x)
{
     char y;
     y=x+2;
     return y;
}
char jiemi1(char x)
{
     char y;
     y=x-2;
     return y;
}
char jiami2(char x)
{
     char y;
     y=x+3;
     return y;
}
char jiemi2(char x)
{
     char y;
     y=x-3;
     return y;
}
char jiami3(char x)
{
     char y;
     y=x+5;
     return y;
}
char jiemi3(char x)
{
     char y;
     y=x-5;
     return y;
}
char jiami4(char x)
{
     char y;
     y=x+7;
     return y;
}
char jiemi4(char x)
{
     char y;
     y=x-7;
     return y;
}
char jiami5(char x)
{
     char y;
     y=x+11;
     return y;
}
char jiemi5(char x)
{
     char y;
     y=x-11;
     return y;
}
main()
{
      printf("��Ϊ�������������ת�����ߣ��뽫Ҫת�����������뵽�ı��ĵ��У����ı��ĵ�����Ϊ����ת��������.txt������ת������������뵽�ı��ĵ��У����ı��ĵ�����Ϊ���軹ԭ������.txt����Ȼ��浽�˳�������Ŀ¼\n��ѡ�����ͣ�\n1��������ת��Ϊ������ʽ\n2����������ʽ�����뻹ԭΪԭ����\n");
      FILE *p1,*p2,*p3,*p4;
      p1=fopen("��ת��������.txt","r");
      p2=fopen("�軹ԭ������.txt","r");
      p3=fopen("ת���������.txt","w");
      p4=fopen("��ԭ�������.txt","w");
      int z;
      scanf("%d",&z);
      if(z==1)
      {
              printf("\n��ѡ����ܷ�ʽ��\n\n1�����ܷ�ʽһ\n2�����ܷ�ʽ��\n3�����ܷ�ʽ��\n4�����ܷ�ʽ��\n5�����ܷ�ʽ��\n");
              char a[2*2*2*2*2*2*2*2*2*2*2*2*2*2*2];
              int l,b,i;
              scanf("%d",&l);
              fscanf(p1,"%s",&a);
              b=strlen(a);
              for(i=0;i<b;i++)
              {
                              if(l==1)     a[i]=jiami1(a[i]);
                              if(l==2)     a[i]=jiami2(a[i]);
                              if(l==3)     a[i]=jiami3(a[i]);
                              if(l==4)     a[i]=jiami4(a[i]);
                              if(l==5)     a[i]=jiami5(a[i]);
                              fprintf(p3,"%c",a[i]);
              }
      }
      else if(z==2)
      {
              printf("\n��ѡ����ܷ�ʽ��\n\n1�����ܷ�ʽһ\n2�����ܷ�ʽ��\n3�����ܷ�ʽ��\n4�����ܷ�ʽ��\n5�����ܷ�ʽ��\n");
              char a[2*2*2*2*2*2*2*2*2*2*2*2*2*2*2];
              int l,b,i;
              scanf("%d",&l);
              fscanf(p2,"%s",&a);
              b=strlen(a);
              for(i=0;i<b;i++)
              {
                              if(l==1)     a[i]=jiemi1(a[i]);
                              if(l==2)     a[i]=jiemi2(a[i]);
                              if(l==3)     a[i]=jiemi3(a[i]);
                              if(l==4)     a[i]=jiemi4(a[i]);
                              if(l==5)     a[i]=jiemi5(a[i]);
                              fprintf(p4,"%c",a[i]);
              }
      }
      printf("��ת����ϣ���������˳�\n");
      getch();
}
