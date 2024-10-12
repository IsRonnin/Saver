#include "control.h"

int main() {
	reader R;
	vector<User> users;
	vector<Message> messages;

	R.get_from_file(users, "users");
	R.get_from_file(messages, "messages");

	users.emplace_back("Me" + to_string(users.size()), "my_login" + to_string(users.size()), "Password" + to_string(users.size()));
	messages.emplace_back("text" + to_string(messages.size()), "sender" + to_string(messages.size()), "receiver" + to_string(messages.size()));

	R.convert_to_file(users, "users");
	R.convert_to_file(messages, "messages");

}

