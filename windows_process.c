#include <stdio.h>
#include <windows.h>

int main(VOID) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    /* تخصيص الذاكرة وتصفيرها */
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    /* إنشاء العملية الابن لفتح برنامج الرسام */
    if (!CreateProcess(NULL,   
        "C:\\WINDOWS\\system32\\mspaint.exe", 
        NULL,                  
        NULL,                  
        FALSE,                 
        0,                     
        NULL,                  
        NULL,                  
        &si,                   
        &pi))                  
    {
        fprintf(stderr, "Create Process Failed\n");
        return -1;
    }

    /* العملية الأب تنتظر الابن حتى ينتهي */
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("Child Complete\n");

    /* إغلاق المقابض */
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
