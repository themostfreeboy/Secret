#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
char jiami1(char x)
{
     char y;
     y=x-2;
     return y;
}
char jiemi1(char x)
{
     char y;
     y=x+2;
     return y;
}
char jiami2(char x)
{
     char y;
     y=x-3;
     return y;
}
char jiemi2(char x)
{
     char y;
     y=x+3;
     return y;
}
char jiami3(char x)
{
     char y;
     y=x-5;
     return y;
}
char jiemi3(char x)
{
     char y;
     y=x+5;
     return y;
}
char jiami4(char x)
{
     char y;
     y=x-9;
     return y;
}
char jiemi4(char x)
{
     char y;
     y=x+9;
     return y;
}
char jiami5(char x)
{
     char y;
     y=x-11;
     return y;
}
char jiemi5(char x)
{
     char y;
     y=x+11;
     return y;
}
main()
{
      printf("��Ϊ�������������ת�����ߣ����ȵ�¼\n�û���:������\n����:");
      char zx[1024];
      scanf("%s",zx);
      if(zx[0]=='j'&&zx[1]=='i'&&zx[2]=='a'&&zx[3]=='x'&&zx[4]=='i'&&zx[5]=='a'&&zx[6]=='n'&&zx[7]=='g'&&zx[8]=='l'&&zx[9]=='o'&&zx[10]=='n'&&zx[11]=='g'&&zx[12]=='\0')
    {
      printf("\n\n��ϲ���½�ɹ����뽫Ҫת�����������뵽�ı��ĵ��У����ı��ĵ�����Ϊ����ת��������.txt������ת������������뵽�ı��ĵ��У����ı��ĵ�����Ϊ���軹ԭ������.txt����Ȼ��浽�˳�������Ŀ¼\n��ѡ�����ͣ�\n1��������ת��Ϊ������ʽ\n2����������ʽ�����뻹ԭΪԭ����\n");
      int z;
      scanf("%d",&z);
      if(z==1)
      {
              FILE *p1,*p3;
              p1=fopen("��ת��������.txt","r");
              p3=fopen("ת���������.txt","w");
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
              FILE *p2,*p4;
              p2=fopen("�軹ԭ������.txt","r");
              p4=fopen("��ԭ�������.txt","w");
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
    }
      else printf("\n\n�Բ���������ĵ�¼��������\n��������˳�\n");      
      getch();
}
