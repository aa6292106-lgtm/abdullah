#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    /* إنشاء عملية ابن تفريعية */
    pid = fork();

    if (pid < 0) {
        /* في حال فشل إنشاء العملية */
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } 
    else if (pid == 0) {
        /* داخل العملية الابن: تنفيذ أمر عرض الملفات ls */
        execlp("/bin/ls", "ls", NULL);
    } 
    else {
        /* داخل العملية الأب: انتظار العملية الابن حتى تنتهي */
        wait(NULL);
        printf("Child Complete\n");
    }

    return 0;
}
