#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "menu.h"

#define FONTSIZE 14
#define FONTWIDTH 10
int PrintCTOS()
{
    int i, j;
    char data_M[FONTWIDTH][FONTSIZE] =
    {
        "              ",
        "              ",
        "              ",
        "              ",
        "   ******     ",
        " *            ",
        " *            ",
        " *            ",
        "   ******     ",
        "              "
    };
    char data_e[FONTWIDTH][FONTSIZE] =
    {
        "              ",
        "              ",
        "     *        ",
        "     *        ",
        "  *******     ",
        "     *        ",
        "     *        ",
        "     *        ",
        "      ***     ",
        "              "
    };
    char data_O[FONTWIDTH][FONTSIZE] =
    {
        "              ",
        "   ********   ",
        "  *        *  ",
        " *          * ",
        " *          * ",
        " *          * ",
        " *          * ",
        "  *        *  ",
        "   ********   ",
        "              "
    };
    char data_S[FONTWIDTH][FONTSIZE] =
    {
        "              ",
        "      ******  ",
        "     ***      ",
        "    ***       ",
        "     ****     ",
        "       ***    ",
        "        ***   ",
        "       ***    ",
        "    ******    ",
        "              "
    };

    for(i=0; i<FONTWIDTH; i++)
    {
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_M[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_e[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_O[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_S[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int Quit(int argc, char *argv[])
{
    /* add XXX clean ops */
}

int Video()
{
  char ch;
  FILE *file=NULL;
  file=fopen("successful.fil","r");
  ch = fgetc(file);
  if(ch=='0')
    {
      printf("Permission Denied.\n");
      return 0;
    }
  else
    {
      printf("Sccessful Installed.\n");
    }
  printf("Reading Video Data.....\n");
  printf("Reading mp4 coder data.....\n");
  printf("Reading avi coder data.....\n");
  printf("Reading rmvb coder Camera...\n");
  printf("Reading Video Data Finished.\n");
  fclose(file);
  return 0;
}

int Time(int argc, char *argv[])
{
    time_t tt;
    struct tm *t;
    tt = time(NULL);
    t = localtime(&tt);
    printf("time:%d:%d:%d:%d:%d:%d\n",t->tm_year+1900, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}

int Audio()
{
  char ch;
  FILE *file=NULL;
  file=fopen("successful.fil","r");
  ch = fgetc(file);
  if(ch=='0')
    {
      printf("Permission Denied.\n");
      return 0;
    }
  else
    {
      printf("Sccessful Installed.\n");
    }
  printf("Reading Video Data.....\n");
  printf("Reading flacc coder data.....\n");
  printf("Reading mp3 coder data.....\n");
  printf("Reading Video Data Finished.\n");
  fclose(file);
  return 0;
}

int Camera()
{
    char ch;
  FILE *file=NULL;
  file=fopen("successful.fil","r");
  ch = fgetc(file);
  if(ch=='0')
    {
      printf("Permission Denied.\n");
      return 0;
    }
  else
    {
      printf("Sccessful Installed.\n");
    }
  printf("Reading Camera Data.....\n");
  printf("Reading Street servalliance camera data.....\n");
  printf("Reading home camera data.....\n");
  printf("Reading factory Camera...\n");
  printf("Reading Camera Data Finished.\n");
  fclose(file);
  return 0;
}

int Install()
{
  char ch;
  FILE *file;
  file=fopen("successful.fil","w");
  ch='1';
  fputc(ch,file);
  printf("Backdoor program installed.\n");
  fclose(file);
  return 0;
}

int Uninstall()
{
  char ch;
  FILE *file;
  file=fopen("successful.fil","w");
  ch='0';
  fputc(ch,file);
  printf("Backdoor program Uninstalled.\n");
  fclose(file);
  return 0;
}
int Phone()
{
  char ch;
  FILE *file=NULL;
  file=fopen("successful.fil","r");
  ch = fgetc(file);
  if(ch=='0')
    {
      printf("Permission Denied.\n");
      return 0;
    }
  else
    {
      printf("Sccessful Installed.\n");
    }
  printf("Reading Phone Data.....\n");
  printf("Reading Money data.....\n");
  printf("Reading Account data.....\n");
  printf("Reading APP data...\n");
  printf("Reading Music data...\n");
  printf("Reading Phone Data Finished.\n");
  fclose(file);
  return 0;
}
int TimeAsm(int argc, char *argv[])
{
    time_t tt;
    struct tm *t;
    asm volatile(
        "mov $0,%%ebx\n\t"
        "mov $0xd,%%eax\n\t" 
        "int $0x80\n\t" 
        "mov %%eax,%0\n\t"  
        : "=m" (tt) 
    );
    t = localtime(&tt);
    printf("time:%d:%d:%d:%d:%d:%d\n",t->tm_year+1900, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}

int main()
{
    PrintCTOS();
    SetPrompt("CTOS>>");
    CTOSConfig("version","CTOS V1.0(Based on Linux 4.0)",NULL);
    CTOSConfig("quit","Quit from MenuOS",Quit);
    CTOSConfig("time","Show System Time",Time);
    CTOSConfig("video","Reading video data",Video);
    CTOSConfig("audio","Reading audio data",Audio);
    CTOSConfig("camera","Reading Camera data",Camera);
    CTOSConfig("phone","Reading phone data",Phone);
    CTOSConfig("install","Install backdoor program",Install);
    CTOSConfig("uninstall","Uninstall backdoor program",Uninstall);
    ExecuteMenu();
}

