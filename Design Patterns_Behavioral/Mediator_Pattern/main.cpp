#include <iostream>

class Mediator
{
public:
	virtual void mediate(const std::string& event) = 0;
	virtual ~Mediator() {};
};

class InterfaceElement
{
protected:
	std::string m_name;
	bool m_isVisible = true;
	Mediator* m_mediator = nullptr;
public:
	InterfaceElement(const std::string& name, bool isVisible, Mediator* mediator) :
		m_name(name), m_isVisible(isVisible),m_mediator(mediator) {};
	void setVisibility(bool isVible) { this->m_isVisible = isVible; };
	std::string getDescription()
	{
		return m_isVisible
			? m_name + " is visible"
			: m_name + "is NOT visible";
	}

};

class ButtonElement : public InterfaceElement
{
public:
	ButtonElement(const std::string& name, bool isVisible, Mediator *mediator) :
		InterfaceElement(name, isVisible,mediator) {};
	virtual ~ButtonElement() {};
	virtual void click()
	{
		m_mediator->mediate(m_name + " clicked");
	};
};

class TextBox : public InterfaceElement
{
	std::string m_textValue = "";
public:
	TextBox(const std::string& name, bool isVisible, Mediator* mediator) :
		InterfaceElement(name, isVisible, mediator) {};
	virtual ~TextBox() {};
	virtual void changeText(const std::string& newValue)
	{
		m_textValue = newValue;
	}
};

class CheckBox : public InterfaceElement
{
	bool m_isChecked = false;
public:
	CheckBox(const std::string& name, bool isVisible, Mediator* mediator) :
		InterfaceElement(name, isVisible, mediator) {};
	virtual ~CheckBox() {};
	virtual void setIsChecked(bool isChecked)
	{
		this->m_isChecked = isChecked;
	}
};



class UserInterface : public Mediator
{
	TextBox* m_nameTextBox;
	CheckBox* m_isMarriedCheckbox;
	TextBox* m_spousesNameTextBox;
	ButtonElement* m_submitButton;
public:
	UserInterface()
	{
		m_nameTextBox = new TextBox("Name textbox", true, this);
		m_isMarriedCheckbox = new CheckBox("Is married checkbox", true, this);
		m_spousesNameTextBox = new TextBox("Spouses's name textbox", false, this);
		m_submitButton = new ButtonElement("Submit Button", false,this);
	}
	~UserInterface()
	{
		delete m_nameTextBox;
		delete m_isMarriedCheckbox;
		delete m_spousesNameTextBox;
		delete m_submitButton; 
	}

	void mediate(const std::string& event) override
	{
		std::cout << "Mediating event: " << event << "...\n";
		if (event == "Name textbox is empty")
		{
			m_submitButton->setVisibility(false);
		}
		else if (event == "Name textbox is not empty")
		{
			m_submitButton->setVisibility(true);
		}
		else if (event == "Is married checkbox is checkde")
		{
			m_spousesNameTextBox->setVisibility(true);
		}
		else if (event == "Is married checkbox is unchecked")
		{
			m_spousesNameTextBox->setVisibility(false);
		}
		else if (event == "Submit button clicked")
		{
			std::cout << "Submitted!\n";
		}
		else
		{
			std::cout << "Unrecognized event!";
		}
	}

	TextBox* getNameTextBox() { return m_nameTextBox; };
	CheckBox* getIsMarriedCheckbox() { return m_isMarriedCheckbox; };
	TextBox* getSpousesNameTextBox() { return m_spousesNameTextBox; };
	ButtonElement* getSubmitButton() { return m_submitButton; };
};

int main()
{
	UserInterface* ui = new UserInterface;

	InterfaceElement* elements[] = {
		ui->getNameTextBox(),
		ui->getIsMarriedCheckbox(),
		ui->getSpousesNameTextBox(),
		ui->getSubmitButton(),
	};

	for (auto element : elements) {
		std::cout << element->getDescription() << "\n";
	}

	ui->getIsMarriedCheckbox()->setIsChecked(true);
	std::cout << "\n";
	for (auto element : elements) {
		std::cout << element->getDescription() << "\n";
	}

	delete ui;
	return 0;
}