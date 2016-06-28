#ifndef USER_H
#define USER_H

#include "manageDigiLibBook.h"
#include "manage_user.h"

class user
{
	public:
	void showMainMenu();

	protected:
    	manageDigiLibBook m_lib;
    	manage_user m_User;
};
#endif

