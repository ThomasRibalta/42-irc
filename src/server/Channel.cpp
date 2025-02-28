#include "../../include/Channel.hpp"

Channel::Channel(std::string name)
{
  this->_name = name;
  this->_maxClients = 10;
  this->_inviteOnly = false;
  this->_topicOnlyOperator = true;
  this->_topic = "";
  this->_password = "";
}

Channel::~Channel()
{
}

std::string Channel::getName()
{
  return this->_name;
}

void Channel::broadcast(std::string message)
{
  for (std::vector<IrcClient *>::iterator it = this->_clients.begin(); it != this->_clients.end(); it++)
  {
    if (!(*it)->isBot())
      (*it)->sendMessage(message);
  }
}

void Channel::broadcast(std::string message, IrcClient *client)
{
  for (std::vector<IrcClient *>::iterator it = this->_clients.begin(); it != this->_clients.end(); it++)
  {
    if ((*it) != client && !(*it)->isBot())
      (*it)->sendMessage(message);
  }
}

void Channel::addClient(IrcClient *client)
{
  this->_clients.push_back(client);
}

void Channel::printClient()
{
  std::cout << "all client" << std::endl;
  for (std::vector<IrcClient *>::iterator it = this->_clients.begin(); it != this->_clients.end(); it++)
  {
    std::cout << (*it)->getUsername() << std::endl;
  }
}

void Channel::removeClient(IrcClient *client)
{
  this->_clients.erase(std::remove(this->_clients.begin(), this->_clients.end(), client), this->_clients.end());
}

void Channel::addOperator(IrcClient *client)
{
  this->_operators.push_back(client);
}

void Channel::removeOperator(IrcClient *client)
{
  this->_operators.erase(std::remove(this->_operators.begin(), this->_operators.end(), client), this->_operators.end());
}

bool Channel::isClientOperator(IrcClient *client)
{
  for (std::vector<IrcClient *>::iterator it = this->_operators.begin(); it != this->_operators.end(); it++)
    if ((*it) == client)
      return true;
  return false;
}

bool Channel::hasClientJoined(IrcClient *client)
{
  for (std::vector<IrcClient *>::iterator it = this->_clients.begin(); it != this->_clients.end(); it++)
    if ((*it) == client)
      return true;
  return false;
}

void Channel::setTopic(std::string topic)
{
  this->_topic = topic;
}

void Channel::setInviteOnly(bool inviteOnly)
{
  this->_inviteOnly = inviteOnly;
}

std::vector<IrcClient *> &Channel::getClients()
{
  return this->_clients;
}
bool Channel::isInviteOnly()
{
  return this->_inviteOnly;
}

void Channel::setTopicOnlyOperator(bool topicOnlyOperator)
{
  this->_topicOnlyOperator = topicOnlyOperator;
}

bool Channel::isTopicOnlyOperator()
{
  return this->_topicOnlyOperator;
}

void Channel::setMaxClients(int maxClients)
{
  this->_maxClients = maxClients;
}

size_t Channel::getMaxClients()
{
  return this->_maxClients;
}

void Channel::setPassword(std::string password)
{
  this->_password = password;
}

std::string Channel::getPassword()
{
  return this->_password;
}

void Channel::AddInvited(IrcClient *client)
{
  this->_invited.push_back(client);
}

void Channel::removeInvited(IrcClient *client)
{
  this->_invited.erase(std::remove(this->_invited.begin(), this->_invited.end(), client), this->_invited.end());
}

bool Channel::isInvited(IrcClient *client)
{
  for (std::vector<IrcClient *>::iterator it = this->_invited.begin(); it != this->_invited.end(); it++)
    if ((*it) == client)
      return true;
  return false;
}
