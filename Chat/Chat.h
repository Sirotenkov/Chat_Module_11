#pragma once
#include <vector>
#include <exception>
#include <memory>
#include "Message.h"

struct UserLoginException : public std::exception   //
{                                                   //
	const char* what() const noexcept override      //
	{                                               //  ��������� ����������
		return "Error! Login failure!";             //
	}                                               //
};                                                  //

class Chat
{
private:
	bool _isChatOpen = false;                       // ����������-����, ������������, ������ ��� ��� ���
	std::vector<User> _users;                       // ��������� �������������
	std::vector<Message> _messages;                 // ��������� ���������
	std::shared_ptr<User> _currentUser = nullptr;   // ��������� �� �������� ������������

	void login();                                   // ���������� ������� ����� � �������
	void signUp();                                  // ���������� ������� ����������� ������������
	void showChat();                                // ���������� ������� ����������� ���� ����
	void showAllUsers();                            // ���������� ������� ����������� ���� ������������� �������
	void addMessage();                              // ���������� ������� ���������� ���������

	std::vector<User>& getAllUsers()
	{
		return _users;
	}

	std::vector<Message>& getAllMessages()
	{
		return _messages;
	}

	std::shared_ptr<User> getUserByLogin(const std::string& login) const;  // ���������� ������� ����������� ��������� �� ������������ �� ������

public:
	
	void start();  // ���������� �������, ������������ �������� ��� ��� ���
	
	bool isChatOpen() const
	{
		return _isChatOpen;
	}

	std::shared_ptr<User> getCurrentUser() const  // �����, ������������ ��������� �� �������� ������������
	{
		return _currentUser;
	}

	void showLoginMenu();                         // �����, ������������ ���� ����� � �������

	void showUserMenu();                          // �����, ������������ ���������������� ����
};