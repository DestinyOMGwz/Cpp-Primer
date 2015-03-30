#ifndef _FOLDER_H_
#define _FOLDER_H_
#include <set>
#include "Message.h"

class Folder
{
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Message;
public:
	// Constructors
	Folder();
	Folder(const Folder&);
	~Folder();

	// Assignment operator
	Folder& operator=(const Folder &source);

	void printFolder() const;

	

private:
	std::set<Message*> messages;
	// private Functionality
	void add_to_Message(const Folder&);
	void remove_to_Message();

	void addMsg(Message*);
	void remMsg(Message*);

};
void swap(Folder&, Folder&);

#endif