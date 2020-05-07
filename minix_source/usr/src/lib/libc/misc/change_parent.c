#include <lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <minix/rs.h>

int changeparent() {

  message mess;
  memset(&mess, 0, sizeof(mess));

  if (_syscall(PM_PROC_NR, PM_CHANGE_PARENT, &mess) < 0) {
    return (-1);
  }

  return 0;
}