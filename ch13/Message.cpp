#include "Message.h"
#include "Folder.h"
#include <iostream>

// private functionality
void Message::add_to_Folders(const Message &msg)
{
	for (auto f : msg.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

void Message::move_Folders(Message *m)
{
	folders = std::move(m->folders);
	for (auto f : m->folders){
		f->addMsg(this);
		f->remMsg(m);
	}
	m->folders.clear();
}

// Constructors
Message::Message(const std::string &s) : contents(s) {}

Message::Message(const Message& source) : contents(source.contents), folders(source.folders)
{
	add_to_Folders(source);
}

Message::Message(Message &&source) : contents(std::move(source.contents))
{
	move_Folders(&source);
}

Message::~Message()
{
	remove_from_Folders();
}

// Operator overloading
Message& Message::operator=(const Message &rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message& Message::operator=(Message &&rhs)
{
	if (this != &rhs){
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}

// Functionality
void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::printMsg() const
{
	std::cout << contents << std::endl;
}