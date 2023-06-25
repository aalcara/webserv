#include "Server.hpp"

Server::Server() {}

Server::~Server() {}

std::string parse_location(char *buffer)
{
	std::string str_buffer(buffer);
	std::size_t first_space = str_buffer.find(" ");
	if (first_space == std::string::npos)
	{
		return (0);
	}
	int second_space = str_buffer.find(" ", first_space + 1);
	std::cout << first_space << " " << second_space << std::endl;
	return (str_buffer.substr(first_space + 1, second_space - first_space - 1));
}
int Server::run_server()
{
	int				   server_fd, new_socket, valread;
	struct sockaddr_in address;
	int				   opt			= 1;
	int				   addrlen		= sizeof(address);
	char			   buffer[1024] = {0};
	std::string		   hello		= "HTTP/1.1 200 OK\nContent-Type: "
									  "text/plain\nContent-Length: 12\n\nHello world!";
	std::string		   nohello		= "HTTP/1.1 404 Not Found\nContent-Type: "
									  "text/plain\nContent-Length: 15\n\n404";
	// Creating socket file descriptor
	// ! socket() creates an endpoint for communication and returns a descriptor.
	// ! AF_INET: is domain argument, and specify to use IPv4 protocols
	// ! SOCK_STREAM: is type argument, specify to use two-way, connection-based byte stream
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		std::cerr << "socket failed" << std::endl;
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port
	// ! setsockopt manipulate options for the socket server_fd.
	// ! server_fd is the socket to have options manipulated;
	// ! To manipulate options at the sockets API level, level is specified as SOL_SOCKET
	// ! optname: options are passed to the appropriate protocol
	// ! optval: buffer where options are to be returned
	if (setsockopt(server_fd, SOL_SOCKET,
				   SO_REUSEADDR | SO_REUSEPORT, &opt,
				   sizeof(opt)))
	{
		std::cerr << "setsockopt" << std::endl;
		exit(EXIT_FAILURE);
	}

	address.sin_family		= AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;

	// ! htons convert integer hostshort from host byte order to network byte order
	address.sin_port = htons(PORT);

	// ! bind assigns the address specified to the (server_fd) socket
	// ! bind(sockfd, *addr, adrrlen)
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		std::cerr << "bind failed" << std::endl;
		exit(EXIT_FAILURE);
	}

	// ! listen marks server_fd as a passive socket, that could have at max 3 pending connections in the queue
	if (listen(server_fd, 3) < 0)
	{
		std::cerr << "listen" << std::endl;
		exit(EXIT_FAILURE);
	}

	// ! accept extract the first connection request on the queue of the server_fd and return a new fd referring to that socket.
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
							 (socklen_t *)&addrlen)) < 0)
	{
		std::cerr << "accept" << std::endl;
		exit(EXIT_FAILURE);
	}
	valread				 = read(new_socket, buffer, 1024);
	std::string location = parse_location(buffer);
	std::cout << valread << std::endl;
	std::cout << "|" << location << "|" << std::endl;
	if (strcmp(location.c_str(), "/") == 0)
	{
		send(new_socket, hello.c_str(), std::strlen(hello.c_str()), 0);
	}
	else
	{
		send(new_socket, nohello.c_str(), std::strlen(nohello.c_str()), 0);
	}

	std::cout << "Hello message sent\n"
			  << std::endl;

	// closing the connected socket
	close(new_socket);
	// closing the listening socket
	shutdown(server_fd, SHUT_RDWR);
	return 0;
}