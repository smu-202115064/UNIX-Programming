#include <netdb.h>
#include <stdio.h>

int main() {
    struct servent *port;
    int n;


    printf("Host Byte Order:\n");

    setservent(0);

    for (n = 0; n < 5; n++) {
        port = getservent();
        printf("Name=%s, Port=%d\n", port->s_name, ntohs(port->s_port));
    }

    endservent();


    printf("Network Byte Order:\n");

    setservent(0);

    for (n = 0; n < 5; n++) {
        port = getservent();
        printf("Name=%s, Port=%d\n", port->s_name, port->s_port);
    }

    endservent();
}
