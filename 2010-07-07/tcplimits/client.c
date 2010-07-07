#include <windows.h>
#include "common.h"

int doconnect( SOCKET in_socket ) {
  struct sockaddr_in clientService; 
  clientService.sin_family = AF_INET;
  clientService.sin_addr.s_addr = inet_addr( "127.0.0.1" );
  clientService.sin_port = htons( 55555 );

  if ( connect( in_socket, (SOCKADDR*) &clientService, sizeof(clientService) ) == SOCKET_ERROR) {
    printf( "Failed to connect.\n" );
    WSACleanup();
    return 1;
  }
  else {
	printf( "Client connected.\n" );
	return 0;
  }
}

int main() {
	SOCKET sock;
	int i;
	doinit();
	
	for( i=0; i < 15000; i++ ) {
		sock = dosocket();	
		if( doconnect( sock ) > 0 ) break;
		printf( "connection number %i\n", i );
	}
	
	_sleep(60000);
}