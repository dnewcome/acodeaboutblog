#include <windows.h>
#include "common.h"

int dobind( SOCKET m_socket, char* in_addr, int in_port ) {
	struct sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr( in_addr );
	service.sin_port = htons( in_port );

	if( bind( m_socket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR ) {
	    printf( "bind() failed: %ld.\n", WSAGetLastError() );
	    closesocket( m_socket );
	    return 1;
	}
	else {
	    printf( "bind() is OK!\n" );
	    return 0;
	}
}

void dolisten( SOCKET in_socket ) {
	if (listen( in_socket, SOMAXCONN ) == SOCKET_ERROR) {
		printf("Error listening on socket.\n");
	}
	else {
		printf( "Listening on socket...\n" );
	}
}

void doaccept( SOCKET in_socket ) {
	SOCKET ClientSocket = INVALID_SOCKET;
	ClientSocket = accept( in_socket, NULL, NULL );
	if( ClientSocket == INVALID_SOCKET ) {
		printf( "accept failed: %d\n", WSAGetLastError() );
		// closesocket( in_socket );
		// WSACleanup();
	}
	else {
		printf( "accepted socket: %d\n", WSAGetLastError() );
	}
}

int main( int argc, char* argv[] ) {
	char* addr = argv[1];
	int port = atoi( argv[2] );

	SOCKET sock;
	doinit();
	sock = dosocket();
	dobind( sock, addr, port );
	dolisten( sock );
	while( 1 ) {
		doaccept( sock );
	}
}
