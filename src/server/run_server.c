/*
** EPITECH PROJECT, 2022
** EPITECH-WORKSOP-Chat-Box-in-C
** File description:
** run_server
*/

#include "server.h"

// run the server with multiple sockets

void run_server(server_t *server)
{
    while(1) {
        server->client_socket = accept(server->socket, (struct sockaddr *)&server->addr, sizeof(server->addr));
        if (server->client_socket == -1)
            continue;
        if (accept(server->socket, (struct sockaddr *)&server->addr, sizeof(server->addr)) == -1)
            continue;
    }
}
