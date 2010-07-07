SOCKET dosocket() {
	SOCKET m_socket;
	m_socket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );

	if( m_socket == INVALID_SOCKET ) {
	    printf( "Error at socket(): %ld\n", WSAGetLastError() );
	    WSACleanup();
	    return 0;
	}
	else {
		printf( "socket() is OK!\n" );
		return m_socket;
	}	
}

// This init function from
// http://www.tenouk.com/Winsock/Winsock2example2.html
int doinit() {
	WORD wVersionRequested;
	WSADATA wsaData;
	int wsaerr;
	wVersionRequested = MAKEWORD(2, 2);
	wsaerr = WSAStartup( wVersionRequested, &wsaData);

	if( wsaerr != 0 ) {
		printf("The Winsock dll not found!\n");
		return 0;
	}

	else {
		printf("The Winsock dll found!\n");
		printf("The status: %s.\n", wsaData.szSystemStatus);
	}

	// now we check the winsock version
	if( LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2 ) {
		printf( 
			"The dll does not support Winsock version %u.%u!\n", 
			LOBYTE(wsaData.wVersion), 
			HIBYTE(wsaData.wVersion)
		);
	    WSACleanup();
	    return 0;
	}
	else {
		printf( 
			"The dll supports the Winsock version %u.%u!\n", 
			LOBYTE(wsaData.wVersion), 
			HIBYTE(wsaData.wVersion));
		printf( 
			"The highest version this dll can support: %u.%u\n", 
			LOBYTE(wsaData.wHighVersion), 
			HIBYTE(wsaData.wHighVersion) 
		);
	}
	return 0;
}