#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <cstdlib>
#include<stdlib.h>
#include<time.h>
int suiji(int x)
{
    //��������� 
    time_t t;
    srand((unsigned) time(&t));
    x=rand()%100;
    return x;
}
char jiami(char x,int y)
{
    char z;
    z=x+y;
    return z;
}
char jiemi(char x,int y)
{
    char z;
    z=x-y;
    return z;
}
main()
{
      printf("��Ϊ�������������ת�����ߣ����ȵ�¼\n");
      m:;
      printf("�û���:������\n����:");
      char zx[1024];
      scanf("%s",zx);
      if(zx[0]=='j'&&zx[1]=='i'&&zx[2]=='a'&&zx[3]=='x'&&zx[4]=='i'&&zx[5]=='a'&&zx[6]=='n'&&zx[7]=='g'&&zx[8]=='l'&&zx[9]=='o'&&zx[10]=='n'&&zx[11]=='g'&&zx[12]=='\0')
    {
      system("command /c cls"); //�������� 
      printf("��ϲ���½�ɹ����뽫Ҫת�����������뵽�ı��ĵ��У����ı��ĵ�����Ϊ����ת��������.txt������ת������������뵽�ı��ĵ��У����ı��ĵ�����Ϊ���軹ԭ������.txt����Ȼ��浽�˳�������Ŀ¼\n��ѡ�����ͣ�\n1��������ת��Ϊ������ʽ\n2����������ʽ�����뻹ԭΪԭ����\n");
      int z;
      scanf("%d",&z);
      if(z==1)
      {
              FILE *p1,*p3;
              p1=fopen("��ת��������.txt","r");
              p3=fopen("ת���������.txt","w");
              char a[2*2*2*2*2*2*2*2*2*2*2*2*2*2*2];
              int l,b,i;
              fscanf(p1,"%s",&a);
              b=strlen(a);
              l=suiji(l); 
              fprintf(p3,"%d\n",l+314);
              for(i=0;i<=b;i++)
              {
                              a[i]=jiami(a[i],l);
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
              char a[2*2*2*2*2*2*2*2*2*2*2*2*2*2*2];
              int l,b,i;
              fscanf(p2,"%d",&l);
              fscanf(p2," %s",&a);
              b=strlen(a);
              l=l-314;
              for(i=0;i<=b;i++)
              {
                              a[i]=jiemi(a[i],l);
                              fprintf(p4,"%c",a[i]);
              }
              fclose(p2);
              fclose(p4);
      }
      printf("��ת����ϣ���������˳�\n");
    }
      else
      {
            printf("\n\n�Բ���������ĵ�¼��������\n�����µ�¼\n");
            goto m; 
     }
      getch();
}
