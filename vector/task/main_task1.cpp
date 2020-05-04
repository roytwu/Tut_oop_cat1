
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/logic/tribool.hpp>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
//#incldue <arpa/inet.h>  

//* assuming packet comes in a vector, or putting all the bits into a vector
//* parsing the packet fields into a vector, so the output is vector <vector >
std::vector< std::vector<bool> > parsePacket(std::vector<bool> packet)
{
	vector<bool>::iterator itr;
	std::vector< std::vector<bool> > dataList; //* data container after parsing

	//* header
	//* iterate through 4 bytes, save them to bitContainer
	for (itr=packet.begin(); itr<packet.begin()+4*8; itr++)
	{
		bitContainer.push_back(itr);
	}
	dataList.push_back(std::move(bitContainer));  //*moving parsed data to the findal container
	packet.erase(packet.begin(), packet.begin()+4*8);  //* removing parsed data from packet, in order to use "begin()"" again

	//* ID
	for (itr=packet.begin(); itr<packet.begin()+4*8; itr++)
	{
		bitContainer.push_back(itr);
	}
	dataList.push_back(std::move(bitContainer));
	packet.erase(packet.begin(), packet.begin()+4*8);

	//* Data Length
	for (itr=packet.begin(); itr<packet.begin()+1*8; itr++)
	{
		bitContainer.push_back(itr);
	}
	dataList.push_back(std::move(bitContainer));
	packet.erase(packet.begin(), packet.begin()+1*8);


	//* checksum
	//* paring the data from the back side
	std::vector<bool> MD5;
	for (itr=packet.end()-16*8; itr<packet.end(); itr++)
	{
		MD5.push_back(itr);
	}
	packet.erase(packet.end()-16*8, packet.end());

	//* data
	//* now there is only data in the packet
	for (itr=packet.begin(); itr<packet.end(); itr++)
	{
		bitContainer.push_back(itr);
	}
	dataList.push_back(std::move(bitContainer));
	dataList.push_back(MD5);

	return dataList;
}





int main()
{
	//* create a socket
	int listening = socket(AF_INET, SOCK_DGRAM, 0)
	if (listerning == -1)
	{
		std::cerr << "cannot create a socket";
		return -1;
	}


	//* bind the socket to a IP/port
	sockaddr_in podl;
	podl.sin_family = AF_INET;
	podl.sin_port = htons(10000);  //* little to big endian
	inet_pton(AF_INET, "0.0.0.0", &podl.sin_address);


	//* Mark the socket for listen
	if (listen(listening, SOMAXCONN)==-1)
	{
		std::cerr << "cannot listen";
		return -2;
	}

	sockaddr_in client;
	socklen_t clientSize = sizeof(client);
	int clientSocket = accept(listening, (sockaddr*)&client, &slientSize);
	

	//* Accept a call
	char buf[4096];
	
	while (true)
	{
		memset(buff, 0, 4096); //* zero the buffer

		//* waing for message
		int bytesIn = recvfrom(listening, buf, 4096, 0, (sockadr*)&client, &clientSize);
		if (bytesIn ==-1)
		{
			std::cerr("connection fails...\n");
			break;
		}

		//* Display message
		char clientIP[256];
		memset(clientIP, 0, 256); //* zero the buffer

		std::cout << "Received: " << std::string(buf, 0, bytesIn) << std::endl;

		inet_ntop(AF_INET, &client.sin_addr, clientIp, 256);
		std::cout << "Message received\n";

	}

	close(listening);

	
	//std::vector<bool> packet; 
    std::cout << "\nEnd of the porgram...\n";
	return 0;
}
