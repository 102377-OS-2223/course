//Fonts de recerca http://dis.um.es/~ginesgm/medidas.html

#include <sys/time.h>
#include <unistd.h>

struct ptimes{
    unsigned long start_time;
    unsigned long real_time;
    unsigned long user_time;
    unsigned long sys_time;
}

gettimes(int pid, struct ptimes *pt){
    
    task = pid_task(find_get_pid(pid), PIDTYPE_PID);
}