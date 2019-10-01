# TP3-FTP-Honeypot
"Programming Workshop" class assignment

`/server <service/port> <path/to/config>`

`/client <host (localhost)> <service/port>`

Task: create a (lite) FTP Honeypot 

The honeypot in this case can be summarized as a "fake" server that interacts and answers the same way a real server would.
The program is divided in server files that will be used to create the server application, client files for the client, and common for both.
The system then must implement the use of threads (the server has one for each client connected) and sockets for networking

Objectives &  Restrictions:
- Use RAII
- Command execution must be polymorphic (see server_command_interpreter & server_commands)
- Cant assume a max length for the messages between server-client
- There is a known communication protocol, messages end with the character '\n'
- Manage and use exceptions

Class relations overview
![alt text](https://github.com/LeviMatias/TP3-FTP-Honeypot/blob/master/diagram.png)
