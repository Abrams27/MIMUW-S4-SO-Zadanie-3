#include <lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <minix/rs.h>

pid_t getoppid(pid_t pid) {

  message mess;
  memset(&mess, 0, sizeof(mess));

  mess.m_pm_lc_getoppid.pid = pid;
  // TODO SPRAWDZENIE INNYCH ERRNO
  if (_syscall(PM_PROC_NR, PM_GETOPPID, &mess) < 0) {
    return (-1);
  }

  return mess.m_pm_lc_getoppid_reply.original_parent_pid;
}