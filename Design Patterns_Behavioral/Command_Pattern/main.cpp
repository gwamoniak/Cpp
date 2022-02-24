#include <iostream>
#include <string>
#include <vector>

class Canvas 
{
	std::vector<std::string> m_shapes;
public:
	void addShape(const std::string& newShape)
	{
		m_shapes.push_back(newShape);
	};
	void clearAll()
	{
		m_shapes.clear();
	}
	std::vector<std::string> getShapes() { return m_shapes; };

};
class Command
{
public:
	virtual ~Command() {};
	virtual void execute() = 0;
};

class Button 
{
	Command* m_command;

public:
	Button(Command* command) : m_command(command) {};
	void click() { m_command->execute(); };
};



class AddShapeCommand : public Command
{
	std::string m_shapeName;
	Canvas *m_canvas;
public:
	AddShapeCommand(const std::string& shapeName, Canvas* canvas) :
		m_shapeName(shapeName), m_canvas(canvas) {};
	void execute() {
		m_canvas->addShape(m_shapeName);
	}
};

class ClearCommand : public Command
{
	Canvas* m_canvas;
public:
	ClearCommand(Canvas* canvas) : m_canvas(canvas) {};
	void execute() { m_canvas->clearAll(); };
};
std::string vectorToString(std::vector<std::string> vector)
{
	std::string result = "";
	for (size_t i = 0; i < vector.size(); i++)
	{
		result.append(vector.at(i) + ", ");
	}
	return result;
};


int main()
{
	Canvas* canvas = new Canvas;
	
	Button* addTriangleButton = new Button(new
		AddShapeCommand("triangle", canvas));
	
	Button* addSquareButton = new Button(new
		AddShapeCommand("square", canvas));

	Button* clearButton = new Button(new ClearCommand(canvas));

	addTriangleButton->click();
	std::cout << "Current canvas state: " << vectorToString(canvas->getShapes()) << "\n";

	addSquareButton->click();
	addTriangleButton->click();
	std::cout << "Current canvas state: " << vectorToString(canvas->getShapes()) << "\n";
	clearButton->click();
	std::cout << "Current canvas state: " << vectorToString(canvas->getShapes()) << "\n";

	delete canvas;


	return 0;
}
