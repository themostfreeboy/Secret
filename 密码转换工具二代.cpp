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
      printf("此为贾翔龙编的密码转换工具，请先登录\n用户名:贾翔龙\n密码:");
      char zx[1024];
      scanf("%s",zx);
      if(zx[0]=='j'&&zx[1]=='i'&&zx[2]=='a'&&zx[3]=='x'&&zx[4]=='i'&&zx[5]=='a'&&zx[6]=='n'&&zx[7]=='g'&&zx[8]=='l'&&zx[9]=='o'&&zx[10]=='n'&&zx[11]=='g'&&zx[12]=='\0')
    {
      printf("\n\n恭喜你登陆成功，请将要转换的密码输入到文本文档中，将文本文档命名为“需转换的密码.txt”，或将转换后的密码输入到文本文档中，将文本文档命名为“需还原的密码.txt”，然后存到此程序所在目录\n请选择类型：\n1、将密码转换为加密形式\n2、将加密形式的密码还原为原密码\n");
      int z;
      scanf("%d",&z);
      if(z==1)
      {
              FILE *p1,*p3;
              p1=fopen("需转换的密码.txt","r");
              p3=fopen("转换后的密码.txt","w");
              printf("\n请选择加密方式：\n\n1、加密方式一\n2、加密方式二\n3、加密方式三\n4、加密方式四\n5、加密方式五\n");
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
              p2=fopen("需还原的密码.txt","r");
              p4=fopen("还原后的密码.txt","w");
              printf("\n请选择解密方式：\n\n1、解密方式一\n2、解密方式二\n3、解密方式三\n4、解密方式四\n5、解密方式五\n");
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
      printf("已转换完毕，按任意键退出\n");
    }
      else printf("\n\n对不起，你输入的登录密码有误\n按任意键退出\n");      
      getch();
}
