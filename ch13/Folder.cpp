#include "Folder.h"
#include <memory>
#include <iostream>

// Constructor
Folder::Folder() {}

Folder::Folder(const Folder &source) : messages(source.messages)
{
	add_to_Message(source);
}

Folder::~Folder() 
{
	remove_to_Message();
}

void swap(Folder &lhs, Folder &rhs)
{
	using std::swap;
	lhs.remove_to_Message();
	rhs.remove_to_Message();
	swap(lhs.messages, rhs.messages);
	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}

Folder& Folder::operator=(const Folder &source)
{
	remove_to_Message();
	messages = source.messages;
	add_to_Message(source);
	return *this;
}


// Functionality
void Folder::addMsg(Message *p)
{
	messages.insert(p);
}

void Folder::remMsg(Message *p)
{
	messages.erase(p);
}

void Folder::printFolder() const
{
	for (auto m : messages)
		m->printMsg();
}

void Folder::add_to_Message(const Folder &rhs)
{
	for (auto m : rhs.messages)
		m->addFlr(this);
}

void Folder::remove_to_Message()
{
	for (auto m : messages)
		m->remFlr(this);
}