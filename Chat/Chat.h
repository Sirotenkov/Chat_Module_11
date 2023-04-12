#pragma once
#include <vector>
#include <exception>
#include <memory>
#include "Message.h"

struct UserLoginException : public std::exception   //
{                                                   //
	const char* what() const noexcept override      //
	{                                               //  ќбработка исключений
		return "Error! Login failure!";             //
	}                                               //
};                                                  //

class Chat
{
private:
	bool _isChatOpen = false;                       // ѕеременна€-флаг, показывающа€, открыт чат или нет
	std::vector<User> _users;                       //  онтейнер пользователей
	std::vector<Message> _messages;                 //  онтейнер сообщений
	std::shared_ptr<User> _currentUser = nullptr;   // ”казатель на текущего пользовател€

	void login();                                   // ќбъ€вление функции входа в систему
	void signUp();                                  // ќбъ€вление функции регистрации пользовател€
	void showChat();                                // ќбъ€вление функции отображени€ меню чата
	void showAllUsers();                            // ќбъ€вление функции отображени€ всех пользователей системы
	void addMessage();                              // ќбъ€вление функции добавлени€ сообщений

	std::vector<User>& getAllUsers()
	{
		return _users;
	}

	std::vector<Message>& getAllMessages()
	{
		return _messages;
	}

	std::shared_ptr<User> getUserByLogin(const std::string& login) const;  // ќбъ€вление функции возвращени€ указател€ на пользовател€ по логину

public:
	
	void start();  // ќбъ€вление функции, показывающей работает чат или нет
	
	bool isChatOpen() const
	{
		return _isChatOpen;
	}

	std::shared_ptr<User> getCurrentUser() const  // ћетод, возвращающий указатель на текущего пользовател€
	{
		return _currentUser;
	}

	void showLoginMenu();                         // ћетод, отображающий меню входа в систему

	void showUserMenu();                          // ћетод, отображающий пользовательское меню
};