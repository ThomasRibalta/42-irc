#pragma once

#include <iostream>
#include <string>
#include <map>
#include "IrcServer.hpp"
#include "IrcClient.hpp"
#include "Channel.hpp"

class IrcServer;
class IrcClient;
class Commands
{
private:
	Commands();

public:
	static void pass_command(IrcServer &server,
													 IrcClient &user, std::string command);
	static void join_command(IrcServer &server,
													 IrcClient &user, std::string command);
	static void nick_command(IrcServer &server,
													 IrcClient &user, std::string command);
	static void user_command(IrcServer &server,
													 IrcClient &user, std::string command);
	static void part_command(IrcServer &server,
													 IrcClient &user, std::string command);
	static void privmsg_command(IrcServer &server,
															IrcClient &user, std::string command);
	static void kick_command(IrcServer &server,
													 IrcClient &user, std::string command);
	static void topic_command(IrcServer &server,
														IrcClient &user, std::string command);
	static void invite_command(IrcServer &server,
														 IrcClient &user, std::string command);
	static void mode_command(IrcServer &server,
													 IrcClient &user, std::string command);
	static void handleDCC(IrcServer &server, IrcClient &user, const std::string &target, const std::string &ctcpMessage);

};
