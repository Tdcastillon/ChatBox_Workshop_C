/*
** EPITECH PROJECT, 2022
** EPITECH-WORKSOP-Chat-Box-in-C
** File description:
** init_server
*/

#include "server.h"
#define MAX_CLIENTS 10

server_t *init_server(char *ip_addr, int port)
{
    server_t server;
    char *buffer[1024];

    server.ip_addr = ip_addr;
    server.port = port;

    server.addr.sin_family = AF_INET;
    server.addr.sin_port = htons(server.port);
    server.addr.sin_addr.s_addr = inet_addr(server.ip_addr);

    server.socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server.socket == -1)
        return (NULL);
    if (bind(server.socket, (struct sockaddr *)&server.addr, sizeof(server.addr)) == -1)
        return (NULL);
    if (listen(server.socket, MAX_CLIENTS) == -1)
        return (NULL);
    recv(server.socket, buffer, 1024, 0);
    printf("%s\n", buffer);
    return &server;
}