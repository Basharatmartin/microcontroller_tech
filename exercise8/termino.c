#include <stdio.h>
#include <sys/ioctl.h> //ioctl() call defenitions
#include <fcntl.h>  /* File Control Definitions          */
#include <termios.h>/* POSIX Terminal Control Definitions*/
#include <unistd.h> /* UNIX Standard Definitions         */
#include <errno.h>  /* ERROR Number Definitions          */


void main()
{
   int fd;
   fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY );//Open Serial Port
  
   int RTS_flag;
   RTS_flag = TIOCM_RTS;
   ioctl(fd,TIOCMBIS,&RTS_flag);//Set RTS pin
   getchar();
   ioctl(fd,TIOCMBIC,&RTS_flag);//Clear RTS pin
   close(fd);
}


