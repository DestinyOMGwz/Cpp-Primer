#ifndef _MESSAGE_H_
#define _MESSAGE_H_
#include <set>
#include <string>

class Folder;

class Message
{
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Folder;
public:
	// Constructors
	Message(const std::string& = "");
	Message(const Message&);
	Message(Message&&);
	~Message();

	// Assignment Operator
	Message& operator=(const Message&);
	Message& operator=(Message&&);
	

	// Functionality
	void save(Folder&);
	void remove(Folder&);
	void printMsg() const;

	void addFlr(Folder *f) { folders.insert(f); }
	void remFlr(Folder *f) { folders.insert(f); }

private:
	std::string contents;
	std::set<Folder*> folders;

	// private functionality
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void move_Folders(Message *m);
};

void swap(Message&, Message&);

#endif