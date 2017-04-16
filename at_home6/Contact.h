// TODO: add header guard
#ifndef COMMUNICATION_CONTACT_H_
#define COMMUNICATION_CONTACT_H_

// TODO: add namespace here
namespace communication{
	class Contact
	{
		char m_name[21];
		int m_index;
		long long* m_phoneNumbers;
		int m_noOfPhoneNumbers;
		void set();

	public:
		// TODO: add the default constructor here
		Contact();

		// TODO: add the constructor with parameters here
		Contact(const char* _name, long long* _phoneNumber,int size);

		// TODO: add the destructor here
		~Contact();
		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
		// TODO: add the display function here
		void display() const;

		// TODO: add the isEmpty function here
		bool isEmpty() const;
		bool isValid(long long) const;
		void addPhoneNumber(const long long phoneNumber);



	};
}

#endif
