#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 7777
#define MESSAGE_LENGTH 1024

class ChatClient {
public:
    ChatClient() : serverSocket(-1) {} 
    //Основные ответы от сервера
    std::string addUserServer = "User added successfully!";
    std::string suchesfulServer = "Login successful!";
    
    bool connectToServer(const std::string& serverAddress);
    void run(); //Основной цикл работы клиента
private:
    int serverSocket;
    struct sockaddr_in serverAddressInfo;

    // Методы для отправки команд серверу и получения ответа:
    std::string sendCommand(const std::string& command);
    bool registerUser();
    bool login();
    void listUsers();
    void sendMessage();  //send private message
    void sendPublicMessage();
    void viewPrivateMessages();
    void viewPublicMessages();
    void userPanel();
};

