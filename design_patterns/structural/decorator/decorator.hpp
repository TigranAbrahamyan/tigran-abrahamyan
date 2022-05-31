#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include <string>

using namespace std;

class Server {
  protected:
    string _ip;
    int _port;

  public:
    Server(string ip, int port) {
      _ip = ip;
      _port = port;
    }

    string getUrl() {
      return "https://" + _ip + ":" + to_string(_port);
    }
};

class AWS : public Server {
  private:
    bool _isAWS;

  public:
    AWS(Server& server) : Server(server) {
      _isAWS = true;
    }

    string awsInfo() {
      return getUrl();
    }

    bool isAWS() {
      return _isAWS;
    }
};

class Azure : public Server {
  private:
    bool _isAzure;

  public:
    Azure(Server& server) : Server(server) {
      _isAzure = true;
      _port += 500;
    }

    bool isAzure() {
      return _isAzure;
    }
};

#endif
