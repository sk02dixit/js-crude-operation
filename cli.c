#include <stdio.h>
#include <unistd.h>
//#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
//#include "arpa/inet.h"
int sd;
char *fmt = "{\"method\":\"%s\"}";
int system()
{
}
int configure()
{
  int ch;
  do {
    printf("1.Buzzer On\n");
    printf("2.Buzzer Off\n");
    printf("3.Contactor On\n");
    printf("4.Contactor Off\n");
    printf("5.System ok On\n");
    printf("6.System ok Off\n");
    printf("7.Solenoid Valve 1 On\n");
    printf("8.Solenoid Valve 1 Off\n");
    printf("9.Solenoid Valve 2 On\n");
    printf("10.Solenoid Valve 2 Off\n");
    printf("11.Major Alarm On\n");
    printf("12.Major Alarm Off\n");
    printf("13.Minor Alarm On\n");
    printf("14.Minor Alarm Off\n");
    printf("15.Spare On\n");
    printf("16.Spare Off\n");
    printf("0.Go Back\n");
    scanf("%d", &ch);
    switch(ch){
    case 1:
    	printf("Buzzer is On\n");
			//gpio_set(113, 0);
      break;
    case 2:
      break;
    case 0:
      return 0;
      break;
    default:
      printf("Not a valid option!\n");
    }
  } while(1);
}

int monitor()
{
  int ch;
  char buf[1024];
  do {
    printf("Press 1 for param1.\n");
    printf("Press 2 for param2.\n");
    printf("Press 3 to go back.\n");
    scanf("%d", &ch);
    switch(ch){
    case 1:
      sprintf(buf, fmt, "sayHello");
      printf("Command: %s\n", buf);
      write(sd, buf, strlen(buf));
      read(sd, buf, 1024);
      printf("Got: %s\n", buf);
      break;
    case 2:
      break;
    case 3:
      return 0;
      break;
    default:
      printf("Not a valid option!\n");
    }
  } while(1);
}

int main_menu()
{
  int ch;
  do {
    printf("1. Monitor\n");
    printf("2. Configure\n");
    printf("3. System\n");
    printf("9. Exit\n");
    scanf("%d", &ch);
    switch(ch){
    case 1:
      monitor();
      break;
    case 2:
      configure();
      break;
    case 3:
      system();
      break;
    case 9:
      return 0;
      break;
    default:
      printf("Not a valid option!\n");
    }
  } while(1);
}

int main()
{
  struct sockaddr_in addr;
  int ret;

  sd = socket(AF_INET, SOCK_STREAM, 0);
  if(sd < 0){
    printf("Socket not Created\n");
    return -1;
  }

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = 0;
  addr.sin_port = htons(5555);
  ret = connect(sd, (struct sockaddr*)&addr, sizeof(addr));
  if (ret < 0){
    perror("Connect failed: ");
    //printf("Connect to 0x%08x:%d failed!!\n", ip, port);
    close(sd);
    return -1;
  }


  main_menu();
}
