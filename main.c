#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdarg.h>
#include "cJSON.c"
#define PORT 12345
#define SA struct sockaddr
#define ip 94.184.135.142
char authtoken[1024];
char* concat(int count, ...);
struct people
{
    int num;
    char name[1000];
    char pas [1000];
};
cJSON* token = NULL;
char chaname[1000];
void jc(struct people x);
void cc(struct people x);
struct people x;
int login(struct people x);
int main()
{
    while(true)
    {
    char buffer[1000];
    printf("Account menu\n");
    printf("1 : register\n");
    printf("2 : login\n");
    scanf("%d",&x.num);
    if(x.num == 1)
    {
    while(true)
    {
        printf("Enter user name:\n");
        scanf("%s",&x.name);
        printf("Enter password:\n");
        scanf("%s",&x.pas);
        //printf("%s\n",concat(4,"register ",x.name,", " ,x.pas));
        //getchar();
        int client_socket, server_socket;
        struct sockaddr_in servaddr, cli;

        WORD wVersionRequested;
        WSADATA wsaData;
        int err;

        // Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h
        wVersionRequested = MAKEWORD(2, 2);

        err = WSAStartup(wVersionRequested, &wsaData);
        if (err != 0) {
        // Tell the user that we could not find a usable Winsock DLL.
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
        }

        // Create and verify socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1) {
		printf("Socket creation failed...\n");
		exit(0);
        }
        else
		printf("Socket successfully created..\n");

        // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("ip");
        servaddr.sin_port = htons(PORT);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0) {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");

            send(client_socket,concat(4,"register ",x.name,", " ,x.pas) , 1000, 0);
            memset(buffer,0,1000);
            recv(client_socket, buffer,1000, 0);
            cJSON *buffer_j = cJSON_Parse(buffer);
            if(strcmp(cJSON_GetObjectItem(buffer_j,"type")->valuestring , "Error")!= 0)
            {
                x.num++;
                printf("Register Accept\n");
                break;
            }
            else
            {
                printf("Error\n");
            }
            closesocket(client_socket);
        }
    }
    if(x.num == 2)
    {
        while(true)
        {
            printf("user name:\n");
            scanf("%s",&x.name);
            printf("password:\n");
            scanf("%s",&x.pas);
            int client_socket, server_socket;
            struct sockaddr_in servaddr, cli;

            WORD wVersionRequested;
            WSADATA wsaData;
            int err;

            // Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h
            wVersionRequested = MAKEWORD(2, 2);

        err = WSAStartup(wVersionRequested, &wsaData);
        if (err != 0) {
            // Tell the user that we could not find a usable Winsock DLL.
            printf("WSAStartup failed with error: %d\n", err);
            return 1;
        }

        // Create and verify socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1) {
            printf("Socket creation failed...\n");
            exit(0);
        }
        else
            printf("Socket successfully created..\n");

        // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("ip");
        servaddr.sin_port = htons(PORT);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0) {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");

            send(client_socket,concat(4,"login ",x.name,", " ,x.pas) ,1000, 0);
            recv(client_socket, buffer, 1000, 0);
            cJSON *buffer_j = cJSON_Parse(buffer);
            if(strcmp(cJSON_GetObjectItem(buffer_j,"type") -> valuestring , "Error"))
            {
                printf("Accepted Login\n");
                token = cJSON_GetObjectItem(buffer_j,"content");
                break;
            }
            else
            {
                printf("%s\n",buffer);
            }
            closesocket(client_socket);
    }
    login(x);
    }
}
}

int login(struct people x)
{
    int stats;
    while(true)
    {
    printf("1 : create channel\n");
    printf("2 : join channel\n");
    printf("3 : logout\n");
    scanf("%d",&stats);
    if(stats == 3)
    {
        int client_socket, server_socket;
        struct sockaddr_in servaddr, cli;

        WORD wVersionRequested;
        WSADATA wsaData;
        int err;

        // Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h
        wVersionRequested = MAKEWORD(2, 2);

        err = WSAStartup(wVersionRequested, &wsaData);
        if (err != 0) {
            // Tell the user that we could not find a usable Winsock DLL.
            printf("WSAStartup failed with error: %d\n", err);
            return 1;
        }

        // Create and verify socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1) {
            printf("Socket creation failed...\n");
            exit(0);
        }
        else
            printf("Socket successfully created..\n");

        // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("ip");
        servaddr.sin_port = htons(12345);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0) {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");

        char temp[1000] ="logout ";
        strcat(temp,token->valuestring);
        //char temp1 [1000]="\n";
        strcat(temp,"\n");
        char fff[10000];
        send(client_socket,temp ,sizeof(temp), 0);
        //printf("hi\n");
        memset(fff,1000,0);
        recv(client_socket, fff,1000, 0);
        //printf("salam\n");
        cJSON *fff_j = cJSON_Parse(fff);
        if(strcmp(cJSON_GetObjectItem(fff_j,"type") -> valuestring , "Error") != 0)
        {
            printf("Accepted Logout");
            return main();
        }
        else
        {
            printf("%s",fff);
        }
        closesocket(client_socket);
    }
    if(stats == 1)
    {
        cc(x);
    }
    if(stats == 2)
    {
    char ch[1000];
    printf("please enter your channel name:\n");
    scanf("%s",ch);
    int client_socket, server_socket;
    struct sockaddr_in servaddr, cli;

    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    // Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h
    wVersionRequested = MAKEWORD(2, 2);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        // Tell the user that we could not find a usable Winsock DLL.
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }

    // Create and verify socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
    printf("Socket successfully created..\n");

    // Assign IP and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("ip");
    servaddr.sin_port = htons(PORT);
    // Connect the client socket to server socket
    if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection to the server failed...\n");
        exit(0);
    }
    else
    printf("Successfully connected to the server..\n");
    char y[10000] = "join channel ";
    strcat(y,ch);
    char y1[1000] = ", ";
    strcat(y,y1);
    strcat(y,token->valuestring);
    char y2[1000]="\n";
    strcat(y,y2);
    send(client_socket,y,sizeof(y),0);
    char g[1000];
    recv(client_socket,g,1000,0);
    cJSON *g_j = cJSON_Parse(g);
    if(strcmp(cJSON_GetObjectItem(g_j,"type") -> valuestring , "Error") != 0)
    {
        printf("Succssful\n");
        jc(x) ;
        closesocket(client_socket) ;
    }
    else
    {
        printf("%s",g);
        closesocket(client_socket) ;
    }
    }
    }
}
void cc(struct people x)
{
    printf("please enter your channel name:\n");
    scanf("%s",&chaname);
    int client_socket, server_socket;
	struct sockaddr_in servaddr, cli;

	WORD wVersionRequested;
    WSADATA wsaData;
    int err;

	// Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h
    wVersionRequested = MAKEWORD(2, 2);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        // Tell the user that we could not find a usable Winsock DLL.
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }

	// Create and verify socket
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		printf("Socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");

	// Assign IP and port
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("ip");
	servaddr.sin_port = htons(PORT);

	// Connect the client socket to server socket
	if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0) {
		printf("Connection to the server failed...\n");
		exit(0);
	}
	else
    printf("Successfully connected to the server..\n");
    send(client_socket,concat(5,"create channel ",chaname,", " ,token->valuestring,"\n") ,1000, 0);
    memset(chaname,0,1000);
    recv(client_socket,chaname,1000,0);
    cJSON *chaname_j = cJSON_Parse(chaname);
    if(strcmp(cJSON_GetObjectItem(chaname_j,"type") -> valuestring , "Error") != 0)
    {
        printf("Succssful\n");
        jc(x);
    }
    else
    {
        printf("%s\n",chaname);
        return cc(x);
    }
    closesocket(client_socket);
}

void jc(struct people x)
{

    cJSON* salam = NULL;
    cJSON *stats= NULL;
    char mas[1000];
    while(true)
    {
        printf("1 : send massage \n");
        printf("2 : refresh\n");
        printf("3 : channel members\n");
        printf("4 : leave channel\n");
        scanf("%d",&x.num);
        if(x.num == 1)
        {
            printf("enter massage :\n");
            scanf("%s",&mas);
            int client_socket, server_socket;
            struct sockaddr_in servaddr, cli;

            WORD wVersionRequested;
            WSADATA wsaData;
            int err;

            // Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h
            wVersionRequested = MAKEWORD(2, 2);

            err = WSAStartup(wVersionRequested, &wsaData);
            if (err != 0) {
            // Tell the user that we could not find a usable Winsock DLL.
            printf("WSAStartup failed with error: %d\n", err);
            return 1;
            }

            // Create and verify socket
            client_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (client_socket == -1) {
                printf("Socket creation failed...\n");
                exit(0);
        }
        else
            printf("Socket successfully created..\n");

            // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("ip");
        servaddr.sin_port = htons(PORT);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0) {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");
            send(client_socket,concat(4,"send ",mas,", ",token->valuestring),1000,0);
            //printf("%s",concat(4,"send ",mas,", ",token));
            memset(mas,0,1000);
            recv(client_socket,mas,1000,0);
            cJSON *mas_j = cJSON_Parse(mas);
            if(strcmp(cJSON_GetObjectItem(mas_j,"type") -> valuestring , "Error") == -1)
            {
                printf("Succssful\n");
                continue;
            }
            else
            {
                printf("%s",mas);
            }
            closesocket(client_socket);
        }
        if(x.num == 2)
        {
            int client_socket, server_socket;
            struct sockaddr_in servaddr, cli;

            WORD wVersionRequested;
            WSADATA wsaData;
            int err;

            // Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h
            wVersionRequested = MAKEWORD(2, 2);

            err = WSAStartup(wVersionRequested, &wsaData);
            if (err != 0) {
                // Tell the user that we could not find a usable Winsock DLL.
                printf("WSAStartup failed with error: %d\n", err);
                return 1;
            }

            // Create and verify socket
            client_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (client_socket == -1) {
                printf("Socket creation failed...\n");
                exit(0);
            }
            else
                printf("Socket successfully created..\n");

            // Assign IP and port
            memset(&servaddr, 0, sizeof(servaddr));
            servaddr.sin_family = AF_INET;
            servaddr.sin_addr.s_addr = inet_addr("ip");
            servaddr.sin_port = htons(PORT);

            // Connect the client socket to server socket
            char temp[1024]="refresh ";
            strcat(temp,token->valuestring);
            strcat(temp,"\n");
            if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0) {
                printf("Connection to the server failed...\n");
                exit(0);
            }
            else
                printf("Successfully connected to the server..\n");
                //printf("%s",temp);
            send(client_socket,temp,sizeof(temp),0);
            memset(mas ,0,1000);
            recv(client_socket,mas,1000,0);
            printf("%s\n",mas);
            cJSON *mas_j = cJSON_Parse(mas);
            stats = cJSON_GetObjectItem(mas_j,"content");
            cJSON_ArrayForEach(salam,stats){
                cJSON *sender =cJSON_GetObjectItem(salam,"sender");
                cJSON *content =cJSON_GetObjectItem(salam,"content");

                printf("%s : %s\n" , sender->valuestring , content->valuestring );


            }
            closesocket(client_socket);
        }
        if(x.num == 3)
        {
            int client_socket, server_socket;
            struct sockaddr_in servaddr, cli;

            WORD wVersionRequested;
            WSADATA wsaData;
            int err;

            // Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h
            wVersionRequested = MAKEWORD(2, 2);

            err = WSAStartup(wVersionRequested, &wsaData);
            if (err != 0) {
                // Tell the user that we could not find a usable Winsock DLL.
                printf("WSAStartup failed with error: %d\n", err);
                return 1;
            }

            // Create and verify socket
            client_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (client_socket == -1) {
                printf("Socket creation failed...\n");
                exit(0);
            }
            else
                printf("Socket successfully created..\n");

            // Assign IP and port
            memset(&servaddr, 0, sizeof(servaddr));
            servaddr.sin_family = AF_INET;
            servaddr.sin_addr.s_addr = inet_addr("ip");
            servaddr.sin_port = htons(PORT);

            // Connect the client socket to server socket
            if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0) {
                printf("Connection to the server failed...\n");
                exit(0);
            }
            else
                printf("Successfully connected to the server..\n");
            char temp[1000] ="channel members ";
            strcat(temp,token->valuestring);
            strcat(temp,"\n");
            send(client_socket,temp,sizeof(temp),0);
            //printf("asd\n");
            memset(mas,0,1000);
            recv(client_socket,mas,1000,0);
            //printf("b\n");
            cJSON* member = NULL;
            cJSON *asd = cJSON_Parse(mas);
            const cJSON *type = NULL;
            const cJSON *content = NULL;
            type = cJSON_GetObjectItemCaseSensitive(asd,"type");
            content = cJSON_GetObjectItemCaseSensitive(asd,"content");
            printf("channel members:\n");
            cJSON_ArrayForEach(member,content)
            {
                printf("%s\n",member->valuestring);
            }
            closesocket(client_socket);
        }
        if(x.num == 4)
        {
            int client_socket, server_socket;
            struct sockaddr_in servaddr, cli;

            WORD wVersionRequested;
            WSADATA wsaData;
            int err;

            // Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h
            wVersionRequested = MAKEWORD(2, 2);

            err = WSAStartup(wVersionRequested, &wsaData);
            if (err != 0) {
                // Tell the user that we could not find a usable Winsock DLL.
                printf("WSAStartup failed with error: %d\n", err);
                return 1;
            }

            // Create and verify socket
            client_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (client_socket == -1) {
                printf("Socket creation failed...\n");
                exit(0);
            }
            else
                printf("Socket successfully created..\n");

            // Assign IP and port
            memset(&servaddr, 0, sizeof(servaddr));
            servaddr.sin_family = AF_INET;
            servaddr.sin_addr.s_addr = inet_addr("ip");
            servaddr.sin_port = htons(PORT);

            // Connect the client socket to server socket
            if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0) {
                printf("Connection to the server failed...\n");
                exit(0);
            }
            else
                printf("Successfully connected to the server..\n");
            send(client_socket,concat(3,"leave ",token->valuestring,"\n"),1000,0);
            memset(mas,0,sizeof(mas));
            recv(client_socket,mas,sizeof(mas),0);
            cJSON *mas_j = cJSON_Parse(mas);
            if(strcmp(cJSON_GetObjectItem(mas_j,"type") -> valuestring , "Error") != 0 )
            {
                printf("Succssful\n");
                login(x);

            }
            else
            {
                printf("%s",mas);
            }
            closesocket(client_socket);
        }
        printf("\n");
    }
}

char* concat(int count, ...)
{
    va_list ap;
    int i;

    // Find required length to store merged string
    int len = 1; // room for NULL
    va_start(ap, count);
    for(i=0 ; i<count ; i++)
        len += strlen(va_arg(ap, char*));
    va_end(ap);

    // Allocate memory to concat strings
    char *merged = calloc(sizeof(char),len + 2);
    int null_pos = 0;

    // Actually concatenate strings
    va_start(ap, count);
    for(i=0 ; i<count ; i++)
    {
        char *s = va_arg(ap, char*);
        strcat(merged, s);
    }
    va_end(ap);
    strcat(merged, "\n");

    return merged;
}
