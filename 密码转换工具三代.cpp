#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <cstdlib>
#include<stdlib.h>
#include<time.h>
int suiji(int x)
{
    //产生随机数 
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
      printf("此为贾翔龙编的密码转换工具，请先登录\n");
      m:;
      printf("用户名:贾翔龙\n密码:");
      char zx[1024];
      scanf("%s",zx);
      if(zx[0]=='j'&&zx[1]=='i'&&zx[2]=='a'&&zx[3]=='x'&&zx[4]=='i'&&zx[5]=='a'&&zx[6]=='n'&&zx[7]=='g'&&zx[8]=='l'&&zx[9]=='o'&&zx[10]=='n'&&zx[11]=='g'&&zx[12]=='\0')
    {
      system("command /c cls"); //清屏函数 
      printf("恭喜你登陆成功，请将要转换的密码输入到文本文档中，将文本文档命名为“需转换的密码.txt”，或将转换后的密码输入到文本文档中，将文本文档命名为“需还原的密码.txt”，然后存到此程序所在目录\n请选择类型：\n1、将密码转换为加密形式\n2、将加密形式的密码还原为原密码\n");
      int z;
      scanf("%d",&z);
      if(z==1)
      {
              FILE *p1,*p3;
              p1=fopen("需转换的密码.txt","r");
              p3=fopen("转换后的密码.txt","w");
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
              p2=fopen("需还原的密码.txt","r");
              p4=fopen("还原后的密码.txt","w");
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
      printf("已转换完毕，按任意键退出\n");
    }
      else
      {
            printf("\n\n对不起，你输入的登录密码有误\n请重新登录\n");
            goto m; 
     }
      getch();
}
