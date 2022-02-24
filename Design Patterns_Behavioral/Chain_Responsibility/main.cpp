#include <iostream>
#include <string>
#include <regex>

class StringValidator
{
public:
	virtual ~StringValidator() {}
	virtual StringValidator* setNext(StringValidator* nextValidator) = 0;
	virtual std::string validate(std::string) = 0;

};

class BaseValidator : public StringValidator
{
protected:
	StringValidator* next = nullptr;
public:
	virtual ~BaseValidator() { delete next; };
	StringValidator* setNext(StringValidator* nextValidator) override
	{
		next = nextValidator;
		return nextValidator;
	}
	virtual std::string validate(std::string testString) override
	{
		if (this->next)
		{
			return this->next->validate(testString);
		}
		return "Horray Success";
	}
};

class NotEmptyValidator : public BaseValidator
{
public:
	NotEmptyValidator() {};
	std::string validate(std::string testString)
	{
		puts("Checking if empty...");

		if (testString.empty())
		{
			return "Please enter a value";
		}
		return BaseValidator::validate(testString);
	}
};

class LengthValidator : public BaseValidator
{
	int m_minLength;
public:
	LengthValidator(int minLength) : m_minLength(minLength) {};
	std::string validate(std::string testString) override
	{
		puts("Checking string length...");
		if (testString.length() < m_minLength)
		{
			return "Please eneter a value longer than " +
				std::to_string(m_minLength);
		}
		return BaseValidator::validate(testString);
	}
};

class RegexValidator : public BaseValidator
{
	std::string patternName;
	std::string regexString;
public:
	RegexValidator(std::string patternName, std::string regexString) :
		patternName(patternName), regexString(regexString) {};
	std::string validate(std::string testString) override
	{
		puts("Checking regex match...");
		if (!std::regex_match(testString, std::regex(regexString)))
		{
			return "The value entered does not match the proper format for a " + patternName;
		}
		return BaseValidator::validate(testString);
	}


};
bool in_array(const std::string& value, const std::vector<std::string>& array)
{
	return std::find(array.begin(), array.end(), value) != array.end();
}

class HistoryValidator : public BaseValidator
{
	std::vector<std::string> m_historyItems;
public:
	HistoryValidator(std::vector<std::string> historyItems) :
		m_historyItems(historyItems) {};
	std::string validate(std::string testString) override
	{
		puts("Checking if string has been used before...");
		if (in_array(testString ,m_historyItems))
		{
			return "please enter a unique value";
		}
		return BaseValidator::validate(testString);
	}


};




int main()
{
	StringValidator* emailValidator = new BaseValidator;

	emailValidator
		->setNext(new NotEmptyValidator)
		->setNext(new RegexValidator("email addres",
			"^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"));

	std::cout << "Checking Emails --------------\n";
	std::cout << "Input: \n" << emailValidator->validate("") << "\n\n";
	std::cout << "Input: lukasz\n" << emailValidator->validate("shaun") << "\n\n";

	std::cout << "Input: lukasz@gmail.com\n" << emailValidator->validate("lukasz@gmail.com") << "\n\n";

	delete emailValidator;


	return 0;
}