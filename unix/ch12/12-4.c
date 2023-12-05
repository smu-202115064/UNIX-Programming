#include <netdb.h>
#include <stdio.h>

int main() {
    struct servent *port;

    port = getservbyname("ssh", "tcp");
    printf("[NBO] Name=%s, Port=%d\n", port->s_name, port->s_port);
    printf("[HBO] Name=%s, Port=%d\n", port->s_name, ntohs(port->s_port));

    port = getservbyport(htons(21), "tcp");
    printf("[NBO] Name=%s, Port=%d\n", port->s_name, port->s_port);
    printf("[HBO] Name=%s, Port=%d\n", port->s_name, ntohs(port->s_port));
}