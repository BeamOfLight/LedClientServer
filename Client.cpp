#include <algorithm>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include <boost/array.hpp>
#include <boost/asio.hpp>

#include "Led.h"
#include "CommandManager.h"

using boost::asio::ip::tcp;
using namespace std;

void showMenu(const vector < string > &menu)
{
    int i = 0;
    for (auto &item: menu) {
        cout << (i++) << ". " << item << endl;
    }
}

string sendRequest(tcp::socket &socket, const string &request)
{
    boost::array<char, 128> buf_write;
    boost::array<char, 128> buf_read;
    boost::system::error_code error;
    copy(request.begin(), request.end(), buf_write.begin());
    socket.write_some(boost::asio::buffer(buf_write, request.size()), error);

    if (error == boost::asio::error::eof) {
        throw "Connection closed cleanly by peer";
    } else if (error) {
        throw boost::system::system_error(error); // Some other error
    }

    string response;
    size_t len = socket.read_some(boost::asio::buffer(buf_read), error);
    copy(buf_read.begin(), buf_read.begin() + len, back_inserter(response));

    if (error == boost::asio::error::eof) {
        throw "Connection closed cleanly by peer";
    } else if (error) {
        throw boost::system::system_error(error); // Some other error.
    }

    string result;
    int pos = response.find(STATUS_MESSAGE_OK);
    if (pos != string::npos && response.size() > 3)    {
        result = response.substr(3, response.size() - 4);
    } else {
        pos = response.find(STATUS_MESSAGE_FAILED);
        if (pos != string::npos) {
            throw response.c_str();
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    try {
        if (argc != 3) {
            cerr << "Usage: client <host> <port>" << endl;
            return 1;
        }

        boost::asio::io_service io_service;

        tcp::resolver resolver(io_service);
        tcp::resolver::query query(argv[1], argv[2]);
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

        tcp::socket socket(io_service);
        boost::asio::connect(socket, endpoint_iterator);
        Led* led = new Led();

        vector < string > menu = {
            "Set color: red",
            "Set color: green",
            "Set color: blue",
            "Turn on",
            "Turn off",
            "Set rate",
            "Refresh",
            "Close connection"
        };

        led->setStateFromText(sendRequest(socket, "get-led-state\n"));
        led->setRateFromText(sendRequest(socket, "get-led-rate\n"));
        led->setColorFromText(sendRequest(socket, "get-led-color\n"));

        int rate;
        int selected_item = -1;
        ostringstream result;
        string request;
        boost::array<char, 128> buf_write;
        boost::array<char, 128> buf_read;
        boost::system::error_code error;
        for (;;) {
            cout << led->getInfo() << endl;
            showMenu(menu);

            cout << "Choise: ";
            cin >> selected_item;
            cout << endl;

            switch (selected_item) {
                case 0:
                    sendRequest(socket, "set-led-color red\n");
                    led->setColor(COLOR_RED);
                    break;
                case 1:
                    sendRequest(socket, "set-led-color green\n");
                    led->setColor(COLOR_GREEN);
                    break;
                case 2:
                    sendRequest(socket, "set-led-color blue\n");
                    led->setColor(COLOR_BLUE);
                    break;
                case 3:
                    sendRequest(socket, "set-led-state on\n");
                    led->setState(true);
                    break;
                case 4:
                    sendRequest(socket, "set-led-state off\n");
                    led->setState(false);
                    break;
                case 5:
                    cout << "Enter rate in Hz (0-5)" << endl;
                    rate = -1;
                    while (rate < 0 || rate > 5) {
                        cin >> rate;
                    }
                    result.str("");
                    result << "set-led-rate " << rate << "\n";
                    request = result.str();
                    sendRequest(socket, request);
                    led->setRate(rate);
                    break;
                case 6:
                    led->setStateFromText(sendRequest(socket, "get-led-state\n"));
                    led->setRateFromText(sendRequest(socket, "get-led-rate\n"));
                    led->setColorFromText(sendRequest(socket, "get-led-color\n"));
                    break;
                case 7:
                    return 0;
                    break;
            }
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
