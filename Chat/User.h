#pragma once
#include <string>

class User
{
private:
	const std::string _login;
	std::string _password;
public:
	User(const std::string& login, const std::string password) : _login(login), _password(password) {}

	const std::string& getUserLogin() const
	{
		return _login;
	}

	const std::string& getUserPassword() const
	{
		return _password;
	}

	void setUserPassword(const std::string& password)
	{
		_password = password;
	}
};