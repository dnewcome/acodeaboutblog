#include <windows.h>
#include "common.h"

int doconnect( SOCKET in_socket, char* in_addr, int in_port ) {
  struct sockaddr_in clientService; 
  clientService.sin_family = AF_INET;
  clientService.sin_addr.s_addr = inet_addr( in_addr );
  clientService.sin_port = htons( in_port );

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

int main( int argc, char* argv[] ) {
	SOCKET sock;
	int i;
	char* addr = argv[1];
	int port = atoi( argv[2] );
	doinit();
	
	for( i=0; i < 15000; i++ ) {
		sock = dosocket();	
		if( doconnect( sock, addr, port ) > 0 ) break;
		printf( "connection number %i\n", i );
	}
	
	_sleep(60000);
}
