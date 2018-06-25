//SyncTOOL.c
//June 19th 2018 - Zach Mitchell Klaric
//
//
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void Menu()  {

  printf("%s%s%s%s%s", "?  - This menu   \n",
                       "o  - Open stream \n",
                       "i  - Info        \n",
                       "                 \n",
                       "q  - Quit        \n");
}

void TxMenu()  {

  printf("%s%s%s%s%s", "?  - This menu     \n",
                       "/x - Send multiple \n",
                       "/  -               \n",
                       "/  -               \n",
                       "q  - Quit          \n");
}

unsigned char Special(unsigned char Switch)  {

  puts("Not implemented yet :P");
  
  return(Switch);  
}

void Quit(int fd)  {

  if (close(fd))  { puts("close stream error"); perror("close"); exit(1); }
  puts("stream closed\nbye.");
  exit(0);
}

void Info()  {

  printf("%s%s%s", "SyncTool v0.9\n",
                   "A tool for syncronis serial connected through an adapter to a asyncronise stream\n",  
		   "And also for sockets soon.....\n");

}
		 
int WriteOut(char *pop, int fd)  {

  int bob = 0;
  
  if ( sscanf(pop, "%x", &bob) < 1 )  return(-1); //catch this some other time.
  write(fd, &bob, 1);
  read(fd, pop, 1);                               //dont waiste the char buff
  return(*pop & 0x000000ff);                      //what pop points to, right?
}
  

int FileOpen()  {

  int  fd;
  char path[256]; //dont overflow meeee.
  
  do  {
    printf("Path\e[96m>\e[0m");
    gets(path);
  }while( strlen(path) < 1 );
  
  //                                            6           4       4
  if ( ( fd = open(path, O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH) ) == -1 ) //later O_SYNC and such.
    { puts("Error"); perror("open");  return(-1); }
  
  return (fd);
}

void SendRecieve(int fd)  {

  int  x = 0;
  char var[128];

  while(1)
    do {
    
      printf("\nTx\e[96m>\e[0m");
      gets(var);
      
      switch(var[0])  {

      case '?' : {  TxMenu();             break; }
      
      case '/' : {  Special(var[1]);      break; }
      
      case 'i' : {  Info();               break; }

      case 'q' : {  Quit(fd);             break; }

      default  : { printf("\t\t \e[35m<\e[0mRx 0x%X\n", WriteOut(var, fd)); break; }
    }

  }  while( !x );
      
}



int main()  {

  int  x  = 0;
  char var[128];

  do {

    printf("\nTool\e[96m>\e[0m");
    gets(var);

    switch(var[0])  {

      case '?' : {  Menu();         break;  }
      
      case 'o' : {  SendRecieve(FileOpen());     break;  }

      case 'i' : {  Info();         break;  }

      case 'q' : {  x = 1;          break;  }

      default  : { printf("what??"); break; }
    }

  }  while( !x );

  puts("bye");
  return 0;
}
